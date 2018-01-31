#include "cbuffer.h"
#include "misc.h"
#include <string>
#include <cassert>
#include <vector>

void test_buono() {
    std::cout << "\n\n***TEST COSTRUTTORE DI DEFAULT SU TIPO PRIMITIVO INT***" << std::endl;
    cbuffer<int> c_int;
    assert(c_int.size() == 0 && "Problema con size, costruttore di default su tipo primitivo");
    assert(c_int.occupied() == 0 && "Problema con occupied, costruttore di default su tipo primitivo");
    assert(c_int.insert(2) == false && "Problema con insert costruttore di default su tipo primitivo");
    assert(c_int.occupied() == 0 && "Problema con occupied, costruttore di default su tipo primitivo");
    c_int.remove_head();
    std::cout << c_int << std::endl;
    assert(c_int.size() == 0 && "Problema con size, costruttore di default su tipo primitivo, dopo insert e remove_head");
    assert(c_int.occupied() == 0 && "Problema con occupied, costruttore di default su tipo primitivo, dopo insert e remove_head");
    std::cout << "!!!TEST COSTRUTTORE DI DEFAULT SU TIPO PRIMITIVO INT PASSATO!!!" <<std::endl;
}

void test_costruttore_iteratori() {
    std::cout << "\n\n***TEST COSTRUTTORE DA UN ITERATORE DI TIPO PRIMITIVO CHAR***" << std::endl;
    char chr[4] = {'a', 'b', 'c', 'd'};
	cbuffer<char> c(4, chr, chr + 4);
    assert(c.occupied() == 4 && "Problema con occupied, costruttore da iteratore"); 
    assert(c.size() == 4 && "Problema con size, costruttore da iteratori");
    c.remove_head(); // rimuovo la testa
    c[0] = 'k';
    assert(c.occupied() == 3 && "Problema con occupied, costruttore da iteratori post remove_head");  
    c.insert('z');
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
		std::cout << *ci << std::endl;

    std::cout << "!!!TEST COSTRUTTORE DA UN ITERATORE DI TIPO PRIMITIVO CHAR PASSATO!!!" << std::endl;
    
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

void test_costruttore_copia() {
    std::cout << "\n\n***TEST COSTRUTTORE COPIA SU INTERI***" << std::endl;    
    int numbers[10] = {-5, 4, 12, -17, 7, 2, 3, 4, 5, 6};
    cbuffer<int> cb_int(10, numbers, numbers + 10);
    cbuffer<int> cb_int_2(cb_int);
    cb_int_2.remove_head();
    cb_int_2.insert(0);
    std::cout << cb_int_2 << std::endl;

    std::cout << "\n\n***TEST COSTRUTTORE COPIA SU VECTOR***" << std::endl;    
    cbuffer<std::vector<std::string> > cv(2);
    std::vector<std::string> s1, s2;
    cv.insert(s1);
    cv.insert(s2);
    cv[0].push_back("cv[0]");
    cv[1].push_back("cv[1]");
    cbuffer<std::vector<std::string> > cv2(cv);
    cv2[0][0] = "cv[!!!]";
    assert(cv[0][0].compare(cv2[0][0]) && "Errore nel costruttore copia del cbuffer di vector");
    for(unsigned int i = 0; i < cv.size(); ++i) {
        std::cout << cv[i][0] << std::endl;
        std::cout << cv2[i][0] << std::endl;        
    }

}


void test_cbuffer_di_cbuffer_di_voci() {
    std::cout << "\n\n***TEST CBUFFER DI CBUFFER DI INTERI***" << std::endl;    
    cbuffer<voce> cb_v(3);
    cb_v.insert(voce("Soligo", "Lorenzo", "123"));
    cb_v.insert(voce("Antoniotti", "Marco", "42"));
    cb_v.insert(voce("Prova3", "Voce", "1235"));
    cb_v.insert(voce("Sovrascrive", "Soligo", "1236"));

    // creo un altro cbuffer di voci, copia dell'altro
    cbuffer<voce> cb_v2(cb_v);
    voce v("Vediamo", "Se funziona", "42");
    cb_v2[1] = v;

    cbuffer<cbuffer<voce> > cb_cb_v(2);

    cb_cb_v.insert(cb_v);
    cb_cb_v.insert(cb_v2);

    std::cout << cb_cb_v << std::endl;    
    assert(cb_cb_v.size() == 2 && "Errore nella size del cbuffer di cbuffer di voci");
    assert(cb_cb_v.occupied() == 2 && "Errore nella occupied del cbuffer di cbuffer di voci");

}

void test_evaluate_if() {
    std::cout << "\n\n***TEST EVALUATE_IF***" << std::endl;

    int numbers[10] = {-5, 4, 12, -17, 7, 2, 3, 4, 5, 6};
    cbuffer<int> cb_int(10, numbers, numbers + 10);
    is_even funct;
    evaluate_if(cb_int, funct);

    unsigned int size = 3;
    cbuffer<point> cbp(size);
    cbp.insert(point(1, 1));
    cbp.insert(point(2, 2));
    cbp.insert(point(1, 3));
    
    x_equals_y f;
    evaluate_if(cbp, f);

}

void test_operator_quadre_cattivo() {}

void test_clear_poi_riempi() {}



int main() {
    // test del costruttore di default su tipo primitivo
    test_buono();

    // test del costruttore da un iteratore
    test_costruttore_iteratori();
    
    // test del costruttore secondario, data la size, su tipo complesso
    test_non_molto_buono();

    // test costruttore copia su tipi semplici e complessi
    test_costruttore_copia();

    // test che crea un cbuffer di cbuffer di voci e ci lavora su
    test_cbuffer_di_cbuffer_di_voci();

    // test che prova evaluate_if su varie struct
    test_evaluate_if();

    test_operator_quadre_cattivo();
    
    test_clear_poi_riempi();


    // controlla bene operator== e operator != nel main

    return 0;
}