#ifndef CBUFFER_H
#define CBUFFER_H

#include <ostream> // std::ostream
#include <iostream>
#include <cassert>
#include <algorithm>
#include <stdexcept>
#include <iterator> // std::forward_iterator_tag
#include <cstddef>  // std::ptrdiff_t

/**
@file cbuffer.h 
@brief Dichiarazione della classe cbuffer
**/

/**
@brief Buffer circolare templato

Classe che rappresenta un buffer circolare templato. La dimensione puo' essere scelta in fase di costruzione.
**/
template <typename T>
class cbuffer {
	struct node {
  		T value;
  		node *next;
		node() : value(), next(0) {}
		node(const T &v, node *n = 0) : value(v), next(n) {}
	};

public:
	class const_iterator; // forward declaration

	class iterator {
		node *n;

	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef T                         value_type;
		typedef ptrdiff_t                 difference_type;
		typedef T*                        pointer;
		typedef T&                        reference;

	
		iterator() : n(0) {}
		
		iterator(const iterator &other) : n(other.n) {}

		iterator& operator=(const iterator &other) {
			n = other.n;
			return *this;
		}

		~iterator() {
			n = 0;
			delete n;
		}

		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const {
			return n->value;
		}

		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const {
			return &(n->value);
		}

		// Operatore di iterazione post-incremento
		iterator operator++(int) {
			iterator tmp(*this);
			n = n->next;
			return tmp;
		}

		// Operatore di iterazione pre-incremento
		iterator& operator++() {
			n = n->next;
			return *this;
		}

		// Uguaglianza
		bool operator==(const iterator &other) const {
			return n == other.n;
		}

		// Diversita'
		bool operator!=(const iterator &other) const {
			return n != other.n;
		}
		
		// Solo se serve anche const_iterator aggiungere le seguenti definizioni
		friend class const_iterator;

		// Uguaglianza
		bool operator==(const const_iterator &other) const {
			return n == other.n;
		}

		// Diversita'
		bool operator!=(const const_iterator &other) const {
			return n != other.n;
		}

		// Solo se serve anche const_iterator aggiungere le precedenti definizioni

	private:
		//Dati membro

		// La classe container deve essere messa friend dell'iteratore per poter
		// usare il costruttore di inizializzazione.
		friend class cbuffer; // !!! Da cambiare il nome!

		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		iterator(node* nn) : n(nn) {}
		
		// !!! Eventuali altri metodi privati
		
	}; // classe iterator
	
	// Ritorna l'iteratore all'inizio della sequenza dati
	iterator begin() {
		return iterator(_head);
	}
	
	// Ritorna l'iteratore alla fine della sequenza dati
	iterator end() {
		if (_occupied == _size)
			return iterator(_head);
		return iterator(0);
	}
	
	
	
	class const_iterator {
		node *n;
	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef T                         value_type;
		typedef ptrdiff_t                 difference_type;
		typedef const T*                  pointer;
		typedef const T&                  reference;

	
		const_iterator() : n(0) {}
		
		const_iterator(const const_iterator &other) : n(other.n) {}

		const_iterator& operator=(const const_iterator &other) {
			n = other.n;
			return *this;	
		}

		~const_iterator() {
			n = 0;
			delete n;
		}

		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const {
			return n->value;
		}

		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const {
			return &(n->value);
		}
		
		// Operatore di iterazione post-incremento
		const_iterator operator++(int) {
			const_iterator tmp(*this);
			n = n->next;
			return tmp;
		}

		// Operatore di iterazione pre-incremento
		const_iterator& operator++() {
			n = n->next;
			return *this;
		}

		// Uguaglianza
		bool operator==(const const_iterator &other) const {
			return n == other.n;
		}
		
		// Diversita'
		bool operator!=(const const_iterator &other) const {
			return n != other.n;
		}

		// Solo se serve anche iterator aggiungere le seguenti definizioni
		
		friend class iterator;

		// Uguaglianza
		bool operator==(const iterator &other) const {
			return n == other.n;
		}

		// Diversita'
		bool operator!=(const iterator &other) const {
			return n != other.n;
		}

		// Costruttore di conversione iterator -> const_iterator
		const_iterator(const iterator &other) : n(other.n) {}

		// Assegnamento di un iterator ad un const_iterator
		const_iterator &operator=(const iterator &other) {
			n = other.n;
			return *this;
		}

		// Solo se serve anche iterator aggiungere le precedenti definizioni

	private:
		friend class cbuffer;

		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		const_iterator(node *nn) : n(nn) {}
		
		// !!! Eventuali altri metodi privati
		
	}; // classe const_iterator
	
	// Ritorna l'iteratore all'inizio della sequenza dati
	const_iterator begin() const {
		return const_iterator(_head);
	}
	
