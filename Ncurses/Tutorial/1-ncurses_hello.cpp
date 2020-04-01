/*
 *
 * To install the ncurses packages on ubuntu:
 * sudo apt-get install libncurses5-dev libncursesw5-dev
 * 
 * 
*/

#include <iostream>
#include <cstdlib>
#include <ncurses.h>

int main(int argc, char** argv)
{
    std::cout << "testing" <<std::endl;
    // Initialized the screen
    // Sets up memory and clears the screen
    initscr();

    //Prints string(const char *) to a buffer
    printw("Hello world");

    // refreshes the screen to match whats in memory
    // dump the buffer to screen
    refresh();

    //waits for user input interrupt
    int char_get = getch();
    printw("0x%02x", char_get);
    refresh();

    getchar();


    // deallocates memory and ends ncurses
    endwin();

    return EXIT_SUCCESS;
}
