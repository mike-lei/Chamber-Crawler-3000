//
//  chamber.cpp
//  test
//
//  Created by Wang Annan on 2016-11-19.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "chamber.h"
using namespace std;

Chamber::Chamber(const int &RoomNum):
ChamberNum{RoomNum} {}

unsigned long Chamber::getSize() {
    return room.size();
}

cell *Chamber::getCell(const int &pos) {
    return room[pos];
}

void Chamber::addToRoom(cell *c) {
    room.push_back(c);
}

void Chamber::clear() {
    room.clear();
}

bool Chamber::get_have_pc() const{
    return have_pc;
}

void Chamber::update_have_pc() {
    have_pc = true;
}
