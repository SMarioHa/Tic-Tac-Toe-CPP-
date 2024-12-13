#pragma once
#ifndef PLAYFIELD_H
#define PLAYFIELD_H
#include <iostream>
#include "Player.h"

class playfield {
public:
	playfield();
	void show_field();
	bool add_in_field(char Character);
	bool isFieldFull();
	bool isWon(Player Player1, Player Player2);
private:
	char field[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
};
#endif // !PLAYFIELD_H