#pragma once

#ifndef _MSREMASTEREDLIB_H_
#define _MSREMASTEREDLIB_H_

#include "stdafx.h"
#include "IField.h"
#include "FlagType.h"

#ifdef MSLIB_EXPORT
# define EXPORT __declspec (dllexport)
#else /* Not BUILDING_DLL */
# define EXPORT __declspec (dllimport)
#endif /* Not BUILDING_DLL */

extern "C" {
	namespace MSUtils {
		class Console
		{
		public:
			static EXPORT void stopConsole(void);
		};
	}
	namespace MSCore {
		__declspec(dllexport) IField * NewField(void);
		__declspec(dllexport) void Destroy(IField*);
	}
}
#endif



