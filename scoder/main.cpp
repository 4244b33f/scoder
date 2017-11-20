//
//  main.cpp
//  scoder
//
//  Created by r325 on 07/11/2017.
//  Copyright © 2017 r325. All rights reserved.
//

#include <iostream>
#include "model/b64.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::string blah = "any carnal pleas";
    std::cout << blah << "| " << &blah << std::endl;
    b64space::B64coder smt(blah);
    smt.b64Enc();
    std::cout << "Hello, World!\n";
    return 0;
}
