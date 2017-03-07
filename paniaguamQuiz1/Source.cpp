#include <iostream>
using namespace std;

//required function prototype
void validateUserInput(char *UserInputCharArray, int &strLength);

//required global constant
int const ARRAY_SIZE = 100;

int main()
{
	//required char pointers
	char *UserInputCharArray = nullptr, 
		contin;
	//allocate space for user input
	UserInputCharArray = new char[ARRAY_SIZE];

	do
	{
		int strLength = 0, odds = 0;
		//prompt user
		cout << "Enter an integer >= 0 and press <ENTER>" << endl;
		cin.get(UserInputCharArray, ARRAY_SIZE, '\n');
		cin.clear();
		cin.ignore(10000, '\n');									//only assign first 100 digits of number entered, discard rest
		//count number of chars
		while (UserInputCharArray[strLength])
		{
			strLength++;
		}
		//call validate function
		validateUserInput(UserInputCharArray, strLength);

		//displays all numbers entered
		cout << "You entered: " << UserInputCharArray << endl;

		//counts odd numbers
		for (int i = 0; i < strLength; i++)
		{
			if (UserInputCharArray[i] %2 != 0)
			{
				odds++;
			}
		}

		if (odds == strLength)										//strLength equal to odds means no evens to display
		{
			cout << "There are no even digits to display";
		}
		else
		{
			cout << "The even digits are: " << endl;				//display even digits
			for (int i = 0; i < strLength; i++)
					if (UserInputCharArray[i] % 2 == 0)
					{
						cout << UserInputCharArray[i] << " ";
					}
		}

		cout << "\nEnter anything starting with a y/Y to continue, anything else to exit." << endl;
		cin >> contin;
		cin.ignore(10000, '\n');
	} while (contin == 'y' || contin == 'Y');

	cout << "End of program." << endl;

	delete[] UserInputCharArray;
	UserInputCharArray = nullptr;

	system("pause");
	return 0;
}

//required function implementation
void validateUserInput(char *UserInputCharArray, int &strLength)
{
	int counter = 0;

	while (counter < strLength || strLength == 0)
	{
		//validates number
		if (!isdigit(UserInputCharArray[counter]) || strLength == 0)
		{
			//if not number, prompts for new number
			cout << "Input is not an integer greater than or equal to 0, please try again:\n";
			cin.get(UserInputCharArray, ARRAY_SIZE);
			cin.clear();
			cin.ignore(10000, '\n');
			strLength = 0;
			//count number of chars
			while (UserInputCharArray[strLength])
			{
				strLength++;
			}

			counter = 0;
		}
		else
		{
			counter++;
		}
	}
}