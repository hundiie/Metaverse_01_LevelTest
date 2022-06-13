#pragma region 1�� 
/*
#include <iostream>

void swap1(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
void swap2(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}
*/
#pragma endregion
#pragma region 2��
/*
#include <iostream>

int main(void)
{
    int a = 3;
    while (a < 1000)
    {
        std::cout << a << std::endl;
        a *= 3;
    }
}
*/
#pragma endregion
#pragma region 3��
/*
#include <iostream>

#define count 5

int main(void)
{
	int a = count - 1;
	int b = 1;

	for (int i = 0; i < count; i++)
	{
		for (int j = a; j > 0; j--)
		{
			std::cout << " ";
		}
		a -= 1;

		for (int k = 0; k < b; k++)
		{
			std::cout << "*";
		}
		b += 2;

		std::cout << std::endl;
	}
}
*/
#pragma endregion
#pragma region 4��
/*
#include <iostream>

void sortArray(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - (i + 1); j++)
		{
			if (arr[j] > arr[j + 1])// �յ� ��
			{
				int change = arr[j + 1];//�ٲٱ�
				arr[j + 1] = arr[j];
				arr[j] = change;
			}
		}
	}
}

int main(void)
{
	int arr[5] = { 5, 2, 4, 1, 3};
	sortArray(arr, 5);

	for (int i = 0; i < 5; i++)
	{
		std::cout <<arr[i];
	}
}
*/
#pragma endregion
#pragma region 5��
/*
#include <iostream>

int main(void)
{
	int max;
	int create;

	srand(time(NULL));

	std::cin >> max >> create;

	if (create > max)
	{
		std::cout << "�߸��� �Է�";
		return 0;
	}

	int* box =  (int*)malloc(sizeof(int) * create);

	for (int i = 0; i < create; i++)
	{
		bool check = true;

		int random = rand() % max + 1;
		box[i] = random;
		for (int j = 0; j < i; j++)
		{
			if (box[j] == random)
			{
				check = false;
				--i;
				break;

			}
		}
		if (check == true)
		{
			std::cout << random << std::endl;
		}
	}
	free(box);
	return 0;
}
*/
#pragma endregion
#pragma region 6��

#include <iostream>
#include <string>

/// <summary>
/// ����� ī�忡�� ī�带 ����
/// </summary>
/// <param name="card">string�� ����� ī�� ��</param>
/// <param name="card_num">string�� ����� ī�� ��</param>
/// <param name="player_">�÷��̾� ��</param>
/// <param name="pick">���� ī�� ��</param>
void pick(std::string* card,int card_num, int player_, int pick)
{
	if (pick*player_ > card_num)
	{
		std::cout << "�߸��� �Է��Դϴ�.(ī���� ���ڰ� ������)";
		return;
	}
	int* player = new int[pick*player_];
	
	srand(time(NULL));
	
	for (int i = 0; i < pick * player_; i++)
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
	int player_num = 0;
	for (int i = 0; i < player_; i++)
	{
		if (player_num + 1 < 10)
		{
			std::cout << "Player 0" << player_num + 1 << " : ";
		}
		else
		{
			std::cout << "Player " << player_num + 1 << " : ";
		}

		for (int c = pick * player_num; c < pick * (player_num + 1); c++)
		{
			std::cout << (c % pick) + 1  << "��° ī�� : " << card[player[c]] << " ";
		}
		std::cout << std::endl;
		player_num++;
	}
}

int main(void)
{
	std::string card[53];
	std::string mark[4] = { "��","��","��","��" };
	std::string num[13] = { "A ","2 ","3 ","4 ","5 ","6 ","7 ","8 ","9 ","10","J ","Q ","K " };


	for (int k = 0; k < 52; k++)
	{
		card[k] = mark[k % 4] + num[k % 13];
	}
	card[52] = "Joke";
	
	pick(card, 53, 7, 6);// ī�� ��, ī�� �� , �÷��̾� ��, �÷��̾ �̴� ī�� ��
}

#pragma endregion
#pragma region 7��
/*
#include <iostream>
#include <string>

int main(void)
{
	bool num[25] = { false };
	int bingo[5][5];
	bool check[12] = { false };
	srand(time(NULL));

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int random = rand() % 25;
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
	int clear = 0;

	while (true)
	{
		//������

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (bingo[i][j] != 0)
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

		//�Է�
		int input;
		std::cout << "���� " << clear << "���� ���� �ϼ��Ǿ����ϴ�." << std::endl;
		std::cout << "���ڸ� �Է��� �ּ��� : ";
		std::cin >> input;

		system("cls");

		//���� �����
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (bingo[i][j] == input)
				{
					bingo[i][j] = 0;
				}
			}
		}

		//���� ���� ó��
		for (int i = 0; i < 5; i++)
		{
			if (bingo[i][0] == 0 && bingo[i][1] == 0 && bingo[i][2] == 0 && bingo[i][3] == 0 && bingo[i][4] == 0)
			{
				if (check[i] != true)
				{
					check[i] = true;
					clear += 1;
				}
			}
			if (bingo[0][i] == 0 && bingo[1][i] == 0 && bingo[2][i] == 0 && bingo[3][i] == 0 && bingo[4][i] == 0)
			{
				if (check[i + 5] != true)
				{
					check[i + 5] = true;
					clear += 1;
				}
			}
		}

		//�밢�� ���� ó��
		if (bingo[0][0] == 0 && bingo[1][1] == 0 && bingo[2][2] == 0 && bingo[3][3] == 0 && bingo[4][4] == 0)
		{
			if (check[10] != true)
			{
				check[10] = true;
				clear += 1;
			}
		}
		if (bingo[0][4] == 0 && bingo[1][3] == 0 && bingo[2][2] == 0 && bingo[3][1] == 0 && bingo[4][0] == 0)
		{
			if (check[11] != true)
			{
				check[11] = true;
				clear += 1;
			}
		}
	}
	return 0;
}
*/
#pragma endregion
#pragma region 8��
/*
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int N;
	cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
	cin >> N;

	int** test = new int* [N];
	for (int i = 0; i < N; i++)
	{
		test[i] = new int[N];
	}

	int*** a = new int** [N];
	for (int i = 0; i < N; i++)
	{
		int* [N];
	}

	int count = 1;

	int UP = 0;
	int D_COUNT = 0;
	int DOWN = N - 1;
	while (count <= N*N)
	{
		for (int i = UP; i < N - D_COUNT; i++)
		{
			test[UP][i] = count;
			count++;
		}
		for (int i = UP + 1; i < N - D_COUNT; i++)
		{
			test[i][DOWN] = count;
			count++;
		}

		for (int i = DOWN - 1; i > D_COUNT - 1; i--)
		{
			test[DOWN][i] = count;
			count++;
		}

		for (int i = DOWN - 2; i > D_COUNT - 1; i--)
		{
			test[i + 1][UP] = count;
			count++;
		}
		UP++;
		D_COUNT++;
		DOWN--;
	}

	//���
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << test[i][j] << "\t";
		}
		cout << endl << endl;
	}
}
*/
#pragma endregion