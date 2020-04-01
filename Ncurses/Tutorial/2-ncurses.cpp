#include <iostream>
#include <ncurses.h>

int main()
{
    int ch;

    initscr();                  // Start curses mode
    raw();                      // Line buffering disabled, disables hotkey commands and passes raw chars
    keypad( stdscr, TRUE );     // we get F1, F2, arrows etc...
    noecho();                   // Don't echo() while we do getch

    printw("Type any character to see it in bold\n");   //write to buffer
    
    // If raw() hadn't been called, we have to press enter before it
    // gets to the program.
    ch = getch();          

    // W/o keypad enable this will not get to us either
    // noecho() will disable the key data printed on screen.
    if ( ch == KEY_F(1) )    
        printw( "F1 Key pressed");
    else
    {
        printw("the pressed key is ");
        attron(A_BOLD);
        printw("%c", ch);
        attroff(A_BOLD);
    }

    refresh();              // print the buffer
    getch();                // wait for user input
    endwin();               // end and clean up memory

    return EXIT_SUCCESS;
    
}