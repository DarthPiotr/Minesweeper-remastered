#include "stdafx.h"
#include "Board.h"
#include <vector>
#include <ctime>
#include "MSUtils.h"

namespace MSCore {
	Board::Board(short row, short col, int mines, bool unsure = true) : rows(row), cols(col), mines(mines), isFilled(false), enableUnsure(unsure)
	{
		board = new Field*[row];
		for (short i = 0; i < row; i++) {
			board[i] = new Field[col];
			for (int j = 0; j < col; j++)
				board[i][j] = Field(i, j);
		}
	}

	//private
	void Board::random(unsigned int seed, std::vector<Field*> restricted) {
		//std::cout << "Entering random...\n";

		srand(seed);

		// random mines positions
		std::vector<int> restrictedIndexes;

		for (int i = 0; i < restricted.size(); ++i)
			restrictedIndexes.push_back(getIndex(restricted[i]));

		for (int i = 0; i < mines;) {
			int r = rand() % getMaxIndex();
			bool valid = true;
			for (int j = 0; j < restrictedIndexes.size() && valid; ++j) {
				if (r == restrictedIndexes[j]) valid = false;
			}
			if (valid) {
				//std::cout << "Mine on index: " << r << '\n';
				getField(r)->setValue(-1);
				restrictedIndexes.push_back(r);
				++i;
			}
		}

		// setting numbers
		for (int i = 0; i < getMaxIndex(); ++i) {
			Field* f = getField(i);
			if (f->getValue() > -1) {
				short count = 0;
				std::vector<Field*> list = getSurroundingFields(f);
				for (int j = 0; j < list.size(); j++) {
					if (list[j]->getValue() == -1) count++;
				}
				f->setValue(count);
			}
		}

		//MSUtils::Console::drawBoardUncovered(this);
	}
	//private
	int Board::getMaxIndex() {
		return cols * rows;
	}

	int Board::getIndex(Field* f) {
		return f->getRow() * cols + f->getCol();
	}

	void Board::setUnsure(bool v) {
		enableUnsure = v;
	}

	bool Board::getUnsure() {
		return enableUnsure;
	}

	Field* Board::getField(short row, short col) {
		return &(board[row][col]);
	}

	Field* Board::getField(int index) {
		return &(board[index / rows][index%cols]);
	}

	short Board::getRows() {
		return rows;
	}
	short Board::getCols() {
		return cols;
	}

	std::vector<Field*> Board::getSurroundingFields(short row, short col) {
		std::vector<Field*> fields;
		for (short r = row - 1; r <= row + 1; r++) {
			for (short c = col - 1; c <= col + 1; c++) {
				if (r >= 0 && r < rows &&
					c >= 0 && c < cols &&
					!(r == row && c == col)) {
					fields.push_back(getField(r, c));
				}
			}
		}
		return fields;
	}

	std::vector<Field*> Board::getSurroundingFields(Field* f) {
		return getSurroundingFields(f->getRow(), f->getCol());
	}

	void Board::randomBoard(unsigned int seed) {
		random(seed, std::vector<Field*>());
	}
	void Board::randomBoard(Field* firstClickField) {
		seed = time(NULL);

		std::vector<Field*> restricted;
		restricted = getSurroundingFields(firstClickField);
		restricted.push_back(firstClickField);

		random(seed, restricted);

		isFilled = true;
	}

	unsigned int Board::getSeed() {
		return seed;
	}

	bool Board::LClick(Field* f, bool isFirst = false) {
		//f = getField(f->getRow(), f->getCol());
		if (isFirst) randomBoard(f);
		f = getField(f->getRow(), f->getCol());

		if (isFilled && f->getFlag().getTypeAsEnum() == UNFLAGGED && !f->getShown()) {
			f->setShown(true);

			//std::cout << "Value is: " << f->getValue();
			if (f->getValue() == 0) {
				//std::cout << " entered.";
				std::vector<Field*> list = getSurroundingFields(f);
				for (int i = 0; i < list.size(); i++) {
					//std::cout << "Checking at r:" << list[i]->getRow() << " c:" << list[i]->getCol() << " v:" << list[i]->getValue() << '\n';
					if (list[i]->getValue() == 0 && !list[i]->getShown()) LClick(list[i]);
					else list[i]->setShown(true);
				}
			}
			//std::cout << '\n';

		}
		return f->getValue() == -1;
	}

	void Board::RClick(Field* f) {

	}
	void Board::MClick(Field* f) {

	}
}

