#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

enum enChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player = 1, Computer = 2, Draw = 3 };

int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;

    return RandNum;
}

short ReadNumberOfRounds()
{
    short Rounds = 0;

    cout << "How Many Rounds? 1 to 10?\n";
    cin >> Rounds;

    return Rounds;
}

short EnterPlayerChoice()
{
    short Choice;
    
    do
    {
        cout << "Your Choice : [1]:Stone, [2]:Paper, [3]:Scissors ? ";
        cin>>Choice;

    } while (!(Choice >= 1 && Choice <= 3));

    return Choice;
}

enChoice PlayerChoice()
{
    switch (EnterPlayerChoice())
    {
    case 1:
        return enChoice::Stone;
    case 2:
        return enChoice::Paper;
    case 3:
        return enChoice::Scissors;
    }

}

short GetComputerChoice()
{
    return RandomNumber(1, 3);
}

enChoice ComputerChoice()
{
    switch (GetComputerChoice())
    {
    case 1:
        return enChoice::Stone;
    case 2:
        return enChoice::Paper;
    case 3:
        return enChoice::Scissors;
    }
}

enWinner WhoWin(enChoice Player, enChoice Computer)
{
    if (Player == Computer)
        return enWinner::Draw;
    else if (Player == enChoice::Stone && Computer == enChoice::Paper)
        return enWinner::Computer;
    else if (Player == enChoice::Stone && Computer == enChoice::Scissors)
        return enWinner::Player;
    else if (Player == enChoice::Paper && Computer == enChoice::Stone)
        return enWinner::Player;
    else if (Player == enChoice::Paper && Computer == enChoice::Scissors)
        return enWinner::Computer;
    else if (Player == enChoice::Scissors && Computer == enChoice::Stone)
        return enWinner::Computer;
    else
        return enWinner::Player;
    
}

void PrintRoundResult(enWinner Winner, enChoice Player, enChoice Computer)
{
    cout << "Player Choice : " << Player << endl;
    cout << "Computer Choice : " << Computer << endl;
    cout << "Round Winner : " << Winner;
}

void BeginRound()
{
    short Rounds = ReadNumberOfRounds();

    for (int i = 1;i <= Rounds;i++)
    {
        cout << "\nRound [" << i << "] begins :\n\n";

        enChoice Player = PlayerChoice();
        enChoice Computer = ComputerChoice();

        enWinner Winner = WhoWin(Player, Computer);

        cout << "\n_______________Round [" << i << "]_______________\n\n";
        PrintRoundResult(Winner, Player, Computer);
        cout << "\n_______________________________________\n";
    }

}

int main()
{
    srand((unsigned)time(NULL));

    BeginRound();

    return 0;

}