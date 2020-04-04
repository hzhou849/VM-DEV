/*
 * Tool2 to be added to static library demo
 */

#include <iostream>
#include <ncurses.h>


void tool2(int *i)
{
	*i = 2;
	std::cout << "You have successfully added tool2 to your library." << std::endl;
	std::cout << "tool2 value: " << i << std::endl; 
}

void tool2_ncurses(int *i)
{
	WINDOW *w_main = initscr();
	move(5,5);
	printw("you have sucessfully called ncurses %d", *i);
	getch();
	endwin();
}


