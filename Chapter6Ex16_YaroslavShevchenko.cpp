/*

Tite Chapter 6 Exercise 16 - RWorld Series Champions
File name:Chapter6Ex16_YaroslavShevchenko.cpp
Programmer: Yaroslav Shevchenko
Date: 12/12/2024
Requirements:

For this programming problem, download the following files from the book’s companion website:

• Teams.txt—This file contains a list of several Major League baseball teams in alphabetical order. 
Each team listed in the file has won the World Series at least once.

• WorldSeriesWinners.txt—This file contains a chronological list of the World Series’ winning teams from 1903 to 2012. 
(The first line in the file is the name of the team that won in 1903, 
and the last line is the name of the team that won in 2012. 
Note the World Series was not played in 1904 or 1994.)

Write a program that displays the contents of the Teams.txt file on the screen and prompts the user to 
enter the name of one of the teams. The program should then display the number of times that team has won the 
World Series in the time period from 1903 to 2012.

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string teamName();
void teams();
void worldSeriesArray(string arr[], int size);
int winNum(string arr[], int size, string tn);



int main()
{
    const int size = 107; // 106 lines in the txt doc

    teams();

    string tn = teamName();

    string teamsArr[size];

    worldSeriesArray(teamsArr, size);

    int wins = winNum(teamsArr, size, tn);

    if (wins > 0) {
        cout << "The team " << tn << " won the World Series " << wins << " times." << endl;
    }
    else cout << "The team you entered either don't exist or have never wone the World Series" << endl;


}


void teams() {
    cout << "List of teams: " << endl;
    ifstream myFile;
    myFile.open("Teams.txt");
    string name;
    if (myFile.is_open()) {
        while (getline(myFile, name)) {

            cout << name << "; ";
        }
        cout << endl;
        myFile.close();
    }
    
}

string teamName() {
    string teamName;
    cout << "Enter team name: " << endl;
    getline(cin, teamName);
    return teamName;
}

void worldSeriesArray(string arr[], int size) {
    ifstream myFile;
    myFile.open("WorldSeriesWinners.txt");
    
    if (myFile.is_open()) {
        string teams;
        int i = 0;
        while (i<size && getline(myFile, teams)) {
            arr[i] = teams;
            i++;
        }
    }
    
}

int winNum(string arr[], int size, string tn) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i].compare(tn) == 0) {
            count++;
        }
    }
    return count;
}




