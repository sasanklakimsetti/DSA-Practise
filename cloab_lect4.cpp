/*
Zara is developing a navigation system for a robot. The system uses directions to determine the robot's movement. So, implement a Navigator class that can receive direction input and provide corresponding navigation instructions.



In this scenario, the program allows you to input a direction using integer values representing the cardinal directions (North, East, West, and South). The code then utilizes the Navigator class to determine the corresponding navigation instruction based on the input direction.



Create an enum with all four directions: North, East, West, and South as the constants.



We will then use the switch case statements to switch between the direction elements and print the output based on the value of the variable for the enum directions.



Write a Program to print the direction.



Note: This is a sample question asked in a TCS interview.
*/
#include<iostream>
using namespace std;
enum class Direction{North=1,East,West,South};
class Navigator
{
    public:
    void printInstruction(Direction d)
    {
        switch(d)
        {
            case Direction::North:
            cout<<"We are headed towards North.";
            break;
            case Direction::East:
            cout<<"We are headed towards East.";
            break;
            case Direction::West:
            cout<<"We are headed towards West.";
            break;
            case Direction::South:
            cout<<"We are headed towards South.";
            break;
            default:
            cout<<"Invalid";
        }
    }
};
int main()
{
    int x;
    cin>>x;
    Navigator nav;
    Direction d= static_cast<Direction>(x);
    nav.printInstruction(d);
    return 0;
}