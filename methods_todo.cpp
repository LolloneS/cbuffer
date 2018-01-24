	/**
			@brief Copy constructor (METODO FONDAMENTALE)

			Costruttore copia. 
			Permette di istanziare un cbuffer con i valori presi da un altro cbuffer.
			@param other cbuffer da usare per creare quello corrente
			@throw Eccezione dovuta alla tentata allocazione della memoria
		**/
		cbuffer(const cbuffer &other) : _size(0), _occupied(0), _current(0), _head(0), _tail(0)  {
			const node *tmp = other._head;		
			try {
				while (tmp != 0) {
					insert(tmp->value);
					tmp = tmp->next;
				}
			}
			catch(...) {
				clear();
				throw;
			}		

			#ifndef NDEBUG
			std::cout << "cbuffer::cbuffer(const cbuffer&)" << std::endl;
			#endif
		}


		/**
			Inserisce un elemento nel cbuffer.
			@param value valore da inserire
			@throw eccezione di allocazione di memoria
		*/
		void insert(const T &value) {
			node *n = new node(value);

			if (_head == 0) {
				_head = n;
				_size = 1;
				return;
			}

			nodo *current = _head, *prev=_head;

			while (current!=0 && _funct(current->value, value)) {
				prev = current;
				current = current->next;		
			} 
			
			if(current == _head) {
				n->next = _head;
				_head = n;
				_size++;
				return;
			}

			n->next = current;
			prev->next = n;		
			_size++;
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



// evaluate_if