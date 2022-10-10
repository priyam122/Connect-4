#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <limits>

using namespace std;

void welcome (char& level) { // Welcome Message and Main Menu...

    cout << "\n-----------------------------------------------------------";
    cout << "\n|| Welcome to the Connect 4 Game || MADE BY PRIYAM PATEL ||";
    cout << "\n-----------------------------------------------------------";
    cout << "\n||\t   Chose whom you'd like to play against:        ||\n";
    cout << "||                                                       ||";
    cout << "\n||\t      Type 'P' to play Player                    ||";
    cout << "\n||\t      Type 'C' to play the Computer              ||\n";
    cout << "||                                                       ||";
    cout << "\n||\t      Or                                         ||\n";
    cout << "||                                                       ||";
    cout << "\n||\t      Type 'I' for Instructions                  ||\n";
    cout << "||                                                       ||";
    cout << "\n-----------------------------------------------------------";
    cout << "\n\t      --> Please enter your choice:";

    cin >> level;
}

void display (vector <vector <char>>& board) { // Displays the game board
    for(int h = 0; h < 10; ++h) { // horizontal print
        for(int v = 0; v < 9; ++v) { //vertical print
            cout << board[h][v] << " ";
        }
        cout << "\n";
    }
}

void comp_choice (vector <vector <char>>& board, int comp_input, int& row) { // Puts random computer choice into the board and calls display()

    board[row][comp_input] = 'Y'; // puts Y into the row and comp_input variable that comes into function
    row = row - 1; // subtract the row by 1, so that we can track if column is full or not
    display(board); // shows the updated board
}

// checks if the random seed's value is valid or not
// if not then repeats and tries again
// if random is valid then proceeds and calls the comp_choice function so that board can be edited
void comp_fun_call (int& comp_entry, int& row_1, int& row_2, int& row_3, int& row_4, int& row_5, int& row_6, int& row_7, vector <vector <char>>& board){

    int test = 0;

    while (test == 0){

        if (comp_entry == 1){ // if the column is one from random

            if (row_1 <= 2) { // if the row is full we take random again and go back of loop
                srand (time(nullptr));
                comp_entry = rand() % 7+1;
                continue;
            } else { // if row is not full it calls function which prints onto the board
                comp_choice(board, comp_entry, row_1);
                test = 1; // set flag as 1 to exit the loop
            }
// this repeated for all seven rows
        } else if (comp_entry == 2) {
            if (row_2 <= 2) {
                srand (time(nullptr));
                comp_entry = rand() % 7+1;
                continue;
            } else {
                comp_choice(board, comp_entry, row_2);
                test = 1; // set flag as 1 to exit the loop

            }
        } else if (comp_entry == 3) {
            if (row_3 <= 2) {
                srand (time(nullptr));
                comp_entry = rand() % 7+1;
                continue;
            } else {
                comp_choice(board, comp_entry, row_3);
                test = 1;

            }
        } else if (comp_entry == 4) {
            if (row_4 <= 2) {
                srand (time(nullptr));
                comp_entry = rand() % 7+1;
                continue;
            } else {
                comp_choice(board, comp_entry, row_4);
                test = 1;

            }
        } else if (comp_entry == 5) {
            if (row_5 <= 2) {
                srand (time(nullptr));
                comp_entry = rand() % 7+1;
                continue;
            } else {
                comp_choice(board, comp_entry, row_5);
                test = 1;
            }
        } else if (comp_entry == 6) {
            if (row_6 <= 2) {
                srand (time(nullptr));
                comp_entry = rand() % 7+1;
                continue;
            } else {
                comp_choice(board, comp_entry, row_6);
                test = 1;
            }
        } else if (comp_entry == 7) {
            if (row_7 <= 2) {
                srand (time(nullptr));
                comp_entry = rand() % 7+1;
                continue;
            } else {
                comp_choice(board, comp_entry, row_7);
                test = 1;
            }
        }
    }
}

