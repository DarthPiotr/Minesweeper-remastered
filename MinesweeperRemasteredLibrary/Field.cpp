#include "stdafx.h"
#include "Field.h"
#include "FlagType.h"

namespace MSCore {
	Field::Field() {
		this->value = 0;
		this->flagLvl.setType(flagTypeEnum::UNFLAGGED);
		this->shown = false;
	}

	short Field::getValue() {
		return this->value;
	}
	void Field::setValue(short val) {
		this->value = val;
	}

	/// <summary>Returns flag level of field. It can be:
	///  0: no flag is set
	///	 1: flag is set
	/// -1: field is set as dont know
	/// </summary>
	FlagType Field::getFlag() {
		return this->flagLvl;
	}
	void Field::setFlag(FlagType flag) {
		this->flagLvl = flag;
	}
	void Field::setFlag(flagTypeEnum flagtype) {
		this->flagLvl.setType(flagtype);
	}

	bool Field::getShown() {
		return this->shown;
	}
	void Field::setShown(bool shown) {
		this->shown = shown;
	}
}