#pragma once
#include <iostream>


class Deck
{
	static bool usecard[53];
	static const std::string mark[4];
	static const std::string num[13];
public:

	static void reset()
	{
		for (int i = 0; i < 53; i++)
		{
			usecard[i] = false;
		}
	}

	bool pick()
	{
		int count = 0;

		for (int i = 0; i < 53; i++){
			if (usecard[i] == false){
				count++;

				if (count > 7){
					break;
				}
			}
		}
		for (int i = 0; i < 7; i++)//덱 초기화
		{
			_deck[i] = 0;
		}
		if (count < 7){
			return false;
		}
		for (int i = 0; i < 7; i++){
			int random;
			do {
				random = rand() % 53;
			
			}while (usecard[random] != false);
			
			_deck[i] = random;
			usecard[random] = true;
		}
		return true;
	}

	void draw()
	{
		for (int i = 0; i < 7; i++){
			if (_deck[1] == _deck[2]){
				std::cout << "카드 부족";
				return;
			}
			if (_deck[i] != 52){
			std::cout << mark[_deck[i] % 4] << num[_deck[i] % 13];
			}
			else{
				std::cout << "JOKER";
			}
			std::cout << "\t";
		}
	}
private:
	int _deck[7];
};

bool Deck::usecard[53] = { false };
const std::string Deck::mark[4] = {"♠","♥","◆","♣"};
const std::string Deck::num[13] = { "A ","2 ","3 ","4 ","5 ","6 ","7 ","8 ","9 ","10","J ","Q ","K " };






///// <summary>
///// 저장된 카드에서 카드를 뽑음
///// </summary>
///// <param name="card">string에 저장된 카드 값</param>
///// <param name="player_">플레이어 수</param>
///// <param name="pick">뽑을 카드 수</param>
//void pick(std::string*card,int card_num, int player_, int pick)
//{
//	if (player_ * pick > card_num)
//	{
//		std::cout << "The deck is empty";
//		return;
//	}
//	int* player = new int[pick * player_];
//
//	for (int i = 0; i < pick * player_; i++)
//	{
//		player[i] = rand() % 53;
//		for (int j = 0; j < i; j++)
//		{
//			if (player[j] == player[i])
//			{
//				i--;
//				break;
//			}
//		}
//	}
//	int player_num = 0;
//	for (int i = 0; i < player_; i++)
//	{
//		if (player_num + 1 < 10)
//		{
//			std::cout << "Player 0" << player_num + 1 << " : ";
//		}
//		else
//		{
//			std::cout << "Player " << player_num + 1 << " : ";
//		}
//
//		for (int c = pick * player_num; c < pick * (player_num + 1); c++)
//		{
//			std::cout << card[player[c]] << " ";
//		}
//		std::cout << std::endl;
//		player_num++;
//	}
//}
