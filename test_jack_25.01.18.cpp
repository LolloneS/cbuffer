struct greater_than_zero {
	bool operator()(const int &a) const {
		return a > 0;
	}
};

struct is_even {
    bool operator()(const int &a) const {
        return ((a % 2) == 0);
    }
};

struct is_divisible_by_three {
    bool operator()(const int &a) const {
        return ((a % 3) == 0);
    }
};

struct is_a_vowel {
    bool operator()(const char &a) const {
        return (a == 'a' || a == 'A' || a == 'e' || a == 'E' || a == 'i' || a == 'I' || a == 'o' || a == 'O' || a == 'u' || a == 'U');
    }
};

struct is_uppercase {
    bool operator()(const char &a) const {
        return (a >= 65 && a <= 90);
    }
};

void test_metodi_fondamentali() {
    /*Metodi richiesti:
      get_occupati, get_size, costruttore di default, inserimento, copy constructor, operator=
      costruttore alternativo (che prende una _size definita), operator<<
     */
    std::cout << "TEST METODI FONDAMENTALI" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Dichiaro cbuffer cb1 con costruttore di default"<< std::endl;
    circolar_buffer<int> cb1;
    std::cout << "Size di cb1: " << cb1.get_size() << std::endl;
    std::cout << "Occupati di cb1: " << cb1.get_occupati() << std::endl;
    std::cout << std::endl;

    std::cout << "Dichiarto cbuffer cb2 con costruttore alternativo indicando 6 come _size " << std::endl;
    circolar_buffer<int> cb2(6);
    std::cout << "Size di cb2: " << cb2.get_size() << std::endl;
    std::cout << "Occupati di cb2: " << cb2.get_occupati() << std::endl;
    std::cout << std::endl;

    std::cout << "Inserisco (5 10 15) in cb1 " << std::endl;
    cb1.insert(5);
    std::cout << "Dopo inserimento primo elemento: " << cb1;
    cb1.insert(10);
    std::cout << "Dopo inserimento secondo elemento: " << cb1;
    cb1.insert(15);
    std::cout << "Dopo inserimento terzo elemento: " << cb1;
    std::cout << "Occupati di cb1: " << cb1.get_occupati() << std::endl;
    std::cout << std::endl;

    std::cout << "Inserisco (4 8 12 16) in cb2 " << std::endl;
    cb2.insert(4);
    cb2.insert(8);
    cb2.insert(12);
    cb2.insert(16);
    std::cout << "Dopo inserimento elementi: " << cb2;
    std::cout << "Occupati di cb2: " << cb2.get_occupati() << std::endl;
    std::cout << std::endl;

    std::cout << "cb2 = cb1" << std::endl;
    cb2 = cb1;
    std::cout << "Stampo cb2: " << cb2;
    std::cout << "Stampo cb1: " << cb1;
    std::cout << "_size di cb2 dopo uguaglianza: " << cb2.get_size() << std::endl;
    std::cout << "_occupati di cb2 dopo uguaglianza: " << cb2.get_occupati() << std::endl;
    std::cout << std::endl;

    std::cout << "Dichiaro cbuffer cb3 con copy constructor passando cb1 " << std::endl;
    circolar_buffer<int> cb3(cb1);
    std::cout << "Elementi in cb3: " << cb3;
    std::cout << "_size di cb3: " << cb3.get_size() << std::endl;
    std::cout << "_occupati di cb3: " << cb3.get_occupati() << std::endl;
    std::cout << std::endl;

}

