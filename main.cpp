#include "cbuffer.h"
#include <string>

int main() {
    // test del costruttore di default
    cbuffer<int>* c_int = new cbuffer<int>();

    // test del costruttore secondario, data la size
    unsigned int size = 10; 
    cbuffer<std::string> c_str(size);

/*
    // test del costruttore secondario date size e value
    unsigned int size_2 = 11;
    cbuffer<double> c_double(size_2, 3.14);

    // test del costruttore copia
    cbuffer<double> c_double_copy_test(c_double);
    c_double = c_double_copy_test;
    c_double_copy_test = c_double;
*/
    delete c_int;
    return 0;
}