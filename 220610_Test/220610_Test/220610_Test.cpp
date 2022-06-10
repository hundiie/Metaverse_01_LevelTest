#include <iostream>
#include <string>

int main(void)
{
	std::string card[53];
	std::string mark[4] = { "♠","♥","◆","♣" };
	std::string num[13] = { "A ","2 ","3 ","4 ","5 ","6 ","7 ","8 ","9 ","10","J ","Q ","K " };

	card[52] = "JOKER";

	for (int k = 0; k < 53; k++)
	{
		card[k] = mark[k % 4] + num[k % 13];
	}

	srand(time(NULL));
	int player[14] = {};

	for (int i = 0; i < 14; i++)
	{
		player[i] = rand() % 53;
		for (int j = 0; j < i; j++)
		{
			if (player[j] == player[i])
			{
				i--;
				break;
			}
		}
	}

	std::cout << "Player1 : ";
	for (int c = 0; c < 7; c++)
	{
		std::cout << card[player[c]] << " ";
	}

	std::cout << "\nPlayer2 : ";
	for (int c = 7; c < 14; c++)
	{
		std::cout << card[player[c]] << " ";
	}
}