
#include "Game.h"

//default constructor to game class
Game::Game() {

    sizeArray=0;
    robotArray=nullptr; // initialize the robot array to null
    robotmap1=Map(); // create new default map
    robotmap2=Map();

}

//function that add robot to the map
void Game::AddRobot() {

int mapnumber; //initialize the needed parameters to roboy
int x;
int y;

cout << "Enter MAP number: ";
cin >> mapnumber;
if (mapnumber != 1 && mapnumber != 2){ //if the number of the map is invalid
    cout << "Invalid MAP number" << endl;}
else{
    cout << "Enter Coordinates (X,Y): ";
    cin >> y;
    cin >> x;

    if (mapnumber == 1){
        if (robotmap1.getMapArrayIndex(x,y)==1){ //if the location of the new robot is wall
            cout << "Invalid location" << endl;
        }
        else{
            Robot *newrobot = new Robot(x, y, mapnumber); //create new robot
            Robot **temp = new Robot *[sizeArray + 1]; //create temp robot array
            for (int i = 0; i < sizeArray; i++) { //initialize every parameter in temp to robot array in the same index
                temp[i] = robotArray[i];
            }
            temp[sizeArray] = newrobot; //add the new robot to the temp array
            if(sizeArray != 0){
                delete[]robotArray;}
            sizeArray++;
            robotArray = temp; //implement the robot to the temp array


            //print the robot after the addition
            cout << "New Robot: " << newrobot->getSerial() << " MAP: " << newrobot->getMap() << " GPS: " << newrobot->gety()
                 << "," << newrobot->getx() << endl;

        }
    } //same but on map 2
    else if (mapnumber == 2){
        if (robotmap2.getMapArrayIndex(x,y)==1){
            cout << "Invalid location" << endl;
        }
        else{
            Robot* newrobot = new Robot(x, y, mapnumber);
            Robot **temp = new Robot *[sizeArray + 1];
            for (int i = 0; i < sizeArray; i++) {
                temp[i] = robotArray[i];
            }
            temp[sizeArray] = newrobot;
            if(sizeArray != 0){
                delete[]robotArray;}
            sizeArray++;
            robotArray = temp;



            cout << "New Robot: " << newrobot->getSerial() << " MAP: " << newrobot->getMap() << " GPS: " << newrobot->gety()
                 << "," << newrobot->getx() << endl;
        }
    }



} //else

} //function

//function that delete robot from the map
void Game::DeleteRobot() {

    int serial;
    cout << "Enter Robot number: ";
    cin >> serial;
    Robot *temp1; //create pointer to the robot
    for (int i=0;i<sizeArray;i++){
        if (robotArray[i]->getSerial()==serial){ //initialize the robot that needed to delete to nullptr
            temp1= robotArray[i];
            robotArray[i]=nullptr;
        }
    }

    int j=0;
    Robot **temp = new Robot *[sizeArray-1]; //initialize new robot temp array
    for (int i=0;i<sizeArray;i++){
        if(robotArray[i] != nullptr) {
            temp[j] = robotArray[i]; //implement temp array to robot array
            j++;
        }
    }
    delete[]robotArray;
    sizeArray--;
    robotArray=temp;

    //print the robot that deleted
    cout << "Robot deleted: " << serial << " MAP: " << temp1->getMap() << " GPS: " << temp1->gety() << "," << temp1->getx() << endl;
    delete temp1; //delete the temp robot


}

//function that move robot in a map by direction. the function check all the cases for the place of the robot
//include if the robot exit the map or move into wall index
void Game::MoveRobot() {

    int robotNum;
    cout << "Enter Robot number: ";
    cin >> robotNum;
    char direction;
    cout << "Enter Direction: ";
    cin >> direction;

    Robot *robotMove = nullptr; //initialize new robot as nullptr
    for (int i=0;i<sizeArray;i++){
        if (robotArray[i]->getSerial()==robotNum){
            robotMove=robotArray[i]; //find the robot in robot array by his number
        }
    }

    int robotmap = robotMove->getMap(); //find the map that the robot exist
    int newX=0,newY=0;
    if (direction == 'U') {
        newY=robotMove->gety();
        newX=robotMove->getx()+1;
    }
    else if (direction == 'D') {
        newY=robotMove->gety();
        newX=robotMove->getx()-1;
    }
    else if (direction == 'R') {
        newY=robotMove->gety()+1;
        newX=robotMove->getx();
    }
    else if (direction == 'L') {
        newY=robotMove->gety()-1;
        newX=robotMove->getx();
    }

    if (newX < 0 || newX > 6 || newY < 0 || newY > 6){ //if the robot exit the wall set it to -1 -1
        robotMove->setX(-1);
        robotMove->setY(-1);
    }
    else if (robotmap == 1 && robotmap1.getMapArrayIndex(newX,newY)==1) { //if the robot move to wall index
    }
    else if (robotmap == 2 && robotmap2.getMapArrayIndex(newX,newY)==1){
    }
    else{
        robotMove->setX(newX); //set the new x and new y of the robot
        robotMove->setY(newY);
    }

    //print the robot if it in map
    if (robotMove->getx()!= -1) {
        cout << "Robot: " << robotMove->getSerial() << " MAP: " << robotMove->getMap() << " GPS: " << robotMove->gety()
             << "," << robotMove->getx() << endl;
    }

}

