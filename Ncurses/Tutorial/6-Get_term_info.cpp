#include <iostream>
#include <ncurses.h>


int main(int argc, char *argv[])
{
	initscr();
	noecho();

	getbegyx(win,y,x); // get the initial cur point of new window 
	getmaxyx(win,y,x) // the the max size of windwo
	

}
