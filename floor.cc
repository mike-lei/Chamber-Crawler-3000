#include "cell.h"
#include "floor.h"
#include "chamber.h"
#include "TextDisplay.h"

using namespace std;

/**************************************HELPERS**************************************/
void rmObject(cell *target, const string &NewType);
map <int, string> get_num_dir ();
bool ValidAct (const string &input);
string Random_EnemyRace();
/**************************************HELPERS**************************************/

// floor constructor
floor::floor(): row{0}, col{0}, pc{nullptr}, td{nullptr}, NewFloor{false}, defaultMap{true}, DefaultMapName{"map.txt"},
FloorFactory{new MakeFloor}, CharacterFactory{new MakeCharacter}, ItemFactory{new MakeItem} {}

// floor destructor
floor::~floor() {
    clear();
}

// clear the floor
void floor::clear() {
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            if (!dynamic_cast<player*>(grid[r][c].getOb())) {
                grid[r][c].clear();
            }
        }
    }
    grid.clear();
    for (int i = 0; i < static_cast<int>(chamber.size()); ++ i) {
        chamber[i]->clear();
    }
    chamber.clear();
    delete td;
    
}

// return if it is not empty map
bool floor::isEmptyMap() const {
    return defaultMap;
}

// to check if the enemy reach the end of the 5th floor
bool floor::Won() const {
    return pc->get_level() == 6;
}

// get the player
player * floor::getPlayer() const {
    return pc;
}

// set the chamber space
void floor::CreateChamber() {
    const int ChamberNum = 5;
    for (int i = 0; i < ChamberNum; ++i) {
        chamber.push_back(new Chamber(i));
    }
}

// let the dragon to guard the treasure
void floor::DragonGuardDragonHoard() {
    for (int c = 0; c < col; ++c) {
        for (int r = 0; r < row; ++r) {
            DragonHoard *dh = dynamic_cast<DragonHoard*>(grid[r][c].getOb());
            if (dh) {
                int dh_col = dh->get_col();
                int dh_row = dh->get_row();
                for (int col = dh_col - 1; col <= dh_col + 1; ++col) {
                    for (int row = dh_row - 1; row <= dh_row; ++row) {
                        if (Dragon *d = dynamic_cast<Dragon*>(grid[row][col].getOb())) {
                            d->guardTreasure(dh);
                            dh->setDragon(d);
                        }
                    }
                }
            }
        }
    }
}

// read the file map and set the floor
void floor::init(const string &mapName) {
    string mapfileName = "";
    if (mapName != DefaultMapName) {
        defaultMap = false;
        mapfileName = mapName;
    }
    else {
        defaultMap = true;
        mapfileName = DefaultMapName;
    }
    ifstream map(mapfileName);
    int tempR = 0;
    int tempC = 0;
    CreateChamber();
    while (!map.eof()) {
        string linetiles;
        getline(map, linetiles);
        vector <cell> row;
        for (int c = 0; c < static_cast<int>(linetiles.length()); ++c, tempC = c) {
            cell theCell;
            theCell.setCoord(tempR, c);
            string type = "";
            type += linetiles[c];
            CellObject *obj = nullptr;
            if (type == "." || type == "|" || type == "-" ||
                type == "+" || type == "#" || type == "/" || type == " ") {
                if (type == ".") {
                    theCell.change_can_spawn(true);
                }
                if (type != ".") {
                    theCell.change_can_spawn(false);
                }
                if (type == "." || type == "#" || type == "+") {
                    theCell.change_can_pass(true);
                }
                obj = FloorFactory->CreateTiles(type);
            }
            else if (type == "0" || type == "1" || type == "2" ||
                     type == "3" || type == "4" || type == "5") {
                defaultMap = false;
                obj = ItemFactory->CreatePotion(stoi(type));
            }
            else if (type == "6" || type == "7" || type == "8" || type == "9") {
                defaultMap = false;
                theCell.change_can_pass(true);
                obj = ItemFactory->CreateTreasure(stoi(type));
                if (DragonHoard * dh = dynamic_cast<DragonHoard*>(obj)) {
                    theCell.change_can_pass(false);
                    dh->setPos(theCell.getX(), theCell.getY());
                }
            }
            else if (type == "H" || type == "O" || type == "E" ||
                     type == "W" || type == "D" || type == "L" || type == "M") {
                defaultMap = false;
                obj = CharacterFactory->CreateEnemy(type);
                if (enemy *e = dynamic_cast<enemy*>(obj)) {
                    e->updatepos(theCell.getX(), theCell.getY());
                }
            }
            else if (type == "s" || type == "d" || type == "v" ||
                     type == "t" || type == "g") {
                defaultMap = false;
                obj = CharacterFactory->CreatePlayer(type);
                this->pc = dynamic_cast<player*>(obj);
                pc->setPos(theCell.getX(), theCell.getY());
            }
            theCell.setOb(obj);
            row.emplace_back(theCell);
        } // created objects of the whole line read
        grid.emplace_back(row);
        ++tempR;
    }
    this->row = tempR - 1;
    this->col = tempC;
    if (!defaultMap) {
        DragonGuardDragonHoard(); // make dragon to guard the treasure if neccessary
    }
    td = new TextDisplay(row, col);
    td->setPc(pc);
    CellObject::setTd(td);
    CellObject::setGrid(grid);
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c){
            addToChamber(r, c);
            grid[r][c].notify(td);
        }
    }
}

