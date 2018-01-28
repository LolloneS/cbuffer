#include "cbuffer.h"
#include "misc.h"
#include <string>
#include <cassert>

void test_buono() {
    std::cout << "\n\n***TEST COSTRUTTORE DI DEFAULT SU TIPO PRIMITIVO INT***" << std::endl;
    cbuffer<int> c_int;
    assert(c_int.size() == 0 && "Problema con size, costruttore di default su tipo primitivo");
    std::cout << "c_int.size(): " << c_int.size() << std::endl;
    assert(c_int.occupied() == 0 && "Problema con occupied, costruttore di default su tipo primitivo");
    std::cout << "c_int.occupied(): " << c_int.occupied() << std::endl;
    bool k = c_int.insert(2);
    assert(k == false && "Problema con insert costruttore di default su tipo primitivo ");
    std::cout << "c_int.insert(2): " << (k == true ? "true" : "false") << std::endl;
    assert(c_int.occupied() == 0 && "Problema con occupied, costruttore di default su tipo primitivo");
    std::cout << "c_int.occupied(): " << c_int.occupied() << std::endl;
    std::cout << c_int << std::endl; 
    std::cout << "c_int.remove_head()" << std::endl;
    c_int.remove_head();
    assert(c_int.size() == 0 && "Problema con size, costruttore di default su tipo primitivo, dopo insert e remove_head");
    std::cout << "c_int.size(): " << c_int.size()  << std::endl;
    assert(c_int.occupied() == 0 && "Problema con occupied, costruttore di default su tipo primitivo, dopo insert e remove_head");
    std::cout << "c_int.occupied(): " << c_int.occupied() << std::endl; 
}


void test_non_molto_buono() {
    std::cout << "\n\n***TEST COSTRUTTORE DATA SIZE SU TIPO NON PRIMITIVO STRING***" << std::endl;
    unsigned int size = 3; 
    cbuffer<std::string> c_str(size);
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
    std::cout << c_str << std::endl;
    c_str.insert("prova3");
    std::cout << "c_str.insert(\"prova3\"): " << (k == true ? "true" : "false") << std::endl;
    assert(c_str.occupied() == 3 && "Problema con occupied, costruttore data la size su tipo complesso");
    std::cout << "c_str.occupied(): " << c_str.occupied() << std::endl;
    std::cout << c_str << std::endl;
    c_str.insert("prova4"); // sovrascrive "prova"
    std::cout << "c_str.insert(\"prova4\"): " << (k == true ? "true" : "false") << std::endl;
    assert(c_str.occupied() == 3 && "Problema con occupied, costruttore data la size su tipo complesso");
    std::cout << "c_str.occupied(): " << c_str.occupied() << std::endl;
    std::cout << c_str << std::endl;
    c_str.insert("prova5"); // sovrascrive "prova2"
    std::cout << "c_str.insert(\"prova5\"): " << (k == true ? "true" : "false") << std::endl;
    assert(c_str.occupied() == 3 && "Problema con occupied, costruttore data la size su tipo complesso");
    std::cout << "c_str.occupied(): " << c_str.occupied() << std::endl;
    std::cout << c_str << std::endl;
    std::cout << "c_str.remove_head()" << std::endl;
    c_str.remove_head();
    std::cout << c_str << std::endl;
    assert(c_str.occupied() == 2 && "Problema con occupied, costruttore data la size su tipo complesso");    
    std::cout << "c_str.occupied(): " << c_str.occupied() << std::endl; 
    c_str.insert("prova6");
    std::cout << "c_str.insert(\"prova6\"): " << (k == true ? "true" : "false") << std::endl;
    std::cout << c_str << std::endl;
    c_str.insert("prova7");
    std::cout << "c_str.insert(\"prova7\"): " << (k == true ? "true" : "false") << std::endl;
    std::cout << c_str << std::endl;
    std::cout << "c_str.occupied(): " << c_str.occupied() << std::endl;
    assert(c_str.occupied() == 3 && "Problema con occupied, costruttore data la size su tipo complesso");
    std::cout << "c_str.remove_head(): " << std::endl;
    c_str.remove_head(); // rimuovo la testa
    std::cout << c_str << std::endl;
    std::cout << "c_str.occupied(): " << c_str.occupied() << std::endl; 
    assert(c_str.occupied() == 2 && "Problema con occupied, costruttore data la size su tipo complesso");    
    std::cout << "c_str.remove_head(): " << std::endl;
    c_str.remove_head(); // rimuovo la testa
    std::cout << c_str << std::endl;
    std::cout << "c_str.occupied(): " << c_str.occupied() << std::endl; 
    assert(c_str.occupied() == 1 && "Problema con occupied, costruttore data la size su tipo complesso");  
    std::cout << "c_str.remove_head(): " << std::endl;
    c_str.remove_head(); // rimuovo la testa
    std::cout << c_str << std::endl;
    std::cout << "c_str.occupied(): " << c_str.occupied() << std::endl; 
    assert(c_str.occupied() == 0 && "Problema con occupied, costruttore data la size su tipo complesso");  
    std::cout << "c_str.remove_head()" << std::endl;
    c_str.remove_head(); // rimuovo la testa
    std::cout << c_str << std::endl;
    std::cout << "c_str.occupied(): " << c_str.occupied() << std::endl;
    assert(c_str.occupied() == 0 && "Problema con occupied, costruttore data la size su tipo complesso");  
}

