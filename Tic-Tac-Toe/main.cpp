#include <iostream>
using namespace std;

char position[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
bool gameRunning = true;

void Board();
int CheckWin();

int main()
{
    int player = 1, choice;
    char mark;
    
    //Checking if the game is running
    while(gameRunning){
        
        Board();
        
        //Results of Draw or Win game
        if(CheckWin() == 1){
            gameRunning = false;
            cout << "\n        Player " << --player << " WIN!" << endl;
            return 0;
        }else if(CheckWin() == 2){
            gameRunning = false;
            cout << "\n            DRAW!" << endl;
            return 0;
        }
        
        //Initialize player depending on the round and his marks
        player = (player % 2) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';
        
        cout << "Player " << player << ", enter a number: ";
        cin >> choice;
        
        //Checking if the choice is not selected and if this is distinct to 10
        if(position[choice] != 'X' && position[choice] != 'O' && choice != 0 && choice < 10){
            position[choice] = mark;
            player++;
        }
        //If the input is invalid we launch an error message and restart the turn
        else{
            cout << "Invalid position!" << endl;
            cin.ignore();
            cin.get();
        }
    }
        
	return 0;
}

int CheckWin()
{
    //Check if we have an a complete horizontal line with the same mark
    for(int i = 1; i <= 9; i += 3){
        if(position[i] == position[i+1] && position[i] == position[i+2]){
            return 1;
        }
    }
    
    //Check if we have an a complete vertical line with the same mark
    for(int i = 1; i <= 3; i++){
        if(position[i] == position[i+3] && position[i] == position[i+6]){
            return 1;
        }
    }
    
    //Check if we have an a complete diagonal line with the same mark
    if((position[5] == position[1] && position[5] == position[9]) ||
    (position[5] == position[3] && position[5] == position[7])){
        return 1;
    }
    
    //Check if all the positions are in use
    if(position[1] != '1' && position[2] != '2' && position[3] != '3' &&
       position[4] != '4' && position[5] != '5' && position[6] != '6' &&
       position[7] != '7' && position[8] != '8' && position[9] != '9'){
           return 2;
       }
   
    return 0;
}

//Function to draw the board of Tic Tac Toe
void Board()
{
    system("cls");
    cout << "\n\t Tic-Tac-Toe\n\n";
    cout << "Player 1 - X     Player 2 - O" << endl << endl;
    
    cout << "           |     |     " << endl;
    cout << "        " << position[1] << "  |  " << position[2] << "  |  " << position[3] << "  " << endl;
    cout << "      _____|_____|_____" << endl;
    cout << "           |     |     " << endl;
    cout << "        " << position[4] << "  |  " << position[5] << "  |  " << position[6] << "  " << endl;
    cout << "      _____|_____|_____" << endl;
    cout << "           |     |     " << endl;
    cout << "        " << position[7] << "  |  " << position[8] << "  |  " << position[9] << "  " << endl;
    cout << "           |     |     " << endl;
}