// add the dotground to its own chamber room
void floor::addToChamber(const int &r, const int &c) {
    if (getRoom(r, c) == chamberVal::room1) {
        chamber[0]->addToRoom(&grid[r][c]);
    }
    if (getRoom(r, c) == chamberVal::room2) {
        chamber[1]->addToRoom(&grid[r][c]);
    }
    if (getRoom(r, c) == chamberVal::room3) {
        chamber[2]->addToRoom(&grid[r][c]);
    }
    if (getRoom(r, c) == chamberVal::room4) {
        chamber[3]->addToRoom(&grid[r][c]);
    }
    if (getRoom(r, c) == chamberVal::room5) {
        chamber[4]->addToRoom(&grid[r][c]);
    }
}

cell * floor::getRandomCell(const std::string &type) {
    cell *theCell;
    srand (static_cast <unsigned int> (time(nullptr)));
    int roomNum = rand() % 5;
    unsigned long roomSize = chamber[roomNum]->getSize();
    int cellPos = rand() % roomSize;
    theCell = chamber[roomNum]->getCell(cellPos);
    while (!theCell->CanSpawn() || (type == "Stair" && chamber[roomNum]->get_have_pc())) {
        roomNum = rand() % 5;
        roomSize = chamber[roomNum]->getSize();
        cellPos = rand() % roomSize;
        theCell = chamber[roomNum]->getCell(cellPos);
    }
    if (type == "PC") {
        chamber[roomNum]->update_have_pc();;
    }
    return theCell;
}

// random generate the player
void floor::SpawnPlayer(const string &race) {
    cell *playerCell = getRandomCell("PC");
    if (!NewFloor && playerCell->CanSpawn()) {
        player *newpc = CharacterFactory->CreatePlayer(race);
        rmObject(playerCell, newpc->getType());
        playerCell->setOb(newpc);
        this->pc = newpc;
        td->updateAct("Player spawned. ");
    }
    else if (NewFloor && playerCell->CanSpawn()) {
        NewFloor = false;
        cell *OldCell = &grid[pc->get_row()][pc->get_col()];
        rmObject(OldCell, pc->getOldTile());
        Floortiles *ground = FloorFactory->CreateTiles(pc->getOldTile());
        OldCell->setOb(ground);
        rmObject(playerCell, pc->getType());
        playerCell->setOb(pc);
        td->updateAct("PC moved to New Floor. ");
    }
    this->pc->setPos(playerCell->getX(), playerCell->getY());
    td->setPc(this->pc);
    playerCell->notify(td);
}

// random generate the stair
void floor::SpawnStair(const string &type) {
    cell *stairCell = getRandomCell("Stair");
    Floortiles *stair = FloorFactory->CreateTiles(type);
    rmObject(stairCell, stair->getType());
    stairCell->setOb(stair);
    stairCell->change_can_pass(true);
    stairCell->notify(td);
}

