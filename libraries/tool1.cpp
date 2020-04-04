/*
 * Custom library static linking demonstration.
 * hopefully this tool/class will be linked as a compiled library
 *  
 *  First tool.cpp file to be linked
 */

#include <iostream>

void tool1(int *i)
{
	*i = 1;
	std::cout << "You have successfully accessed tool1" <<std::endl;
	std::cout << "var passed: " << i << std::endl;
}


