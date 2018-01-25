#include "cbuffer.h"
#include <string>

int main() {
    // test del costruttore di default
    cbuffer<int>* c_int = new cbuffer<int>();

    // test del costruttore secondario, data la size
    unsigned int size = 3; 
    cbuffer<std::string> c_str(size);

    c_str.insert("prova");
    c_str.insert("prova2");
    c_str.insert("prova3");
    
    c_str.get();

    // test del costruttore copia
    
    cbuffer<std::string> c_string_copy_test(c_str);
    c_string_copy_test.get();
    
    delete c_int;
    return 0;
}