void test_metodi_con_char() {
    /*Metodi richiesti:
      get_occupati, get_size, costruttore di default, inserimento con riscrittura, copy constructor, operator=
      costruttore alternativo (che prende una _size definita), operator<<
    */
    std::cout << "TEST METODI CON CHAR" << std::endl;
    std::cout << std::endl;

    std::cout << "Dichiaro un cbuffer cb1 di char con costruttore di default e inserisco (A B C)" << std::endl;
    circolar_buffer<char> cb1;
    cb1.insert('A');
    cb1.insert('B');
    cb1.insert('C');
    std::cout << "Elementi in cb1: " << cb1;
    std::cout << "Size di cb1: " << cb1.get_size() << std::endl;
    std::cout << "Occupati di cb1: " << cb1.get_occupati() << std::endl;
    std::cout << std::endl;

    std::cout << "Inserico in cb1 (D E F)" << std::endl;
    cb1.insert('D');
    std::cout << "Dopo inserimento primo elemento: " << cb1;
    cb1.insert('E');
    std::cout << "Dopo inserimento secondo elemento: " << cb1;
    cb1.insert('F');
    std::cout << "Dopo inserimento terzo elemento: " << cb1;
    std::cout << "Occupati di cb1: " << cb1.get_occupati() << std::endl;
    std::cout << std::endl;

    std::cout << "Dichiarto cbuffer cb2 con costruttore alternativo indicando 6 come _size " << std::endl;
    circolar_buffer<char> cb2(6);
    std::cout << "Size di cb2: " << cb2.get_size() << std::endl;
    std::cout << "Occupati di cb2: " << cb2.get_occupati() << std::endl;
    std::cout << std::endl;

    std::cout << "Inserisco in cb2 (Z W K R)" << std::endl;
    cb2.insert('Z');
    cb2.insert('W');
    cb2.insert('K');
    cb2.insert('R');
    std::cout << "Dopo inserimento elementi: " << cb2;
    std::cout << "Occupati di cb2: " << cb2.get_occupati() << std::endl;
    std::cout << "_size di cb2: " << cb2.get_size() << std::endl;
    std::cout << std::endl;

    std::cout << "cb1 = cb2" << std::endl;
    cb1 = cb2;
    std::cout << "Elementi di cb1: " << cb1;
    std::cout << "_size di cb1: " << cb1.get_size() << std::endl;
    std::cout << "_occupati di cb1: " << cb1.get_occupati() << std::endl;
    std::cout << "Elementi di cb2: " << cb2;
    std::cout << "_size di cb2: " << cb2.get_size() << std::endl;
    std::cout << "_occupati di cb2: " << cb2.get_occupati() << std::endl;

    std::cout << std::endl;

    std::cout << "Dichiaro cb3 con copy costructor passando cb1 " << std::endl;
    circolar_buffer<char> cb3(cb1);
    std::cout << "Elementi di cb3: " << cb3;
    std::cout << "_size di cb3: " << cb3.get_size() << std::endl;
    std::cout << "_occupati di cb3: " << cb3.get_occupati() << std::endl;
    std::cout << std::endl;
}

