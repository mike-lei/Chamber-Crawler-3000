//
//  floortiles.cpp
//  test
//
//  Created by Wang Annan on 2016-11-21.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "Floortiles.h"
using namespace std;

Floortiles::Floortiles(const string &type):
type {type} {}

Floortiles::~Floortiles() {}

string Floortiles::getType() const{
    return type;
}

string Floortiles::getRace() const {
    return type;
}
