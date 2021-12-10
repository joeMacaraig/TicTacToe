#include <iostream> 

using namespace std; 

class TicTac{
    private:
        char board[3][3];
        int player; 
        int x;
        char choices;
        bool winner; 
    public:
        TicTac();
        void intro();
        void play();
        void display();
        bool winningConditions();

};