void test_costruttore_copia() {}

void test_costruttore_iteratori() {
    std::cout << "\n\n***TEST COSTRUTTORE DA UN ITERATORE DI TIPO PRIMITIVO CHAR***" << std::endl;
    char chr[4] = {'a', 'b', 'c', 'd'};
	cbuffer<char> c(4, chr, chr + 4);
    std::cout << c << std::endl;
    std::cout << "c.occupied(): " << c.occupied() << std::endl; 
    assert(c.occupied() == 4 && "Problema con occupied, costruttore da iteratore"); 
    assert(c.size() == 4 && "Problema con size, costruttore da iteratori");
    std::cout << "c.size(): " << c.size() << std::endl;
    std::cout << "c.remove_head()" << std::endl;
    c.remove_head(); // rimuovo la testa
    std::cout << c << std::endl;
    std::cout << "c.occupied(): " << c.occupied() << std::endl;
    assert(c.occupied() == 3 && "Problema con occupied, costruttore data la size su tipo complesso");  

    // test stampa con iteratori
	std::cout<<std::endl<<"TEST STAMPA CON ITERATOR"<<std::endl;
	cbuffer<char>::iterator i, ie;
	for(i = c.begin(), ie = c.end(); i != ie; ++i) 
		std::cout << *i << std::endl;

	std::cout<<std::endl<<"TEST STAMPA CON CONST_ITERATOR"<<std::endl;
	cbuffer<char>::const_iterator ci, cie;
	for(ci = c.begin(), cie = c.end(); ci != cie; ++ci) 
		std::cout<<*ci<<std::endl;
}


void test_cbuffer_di_cbuffer_di_voci() {}





int main() {
    // test del costruttore di default su tipo primitivo
    test_buono();

    // test del costruttore secondario, data la size, su tipo complesso
    test_non_molto_buono();

    test_costruttore_copia();

    test_costruttore_iteratori();

    test_cbuffer_di_cbuffer_di_voci();

/*
   
    // test del costruttore copia
    cbuffer<std::string>* c_string_copy_test = new cbuffer<std::string>(c_str);
    
    c_string_copy_test->insert("prova6");
    
    c_string_copy_test->remove_head();
    c_string_copy_test->insert("prova6");
    


    // test dell'operator=
    *c_string_copy_test = c_str;
    std::cout << "c_string_copy_test = &c_str" << std::endl;


    delete c_string_copy_test;
*/
    return 0;
}