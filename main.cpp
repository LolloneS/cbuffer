#include "cbuffer.h"
#include "misc.h"
#include <string>
#include <cassert>

void test_buono() {
    std::cout << "\n\n***TEST COSTRUTTORE DI DEFAULT SU TIPO PRIMITIVO INT***" << std::endl;
    cbuffer<int> c_int;
    assert(c_int.size() == 0 && "Problema con size, costruttore di default su tipo primitivo");
    assert(c_int.occupied() == 0 && "Problema con occupied, costruttore di default su tipo primitivo");
    assert(c_int.insert(2) == false && "Problema con insert costruttore di default su tipo primitivo");
    assert(c_int.occupied() == 0 && "Problema con occupied, costruttore di default su tipo primitivo");
    c_int.remove_head();
    assert(c_int.size() == 0 && "Problema con size, costruttore di default su tipo primitivo, dopo insert e remove_head");
    assert(c_int.occupied() == 0 && "Problema con occupied, costruttore di default su tipo primitivo, dopo insert e remove_head");
    std::cout << "!!!TEST COSTRUTTORE DI DEFAULT SU TIPO PRIMITIVO INT PASSATO!!!" <<std::endl;
}


void test_non_molto_buono() {
    std::cout << "\n\n***TEST COSTRUTTORE DATA SIZE SU TIPO NON PRIMITIVO STRING***" << std::endl;
    unsigned int size = 3; 
    cbuffer<std::string> c_str(size);
    assert(c_str.size() == 3 && "Problema con size, costruttore data la size su tipo complesso");
    assert(c_str.occupied() == 0 && "Problema con occupied, costruttore data la size su tipo complesso");
    c_str.insert("prova");
    assert(c_str.occupied() == 1 && "Problema con occupied, costruttore data la size su tipo complesso");
    c_str.insert("prova2");
    assert(c_str.occupied() == 2 && "Problema con occupied, costruttore data la size su tipo complesso");
    c_str.insert("prova3");
    std::cout << c_str << std::endl;
    c_str[2] = "prova_operator[]";
    std::cout << c_str << std::endl;
    assert(c_str.occupied() == 3 && "Problema con occupied, costruttore data la size su tipo complesso");
    c_str.insert("prova4"); // sovrascrive "prova"
    assert(c_str.occupied() == 3 && "Problema con occupied, costruttore data la size su tipo complesso");
    c_str.insert("prova5"); // sovrascrive "prova2"
    assert(c_str.occupied() == 3 && "Problema con occupied, costruttore data la size su tipo complesso");
    std::cout << "Test operator <<: ";
    std::cout << c_str << std::endl;
    c_str.remove_head();
    assert(c_str.occupied() == 2 && "Problema con occupied, costruttore data la size su tipo complesso");    
    c_str.insert("prova6");
    c_str.insert("prova7");
    assert(c_str.occupied() == 3 && "Problema con occupied, costruttore data la size su tipo complesso");
    c_str.remove_head(); // rimuovo la testa
    assert(c_str.occupied() == 2 && "Problema con occupied, costruttore data la size su tipo complesso");    
    c_str.remove_head(); // rimuovo la testa
    assert(c_str.occupied() == 1 && "Problema con occupied, costruttore data la size su tipo complesso");  
    c_str.remove_head(); // rimuovo la testa
    assert(c_str.occupied() == 0 && "Problema con occupied, costruttore data la size su tipo complesso");  
    c_str.remove_head(); // rimuovo la testa
    assert(c_str.occupied() == 0 && "Problema con occupied, costruttore data la size su tipo complesso");  
    std::cout << "!!!TEST COSTRUTTORE DATA SIZE SU TIPO NON PRIMITIVO STRING PASSATO!!!" <<std::endl;

}

void test_costruttore_copia() {}

void test_costruttore_iteratori() {
    std::cout << "\n\n***TEST COSTRUTTORE DA UN ITERATORE DI TIPO PRIMITIVO CHAR***" << std::endl;
    char chr[4] = {'a', 'b', 'c', 'd'};
	cbuffer<char> c(4, chr, chr + 4);
    assert(c.occupied() == 4 && "Problema con occupied, costruttore da iteratore"); 
    assert(c.size() == 4 && "Problema con size, costruttore da iteratori");
    c.remove_head(); // rimuovo la testa
    c[0] = 'k';
    assert(c.occupied() == 3 && "Problema con occupied, costruttore da iteratori post remove_head");  
	std::cout<<"Test stampa con iterator"<<std::endl;
	cbuffer<char>::iterator i, ie;
	for(i = c.begin(), ie = c.end(); i != ie; ++i) 
		std::cout << *i << std::endl;
    c.clear();
    assert(c.size() == 0 && "Problema con size, costruttore da iteratori post remove_head");
    assert(c.occupied() == 0 && "Problema con occupied, costruttore da iteratori post remove_head");
	std::cout<<std::endl<<"Test stampa cbuffer vuoto con const_iterator"<<std::endl;
	cbuffer<char>::const_iterator ci, cie;
	for(ci = c.begin(), cie = c.end(); ci != cie; ++ci) 
		std::cout<<*ci<<std::endl;

    std::cout << "!!!TEST COSTRUTTORE DA UN ITERATORE DI TIPO PRIMITIVO CHAR PASSATO!!!" << std::endl;

}


void test_cbuffer_di_cbuffer_di_voci() {
    // istanzio e riempio un cbuffer di voci
    cbuffer<voce> cb_v(3);
    cb_v.insert(voce("Soligo", "Lorenzo", "123"));
    cb_v.insert(voce("Antoniotti", "Marco", "42"));
    cb_v.insert(voce("Prova3", "Voce", "1235"));
    cb_v.insert(voce("Sovrascrive", "Soligo", "1236"));

    // creo un altro cbuffer di voci, copia dell'altro
    cbuffer<voce> cb_v2(cb_v);
    voce v("Vediamo", "Se funziona", "42");
    cb_v2[1] = v;

    cbuffer<cbuffer<voce>> cb_cb_v(2);

    cb_cb_v.insert(cb_v);
    cb_cb_v.insert(cb_v2);

    std::cout << cb_cb_v << std::endl;    
    assert(cb_cb_v.size() == 2 && "Errore nella size del cbuffer di cbuffer di voci");
    assert(cb_cb_v.occupied() == 2 && "Errore nella occupied del cbuffer di cbuffer di voci");

}

void test_operator_quadre_cattivo() {}


void test_evaluate_if() {
    std::cout << "\n\n***TEST EVALUATE_IF***" << std::endl;

    int numbers[10] = {-5, 4, 12, -17, 7, 2, 3, 4, 5, 6};
    cbuffer<int> cb_int(10, numbers, numbers + 10);
    is_even funct;
    evaluate_if(cb_int, funct);

}



int main() {
    // test del costruttore di default su tipo primitivo
    test_buono();

    // test del costruttore da un iteratore
    test_costruttore_iteratori();
    
    // test del costruttore secondario, data la size, su tipo complesso
    test_non_molto_buono();

    test_costruttore_copia();



    test_cbuffer_di_cbuffer_di_voci();

    test_evaluate_if();

    test_operator_quadre_cattivo();

    return 0;
}