#include <iostream>
#include <stdlib.h>
#include <string>
#include <memory>
#include <boost/regex.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/make_unique.hpp>
#include <boost/interprocess/smart_ptr/unique_ptr.hpp>



// creates a weak pointer
class Thing : public boost::enable_shared_from_this<Thing>{
	int i;
public:
	Thing():i(10){}
	void foo(){
		boost::shared_ptr<Thing> sp = shared_from_this();
		print(sp);
	}
	void print(boost::shared_ptr<Thing> ptr){
		std::cout << ptr->i << std::endl;
	}
};

int main (void)
{
	// creates two allocation, one for managed object and second for manager object
	//boost::shared_ptr<Thing> p1(new Thing());

	//boost::shared_ptr<Base> p1(boost::make_shared<Derived>(Parameters));
	boost::shared_ptr<Thing> p1(boost::make_shared<Thing>());
	auto p2 = p1;
	p2->foo();

	// weak pointer can be created from shared pointer or weak pointer
	boost::shared_ptr<Thing> sp(boost::make_shared<Thing>());
	boost::weak_ptr<Thing> wp1(sp);

	boost::weak_ptr<Thing> wp2;
	wp2 = wp1;

	wp2.reset();
	boost::shared_ptr<Thing> sp3 = wp2.lock();
	if(sp3)
		sp3->foo();
	else{
		std::cout << "Object out of scope" << std::endl;
	}

	if(wp2.expired()){
		std::cout << "Weak pointer is expired" << std::endl;
	}
	return 0;

	std::unique_ptr<Thing> up1(new Thing);
	std::unique_ptr<Thing> up2 = std::move(up1);
	std::unique_ptr<Thing> up3(std::move(up2));



}

