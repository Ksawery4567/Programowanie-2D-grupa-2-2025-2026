#include <iostream>
#include <fstream>
#include <vector>

bool isPrime(int number)
{
	if (number < 2)
		return false;

	for (int i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}

int reversedNumber(int number)
{
	int reversed = 0;
	while (number > 0)
	{
		reversed = reversed * 10 + number % 10;
		number = number / 10;
	}

	return reversed;
}

int main()
{
	setlocale(LC_CTYPE, "Polish");
	std::ifstream file("przyklad.txt");
	std::vector<int> numbers;
	int number;

	while (file >> number)
	{
		numbers.push_back(number);
	}

	//Zadanie 1
	for (int num : numbers)
	{
		if (reversedNumber(num) % 17 == 0)
		{
			std::cout << reversedNumber(num) << "\n";
		}
	}

	//Zadanie 2
	int maxDifference = 0;
	int highest = 0;
	int reversedNum;

	for (int num : numbers)
	{
		reversedNum = reversedNumber(num);
		int difference = abs(num - reversedNum);

		if (difference > maxDifference)
		{
			maxDifference = difference;
			highest = num;
		}
	}

	std::cout << highest << " " << maxDifference << "\n";

	//Zadanie 3
	for (int num : numbers)
	{
		int reversedNum = reversedNumber(num);
		if (isPrime(num) && isPrime(reversedNum))
		{
			std::cout << num << "\n";
		}
	}

	//Zadanie 4
	std::vector<int> uniqueNumbers;
	std::vector<int> occurrences;

	for (int i = 0; i < numbers.size(); i++) {
		bool found = false;
		for (int j = 0; j < uniqueNumbers.size(); j++) {
			if (uniqueNumbers[j] == numbers[i]) {
				occurrences[j]++;
				found = true;
				break;
			}
		}
		if (!found) {
			uniqueNumbers.push_back(numbers[i]);
			occurrences.push_back(1);
		}
	}

	int uniqueCount = uniqueNumbers.size();
	int countTwice = 0, countThrice = 0;

	for (int i = 0; i < occurrences.size(); i++) {
		if (occurrences[i] == 2) countTwice++;
		if (occurrences[i] == 3) countThrice++;
	}

	std::cout << uniqueCount << " " << countTwice << " " << countThrice << "\n";
}
