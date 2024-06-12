#include <iostream>
#include <vector>

using namespace std;

// Khai bao bien
vector<char> bang = {'_', '_', '_', '_', '_', '_', '_', '_', '_'};
int inputs;
char x_o = 'x';
char x = 'x';
char o = 'o';
int player = 0;
int input1;
bool x_or_o = true;
int returns;
int again;

// Khai bao ham
void greet(); void how_to();
void create_board();
int input(int xy);
int check(int players);
void end_game();

// Dinh huong ham
int main() {

    //Start game
    greet();
    if (inputs == 1 ) {
        while (returns < 9 + again && player < 2) {

            x_o = x_or_o ? 'x' : 'o';
            create_board();
            cout << "Enter the positive of " << x_o << "\n";
            cin >> input1;
            input(input1);
            player = check(1);
            returns++;

        }
        end_game();

    } else {

        how_to();

    }

}

void greet() {

    // Menu
    int input;
    cout << "=============================\n";
    cout << "=========Tic-Tac-Toe=========\n";
    cout << "=============================\n\n";
    cout << "Player 1 (x)  |  Player 2 (o)\n\n";
    cout << "1) Start\n";
    cout << "2) How to play\n";
    cin >> input;
    inputs = input;

}

void how_to() {

    cout << "How to play X/O";
    cout << "\n";
    cout << "  Tic-Tac-Toe is a paper-and-pencil game for two players,\n ";
    cout << "X and O, who take turns marking the spaces in a 3x3 grid.\n ";
    cout << "The player who succeeds in placing three of their marks in\n ";
    cout << "a horizontal, vertical or diagonal row wins the game.\n";
    cout << "--To enter X/O, enter numbers 1 - 9 to specify the entry position--\n";
    for (int i = 1; i < bang.size() + 1; ++i) {

        if (i == 3 || i == 6) {
            cout << " " << i << endl;
        } else {
            cout << " " << i;
        }

    }

}

void create_board() {

    for (int i = 0; i < bang.size(); ++i) {

        if (i == 2 || i == 5 ) {
            cout << " " << bang[i] << endl;
        } else if (i == 8) {
            cout << " " << bang[i] << endl << "\n\n";
        } else {
            cout << " " << bang[i];
        }

    }
}

int input(int xy) {



    if (x_or_o) {
        if (bang[xy - 1] == o || xy > 10 || xy > 0) {
            bang[xy - 1] = o;
            again++;
        } else {
            x_or_o = false;
            bang[xy - 1] = x;
        }

    } else {
        if (bang[xy - 1] == x || xy > 10 || xy > 0) {
            bang[xy - 1] = x;
            again++;
        } else {
            x_or_o = true;
            bang[xy - 1] = o;
        }

    }
    return 0;

}

int check(int players) {

    if (bang[3] == bang[4] && bang[4] == bang[5] && bang[5] == 'x'
            || bang[0] == bang[4] && bang[4] == bang[8] && bang[8] == 'x'
            || bang[0] == bang[3] && bang[3] == bang[6] && bang[6] == 'x'
            || bang[2] == bang[4] && bang[4] == bang[6] && bang[6] == 'x'
            || bang[2] == bang[5] && bang[5] == bang[8] && bang[8] == 'x'
            || bang[1] == bang[4] && bang[4] == bang[7] && bang[7] == 'x'
            || bang[6] == bang[7] && bang[7] == bang[8] && bang[8] == 'x'
            || bang[0] == bang[1] && bang[1] == bang[2] && bang[2] == 'x') {
        players = 3;
    } else if (bang[3] == bang[4] && bang[4] == bang[5] && bang[5] == 'o'
               || bang[0] == bang[4] && bang[4] == bang[8] && bang[8] == 'o'
               || bang[0] == bang[3] && bang[3] == bang[6] && bang[6] == 'o'
               || bang[2] == bang[4] && bang[4] == bang[6] && bang[6] == 'o'
               || bang[2] == bang[5] && bang[5] == bang[8] && bang[8] == 'o'
               || bang[1] == bang[4] && bang[4] == bang[7] && bang[7] == 'o'
               || bang[6] == bang[7] && bang[7] == bang[8] && bang[8] == 'o'
               || bang[0] == bang[1] && bang[1] == bang[2] && bang[2] == 'o') {
        players = 4;
    } else {
        players = 1;
    }
    return players;

}

void end_game() {

    if (player == 1 && returns == 9 + again) {
        cout << "============================\n\n";
        cout << "==========  Draw  ==========\n\n";
        cout << "============================\n";
    } else if (player == 3) {
        cout << "============================\n\n";
        cout << "======  Player 1 win  ======\n\n";
        cout << "============================\n";
    } else if (player == 4) {
        cout << "============================\n\n";
        cout << "======  Player 2 win  ======\n\n";
        cout << "============================\n";
    }

}
