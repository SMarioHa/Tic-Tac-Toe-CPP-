#include <iostream>
#include <cstdlib>
#include "TTT.h"

bool isGameOver(playfield field, Player Player1, Player Player2) {
    bool gameOver = false;
    if (field.isFieldFull() || field.isWon(Player1, Player2))
    {
        gameOver = true;
    }
    return gameOver;
}

void gameLoop(playfield field, Player Player1, Player Player2) {
    Player active_player = Player1;
    int active_player_number = 1;
    while (true)
    {
        //start of Round.
        if (isGameOver(field, Player1, Player2))
        {
            field.show_field();
            break;
        }
        bool inputLoopCon = true;
        while (inputLoopCon)
        {
            field.show_field();
            inputLoopCon = field.add_in_field(active_player.Character);
        }
        //Round is over.
        if (active_player_number == 1)
        {
            active_player = Player2;
            active_player_number = 2;
        }
        else if (active_player_number == 2)
        {
            active_player = Player1;
            active_player_number = 1;
        }
    }
}

int main(int argc, char** argv)
{
    std::cout << "Welcome to New York." << "\n";
    system("pause");
    std::cout << "Just kidding, this is Tic Tac Toe, Let's go, glhf \n";
    std::string p1_name = "Elfi";
    std::string p2_name = "Mario";
    Player Player1 = Player(p1_name, 'x');
    Player Player2 = Player(p2_name, 'o');
    playfield field = playfield();
    gameLoop(field, Player1, Player2);
    std::cout << '\n' << "Well played." << '\n';
    system("pause");
    return 1;
}