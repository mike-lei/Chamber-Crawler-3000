//
//  textDisplay.hpp
//  test
//
//  Created by Wang Annan on 2016-11-20.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef textDisplay_hpp
#define textDisplay_hpp

#include <vector>
#include <string>

class player;

class TextDisplay {
    int row, col;
    const player *pc;
    std::string Action;
    std::vector< std::vector<std::string>> theDisplay;
public:
    TextDisplay (const int &row, const int &col);
    ~TextDisplay();
    
    int getRow() const;
    int getCol() const;
    std::string getAct() const;
    const player *getPc() const;
    std::string getType(const int &row, const int & col) const;
    
    void updateAct(const std::string &mssg);
    void resetAct();
    void setPc(const player *pc);
    void notify(const int &row, const int &col, const std::string &type);
};

std::ostream &operator<<(std::ostream &out, const TextDisplay &td);

#endif /* textDisplay_hpp */
