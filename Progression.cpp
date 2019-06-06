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


class fib_iterator {
	int curr;
	int prev;
	friend class FibProgression;
	fib_iterator(int prev, int base):curr{base}, prev{prev}{}
	public:
	bool operator==(const fib_iterator& other) const{
		return curr==other.curr;
	}
	bool operator!=(const fib_iterator& other) const{
		return curr<other.curr;
	}
	int& operator*(){
		return curr;
	}
	fib_iterator& operator++(){
		curr+=prev;
		prev=curr-prev;
		return *this;
	}

	fib_iterator& operator++(int){
		auto _prev=this;
		++*this;
		return *_prev;
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

class FibProgression{
	long prev;
	long base;
	long limit;
	public:
	FibProgression(long _stop){
		int i=0;
		int x=0;
		for (i;i<_stop;i++){
			x=base+prev;
			prev=base;
			base=x;
		}
		prev=0;
		base=1;
		limit=i;
	};
	FibProgression(long _stop, long _second){
		int i=0;
		int x=0;
		for (i;i<_stop;i++){
			x=base+prev;
			prev=base;
			base=x;
		}
		prev=0;
		base=_second;
		limit=i;
	};
	FibProgression(long _stop, long _first, long _second){
		int i=0;
		int x=0;
		for (i;i<_stop;i++){
			x=base+prev;
			prev=base;
			base=x;
		}
		prev=_first;
		base=_second;
		limit=i;
	};

	using iterator = fib_iterator;

	iterator begin() const{
		cout<<prev<<" "<<base<<std::endl;
		return FibProgression::iterator(prev,base);
	}
	iterator end() const{
		return FibProgression::iterator(limit,limit);
	}
};

int main(){
	std::cout<<"Aritmetica"<<std::endl;
	for (auto i: ArithProgression{10})
		std::cout<<i<<",";
	std::cout<<std::endl<<"Geometrica"<<std::endl;
	for (auto i: GeomProgression{2,100,4})
		std::cout<<i<<",";
	std::cout<<std::endl<<"Fibonacci"<<std::endl;
	for (auto i: FibProgression{100,5,9}){
		std::cout<<i<<",";
	}
	std::cout<<std::endl;
	return 0;
}

