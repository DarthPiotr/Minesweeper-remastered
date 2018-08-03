#pragma once

#include "stdafx.h"

#ifdef MINESWEEPERREMASTEREDLIBRARY_EXPORTS
# define MINESWEEPER_LIB __declspec (dllexport)
#else /* Not BUILDING_DLL */
# define MINESWEEPER_LIB __declspec (dllimport)
#endif /* Not BUILDING_DLL */

namespace MinesweeperLib {
	class Functions
	{
	public:
		static MINESWEEPER_LIB int doStuff(int a);
		static MINESWEEPER_LIB void stopConsole();

	private:

	};
}



