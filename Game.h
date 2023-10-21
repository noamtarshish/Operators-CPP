#ifndef ASSIGNMENT4_GAME_H
#define ASSIGNMENT4_GAME_H //compilation guard
#include "Robot.h"
#include "Map.h"

//class Game is a class to modify the game with robot array, its size and the two maps, in this class I did all the function for the menu
class Game{

private:
    Robot **robotArray; //pointer to pointer to robot that contain all the robots in the game
    int sizeArray;
    Map robotmap1;
    Map robotmap2;

public:
    Game(int m1[7][7],int m2[7][7]):robotmap1(1,m1),robotmap2(2,m2),sizeArray(0),robotArray(nullptr){}; //constructor with values
    Game(); //copy constructor
    ~Game(); //destructor

    //all the functions that I used in the menu
    void AddRobot(); // case 1 - add robot to map
    void DeleteRobot(); // case 2 - remove robot from map
    void MoveRobot(); // case 3 - move robot in map
    void addMap(); // case 4 - add one map to other
    void addImpMap(); // case 5 - add one map and implement into new map
    void implementMap(); // case 6 - implement new map to other
    void printMap(); // case 8 - print the map
    void quit(); // case 9 - quit the game and clean all the memory



};


#endif //ASSIGNMENT4_GAME_H
