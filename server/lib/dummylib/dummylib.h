#ifndef DUMMYLIB_H
#define DUMMYLIB_H
#include <vector>

class DummyLib
{
public:
    DummyLib() = default;
    ~DummyLib() = default;

    std::string process(const std::string& input);
    std::string processArray(const uint8_t* input, size_t length);
    std::vector<float> makeArray(const std::string& input);
};

#endif
