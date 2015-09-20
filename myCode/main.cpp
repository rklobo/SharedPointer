#include <iostream>
#include <stdlib.h>
#include <string>
#include <memory>
#include <boost/regex.hpp>
#include <boost/shared_ptr.hpp>

using namespace std;

class Thing {
	int i;
public:
	Thing():i(10){}
	void print(){
		cout << i << endl;
	}
};

int main (void)
{
	// creates two allocation, one for managed object and second for manager object
	//boost::shared_ptr<Thing> p1(new Thing());

	boost::shared_ptr<Thing> p1(new Thing());
	auto p2 = p1;

	p1->print();
	if(p1){
		cout << "Managed object existing" << endl;
	}

	p2->print();
	return 0;
}
