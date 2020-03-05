#include <iostream>
#include <vector>
#include <string>

std::vector<int> reorderDigits(std::vector<int> arr, std::string direction);

int main()
{
	std::vector<int> testArray = { 1234, 7360, 1337331, 55, 0 };	// Array used for testing
	std::vector<int> newArr;

	// Arrange digits of each number of the test array in ascending order
	// Output result
	newArr = reorderDigits(testArray, "asc");
	for (int i = 0; i < newArr.size(); i++)
	{
		std::cout << newArr[i] << " ";
	}
	std::cout << std::endl;

	// Arrange digits of each number of the test array in descending order
	// Output result
	newArr = reorderDigits(testArray, "desc");
	for (int i = 0; i < newArr.size(); i++)
	{
		std::cout << newArr[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

std::vector<int> reorderDigits(std::vector<int> arr, std::string direction)
{
	// Create vector to hold new array of reordered digits in each element of the given array
	std::vector<int> newArr;

	// Loop used to iterate through each element of the given array
	for (int i = 0; i < arr.size(); i++)
	{
		// Convert current element to a string
		// Convert each element of the new string to a single digit integer
		// Store digit in a temporary integer array
		std::string stringNumber = std::to_string(arr[i]);
		std::vector<int> tempArr;
		for (int j = 0; j < stringNumber.size(); j++)
		{
			char digit = stringNumber[j];
			int currentDigit = atoi(&digit);
			tempArr.push_back(currentDigit);
		}

		// Loop that sorts the temporary intgeger array in either ascending or descending order
		bool swap;
		int temp;
		do
		{
			swap = false;
			for (int j = 0; j < tempArr.size() - 1; j++)
			{
				if (direction == "asc")
				{
					if (tempArr[j] > tempArr[j + 1])
					{
						temp = tempArr[j];
						tempArr[j] = tempArr[j + 1];
						tempArr[j + 1] = temp;
						swap = true;
					}
				}
				else
				{
					if (tempArr[j] < tempArr[j + 1])
					{
						temp = tempArr[j];
						tempArr[j] = tempArr[j + 1];
						tempArr[j + 1] = temp;
						swap = true;
					}
				}
			}
		} while (swap);

		// Convert each digit into a char and then push back into a string
		// Use new string to convert the current digits into an integer
		// Push back the new sorted integer into the new array of ordered integers
		std::string newStringNumber;
		for (int j = 0; j < tempArr.size(); j++)
		{
			char digit[2];
			_itoa_s(tempArr[j], digit, 10);
			newStringNumber.push_back(digit[0]);
		}
		int reorderedNumber = stoi(newStringNumber);
		newArr.push_back(reorderedNumber);
	}

	return newArr;
}
