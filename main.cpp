#include "cbuffer.h"
#include "misc.h"
#include <string>
#include <cassert>

void test_buono() {
    std::cout << "\n\n***TEST COSTRUTTORE DI DEFAULT SU TIPO PRIMITIVO INT***" << std::endl;
    cbuffer<int> c_int;
    
    // assert da verificare
    assert(c_int.size() == 0 && "Problema con size, costruttore di default su tipo primitivo");
    std::cout << "c_int.size(): " << c_int.size() << std::endl;
    assert(c_int.occupied() == 0 && "Problema con occupied, costruttore di default su tipo primitivo");
    std::cout << "c_int.occupied(): " << c_int.occupied() << std::endl;
    bool k = c_int.insert(2);
    assert(k == false && "Problema con insert costruttore di default su tipo primitivo ");
    std::cout << "c_int.insert(2): " << (k == true ? "true" : "false") << std::endl;
    assert(c_int.occupied() == 0 && "Problema con occupied, costruttore di default su tipo primitivo");
    std::cout << "c_int.occupied(): " << c_int.occupied() << std::endl;
    
    
    std::cout << "c_int.get(): " << std::endl; 
    c_int.get(); // non ha inserito nulla
    std::cout << "c_int.remove_head()" << std::endl;
    c_int.remove_head(); // rimuovo la testa

    // assert da verificare
    assert(c_int.size() == 0 && "Problema con size, costruttore di default su tipo primitivo, dopo insert e remove_head");
    std::cout << "c_int.size(): " << c_int.size()  << std::endl;
    assert(c_int.occupied() == 0 && "Problema con occupied, costruttore di default su tipo primitivo, dopo insert e remove_head");
    std::cout << "c_int.occupied(): " << c_int.occupied() << std::endl; 
}


