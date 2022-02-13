#include <iostream>
#include "dummylib.h"

// #if defined(__linux__) || defined(__APPLE__)
// extern "C"
// {
//     DummyLib *allocator() { return new DummyLib(); }
//
//     void deleter(DummyLib *ptr) { delete ptr; }
// }
// #endif
//
// #ifdef WIN32
// extern "C"
// {
//     __declspec (dllexport) DummyLib *allocator() { return new DummyLib(); }
//
//     __declspec (dllexport) void deleter(DummyLib *ptr) { delete ptr; }
// }
// #endif

std::string DummyLib::process(const std::string& input) {
    if (input == "hello") {
        return "world";
    }
    else {
        return "You said, I quote: " + input;
    }
}