// random generate the potion
void floor::SpawnPotion(const string &type) {
    const int total_potion = 10;
    int numm_potion = 0;
    while (numm_potion < total_potion) {
        cell *potionCell = getRandomCell("Potion");
        int potion_id = rand() % 6;
        Potion *p = ItemFactory->CreatePotion(potion_id);
        rmObject(potionCell, p->getType());
        potionCell->setOb(p);
        potionCell->notify(td);
        ++numm_potion;
    }
}

// create a map with the input key and the cell as value
map <string, cell*> floor::get_dir_cell(const int &curRow, const int &curCol) {
    map <string, cell*> dir_cell;
    dir_cell["NorthWest"] = &grid[curRow-1][curCol-1];
    dir_cell["North"] = &grid[curRow-1][curCol];
    dir_cell["NorthEast"] = &grid[curRow-1][curCol+1];
    dir_cell["West"] = &grid[curRow][curCol-1];
    dir_cell["East"] = &grid[curRow][curCol+1];
    dir_cell["SouthWest"] = &grid[curRow+1][curCol-1];
    dir_cell["South"] = &grid[curRow+1][curCol];
    dir_cell["SouthEast"] = &grid[curRow+1][curCol+1];
    return dir_cell;
}

// random generate the Gold
void floor::SpawnGold(const string &type) {
    const int total_gold = 10;
    int num_gold = 0;
    while (num_gold < total_gold) {
        cell *GoldCell = getRandomCell("Gold");
        int treasureID = rand() % 8;
        GoldCell->rm_object();
        GoldCell->change_can_spawn(false);
        Treasure *t = nullptr;
        if (0 <= treasureID && treasureID <= 4) {
            const int NormalHoard = 6;
            t = ItemFactory->CreateTreasure(NormalHoard);
        }
        else if (5 <= treasureID && treasureID <= 6) {
            const int SmallHoard = 7;
            t = ItemFactory->CreateTreasure(SmallHoard);
        }
        else if (treasureID > 6) {
            GoldCell->change_can_pass(false);
            const int DragonHoard_num_translate = 9;
            t = ItemFactory->CreateTreasure(DragonHoard_num_translate);
            const int curRow = GoldCell->getX();
            const int curCol = GoldCell->getY();
            dynamic_cast<DragonHoard*>(t)->setPos(curRow, curCol);
            map <string, cell*> dir_cell = get_dir_cell(curRow, curCol);
            map <int, string> num_dir = get_num_dir();
            while (true) {
                int non_occupied_dirID= rand() % 8;
                cell *DragonCell = dir_cell[num_dir[non_occupied_dirID]];
                if (DragonCell->CanSpawn()) {
                    enemy *dragon = CharacterFactory->CreateEnemy("Dragon");
                    rmObject(DragonCell, dragon->getType());
                    DragonCell->setOb(dragon);
                    dragon->updatepos(DragonCell->getX(), DragonCell->getY());
                    dynamic_cast<DragonHoard*>(t)->setDragon(dragon);
                    dynamic_cast<Dragon*>(dragon)->guardTreasure(dynamic_cast<DragonHoard*>(t));
                    DragonCell->notify(td);
                    break;
                }
            }
        } // loop through the cell around the DragonHoard and
          // found the available cell to spawn Dragon
        GoldCell->setOb(t);
        GoldCell->notify(td);
        ++num_gold;

    }
}

// random generate the enemy
void floor::SpawnEnemy() {
    const int total_enemy = 20;
    int num_enemy = 0;
    while (num_enemy < total_enemy) {
        cell *enemyCell = getRandomCell("Enemy");
        ++num_enemy;
        enemy *NewEnemy = CharacterFactory->CreateEnemy(Random_EnemyRace());
        rmObject(enemyCell, NewEnemy->getType());
        enemyCell->setOb(NewEnemy);
        NewEnemy->updatepos(enemyCell->getX(), enemyCell->getY());
        enemyCell->notify(td);    
    }
}

// let the player to use the potion
void floor::pc_usePotion(const string &input) {
    td->resetAct();
    const int curRow = pc->get_row();
    const int curCol = pc->get_col();
    map <string, cell*> dir_cell = get_dir_cell(curRow, curCol);
    Potion *p = dynamic_cast<Potion*>(dir_cell[input]->getOb());
    if (p) {
        pc->Take_Potion(p);
        td->updateAct("PC uses " + p->getName() + ". ");
        cell *potionCell = dir_cell[input];
        Floortiles *dotTile = FloorFactory->CreateTiles(".");
        rmObject(potionCell, dotTile->getType());
        potionCell->setOb(dotTile);
        potionCell->notify(td);
    }
    else {
        td->updateAct("No item is usable over there. ");
    }
}

