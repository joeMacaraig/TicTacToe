#include "ttt.hpp"

TicTac::TicTac(){
    board[0][0] = '1';
    board[0][1] = '2';
    board[0][2] = '3';
    board[1][0] = '4';
    board[1][1] = '5';
    board[1][2] = '6';
    board[2][0] = '7';
    board[2][1] = '8';
    board[2][2] = '9';
    
    player = 1;
    x = 0; 
    winner = false; 

}

void TicTac::intro(){
    cout << "=================\n";
    cout << "   Tic-Tac-Toe   \n";
    cout << "==================\n";
    cout << "Instructions: You\n";
    cout << "need to make 3 in\na row to win!\n";
    cout << endl;
    display();
}

void TicTac::display(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void TicTac::play(){
    int choose; 

    intro();

    while(winner == false && x < 9){

        player = (player % 2) ? 1 : 2; 
        choices = (player == 1) ? 'X' : 'O';

        cout << "Choose a place mark.\n";
        cin >> choose; 

        if(choose == 1 && board[0][0] == '1'){
            board[0][0] = choices; 
        }
        else if(choose == 2 && board[0][1] == '2'){
            board[0][1] = choices; 
        }
        else if(choose == 3 && board[0][2] == '3'){
            board[0][2] = choices; 
        }
        else if(choose == 4 && board[1][0] == '4'){
            board[1][0] = choices; 
        }
        else if(choose == 5 && board[1][1] == '5'){
            board[1][1] = choices; 
        }
        else if(choose == 6 && board[1][2] == '6'){
            board[1][2] = choices; 
        }
        else if(choose == 7 && board[2][0] == '7'){
            board[2][0] = choices; 
        }
        else if(choose == 8 && board[2][1] == '8'){
            board[2][1] = choices; 
        }
        else if(choose == 9 && board[2][2] == '9'){
            board[2][2] = choices; 
        }
        else{
            cout << "invalid move\n";
            player--;
        };
        x++;
        display();
        winningConditions();
        player++;
    }
    if(winner == true){
        cout << "The winner is " << player-1; 
    }
    else{
        cout << "Tie!";
    }
}

bool TicTac::winningConditions(){
    /* i feel like you can do it with a for loop...
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2]){ 
                winner = true; 
            }
            else{
                winner = false; 
            }
        }
    }*/
    //row
    if(board[0][0] == board[0][1] && board[0][1] == board[0][2]){
        winner = true; 
    }
    else if(board[1][0] == board[1][1] && board[1][1] == board[1][2]){
        winner = true; 
    }
    else if(board[2][0] == board[2][1] && board[2][1] == board[2][2])
    {
        winner = true;
    }
    //column
    else if(board[0][0] == board[1][0] && board[1][0] == board[2][0]){
        winner = true; 
    }
    else if(board[0][1] == board[1][1] && board[1][1] == board[2][1]){
        winner = true; 
    }
    else if(board[0][2] == board[1][2] && board[1][2] == board[2][2])
    {
        winner = true;
    }
    //diagnol
    else if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        winner = true; 
    }
    else if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        winner = true;
    }
    else{
        winner = false; 
    }

    return winner; 
}
