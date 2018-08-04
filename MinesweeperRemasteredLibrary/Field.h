#pragma once

#include "IField.h"

#ifndef __FIELD_H__
#define __FIELD_H__

namespace MSCore {

	class Field : public IField {
	private:
		short value;
		FlagType flagLvl;
		bool shown;

	public:
		Field();

		short getValue();
		void setValue(short);
		FlagType getFlag();
		void setFlag(FlagType);
		void setFlag(flagTypeEnum);
		bool getShown();
		void setShown(bool);

	};
}

#endif
