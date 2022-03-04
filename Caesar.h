#ifndef __Cesar__
#define __Cesar__

#include <fstream>
#include <string>

class Caesar {    
    std::ifstream inp;
    std::ofstream out;
    std::string st;
    bool flag = true;
public:
    Caesar(std::string, std::string);
    ~Caesar();
    Caesar(const Caesar&) = delete;
    Caesar(Caesar&&) = delete;
    Caesar& operator=(const Caesar&) = delete;
    Caesar& operator=(Caesar&&) = delete;
public:
    std::string cipher();
    std::string decipher();
private:
    void copyFileTextToString();
};

#endif