void test_metodi_con_string() {
    /*Metodi richiesti:
      get_occupati, get_size, costruttore di default, inserimento con riscrittura, copy constructor, operator=
      costruttore alternativo (che prende una _size definita), operator<<
    */
    std::cout << "TEST METODI CON STRING" << std::endl;
    std::cout << std::endl;

    std::cout << "Dichiaro un cbuffer cb3 con costruttore alternativo _size = 6 e inserisco (DIO È UN CANE CIAO DIO) " << std::endl;
    circolar_buffer<std::string> cb1(6);
    cb1.insert("DIO");
    cb1.insert("È");
    cb1.insert("UN");
    cb1.insert("CANE");
    cb1.insert("CIAO");
    cb1.insert("DIO");
    std::cout << "Elementi in cb1: " << cb1;
    std::cout << "_size di cb1: " << cb1.get_size() << std::endl;
    std::cout << "_occupati di cb1: " << cb1.get_occupati() << std::endl;
    std::cout << std::endl;

    std::cout << "Inserisco (JESUS) in cb3, la nuova testa sarà È e JESUS sarà la coda " << std::endl;
    cb1.insert("JESUS");
    std::cout << "Elementi in cb1: " << cb1;

    std::cout << "Elimino la testa in cb1 fino a che cb1 non risulta vuota " << std::endl;
    cb1.elimina_testa();
    std::cout << "Elementi in cb1: " << cb1;
    cb1.elimina_testa();
    std::cout << "Elementi in cb1: " << cb1;
    cb1.elimina_testa();
    std::cout << "Elementi in cb1: " << cb1;
    cb1.elimina_testa();
    std::cout << "Elementi in cb1: " << cb1;
    cb1.elimina_testa();
    std::cout << "Elementi in cb1: " << cb1;
    cb1.elimina_testa();
    std::cout << "Elementi in cb1: " << cb1;
    std::cout << std::endl;

    std::cout << "Inserisco in cb1 (JESUS IN VERITÀ TI AMO) " << std::endl;
    cb1.insert("JESUS");
    cb1.insert("IN");
    cb1.insert("VERITÀ");
    cb1.insert("TI");
    cb1.insert("AMO");
    std::cout << "Elementi in cb1: " << cb1;
    std::cout << "_occupati di cb1: " << cb1.get_occupati() << std::endl;
    std::cout << "_size di cb1: " << cb1.get_size() << std::endl;
    std::cout << std::endl;

    std::cout << "Dichiaro in cb2 con costruttore di default e poi faccio cb2 = cb1 " << std::endl;
    circolar_buffer<std::string> cb2;
    std::cout << "Elementi in cb2: " << cb2;
    std::cout << "_occupati in cb2: " << cb2.get_occupati() << std::endl;
    std::cout << "_size in cb2: " << cb2.get_size() << std::endl;
    cb2 = cb1;
    std::cout << "Elementi in cb2: " << cb2;
    std::cout << "_occupati in cb2: " << cb2.get_occupati() << std::endl;
    std::cout << "_size in cb2: " << cb2.get_size() << std::endl;
    std::cout << std::endl;

    std::cout << "Inserisco in cb2 (SCIROPPOCADEINBASSOCOMEMD) " << std::endl;
    cb2.insert("SCIROPPOCADEINBASSOCOMEMD");
    std::cout << "Elementi in cb2: " << cb2;
    std::cout << "_occupati in cb2: " << cb2.get_occupati() << std::endl;
    std::cout << "_size in cb2: " << cb2.get_size() << std::endl;
    std::cout << "Elementi in cb1: " << cb1;
    std::cout << "_occupati di cb1: " << cb1.get_occupati() << std::endl;
    std::cout << "_size di cb1: " << cb1.get_size() << std::endl;
    std::cout << std::endl;

}

void test_inserimento_con_riscrittura () {
    /*Metodi richiesti: inserimento (con parte per la riscrittura), operator <<*/
    std::cout << "TEST INSERIMENTO CON RISCRITTURA" << std::endl;
    std::cout << std::endl;

    std::cout << "Dichiaro cbuffer cb1 con costruttore di default e inserisco (5 10 15) " << std::endl;
    circolar_buffer<int> cb1;
    cb1.insert(5);
    cb1.insert(10);
    cb1.insert(15);
    std::cout << "Elementi in cb1: " << cb1;
    std::cout << std::endl;

    std::cout << "Inserisco (20) in cb1 " << std::endl;
    cb1.insert(20);
    std::cout << "10 deve essere la nuova _head e 20 la _tail " << std::endl;
    std::cout << "Elementi in cb1: " << cb1;
    std::cout << std::endl;

    std::cout << "Inserisco (25) in cb1 " << std::endl;
    cb1.insert(25);
    std::cout << "15 deve essere la nuova _head e 25 la _tail " << std::endl;
    std::cout << "Elementi in cb1: " << cb1;
    std::cout << std::endl;

    std::cout << "Inserisco (30) in cb1 " << std::endl;
    cb1.insert(30);
    std::cout << "20 deve essere la nuova _head e 30 la _tail " << std::endl;
    std::cout << "Elementi in cb1: " << cb1;
    std::cout << std::endl;

    std::cout << "Dichiaro un cbuffer cb2 e lo uguaglio a cb1 " << std::endl;
    circolar_buffer<int> cb2 = cb1;
    std::cout << "Elementi in cb2: " << cb1;
    std::cout << std::endl;

    std::cout << "Aggiungo (35 40) a cb1 " << std::endl;
    cb1.insert(35);
    cb1.insert(40);
    std::cout << "Elementi in cb1: " << cb1;
    std::cout << "Elementi in cb2: " << cb2;
    std::cout << std::endl;


}

