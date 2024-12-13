#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>


class Player
{
public:
	Player(std::string Name, char Character);
	char Character;
	std::string Name;
};
#endif // !PLAYER_H