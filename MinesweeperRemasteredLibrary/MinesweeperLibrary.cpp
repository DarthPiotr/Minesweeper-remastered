// MinesweeperRemasteredLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <iostream>
#include "MinesweeperLibrary.h"

namespace MinesweeperLib {
	int Functions::doStuff(int a) {
		return a * 2;
	}

	void Functions::stopConsole() {
		std::cout << std::endl;
		system("pause");
	}
}

