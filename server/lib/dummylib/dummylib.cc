#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
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

std::vector<float> DummyLib::makeArray(const std::string& input) {
    const size_t nElements = 20;
    std::vector<float> output(nElements);
    std::uniform_real_distribution<float> distribution(0.0f, 1.0f); //Values between 0 and 1
    std::mt19937 engine; // Mersenne twister MT19937
    auto generator = std::bind(distribution, engine);
    std::generate_n(output.begin(), nElements, generator);
    return output;
}
