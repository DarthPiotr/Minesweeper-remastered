// MinesweeperConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MinesweeperLibrary.h"

int main()
{
	std::cout << "5 -> " << MinesweeperLib::Functions::doStuff(5);

	MinesweeperLib::Functions::stopConsole();

	return 0;
}

