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


	private:
		unsigned int _size;
		unsigned int _occupied;
		node* _current;
		node* _head;
		node* _tail;

	public:

		/**
			@brief Costruttore di default
			Costruttore di default per istanziare un cbuffer vuoto.
		**/
		cbuffer(): _size(0), _occupied(0), _current(0), _head(0), _tail(0) { // initialization list
			#ifndef NDEBUG
			std::cout << "cbuffer::cbuffer()" << std::endl;
			#endif
		}
		
		/**
			@brief Costruttore secondario

			Costruttore secondario. Permette di istanziare un cbuffer con una data dimensione.
			@param size Dimensione del cbuffer da istanziare 
		**/
		explicit cbuffer(unsigned int size) : _size(0), _occupied(0), _current(0), _head(0), _tail(0) {
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
		}

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
			_current = 0;
			_occupied = 0;
		}

		/**
			@brief Copy constructor (METODO FONDAMENTALE)

			Costruttore copia. 
			Permette di istanziare un cbuffer con i valori presi da un altro cbuffer.
			@param other cbuffer da usare per creare quello corrente
			@throw Eccezione dovuta alla tentata allocazione della memoria
		**/
		cbuffer(const cbuffer &other) : _size(0), _occupied(0), _current(0), _head(0), _tail(0)  {
			const node *tmp = other._head;	
			_size = other._size;	
			try {
				while (tmp != 0) {
					insert(tmp->value);
					tmp = tmp->next;
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
			Inserisce un elemento in coda nel cbuffer.
			@param value valore da inserire
			@throw eccezione di allocazione di memoria
		*/
		void insert(const T &value) {			
			// Se il cbuffer non ha ancora elementi e la sua size è > 0, inserisco in testa creando il primo nodo
			if (_occupied == 0 && _size != 0) {
				_head = new node(value, 0);
				_tail = _head;
				_current = _head;
				_occupied = 1;
			}
			// Se il cbuffer è pieno, inserisco l'elemento dove ora ho la testa, e la testa diventa il next della vecchia
			else if (_occupied == _size) {
				node *tmp = _head;
				_head = _head->next;
				_current = _head;
				delete tmp;
				_tail->next = new node(value, _head);
				_tail = _tail->next;
			}
			else {
				_occupied++;
				// Se questo è l'ultimo elemento, i.e. se il successore dell'elemento che aggiungo ora è la testa
				if (_occupied == _size) {
					_tail->next = new node(value, _head);
					_current = _head;
				}
				// Se non sono ancora arrivato alla fine del cbuffer 
				else {
					_tail->next = new node(value, 0);
					_current = _tail;

				}
				_tail = _tail->next;	
			}
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
	for (unsigned int i = 0; i < cb.size(); ++i)
		os << cb[i] << " ";
	return os;
}


// evaluate_if

#endif