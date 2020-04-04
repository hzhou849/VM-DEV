/*
 * Ncurses GUI Framework - Protoype Application
 *
 * Template menu script execution application test 
 */

#include <iostream>
#include <ncurses.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <string>

void start_ncurses(bool useRaw, bool useNoecho);
void print_menu(WINDOW *menu, std::string choices[], int size, int highlight);
void raw_string(const char* raw_string)
{
	std::cout << "c string: " << raw_string << std::endl;
}

int main(int argc, char *argv[])
{
	const char *str1 = "hello world";

	raw_string(str1);
}




