#pragma once

#ifndef __FLAGTYPE_H__
#define __FLAGTYPE_H__

#ifdef MSLIB_EXPORT
# define EXPORT __declspec (dllexport)
#else /* Not BUILDING_DLL */
# define EXPORT __declspec (dllimport)
#endif /* Not BUILDING_DLL */

#include <string>

namespace MSCore {
	enum flagTypeEnum { IDK = -1, FLAGGED = 1, UNFLAGGED = 0 };
	class FlagType {
	private:
		flagTypeEnum type;
	public:
		EXPORT FlagType();

		EXPORT void setType(flagTypeEnum);
		EXPORT flagTypeEnum getTypeAsEnum();
		EXPORT short getTypeAsShort();
		EXPORT std::string getTypeAsString();
	};
}
#endif