// these are all the checks needed to tell the program if/when a user wins
void userwin_check1 (const vector <vector <char>>& board, int& win, int& user_check1){ // checks for player 1 wins in game

    ///HORIZONTAL CHECK IF USER WON --->
    for (int i = 8;i > 2;--i) {
        if ((board[i][1] == 'R' && board[i][2] == 'R' && board[i][3] == 'R' && board[i][4] == 'R') || (board[i][2] == 'R' && board[i][3] == 'R' && board[i][4] == 'R' && board[i][5] == 'R') || (board[i][3] == 'R' && board[i][4] == 'R' && board[i][5] == 'R' && board[i][6] == 'R') || (board[i][4] == 'R' && board[i][5] == 'R' && board[i][6] == 'R' && board[i][7] == 'R')){
            win = 1; // win = 1 means player 1 has won
            user_check1 = 0;// setting user_check = 0 so that we know player 1 is the winner
            break;
        }
        ///VERTICAL USER CHECK --->
        if ((board[i][1] == 'R' && board[i-1][1] == 'R' && board[i-2][1] == 'R' && board[i-3][1] == 'R') || (board[i][2] == 'R' && board[i-1][2] == 'R' && board[i-2][2] == 'R' && board[i-3][2] == 'R') || (board[i][3] == 'R' && board[i-1][3] == 'R' && board[i-2][3] == 'R' && board[i-3][3] == 'R') || (board[i][4] == 'R' && board[i-1][4] == 'R' && board[i-2][4] == 'R' && board[i-3][4] == 'R') || (board[i][5] == 'R' && board[i-1][5] == 'R' && board[i-2][5] == 'R' && board[i-3][5] == 'R') || (board[i][6] == 'R' && board[i-1][6] == 'R' && board[i-2][6] == 'R' && board[i-3][6] == 'R') || (board[i][7] == 'R' && board[i-1][7] == 'R' && board[i-2][7] == 'R' && board[i-3][7] == 'R')) {
            win = 1;
            user_check1 = 0;
            break;
        }
        ///DIAGONAL RIGHT USER CHECK --->
        if ((board[i][1] == 'R' && board[i-1][2] == 'R' && board[i-2][3] == 'R' && board[i-3][4] == 'R') || (board[i][2] == 'R' && board[i-1][3] == 'R' && board[i-2][4] == 'R' && board[i-3][5] == 'R') || (board[i][3] == 'R' && board[i-1][4] == 'R' && board[i-2][5] == 'R' && board[i-3][6] == 'R') || (board[i][4] == 'R' && board[i-1][5] == 'R' && board[i-2][6] == 'R' && board[i-3][7] == 'R')){
            win = 1;
            user_check1 = 0;
            break;
        }
    }
    ///DIAGONAL LEFT USER CHECK --->
    for (int i = 3;i < 9;++i) {
        if ((board[i][1] == 'R' && board[i+1][2] == 'R' && board[i+2][3] == 'R' && board[i+3][4] == 'R') || (board[i][2] == 'R' && board[i+1][3] == 'R' && board[i+2][4] == 'R' && board[i+3][5] == 'R') || (board[i][3] == 'R' && board[i+1][4] == 'R' && board[i+2][5] == 'R' && board[i+3][6] == 'R') || (board[i][4] == 'R' && board[i+1][5] == 'R' && board[i+2][6] == 'R' && board[i+3][7] == 'R')){
            win = 1;
            user_check1 = 0;
            break;
        }
    }
}

