#pragma once

#ifndef __FLAGTYPE_H__
#define __FLAGTYPE_H__

#include <string>

namespace MSCore {
	enum flagTypeEnum { IDK = -1, FLAGGED = 1, UNFLAGGED = 0 };
	class FlagType {
	private:
		flagTypeEnum type;
	public:
		__declspec(dllexport) void setType(flagTypeEnum);
		__declspec(dllexport) flagTypeEnum getTypeAsEnum();
		__declspec(dllexport) short getTypeAsShort();
		__declspec(dllexport) std::string getTypeAsString();
	};
}
#endif