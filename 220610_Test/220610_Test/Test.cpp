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
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int change = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = change;
			}
		}
	}
}

int main(void)
{
	int arr[5] = { 5, 2, 4, 1, 3 };
	sortArray(arr, 5);
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
/*
#include <iostream>
#include <string>

int main(void)
{
	std::string card[53];
	std::string mark[4] = { "��","��","��","��" };
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
return 0;
}
*/
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
#include <iostream>
#include <string>

using namespace std;
	
	//  1 ...	N-3			N-2			N-1			N
	//	(N*4-4)=(N*3+N-4)...			(N*5-6)		(N+1)
	//	.											(N+2)
	//	.											(N+3)
	//	(N*3-2+2)									.
	//	(N*3-2+1)									.
	//	(N*3-2)=(N*2+N-2)...(N*2+2)		(N*2+1)		(N*2-1)=(N+N-1)
int test[1000][1000];
int main(void)
{
	int N;
	cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
	cin >> N;
	
	int in = 0;
	int sero = 1;
	int garo = 0;

	for (int i = 0; i < N; i++)
	{
		test[garo][i] = i + 1;
	}
	for (int i = 0; i < N; i++)
	{
		test[i + sero][N - sero] = N + i + 1;
	}
	for (int i = 0; i < N - in; i++)
	{
		test[N - 1][i] = N * 3 - 2 - i;
	}
	in++;
	for (int i = 0; i < N - in; i++)
	{
		test[i][garo] = N * 4 - 3 - i;
	}
	

	//���
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << test[i][j]<< "\t";
		}
		cout << endl << endl;
	}
}
#pragma endregion
