
#define MSLIB_EXPORT

#include "stdafx.h"
#include "MinesweeperLibrary.h"
#include "Field.h"
#include "FlagType.h"

namespace MSCore {
	IField* NewField(){ return new Field(); }
	void Destroy(IField* instance) { delete instance; }
}