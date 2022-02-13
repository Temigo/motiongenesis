# MotionGenesis Prototype
Proof-of-concept of running a text command prompt through the browser, interacting with a C++ program in the backend.

Requires Node.js v16 (LTS/Gallium) or higher.

**Demo is available on [Heroku](https://motiongenesis.herokuapp.com/). Check it out!**

The instructions below are only if you want to run everything locally on your computer.

## Installing tools for development
Install NVM (Node Version Manager) for easier management of Node.js versions in the long term:
```
wget -qO- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.1/install.sh | bash
```
Make sure it worked by typing `nvm`. It should print the help information. If not, trying `source ~/.bashrc` again.

Then install Node.js through NVM:
```
$ nvm install v16.13.2
$ nvm list
$ nvm use lts/gallium
```
You have to run the last command in any new terminal session to enable Node.js.

Of course, we are assuming you have GCC or some other standard C++ compiler.

## Build & run:
```
$ git clone https://github.com/Temigo/motiongenesis.git && cd motiongenesis
$ npm install
$ npm run build
```
then run the server with `npm start`. Go take a look at [http://localhost:3001](http://localhost:3001).

## Notes
Server is based on [Koa.js](https://koajs.com/) framework. CPP extensions are written with Node API interface, see [here](https://github.com/nodejs/node-addon-api#api) and [here](https://nodejs.org/api/n-api.html). Client is based on [React.js](https://reactjs.org/).

The front-end code mostly lives in `src/App.js`. The server code lives in `server/server.js`. The C++ code is in `server/hello_world.cc`.

## Authors
Temigo
