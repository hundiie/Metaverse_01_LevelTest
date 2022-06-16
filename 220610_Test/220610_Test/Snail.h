#pragma once

using namespace std;

class Snail
{
public:
	static void ArrayMake(int in)
	{
		N = in;

		int count = 1;
		int UP = 0; //올라가는 숫자
	    int DOWN = N - 1;// 내려가는 숫자

		test = new int[in*in];

		while (count <= N * N)// N * N값(배열 최대 값)이 출력되면 종료
		{
			for (int i = UP; i < N - UP; i++)// 위쪽
			{
				test[UP * N + i] = count;
				count++;
			}
			for (int i = UP + 1; i < N - UP; i++)// 오른쪽
			{
				test[i * N + DOWN] = count;
				count++;
			}

			for (int i = DOWN - 1; i > UP - 1; i--)// 아래쪽
			{
				test[DOWN * N + i] = count;
				count++;
			}

			for (int i = DOWN - 2; i > UP - 1; i--)// 왼쪽
			{
				test[(i + 1) * N + UP] = count;
				count++;
			}
			UP++;
			DOWN--;
		}
	//출력
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << test[i * N + j] << "\t";
			}
			cout << endl << endl;
		}
	}
	~Snail()
	{
		delete[] test;
	}

private:
	static int N;
	static int *test;
};
int Snail::N = 0;
int* Snail::test = { 0 };