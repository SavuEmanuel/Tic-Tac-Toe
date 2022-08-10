#include <iostream>
#include <cstring>

using namespace std;
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char team;
bool teamturn;
void buildboard()
{
    cout << ' ' << board[0][0] << '|' << board[0][1] << '|' << board[0][2] << '\n';
    cout << "-------\n";
    cout << ' ' << board[1][0] << '|' << board[1][1] << '|' << board[1][2] << '\n';
    cout << "-------\n";
    cout << ' ' << board[2][0] << '|' << board[2][1] << '|' << board[2][2] << '\n';
}
void teamchoice()
{
    cout << " **** WELLCOME **** " << '\n';
    cout << "RULES :" << '\n';
    cout << "-TO GET YOUR X AND O IN THE SQUARE THAT YOU WANT PRESS ON THE NUMPAD THE NUMBER THAT" << '\n';
    cout << " IS EQUIVALENT TO YOUR DESIRED SQUARE " << '\n';
    cout << "CHOOSE YOUR TEAM : " << '\n';
    cout << "Team X" << ' ' << "OR" << ' '
         << "Team O" << '\n';
    cin >> team;
    if (strchr("X", team))
    {
        cout << "YOU ARE TEAM X AND YOU START" << '\n';
        teamturn = 1;
    }
    else
    {
        cout << "YOU ARE TEAM O AND YOU START" << '\n';
        teamturn = 0;
    }
}
bool checkboardX()
{
    int k = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == 'X')
                k++;
        if (k == 3)
            return 1;
        k = 0;
    }
    k = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            if (board[j][i] == 'X')
                k++;
        if (k == 3)
            return 1;
        k = 0;
    }
    k = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][i] != 'X')
            return 0;
    }
    k = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            if (i + j - 1 == 3 && board[i][j] == 'X')
                k++;
        if (k == 3)
            return 1;
        k = 0;
    }
    return 0;
}
bool checkboardO()
{
    int k = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == 'O')
                k++;
        if (k == 3)
            return 1;
        k = 0;
    }
    k = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            if (board[j][i] == 'O')
                k++;
        if (k == 3)
            return 1;
        k = 0;
    }
    k = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][i] != 'O')
            return 0;
    }
    k = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            if (i + j - 1 == 3 && board[i][j] == 'O')
                k++;
        if (k == 3)
            return 1;
        k = 0;
    }
    return 0;
}
int main()
{
    teamchoice();
    int x;
    int cnt = 0, p = 0, read = 0;
    bool var = 1;
    while (read != 8)
    {
        if (var == 1)
            buildboard();
        var = 1;
        cin >> x;
        if (teamturn == 1)
        {
            if (x >= 1 && x <= 3)
            {
                if (board[2][x - 1] != ' ')
                {
                    cout << "YOU CAN'T PLACE IT HERE" << '\n';
                    var = 0;
                }
                else
                    board[2][x - 1] = 'X';
            }
            else if (x >= 4 && x <= 6)
            {
                if (board[1][x - 4] != ' ')
                {
                    cout << "YOU CAN'T PLACE IT HERE" << '\n';
                    var = 0;
                }
                else
                    board[1][x - 4] = 'X';
            }
            else if (x >= 7 && x <= 9)
            {
                if (board[0][x - 7] != ' ')
                {
                    cout << "YOU CAN'T PLACE IT HERE" << '\n';
                    var = 0;
                }
                else
                    board[0][x - 7] = 'X';
            }
            if (checkboardX() == 1)
            {
                cout << '\n'
                     << "Team X has won the game !!!" << '\n'
                     << "CONGRATS !!!" << '\n';
                buildboard();
                p = 1;
                break;
            }
            if (var == 1)
                teamturn = 0;
        }
        else
        {
            if (x >= 1 && x <= 3)
            {
                if (board[2][x - 1] != ' ')
                {
                    cout << "YOU CAN'T PLACE IT HERE" << '\n';
                    var = 0;
                }
                else
                    board[2][x - 1] = 'O';
            }
            else if (x >= 4 && x <= 6)
            {
                if (board[1][x - 4] != ' ')
                {
                    cout << "YOU CAN'T PLACE IT HERE" << '\n';
                    var = 0;
                }
                else
                    board[1][x - 4] = 'O';
            }
            else if (x >= 7 && x <= 9)
            {
                if (board[0][x - 7] != ' ')
                {
                    cout << "YOU CAN'T PLACE IT HERE" << '\n';
                    var = 0;
                }
                else
                    board[0][x - 7] = 'O';
            }
            if (checkboardO() == 1)
            {
                cout << '\n'
                     << "Team O has won the game !!!" << '\n'
                     << "CONGRATS !!!" << '\n';
                buildboard();
                p = 1;
                break;
            }
            if (var == 1)
                teamturn = 1;
        }
        if (var == 1)
            read++;
    }
    if (p == 0)
    {
        cout << '\n'
             << "IT'S A TIE" << '\n';
        buildboard();
    }
    return 0;
}