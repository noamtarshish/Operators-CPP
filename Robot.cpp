#include "Robot.h"


//define the serial number for the static parameter
int Robot::serialRobotNumber=0;

//constructor with values
Robot::Robot(int x, int y, int mapNum){
    this->x = x;
    this->y = y;
    this->mapNumber = mapNum;
    serialRobotNumber++;
    this->robotid = serialRobotNumber;

}

//copy constructor
Robot::Robot(const Robot &other):
    robotid(other.robotid),x(other.x),y(other.y),mapNumber(other.mapNumber){}

//operator implementation
Robot &Robot::operator=(const Robot &other){

    if (this == &other)
        return *this;

    robotid=other.robotid;
    x=other.x;
    y=other.y;
    mapNumber=other.mapNumber;
    return *this;
}

//destructor - there is no use in it because I did not allocate any parameter in the class
Robot::~Robot() {}

//getter the return the number of the map
int Robot::getMap() const {
    return mapNumber;
}

//getter that return the x of the map
int Robot::getx() const {
    return x;
}

//getter that return the y of the map
int Robot::gety() const {
    return y;
}

//getter that return the serial number of the robot
int Robot::getSerial() {
    return robotid;
}

//setter that set new x
void Robot::setX(int xx) {
    this->x=xx;
}

//setter that set new y
void Robot::setY(int yy) {
    this->y=yy;
}


















