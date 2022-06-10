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
