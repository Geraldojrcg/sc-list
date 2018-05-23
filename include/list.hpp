#ifndef _LIST_
#define _LIST_
#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <cstring>

namespace sc{
	template<typename T>
	/**@title Classe list, comporta todas as funções que podem ser usadas e demais classes de iteradores de tipo abstrato*/
	class list{
		using size_type = unsigned long;
		private:
			struct Node{
				T data;   //<! Store content.
				Node *next; //<! Pointer to the next block in the list.
				Node *prev; //<! Pointer to the last block in the list
				//<! Basic constructors for Node.
				Node(const T & d = T(), Node *p = nullptr, Node *n = nullptr): data{d}, prev{p}, next{n} {}
			};
		public:
			/**@title Classe const iterator, comporta todas as funções que podem ser usadas por iteradores constantes do tipo da lista*/
			class const_iterator{
				public:
					/**@title Construtor da classe const_iterator 
					 * @param (empty and single value)*/
                	const_iterator();
					/**@title Destrutor da classe const_iterator 
						 * @param (empty and single value)*/
					~const_iterator() = default;
					/**@title Operador * da classe const_iterator 
						 * @param (void)
						 * @return value*/
					const T & operator*() const;
					/**@title Operador ++it da classe const_iterator 
						 * @param (void)
						 * @return reference*/
					const_iterator & operator++(); // ++it;
					/**@title Operador it++ da classe const_iterator 
						 * @param (void)
						 * @return reference*/
					const_iterator operator++(int); // it++;
					/**@title Operador --it da classe const_iterator 
						 * @param (void)
						 * @return reference*/
					const_iterator & operator--(); // --it;
					/**@title Operador it-- da classe const_iterator 
						 * @param (void)
						 * @return reference*/
					const_iterator operator--(int); // it--;
					/**<@title Operador == da classe const_iterator 
						 * @param (const iterator& rhs)
						 * @return boolean*/
					bool operator== ( const const_iterator & rhs ) const;
					/**<@title Operador != da classe const_iterator 
						 * @param (const iterator& rhs)
						 * @return boolean*/
					bool operator!= ( const const_iterator & rhs ) const;
				protected:
					Node *current;
					const_iterator(Node *p);
					T & reference() const;
					friend class list<T>;
			};
			/**@title Classe iterator, comporta todas as funções que podem ser usadas por iteradores do tipo da lista*/
			class iterator : public const_iterator{
				public:
				/**@title Construtor da classe iterator 
						 * @param (empty and single value)*/
					iterator() : const_iterator(){/* Empty */};
					/**@title Destrutor da classe iterator 
						 * @param (empty and single value)*/
					~iterator() = default;
					/**@title Operador * da classe iterator 
						 * @param (void)
						 * @return value*/
					const T & operator*() const;
					T & operator*();
					/**@title Operador ++it da classe iterator 
						 * @param (void)
						 * @return reference*/
					iterator & operator++();
					/**@title Operador it++ da classe iterator 
						 * @param (void)
						 * @return reference*/
					iterator operator++(int);
					/**@title Operador --it da classe iterator 
						 * @param (void)
						 * @return reference*/
					iterator & operator--();
					/**@title Operador it-- da classe iterator 
						 * @param (void)
						 * @return reference*/
					iterator operator--(int);
           		protected:
					iterator(Node *p) : const_iterator(p){/* Empty */}
					friend class list<T>;
			};
			// [I] SPECIAL MEMBERS
			/**@title Construtor Default que cria uma lista vazia.*/
			list(); /*Default constructor that creates an empty list.*/
			/**@title Constrói uma lista com instâncias inseridas por padrão de T .
			 * @param (size_t count)
			*/
			explicit list(size_t count); 
			/*@title Constrói uma lista com o conteúdo do intervalo [first, last].
			*@param (InputIt first, InputIt last)
			*/
			template<typename InputIt>
			list(InputIt first, InputIt last);
			/**@title Construtor de cópia. Constrói uma lista com a cópia profunda do conteúdo de outra.
			 * @param const list& other - lista cópia.
			*/
			list(const list& other);/*Copy constructor. Constructs the list with the deep copy of the contents of other .*/
			
			/**@title Constrói uma lista com o conteúdo da lista inicializadora init.
			 * @param const std::initializer_list<T> il - lista inicializadora para inicializar os elementos da lista.
			*/ 
			list(std::initializer_list<T> ilist);/*Constructs the list with the contents of the initializer list init .*/
			/**@title Destrutor da classe list.*/
			~list();//Destructs the list. The destructors of the elements are called and the used storage is de-
					//allocated. Note, that if the elements are pointers, the pointed-to objects are not destroyed.

			/**@title Operador = (de atribuição) da classe list, receber uma outra list 
			 * @param const list& other
			*/
			list& operator=(const list& other);/*Copy assignment operator. Replaces the contents with a copy of the contents of other.*/

			/**@title Operador = (de atribuição) da classe list, receber uma lista inicializadora 
			 * @param std::initializer_list<T> ilist
			*/
			list& operator=(std::initializer_list<T> ilist);/*Replaces the contents with those identified by initializer list ilist .*/

