#include "Sport.h"
#include <iostream>
#include <string>
using namespace std;

void sportOperation(Sport sports[], int size);

//****************************************************************************************************

int main ()
{
    const int SIZE = 3;

    Sport sports[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Sport #" << i + 1 << endl;
        sports[i].populate();
    }

    sportOperation(sports, SIZE); 

    return 0;
}

//****************************************************************************************************

void sportOperation(Sport sports[], int size)
{
    char choice;
    int indexPop;
    int indexDis;
    int totalTeams = 0;
    double avgTeams;
    int earliestIndex = 0;
    bool exit = false;

    do
    {
        cout << "Here are the following options: \n"
             << "a) All Sports in the array are populated\n"
             << "b) All Sports in the array are displayed\n"
             << "c) A particular Sport in the array is populated\n"
             << "d) A particular Sport in the array is displayed\n"
             << "e) Calculated & display the average number of teams in the 3 Sports in the array\n"
             << "f) Display the name of the Sport that is scheduled to take place on the earliest "
             << "date\n"
             << "x) To quit\n"
             << "Choose one option: ";
        cin >> choice;
        cin.ignore();

        if (choice == 'a')
        {
            for (int i = 0; i < size; i++)
            {
                sports[i].populate();
            }
        }

        else if (choice == 'b')
        {
            for (int i = 0; i < size; i++)
            {
                sports[i].displayInfo();
                cout << endl;
            }
        }

        else if (choice == 'c')
        {
            cout << "Enter the index of the Sport to populate: ";
            cin >> indexPop;
            cin.ignore();
            if (indexPop >= 0 && indexPop < size)
            {
                sports[indexPop].populate();
            }
        }

        else if (choice == 'd')
        {
            cout << "Enter the index of the Sport to display: ";
            cin >> indexDis;
            cin.ignore();

            if (indexDis >= 0 && indexDis < size)
            {
                sports[indexDis].displayInfo();
            }
        }

        else if (choice == 'e')
        {
            for (int i = 0; i < size; i++)
            {
                totalTeams += sports[i].getNumTeam();
            }
            
            if (size > 0)
            {
                avgTeams = static_cast<double>(totalTeams) / size;
                cout << "Average Number of Teams: " << avgTeams << endl;
            }
        }

        else if (choice == 'f')
        {
            for (int i = 1; i < size; i++)
            {
                Date current = sports[i].getScheduleGame();
                Date earliest = sports[earliestIndex].getScheduleGame();

                if (current.year < earliest.year ||
                    (current.year == earliest.year && current.month < earliest.month) || 
                    (current.year == earliest.year && current.month == earliest.month && 
                    current.day < earliest.day))
                {
                    earliestIndex = i;
                }
            }

            cout << "Sport with the Earliest Date: " << sports[earliestIndex].getSportName() << endl;
        }
        else if (choice == 'x')
        {
            cout << "Successfully quitted.\n";
        }
        
        else if (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice != 'e' 
                 && choice != 'f' && choice != 'x')
        {
            cout << "Invalid option. Please pick letters a-f in lowercase or 'x' to quit.\n";
        }
    } 
    while (choice != 'x');
}

/*

Sport #1
Enter Sport Name: Football
Enter the Date of the Next Scheduled Game:
Day: 12
Month: 12
Year: 2003
Enter Number of Teams: 2
Enter Team Names:
Team 1: Chiefs
Team 2: Rams
Sport #2
Enter Sport Name: Basketball
Enter the Date of the Next Scheduled Game:
Day: 12
Month: 2
Year: 2003
Enter Number of Teams: 3
Enter Team Names:
Team 1: Lakers
Team 2: Mavericks
Team 3: Heat
Sport #3
Enter Sport Name: Soccer
Enter the Date of the Next Scheduled Game:
Day: 04
Month: 11
Year: 2003
Enter Number of Teams: 4
Enter Team Names:
Team 1: Spurs
Team 2: Liverpool
Team 3: Madrid
Team 4: Manchester
Here are the following options:
a) All Sports in the array are populated
b) All Sports in the array are displayed
c) A particular Sport in the array is populated
d) A particular Sport in the array is displayed
e) Calculated & display the average number of teams in the 3 Sports in the array
f) Display the name of the Sport that is scheduled to take place on the earliest date
x) To quit
Choose one option: f
Sport with the Earliest Date: Basketball
Here are the following options:
a) All Sports in the array are populated
b) All Sports in the array are displayed
c) A particular Sport in the array is populated
d) A particular Sport in the array is displayed
e) Calculated & display the average number of teams in the 3 Sports in the array
f) Display the name of the Sport that is scheduled to take place on the earliest date
x) To quit
Choose one option: e
Average Number of Teams: 3
Here are the following options:
a) All Sports in the array are populated
b) All Sports in the array are displayed
c) A particular Sport in the array is populated
d) A particular Sport in the array is displayed
e) Calculated & display the average number of teams in the 3 Sports in the array
f) Display the name of the Sport that is scheduled to take place on the earliest date
x) To quit
Choose one option: b
Sport Name: Football
Next Scheduled Game (Day/Month/Year): 12 / 12 / 2003
Number of Teams: 2
Teams: Team Name [1]: Chiefs Team Name [2]: Rams

Sport Name: Basketball
Next Scheduled Game (Day/Month/Year): 12 / 2 / 2003
Number of Teams: 3
Teams: Team Name [1]: Lakers Team Name [2]: Mavericks Team Name [3]: Heat

Sport Name: Soccer
Next Scheduled Game (Day/Month/Year): 4 / 11 / 2003
Number of Teams: 4
Teams: Team Name [1]: Spurs Team Name [2]: Liverpool Team Name [3]: Madrid Team Name [4]: Manchester

Here are the following options:
a) All Sports in the array are populated
b) All Sports in the array are displayed
c) A particular Sport in the array is populated
d) A particular Sport in the array is displayed
e) Calculated & display the average number of teams in the 3 Sports in the array
f) Display the name of the Sport that is scheduled to take place on the earliest date
x) To quit
Choose one option: x
Successfully quitted.
Destructor complete.

*/