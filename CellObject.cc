//
//  CellObject.cpp
//  test
//
//  Created by Wang Annan on 2016-11-25.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "CellObject.h"

using namespace std;

TextDisplay * CellObject::td = nullptr;

vector <vector <cell>> CellObject::theGrid;

CellObject::CellObject() {}

CellObject::~CellObject() {}


void CellObject::setTd(TextDisplay *theDisplay) {
    td = theDisplay;
}


void CellObject::setGrid(vector<vector<cell>> &grid) {
    theGrid = grid;
}

