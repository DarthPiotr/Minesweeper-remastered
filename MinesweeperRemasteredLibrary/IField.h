#pragma once


#ifndef __IFIELD_H__
#define __IFIELD_H__

#include "FlagType.h"


namespace MSCore {
	class IField {
	public:
		virtual short getValue() = 0;
		virtual void setValue(short) = 0;
		virtual FlagType getFlag() = 0;
		virtual void setFlag(FlagType) = 0;
		virtual void setFlag(flagTypeEnum) = 0;
		virtual bool getShown() = 0;
		virtual void setShown(bool) = 0;
	};
}

#endif