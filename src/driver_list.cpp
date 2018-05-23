#include "../include/list.hpp"

int main(){
	sc::list<int> l = {1,2,3};
	sc::list<int> tes = {1,2,3};
	std::cout<< "l is empty? "<< std::endl;
	if(!l.empty()){
		std::cout<< "false"<< std::endl;
	}
	auto begin = l.cbegin();
	auto end = l.cend();
	std::cout << "cBegin -- "<< *begin << std::endl;
	std::cout << "cEnd -- "<< *end << std::endl;

	sc::list<int>::iterator it;
	sc::list<int>::iterator it1;
	sc::list<int>::iterator it2;
	
	auto i = l.begin();
	//i++;
	//insert with one element
	it = l.insert(i, 4);
	i = l.begin();
	//insert with ranges
	it1 = l.insert(i, {10,11,14});
	i = l.begin();
	//insert with list
	std::initializer_list<int> ilist{7,8,9};
	it2 = l.insert(i, ilist.begin(), ilist.end());

	//erase simples
	l.erase(l.begin());

	l.push_front(0);
	l.pop_front();
	
	auto begin2 = l.cbegin();
	auto end2 = l.cend();
	std::cout << "cBegin -- "<< *begin2 << std::endl;
	std::cout << "cEnd -- "<< *end2 << std::endl;

	std::cout<< "size l -> "<< l.size() << std::endl;
	std::cout << "printing l with iterator "<< std::endl;
	for(auto i = l.begin(); i != l.end(); i++){
		std::cout << "-- "<< *i << std::endl;
	}
	std::cout<< "size tes -> "<< tes.size() << std::endl;
	std::cout << "printing tes with conts_iterator "<< std::endl;
	for(auto i = tes.cbegin(); i != tes.cend(); i++){
		std::cout << "-- "<< *i << std::endl;
	}
	//compare l and tes
	std::cout << "comparisson != between l and tes "<< std::endl;
	if(l != tes){
		std::cout << "true"<< std::endl;
	}
	return 0;
}