// PC to attack the enemy in the specified input if the enemy exists
void floor::pc_attack(const string &input) {
    srand(static_cast<unsigned int>(time(nullptr)));
    td->resetAct();
    if (ValidAct(input)) {
        const int curRow = pc->get_row();
        const int curCol = pc->get_col();
        map <string, cell*> dir_cell = get_dir_cell(curRow, curCol);
        cell *EnemyCell = dir_cell[input];
        enemy *theEnemy = dynamic_cast<enemy*>(EnemyCell->getOb());
        if (theEnemy) {
            pc->attack(theEnemy);
            if (theEnemy->get_hp() <= 0) {
                const int oldGoldVal = pc->get_gold();
                pc->steal_gold();
                td->updateAct("PC defeated " + theEnemy->getRace() + ". ");
                if (theEnemy->getRace() != "Human" && theEnemy->getRace() != "Merchant") {
                    int smallhoard_id = rand() % 2;
                    Treasure *t;
                    if (smallhoard_id) {
                        const int small_hoard = 7;
                        t = ItemFactory->CreateTreasure(small_hoard);
                    } else {
                        const int normal_hoard = 6;
                        t = ItemFactory->CreateTreasure(normal_hoard);
                    }
                    t->Take_Treasure(pc);
                }
                else if (theEnemy->getRace() == "Merchant") {
                    td->updateAct("There is a Treasure appered. ");
                    map <int, string> num_dir = get_num_dir();
                    map <string, cell*> dir_cell = get_dir_cell(theEnemy->get_row(), theEnemy->get_col());
                    int dir_key = rand() % 8;
                    for (; ; dir_key = rand() % 8) {
                        cell *DropTreasureCell = dir_cell[num_dir[dir_key]];
                        if (DropTreasureCell->CanSpawn()) {
                            DropTreasureCell->rm_object();
                            DropTreasureCell->change_can_spawn(false);
                            const int merchant_hoard = 8;
                            Treasure *MerchantHoard = ItemFactory->CreateTreasure(merchant_hoard);
                            DropTreasureCell->setOb(MerchantHoard);
                            DropTreasureCell->notify(td);
                            break;
                        }
                    }
                }
                else if (theEnemy->getRace() == "Human") {
                    td->updateAct("There are two Treasure appered. ");
                    map <int, string> num_dir = get_num_dir();
                    map <string, cell*> dir_cell = get_dir_cell(theEnemy->get_row(), theEnemy->get_col());
                    int dir_key = rand() % 8;
                    int total_normalhoard = 2;
                    for (int num_normalhoard = 0; num_normalhoard < total_normalhoard; dir_key = rand() % 8) {
                        cell *DropTreasureCell = dir_cell[num_dir[dir_key]];
                        if (DropTreasureCell->CanSpawn()) {
                            DropTreasureCell->rm_object();
                            DropTreasureCell->change_can_spawn(false);
                            const int normal_hoard = 6;
                            Treasure *NormalHoard = ItemFactory->CreateTreasure(normal_hoard);
                            DropTreasureCell->setOb(NormalHoard);
                            DropTreasureCell->notify(td);
                            ++num_normalhoard;
                        }
                    }
                }
                Floortiles *dotTile = FloorFactory->CreateTiles(".");
                rmObject(EnemyCell, dotTile->getType());
                EnemyCell->setOb(dotTile);
                EnemyCell->notify(td);
                const int GoldGained = pc->get_gold() - oldGoldVal;
                ostringstream num_to_str;
                num_to_str << GoldGained;
                td->updateAct("PC got " + num_to_str.str() + " gold. ");
            }
        }
        else {
            td->updateAct("No enemy over there. ");
        }
    }
    else {
        td->updateAct("Invalid Command. ");
    }
}

