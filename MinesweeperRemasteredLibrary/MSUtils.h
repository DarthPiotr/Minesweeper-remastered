#pragma once

#ifndef _MSREMASTEREDLIB_H_
#define _MSREMASTEREDLIB_H_

#include "stdafx.h"
#include "Board.h"

#ifdef MSLIB_EXPORT
# define EXPORT __declspec (dllexport)
#else /* Not BUILDING_DLL */
# define EXPORT __declspec (dllimport)
#endif /* Not BUILDING_DLL */

extern "C" {
	namespace MSUtils {
		class Console
		{
		private:
			static void writeString(std::string c);
		public:
			static EXPORT void stopConsole(void);
			static EXPORT void drawBoard(MSCore::Board*);
			static EXPORT void drawBoardUncovered(MSCore::Board*);
		};
	}
}
#endif



