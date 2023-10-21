#ifndef ASSIGNMENT4_ROBOT_H
#define ASSIGNMENT4_ROBOT_H //compilation guard

#include "Map.h"
#include <iostream>
using namespace std; //namespace for cin and cout

//class Robot is class for the robot object, containing the robotid, the indexes of the robot in the map and the number of the map
//that the robot belong
class Robot{
private:
    static int serialRobotNumber; //static parameter that return the serial number of the robot
    int robotid; //robot number
    int x;
    int y;
    int mapNumber;
public:
    Robot(int x, int y, int mapNumber); //constructor
    Robot(const Robot& other); //copy constructor
    Robot& operator=(const Robot &other); //implementation operator
    ~Robot(); //destructor

    int getMap() const; //getter that return the number of the map
    int getx() const; //getter that return x of the map
    int gety() const; //getter that return y of the map
    int getSerial(); //getter that return the serial number
    void setX(int xx); //setter for the new x
    void setY(int yy); //setter for the new y


};


#endif //ASSIGNMENT4_ROBOT_H
