// anurag
// lab 1
// 9/15

#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int SIZE = 5;

struct Animal
{
	string type{};
	int count{ 0 };
};

// function prototype
string caseConversion(string);
void enterData(vector<Animal>&);
void displayData(const vector<Animal>&);
int validator(int);

enum { ADD = 1, DISPLAY, EXIT };

int main()
{
	string animalType{};
	int animalCount{ 0 };
	int menuChoice{ 0 };

	// vector with no element 
	vector<Animal>animals;

	do
	{
		cout << "\t1.Add animal(s)" << endl;
		cout << "\t2.Display animals" << endl;
		cout << "\t3.Exit" << endl;

		cout << "Enter Menu choice: ";
		cin >> menuChoice;

		// calling validator function
		menuChoice = validator(menuChoice);

		switch (menuChoice)
		{

			case ADD:
			{
				cin.ignore();
				enterData(animals);
				break;
			}

			case DISPLAY:
			{
				displayData(animals);
				break;
			}

			case EXIT:
			{
				cout << "Thanks for using our program " << endl << endl;
				break;
			}

			default:
			{
				cout << "INVALID!!! please enter a valid Number\n";
				break;
			}
		}

	} while (menuChoice != EXIT);

	cout << endl;

	system("pause");
	return 0;

} // end of main

string caseConversion(string animal)
{
	string lowerAnimal{};

	for (int i = 0; i < animal.size(); i++)
	{
		lowerAnimal += tolower(animal[i]);
	}

	return lowerAnimal;

} // end of function caseConversion

int validator(int number)
{
	while (cin.fail() || number <= 0)
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Invalid Choice!!!\nTry again: ";
		cin >> number;

		cout << endl;
	}
	return number;

} // end of function validator

void enterData(vector<Animal>& animals)
{
	Animal TempStruct{}; // temporary structure

	int tempCount{};
	string tempType{};
	
	do
	{
			if (animals.size() == SIZE)
			{
				cout << "The Database's full, no available space..." << endl;
			}

			else 
			{
				cout << "Enter the animal's type (none to stop): ";
				getline(cin, tempType);

				tempType = caseConversion(tempType);

				if (tempType != "none")
				{
					TempStruct.type = tempType;

					cout << "Enter the animal type's count: ";
					cin >> tempCount;

					cout << endl;

					tempCount = validator(tempCount);

					TempStruct.count = tempCount;

					animals.push_back(TempStruct); // adding record to the vector

					cin.ignore();
				}
			}

	} while (tempType != "none" && animals.size() != SIZE);

	cout << endl;

} // end of funtion enter data

void displayData(const vector<Animal> &animals)
{
	if (animals.empty())
	{
		cout << "Database is empty!!!!" << endl << endl;
	}
	else
	{
		for (int i = 0; i < animals.size(); i++)
		{
			cout << "Animal: " << animals[i].type << endl;
			cout << "Count : " << animals[i].count << endl << endl;
		}
	}

} // end of function displayData