			// [II] ITERATORS
			/**@title função begin da classe list, retorna um iterator que aponta para o nó inicial da lista
			 *@param void
			 *@return iterator it*/
			iterator begin();
			/**@title função begin da classe list, retorna um const_iterator que aponta para o nó inicial da lista
			 *@param void
			 *@return const_iterator it*/
			const_iterator cbegin() const;
			/**@title função begin da classe list, retorna um iterator que aponta para o nó final da lista
			 *@param void
			 *@return iterator it*/
			iterator end();
			/**@title função begin da classe list, retorna um const_iterator que aponta para o nó final da lista
			 *@param void
			 *@return const_iterator it*/
			const_iterator cend() const;

			// [III] COMMOM OPERATIONS TO ALL LISTS IMPLEMENTATIONS
			/**@title função size da classe list, retorna o tamanho size da list
			 * @param void
			 * @return size_type size da list
			*/
        	int size() const;
			/**@title função empty da classe list, retorna verdadeiro se a lista estiver vazia e falso se não vazio
			 * @param void
			 * @return boolean
			*/
        	bool empty() const;

			/**@title função push_back da classe list, insere um elemento no ultimo nó da list
			 * @param const T & value
			 * @return void
			*/
			void push_back( const T & value);

			/**@title função push_front da classe list, insere um elemento no primeiro nó do lista
			 * @param const T & value
			 * @return void
			*/
			void push_front( const T & value);

			/**@title função pop_back da classe list, exclui o elemento no ultimo nó da list
			 * @param void
			 * @return void
			*/
			void pop_back();

			/**@title função pop_back da classe list, exclui o elemento no primeiro nó da list
			 * @param void
			 * @return void
			*/
			void pop_front();
			
			/**@title função back da classe list, retorna o elemento do ultimo nó da list
			 * @param void
			 * @return void
			*/
			const T & back() const;
			/**@title função back da classe list, retorna o elemento do primeiro nó da list
			 * @param void
			 * @return void
			*/
			const T & front() const;
			/**@title Apaga todo o conteúdo da lista*/
			void clear();

			/**@title Operador == da classe list, compara duas listas e retorna true se eles forem iguais e falso se não
			 *@param const list<T>& rhs
			 *@return boolean*/
			bool operator==(const list<T>& rhs);

			/**@title Operador != da classe list, compara duas listas e retorna true se eles forem diferentes e falso se não
			 *@param const list<T>& rhs
			 *@return boolean*/
			bool operator!=(const list<T>& rhs);

			// [IV] LIST CONTAINER OPERATIONS THAT REQUIRE ITERATORS

			/**@title função erase da classe list, como como parametro um iterator, e deleta o valor na posição anteraior 
			 * ao apontado pelo iterator e retorna um iterator para o endereço do novo elemento da posição
			 *@param iterator pos
			 *@return iterator*/
			iterator erase( iterator pos);

			/**@title função erase (com range) da classe list, como como parametro um range, e deleta os valores do range 
			 * e retorna um iterator para o endereço do primeiro elemento do range
			 *@param iterator first, iterator last
			 *@return iterator*/
			iterator erase(iterator first, iterator last);
			
			/**@title função assign (com range) da classe list, substitui o conteúdo da lista por cópias dos elementos no intervalo [primeiro; último). 
			 *@param InItr first, InItr last
			 *@return void*/
			template<typename InputIt>
			void assign(InputIt first, InputIt last);

			/**@title função assign (com lista) da classe list, substitui o conteúdo do vetor com os elementos da lista de inicializadores ilist. 
			 *@param std::initializer_list<T> ilist
			 *@return void*/
			void assign(std::initializer_list<T> ilist);
			
			/**@title função assign da classe list, substitui o conteúdo com cópias de contagem do valor 
			 *@param size_type count, const T & value
			 *@return void*/
			void assign(size_type count, const T & value);
			
			/**@title função insert da classe list, como como parametro um iterator e um valor, e insere o valor na posição anteraior 
			 * ao apontado pelo iterator e retorna um iterator para o endereço do novo elemento
			 *@param iterator pos, const T& value
			 *@return iterator*/
			iterator insert( iterator pos, const T & value );

        	/**@title função insert (com list) da classe list, como como parametro um iterator e uma lista, e insere os valores da lista na posição anteraior 
			 * ao apontado pelo iterator e retorna um iterator para o endereço do primeiro elemento da lista
			 *@param iterator pos, std::initializer_list<T> ilist
			 *@return iterator*/
			iterator insert( iterator pos, std::initializer_list<T> ilist );
			
			/**@title função insert (com range) da classe list, como como parametro um iterator e um um range, e insere os valores do range na posição anteraior 
			 * ao apontado pelo iterator e retorna um iterator para o endereço do primeiro elemento do range
			 *@param iterator pos, InItr first, InItr last
			 *@return iterator*/
			template<typename InItr>
       		iterator insert(iterator pos, InItr first, InItr last);

		private:
			Node * head; //<! Head Node.
			Node * tail; //<! Tail Node.             '
			int m_size; //<! Size of list.

			void init();

	};
	#include "list.inl"
}
#endif
