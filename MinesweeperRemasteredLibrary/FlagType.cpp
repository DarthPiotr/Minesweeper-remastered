#include "stdafx.h"
#include "FlagType.h"

namespace MSCore {
	void FlagType::setType(flagTypeEnum type) {
		this->type = type;
	}
	flagTypeEnum FlagType::getTypeAsEnum() {
		return this->type;
	}
	short FlagType::getTypeAsShort() {
		return (short)this->type;
	}
	std::string FlagType::getTypeAsString() {
		switch (getTypeAsShort())
		{
		case 0:
			return "unflagged";
		case 1:
			return "flagged";
		case -1:
			return "not sure";
		}
		return "unidentified";
	}
}