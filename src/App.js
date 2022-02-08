import React, { useState } from 'react';
import './App.css';
import Terminal, { ColorMode, LineType } from 'react-terminal-ui';
// const { HelloWorld } = require('./build/Release/hello_world_native.node');
// console.log(HelloWorld)
const axios = require('axios');

function callBackend(terminalInput) {
    return axios.get(`${ process.env.REACT_APP_BACKEND_URL }/command/${ terminalInput }`)
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
                    onInput={ (terminalInput) =>
                        callBackend(terminalInput).then((data) => setTerminalLineData(terminalLineData.concat([
                            { type: LineType.Input, value: terminalInput },
                            { type: LineType.Output, value: data }
                        ])))
                    }
                />
            </div>
        </div>
    );
  // return (
  //   <div className="App">
  //     <header className="App-header">
  //       <img src={logo} className="App-logo" alt="logo" />
  //       <p>
  //         Edit <code>src/App.js</code> and save to reload.
  //       </p>
  //       <a
  //         className="App-link"
  //         href="https://reactjs.org"
  //         target="_blank"
  //         rel="noopener noreferrer"
  //       >
  //         Learn React
  //       </a>
  //     </header>
  //   </div>
  // );
}

export default App;
