#pragma once

using namespace std;

class Snail
{
public:
	static void ArrayMake(int in)
	{
		N = in;

		int count = 1;
		int UP = 0; //�ö󰡴� ����
	    int DOWN = N - 1;// �������� ����

		test = new int[in*in];

		while (count <= N * N)// N * N��(�迭 �ִ� ��)�� ��µǸ� ����
		{
			for (int i = UP; i < N - UP; i++)// ����
			{
				test[UP * N + i] = count;
				count++;
			}
			for (int i = UP + 1; i < N - UP; i++)// ������
			{
				test[i * N + DOWN] = count;
				count++;
			}

			for (int i = DOWN - 1; i > UP - 1; i--)// �Ʒ���
			{
				test[DOWN * N + i] = count;
				count++;
			}

			for (int i = DOWN - 2; i > UP - 1; i--)// ����
			{
				test[(i + 1) * N + UP] = count;
				count++;
			}
			UP++;
			DOWN--;
		}
	//���
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