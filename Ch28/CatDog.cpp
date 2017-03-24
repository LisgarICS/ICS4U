/*****************************************************************************
 *	Name:  Mr. W. Creelman                                                   *
 *	Course: ICS4U                                                            *  
 *	Date:   March 2017                                                                 * 
 *	                                                                         * 
 *	Purpose:  Short demo of inheritance.  Cat is "a kind of " Pet,
 *            Dog is also a "a kind of Pet". 
 *	                                                                         *
 *	Usage:                                                                   *
 *	                                                                         *
 *	Revision History:                                                        *  
 *	                                                                         *
 *	Known Issues: Particularly bare bones, add private data and public methods 
 *            to make more useful                                           *	                                                                         *  
 *****************************************************************************/

#include <iostream>
#include <apstring.h>
#include <apstring.cpp>

using namespace std;

class Pet {
	// imagine many more common attributes like age, owner, breed. 
	// note protected instead of private so derived classes can access.
	protected:
		apstring name;
	public:
		Pet(apstring n) { name = n;}
		apstring getName() { return name; }
		~Pet() { cout << name << " has gone to Pet Heaven" << endl;}
			
};

class Dog : public Pet {
	private:
		bool playsFetch;
	public:
		Dog(apstring n) : Pet(n) {playsFetch = true;}
		void speak() { cout << name << " says Woof " << endl;} 	
};

class Cat : public Pet {
	private:
	
		bool isPurring;
	public:
		Cat(apstring n) : Pet(n) { isPurring = true;}
		void speak() { cout << name << " says Meow " << endl;} 
};



int main() {
	apstring catName = "Fluffy";
	apstring dogName = "Rover";
	Cat myCat(catName);
	Dog myDog(dogName);
	myCat.speak();
	myDog.speak();
	return 0 ;
}
