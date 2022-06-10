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
		//빙고판
		
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
		
		//입력
		int input;
		std::cout << "현재 " << clear << "줄의 빙고가 완성되었습니다." << std::endl;
		std::cout << "숫자를 입력해 주세요 : ";
		std::cin >> input;
		
		system("cls");
		
		
		//숫자 지우기
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
		//직선 빙고 처리
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
		//대각선 빙고 처리
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