// check whether the player is within the 1-block radius of the hostile enemy or DragonHoard
bool nearby (player *pc, const int &row, const int &col) {
    for (int r = row - 1; r <= row + 1; ++r) {
        for (int c = col - 1; c <= col + 1; ++c) {
            if (pc->get_row() == r && pc->get_col() == c) {
                return true;
            }
        }
    }
    return false;
}

// enemy random move
void floor::Enemy_move(bool &freeze) {
    srand(static_cast<unsigned int>(time(nullptr)));
    map <int, string> num_dir = get_num_dir();
    vector <enemy*> enemies;
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++ c) {
            enemy *is_enemy = dynamic_cast<enemy*>(grid[r][c].getOb());
            if (is_enemy) {
                enemies.push_back(is_enemy);
            }
        }
    } // get the enemy from the map
    
    for (int i = 0, dir_key = 0; i < static_cast<int>(enemies.size()); dir_key = rand() % 8) {
        enemy *theEnemy = enemies[i];
        if (Dragon *dragon = dynamic_cast<Dragon*>(theEnemy)) {
            ++i;
            DragonHoard *dragon_hoard = dragon->getDragonHoard();
            if (nearby(pc, theEnemy->get_row(), theEnemy->get_col())) {
                dragon->attack(pc);
            }
	    if (dragon_hoard) {
		if (nearby(pc, dragon_hoard->get_row(), dragon_hoard->get_col())) {
		    dragon->attack(pc);
		}
	    }
        } // check if the PC near the Dragon or DragonHoard
        else {
            if (nearby(pc, theEnemy->get_row(), theEnemy->get_col()) && theEnemy->is_hostile()) {
                theEnemy->attack(pc);
                ++i;
            } // If PC near enemy, enemy will attack PC
            else if (!freeze) {
                map <string, cell*> dir_cell = get_dir_cell(theEnemy->get_row(), theEnemy->get_col());
                cell *NewEnemyCell = dir_cell[num_dir[dir_key]];
                cell *oldEnemyCell = &grid[theEnemy->get_row()][theEnemy->get_col()];
                if(NewEnemyCell->CanSpawn()) {
                    rmObject(NewEnemyCell, theEnemy->getType());
                    NewEnemyCell->setOb(theEnemy);
                    theEnemy->updatepos(NewEnemyCell->getX(), NewEnemyCell->getY());
                    NewEnemyCell->notify(td);
                    
                    Floortiles *dotTile = FloorFactory->CreateTiles(".");
                    rmObject(oldEnemyCell, dotTile->getType());
                    oldEnemyCell->setOb(dotTile);
                    oldEnemyCell->notify(td);
                    ++i;
                }
            } // PC is not near enemy, enemy will resume random move
            else {
                ++i;
            }
        }
    }
}

