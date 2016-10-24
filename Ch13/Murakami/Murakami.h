// Murakami.h  
#ifndef MURAKAMI_H
#define MURAKAMI_H

#include <iostream>
#include <apstring.h>

class Murakami {
	private:
		apstring title;
		bool read;
	public:
		Murakami() {title = ""; read = false;}
		Murakami(apstring t) {title = t; read = false;}
		void setTitle(apstring t) {title = t;}
		void setRead() {read = true;}
		void QTheTitle();
		void print();	
		~Murakami() {std::cout << "book out of slope" << std::endl;}
};
#endif
