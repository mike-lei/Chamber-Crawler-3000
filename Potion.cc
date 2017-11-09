//
//  Potion.cpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "Potion.h"
using namespace std;

Potion::Potion(const string &name):type{'P'}, name{name} {}

string Potion::getRace() const {
    return type;
}

string Potion::getType() const {
    return type;
}

string Potion::getName() const {
    return name;
}

Potion::~Potion() {}


