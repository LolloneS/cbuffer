#include "cbuffer.h"
#include <string>

int main() {
    // test del costruttore di default
    cbuffer<int> c_int();

    // test del costruttore secondario, data la size
    unsigned int size = 10; 
    cbuffer<std::string> c_str(size);

    


    return 0;
}