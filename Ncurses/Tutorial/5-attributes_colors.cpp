#include <iostream>
#include <ncurses.h>
#include <thread>
#include <chrono>

int main(int argc, char *argv[])
{
	initscr();						// start GUI mode;
	raw();							// captures raw keys, requires cbreak() after to quit
	cbreak();

	// check if terminal supports color
	if (!has_colors() )
	{
		printw("Terminal does not support color");
		getch();
		return -1;
	}
	start_color();		// enables color mode

	/* A_NORMAL
	 * A_STANDOUT
	 * A_REVERSE
	 * A_BLINK
	 * A_DIM
	 * A_BOLD
	 * A_PROTECT
	 * A_INVIS
	 * A_ALTCHARSET
	 * A_CHARTEXT
	 */
	attron(A_ALTCHARSET);
	move(5,5);
	printw("testing attributes");
	attroff(A_ALTCHARSET);
	getch();
	refresh();

	/* COLOR_PAIR(n)
	 * COLOR_BLACK   0
	 * COLOR_RED	 1
	 * COLOR_GREEN   2
	 * COLOR_YELLOW  3
	 * COLOR_BLUE    4
	 * COLOR_MAGENTA 5
	 * COLOR_CYAN    6
	 * COLOR_WHITE  7
	 */

	short COLOR_MINE =8;
	// create own color
	init_color(COLOR_MINE,75,52,999); //rgb
	
	init_pair(1, COLOR_CYAN, COLOR_MINE);   // creates color index
	bkgd(COLOR_PAIR(1));
	// wbkgd();  							// specific window backgroud


	attron(COLOR_PAIR(1));
	// very useful group attribute assignment
	// args1-2: (Y, X, )
	// args3:   number of chars to update -1 = eol, 0 for no change 
	// args4: Attributes 
	// arg 5: color-index(init_par(); 0 no color
	// arg 6: always NULL
	mvchgat(6,5,0, A_DIM, 0, NULL);
	printw("mvchat testing");
	attroff(COLOR_PAIR(1));
	volatile int catch_c= getch();
	char exit_char = 'c';
	refresh();
	
	do
	{
	    catch_c = getch();
		mvprintw(7,5, "%c", catch_c);
		mvprintw(8,5, "what the fuck?");
		refresh();
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	} while(catch_c != exit_char);

	attroff(COLOR_PAIR(1));

	 endwin();




}