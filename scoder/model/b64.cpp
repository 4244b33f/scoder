//
//  b64.cpp
//  scoder
//
//  Created by r325 on 08/11/2017.
//  Copyright © 2017 r325. All rights reserved.
//

#include "b64.hpp"

namespace b64space {
    
    B64coder::B64coder()
    {
        
    }
    
    B64coder::B64coder(std::string &text)
    {
        std::cout << "B64coder construct" << std::endl;
        this->pSourceText = &text;
        std::cout << "Inner location: " << this->pSourceText << '\n';
    }
    
    B64coder::B64coder(std::vector<char> &buf)
    {
        
    }

    B64coder::~B64coder()
    {
        std::cout << "Destruct" << std::endl;
        delete encodedBuffer;
    }
    
    void B64coder::reserveOutSize()
    {
//        ToDo
    }
    
    std::string B64coder::b64Enc()
    {
        std::cout << *pSourceText << std::endl;
        std::cout << "b64Enc" << std::endl;
        long temp = 0;
        unsigned char c = 'n';
        std::string someStd = "some strrr";
        std::cout << pSourceText->length() << " | " << sizeof(c) << '\n';
        unsigned int i;
        for (i = 0; i < pSourceText->length(); i++) {
            std::cout << pSourceText->at(i) << '\n';
            if ((i + 1) % 3 != 0) {
                // ToDo: need to push left: 1st - 16, 2nd - 8
                temp += (unsigned char)pSourceText->at(i) << (24 - (((i+1)%3)*8));
            } else {
                temp += (unsigned char)pSourceText->at(i);
                this->encodedBuffer->push_back(b64[((temp & 0x00FC0000) >> 18)]);
                this->encodedBuffer->push_back(b64[((temp & 0x0003F000) >> 12)]);
                this->encodedBuffer->push_back(b64[((temp & 0x00000FC0) >> 6)]);
                this->encodedBuffer->push_back(b64[((temp & 0x0000003F))]);
                temp = 0;
            }
        }
        i = i % 3;
        switch (i) {
            case 2:
                this->encodedBuffer->push_back(b64[((temp & 0x00FC0000) >> 18)]);
                this->encodedBuffer->push_back(b64[((temp & 0x0003F000) >> 12)]);
                this->encodedBuffer->push_back(b64[((temp & 0x00000FC0) >> 6)]);
                this->encodedBuffer->push_back(this->padChar);
                break;
            case 1:
                this->encodedBuffer->push_back(b64[((temp & 0x00FC0000) >> 18)]);
                this->encodedBuffer->push_back(b64[((temp & 0x0003F000) >> 12)]);
                this->encodedBuffer->push_back(this->padChar);
                this->encodedBuffer->push_back(this->padChar);
                break;
            default:
                break;
        }
        for (std::vector<char>::iterator it = encodedBuffer->begin(); it != encodedBuffer->end(); it++) {
            std::cout << *it;
        }
        std::cout << '\n';
        return "";
    }
    
    std::string B64coder::b64Dec()
    {
        return "";
    }
}
