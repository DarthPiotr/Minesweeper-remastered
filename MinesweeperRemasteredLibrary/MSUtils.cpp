// MinesweeperRemasteredLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "MSUtils.h"
#include "Board.h"
#include "Field.h"

extern "C" {
	namespace MSUtils {

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		void Console::stopConsole() {
			std::cout << std::endl;
			system("pause");
		}

		void Console::drawBoard(MSCore::Board* board) {
			for (int r = 0; r < board->getRows(); ++r) {
				for (int c = 0; c < board->getCols(); ++c) {
					MSCore::Field* f = board->getField(c, r);
					std::cout << std::setw(3);
					writeString(f->getShown() ? std::to_string(f->getValue()) : "#");// f->getShown()? std::to_string(f->getValue()) : "X";
				}
				std::cout << '\n';
			}
			std::cout << '\n';
		}

		void Console::drawBoardUncovered(MSCore::Board* board) {
			for (int r = 0; r < board->getRows(); ++r) {
				for (int c = 0; c < board->getCols(); ++c) {
					MSCore::Field* f = board->getField(c, r);
					std::cout << std::setw(3);
					writeString(std::to_string(f->getValue()));
				}
				std::cout << '\n';
			}
			std::cout << '\n';
		}

		void Console::writeString(std::string s) {
			int defCol = 7;
			
			if(s == "#")
				SetConsoleTextAttribute(hConsole, 9);
			else if(s == "0")
				SetConsoleTextAttribute(hConsole, 0);
			else if(s == "-1")
				SetConsoleTextAttribute(hConsole, 12);
			else if(s == "F")
				SetConsoleTextAttribute(hConsole, 10);
			else 
				SetConsoleTextAttribute(hConsole, 15);

			std::cout << s;

			SetConsoleTextAttribute(hConsole, defCol);
		}
	}
}