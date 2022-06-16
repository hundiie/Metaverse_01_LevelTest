#pragma once
#include <iostream>

#define size 5

class Bingo
{
public:
	void Init()
	{
		clear = 0;

		for (int i = 0; i < size + size + 2; i++)
		{
			check[i] = false;
		}

		for (int i = 0; i < size * size; i++)
		{
			num[i] = false;
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				int random = rand() % (size * size);
				if (num[random] == false)
				{
					num[random] = true;
					bingo[i][j] = random + 1;
				}
				else
				{
					j--;
				}
			}
		}
	}
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (bingo[i][j] != false)//int false�� = 0
				{
					std::cout << bingo[i][j] << "\t";
				}
				else
				{
					std::cout << "\t";
				}
			}
			std::cout << std::endl << std::endl;
		}
		std::cout << "'0' �Է� �� �����" << endl;
		std::cout << "���� " << clear << "���� ���� �ϼ��Ǿ����ϴ�." << std::endl;
		std::cout << "���ڸ� �Է��� �ּ��� : ";
	}

	void Update(int input)
	{
		if (input == 0)
		{
			Init();
			return;
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (bingo[i][j] == input)
				{
					bingo[i][j] = false;//��ǲ �� false�� �ٲ�
					break;
				}
			}
		}

		for (int i = 0; i < size; i++)
		{
			bool bingo_check = true;
			for (int j = 0; j < size; j++)
			{
				if (bingo[i][j] != 0)// �ϳ��� 0�� �ƴϸ� false
				{
					bingo_check = false;
					break;
				}
			}
			if (bingo_check == true)
			{
				if (check[i] != true)
				{
					check[i] = true;
					clear += 1;
				}
			}
		}
		//���� ���� ó��
		for (int i = 0; i < size; i++)
		{
			bool bingo_check = true;
			for (int j = 0; j < size; j++)
			{
				if (bingo[j][i] != 0)// �ϳ��� 0�� �ƴϸ� false
				{
					bingo_check = false;
					break;
				}
			}
			if (bingo_check == true)
			{
				if (check[i + size] != true)
				{
					check[i + size] = true;
					clear += 1;
				}
			}
		}

		//�밢�� ���� ó��
		{
			bool bingo_check = true;
			for (int i = 0; i < size; i++)
			{
				if (bingo[i][i] != 0)// �ϳ��� 0�� �ƴϸ� false
				{
					bingo_check = false;
					break;
				}
			}
			if (bingo_check == true)//true�϶� �� üũ
			{
				if (check[size * 2] != true)
				{
					check[size * 2] = true;
					clear += 1;
				}
			}
		}

		{
			bool bingo_check = true;
			for (int i = 0; i < size; i++)
			{

				if (bingo[i][size - 1 - i] != 0)// �ϳ��� 0�� �ƴϸ� false
				{
					bingo_check = false;
					break;
				}
			}
			if (bingo_check == true)//true�϶� �� üũ
			{
				if (check[size * 2 + 1] != true)
				{
					check[size * 2 + 1] = true;
					clear += 1;
				}
			}
		}
	}

private:
	static bool num[size * size];
	static int bingo[size][size];
	static int clear;
	static bool check[size + size + 2];
};

bool Bingo::num[size * size] = { false };
int Bingo::bingo[size][size] = { 0 };
bool Bingo::check[size + size + 2] = { false };
int Bingo::clear = 0;
