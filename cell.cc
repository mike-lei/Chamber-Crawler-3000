//
//  cell.cpp
//  test
//
//  Created by Wang Annan on 2016-11-19.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "cell.h"
#include "TextDisplay.h"
#include "CellObject.h"
#include "Floortiles.h"

using namespace std;

cell::cell(): object{nullptr} {}

void cell::setCoord(const int &row, const int &col) {
    x = row;
    y = col;
}

string cell::getType() const{
    return object->getType();
}

int cell::getX() const {
    return x;
}

int cell::getY() const {
    return y;
}

bool cell::CanSpawn() const{
    return can_spawn;
}

bool cell::CanPass() const{
    return can_pass;
}

CellObject * cell::getOb() const{
    return object;
}

void cell::change_can_spawn(const bool &boolval) {
    can_spawn = boolval;
}

void cell::change_can_pass(const bool &boolval) {
    can_pass = boolval;
}

void cell::clear() {
    delete object;
}

void cell::rm_object() {
    if(dynamic_cast<Floortiles*>(object)) {
        delete object;
    }
    else {
        object = nullptr;
    }
}

void cell::setOb(CellObject *object) {
    this->object = object;
}

void cell::notify(TextDisplay *td) {
    if (object) {
        td->notify(x, y, object->getType());
    }
    
}
