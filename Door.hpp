#include <string>

#ifndef Door_hpp
#define Door_hpp

class Room;

using namespace std;

class Door
{
    private:
        string directionToRoomA;
        string directionToRoomB;
        Room* roomA;
        Room* roomB;

    public:
        Door(string directionToRoomA, Room* roomA, string directionToRoomB, Room* roomB);
        string getDirectionToOtherRoom(Room* currentRoom);
        bool hasDirection(string direction);
        void getDoor(string direction);
};
#endif
