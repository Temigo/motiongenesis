import React, { useState, useRef } from 'react';
import Terminal, { ColorMode, LineType } from 'react-terminal-ui';
import './App.css';
import { Button } from 'semantic-ui-react';
const axios = require('axios');


// Wraps up the backend call functionality
function callBackend(terminalInput, route) {
    return axios.get(`${ process.env.REACT_APP_BACKEND_URL }/${ route }/${ terminalInput }`)
        .then((response) => {
            if (response.status == 200) {
                return response.data;
            }
            else {
                console.log(response);
            }
        })
        .catch((error) => console.log(error))
}

function selectFiles(event) {
    console.log(event)
}

function App() {
    const [terminalLineData, setTerminalLineData] = useState([
      {type: LineType.Output, value: 'Welcome to the demo of Motion Genesis in the browser!'},
      {type: LineType.Output, value: 'Type `help` to see available commands.'}
    ]);

    const helpString = `
        Help\n
        plot\tSend me an array of numbers.\n
        hello\tGreet me.\n
        upload\tRead my text file.\n
        Or type anything else, really.\n
    `.split('\n');
    const help = helpString.map((s) => { return { type: LineType.Output, value: s.trim() }; } );

    const filePickerRef = useRef(null);
    return (
        <div className="App">
            <div className="container">
                <input type="file" style={{"visibility": "hidden", "height": 0, "width": 0, "display": "block"}} ref={filePickerRef} onChange={(e) => {
                    let reader = new FileReader();
                    console.log(reader)
                    // Every time we read a file, send it to the backend via POST request
                    reader.onloadend = (e) => console.log('loaded', e)
                    reader.onload = (e) => axios.post(`${ process.env.REACT_APP_BACKEND_URL }/upload/`, {
                        content: e.target.result
                    }).then((response) => {
                        if (response.status == 200) {
                            setTerminalLineData(prevTerminalLineData => prevTerminalLineData.concat([{
                                type: LineType.Output, value: 'Uploaded ' + e.target.currentFile.name + '... ' + response.data
                            }]))
                        }
                        else { console.log(response); }
                    }).catch((error) => console.log(error));
                    // Now loop over files and read them
                    const files = [...filePickerRef.current.files];
                    files.forEach((item, i) => {
                        console.log(item, i);
                        // TODO enforce file mime type to be text
                        reader.currentFile = item;
                        reader.readAsText(item);
                    });
                }} />
                <Terminal
                    name='Motion Genesis Prototype'
                    colorMode={ ColorMode.Dark }
                    lineData={ terminalLineData }
                    onInput={ (terminalInput) => {
                        if (terminalInput == "upload") {
                            filePickerRef.current.click();
                            setTerminalLineData(prevTerminalLineData => prevTerminalLineData.concat([{ type: LineType.Input, value: terminalInput }]));
                        }
                        else if (terminalInput == "help") {
                            console.log([
                                { type: LineType.Input, value: terminalInput },
                                ...help])
                            setTerminalLineData(prevTerminalLineData => prevTerminalLineData.concat([
                                { type: LineType.Input, value: terminalInput },
                                ...help]));
                        }
                        else {
                            var route = "command";
                            if (terminalInput == "plot") { route = "array"; }
                            callBackend(terminalInput, route).then((data) => setTerminalLineData(prevTerminalLineData => prevTerminalLineData.concat([
                                { type: LineType.Input, value: terminalInput },
                                { type: LineType.Output, value: Array.isArray(data) ? data.join('\n') : data }
                            ])));
                        }
                    } }
                />
            </div>
        </div>
    );
}

export default App;
