#pragma once

#include "IField.h"
#include <utility>

#ifndef __FIELD_H__
#define __FIELD_H__

#ifdef MSLIB_EXPORT
# define EXPORT __declspec (dllexport)
#else /* Not BUILDING_DLL */
# define EXPORT __declspec (dllimport)
#endif /* Not BUILDING_DLL */
	namespace MSCore {

		class Field {
		private:
			short row, col;
			short value;
			FlagType flagLvl;
			bool shown;

		public:
			EXPORT Field();
			EXPORT Field(short, short);

			EXPORT short getValue();
			EXPORT void setValue(short);
			EXPORT FlagType getFlag();
			EXPORT void setFlag(FlagType);
			EXPORT void setFlag(flagTypeEnum);
			EXPORT bool getShown();
			EXPORT void setShown(bool);
			EXPORT std::pair<short,short> getCoords();
			EXPORT short getRow();
			EXPORT short getCol();
		};
	}
#endif
