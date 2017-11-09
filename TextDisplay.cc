//
//  textDisplay.cpp
//  test
//
//  Created by Wang Annan on 2016-11-20.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "TextDisplay.h"
#include "player.h"
#include <iostream>
#include <iomanip>

using namespace std;

// TextDisplay constructor
TextDisplay::TextDisplay(const int &row, const int &col):
row{row}, col{col}, pc{nullptr}, Action{""} {
    theDisplay.resize(row, vector <string> (col, " "));
}

// TextDisplay destructor
TextDisplay::~TextDisplay() {
}

// set the player to be binded to the TextDisplay
void TextDisplay::setPc(const player *pc) {
    this->pc = pc;
}

// get the player
const player * TextDisplay::getPc() const{
    return pc;
}

// TextDisplay notify to change the position to be the char type
void TextDisplay::notify(const int &row, const int &col, const string &type) {
    theDisplay[row][col] = type;
}

// TextDisplay to get the Type according to row and col
string TextDisplay::getType(const int &row, const int &col) const{
    return theDisplay[row][col];
}

// get the row of TextDisplay
int TextDisplay::getRow() const {
    return row;
}

// get the col of TextDisplay
int TextDisplay::getCol() const {
    return col;
}

// update the Action of the player
void TextDisplay::updateAct(const string &mssg) {
    Action = Action + mssg;
}

// get the Action of TextDisplay
string TextDisplay::getAct() const{
    return Action;
}

// reset the Action information
void TextDisplay::resetAct() {
    Action = "";
}

// output overloading for displaying the grid
std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
    const int row = td.getRow();
    const int col = td.getCol();
    const player *tempPc = td.getPc();
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            out << td.getType(r, c);
        }
        out << endl;
    }

    out << "Race: " << tempPc->getRace() << " Gold: " << tempPc->get_gold();
    out << setw(50) << "floor " << tempPc->get_level() << endl;
    out << "HP: " << tempPc->get_hp() << endl;
    out << "Atk: " << tempPc->get_atk() << endl;
    out << "Def: " << tempPc->get_def() << endl;
    out << "Action: " << td.getAct() << endl;
    out << "\r" ;
    
    return out;
}
