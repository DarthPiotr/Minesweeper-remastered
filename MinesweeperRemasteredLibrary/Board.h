#pragma once

#include "Field.h"
#include <vector>


#ifdef MSLIB_EXPORT
# define EXPORT __declspec (dllexport)
#else /* Not BUILDING_DLL */
# define EXPORT __declspec (dllimport)
#endif /* Not BUILDING_DLL */

namespace MSCore {
	class Board
	{
	private:
		short rows, cols;
		int mines;
		unsigned int seed;
		bool isFilled;
		bool enableUnsure;
		Field * * board;

		void random(unsigned int seed, std::vector < Field*>);
		int getMaxIndex();
	public:
		EXPORT Board(short, short, int, bool);

		EXPORT short getRows();
		EXPORT short getCols();
		EXPORT bool getUnsure();
		EXPORT void setUnsure(bool);
		EXPORT Field* getField(short, short);
		EXPORT Field* getField(int);
		EXPORT unsigned int getSeed();
		EXPORT int getIndex(Field*);
		EXPORT std::vector<Field*> getSurroundingFields(short, short);
		EXPORT std::vector<Field*> getSurroundingFields(Field*);
		EXPORT void randomBoard(unsigned int);
		EXPORT void randomBoard(Field*);

		EXPORT bool LClick(Field *, bool);
		EXPORT void RClick(Field *);
		EXPORT void MClick(Field *);
	};
}


