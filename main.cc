#include <iostream>
#include "floor.h"
#include "MoveControl.h"
#include "player.h"
#include <string>
#include <curses.h>

using namespace std;

int main(int argc, char *argv[]) {
    string mapname;
    if (argc > 1) {
        mapname = argv[1];
    }

    ifstream map{mapname}; // load the map file
    if (!map.is_open()) {
        cerr << mapname << "No map available. Please choose a map to set up the game. " << endl;
        return 1;
    }
    else {
        bool restart = true;
        bool quitgame = false;
        bool enemy_freeze = false;
        bool EnableWASD = false;
        
        while (restart) {
            string input;
            floor f;
            f.init(mapname); // initialize the the floor
            /*************************************************When Map is Default*************************************************/
            if (f.isEmptyMap()) {
                cout << "Welcome to the game, enjoy your time! " << endl;
                cout << "Please choose your race. The race will be defaulted as Shade if you input other words. " << endl;
                cout << "s: Shade" << endl << "d: Drow" << endl << "v: Vampire" << endl;
                cout << "t: Troll" << endl << "g: Goblin" << endl;
                
                cin >> input;
                if (input == "q") {
                    quitgame = true;
                    break;
                }
                if (input == "s" || input == "d" || input == "v" || input == "t" || input == "g") {
                    f.SpawnPlayer(input);
                }
                else {
                    f.SpawnPlayer("s");
                }
                f.SpawnStair("/");
                f.SpawnPotion("P");
                f.SpawnGold("G");
                f.SpawnEnemy();
            }
            /*************************************************When Map is Default*************************************************/
            else if (!f.isEmptyMap()) {
                cout << "You used the customized map. The race has been set. " << endl;
            }
            cout << f; // refresh the map status
            /*************************************************During the game*************************************************/
            cout << "Please enter [no, so, ea, we, nw, ne, sw, se] to move the PC. " << endl;
            string command;
            while (cin >> command) {
                input = MoveControl(command); // To get the full direction or command information
                if (input == "EnableWASD" || EnableWASD) {
                    EnableWASD = true;
                    
                }
                if (command == "f") {
                    enemy_freeze ? enemy_freeze = false : enemy_freeze = true;
                    if (enemy_freeze) {
                        input = "FreezeEnemy";
                    }
                    else {
                        input = "UnfreezeEnemy";
                    }
                } // PC can freeze the Enemies or unfreeze them
                
                f.move_pc(input); // PC moves
                if (f.Won()) {
                    cout << "You win! You have reached the end of all of floor. Do you want to play again? (yes/no) " << endl;
                    while (cin >> input) {
                        if (input == "yes") {
                            command = "r";
                            break;
                        }
                        else if (input == "no") {
                            command = "q";
                            break;
                        }
                        else {
                            cout << "Invalid input. " << endl;
                        }
                    }
                } // Valid command after User won
                if (command == "u") {
                    cin >> input;
                    f.pc_usePotion(MoveControl(input));
                } // PC tries to use the item on the specified direction
                if (command == "a") {
                    cin >> input;
                    f.pc_attack(MoveControl(input));
                } // PC tries to attack the enemy on the specified direction
                
                f.Enemy_move(enemy_freeze); // the enemies turn to react accordingly
                
                if (f.getPlayer()->get_hp() <= 0) {
                    cout << f;
                    cout << "You died! Do you want to play again? (yes/no) " << endl;
                    while (cin >> input) {
                        if (input == "yes") {
                            command = "r";
                            break;
                        }
                        else if (input == "no") {
                            command = "q";
                            break;
                        }
                        else {
                            cout << "Invalid input. " << endl;
                        }
                    }
                } // end of valid command after PC died
                if (command == "r") {
                    restart = true;
                    break;
                } // User tries to restart the game
                if (command == "q") {
                    restart = false;
                    cout << "Thank you for playing, hope you enjoy it. " << endl;
                    break;
                } // User quits the game while playing the game
                
                cout << f; // refresh the map status
                
            } // end of user command
            /*************************************************During the game*************************************************/
            
            if (restart) {
                continue;
            } // User to restart the game
            
        } // end of non-restart command
        if (quitgame) {
            cout << "Thank you for playing. " << endl;
        } // the user enter "q" at the race prompt
    } // the map file successfully opened
}