void test_elimina_testa() {
    /*Metodi richiesti: elimina_testa, operator <<, copy constructor, operator =*/
    std::cout << "TEST ELIMINA TESTA" << std::endl;
    std::cout << std::endl;

    std::cout << "Dichiaro un cbuffer cb1 con costruttore di default e inserisco (5 10 15) " << std::endl;
    circolar_buffer<int> cb1;
    cb1.insert(5);
    cb1.insert(10);
    cb1.insert(15);
    std::cout << "Elementi in cb1: " << cb1;
    std::cout << "_size di cb1: " << cb1.get_size() << std::endl;
    std::cout << "_occupati di cb1: " << cb1.get_occupati() << std::endl;
    std::cout << std::endl;

    std::cout << "Elimino la testa di cb1 " << std::endl;
    cb1.elimina_testa();
    std::cout << "Ora 10 sarà la nuova testa " << std::endl;
    std::cout << "Elementi in cb1: " << cb1;
    std::cout << "_size di cb1: " << cb1.get_size() << std::endl;
    std::cout << "_occupati di cb1: " << cb1.get_occupati() << std::endl;
    std::cout << std::endl;

    std::cout << "Inserisco in cb1 (20) " << std::endl;
    cb1.insert(20);
    std::cout << "Elementi in cb1: " << cb1;
    std::cout << "_size di cb1: " << cb1.get_size() << std::endl;
    std::cout << "_occupati di cb1: " << cb1.get_occupati() << std::endl;
    std::cout << "Elimino testa da cb1 " << std::endl;
    cb1.elimina_testa();
    std::cout << "Elementi in cb1: " << cb1;
    std::cout << "_size di cb1: " << cb1.get_size() << std::endl;
    std::cout << "_occupati di cb1: " << cb1.get_occupati() << std::endl;
    std::cout << "Elimino testa da cb1 " << std::endl;
    cb1.elimina_testa();
    std::cout << "Elementi in cb1: " << cb1;
    std::cout << "_size di cb1: " << cb1.get_size() << std::endl;
    std::cout << "_occupati di cb1: " << cb1.get_occupati() << std::endl;
    std::cout << "Elimino testa da cb1 " << std::endl;
    cb1.elimina_testa();
    std::cout << "Elementi in cb1: " << cb1;
    std::cout << "_size di cb1: " << cb1.get_size() << std::endl;
    std::cout << "_occupati di cb1: " << cb1.get_occupati() << std::endl;
    std::cout << "Elimino testa da cb1 " << std::endl;
    cb1.elimina_testa();
    std::cout << "Elementi in cb1: " << cb1;
    std::cout << "_size di cb1: " << cb1.get_size() << std::endl;
    std::cout << "_occupati di cb1: " << cb1.get_occupati() << std::endl;
    std::cout << std::endl;

    std::cout << "Riempo con (25 30 35) cb1 e dichiaro cb2 con copy constructor e cb3 con = " << std::endl;
    cb1.insert(25);
    cb1.insert(30);
    cb1.insert(35);
    circolar_buffer<int> cb2(cb1);
    circolar_buffer<int> cb3;
    cb3 = cb1;
    std::cout << "Elementi cb1: " << cb1;
    std::cout << "_occupati di cb1: " << cb1.get_occupati() << std::endl;
    std::cout << "Elementi cb2: " << cb2;
    std::cout << "_occupati di cb2: " << cb2.get_occupati() << std::endl;
    std::cout << "Elementi cb3: " << cb3;
    std::cout << "_occupati di cb3: " << cb3.get_occupati() << std::endl;
    std::cout << "Elimino 3 volte la testa di cb1 " << std::endl;
    cb1.elimina_testa();
    cb1.elimina_testa();
    cb1.elimina_testa();
    std::cout << "Elementi cb1: " << cb1;
    std::cout << "_occupati di cb1: " << cb1.get_occupati() << std::endl;
    std::cout << "Elementi cb2: " << cb2;
    std::cout << "_occupati di cb2: " << cb2.get_occupati() << std::endl;
    std::cout << "Elementi cb3: " << cb3;
    std::cout << "_occupati di cb3: " << cb3.get_occupati() << std::endl;
    std::cout << std::endl;
}

