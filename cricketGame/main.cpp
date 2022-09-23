// All header files are declared here
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
using namespace std;

// All universal variables and array
string Team1[4];
int Team1IndividualScore[4];
int Team1IndividualBallPlayed[4];
int Team1Wicket = 0;
int Team1Score;

string Team2[4];
int Team2IndividualScore[4];
int Team2IndividualBallPlayed[4];
int Team2Wicket = 0;
int Team2Score;

int decisionToss;
int tossResult;

//Exception are handled
class Welcome
{
public:
    //Welcome message is displayed here
    Welcome()
    {
        cout << "----------------------------------------------------------------\n"
             << "     =====================***CRICIN***=====================     \n"
             << "\n"
             << "              WELCOME TO THE VIRTUAL CRICKET GAME               \n"
             << "----------------------------------------------------------------\n"
             << "                    xxx===INSTRUCTIONS===xxx                    \n"
             << "\n"
             << "1. Create 2 teams 'Team1' & 'Team2' with 4 players each from a\n"
             << "   given pool of 11 players.\n"
             << "2. Lead the toss and decide the choice of play.\n"
             << "3. Each inning will be of 6 balls.\n"
             << "----------------------------------------------------------------\n"
             << "Press ENTER to continue...\n";
        cin.get();   // get is use so that the programs stop till the user press ENTER
        cin.clear(); // used to clear buffer memory for further use
    }
};

//Exception are handled
class TeamSelect
{
private:
    string AllPlayer[11] = {"Virat", "Rohit", "Dhawan", "Pant", "Karthik", "KLRahul", "Jadeja", "Hardik", "Bumrah", "BKumar", "Ishant"};
    vector<int> arr;
    // Checks if the integer is present in the vector
    bool check(int a)
    {
        bool temp;
        if (find(arr.begin(), arr.end(), a) != arr.end()) // It check if the integer 'a' is present in an unsorted vector arr
            return true;
        else
        {
            arr.push_back(a);
            return false;
        }
    };

public:
    TeamSelect()
    {
        cout << "----------------------------------------------------------------\n"
             << "                  xxx***POOL OF PLAYERS***xxx                   \n"
             << "----------------------------------------------------------------\n"
             << "\n";
        // Displays the list of player
        for (int i = 0; i < 5; i++)
        {
            cout << "\t [" << 2 * i + 1 << "] " << AllPlayer[2 * i] << "\t\t [" << 2 * i + 2 << "] " << AllPlayer[2 * i + 1] << endl
                 << "\n";
        }
        // Last player is displayed differently for it don't fit in regular design using for
        cout << "\t [11]" << AllPlayer[10] << endl;
        cout << "----------------------------------------------------------------\n";
    }

    //Team is created in this class function
    void CreateTeam()
    {
        int selectedOption;
        cout << "----------------------------------------------------------------\n"
             << "              <=== LETS SELECT OUR PLAYERS ===>\n"
             << "----------------------------------------------------------------\n";
        //Inside for loop user select team player for both teams
        for (int i = 1; i < 5; i++)
        {
            bool error = true;
            //Team1 selection
            while (error) // Used for error handling
            {
                cin.clear(); //clear and ignore are use for clearing cin memory
                cin.ignore();
                cout << "Select player " << i << " of Team1: ";
                cin >> selectedOption;
                if (selectedOption < 1 || selectedOption > 11) //Handle the error of wrong input
                {
                    cout << "Please enter correct option!!!\n\n";
                }
                else
                {
                    bool temp = check(selectedOption); //checks if user had already selcetd the player
                    if (temp)
                    {
                        cout << "Player already selected. Please select other player!!!\n";
                    }
                    else
                    {
                        Team1[i - 1] = AllPlayer[selectedOption - 1];
                        error = false; //Thus only when the right answer is inputed the while loop is terminated
                    }
                }
            }
            //Team2 selection
            //Same as above concept
            error = true;
            while (error)
            {
                cin.clear();
                cin.ignore();
                cout << "Select player " << i << " of Team2: ";
                cin >> selectedOption;
                if (selectedOption < 1 || selectedOption > 11)
                {
                    cout << "Please enter correct option!!!\n\n";
                }
                else
                {
                    bool temp1 = check(selectedOption);
                    if (temp1)
                    {
                        cout << "Player already selected. Please select other player!!!\n";
                    }
                    else
                    {
                        Team2[i - 1] = AllPlayer[selectedOption - 1];
                        error = false;
                    }
                }
            }
        }
    }