	// Ritorna l'iteratore alla fine della sequenza dati
	const_iterator end() const {
		if (_occupied == _size)
			return const_iterator(_head);
		return const_iterator(0);
	}
	
	


	private:
		unsigned int _size;
		unsigned int _occupied;
		node* _head;
		node* _tail;

				/** 
		   @brief Ritorna un puntatore costante al nodo i-esimo

		   Metodo che ritorna un puntatore costante al nodo i-esimo.
		   Se questo non esiste, ritorna un puntatore a null

		   @param index Indice del nodo da estrarre
		   @return Puntatore costante al nodo index-esimo
		**/
		const node* get_node(unsigned int index) const {
			if (index < _occupied) {
				unsigned int count = 0;
				node *tmp = _head;
				while (tmp != 0 && count < index) {
					tmp = tmp->next;
					count++;
				}
				return tmp;
			}
			return 0;
		}

		/** 
		   @brief Ritorna un puntatore al nodo i-esimo

		   Metodo che ritorna un puntatore al nodo i-esimo.
		   Se questo non esiste, ritorna un puntatore a null

		   @param index Indice del nodo da estrarre
		   @return Puntatore costante al nodo index-esimo
		**/
		node* get_node(unsigned int index) {
			if (index < _occupied) {
				unsigned int count = 0;
				node *tmp = _head;
				while (tmp != 0 && count < index) {
					tmp = tmp->next;
					count++;
				}
				return tmp;
			}
			return 0;
		}

	public:

		/**
			@brief Costruttore di default
			Costruttore di default per istanziare un cbuffer vuoto.
		**/
		cbuffer(): _size(0), _occupied(0), _head(0), _tail(0) { // initialization list
			#ifndef NDEBUG
			std::cout << "cbuffer::cbuffer()" << std::endl;
			#endif
		}
		
		/**
			@brief Costruttore secondario

			Costruttore secondario. Permette di istanziare un cbuffer con una data dimensione.
			@param size Dimensione del cbuffer da istanziare 
		**/
		explicit cbuffer(const unsigned int size) : _size(0), _occupied(0), _head(0), _tail(0) {
			_size = size;
			#ifndef NDEBUG
			std::cout << "cbuffer::cbuffer(unsigned int)" << std::endl;
			#endif
		}

		/**
			@brief Distruttore (METODO FONDAMENTALE)

			Distruttore. Rimuove la memoria allocata da cbuffer.
		**/
		~cbuffer() {
			clear();
			#ifndef NDEBUG
				std::cout << "cbuffer::~cbuffer()" << std::endl;
			#endif
		}

		/**
			@brief Metodo per svuotare il cbuffer

			Svuota il cbuffer e lascia la memoria in uno stato consistente
		**/
  		void clear() {
			node *tmp = _head;
			while(_occupied > 0 && tmp != 0) {
				node* tmp2 = tmp->next;
				delete tmp;
				tmp = tmp2;
				_occupied--;
			}
			_size = 0;
			_head = 0;
			_tail = 0;
			_occupied = 0;
			#ifndef NDEBUG
				std::cout << "cbuffer::clear()" << std::endl;
			#endif
		}

		/**
			@brief Copy constructor (METODO FONDAMENTALE)

			Costruttore copia. 
			Permette di istanziare un cbuffer con i valori presi da un altro cbuffer.
			@param other cbuffer da usare per creare quello corrente
			@throw Eccezione dovuta alla tentata allocazione della memoria
		**/
		cbuffer(const cbuffer &other) : _size(0), _occupied(0), _head(0), _tail(0)  {
			const node *tmp = other._head;	
			_size = other._size;	
			unsigned int count = 0;
			try {
				while (count < _size) {
					insert(tmp->value);
					tmp = tmp->next;
					++count;
				}
			} catch(...) {
				clear();
				throw;
			}		

			#ifndef NDEBUG
			std::cout << "cbuffer::cbuffer(const cbuffer&)" << std::endl;
			#endif
		}

		/**
			Operatore di assegnamento
		
			@param other lista da copiare
			@return reference a this
			@throw eccezione di allocazione di memoria
		*/
		cbuffer& operator=(const cbuffer &other) {
			if (this != &other) {
				cbuffer tmp(other);
				std::swap(tmp._size, _size);
				std::swap(tmp._occupied, _occupied);
				std::swap(tmp._head, _head);
				std::swap(tmp._tail, _tail);
			}
			return *this;
		}


