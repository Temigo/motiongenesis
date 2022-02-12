#ifndef DUMMYLIB_H
#define DUMMYLIB_H

class DummyLib
{
public:
    DummyLib();
    ~DummyLib() = default;

    std::string process(const std::string& input);
    void test();
    int help;
};

#endif
