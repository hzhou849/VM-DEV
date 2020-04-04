#include <ncurses.h>

int main(int argc, char *argv[])
{
	// Main screen window
	WINDOW *w_main = initscr();

	//hide the cursor
	// curs_set(0);

	//cbreak(); handles control+c exit
	//raw();   // displays ^c when ctrl+c is press instead of numerical value
	noecho(); //keeps cursor disables text display when pressing keys
	// echo() - re-enable echo
	
	// variables
	int height, width, start_y, start_x;
	height = 10;
	width = 20;
	start_y = start_x = 10;

	// my sub-window
	// not the actual box, but allocates the memory for it
	
	WINDOW *m_win = newwin(height, width, start_y, start_x); 
	
	// delwin(m_win); // to destry window
	refresh();

	box(m_win, 0,0); // the actuallly box
	wmove(m_win,1,3);
	wprintw(m_win, "this is my box");

	// mvwprintw(m_win,1,3,"blah"); // one line move window + print

	/*Custom border window init */
	// wborder(m_win, left,right, top, bottom, top_left_corner, top_r_corner, bottom_l_corner, bottom_r_corner);

	wrefresh(m_win); // refreshes the specific window
	getch();

	getch();

	endwin();

	return 0;

}