#include "cbuffer.h"
#include <string>

int main() {
    // test del costruttore di default
    cbuffer<int> c_int;
    std::cout << "c_int.size(): " << c_int.size()  << std::endl;
    std::cout << "c_int.occupied(): " << c_int.occupied() << std::endl;

    // test del costruttore secondario, data la size
    unsigned int size = 3; 
    cbuffer<std::string> c_str(size);

    // test insert + sovrascrittura
    c_str.insert("prova");
    c_str.insert("prova2");
    c_str.insert("prova3");
    c_str.insert("prova4");
    c_str.insert("prova5");
    std::cout << "c_str.get()" << std::endl;
    c_str.get();

    // test del costruttore copia
    cbuffer<std::string>* c_string_copy_test = new cbuffer<std::string>(c_str);
    c_string_copy_test->insert("prova6");
    c_string_copy_test->get();
    std::cout << "c_string_copy_test->get()" << std::endl;
    

    // test dell'operator=
    *c_string_copy_test = c_str;
    std::cout << "c_string_copy_test = &c_str" << std::endl;
    std::cout << "c_string_copy_test->get()" << std::endl;

    c_string_copy_test->get();

    delete c_string_copy_test;
    
    return 0;
}