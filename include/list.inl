#include "list.hpp"
/*CONST ITERATOR*/
	template <typename T>
	list<T>::const_iterator::const_iterator() : current(nullptr){

	}
	template <typename T>
	const T & list<T>::const_iterator::operator*() const{
		return reference();
	}
	template <typename T>
	list<T>::const_iterator::const_iterator(Node *p) : current(p){

	}
	template <typename T>
	typename list<T>::const_iterator & list<T>::const_iterator::operator++(){
		current = current->next;
		return *this;
	}
	template <typename T>
	typename list<T>::const_iterator list<T>::const_iterator::operator++(int){
		auto temp(*this);
		++(*this);
		return temp;
	}
	template <typename T>
	typename list<T>::const_iterator & list<T>::const_iterator::operator--(){
		current = current->prev;
		return *this;
	}
	template <typename T>
	typename list<T>::const_iterator list<T>::const_iterator::operator--(int){
		auto temp(*this);
		--(*this);
		return temp;
	}
	template <typename T>
	bool list<T>::const_iterator::operator==(const const_iterator & rhs ) const {
		return current == rhs.current;
	}
	template <typename T>
	bool list<T>::const_iterator::operator!=(const const_iterator & rhs ) const {
		return !(*this == rhs);
	}
	template <typename T>
	T & list<T>::const_iterator::reference() const{
		return current->data;
	}
/*ITERATOR*/
	template <typename T>
	T & list<T>::iterator::operator*(){
		return const_iterator::reference();
	}
	template <typename T>
	typename list<T>::iterator & list<T>::iterator::operator++(){
		this->current = this->current->next;
		return *this;
	}
	template <typename T>
	typename list<T>::iterator list<T>::iterator::operator++(int){
		auto temp(*this);
		++(*this);
		return temp;
	}
	template <typename T>
	typename list<T>::iterator & list<T>::iterator::operator--(){
		this->current = this->current->prev;
		return *this;
	}
	template <typename T>
	typename list<T>::iterator list<T>::iterator::operator--(int){
		auto temp(*this);
		--(*this);
		return temp;
	}

	template<typename T>
	void list<T>::init(){
		m_size = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}
