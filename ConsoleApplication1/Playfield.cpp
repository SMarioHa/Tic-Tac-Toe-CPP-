
#include "playfield.h"
playfield::playfield()
{

}
void playfield::show_field() {
	std::cout << "\n";
	for (int index = 0; index < 9; ++index)
	{
		if(index == 2 || index == 5 || index == 8)
		{
			std::cout << this->field[index] << "\n";
			if (index == 2 || index == 5)
			{
				std::cout << "=====" << "\n";
			}
		}
		else
		{
			std::cout << this->field[index] << "|";
		}
	}
};
bool playfield::isFieldFull() {
	bool is_full = false;
	for (int index = 0; index < 9; ++index)
	{
		if (this->field[index] == ' ')
		{
			is_full = false;
			break;
		}
		is_full = true;
	}
	return is_full;
}
bool playfield::add_in_field(char Character) {
	bool CANT_END_LOOP = false;
	int userIndex = 0;
	try
	{
		//New Line so we are always on new Line.
		std::cout << "\n" << "Input a Field from 1-9 (From top left to down right.)";
		std::cin >> userIndex;
		if (userIndex == 0 || (userIndex < 1 && userIndex > 9)) CANT_END_LOOP = true;
		else if (this->field[userIndex - 1] != ' ')
		{
			std::cout << "pick a none Empty Field Mate.";
		}
		else{
			//decrease by one to make sure we match Array Index
			//This gives Buffer Overflow warning, but should be no Problem since we filter out all outputs which arent 1-9
			this->field[userIndex - 1] = Character;
		}
	}
	catch (const std::exception&)
	{

		std::cout << "unexpected Error";
		CANT_END_LOOP = true;
	}
	if (std::cin.fail())
	{
		//New Line so we are always on new Line.
		std::cout << "\n" << "Please Enter an Integer between 1-9.";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return CANT_END_LOOP;
}
bool playfield::isWon(Player Player1, Player Player2) {
	bool is_won = false;

	char P1_char = Player1.Character;
	char P2_char = Player2.Character;

	//row one
	if ((this->field[0] == P1_char && this->field[1] == P1_char && this->field[2] == P1_char) || (this->field[0] == P2_char && this->field[1] == P2_char && this->field[2] == P2_char))
	{
		is_won = true;
	}
	//row two
	if ((this->field[3] == P1_char && this->field[4] == P1_char && this->field[5] == P1_char) || (this->field[3] == P2_char && this->field[4] == P2_char && this->field[5] == P2_char))
	{
		is_won = true;
	}
	//row three
	if ((this->field[6] == P1_char && this->field[7] == P1_char && this->field[8] == P1_char) || (this->field[6] == P2_char && this->field[7] == P2_char && this->field[8] == P2_char))
	{
		is_won = true;
	}
	//column one
	if ((this->field[0] == P1_char && this->field[3] == P1_char && this->field[6] == P1_char) || (this->field[0] == P2_char && this->field[3] == P2_char && this->field[6] == P2_char))
	{
		is_won = true;
	}
	//column two
	if ((this->field[1] == P1_char && this->field[4] == P1_char && this->field[7] == P1_char) || (this->field[1] == P2_char && this->field[4] == P2_char && this->field[7] == P2_char))
	{
		is_won = true;
	}
	//column three
	if ((this->field[2] == P1_char && this->field[5] == P1_char && this->field[8] == P1_char) || (this->field[2] == P2_char && this->field[5] == P2_char && this->field[8] == P2_char))
	{
		is_won = true;
	}
	//top left to down right
	if ((this->field[0] == P1_char && this->field[4] == P1_char && this->field[8] == P1_char) || (this->field[0] == P2_char && this->field[4] == P2_char && this->field[8] == P2_char))
	{
		is_won = true;
	}
	//top right to down left
	if ((this->field[2] == P1_char && this->field[4] == P1_char && this->field[6] == P1_char) || (this->field[2] == P2_char && this->field[4] == P2_char && this->field[6] == P2_char))
	{
		is_won = true;
	}
	return is_won;
}