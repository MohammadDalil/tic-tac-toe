#include<iostream>
#include<iomanip>
#include <chrono>
using namespace std;

void drawBoard(char board[][3]);
char checkWinner3by3(char board[][3]);
void play_cpu();
char print[][3] = { {' ',' ',' '},
                        {' ',' ',' '},
                        {' ',' ',' '} };
const string red("\033[0;31m");
const string cyan("\033[0;36m");
const string reset("\033[0m");

const unsigned int EMPTY_SUM = 216; 
const unsigned int X_SUM = 272 + 434 + 275; 
const unsigned int O_SUM = 263 + 439 + 275; 

const string X_PLAYER = red + "X" + reset;
const string O_PLAYER = cyan + "O" + reset;


int main()
{
    char board[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };
    char player = 'X';
    char winner = ' ';
    int row;
    int column;
    bool is_move;
    bool is_row;
    bool is_column;

    cout << "************ TIC TAC TOE ************\n";
    auto start = chrono::steady_clock::now();
    while (winner == ' ')
    {
        is_move = false;
        is_row = false;
        is_column = false;
        drawBoard(board);
        cout << "Player ";
        if (player == 'X')
        {
            cout << 1;
        }
        else
        {
            cout << 2;
        }
        cout << "'s turn:" << endl;
        is_move = false;
        while (!is_move)
        {
            is_row = false;
            while (!is_row)
            {
                cout << "Row: ";
                cin >> row;
                if (row == 1 || row == 2 || row == 3)
                {
                    is_row = true;
                }
                else
                {
                    cout << endl << "Invalid row!" << endl;
                }
            }

            is_column = false;
            while (!is_column)
            {
                cout << "Column: ";
                cin >> column;
                if (column == 1 || column == 2 || column == 3)
                {
                    is_column = true;
                }
                else
                {
                    cout << endl << "Invalid column!" << endl;
                }
            }

            if (board[row - 1][column - 1] == ' ')
            {
                board[row - 1][column - 1] = player;
                is_move = true;
                if (player == 'X')
                {
                    player = 'O';
                }
                else
                {
                    player = 'X';
                }
            }
            else
            {
                cout << "The selected space is occupied!" << endl;
                cout << "Select a different space:" << endl << endl;
                drawBoard(board);
            }
        }

        cout << endl;

       
        winner = checkWinner3by3(board);

        
        if (winner == 'X' || winner == 'O')
        {
            drawBoard(board);

            cout << "Congratulations! Player ";
            if (winner == 'X')
            {
                cout << 1 << "is winner !" << endl;
                auto end = chrono::steady_clock::now();
                cout << "The elapsed time in seconds is equal to: "
                    << chrono::duration_cast<chrono::seconds>(end - start).count()
                    << " sec";
            }
            else
            {
                cout << 2 << "is winner !" << endl;
                auto end = chrono::steady_clock::now();
                cout << "The elapsed time in seconds is equal to: "
                    << chrono::duration_cast<chrono::seconds>(end - start).count()
                    << " sec";

            }

        }
        else if (winner == 'T')
        {
            drawBoard(board);

            cout << "Well Done!" << endl;
        }

    }

    system("pause");
    return 0;
}



void drawBoard(char board[][3])
{
    
    cout << "     1   2   3" << endl;
    cout << "   +---+---+---+" << endl;

    cout << " 1" << " | " << print[0][0] << " | " << print[0][1] << " | " << print[0][2] << " | " << endl;
    cout << "   +---+---+---+" << endl;

    cout << " 2" << " | " << print[1][0] << " | " << print[1][1] << " | " << print[1][2] << " | " << endl;
    cout << "   +---+---+---+" << endl;

    cout << " 3" << " | " << print[2][0] << " | " << print[2][1] << " | " << print[2][2] << " | " << endl;
    cout << "   +---+---+---+" << endl;

}

void play_cpu()
{
    srand(time(0));
    int row, col;
    int r = rand();
    int c = rand() + rand();
    while (true)
    {
        row = (r % 3);
        c = (c % 4);
        if (print[row][col] == '_')
        {
            print[row][col] = 'X';
            break;
        }
        if (0 <= row && row <= 2) r++;
        if (0 <= col && col <= 2) c++;
    }
}

char checkWinner3by3(char board[][3])
{


    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return board[0][2];
    }

    return ' ';
}