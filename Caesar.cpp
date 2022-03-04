#include <iostream>
#include "Caesar.h"

Caesar::Caesar(std::string outFileName, std::string inputFileName) 
        : out(outFileName), inp(inputFileName)
{
    std::cout << "enter 0 for decipher, any number for cipher" << std::endl;

    if(inp.is_open() && out.is_open()) {
        copyFileTextToString();
        
        bool t;
        std::cin >> t;

        if(t) {
            cipher();
        } else {
            decipher();
        }
    } else {
        flag = false;
        if(inp.is_open()) {
            std::cout << inputFileName << " file can't open" << std::endl;
        }

        if(out.is_open()) {
            std::cout << outFileName << " file can't open" << std::endl;
        }
    }
}

Caesar::~Caesar() {
    if(flag) {
        out.close();
        inp.close();
    }
}

void Caesar::copyFileTextToString() {
    std::string str;
    while(!inp.eof()) {
        std::getline(inp, str);
        st += str;
        st += '\n';
    }
}

std::string Caesar::cipher() {
    for(int i = 0; i < st.size(); ++i) {
        if(st[i] == '\0' || st[i] == ' ' || st[i] == '\n') {
            continue;
        }

        //88 X, 120 x
        if(st[i] > 87 && st[i] < 91) {
            st[i] = (65 + (-1 * (88 - st[i])));
        }
        else if(st[i] > 119 && st[i] < 123) {
            st[i] = (97 + (-1 * (120 - st[i])));
        } 
        else if((st[i] >= 65 && st[i] <= 87) || (st[i] >= 97 && st[i] <= 119)) {
            st[i] = st[i] + 3;
        }
    }
    
    out << st;

    return st;
}

std::string Caesar::decipher() {
    for(int i = 0; i < st.size(); ++i) {
        if(st[i] == '\0' || st[i] == ' ' || st[i] == '\n') {
            continue;
        }

        //65 A. 97 a
        if(st[i] > 64 && st[i] < 68) {
            st[i] = (90 - (67 - st[i]));
        }
        else if(st[i] > 96 && st[i] < 100) {
            st[i] = (122 - (99 - st[i]));
        } 
        else if((st[i] >= 68 && st[i] <= 90) || (st[i] >= 100 && st[i] <= 122)) {
            st[i] = st[i] - 3;
        }
    }

    out << st;

    return st;
}
