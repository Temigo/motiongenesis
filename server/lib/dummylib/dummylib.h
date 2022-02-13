#ifndef DUMMYLIB_H
#define DUMMYLIB_H

class DummyLib
{
public:
    DummyLib() = default;
    ~DummyLib() = default;

    std::string process(const std::string& input);
};

#endif
