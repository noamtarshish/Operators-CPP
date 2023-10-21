#include "Map.h"

//default constructor - initialize map with 0 in all indexes
Map::Map() {

    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            mapArray[i][j]=0;
        }
    }

}

//constructor with values to initialize new map;
Map::Map(int number, int arr[7][7]) {

    mapNumber=number;

    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            mapArray[i][j]=arr[i][j];
        }

    }

}

//copy constructor that copy one map to other
Map::Map(const Map &other) {

    mapNumber = other.mapNumber;

    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            mapArray[i][j]=other.mapArray[i][j];
        }

    }
}

//operator implementation that implement one map to other
Map& Map::operator=(const Map &other) {

    this->mapNumber=other.mapNumber;
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            mapArray[i][j]=other.mapArray[i][j];
        }

    }
    return *this;

}
//operator add that add create new map, and add the two map
Map Map::operator+(const Map &other) {

    Map temp=Map();
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if (this->mapArray[i][j]+other.mapArray[i][j] == 0)
                temp.mapArray[i][j]=0;
            else
                temp.mapArray[i][j]=1;
        }

    }
    return temp;


}

//operator add and implementation that consist of the two operators
void Map::operator+=(const Map &other) {

    this->operator=(this->operator+(other));

}

//operator equal that check if two maps are equal
bool Map::operator==(const Map &other) const {

    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if (this->mapArray[i][j]!=other.mapArray[i][j])
                return false;
        }

    }
    return true;

}

//print function that print the map and every index in it
ostream &Map::show(ostream &out) const {

    for(int i = 6; i > -1; i--)
    {
        out << "[";
        for(int j = 0; j < 7; j++)
        {
            if (j!=6)
                out << mapArray[i][j] << " ";
            else
                out << mapArray[i][j]; //end of the map
        }
        out << "]" << endl;
    }
    return out;

}

//operator print that use show function
ostream &operator<<(ostream &out, const Map &other) {
    return other.show(out);
}

//destructor - there is no use in it because I did not allocate any parameter in the class
Map::~Map() {

}

//function that get int x and int y and find the index
int Map::getMapArrayIndex(int i, int j){
    return mapArray[i][j];
}










