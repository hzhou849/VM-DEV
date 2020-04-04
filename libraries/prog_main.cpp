/*
 *
 * Static linking demo program
 * This program will call on my statically linked
 *  tool1 and tool2 libraries.
 * 
 * 1) Compile the tools into object *.o files.
 *    -g++ -Wall -c tool1.cpp tool2.cpp
 * 
 * 2) Create the library "libmytool.a"
 * 
 * 		ar -cvq libmytool.a tool1.o tool2.o (or *.o)
 * 
 * 		-c Whenever an archive is created, an informational message to that effect is 
 * 			written to standard error. If the -c option is specified, ar creates 
 * 			the archive silently.
 * 
 *		-v Provide verbose output.
 
 *		-q Quickly append the specified files to the archive. If the archive does not 
 			exist a new archive file is created.

	3) Compile your application with the new statically created library:
		g++ -o prog_main prog_main.cpp -L/path/to/libaray(or '.') -lmytool


		you still have to static link ncurses when building prog_main.c
		g++ -o prog_main prog_main.cpp -static -L. -lmytool -lncurses -ltinfo -lgpm

 *
 */

#include <iostream>

//Statically linked library prototypes
void tool1(int*);
void tool2(int*);
void tool2_ncurses(int*);


int main (int argc, char *arvg[])
{
	int x;
	tool1(&x);
	std::cout << "x passed into tool1: " << x << std::endl;
	tool2(&x);
	std::cout << "x passed into tool2: " << x << std::endl;
	tool2_ncurses(&x);
}