//function that use operator = between two maps
void Game::implementMap() {

    int mapnumber;
    cout << "Override MAP number: " << endl;
    cin >> mapnumber;

    //implement by the number map to override by the other map
    if (mapnumber == 1){


        robotmap1=robotmap2;

        for (int i = 0; i < sizeArray; i++) {
            if (robotArray[i]->getMap() == 2) {
                if (robotmap1.getMapArrayIndex(robotArray[i]->getx(), robotArray[i]->gety()) == 1) { //check if robot is in wall after the override
                    delete robotArray[i];
                }

            }
        }

    }

    //same to the other map
    else if (mapnumber == 2){

        robotmap2=robotmap1;

        for (int i = 0; i < sizeArray; i++) {
            if (robotArray[i]->getMap() == 1) {
                if (robotmap2.getMapArrayIndex(robotArray[i]->getx(), robotArray[i]->gety()) == 1) {
                    delete robotArray[i];
                }

            }
        }

    }

    else
        cout << "Invalid MAP number" << endl;

}

//function that print the map and all the robot exists in map
void Game::printMap() {

    int number;
    cout << "Please enter MAP number: ";
    cin >> number;

    if (number == 1){
        cout << robotmap1 << endl;
        for (int i=0;i<sizeArray;i++){
            if (robotArray[i]->getMap()==1 && robotArray[i]->getx() != -1){
                cout << "Robot: " << robotArray[i]->getSerial()<< " MAP: " << robotArray[i]->getMap() << " GPS: " << robotArray[i]->gety() << "," << robotArray[i]->getx() << endl;

            }
        }
    }
    else{
        cout << robotmap2 << endl;
        for (int i=0;i<sizeArray;i++){
            if (robotArray[i]->getMap()==2 && robotArray[i]->getx() != -1){
                cout << "Robot: " << robotArray[i]->getSerial()<< " MAP: " << robotArray[i]->getMap() << " GPS: " << robotArray[i]->gety() << "," << robotArray[i]->getx() << endl;

            }
        }
    }

}

//function that use operator + to add two maps into new map and print it and the valid robots of the new map
void Game::addMap() {
    Map newmap = robotmap1+robotmap2;

    cout << newmap << endl;
    for (int i=0;i<sizeArray;i++){
        if (newmap.getMapArrayIndex(robotArray[i]->getx(), robotArray[i]->gety()) == 0 && robotArray[i]->getx() != -1) {
            cout << "Robot: " << robotArray[i]->getSerial() << " GPS: " << robotArray[i]->gety() << "," << robotArray[i]->getx() << endl;

        }
    }

}

//function that use operator += and delete robot that is in wall after the operator
void Game::addImpMap() {

    int mapNumber;
    cout << "Override MAP number: " << endl;
    cin >> mapNumber;


    if (mapNumber == 1){


        robotmap1+=robotmap2; //operator +=

        for (int i = 0; i < sizeArray; i++) {
            if (robotArray[i]->getMap() == 1) {
                if (robotmap1.getMapArrayIndex(robotArray[i]->getx(), robotArray[i]->gety()) == 1) { //check if robot exist in index wall
                    delete robotArray[i];
                }

            }
        }

    }

    //same to the other map
    else if (mapNumber == 2){

        robotmap2+=robotmap1;

        for (int i = 0; i < sizeArray; i++) {
            if (robotArray[i]->getMap() == 2) {
                if (robotmap2.getMapArrayIndex(robotArray[i]->getx(), robotArray[i]->gety()) == 1) {
                    delete robotArray[i];
                }

            }
        }
        cout << robotmap2 << endl;

    }
    //if the user input another number apart from 0 or 1
    else
        cout << "Invalid Map number";

}

//destructor to game class without nothing
Game::~Game() {

}

//function that quit the game and clean all the memory allocated during the game
void Game::quit() {

    for (int i=0;i<sizeArray;i++){ //delete every robot from the robot array
        delete robotArray[i];
    }
    delete[]robotArray; //delete the robot array itself

}



