#include "Room.hpp"
#include <iostream>
#include "Door.hpp"

using namespace std;

Room::Room(string title)
{
    this->title = title;
    this->currentNumberOfDoors = 0;
}

void Room::addDoor(Door* aDoor)
{
    this->collectionOfDoors[this->currentNumberOfDoors] = aDoor;
    this->currentNumberOfDoors++;
    this->theStudents = new LinkedListOfStudents();
}

void Room::addStudent(Student* aStudent)
{
    this->theStudents->addFront(aStudent);
}

void Room::takeDoor(string direction)
{
    Door* tempDoor;
    for(int i = 0; i < this->currentNumberOfDoors; i++)
    {
        tempDoor = this->collectionOfDoors[i];
        ...///
    }
}

void Room::display()
{
    cout << this->title << "\n";

    //show the potential doors
    cout << "Obvious Exits: ";
    Door* tempDoor = 0;
    
    for(int i = 0; i < this->currentNumberOfDoors; i++)
    {
        tempDoor = this->collectionOfDoors[i];
        cout << tempDoor->getDirectionToOtherRoom(this) << " ";
    }
    cout << "\n Also Here: ";
    Student* tempStudent;

    for(int i = 0; i < this->theStudents->getCount(); i++)
    {
        tempStudent = this->theStudents->getAtIndex(i);
        cout << tempStudent->getName() << " ";
    }
    cout << "\n";
}