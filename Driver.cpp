#include <iostream>
#include "Student.hpp"
#include "Room.hpp"
#include "Door.hpp"
#include "Student.hpp"
#include "Item.hpp"

using namespace std;

string getCommand(string s)
{
    string command ="";
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == ' ')
        {
            return command;
        }
        command += s[i];
    }
    return command;
}

string getParamsFromCommand(string s)
{
    string params = "";
    int i = 0;
    while(s[i] != ' ')
    {
        i++;
    }

    for(int j = i+1; j < s.length(); j++)
    {
        params += s[j];
    }
    return params;
}

int main()
{
    Student* theStudent = new Student("Mr. Gonzales");
    Room* lobby = new Room("Lobby");
    Room* serverRoom = new Room("Server Room");
    Room* esports = new Room("Esports");
    Room* locklairOffice = new Room("Lockair's Office");

    Door* d1 = new Door("north", serverRoom, "south", lobby);
    Door* d2 = new Door("west", locklairOffice, "east", lobby);
    Door* d3 = new Door("south", esports, "north", lobby);

    string commandString = "";
    string command = "";
    string params = "";
    lobby->addStudent(theStudent);

    Item* chainsaw = new Item("a running chainsaw");
    theStudent->addItem(chainsaw);
    theStudent->addItem(new Item("machete"));

    while(command != "quit")
    {
        theStudent->getCurrentRoom()->display();
        cout << "What would you like to do?: ";
        getline(cin, commandString); 
        command = getCommand(commandString);

        if(command == "backpack")
        {
            theStudent->displayBackpackContents();
        }
        else if(command == "drop")
        {
            params = getParamsFromCommand(commandString);
            Item* droppedItem = theStudent->removeItem(params);
            if(droppedItem)
            {
                cout << "you dropped " << params << "\n";
                theStudent->getCurrentRoom()->addItem(droppedItem);
            }
        }
        else if(command == "pickup")
        {
            params = getParamsFromCommand(commandString);
            Item* pickedUpItem = theStudent->getCurrentRoom()->removeItem(params);
            if(pickedUpItem)
            {
                cout << "you picked up " << params << "\n";
                theStudent->addItem(pickedUpItem);
            }
        }
        else
        {
            theStudent->getCurrentRoom()->takeDoor(theStudent, command);
        } 
    }
    cout << "Goodbye!!!\n";
    return 0;
}