		/**
			Inserisce un elemento in coda nel cbuffer.
			@param value valore da inserire
			@throw eccezione di allocazione di memoria
			@return boolean che vale false se e solo se la _size del cbuffer è 0
		*/
		bool insert(const T &value) {
			if (_size == 0)
				return false;		
			// Se il cbuffer non ha ancora elementi e la sua size è > 0, inserisco in testa creando il primo nodo
			try {
				if (_occupied == 0) {
					_head = new node(value, 0);
					_tail = _head;
					_occupied = 1;
					return true;
				}
				// Se il cbuffer è pieno, inserisco l'elemento dove ora ho la testa, e la testa diventa il next della vecchia
				else if (_occupied == _size) {
					node *tmp = _head;
					_head = _head->next;
					delete tmp;
					_tail->next = new node(value, _head);
					_tail = _tail->next;
					return true;
				}
				else {
					++_occupied;
					// Se questo è l'ultimo elemento, i.e. se il successore dell'elemento che aggiungo ora è la testa
					if (_occupied == _size) {
						_tail->next = new node(value, _head);
					}
					// Se non sono ancora arrivato alla fine del cbuffer 
					else {
						_tail->next = new node(value, 0);
					}
					_tail = _tail->next;
					return true;	
				}
			} catch (...) {
				clear();
				throw;
			}
			#ifndef NDEBUG
				std::cout << "cbuffer::insert()" << std::endl;
			#endif

		}

		/**
			@brief Dimensione del cbuffer

			Metodo per conoscere la dimensione del cbuffer
			@return dimensione del cbuffer, _size
		**/
		unsigned int size() const {
			return _size;
		}

		/**
			@brief Elementi occupati del cbuffer

			Metodo per conoscere quanti sono gli elementi occupati del cbuffer
			@return numero di elementi occupati, _occupied
		**/
		unsigned int occupied() const {
			return _occupied;
		}

		/**
			Costruttore secondario che costruisce un cbuffer a partire
			da una sequenza generica di dati identificata da due 
			iteratori.

			@param size dimensione del cbuffer da creare
			@param begin iteratore di inizio della sequenza
			@param end iteratore di fine della sequenza

			@throw eccezione di allocazione di memoria
		*/
		template <typename IterT>
		cbuffer(const unsigned int size, IterT begin, IterT end) : _size(0), _occupied(0), _head(0), _tail(0) {
			try {
				_size = size;		
				for(; begin != end; ++begin) {
					insert(static_cast<T>(*begin));		
				}
			}
			catch(...) {
				clear();
				throw;
			}
		}

		/**
		    @brief Metodo che rimuove l'elemento in testa del cbuffer

			Rimuove l'elemento in testa, se questa esiste. In tal caso, riduce il numero
			degli occupati di 1 ed aggiorna il cbuffer
		*/
		void remove_head() {
			if (_head != 0) {
				// assegno esplicitamente a null, probabilmente non necessario
				if (_occupied == _size) {
					_tail->next = 0;
				}
				node* tmp;
				tmp = _head;
				_head = _head->next;
				--_occupied;
				delete tmp;
			}
		}


		/**
			@brief Accesso ai dati in lettura/scrittura (stile C++ con operatore)

			Metodo getter per leggere il valore index-esimo dell'array. 

			@pre E' necessario che index < _occupied
			@param index Indice della cella dell'array da leggere
			@return Il valore della cella index-esima
		**/
		T &operator[](unsigned int index) {
			assert(index < _occupied && "ERRORE! Accesso ad un indice inesistente"); // asserzione; se viene violata il programma termina
			return get_node(index)->value;
		}

		/**
			@brief Accesso ai dati in lettura (stile C++ con operatore)

			Metodo setter per scrivere il valore index-esimo dell'array. 

			@pre E' necessario che index < _occupied
			@param index Indice della cella dell'array da scrivere
		**/
		const T &operator[](unsigned int index) const {
			assert(index < _occupied && "ERRORE! Accesso ad un indice inesistente"); // asserzione; se viene violata il programma termina
			return get_node(index)->value;
		}

};




/**
	@brief Operatore di stream

	Permette di spedire su uno stream di output il contenuto del cbuffer.

	@param os stream di output
	@param cb cbuffer del quale vogliamo stampare il contenuto
	@return Il riferimento allo stream di output
**/
template <typename T>
std::ostream& operator<<(std::ostream &os, const cbuffer<T> & cb) {
	for (unsigned int i = 0; i < cb.occupied(); ++i)
		os << cb[i] << " ";
	return os;
}

/**
	@brief Funzione evaluate_if

	Permette di spedire su uno stream di output, per ogni elemento del cbuffer, se P(cb[i]) è true o false
 
	@param cb cbuffer del quale vogliamo stampare il contenuto
	@param P funtore unario
**/
template <typename T, typename P>
void evaluate_if(const cbuffer<T> &cb, const P &funct) {
	for (unsigned int i = 0; i < cb.occupied(); ++i)
		std::cout << "[" << i << "]: " << (funct(cb[i]) ? "true" : "false") << std::endl;
}



#endif