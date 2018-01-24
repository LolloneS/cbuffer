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
  		bool used;
  		T value;
  		node *next;
		node() : used(false), value(), next(0) {}
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