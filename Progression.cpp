#include <iostream>

using namespace std;


class arith_iterator {
	int curr;
	int step;
	friend class ArithProgression;
	arith_iterator(int curr, int step):curr{curr}, step{step} {}
	public:
	bool operator==(const arith_iterator& other) const{
		return curr==other.curr;
	}
	bool operator!=(const arith_iterator& other) const{
		return curr<other.curr;
	}
	int& operator*(){
		return curr;
	}
	arith_iterator& operator++(){
		curr+=step;
		return *this;
	};
	arith_iterator& operator++(int){
		auto _curr=this;
		++*this;
		return *_curr;
	}
};

class geo_iterator {
	int curr;
	int step;
	friend class GeomProgression;
	geo_iterator(int curr, int step):curr{curr}, step{step} {}
	public:
	bool operator==(const geo_iterator& other) const{
		return curr==other.curr;
	}
	bool operator!=(const geo_iterator& other) const{
		return curr<other.curr;
	}
	int& operator*(){
		return curr;
	}
	geo_iterator& operator++(){
		curr=curr*step;
		return *this;
	}

	geo_iterator& operator++(int){
		auto _curr=this;
		++*this;
		return *_curr;
	}	
};
/*
class Progression{
	private:
	long start;
	long cur;
	long stop;
	public:
	Progression();
	long firstValue();
	long nextValue();
	void print(Progression(int));
}
*/
class ArithProgression{
	long inc;
	long start;
	long stop;
	public:
	ArithProgression(long _stop):inc(1),start(0),stop(_stop){};
	ArithProgression(long _start,long _stop):inc(1),start(_start),stop(_stop){};
	ArithProgression(long _inc,long _start,long _stop):inc(_inc),start(_start),stop(_stop){};
	
	using iterator=arith_iterator;
	
	iterator begin() const{
		return ArithProgression::iterator(start,inc);
	}
	iterator end() const{
		return ArithProgression::iterator(stop,inc);
	}
};
class GeomProgression{
	long base;
	long start;
	long stop;
	public:
	GeomProgression(long _stop):start(1),stop(_stop),base(2){};
	GeomProgression(long _start,long _stop):base(2),start(_start),stop(_stop){};
	GeomProgression(long _start,long _stop,long _base):base(_base),start(_start),stop(_stop){};

	using iterator = geo_iterator;

	iterator begin() const{
		return GeomProgression::iterator(start,base);
	}
	iterator end() const{
		return GeomProgression::iterator(stop,base);
	}
};
/*
FibonacciProgression{
	long prev;
	public:
	FibonacciProgression();
	FibonacciProgression( long,long);
	long nextValue();
}
*/

int main(){
	for (auto i: ArithProgression{10})
		std::cout<<i<<",";
	std::cout<<std::endl;
	for (auto i: GeomProgression{2,100,4})
		std::cout<<i<<",";
	std::cout<<std::endl;
	return 0;
}

