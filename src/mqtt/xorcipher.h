#ifndef CRYPTOGRAPHY_H
#define CRYPTOGRAPHY_H
#include <iostream>

class XorCipher {
private:
    static const std::string KEY_;

public:
    XorCipher();
    static std::string encrypt(std::string str);
    static std::string decrypt(std::string str);
};

#endif // CRYPTOGRAPHY_H
