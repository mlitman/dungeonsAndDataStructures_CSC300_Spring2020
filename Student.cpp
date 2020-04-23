#include "Student.hpp"

Student::Student(string name)
{
    this->name = name;
    this->currentRoom = 0;
}

string Student::getName()
{
    return this->name;
}

Room* Student::getCurrentRoom()
{
    return this->currentRoom;
}