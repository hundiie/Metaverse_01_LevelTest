#include <iostream>

int main(void)
{
	int max;
	int create;

	srand(time(NULL));

	std::cin >> max >> create;
	
	for (int i = 0; i < create; i++)
	{
		std::cout << rand() %max + 1 << std::endl;
	}
}