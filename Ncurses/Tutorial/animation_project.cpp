#include <iostream>
#include <ncurses.h>
#include <thread>
#include <chrono>

int main (int argc, char **argv)
{
    // init screen, setups memeory and clears screen
    WINDOW *w_main = initscr();

    int x,y;
    x = y = 10;
	WINDOW *ventana1;
    system("resize -s 30 80");
	 start_color();
    ventana1 = newwin(15, 50, 0, 0);
    init_pair(1,COLOR_YELLOW,COLOR_BLUE);
    init_pair(2,COLOR_BLUE, COLOR_YELLOW);
    wbkgd(ventana1,COLOR_PAIR(1));
    wprintw(ventana1, "POLLO");
    wrefresh(ventana1);
    wgetch(ventana1);
    wgetch(ventana1);
    system("resize -s 20 60");
    wbkgd(ventana1,COLOR_PAIR(2));
    wprintw(ventana1, "POLLO");
    wrefresh(ventana1);
    wgetch(ventana1);
    wgetch(ventana1);
    system("resize -s 35 85");
    system("clear");
    wbkgd(ventana1,COLOR_PAIR(1));
    wprintw(ventana1, "POLLO");
    wrefresh(ventana1);
    wgetch(ventana1);
    wgetch(ventana1);
    delwin(ventana1);
    endwin();
    system("resize -s 25 75");

    printw("Upper left corner           "); addch(ACS_ULCORNER); printw("\n"); 
        printw("Lower left corner           "); addch(ACS_LLCORNER); printw("\n");
        printw("Lower right corner          "); addch(ACS_LRCORNER); printw("\n");
        printw("Tee pointing right          "); addch(ACS_LTEE); printw("\n");
        printw("Tee pointing left           "); addch(ACS_RTEE); printw("\n");
        printw("Tee pointing up             "); addch(ACS_BTEE); printw("\n");
        printw("Tee pointing down           "); addch(ACS_TTEE); printw("\n");
        printw("Horizontal line             "); addch(ACS_HLINE); printw("\n");
        printw("Vertical line               "); addch(ACS_VLINE); printw("\n");
        printw("Large Plus or cross over    "); addch(ACS_PLUS); printw("\n");
        printw("Scan Line 1                 "); addch(ACS_S1); printw("\n");
        printw("Scan Line 3                 "); addch(ACS_S3); printw("\n");
        printw("Scan Line 7                 "); addch(ACS_S7); printw("\n");
        printw("Scan Line 9                 "); addch(ACS_S9); printw("\n");
        printw("Diamond                     "); addch(ACS_DIAMOND); printw("\n");
        printw("Checker board (stipple)     "); addch(ACS_CKBOARD); printw("\n");
        printw("Degree Symbol               "); addch(ACS_DEGREE); printw("\n");
        printw("Plus/Minus Symbol           "); addch(ACS_PLMINUS); printw("\n");
        printw("Bullet                      "); addch(ACS_BULLET); printw("\n");
        printw("Arrow Pointing Left         "); addch(ACS_LARROW); printw("\n");
        printw("Arrow Pointing Right        "); addch(ACS_RARROW); printw("\n");
        printw("Arrow Pointing Down         "); addch(ACS_DARROW); printw("\n");
        printw("Arrow Pointing Up           "); addch(ACS_UARROW); printw("\n");
        printw("Board of squares            "); addch(ACS_BOARD); printw("\n");
        printw("Lantern Symbol              "); addch(ACS_LANTERN); printw("\n");
        printw("Solid Square Block          "); addch(ACS_BLOCK); printw("\n");
        printw("Less/Equal sign             "); addch(ACS_LEQUAL); printw("\n");
        printw("Greater/Equal sign          "); addch(ACS_GEQUAL); printw("\n");
        printw("Pi                          "); addch(ACS_PI); printw("\n");
        printw("Not equal                   "); addch(ACS_NEQUAL); printw("\n");
        printw("UK pound sign               "); addch(ACS_STERLING); printw("\n");

    //moves the cursor to specified location
    move (y, x);

    //print string to a window
    printw("Hello world!");
    // what for user input, returns int value of that key
    int c = getch();

    // clears the current screen
    clear(); 

    // mvwprintw()  move window print - prints to a specific window
    mvprintw(10,5, "testing: ");
    move(0, 0);

    printw("%d", c);
    // mvprint(y,x, "blah"); move and print
    move(11,5);
    int tempx;
    int tempy;
    int MAX_X;
    int MAX_Y;
    
    getyx(w_main, tempy, tempx);
    getmaxyx(w_main, MAX_Y, MAX_X);
    
	// make the cursor invisible
	curs_set(0);
    mvprintw(9,5, "max X:%d, max Y:%d", MAX_X, MAX_Y); 
    for (int i=0; i < 30; i++)
    {
        move(tempy, tempx);
        getyx(w_main, tempy, tempx);
        printw("x:%d y:%d", tempx, tempy);
        printw("%c █", '\x97');
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        
        mvprintw(12,5, "%d", i);
        move(13,5+i);
        addch(ACS_CKBOARD);printw("\n");
        refresh();


    }

    
    int catch_key = getch();
    printw("key:%d", catch_key);
    std::this_thread::sleep_for(std::chrono::milliseconds(5500));

	// Catches the resizing of the terminal. 
    while (catch_key ==410 )
    {
        resize_term(MAX_Y,MAX_X );
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
        catch_key=getch();
		 mvprintw(12,5, "%d", tempx++);
		 refresh();
    }


    //dealloc
    endwin();

    return EXIT_SUCCESS;
}
