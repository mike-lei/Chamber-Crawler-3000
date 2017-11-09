//
//  cell.hpp
//  test
//
//  Created by Wang Annan on 2016-11-19.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef cell_h
#define cell_h

#include <string>
#include <iostream>

class CellObject;
class TextDisplay;

class cell {
    int x = 0;
    int y = 0;
    bool can_spawn = false;
    bool can_pass = false;
    CellObject *object;
public:
    cell();
    int getX() const;
    int getY() const;
    std::string getType() const;
    bool CanSpawn() const;
    bool CanPass() const;
    CellObject * getOb() const;
    void clear();
    void rm_object();
    void change_can_pass(const bool &);
    void change_can_spawn(const bool &);
    void notify(TextDisplay *td);
    void setCoord (const int &row, const int &col);
    void setOb (CellObject *object);
};

#endif /* cell_hpp */
