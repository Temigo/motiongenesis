import React, { useState } from 'react';
import './App.css';
import Terminal, { ColorMode, LineType } from 'react-terminal-ui';
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

function App() {
    const [terminalLineData, setTerminalLineData] = useState([
      {type: LineType.Output, value: 'Welcome to the demo of Motion Genesis in the browser!'}
    ]);
    return (
        <div className="App">
            <div className="container">
                <Terminal
                    name='Motion Genesis Prototype'
                    colorMode={ ColorMode.Dark }
                    lineData={ terminalLineData }
                    onInput={ (terminalInput) => {
                        var route = "command";
                        if (terminalInput == "plot") { route = "array"; }
                        callBackend(terminalInput, route).then((data) => setTerminalLineData(terminalLineData.concat([
                            { type: LineType.Input, value: terminalInput },
                            { type: LineType.Output, value: Array.isArray(data) ? data.join('\n') : data }
                        ])));
                    } }
                />
            </div>
        </div>
    );
}

export default App;
