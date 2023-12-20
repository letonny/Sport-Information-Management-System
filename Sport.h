// Sport.h
#ifndef SPORT_H
#define SPORT_H

#include <iostream>
#include <string>

struct Date
{
    int day;
    int month;
    int year;
};

class Sport
{
    private:
        std:: string sportName;
        Date nextScheduleGame;
        int numTeams;
        std:: string* teamNames;

    public:
        Sport(const std:: string& n = "");
        ~Sport();
        std:: string getSportName() const;
        void setSportName(const std:: string& n);
        Date getScheduleGame() const;
        void setScheduleGame(int day, int month, int year);
        int getNumTeam() const;
        std:: string getTeamName(int teamIndex) const;
        void displayInfo() const;
        void populate();
};

inline
Sport:: Sport(const std:: string& n)
{
    teamNames = nullptr;
    sportName = n;
}

inline
Sport:: ~Sport()
{
    delete[] teamNames;
    std:: cout << "Deconstructor complete.\n";
}

inline
std:: string Sport:: getSportName() const
{
    return sportName;
} 

void Sport:: setSportName(const std:: string& n)
{
    sportName = n;
}

inline
Date Sport:: getScheduleGame() const
{
    return nextScheduleGame;
}

void Sport:: setScheduleGame(int day, int month, int year)
{
    if (month >= 1 && month <= 12 && day >=1 && day <= 30)
    {
        nextScheduleGame.day = day;
        nextScheduleGame.month = month;
        nextScheduleGame.year = year;
    }
   
    else
    {
        nextScheduleGame.day = 1;
        nextScheduleGame.month = 1;
        nextScheduleGame.year = 2000;
    }
    
}

inline
int Sport:: getNumTeam() const
{
    int nonNegative = 5;
    
    if (numTeams < 0)
    {
        return nonNegative;
    }
    else
    {
        return numTeams;
    }
}

inline
std:: string Sport:: getTeamName(int teamIndex) const
{
    if (teamIndex >= 0 && teamIndex < numTeams)
    {
        return teamNames[teamIndex];
    }

    return "";
}

void Sport:: displayInfo() const
{
    std:: cout << "Sport Name: " << sportName << std:: endl
               << "Next Scheduled Game (Day/Month/Year): " << nextScheduleGame.day
               << " / " << nextScheduleGame.month << " / " << nextScheduleGame.year
               << "\nNumber of Teams: " << numTeams << std:: endl
               << "Teams: ";
    
    for (int i = 0; i < numTeams; i++)
    {
        std:: cout << "Team Name [" << i + 1 << "]: " << teamNames[i] << " ";
    }

    std:: cout << std:: endl;

}

void Sport:: populate()
{
    std:: cout << "Enter Sport Name: ";
    getline(std:: cin, sportName);
    setSportName(sportName);

    std:: cout << "Enter the Date of the Next Scheduled Game:\n"
               << "Day: ";
    std:: cin >> nextScheduleGame.day;

    std:: cout << "Month: ";
    std:: cin >> nextScheduleGame.month;

    std:: cout << "Year: ";
    std:: cin >> nextScheduleGame.year;

    std:: cout << "Enter Number of Teams: ";
    std:: cin >> numTeams;

    std:: cin.ignore();

    teamNames = new std:: string[numTeams];

    std:: cout << "Enter Team Names: " << std:: endl;

    for(int i = 0; i < numTeams; i++)
    {
        std:: cout << "Team " << i + 1 << ": ";
        std:: getline(std:: cin, teamNames[i]);
    }

    #endif
}