// these are all the checks needed to tell the program if/when player 2 wins
void userwin_check2 (const vector <vector <char>>& board, int& win, int& user_check2){ // checks for player 2 wins in game

    ///HORIZONTAL CHECK IF USER WON --->
    for (int i = 8;i > 2;--i) {
        if ((board[i][1] == 'Y' && board[i][2] == 'Y' && board[i][3] == 'Y' && board[i][4] == 'Y') || (board[i][2] == 'Y' && board[i][3] == 'Y' && board[i][4] == 'Y' && board[i][5] == 'Y') || (board[i][3] == 'Y' && board[i][4] == 'Y' && board[i][5] == 'Y' && board[i][6] == 'Y') || (board[i][4] == 'Y' && board[i][5] == 'Y' && board[i][6] == 'Y' && board[i][7] == 'Y')){
            win = 2; // win = 2 means player 2 has won
            user_check2 = 0; // setting user_check = 0 so that we know player 2 is the winner
            break;
        }
        ///VERTICAL USER CHECK --->
        if ((board[i][1] == 'R' && board[i-1][1] == 'Y' && board[i-2][1] == 'Y' && board[i-3][1] == 'Y') || (board[i][2] == 'Y' && board[i-1][2] == 'Y' && board[i-2][2] == 'Y' && board[i-3][2] == 'Y') || (board[i][3] == 'Y' && board[i-1][3] == 'Y' && board[i-2][3] == 'Y' && board[i-3][3] == 'Y') || (board[i][4] == 'Y' && board[i-1][4] == 'Y' && board[i-2][4] == 'Y' && board[i-3][4] == 'Y') || (board[i][5] == 'Y' && board[i-1][5] == 'Y' && board[i-2][5] == 'Y' && board[i-3][5] == 'Y') || (board[i][6] == 'Y' && board[i-1][6] == 'Y' && board[i-2][6] == 'Y' && board[i-3][6] == 'Y') || (board[i][7] == 'Y' && board[i-1][7] == 'Y' && board[i-2][7] == 'Y' && board[i-3][7] == 'Y')) {
            win = 2;
            user_check2 = 0;
            break;
        }
        ///DIAGONAL RIGHT USER CHECK --->
        if ((board[i][1] == 'Y' && board[i-1][2] == 'Y' && board[i-2][3] == 'Y' && board[i-3][4] == 'Y') || (board[i][2] == 'Y' && board[i-1][3] == 'Y' && board[i-2][4] == 'Y' && board[i-3][5] == 'Y') || (board[i][3] == 'Y' && board[i-1][4] == 'Y' && board[i-2][5] == 'Y' && board[i-3][6] == 'Y') || (board[i][4] == 'Y' && board[i-1][5] == 'Y' && board[i-2][6] == 'Y' && board[i-3][7] == 'Y')){
            win = 2;
            user_check2 = 0;
            break;
        }
    }
    ///DIAGONAL LEFT USER CHECK --->
    for (int i = 3;i < 9;++i) {
        if ((board[i][1] == 'Y' && board[i+1][2] == 'Y' && board[i+2][3] == 'Y' && board[i+3][4] == 'Y') || (board[i][2] == 'Y' && board[i+1][3] == 'Y' && board[i+2][4] == 'Y' && board[i+3][5] == 'Y') || (board[i][3] == 'Y' && board[i+1][4] == 'Y' && board[i+2][5] == 'Y' && board[i+3][6] == 'Y') || (board[i][4] == 'Y' && board[i+1][5] == 'Y' && board[i+2][6] == 'Y' && board[i+3][7] == 'Y')){
            win = 2;
            user_check2 = 0;
            break;
        }
    }
}

// these are checks to see if the computer wins or not
void compwin_check (const vector <vector <char>>& board, int& win, int& user_check1) { // checks if the computer won the game

    ///HORIZONTAL CHECK IF COMPUTER WON --->
    for (int i = 8;i > 2;--i) {
        if ((board[i][1] == 'Y' && board[i][2] == 'Y' && board[i][3] == 'Y' && board[i][4] == 'Y') || (board[i][2] == 'C' && board[i][3] == 'Y' && board[i][4] == 'Y' && board[i][5] == 'Y') || (board[i][3] == 'Y' && board[i][4] == 'Y' && board[i][5] == 'Y' && board[i][6] == 'Y') || (board[i][4] == 'Y' && board[i][5] == 'Y' && board[i][6] == 'Y' && board[i][7] == 'Y')){
            win = 3; // win = 3 means the computer won
            user_check1 = 0; //set user_check = 0 so that we know the computer won
            break;
        }
        ///VERTICAL COMPUTER CHECK --->
        if ((board[i][1] == 'Y' && board[i-1][1] == 'Y' && board[i-2][1] == 'Y' && board[i-3][1] == 'Y') || (board[i][2] == 'Y' && board[i-1][2] == 'Y' && board[i-2][2] == 'Y' && board[i-3][2] == 'Y') || (board[i][3] == 'Y' && board[i-1][3] == 'Y' && board[i-2][3] == 'Y' && board[i-3][3] == 'Y') || (board[i][4] == 'Y' && board[i-1][4] == 'Y' && board[i-2][4] == 'Y' && board[i-3][4] == 'Y') || (board[i][5] == 'Y' && board[i-1][5] == 'Y' && board[i-2][5] == 'Y' && board[i-3][5] == 'Y') || (board[i][6] == 'Y' && board[i-1][6] == 'Y' && board[i-2][6] == 'Y' && board[i-3][6] == 'Y') || (board[i][7] == 'Y' && board[i-1][7] == 'Y' && board[i-2][7] == 'Y' && board[i-3][7] == 'Y')) {
            win = 3;
            user_check1 = 0;
            break;
        }
        ///DIAGONAL RIGHT COMPUTER CHECK --->
        if ((board[i][1] == 'Y' && board[i-1][2] == 'Y' && board[i-2][3] == 'Y' && board[i-3][4] == 'Y') || (board[i][2] == 'Y' && board[i-1][3] == 'Y' && board[i-2][4] == 'Y' && board[i-3][5] == 'Y') || (board[i][3] == 'Y' && board[i-1][4] == 'Y' && board[i-2][5] == 'Y' && board[i-3][6] == 'Y') || (board[i][4] == 'Y' && board[i-1][5] == 'Y' && board[i-2][6] == 'Y' && board[i-3][7] == 'Y')){
            win = 3;
            user_check1 = 0;
            break;
        }
    }
    ///DIAGONAL LEFT COMPUTER CHECK --->
    for (int i = 3;i < 9;++i) {
        if ((board[i][1] == 'Y' && board[i+1][2] == 'Y' && board[i+2][3] == 'Y' && board[i+3][4] == 'Y') || (board[i][2] == 'Y' && board[i+1][3] == 'Y' && board[i+2][4] == 'Y' && board[i+3][5] == 'Y') || (board[i][3] == 'Y' && board[i+1][4] == 'Y' && board[i+2][5] == 'Y' && board[i+3][6] == 'Y') || (board[i][4] == 'Y' && board[i+1][5] == 'Y' && board[i+2][6] == 'Y' && board[i+3][7] == 'Y')){
            win = 3;
            user_check1 = 0;
            break;
        }
    }
}

