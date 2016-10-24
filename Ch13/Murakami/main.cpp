/*****************************************************************************
 *	Name:      Mr. Creelman                                                  *
 *	Course:    ICS4U                                                         *  
 *	Date:      October 24st, 2016	                                         * 
 *	                                                                         * 
 *	Purpose:   Demonstrate a simple class in multiple files                  *
 *	                                                                         *
 *	Usage:                                                                  *
 *	                                                                         *
 *	Revision History:                                                        *  
 *	                                                                         *
 *	Known Issues:                                                            *
 *	                                                                         *  
 *****************************************************************************/
#include <iostream>
#include <apstring.h>
#include <apstring.cpp>
#include "Murakami.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Murakami k("Kafta On The Shore");
	Murakami q("1984");
	k.setRead();
	q.QTheTitle();
	k.print();
	q.print();
	return 0;
}
