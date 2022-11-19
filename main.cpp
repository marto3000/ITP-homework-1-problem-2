#include <iostream>
using namespace std;

bool isSimple(int num)
{
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	const int MAX_SIZE = 1024;

	int length;
	do
	{
		cin >> length;
	} while (length<2 || length>MAX_SIZE);
	int numbers[MAX_SIZE];
	for (int i = 0; i < length; i++)
	{
		do
		{
			cin >> numbers[i];
		} while (numbers[i] <= 1);
	}
	int problemCounter = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (isSimple(numbers[i]))
			{
				if (!isSimple(numbers[j]) || (isSimple(numbers[j]) && numbers[i] > numbers[j]))
				{
					problemCounter++;
				}
			}
		}
	}
	cout << problemCounter;

	return 0;
}