// ends the program if either player 1 or 2 win
void end_game (int& flag, int& user_entry1, int& user_entry2, int& comp_entry, int& row_1, int& row_2, int& row_3, int& row_4, int& row_5, int& row_6, int& row_7, int& counter) {
    cout << "|| Thank you for playing Connect4. Have a good day! ||\n";
    exit(0);
}

// if user chooses to play again we clear variable values and if not then we close program
void play_again (int& flag, int& user_entry1, int& user_entry2, int& comp_entry, int& row_1, int& row_2, int& row_3, int& row_4, int& row_5, int& row_6, int& row_7, int& counter) {
    char play_again = ' ';
    cout << "Are you ready to play now? (Type Y for yes and any other character for no): \n";
    cin >> play_again;
    if (play_again =='Y' || play_again == 'y'){
        flag = 1;
        comp_entry = 0;
        user_entry1 = 0;
        user_entry2 = 0;
        row_1 = 8;
        row_2 = 8;
        row_3 = 8;
        row_4 = 8;
        row_5 = 8;
        row_6 = 8;
        row_7 = 8;
        counter = 0;
    } else {
        cout << "|| No problem, come back soon. Have a good day! ||\n";
        exit(0);
    }
}

// this is for when the player is ready to play or not after choosing the option to get help on how to play
void ready_to_play (int& flag, int& user_entry1, int& user_entry2, int& comp_entry, int& row_1, int& row_2, int& row_3, int& row_4, int& row_5, int& row_6, int& row_7, int& counter) {
    char ready_to_play = ' ';
    cout << "Are you ready to play now? (Type Y for yes and any other character for no): \n";
    cin >> ready_to_play;
    if (ready_to_play =='Y' || ready_to_play == 'y'){
        flag = 1;
        comp_entry = 0;
        user_entry1 = 0;
        user_entry2 = 0;
        row_1 = 8;
        row_2 = 8;
        row_3 = 8;
        row_4 = 8;
        row_5 = 8;
        row_6 = 8;
        row_7 = 8;
        counter = 0;
    } else {
        cout << "|| No problem, come back soon. Have a good day! ||\n";
        exit(0);
    }
}