void test_operatore_quadre() {
    /*Metodi richiesti: costruttori vari, operator[]
    */
    std::cout << "TEST OPERATORE QUADRE" << std::endl;
    std::cout << std::endl;

    std::cout << "Dichiaro un cbuffer cb1 con costruttore di default e inserisco (5 10 15) " << std::endl;
    circolar_buffer<int> cb1;
    cb1.insert(5);
    cb1.insert(10);
    cb1.insert(15);
    std::cout << "Elementi in cb1: " << cb1;
    std::cout << "_size di cb1: " << cb1.get_size() << std::endl;
    std::cout << "_occupati di cb1: " << cb1.get_occupati() << std::endl;
    std::cout << std::endl;

    std::cout << "Provo ad accedere alla testa tramite l'operatore []: " << cb1[0] << std::endl;;
    std::cout << "Provo ad accedere al secondo elemento tramite l'operatore []: " << cb1[1] << std::endl;
    std::cout << "Provo ad accere al terzo elemento tramite l'operatore[]: " << cb1[2] << std::endl;
    std::cout << "Provo ad accere all'elemento in posizione 100000 tramite l'operatore []: " << cb1[100000] << std::endl;
    std::cout << std::endl;

    std::cout << "Dichiaro un cbuffer cb2 con costruttore alternativo _size = 6 e inserisco (4 8 12 16)" << std::endl;
    circolar_buffer<int> cb2(6);
    cb2.insert(4);
    cb2.insert(8);
    cb2.insert(12);
    cb2.insert(16);
    std::cout << "Elementi in cb2: " << cb2;
    std::cout << "_size di cb1: " << cb2.get_size() << std::endl;
    std::cout << "_occupati di cb1: " << cb2.get_occupati() << std::endl;
    std::cout << "Leggo gli elementi di cb2 con un ciclo for utilizzando []" << std::endl;
    for(int i = 0; i < (int)cb2.get_occupati(); i++)
        std::cout << "Elemento in posizione " << i << " : " << cb2[i] << std::endl;
    std::cout << std::endl;

    std::cout << "Provo ad accedere alla posizione 100000 di cb2 " << std::endl;
    std::cout << cb2[100000] << std::endl;
    std::cout << std::endl;

}

