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
    public:
        // cbuffer() : .....
        // explicit cbuffer(size) : .....
        // cbuffer(const cbuffer &other) : ....
        // cbuffer &operator=(const cbuffer &other)
        // ~cbuffer()
        // size() const
		// occupied() const 
		// current_position() const
		// insert_tail()
		// remove_head()
		// operator[]
		// forward iterator
			// cbuffer[0] è l'elemento più vecchio
			// cbuffer.begin() è l'iteratore all'elemento più vecchio


	private:
		unsigned int size;
		unsigned int currentpos;
		unsigned int occupied;
		T* buffer;

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