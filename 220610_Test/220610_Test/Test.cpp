#pragma region 1�� 

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

	for (int i = 3; i < 1000; i+= 3)
	{
		std::cout << i << std::endl;
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

void makeLotto(int max, int create)
{
	srand(time(NULL));

	if (create > max)
	{
		std::cout << "�߸��� �Է�";
		return;
	}

	int* box = new int[create];//���� �迭

	for (int i = 0; i < create; i++)
	{
		bool check = true;

		box[i] = rand() % max + 1;
		for (int j = 0; j < i; j++)
		{
			if (box[j] == box[i])
			{
				check = false;
				--i;
				break;
			}
		}
		if (check == true)
		{
			std::cout << box[i] << std::endl;
		}
	}
	delete [] box;
}
int main(void)
{
	int max;
	int create;

	std::cin >> max >> create;
	makeLotto(max, create);
}
*/
#pragma endregion
#pragma region 6��
/*
#include <iostream>
#include <string>
#include "card.h"

int main(void)
{
	const std::string mark[4] = { "��","��","��","��" };
	const std::string num[13] = { "A ","2 ","3 ","4 ","5 ","6 ","7 ","8 ","9 ","10","J ","Q ","K " };

	std::string card[53];

	for (int k = 0; k < 52; k++)
	{
		card[k] = mark[k % 4] + num[k % 13];
	}

	card[52] = "Joke";
	srand(time(NULL));

	for (int i = 0; i < 8; i++)
	{
	Deck a;
	a.pick();
	a.draw();
	std::cout << std::endl;
	}
	Deck::reset();
	for (int i = 0; i < 9; i++)
	{
		Deck a;
		a.pick();
		a.draw();
		std::cout << std::endl;
	}
}
*/
#pragma endregion
#pragma region 7��
/*
#include <iostream>

// 10 x 10 Ȯ��

using namespace std;

#include "Bingo.h"

int main(void)
{
	Bingo a;

	a.Init();//���� ���� ����

	while (true)
	{
		system("cls");
		a.Print();//������ ǥ��

		int input;
		std::cin >> input;

		a.Update(input);// ���� üũ
	}
}
*/
#pragma endregion
#pragma region 8��

#include <iostream>
#include <string>
#include "Snail.h"
using namespace std;

int main(void)
{
	int N;
	cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
	cin >> N;

	Snail::ArrayMake(N);
}

#pragma endregion
/*
//������ ������ ����
#include <iostream>

using namespace std;

#define NOT_VISITED 0

int main()
{

	// 1. �迭 �����
	cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
	int size;
	cin >> size;

	int* arr = new int[size * size];
	memset(arr, 0, sizeof(int) * size * size);

	// 2. ������ �迭 ����
	// 2-1. ������ ������ �ʱ�ȭ
	int r = 0; // �������� ��ġ(y ��ǥ)
	int c = 0; // �������� ��ġ(x ��ǥ)
	int footstep = 1; // ���ڱ�
	enum Direction { DIR_RIGHT, DIR_DOWN, DIR_LEFT, DIR_UP, DIR_MAX };
	Direction direction = DIR_RIGHT; // �����̰� �����̴� ����

	for (int i = 0; i < size * size; ++i)
	{
		// 2-2. ���ڱ��� �����.
		arr[r * size + c] = footstep;
		++footstep;

		// 2-3. �̵��� ��ġ�� ����Ѵ�.
		static const int dr[] = { 0, 1, 0, -1 };
		static const int dc[] = { 1, 0, -1, 0 };

		int nr = r + dr[(int)direction];
		int nc = c + dc[(int)direction];

		// 2-4. �̵��� �������� �Ǻ��Ѵ�. 
		// 2-4-1. ���� ����� �� => r, c�� ��ġ�� [0, size)
		// 2-4-2. �̹� ������ ���� �� => arr[nr][nc] != 0
		if (nr < 0 || nr >= size || nc < 0 || nc >= size ||
			arr[nr * size + nc] != NOT_VISITED)
		{
			// 2-5. �̵��� �Ұ����ϹǷ� ���� ��ȯ�� �Ѵ�.
			direction = (Direction)((direction + 1) % DIR_MAX);

			// 2-6. ��ġ���� �ٽ� ����Ѵ�.
			nr = r + dr[(int)direction];
			nc = c + dc[(int)direction];
		}

		// 2-7. �̵��Ѵ�.
		r = nr;
		c = nc;
	}

	// 3. ���
	for (int r = 0; r < size; ++r)
	{
		for (int c = 0; c < size; ++c)
		{
			cout << arr[r * size + c] << "\t";
		}
		cout << "\n";
	}


	delete[] arr;
}
*/