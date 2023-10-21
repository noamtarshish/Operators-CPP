#ifndef ASSIGNMENT4_MAP_H //compilation guard
#define ASSIGNMENT4_MAP_H
#include <iostream>
using namespace std;

//class Map is class for each one of the map to the game, every map has 2 int parameters:
// mapArray - multidimensional array in size 7x7 - represent the board to the game
// mapNumber - number represent which map is it - 1 for map1 and 2 for map2
class Map{
private:
    int mapArray[7][7];
    int mapNumber;
    ostream &show(ostream &out) const; //print function that print the map
public:
    Map(); //default constructor;
    Map(int number, int arr[7][7]); //constructor
    Map(const Map &other); //copy constructor
    Map operator+(const Map &other); //plus operator
    Map& operator=(const Map &other); //implementation operator
    void operator+=(const Map &other); //plus and implementation operator
    bool operator==(const Map &other) const; //equal operator
    friend ostream& operator<<(ostream& out, const Map& other); //friend operator for print the map

    int getMapArrayIndex(int i, int j); //function that get the index in the map (0 or 1)

    ~Map(); //destructor

};
















#endif //ASSIGNMENT4_MAP_H
