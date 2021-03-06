// MinesweeperConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include "Field.h"
#include "FlagType.h"
#include "Board.h"
#include "MSUtils.h"

#include <memory>
#include  <ctime>

using namespace MSCore;
using namespace std;

int main()
{
	cout << "=== Static linking test. ===\n";

	Field f = Field();

	cout << "Value: " << f.getValue() << '\n';
	f.setValue(3);
	cout << "Value: " << f.getValue() << '\n';
	cout << "Current flag: " << f.getFlag().getTypeAsString() << '\n';
	f.setFlag(flagTypeEnum::FLAGGED);
	cout << "Current flag: " << f.getFlag().getTypeAsString() << '\n';

	Board b = Board(16, 16, 25, true);

	MSUtils::Console::drawBoard(&b);
	cout << '\n';
	bool end = false;
	bool first = true;

	srand(time(NULL));

	while (!end) {
		short r = rand() % 16;
		short c = rand() % 16;
		if (b.getField(r, c)->getShown()) continue;

		end = b.LClick(b.getField(r, c), first);
		first = false;

		MSUtils::Console::drawBoard(&b);
	}
	if (end) cout << "YOU'VE LOST\n";
	MSUtils::Console::drawBoardUncovered(&b);

	cout << "Some field on board: " << b.getField(2, 2)->getFlag().getTypeAsString() << '\n';
	b.getField(2, 2)->setFlag(FLAGGED);
	cout << "Some field on board: " << b.getField(2, 2)->getFlag().getTypeAsString() << '\n';

	cout << "Surroundings of (0, 0): " << b.getSurroundingFields(0, 0).size() << '\n';
	cout << "Surroundings of (2, 2): " << b.getSurroundingFields(2, 2).size() << '\n';

	Field* myF = b.getSurroundingFields(2, 2)[2];
	cout << "Coords of [2] surrounder of (2, 2): (" << myF->getRow() << ", " << myF->getCol() << ")\n";

	cout << "=== End of static linking ===\n";

	MSUtils::Console::stopConsole();

	return 0;
}

