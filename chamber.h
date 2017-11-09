//
//  chamber.hpp
//  test
//
//  Created by Wang Annan on 2016-11-19.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef chamber_hpp
#define chamber_hpp

#include <vector>
#include "ChamberVal.h"

class cell;

class Chamber {
    int ChamberNum;
    bool have_pc = false;
    std::vector <cell*> room;
public:
    Chamber(const int &RoomNum);
    unsigned long getSize();
    cell *getCell(const int &pos);
    bool get_have_pc() const;
    void addToRoom(cell *c);
    void update_have_pc();
    void clear();
    
};
#endif /* chamber_hpp */
