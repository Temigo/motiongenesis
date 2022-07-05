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
$ nvm use v16.13.2
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

## Develop front-end only
The previous section showed how to build a (static) version of the frontend and serve it with the backend server.
For development, it is easier to run frontend and backend separately, so you can use the "hot reload" feature of
the frontend.

Run `npm run start-client` from the root folder for the client and `cd server && npm start` for the server
in two different terminals. The first terminal will show logs for the frontend client. The second terminal
will display logs from the server side.
You can see the result at [http://localhost:3002](http://localhost:3002). This will be calling the server
at localhost:3001 but serving the frontend client at localhost:3002. Every time you change the client code,
it will re-compile and re-load on the fly the frontend client, so you can directly see the outcome in your
browser. Enjoy!

## Folder structure
```
├── public            # Static assets for frontend client (e.g. icon, etc)
├── server            # Server-related code (Koa.js)
|   ├── build         # C++ build folder
|   ├── lib           # Dummy C++ library example
|   |   ├── dummylib
|   ├── loader        # Boilerplate code to load shared library object file
|   ├── binding.gyp   # Explains node-gyp how to compile C++ code
|   ├── hello_world.cc
|   ├── package.json  # Server is ran by node.js too
|   ├── server.js     # Defines Koa.js server
├── src               # Frontend-related code (React.js)
|   ├── App.js        # Main component
|   ├── index.js      # entry point of the frontend client
├── .env.development  # Environment variables (dev)
├── .env.production   # Environment variables (prod)
├── package.json      # Node project metadata, dependencies, npm scripts etc
```

## Notes
Server is based on [Koa.js](https://koajs.com/) framework. CPP extensions are written with Node API interface, see [here](https://github.com/nodejs/node-addon-api#api) and [here](https://nodejs.org/api/n-api.html). Client is based on [React.js](https://reactjs.org/).

The front-end code mostly lives in `src/App.js`. The server code lives in `server/server.js`. The C++ code is in `server/hello_world.cc`.

## Authors
Temigo
