# MotionGenesis Prototype
Requires Node.js v16 or higher.

## Installing tools for development
Install NVM (Node Version Manager) for easier management of Node.js versions in the long term:
```
wget -qO- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.1/install.sh | bash
```
then install Node.js through NVM:
```
$ nvm install v16.13.2
$ nvm list
$ nvm use lts/gallium
```
You have to run the last command in any new terminal session to enable Node.js.

Of course, assuming you have GCC or some other standard C++ compiler.

## Run server
Serve is based on Koa.js framework. CPP extensions are written with Node API interface.
```
$ cd server && npm install
$ node server.js
```
If the C++ code is changed, rebuild with node-gyp
```
$ npm run build
```

## Run client
Client is based on React.js.
```
$ cd motiongenesis & npm install
$ npm start
```

## Authors
Temigo