// move the player corresponding to input
void floor::move_pc(const std::string &input) {
    td->resetAct();
    bool moved = false;
    int OldRow = pc->get_row();
    int OldCol = pc->get_col();
    string PotionMssg = "";
    if (ValidAct(input)) {
        pc->move(input);
        moved = true;
    }
    if (moved) {
        int newrow = pc->get_row();
        int newcol = pc->get_col();
        cell *NewPlayerCell = &grid[newrow][newcol];
        cell *oldPlayerCell = &grid[OldRow][OldCol];
        for (int r = newrow - 1; r <= newrow + 1; ++r) {
            for (int c = newcol - 1; c <= newcol + 1; ++c) {
                Potion *p = dynamic_cast<Potion*>(grid[r][c].getOb());
                if (p && !p->getFound()) {
                    PotionMssg = "PC sees an unknown potion. ";
                }
                if (p && p->getFound()) {
                    PotionMssg = "PC sees a potion " + p->getName() + ". ";
                }
            }
        } // check if PC sees the Potion
        
        string move_ontoType = NewPlayerCell->getType();
        if (move_ontoType == "/") {
            NewFloor = true;
            this->clear();
            this->init("map.txt");
            this->SpawnPlayer(pc->getRace());
            this->SpawnStair("/");
            this->SpawnPotion("P");
            this->SpawnGold("G");
            this->SpawnEnemy();
            pc->change_OldTile(".");
            pc->goToNewFloor();
        } // check if the PC move onto Stair
        else {
            Treasure *t = dynamic_cast <Treasure*> (NewPlayerCell->getOb());
            DragonHoard *dh = dynamic_cast<DragonHoard*>(t);
            if (dh) {
                if (dh->dragon_died()) {
                    NewPlayerCell->change_can_pass(true);
                }
            }
            if (!NewPlayerCell->CanPass()) {
                pc->setPos(OldRow, OldCol);
                if (dh) {
                    if (!dh->dragon_died()) {
                        td->updateAct("The Dragon is still alive, slain it before taking the Treasure Gold. ");
                    }
                }
                else {
                    td->updateAct("PC cannot reach that position. ");
                }
            }
	    if (NewPlayerCell->CanPass()) {
                if (ValidAct(input)) {
                    td->updateAct("PC moves " + input + ". " + PotionMssg);
                }
                if (t) {
                    td->resetAct();
                    if (dh) {
			if (dh->dragon_died()) {
                            t->Take_Treasure(pc);
                            td->updateAct("PC gets a " + t->getRace() + ". ");
                    	}
		    }
                    else if (!dh) {
                        t->Take_Treasure(pc);
                        td->updateAct("PC gets a " + t->getRace() + ". ");
                    }
                }
                string oldType = pc->getOldTile();
                if (oldType == "G") { oldType = '.';}
                rmObject(NewPlayerCell, pc->getType());
                pc->setPos(newrow, newcol);
                pc->change_OldTile(move_ontoType);
                NewPlayerCell->setOb(pc);
                NewPlayerCell->notify(td);
                
                Floortiles *dotTile = FloorFactory->CreateTiles(oldType);
                rmObject(oldPlayerCell, dotTile->getType());
                oldPlayerCell->setOb(dotTile);
                oldPlayerCell->notify(td);
                td->setPc(pc);
            }
        }
    }// end of valid action
    else if (input == "FreezeEnemy") {
        td->updateAct("Freeze Enemies! ");
    }
    else if (input == "UnfreezeEnemy") {
        td->updateAct("Unfreeze Enemies! ");
    }
    else if (input == "NoCommand") {
        td->updateAct("Invalid Command. ");
    }
}

// to get the TextDisplay
TextDisplay* floor::getTd() const{
    return td;
}

// output overloding to print the floor
std::ostream &operator<<(std::ostream &out, const floor &floor) {
    out << *floor.getTd();
    return out;
}

/**************************************HELPERS**************************************/
// remove the object of the cell
void rmObject(cell *target, const string &NewType) {
    if (NewType == ".") {
        target->change_can_spawn(true);
    }
    if (NewType != ".") {
        target->change_can_pass(false);
        target->change_can_spawn(false);
    }
    if (NewType == "." || NewType == "#" || NewType == "+") {
        target->change_can_pass(true);
    }
    target->rm_object();
}

// create a map with the input key and the input as value
map <int, string> get_num_dir () {
    map <int, string> num_dir;
    num_dir[0] = "NorthWest";
    num_dir[1] = "North";
    num_dir[2] = "NorthEast";
    num_dir[3] = "West";
    num_dir[4] = "East";
    num_dir[5] = "SouthWest";
    num_dir[6] = "South";
    num_dir[7] = "SouthEast";
    return num_dir;
}

//check valid input and valid action
bool ValidAct (const string &input) {
    if (input == "North" || input == "East" || input == "South" || input == "West" ||
        input == "NorthEast" || input == "NorthWest" || input == "SouthEast" || input == "SouthWest") {
        return true;
    }
    else {
        return false;
    }
}

// get random enemy race
string Random_EnemyRace() {
    int enemy_id;
    enemy_id = rand() % 18;
    string enemy_race;
    if (0 <= enemy_id && enemy_id <= 3) {
        enemy_race = "Human";
    }
    if (4 <= enemy_id && enemy_id <= 6) {
        enemy_race = "Dwarf";
    }
    if (7 <= enemy_id && enemy_id <= 11) {
        enemy_race = "Halfling";
    }
    if (12 <= enemy_id && enemy_id <= 13) {
        enemy_race = "Elf";
    }
    if (14 <= enemy_id && enemy_id <= 15) {
        enemy_race = "Orc";
    }
    if (16 <= enemy_id && enemy_id <= 17) {
        enemy_race = "Merchant";
    }
    return enemy_race;
}
/**************************************HELPERS**************************************/
