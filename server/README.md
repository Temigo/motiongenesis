# Server code

This spins up a simple [Koa.js](https://koajs.com/) backend server (see `server.js` code). At build time the frontend is put
into a `../build` folder, which is then served statically by the server.

CPP functions exported through Node API (see `hello_world.cc` and compilation configuration in `bindings.gyp`)
are compiled at build time and the `.node` executable (basically a shared library) lives in the folder `./build/Release/`.
