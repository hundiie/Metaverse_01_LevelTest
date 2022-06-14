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

class Lotto
{
public:
	static void makeLotto(int max, int create);
	
private:
	static int* box;
	static int create;
	static int max;
};

void Lotto::makeLotto(int max, int create)
{
	srand(time(NULL));

	if (create > max)
	{
		std::cout << "�߸��� �Է�";
		return;
	}

	for (int i = 0; i < create; i++)
	{
		bool check = true;

		Lotto::box[i] = rand() % max + 1;
		for (int j = 0; j < i; j++)
		{
			if (Lotto::box[j] == Lotto::box[i])
			{
				check = false;
				--i;
				break;

			}
		}
		if (check == true)
		{
			std::cout << Lotto::box[i] << std::endl;
		}
	}
}
int main(void)
{
	int max;
	int create;

	std::cin >> max >> create;
	Lotto::makeLotto(max, create);
}
*/
#pragma endregion
#pragma region 6��

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

	pick(card,53, 7, 7);// ī�� ��, �÷��̾� ��, �÷��̾ �̴� ī�� ��
}

#pragma endregion
#pragma region 7��
/*
#include <iostream>

// 10 x 10 Ȯ��

using namespace std;

#define size 5
int main(void)
{
	bool num[size * size] = { false };
	int bingo[size][size];

	srand(time(NULL));

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
	int clear = 0;//���� üũ��
	bool check[size + size + 2] = {false};//���� �ߺ� üũ

	while(clear < size + size + 2)
	{
		//������
		system("cls");

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

		//�Է�
		int input;
		std::cout << "���� " << clear << "���� ���� �ϼ��Ǿ����ϴ�." << std::endl;

		std::cout << "���ڸ� �Է��� �ּ��� : ";
		std::cin >> input;
		//���� �����
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
		//�� �κ� ��¼��

		//���� ���� ó��
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
				if (check[i+size] != true)
				{
					check[i+size] = true;
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

	int count = 1;

	int UP = 0;
	int D_COUNT = 0;
	int DOWN = N - 1;

	//while (count <= N*N)
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