#include <iostream>
#include <cstring>
#include "Map.h"
#include "Game.h"
using namespace std;

int main() {

//initialize the two maps for the game
int map1[7][7] = {
        {1, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 1, 1, 1, 0},
        {0,1,0,1,1,1,0},
        {1,1,0,0,0,0,1},
        {1,0,0,1,1,0,1}
};




int map2[7][7] = {
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 1, 1},
        {0, 1, 1, 1, 0, 1, 1},
        {1,1,0,0,0,1,1},
        {1,1,0,1,1,1,1},
        {1,1,0,0,0,1,1}
};

Map m1 = Map(1,map1);
Map m2 = Map(2,map2);
Game g(map1,map2);



//menu for the game
char chr='1';
while (chr!='9') {
cout << "Robot Control Menu"<<endl;
cout <<"1. Add Robot"<<endl;
cout <<"2. Delete Robot"<<endl;
cout <<"3. Move Robot"<<endl;
cout <<"4. Operator +"<<endl;
cout <<"5. Operator +="<<endl;
cout <<"6. Operator ="<<endl;
cout <<"7. Operator =="<<endl;
cout <<"8. Operator <<"<<endl;
cout <<"9. Quit"<<endl;
cout << "Input your option: ";
cin >> &chr;
if (strlen(&chr)>1){
    cout << "Invalid input" << endl;
    continue;
}
switch(chr){ //every case calling to the appropriate function for the game class
    case '1': //Add Robot
        g.AddRobot();
        break;

    case '2': //Delete Robot
        g.DeleteRobot();
        break;

    case '3': //Move Robot
        g.MoveRobot();
        break;

    case '4': //Operator +
        g.addMap();
        break;

    case '5': //Operator +=
        g.addImpMap();
        break;

    case '6': //Operator =
        g.implementMap();
        break;

    case '7': //Operator ==
        if (!m1.operator==(m2))
            cout<< "FALSE" << endl;

        else
            cout<<"TRUE" << endl;

        break;

    case '8': //Operator <<
        g.printMap();
        break;

    case '9': //Quit
        g.quit();
        break;

    default:
        cout << "Invalid input" << endl;
        break;

} //switch

} //while



} //main