/*LIST*/
	/*[I] SPECIAL MEMBERS*/
	template<typename T>
	list<T>::list( void ){
		init();
	}
	template<typename T>
	list<T>::list(size_t count){
				init();
        m_size = count;
	}
	template<typename T>
	template<typename InputIt>
	list<T>::list(InputIt first, InputIt last ){
		init();
		assign(first, last);
	}
	template<typename T>
	list<T>::list( const list& other){
		init();
		assign(other.begin(), other.begin());
	}
	template<typename T>
	list<T>::list(std::initializer_list<T> ilist){
		init();
		assign(ilist.begin(), ilist.end());
	}
	template<typename T>
	list<T>::~list(void){
		clear();
		delete head;
		delete tail;
	}
	template<typename T>
	list<T> & list<T>::operator=( const list& other){
		init();
		assign(other.begin(), other.begin());
	}
	template<typename T>
	list<T> & list<T>::operator=(std::initializer_list<T> ilist){
		init();
		assign(ilist.begin(), ilist.end());
	}

	/*[II] ITERATORS*/
	template <typename T>
	typename list<T>::iterator list<T>::begin(){
		return head;
	}

	template <typename T>
	typename list<T>::const_iterator list<T>::cbegin() const{
		return head;
	}

	template <typename T>
	typename list<T>::iterator  list<T>::end(){
		return tail->prev->next;
	}

	template <typename T>
	typename list<T>::const_iterator list<T>::cend() const{
		return tail->prev->next;
	}

	/*[III] COMMOM OPERATIONS TO ALL LISTS IMPLEMENTATIONS*/
	template <typename T>
	int list<T>::size() const{
		return m_size;
	}

	template <typename T>
	bool list<T>::empty() const{
		return (size()== 0);
	}


	template <typename T>
	void list<T>::clear(){
		while( !empty()){
			pop_front();
		}
		m_size = 0;
	}

	template<typename T>
	void list<T>::push_back( const T & value){

		if(m_size == 0){
			head = new Node(value, nullptr, nullptr);
			tail = new Node;
			head->next = tail;
			tail->prev = head;
		}else{
			Node *new_tail = new Node(value, tail->prev, tail);
			tail->prev->next = new_tail;
			tail = new Node;
			tail->prev = new_tail;
		}

		m_size++;
	}

	template<typename T>
	void list<T>::push_front( const T & value){

		if(m_size == 0){
			head = new Node(value, nullptr, nullptr);
			tail = new Node;
			head->next = tail;
			tail->prev = head;
		}else{
			Node *new_head = new Node(value, nullptr, head);
			head = new_head;
		}

		m_size++;
	}

	template<typename T>
	void list<T>::pop_back(){
		Node *new_tail = new Node(tail->prev->data, tail->prev->prev, nullptr);
		tail = new_tail;
		m_size--;
	}

	template<typename T>
	void list<T>::pop_front(){
		Node *new_head = new Node(head->next->data, nullptr, head->next->next);
		head = new_head;
		m_size--;
	}

	template<typename T>
	const T & list<T>::back() const{
		return tail->data;
	}

	template<typename T>
	const T & list<T>::front() const{
		return head->data;
	}

	template <typename T>
	bool list<T>:: operator==(const list<T>& rhs){
					if(m_size != rhs.m_size)
									return false;
					auto inil = cbegin();
					auto inir = rhs.cbegin();

					while(inil != cend()){
						if(*inil != *inir){
							return false;
						}

						inil++;
						inir++;
					}
					return true;
	}

	template <typename T>
	bool list<T>:: operator!=(const list<T>& rhs){
				if(m_size != rhs.m_size){
						return true;
				}
				auto inil = cbegin();
				auto inir = rhs.cbegin();

				while(inil != cend()){
					if(*inil != *inir){
						return true;
					}

					inil++;
					inir++;
				}

				return false;
	}

	template<typename T>
	typename list<T>::iterator list<T>::erase(typename list<T>::iterator pos){
		Node *p = pos.current;
		if(pos == begin() ){
			pop_front();
			return head;
		}
		if(pos == end()){
			pop_back();
			return tail->prev;
		}
		iterator retVal{ p->next };
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		m_size--;

		return retVal;
	}
	template<typename T>
	typename list<T>::iterator list<T>::erase(typename list<T>::iterator first, typename list<T>::iterator last){

		if(first == begin() and last == end()){
			init();
		}
		for(auto it= first; it != last; it++){
				erase(it);
		}
	}

	template<typename T>
	template<typename InputIt>
	void list<T>::assign(InputIt first, InputIt last){
		clear();
		for(auto it = first; it != last; it++){
			push_back(*it);
		}
	}

	template<typename T>
	void list<T>::assign(std::initializer_list<T> ilist){
		assign(ilist.begin(), ilist.end());
	}

	template<typename T>
	void list<T>::assign(size_type count, const T & value){
		clear();
		for(auto i = 0; i < count; i++){
			push_back(value);
		}
	}
	
	template <typename T>
	typename list<T>::iterator  list<T>::insert(iterator itr, const T & value){
		if(itr == begin()){
			push_front(value);
			return head;
		}else if(itr == end()){
			push_back(value);
			return tail->prev;
		}
		Node *p = itr.current;
		Node *target = new Node{value, p->prev, p};
		p->prev->next = target;
		p->prev = target;
		m_size++;
		return p->prev;
	}
	
	template<typename T>
	template<typename InputIt>
	typename list<T>::iterator list<T>::insert(iterator pos, InputIt first, InputIt last){
		Node *p = pos.current;
		iterator it = pos;
		auto e = last;
		e--;
		auto b = first;
		b--;
		for(auto i = e; i != b; --i){
			it = insert(it, *i);
		}
		return it;
	}
	
	template <typename T>
	typename list<T>::iterator  list<T>::insert(iterator pos, std::initializer_list<T> ilist){
		return insert(pos, ilist.begin(), ilist.end());
	}