void test_non_molto_buono() {
    std::cout << "\n\n***TEST COSTRUTTORE DATA SIZE SU TIPO NON PRIMITIVO STRING***" << std::endl;
    unsigned int size = 3; 
    cbuffer<std::string> c_str(size);

    // assert da verificare
    assert(c_str.size() == 3 && "Problema con size, costruttore data la size su tipo complesso");
    std::cout << "c_str.size(): " << c_str.size() << std::endl;
    assert(c_str.occupied() == 0 && "Problema con occupied, costruttore data la size su tipo complesso");
    std::cout << "c_str.occupied(): " << c_str.occupied() << std::endl;
    bool k = c_str.insert("prova");
    assert(k == true && "Problema con insert, costruttore data la size su tipo complesso");
    std::cout << "c_str.insert(\"prova\"): " << (k == true ? "true" : "false") << std::endl;
    assert(c_str.occupied() == 1 && "Problema con occupied, costruttore data la size su tipo complesso");
    std::cout << "c_str.occupied(): " << c_str.occupied() << std::endl;
    c_str.insert("prova2");
    std::cout << "c_str.insert(\"prova2\"): " << (k == true ? "true" : "false") << std::endl;
    assert(c_str.occupied() == 2 && "Problema con occupied, costruttore data la size su tipo complesso");
    std::cout << "c_str.occupied(): " << c_str.occupied() << std::endl;
    std::cout << "c_str.get()" << std::endl;
    c_str.get();
    c_str.insert("prova3");
    std::cout << "c_str.insert(\"prova3\"): " << (k == true ? "true" : "false") << std::endl;
    assert(c_str.occupied() == 3 && "Problema con occupied, costruttore data la size su tipo complesso");
    std::cout << "c_str.occupied(): " << c_str.occupied() << std::endl;
    std::cout << "c_str.get()" << std::endl;
    c_str.get();
    c_str.insert("prova4"); // sovrascrive "prova"
    std::cout << "c_str.insert(\"prova4\"): " << (k == true ? "true" : "false") << std::endl;
    assert(c_str.occupied() == 3 && "Problema con occupied, costruttore data la size su tipo complesso");
    std::cout << "c_str.occupied(): " << c_str.occupied() << std::endl;
    std::cout << "c_str.get()" << std::endl;
    c_str.get();
    c_str.insert("prova5"); // sovrascrive "prova2"
    std::cout << "c_str.insert(\"prova5\"): " << (k == true ? "true" : "false") << std::endl;
    assert(c_str.occupied() == 3 && "Problema con occupied, costruttore data la size su tipo complesso");
    std::cout << "c_str.occupied(): " << c_str.occupied() << std::endl;
    std::cout << "c_str.get()" << std::endl;
    c_str.get();
    std::cout << "c_str.remove_head()" << std::endl;
    c_str.remove_head(); // rimuovo la testa
    std::cout << "c_str.get()" << std::endl;
    c_str.get();
    assert(c_str.occupied() == 2 && "Problema con occupied, costruttore data la size su tipo complesso");    
    std::cout << "c_str.occupied(): " << c_str.occupied() << std::endl; // stampa 2
    c_str.insert("prova6");
    std::cout << "c_str.insert(\"prova6\"): " << (k == true ? "true" : "false") << std::endl;
    std::cout << "c_str.get()" << std::endl;
    c_str.get();
    c_str.insert("prova7");
    std::cout << "c_str.insert(\"prova7\"): " << (k == true ? "true" : "false") << std::endl;
    std::cout << "c_str.get()" << std::endl;
    c_str.get();
    std::cout << "c_str.occupied(): " << c_str.occupied() << std::endl; // stampa 3
    assert(c_str.occupied() == 3 && "Problema con occupied, costruttore data la size su tipo complesso");
    std::cout << "c_str.remove_head(): " << std::endl;
    c_str.remove_head(); // rimuovo la testa
    std::cout << "c_str.get()" << std::endl;
    c_str.get();
    std::cout << "c_str.occupied(): " << c_str.occupied() << std::endl; // stampa 2
    assert(c_str.occupied() == 2 && "Problema con occupied, costruttore data la size su tipo complesso");    
    std::cout << "c_str.size(): " << c_str.size()  << std::endl; // stampa 3
    
    std::cout << "c_str.remove_head(): " << std::endl;
    c_str.remove_head(); // rimuovo la testa
    std::cout << "c_str.get()" << std::endl;
    c_str.get();
    std::cout << "c_str.occupied(): " << c_str.occupied() << std::endl; // stampa 2
    assert(c_str.occupied() == 1 && "Problema con occupied, costruttore data la size su tipo complesso");  

    std::cout << "c_str.remove_head(): " << std::endl;
    c_str.remove_head(); // rimuovo la testa
    std::cout << "c_str.get()" << std::endl;
    c_str.get();
    std::cout << "c_str.occupied(): " << c_str.occupied() << std::endl; // stampa 2
    assert(c_str.occupied() == 0 && "Problema con occupied, costruttore data la size su tipo complesso");  

    std::cout << "c_str.remove_head()" << std::endl;
    c_str.remove_head(); // rimuovo la testa
    std::cout << "c_str.get()" << std::endl;
    c_str.get();
    std::cout << "c_str.occupied(): " << c_str.occupied() << std::endl; // stampa 2
    assert(c_str.occupied() == 0 && "Problema con occupied, costruttore data la size su tipo complesso");  
}


int main() {
    // test del costruttore di default su tipo primitivo
    test_buono();

    // test del costruttore secondario, data la size, su tipo complesso
    test_non_molto_buono();

/*
   
    // test del costruttore copia
    cbuffer<std::string>* c_string_copy_test = new cbuffer<std::string>(c_str);
    
    c_string_copy_test->insert("prova6");
    c_string_copy_test->get();
    std::cout << "c_string_copy_test->get()" << std::endl;
    
    c_string_copy_test->remove_head();
    c_string_copy_test->insert("prova6");
    c_string_copy_test->get();
    std::cout << "c_string_copy_test->get()" << std::endl;
    


    // test dell'operator=
    *c_string_copy_test = c_str;
    std::cout << "c_string_copy_test = &c_str" << std::endl;
    std::cout << "c_string_copy_test->get()" << std::endl;

    c_string_copy_test->get();

    delete c_string_copy_test;
*/
    return 0;
}