void test_evaluate_if() {
    /*Metodi richiesti: costruttori vari, evaluate_if
    */
    std::cout << "TEST EVALUATE_IF" << std::endl;
    std::cout << std::endl;

    std::cout << "Dichiaro un cbuffer cb1 con costruttore alternativo _size = 6 e inserisco (-5 10 -15 -20 30) " << std::endl;
    circolar_buffer<int> cb1(6);
    cb1.insert(-5);
    cb1.insert(10);
    cb1.insert(-15);
    cb1.insert(-20);
    cb1.insert(30);
    std::cout << "Elementi in cb1: " << cb1;
    std::cout << "_size di cb1: " << cb1.get_size() << std::endl;
    std::cout << "_occupati di cb1: " << cb1.get_occupati() << std::endl;
    std::cout << std::endl;

    std::cout << "Dichiaro un cbuffer cb2 con costruttore alternativo _size = 6 e inserisco (a B E a J u) " << std::endl;
    circolar_buffer<char> cb2(6);
    cb2.insert('a');
    cb2.insert('B');
    cb2.insert('E');
    cb2.insert('a');
    cb2.insert('J');
    cb2.insert('u');
    std::cout << "Elementi in cb2: " << cb2;
    std::cout << "_size di cb2: " << cb2.get_size() << std::endl;
    std::cout << "_occupati di cb2: " << cb2.get_occupati() << std::endl;
    std::cout << std::endl;

    std::cout << "Test funtore greater_than_zero " << std::endl;
    std::cout << "True -> numero > 0" << std::endl;
    std::cout << "False -> numero < 0" << std::endl;
    greater_than_zero funtore;
    for(int i = 0; i < (int)cb1.get_occupati(); i++) 
        evaluate_if(cb1[i], funtore);
    std::cout << std::endl;

    std::cout << "Test funtore is_even" << std::endl;
    std::cout << "True -> numero è pari" << std::endl;
    std::cout << "False -> numero è dispari" << std::endl;
    is_even funtore2;
    for(int i = 0; i < (int)cb1.get_occupati(); i++) 
        evaluate_if(cb1[i], funtore2);
    std::cout << std::endl;

    std::cout << "Test funtore is_divisible_by_three" << std::endl;
    std::cout << "True -> numero è divisibile per 3" << std::endl;
    std::cout << "False -> numero non divisibile per 3" << std::endl;
    is_divisible_by_three funtore3;
    for(int i = 0; i < (int)cb1.get_occupati(); i++) 
        evaluate_if(cb1[i], funtore3);
    std::cout << std::endl;

    std::cout << "Test funtore is_a_vowel" << std::endl;
    std::cout << "True -> elemento è una vocale" << std::endl;
    std::cout << "False -> elemento è una vocale" << std::endl;
    is_a_vowel funtore4;
    for(int i = 0; i < (int)cb1.get_occupati(); i++) 
        evaluate_if(cb2[i], funtore4);
    std::cout << std::endl;

    std::cout << "Test funtore is_uppercase" << std::endl;
    std::cout << "True -> elemento è maiuscolo" << std::endl;
    std::cout << "False -> elemento è minuscolo" << std::endl;
    is_uppercase funtore5;
    for(int i = 0; i < (int)cb1.get_occupati(); i++) 
        evaluate_if(cb2[i], funtore5);
    std::cout << std::endl;

}

void test_costruttore_iteratori() {
    /*Metodi necessari: costruttore con iteratori, evaluate_if, inserimento con riscrittura
    */
    std::cout << "TEST CON COSTRUTTORE ITERATORI " << std::endl;
    std::cout << std::endl;

    std::cout << "Dichiaro array di interi con 5 elementi (7 9 12 2 1)" << std::endl;
    int a[5] = {7, 9, 12, 2, 1};
	std::cout << "Dichiaro cbuffer con il costruttore dotato di iteratori" << std::endl;
	circolar_buffer<int> cb1(a,a+5, 5);
	std::cout << "Elementi di cb1: " << cb1;
    std::cout << "_occupati di cb1: " << cb1.get_occupati() << std::endl;
    std::cout << "_size di cb1: " << cb1.get_size() << std::endl;
    std::cout << std::endl;
    
    std::cout << "Inserisco in cb1 un elemento (19) avrò 9 nuova head e 19 tail" << std::endl;
    cb1.insert(19);
    std::cout << "cb1 dopo inserimenti elemento: " << cb1 << std::endl;
    
    std::cout << "Elimino la testa di cb1 la nuova testa sarà 12" << std::endl;
    cb1.elimina_testa();
    std::cout << "cb1 dopo eliminazione testa: " << cb1;
    std::cout << "_occupati di cb1: " << cb1.get_occupati() << std::endl;
    std::cout << "_size di cb1: " << cb1.get_size() << std::endl;
    std::cout << std::endl;

    std::cout << "Test funtore is_even" << std::endl;
    std::cout << "True -> numero è pari" << std::endl;
    std::cout << "False -> numero è dispari" << std::endl;
    is_even funtore;
    for(int i = 0; i < (int)cb1.get_occupati(); i++) 
        evaluate_if(cb1[i], funtore);
    std::cout << std::endl;
}