    //Displayes teams
    void teamDisplay()
    {
        cout << "\n===================================================\n"
             << "Displaying Team1.....\n";
        for (int i = 0; i < 4; i++)
        {
            cout << "   [" << i + 1 << "] " << Team1[i] << endl;
        }
        cout << "\n===================================================\n"
             << "Displaying Team2.....\n";
        for (int i = 0; i < 4; i++)
        {
            cout << "   [" << i + 1 << "] " << Team2[i] << endl;
        }
    }
};

//Exception are handled
class Toss
{
public:
    Toss()
    {
        tossResult = rand() % 2; //Gives random number between 1 and 2
        cout << "=====================================================\n";
        cout << "           --------***LET'S TOSS***--------\n";
        cout << "=====================================================\n"
             << "Press ENTER to Toss...\n";
        cin.ignore();
        cin.get();
        cout << "Tossing the coin...\n";

        bool error = true;
        //Error are handled from here
        while (error)
        {
            if (tossResult == 0) //Same exception handling concept as used in team selection class
            {
                cout << "Team1 won the toss!!\n"
                     << "Enter 1 to bat or 2 to ball: ";
                cin >> decisionToss;
                if (decisionToss < 1 || decisionToss > 2)
                {
                    cout << "Please enter correct option!!!\n\n";
                }
                else
                {
                    if (decisionToss == 1)
                        cout << "\n\t-->Team1 won the toss and elected to BAT first\n";
                    else
                        cout << "\n\t-->Team1 won the toss and elected to BALL first\n";
                    error = false; //While loop will get terminated now
                }
                cin.clear();
                cin.ignore();
            }
            else
            {
                cout << "Team2 won the toss!!\n"
                     << "Enter 1 to bat or 2 to ball: ";
                cin >> decisionToss;
                if (decisionToss < 1 || decisionToss > 2)
                {
                    cout << "Please enter correct option!!!\n\n";
                }
                else
                {
                    if (decisionToss == 1)
                        cout << "Team2 won the toss and elected to BAT first\n";
                    else
                        cout << "Team2 won the toss and elected to BALL first\n";
                    error = false; //While loop will get terminated now
                }
                cin.clear();
                cin.ignore();
            }
        }
    }
};

