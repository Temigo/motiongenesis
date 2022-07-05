#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include <sstream>
#include "dummylib.h"

std::string DummyLib::process(const std::string& input) {
    if (input == "hello") {
        return "world";
    }
    else {
        return "You said, I quote: " + input;
    }
}

std::string DummyLib::processArray(const uint8_t* input, size_t length) {
    std::string out = "Got a file with " + std::to_string(length) + " characters\n";
    // if (length > 0) {
    //     out = out + (reinterpret_cast<char *>(input[0]));
    // }
    if (length > 0) {
        std::string content(reinterpret_cast<char const *>(input));
        std::stringstream file_content(content);
        std::string line;
        std::vector<std::string> lines_list;
        while(std::getline(file_content, line, '\n')) {
            lines_list.push_back(line);
            break; // we just want the 1st line
        }
        if (lines_list.size() > 0) {
            out = out + lines_list[0];
        }
        // out = out + content;
    }
    return out;
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
