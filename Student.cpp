#include "Student.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

Student::Student(string name)
{
    this->name = name;
    this->currentRoom = 0;
    this->maxItemCount = 10;
    this->currentItemCount = 0;
    this->backpack = (Item**)malloc(this->maxItemCount * sizeof(Item*));
}

void Student::displayBackpackContents()
{
    if(this->currentItemCount == 0)
    {
        cout << "Empty Backpack\n";
        return;
    }
    else
    {
        for(int i = 0; i < this->currentItemCount; i++)
        {
            cout << this->backpack[i]->getName() << "\n";
        }
    }
    
    
}

Item* Student::removeItem(string itemName)
{
    for(int i = 0; i < this->currentItemCount; i++)
    {
        if(this->backpack[i]->getName() == itemName)
        {
            //remove the item from our backpack
            Item* itemToRemove = this->backpack[i];
            for(int j = i; j < this->currentItemCount-1; j++)
            {
                this->backpack[j] = this->backpack[j+1];
            }
            this->currentItemCount--;
            return itemToRemove;
        }
    }
    return 0;
}

bool Student::addItem(Item* anItem)
{
    if(this->currentItemCount == this->maxItemCount)
    {
        return false;
    }
    else
    {
        this->backpack[this->currentItemCount] = anItem;
        this->currentItemCount++;
        return true;
    } 
}

string Student::getName()
{
    return this->name;
}

void Student::setCurrentRoom(Room* aRoom)
{
    this->currentRoom = aRoom;
}

Room* Student::getCurrentRoom()
{
    return this->currentRoom;
}