///depending on the value of the win variable, we give appropriate message and call back appropriate function to give to the user...
void win_message (int win, int& flag, int& user_entry1, int& user_entry2, int& comp_entry, int& row_1, int& row_2, int& row_3, int& row_4, int& row_5, int& row_6, int& row_7, int& counter){

    if (win == 1) { // if win = 1 user won
        cout <<  "Congrats!! Player 1 Won!\n\n";
        end_game(flag, user_entry1, user_entry2, comp_entry, row_1, row_2, row_3, row_4, row_5, row_6, row_7, counter);		//play again
    }
    else if (win == 2) { // if win = 2 user won
        cout << "Congrats!! Player 2 Won!\n\n";
        end_game(flag, user_entry1, user_entry2, comp_entry, row_1, row_2, row_3, row_4, row_5, row_6, row_7, counter);
    }
    else if (win == 3) { // if win = 1 user won
        cout << "Good Try!! Computer Won!\n\n";
        play_again(flag, user_entry1, user_entry2, comp_entry, row_1, row_2, row_3, row_4, row_5, row_6, row_7, counter);		//play again
    }
    else if (win == 4) { // if win = 1 user won
        cout << "So close!! Its a draw!\n\n";
        play_again(flag, user_entry1, user_entry2, comp_entry, row_1, row_2, row_3, row_4, row_5, row_6, row_7, counter);		//play again
    }
}

