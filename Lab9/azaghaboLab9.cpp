//Abdala Zaghab
//05/10/2024
//Soccer Statistics Report.

//Libraries used
#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>

//Constants
const int NAME_SPACE = 20, TEAM_SIZE = 4, NUMBER_OF_TEAMS = 3, FALSE_CONDITION = 4;

//Structures Used
struct SoccerPlayer
{
	char playerName[NAME_SPACE] = { "NONE" };
	int goalsScored = 0;
};

struct SoccerTeam
{
	char teamName[NAME_SPACE] = { "NONE" };
	int gamesPlayed = 0, totalWins=0;
	SoccerPlayer players[TEAM_SIZE];

};//All the primitive values from the structures are initialized with a default value.

//Function Prototypes
void copyrightDisplay();
void showStats(SoccerTeam [NUMBER_OF_TEAMS]);
void getTeamInfo(SoccerTeam[NUMBER_OF_TEAMS]);

using namespace std;

//Beggining of the program.
int main()
{
	cout << fixed << setprecision(2) << showpoint; // Two decimal places

	copyrightDisplay();// Copyright Display message.

	SoccerTeam teams[NUMBER_OF_TEAMS];// array of structure 3 different teams

	
	showStats(teams);//Show default report. "NONE" , 0
	getTeamInfo(teams);//Get the info from the user to fill the report.
	showStats(teams);//Shows the report with the information previously entered.

	cout << endl << endl;// End of the program
	system("pause");
	return 0;
}

//Copyright Display message. 
void copyrightDisplay()
{
	cout << "Lab - 9 Structures" << endl;
	cout << "Copyright 2024 - Howard Community College All rights reservedl unauthorized duplication prohibited." << endl;
	cout << "\n\tWelcome to the CMSY-141 Soccer Statistics Calculator" << endl;

	return;
}

//Shows the Report and the stats of the players and their respective teams.
void showStats(SoccerTeam team[NUMBER_OF_TEAMS])
{
	//variable decclarations 
	double average = 0;
	int losses = 0;

	cout << "\nData After Initialization:" << endl;

		for (int i = 0; i < NUMBER_OF_TEAMS; i++) //Outter Loop. Team's information
		{
			cout << "\nThe team: " << team[i].teamName << " has played " << team[i].gamesPlayed << " games." << endl;

			losses = team[i].gamesPlayed - team[i].totalWins;

			cout << "\tTheir record is " << team[i].totalWins << " wins and " << losses << " losses " << endl << endl;

			for (int j = 0; j < TEAM_SIZE; j++) //Inner Loop. Player's Information
			{
				cout << "Player : " << team[i].players[j].playerName << ", has " << team[i].players[j].goalsScored << " goals." << endl;

				if (team[i].gamesPlayed > 0)//Average Validation and calculation.
				{
					average = static_cast<double>(team[i].players[j].goalsScored )/ static_cast<double>(team[i].gamesPlayed);

					cout << "\tThey avearage "<< average<< " goals per game," << endl;
				}
				else// No number divied by 0 or a negative number
				{
					cout << "\tThe average goals are: No Games Played" << endl;
				}
			}
			cout << endl;
		}
	return;
}

//Gets the inpput from the user to fill the Reports and stat's calculations.
void getTeamInfo(SoccerTeam team[NUMBER_OF_TEAMS])
{
	for (int i = 0; i < NUMBER_OF_TEAMS; i++)// Outter loop. Team's input
	{
		cout << "\nUser Input:" << endl << endl;
		cout << "Enter the team's name: ";
		cin.getline(team[i].teamName, NAME_SPACE);

		cout << "Enter the number of games played: ";
		cin >> team[i].gamesPlayed;

		while (team[i].gamesPlayed < 0)//Validation of input for games played.
		{
			cout << "Error - number of games must be greater than or equal to zero. Please reenter.\n" << endl;

			cout << "Enter the number of games played: ";
			cin >> team[i].gamesPlayed;
		}

		cout << "Enter the number of games won: ";
		cin >> team[i].totalWins;

		while (team[i].totalWins < 0 || team[i].totalWins > team[i].gamesPlayed)// Validation of input for games won. it cannot be negative, nor bigger than the games played.
		{
			if (team[i].totalWins < 0)
			{
				cout << "Error - number of games won cannot be negative. Please reenter.\n" << endl;

				cout << "Enter the number of games played: ";
				cin >> team[i].totalWins;
			}
			else
			{
				cout << "Error - number of games won cannot be greater than the number of games played. Please reenter.\n" << endl;

				cout << "Enter the number of games played: ";
				cin >> team[i].totalWins;
			}
		}

		cin.ignore();// delete keyboard buffer
		
		int j = 0;// used to iterate over the array structures. Restart flag
		while (j < FALSE_CONDITION )// while loop to stop the task once the user types any type of "none" combination.
		{
				cout << "\tEnter name of player " << j + 1 << ": ";
				cin.getline(team[i].players[j].playerName, NAME_SPACE);


			for (int k = 0; k < strlen(team[i].players[j].playerName); k++)
			{
				team[i].players[j].playerName[k] = toupper(team[i].players[j].playerName[k]);// Converts the character string into all caps
			}
			if (strcmp(team[i].players[j].playerName, "NONE") == 0)// if it matches, it will return false.
			{
				j = FALSE_CONDITION;// This means that the program will not iterate more after none was typed.
			}

			if (j < FALSE_CONDITION)// If the value of j (index of iteration) is valid, it will ask for the goals
			{
				cout << "\tEnter goals scored "<< j+1 << ": ";
				cin >> team[i].players[j].goalsScored;
			}

			int k = 0;//index for the players iteration. Using j would have craashed the program if typed "NONE"
				while (team[i].players[k].goalsScored < 0)
				{
					cout << "Error - number of goals must be greater than zero. Please reenter\n" << endl;

					cout << "\tEnter goals scored " << j + 1 << ": ";
					cin >> team[i].players[k].goalsScored;

				}

				k++;//Add values to j and k for next iteration if valid.
				j++;
				cin.ignore();//delete keyboard buffer.
		}
		return;
	}
	
}