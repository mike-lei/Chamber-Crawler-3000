//
//  Treasure.cpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "Treasure.h"
using namespace std;

Treasure::Treasure(const string &name): type{'G'}, name{name} {}

Treasure::~Treasure() {}

string Treasure::getType() const {
    return type;
}

string Treasure::getRace() const {
    return name;
}
