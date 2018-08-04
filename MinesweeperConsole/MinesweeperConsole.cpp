// MinesweeperConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define TEST_VERSION 0

#if TEST_VERSION
#include "MinesweeperLibrary.h"
#include "FlagType.h"
#else
#include <Windows.h>
#include <string>
#include "IField.h"
#include "FlagType.h"
#endif
using namespace MSCore;
using namespace std;

int main()
{

#if TEST_VERSION
	cout << "=== Static linking test. ===\n";

	IField* f = NewField();

	if (f) {
		cout << "Value: " << f->getValue() << '\n';
		f->setValue(3);
		cout << "Value: " << f->getValue() << '\n';
		cout << "Current flag: " << f->getFlag().getTypeAsString() << '\n';
		f->setFlag(flagTypeEnum::FLAGGED);
		cout << "Current flag: " << f->getFlag().getTypeAsString() << '\n';

		Destroy(f);
	}
	else
		cout << "An error occured while loading class.\n";
	
	cout << "=== End of static linking ===\n";

	MSUtils::Console::stopConsole();
#else
	cout << "=== Dynamic linking test. ===\n";
	typedef IField* (*NewFieldFunc)();
	typedef void (*DestroyFunc)(IField*);
	NewFieldFunc newFieldFunc;
	DestroyFunc destroyFunc;

	HINSTANCE hInstMyDll = LoadLibrary(L"MinesweeperRemasteredLibrary.dll");
	if (hInstMyDll) {
		newFieldFunc = (NewFieldFunc)GetProcAddress(hInstMyDll, "NewField");
		destroyFunc = (DestroyFunc)GetProcAddress(hInstMyDll, "Destroy");

		if (newFieldFunc) cout << "NewField() loaded correctly\n";
		else cout << "Error while loading NewField()\n";
		if (destroyFunc) cout << "Destroy(IField*) loaded correctly\n";
		else cout << "Error while loading Destroy(IField*)\n";

		if (newFieldFunc && destroyFunc) {
			IField* f = newFieldFunc();
			cout << "Current flag: " << f->getFlag().getTypeAsString() << '\n';
			f->setFlag(flagTypeEnum::FLAGGED);
			cout << "Current flag: " << f->getFlag().getTypeAsString() << '\n';
			destroyFunc(f);

			//FlagType x = FlagType();
			//x.setType(flagTypeEnum::IDK);
		}
	}
	else 
		cout << "An error occured while loading dll.\n";

	cout << '\n';
	system("pause");

#endif

	return 0;
}

