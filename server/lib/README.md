# Dynamical linking to shared library
`dummylib` is an example of naive C++ code that gets compiled into a shared library (.so on Linux).

The source code is included in the folder `dummylib` for clarity but the only thing
needed to build the server is the `libDummyLib.so` shared library.

Type `cmake . && make` to build the shared library yourself.
