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

	private:
		unsigned int _size;
		unsigned int _currentpos;
		unsigned int _occupied;
		T* _buffer;
    
	
	public:

	/**
		@brief Costruttore di default
		Costruttore di default per istanziare un cbuffer vuoto.
	**/
	cbuffer(): _size(0), _currentpos(0), _occupied(0), _buffer(0) { // initialization list
		#ifndef NDEBUG
		std::cout << "cbuffer::cbuffer()" << std::endl;
		#endif
	}

	/**
		@brief Costruttore secondario

		Costruttore secondario. Permette di istanziare un cbuffer con una data dimensione.
		@param size Dimensione del cbuffer da istanziare 
	**/
	explicit cbuffer(unsigned int size) : _size(0), _currentpos(0), _occupied(0), _buffer(0) {
		_buffer = new T[size];
		_size = size;

		#ifndef NDEBUG
		std::cout << "cbuffer::cbuffer(unsigned int)" << std::endl;
		#endif
	}


	/**
		@brief Costruttore secondario

		Costruttore secondario. Permette di istanziare un cbuffer con una data dimensione
		e di inizializzare ogni cella con il valore dato
		@param size Dimensione del cbuffer da istanziare
		@param value Valore da usare per inizizalizzare le celle dell'array
	**/
	cbuffer(unsigned int size, const T &value) : _size(0), _currentpos(0), _occupied(0), _buffer(0) {
		_buffer = new T[size];
		_size = size;

		try {
			for(unsigned int i=0 ; i < _size; ++i) {
				_buffer[i] = value;
				_occupied++;
				_currentpos++;
			}
		}
		catch(...) {
			delete[] _buffer;
			_size = 0;
			_buffer = 0;
			_occupied = 0;
			_currentpos = 0;
			throw;
		}
		#ifndef NDEBUG
		std::cout << "cbuffer::cbuffer(unsigned int, T)" << std::endl;
		#endif
	}

	/**
		@brief Copy constructor (METODO FONDAMENTALE)

		Costruttore copia. 
		Permette di istanziare un cbuffer con i valori presi da un altro cbuffer.
		@param other cbuffer da usare per creare quello corrente
	**/
	cbuffer(const cbuffer &other) : _size(0), _currentpos(0), _occupied(0), _buffer(0)  {
		_buffer = new T[other._size];
		_size = other._size;

		try {
			for(unsigned int i=0; i<_size; ++i) {
				_buffer[i] = other._buffer[i];
				_occupied++;
				_currentpos++;
			}
		}
		catch(...) {
			delete[] _buffer;
			_size = 0;
			_buffer = 0;
			_occupied = 0;
			_currentpos = 0;
			throw;
		}

		#ifndef NDEBUG
		std::cout << "cbuffer::cbuffer(const cbuffer&)" << std::endl;
		#endif
	}

	/**
		@brief Operatore di assegnamento (METODO FONDAMENTALE)

		Operatore di assegnamento. Permette la copia tra cbuffer.
		@param other cbuffer sorgente
		@return Riferimento a this
	**/
	cbuffer &operator=(const cbuffer &other) {
		if (this != &other) {
			// Proviamo a copiare i nuovi dati in un dbuffer di appoggio
			// Se la copia fallisce, viene lanciata una eccezione e l'esecuzione
			// torna al chiamante (non la stiamo gestendo)  
			cbuffer tmp(other);
			// Se la copia riesce, scambiamo i dati di this con quelli del cbuffer di appoggio
			std::swap(tmp._buffer, this->_buffer);
			std::swap(tmp._size, this->_size);
			std::swap(tmp._occupied, this->_occupied);
			std::swap(tmp._currentpos, this->_currentpos);
			// All'uscita dell'if, tmp viene automaticamente distrutto e quindi vengono 
			//  rimossi i vecchi dati di this che ora si trovano dentro tmp!
		}

		#ifndef NDEBUG
		std::cout << "cbuffer::operator=(const cbuffer&)" << std::endl;
		#endif

		return *this;
	}

	/**
		@brief Distruttore (METODO FONDAMENTALE)

		Distruttore. Rimuove la memoria allocata da cbuffer.
	**/
	~cbuffer() {
		delete[] _buffer;
		_buffer = 0;
		_size = 0;
		_occupied = 0;
		_currentpos = 0;

		#ifndef NDEBUG
		std::cout << "cbuffer::~cbuffer()" << std::endl;
		#endif
	}


        // cbuffer &operator=(const cbuffer &other)




        // size() const
		// occupied() const 
		// current_position() const
		// insert_tail()
		// remove_head()
		// operator[]
		// forward iterator
			// cbuffer[0] è l'elemento più vecchio
			// cbuffer.begin() è l'iteratore all'elemento più vecchio


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