int main () { // Main program

    char level; // keeps track of which option is chosen from the main menu
    int row_1 = 8, row_2 = 8, row_3 = 8, row_4 = 8, row_5 = 8, row_6 = 8, row_7 = 8; // Variables to keep track of current row number
    int user_entry1 = 0, user_entry2 = 0, comp_entry = 0; // these are the variables that keep track of which column player 1/player 2/computer chooses
    int flag = 1; //  flag used for loop purposes
    int counter = 0; // counter is to find out when board is full and no one won, so it'll be a draw
    while (flag == 1) {
        welcome(level); //calling back welcome function
        // makes the empty game board ready to play
        vector<vector<char>> board = {

                {'+', '-', '-', '-', '-', '-', '-', '-', '+'},
                {'|', '1', '2', '3', '4', '5', '6', '7', '|'},
                {'|', '=', '=', '=', '=', '=', '=', '=', '|'},
                {'|', '0', '0', '0', '0', '0', '0', '0', '|'},
                {'|', '0', '0', '0', '0', '0', '0', '0', '|'},
                {'|', '0', '0', '0', '0', '0', '0', '0', '|'},
                {'|', '0', '0', '0', '0', '0', '0', '0', '|'},
                {'|', '0', '0', '0', '0', '0', '0', '0', '|'},
                {'|', '0', '0', '0', '0', '0', '0', '0', '|'},
                {'+', '-', '-', '-', '-', '-', '-', '-', '+'},
        };

        if (level == 'P' || level == 'p') { // Playing against Human
            flag = 0; // make flag = 0, so we don't loop and make the board again, only happens when we start...
            display(board); // shows board
            int win = 0; // to check if it is a win or loss or tie
            while (win == 0) { // when no one has won yet win = 0
                cout << endl;
                int user_check1 = 1; // variable that checks if player 1 column choice is valid
                while (user_check1 == 1) { // checks if player 1 has entered a valid column selection
                    cout << "\nPLayer 1 enter the column number you would like to fill: "; // asks player 1 to fill
                    cin >> user_entry1;
                    if (!cin, user_entry1 <= 0 || user_entry1 >= 8) { // if out of bounds gives error
                        cout << "\nInvalid Column! Please try again.";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // makes sure that only integers are entered
                        user_check1 = 1; // makes user_check1 = 1 and loops again asking for a valid column number
                    } else if (user_entry1 == 1) { // so if column 1 is chosen
                        if (row_1 <= 2) { // if that is full give error message is given
                            cout << "|| Column " << user_entry1 << " is full. Please try a different column!||\n";
                            user_check1 = 1; // set user_check1 = 1 so we loop again
                            continue;
                        } else { // if all is good then put what user entered into board
                            board[row_1][user_entry1] = 'R';
                            counter++; // increase counter
                            row_1 = row_1 - 1; // minus one for row, so we know when the column is full
                            user_check1 = 0; // setting it to 0 so it doesn't loop again
                            break;
                        }
                        // this process is repeated for all seven columns
                    } else if (user_entry1 == 2) {
                        if (row_2 <= 2) {
                            cout << "|| Column " << user_entry1 << " is full. Please try a different column!||\n";
                            user_check1 = 1;
                            continue;
                        } else {
                            board[row_2][user_entry1] = 'R';
                            counter++;
                            row_2 = row_2 - 1;
                            user_check1 = 0;
                            break;
                        }
                    } else if (user_entry1 == 3) {
                        if (row_3 <= 2) {
                            cout << "|| Column " << user_entry1 << " is full. Please try a different column!||\n";
                            user_check1 = 1;
                            continue;
                        } else {
                            board[row_3][user_entry1] = 'R';
                            counter++;
                            row_3 = row_3 - 1;
                            user_check1 = 0;
                            break;
                        }
                    } else if (user_entry1 == 4) {
                        if (row_4 <= 2) {
                            cout << "|| Column " << user_entry1 << " is full. Please try a different column!||\n";
                            user_check1 = 1;
                            continue;
                        } else {
                            board[row_4][user_entry1] = 'R';
                            counter++;
                            row_4 = row_4 - 1;
                            user_check1 = 0;
                            break;
                        }
                    } else if (user_entry1 == 5) {
                        if (row_5 <= 2) {
                            cout << "|| Column " << user_entry1 << " is full. Please try a different column!||\n";
                            user_check1 = 1;
                            continue;
                        } else {
                            board[row_5][user_entry1] = 'R';
                            counter++;
                            row_5 = row_5 - 1;
                            user_check1 = 0;
                            break;
                        }
                    } else if (user_entry1 == 6) {
                        if (row_6 <= 2) {
                            cout << "|| Column " << user_entry1 << " is full. Please try a different column!||\n";
                            user_check1 = 1;
                            continue;
                        } else {
                            board[row_6][user_entry1] = 'R';
                            counter++;
                            row_6 = row_6 - 1;
                            user_check1 = 0;
                            break;
                        }
                    } else if (user_entry1 == 7) {
                        if (row_7 <= 2) {
                            cout << "|| Column " << user_entry1 << " is full. Please try a different column!||\n";
                            user_check1 = 1;
                            continue;
                        } else {
                            board[row_7][user_entry1] = 'R';
                            counter++;
                            row_7 = row_7 - 1;
                            user_check1 = 0;
                            break;
                        }
                    }

                }
                display(board); // displays updated game board
                userwin_check1(board, win, user_check1);// call function that checks if player 1 has won the game...
                if (counter == 42) { // if counter is 42 and no one has won then board is full
                    win = 4; // set win to 4 which will draw the game
                    user_check1 = 0;// sets player 1 check to 0
                }
                win_message(win, flag, user_entry1, user_entry2, comp_entry, row_1, row_2, row_3, row_4, row_5, row_6,row_7, counter); // gives win message if it is needed... depending on if its win lose or draw

                int user_check2 = 1; // variable that checks if player 2 column choice is valid
                while (user_check2 == 1) { // check if player 2 has entered a valid column selection
                    cout << "\nPLayer 2 enter the column number you would like to fill: "; // asks player 2 to fill
                    cin >> user_entry2;
                    if (!cin, user_entry2 <= 0 || user_entry2 >= 8) { // if out of bounds gives error
                        cout << "\nInvalid Column! Please try again.";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // makes sure that only integers are entered
                        user_check2 = 1; // make user_check2 = 1 and loops again asking for valid column
                    } else if (user_entry2 == 1) { // so if column 1 is chosen

                        if (row_1 <= 2) { // if that is full gives error message
                            cout << "|| Column " << user_entry2 << " is full. Please try a different column!||\n";
                            user_check2 = 1; // set user_check2 = 1 so we loop again
                            continue;
                        } else { // if all is good then put what user entered into board
                            board[row_1][user_entry2] = 'Y';
                            counter++; // increase counter
                            row_1 = row_1 - 1; // minus one for row, so we know when the column is full
                            user_check2 = 0; // setting it to 0 so it doesn't loop again
                            break;
                        }
                        // this process is repeated for all seven columns
                    } else if (user_entry2 == 2) {
                        if (row_2 <= 2) {
                            cout << "|| Column " << user_entry2 << " is full. Please try a different column!||\n";
                            user_check2 = 1;
                            continue;
                        } else {
                            board[row_2][user_entry2] = 'Y';
                            counter++;
                            row_2 = row_2 - 1;
                            user_check2 = 0;
                            break;
                        }
                    } else if (user_entry2 == 3) {
                        if (row_3 <= 2) {
                            cout << "|| Column " << user_entry2 << " is full. Please try a different column!||\n";
                            user_check2 = 1;
                            continue;
                        } else {
                            board[row_3][user_entry2] = 'Y';
                            counter++;
                            row_3 = row_3 - 1;
                            user_check2 = 0;
                            break;
                        }
                    } else if (user_entry2 == 4) {
                        if (row_4 <= 2) {
                            cout << "|| Column " << user_entry2 << " is full. Please try a different column!||\n";
                            user_check2 = 1;
                            continue;
                        } else {
                            board[row_4][user_entry2] = 'Y';
                            counter++;
                            row_4 = row_4 - 1;
                            user_check2 = 0;
                            break;
                        }
                    } else if (user_entry2 == 5) {
                        if (row_5 <= 2) {
                            cout << "|| Column " << user_entry2 << " is full. Please try a different column!||\n";
                            user_check2 = 1;
                            continue;
                        } else {
                            board[row_5][user_entry2] = 'Y';
                            counter++;
                            row_5 = row_5 - 1;
                            user_check2 = 0;
                            break;
                        }
                    } else if (user_entry2 == 6) {
                        if (row_6 <= 2) {
                            cout << "|| Column " << user_entry2 << " is full. Please try a different column!||\n";
                            user_check2 = 1;
                            continue;
                        } else {
                            board[row_6][user_entry2] = 'Y';
                            counter++;
                            row_6 = row_6 - 1;
                            user_check2 = 0;
                            break;
                        }
                    } else if (user_entry2 == 7) {
                        if (row_7 <= 2) {
                            cout << "|| Column " << user_entry2 << " is full. Please try a different column!||\n";
                            user_check2 = 1;
                            continue;
                        } else {
                            board[row_7][user_entry2] = 'Y';
                            counter++;
                            row_7 = row_7 - 1;
                            user_check2 = 0;
                            break;
                        }
                    }
                }
                display(board);// displays updated board
                userwin_check2(board, win, user_check2);// call function that checks if player 2 has won the game...
                if (counter == 42) { // if counter is 42 and no one has won then board is full
                    win = 4; // set win to 4 which will draw the game
                    user_check2 = 0; // sets player 2 check to 0
                }
                win_message(win, flag, user_entry1, user_entry2, comp_entry, row_1, row_2, row_3, row_4, row_5, row_6,row_7, counter); // gives win message if it is needed... depending on if its win lose or draw
            }
        } else if (level == 'C' || level == 'c') { // Playing against Computer
            flag = 0; // make flag = 0, so we don't loop and make the board again, only happens when we start...
            display(board); // show board
            int win = 0; // to check if it is a win or loss or tie
            while (win == 0) { // when no one has won yet win =0
                cout << endl;
                int user_check1 = 1; // variable that checks if player 1 column choice is valid
                while (user_check1 == 1) { // checks if player 1 has entered a valid column selection
                    cout << "\nPlayer 1 please enter the column number you would like to fill: "; // asks player 1 to fill
                    cin >> user_entry1;
                    if (!cin, user_entry1 <= 0 || user_entry1 >= 8) { // if out of bounds give error
                        cout << "\nInvalid Column! Please try again.";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // makes sure that only integers are entered
                        user_check1 = 1; // make user_check1 = 1 and loops again asking for valid column
                    } else if (user_entry1 == 1) { // so if column 1 is chosen
                        if (row_1 <= 2) { // if that is full give error message is given
                            cout << "|| Column " << user_entry1<< " is full. Please try a different column!||\n";
                            user_check1 = 1; // set user_check1 = 1 so we loop again
                            continue;
                        } else { // if all is good then put what user entered into board
                            board[row_1][user_entry1] = 'R';
                            counter++; // increase counter
                            row_1 = row_1 - 1; // minus one for row, so we know when the column is full
                            user_check1 = 0; // setting it to 0 so it doesn't loop again
                            break;
                        }
                       // this process is repeated for all seven columns
                    } else if (user_entry1 == 2) {
                        if (row_2 <= 2) {
                            cout << "|| Column " << user_entry1 << " is full. Please try a different column!||\n";
                            user_check1 = 1;
                            continue;
                        } else {
                            board[row_2][user_entry1] = 'R';
                            counter++;
                            row_2 = row_2 - 1;
                            user_check1 = 0;
                            break;
                        }
                    } else if (user_entry1 == 3) {
                        if (row_3 <= 2) {
                            cout << "|| Column " << user_entry1 << " is full. Please try a different column!||\n";
                            user_check1 = 1;
                            continue;
                        } else {
                            board[row_3][user_entry1] = 'R';
                            counter++;
                            row_3 = row_3 - 1;
                            user_check1 = 0;
                            break;
                        }
                    } else if (user_entry1 == 4) {
                        if (row_4 <= 2) {
                            cout << "|| Column " << user_entry1 << " is full. Please try a different column!||\n";
                            user_check1 = 1;
                            continue;
                        } else {
                            board[row_4][user_entry1] = 'R';
                            counter++;
                            row_4 = row_4 - 1;
                            user_check1 = 0;
                            break;
                        }
                    } else if (user_entry1 == 5) {
                        if (row_5 <= 2) {
                            cout << "|| Column " << user_entry1 << " is full. Please try a different column!||\n";
                            user_check1 = 1;
                            continue;
                        } else {
                            board[row_5][user_entry1] = 'R';
                            counter++;
                            row_5 = row_5 - 1;
                            user_check1 = 0;
                            break;
                        }
                    } else if (user_entry1 == 6) {
                        if (row_6 <= 2) {
                            cout << "|| Column " << user_entry1 << " is full. Please try a different column!||\n";
                            user_check1 = 1;
                            continue;
                        } else {
                            board[row_6][user_entry1] = 'R';
                            counter++;
                            row_6 = row_6 - 1;
                            user_check1 = 0;
                            break;
                        }
                    } else if (user_entry1 == 7) {
                        if (row_7 <= 2) {
                            cout << "|| Column " << user_entry1 << " is full. Please try a different column!||\n";
                            user_check1 = 1;
                            continue;
                        } else {
                            board[row_7][user_entry1] = 'R';
                            counter++;
                            row_7 = row_7 - 1;
                            user_check1 = 0;
                            break;
                        }
                    }
                }
                display(board); // shows the updated board
                userwin_check1(board, win, user_check1); // calls in function that checks if player 1 or computer has won the game...
                if (win != 1) { //only do it when player 1 has not won the game already
                    srand(time(nullptr)); // sets random seed
                    comp_entry = rand() % 7 + 1; // computer selects randomly
                    comp_fun_call(comp_entry, row_1, row_2, row_3, row_4, row_5, row_6, row_7,board); // calls the computer function which places into the board
                    cout << "The computer has chosen to fill column " << comp_entry << ".\n"; // lets player 1 know where the computer put its piece
                    counter++; // adding counter for draw check
                    if (counter == 42) { // if counter is 42 and no one has won then board is full
                        win = 4; // set win to 4 which will draw the game
                        user_check1 = 0; // sets player 1 check to 0
                    }
                }
                compwin_check(board, win, user_check1); // calling function that checks if the computer won...
            }
            win_message(win, flag, user_entry1, user_entry2, comp_entry, row_1, row_2, row_3, row_4, row_5, row_6, row_7,counter); // gives win message if it is needed... depending on if its win lose or draw
        }
        else if(level == 'I' || level == 'i'){ // if user uses to learn how play then this will be executed
            cout << "\n\t\t|| How to Play ||\n";
            cout << "\n\t|| Player VS Player mode ||\n";
            cout << "\n\t--> In this mode there will be two players (Player 1 and Player 2)\n";
            cout << "\t--> Starting with the game with player 1 which will be indicated as R for RED on the game board\n";
            cout << "\t--> And Player 2 indicated as Y for YELLOW on the game board\n";
            cout << "\t--> Both players will take turns to play\n";
            cout << "\t--> Whichever player gets a connect 4 either vertically, horizontally, or diagonally first will WIN\n";
            cout << "\t--> If its a DRAW you will get an option to play again.\n";
            cout << "\n\t|| Player VS Computer mode ||\n";
            cout << "\n\t--> In this mode you will be playing against the computer\n";
            cout << "\t--> Starting the game with player 1 which will be indicated as R for RED on the game board\n";
            cout << "\t--> And the Computer indicated as Y for YELLOW on the game board\n";
            cout << "\t--> Once Player 1 has taken their turn the computer will go next\n";
            cout << "\t--> And this will be repeated until either the player or computer\n";
            cout << "\t--> Gets a connect 4 either vertically, horizontally, or diagonally first will WIN\n";
            cout << "\t--> If its a DRAW or if the computer WINS you will get and option to play again.\n\n";
            ready_to_play(flag, user_entry1, user_entry2, comp_entry, row_1, row_2, row_3, row_4, row_5, row_6, row_7, counter); // asks the user if they want to play the game now or not
        }
        else { // if the options 'P', 'C' and 'I' where not picked then executes the below
            cout << "Invalid level choice. Please try again."; //gives error message
            flag = 1; // flag = 1 so we loop again
        }
    }
}