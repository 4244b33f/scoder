//
//  b64.hpp
//  scoder
//
//  Created by r325 on 08/11/2017.
//  Copyright © 2017 r325. All rights reserved.
//

#ifndef b64_hpp
#define b64_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bitset>


namespace b64space {
    class B64coder {
    private:
        const char b64[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
        const char padChar = '=';
        const std::string *pSourceText;
        std::vector<char> *encodedBuffer = new std::vector<char>;
        
    public:
        B64coder();
        B64coder(std::string &text);
        B64coder(std::ifstream ifile);
        B64coder(std::vector<char> &buf);
        std::string b64Enc();
        std::string b64Dec();
        ~B64coder();
        
    private:
        void reserveOutSize();
    };
}

#endif /* b64_hpp */
