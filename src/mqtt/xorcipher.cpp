#include <xorcipher.h>

const std::string XorCipher::KEY_ =
    "Vision Studio, video analitico inteligente. La cantidad correcta, en el "
    "lugar preciso, en el momento adecuado. Guia automatico inteligente del "
    "Cabezal Cosechadora";

XorCipher::XorCipher() {}

std::string XorCipher::encrypt(std::string str) {
    for (unsigned int i = 0; i < str.size(); i++)
        str[i] ^= KEY_[i % KEY_.size()];
    return str;
}

std::string XorCipher::decrypt(std::string str) { return encrypt(str); }
