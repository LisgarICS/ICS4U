// a couple of methods here.
#include <iostream>
#include "Murakami.h"

void Murakami::QTheTitle() {
	title[2] = 'Q';
}

void Murakami::print() {
	if (read)
		std::cout << "You have read ";
	else
		std::cout << "You have not read ";
	std::cout << title << std::endl;
}