//Errors are handled
class Inning
{
protected:
    int batter = 0;
    void run(int whoseBatting)
    {
        int temp = rand() % 7; //Gives random number between 0 to 6; 0=out and rest are runs
        if (whoseBatting == 1)
        {
            Team1Score += temp; // It makes changes in score, individual score, ball played;
            Team1IndividualScore[batter] += temp;
            Team1IndividualBallPlayed[batter]++;
        }
        else
        {
            Team2Score += temp;
            Team2IndividualScore[batter] += temp;
            Team2IndividualBallPlayed[batter]++;
        }
        if (temp == 0) //Displays out message
        {
            cout << "\nOUT!!\n\n";
            batter++;
            if (whoseBatting == 1)
                Team1Wicket++;
            else
                Team2Wicket++;
        }
        else //Displays run message
        {
            cout << " " << temp << " runs!\n\n";
        }
    }
    void welcomeMessage(int inning) //welcome message displaying inning starting message
    {
        cout << "\n===================================================\n";
        cout << "\n             Inning " << inning << " started!!!\n";
        cout << "\n===================================================\n";
        if ((tossResult == 0 && decisionToss == 1) || (tossResult == 1 && decisionToss == 2))
        {
            cout << "Team1: " << Team1[0] << " is batting\n"
                 << "Team2: " << Team2[0] << " is balling\n\n";
        }
        else
        {
            cout << "Team1: " << Team1[0] << " is balling\n"
                 << "Team2: " << Team2[0] << " is battng\n\n";
        }
    }

public:
    void bowling() // just design
    {
        welcomeMessage(1);
        for (int i = 1; i < 7; i++)
        {
            cout << "Press ENTER to bowl...";
            cin.get();
            cout << "Bowling...\n\n";
            if ((tossResult == 0 && decisionToss == 1) || (tossResult == 1 && decisionToss == 2))
            {
                cout << Team2[0] << " to " << Team1[batter];
                run(1);
                cout << "---------------------------------------\n"
                     << "Team1: " << Team1Score << " - " << Team2Wicket << "(" << i << ")\n"
                     << "---------------------------------------\n\n";
            }
            else
            {
                cout << Team1[0] << " to " << Team2[batter];
                run(2);
                cout << "---------------------------------------\n"
                     << "Team2: " << Team2Score << " - " << Team1Wicket << "(" << i << ")\n"
                     << "---------------------------------------\n\n";
            }
        }
        cout << "\t\t!!! INNING ENDED !!!\n\n";
        batter = 0;

        welcomeMessage(2);
        for (int i = 1; i < 7; i++)
        {
            cout << "Press ENTER to bowl...";
            cin.get();
            cout << "Bowling...\n\n";
            if ((tossResult == 0 && decisionToss == 1) || (tossResult == 1 && decisionToss == 2))
            {
                cout << Team1[0] << " to " << Team2[batter];
                run(2);
                cout << "---------------------------------------\n"
                     << "Team2: " << Team2Score << " - " << Team1Wicket << "(" << i << ")\n"
                     << "---------------------------------------\n\n";
            }
            else
            {
                cout << Team2[0] << " to " << Team1[batter];
                run(1);
                cout << "---------------------------------------\n"
                     << "Team1: " << Team1Score << " - " << Team2Wicket << "(" << i << ")\n"
                     << "---------------------------------------\n\n";
            }
        }
        cout << "\t\t!!! INNING ENDED !!!\n\n";
        batter = 0;
    }
};

//Errors are handled
class WinningDecider
{
public:
    WinningDecider() //winning message
    {
        if (Team1Score > Team2Score)
        {
            cout << "---------------------------------------\n\n"
                 << "\n      ***///---TEAM1 WON---///***\n\n\n"
                 << "---------------------------------------\n\n";
        }
        else if (Team2Score > Team1Score)
        {
            cout << "---------------------------------------\n\n"
                 << "\n      ***///---TEAM2 WON---///***\n\n\n"
                 << "---------------------------------------\n\n";
        }
        else
        {
            cout << "---------------------------------------\n\n"
                 << "\n    ***///---IT'S A DRAW---///***\n\n\n"
                 << "---------------------------------------\n\n";
        }
    }
    void finalScoreTable() //final score table
    {
        cout << "\t\t\tMATCH ENDS\n\n";
        cout << "Team1 " << Team1Score << " - " << Team1Wicket << " (6)\n"
             << "=======================================\n"
             << "PLAYER'S BATTING STATISTIC\n";
        for (int i = 0; i < 4; i++)
        {
            cout << "---------------------------------------\n"
                 << "[" << i + 1 << "] " << Team1[i] << " --> " << Team1IndividualScore[i] << "("
                 << Team1IndividualBallPlayed[i] << ")\n";
        }
        cout << "=======================================\n\n";

        cout << "Team2 " << Team2Score << " - " << Team2Wicket << " (6)\n"
             << "=======================================\n"
             << "PLAYER'S BATTING STATISTIC\n";
        for (int i = 0; i < 4; i++)
        {
            cout << "---------------------------------------\n"
                 << "[" << i + 1 << "] " << Team2[i] << " --> " << Team2IndividualScore[i] << "("
                 << Team2IndividualBallPlayed[i] << ")\n";
        }
        cout << "=======================================\n\n";
    }
};

int main()
{
    Welcome Wel;

    TeamSelect Tem;
    Tem.CreateTeam();
    Tem.teamDisplay();

    Toss to;

    Inning inni;
    inni.bowling();

    WinningDecider winn;
    winn.finalScoreTable();

    return 0;
}