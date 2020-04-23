#include <iostream>
#include "LinkedListOfStudents.hpp"
#include "Student.hpp"

using namespace std;

int main()
{
    LinkedListOfStudents* ll = new LinkedListOfStudents();
    Student* s = 0;
    for(int i = 0; i < 10; i++)
    {
        s = new Student(((string)"name") + to_string(i));
        ll->addFront(s);
    }

    for(int i = 0; i < ll->getCount(); i++)
    {
        cout << ll->getAtIndex(i)->getName() << "\n";
    }
    
    ll->removeAtIndex(0);
    cout << ll->indexOf(s) << "\n";
    return 0;
}