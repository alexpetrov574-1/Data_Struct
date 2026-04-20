#include <iostream>
#include <string>

using namespace std;

struct Person
{
	//! Имя человека
	string FirstName;
	//! Фамилия человека
	string LastName;
	//! Возраст человека
	unsigned Age;
};

void BreakpointsFirst()
{
	double add = 1.0;
	double sum = 0.0;

	for (int i = 0; i < 10; i++)
	{
		sum += add * i;
		add *= 1.1;
	}
	cout << "Total sum is " << sum << endl;
}
void Breakpoints()
{
	double add = 1.0;
	double sum = 0.0;

	for (int i = 0; i < 1000; i++)
	{
		sum += add * i;
		if (i % 3 == 0)
		{
			add *= 1.1;
		}
		else
		{
			add /= 3.0;
		}
	}
	cout << "Total sum is " << sum << endl;
}

double GetPower(double base, int exponent)
{
	double numberObtainedFromExponent = base;
	for (int i = 1; i < exponent; i++)
	{
		numberObtainedFromExponent *= base;
	}
	return numberObtainedFromExponent;
}

void DemoGetPower(double base, int exponent)
{
	double result = GetPower(base, exponent);
	cout << base << " ^ " << exponent << " = " << result << endl;
}

void RoundToTens(int& value)
{
	int divisionRemainder = value % 10;
	if (divisionRemainder < 5)
	{
		value = value / 10 * 10;
	}
	else
	{
		value = value / 10 * 10 + 10;
	}
	cout << value << endl;
}

void Foo(double a)
{
	cout << "Address of a in Foo(): " << &a << endl;
	cout << "Value of a in Foo(): " << a << endl;

	a = 15.0;
	cout << "New value of a in Foo(): " << a << endl;
	cout << "Address in pointer: " << a << endl;
}

void Foo(double* a)
{
	cout << "Address of a in Foo(): " << &a << endl;
	cout << "Value of a in Foo(): " << a << endl;

	*a = 15.0;
	cout << "New value of a in Foo(): " << a << endl;
}

int* MakeRandomArray(int arraySize)
{
	int* randomArray = new int[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		*(randomArray + i) = rand() % 100 + 0;
	}
	return randomArray;
}

void WritePerson(const Person& person)
{
	cout << "First name: " + person.FirstName
		+ "; Last name: " + person.LastName
		+ "; Age: " + to_string(person.Age)
		<< endl;
}

void ClearPerson(Person* person)
{
	delete person;
}

const int PeopleCount = 5;

Person** CreatePeopleArray()
{
	Person** people = new Person * [PeopleCount];
	people[0] = new Person();
	people[0]->FirstName = "Casey";
	people[0]->LastName = "Aguilar";
	people[0]->Age = 30;

	people[1] = new Person();
	people[1]->FirstName = "Brock";
	people[1]->LastName = "Curtis";
	people[1]->Age = 19;

	people[2] = new Person();
	people[2]->FirstName = "Blake";
	people[2]->LastName = "Diaz";
	people[2]->Age = 21;

	people[3] = new Person();
	people[3]->FirstName = "Cristian";
	people[3]->LastName = "Evans";
	people[3]->Age = 55;

	people[4] = new Person();
	people[4]->FirstName = "Les";
	people[4]->LastName = "Foss";
	people[4]->Age = 4;

	return people;
}

void ClearPeople(Person** people, int itemsCount)
{
	for (int i = 0; i < itemsCount; i++)
	{
		ClearPerson(people[i]);
	}
	delete[] people;
}

void Task1FindPersonByLastName()
{
	Person** people = CreatePeopleArray();
	for (int i = 0; i < PeopleCount; i++)
	{
		WritePerson(*people[i]);
	}
	string lastName;
	cout << "Enter last name: ";
	cin >> lastName;
	int foundIndex = -1;

	for (int i = 0; i < PeopleCount; i++)
	{
		if (lastName == people[i]->LastName)
		{
			foundIndex = i;
		}
	}

	if (foundIndex == -1)
	{
		cout << "Could not find a person by last name: " << lastName << endl;
	}
	else
	{
		cout << "A person's last name " << lastName <<
			" was found. Its index in the array is "
			<< foundIndex << endl;
	}

	ClearPeople(people, PeopleCount);
}

int main()
{
	while (true)
	{
		int numberTask = 0;
		cout << "Input number of task 1 to 6: ";
		cin >> numberTask;
		switch (numberTask)
		{
		case 1:
		{
			cout << "1 Task:" << endl;
			// Сумма на 1-й итерации 0
			BreakpointsFirst();
			// Сумма на 777-й итерации 3.2624579394327844
			Breakpoints();
			break;
		}
		case 2:
		{
			cout << "2 Task:" << endl;
			int numbers[10] = { 150, 21, 50, 500, 90, 88, 37, 45, 60, 73 };
			cout << "Source array:" << endl;
			for (int i = 0; i < 10; i++)
			{
				cout << numbers[i] << ' ';
			}
			cout << endl;
			// сортировка вставками эффективнее, чем метод сортировки пузырьком
			int key, j;
			for (int i = 1; i < 10; i++)
			{
				key = numbers[i];
				j = i - 1;

				while (j >= 0 && numbers[j] > key)
				{
					numbers[j + 1] = numbers[j];
					j = j - 1;
				}
				numbers[j + 1] = key;
			}
			cout << "Sorted array is:" << endl;
			for (int i = 0; i < 10; i++)
			{
				cout << numbers[i] << ' ';
			}
			cout << endl;

			double floatNumbers[12] = { 15.0, 25.6, 195.2, -80.7, 305.0, 79.5,
				80.3, 9.1, 47.3, 31.2, 85.3, 100.1 };
			cout << "Source array:\n";
			for (int i = 0; i < 12; i++)
			{
				cout << floatNumbers[i] << ' ';
			}
			cout << "\n";
			double searchingValue;
			cout << "Please, input float number for search: ";
			cin >> searchingValue;
			cout << "\n";
			int countNumbersInArrayIfAreMoreThanSearchingValue = 0;
			for (int i = 0; i < 12; i++)
			{
				if (floatNumbers[i] > searchingValue)
				{
					countNumbersInArrayIfAreMoreThanSearchingValue++;
				}
			}
			cout << "Elements of array more than " << searchingValue <<
				" is (count): " << countNumbersInArrayIfAreMoreThanSearchingValue << endl;
			char arrayFromChars[8];
			char elementForArray;
			cout << "Enter array of 8 chars" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << "a[" << i << "]: ";
				cin >> elementForArray;
				arrayFromChars[i] = elementForArray;
			}
			cout << "Your array is:" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << arrayFromChars[i] << ' ';
			}
			cout << endl;
			cout << "All letters in your array:" << endl;
			for (int i = 0; i < 8; i++)
			{
				if ((arrayFromChars[i] >= 'A' && arrayFromChars[i] <= 'Z')
					|| (arrayFromChars[i] >= 'a' && arrayFromChars[i] <= 'z'))
				{
					cout << arrayFromChars[i] << ' ';
				}
			}
			cout << endl;
			break;
		}
		case 3:
		{
			cout << "3 Task:" << endl;
			DemoGetPower(2.0, 5);
			DemoGetPower(3.0, 4);
			DemoGetPower(-2.0, 5);

			cout << endl;

			int a = 14;
			cout << "For " << a << " rounded value is ";
			RoundToTens(a);
			a = 191;
			cout << "For " << a << " rounded value is ";
			RoundToTens(a);
			a = 27;
			cout << "For " << a << " rounded value is ";
			RoundToTens(a);
			break;
		}
		case 4:
		{
			cout << "4 Task:" << endl;
			int a = 5;
			int b = 4;
			cout << "Address of a: " << &a << endl;
			cout << "Address of b: " << &b << endl;

			double c = 13.5;
			cout << "Address of c: " << &c << endl;

			bool d = true;
			cout << "Address of d: " << &d << endl;

			int aArray[10] = { 1, 2, 7, -1, 5, 3, -1, 7, 1, 6 };
			cout << "Size of int type: " << sizeof(int) << endl;

			for (int i = 0; i < 10; i++)
			{
				cout << "Address of a[" << i << "]: " << &aArray[i] << endl;
			}

			cout << endl;
			cout << "Size of double type: " << sizeof(double) << endl;
			double bArray[10] = { 1.0, 2.0, 7.0, -1.0, 5.0, 3.5, -1.8, 7.2, 1.9, 6.2 };
			for (int i = 0; i < 10; i++)
			{
				cout << "Address of b[" << i << "]: " << bArray[i] << endl;
			}

			a = 5;
			int& b1 = a;

			cout << "Address of a: " << &a << endl;
			cout << "Address of b1: " << &b1 << endl;

			cout << endl;
			b1 = 7;
			cout << "Value of a: " << a << endl;

			double a1 = 5.0;
			cout << "Address of a in main(): " << &a1 << endl;
			cout << "Value of a in main(): " << a1 << endl;
			cout << endl;

			Foo(a1);

			cout << endl;
			cout << "Value of a in main(): " << a1 << endl;


			a = 5;
			int* pointer = &a;

			cout << "Address of a: " << &a << endl;
			cout << "Address in pointer: " << pointer << endl;
			cout << "Address of pointer: " << &pointer << endl;

			cout << endl;
			*pointer = 7;
			cout << "Value in a: " << a << endl;
			cout << "Value by pointer address: " << *pointer << endl;
			double value = 5.0;
			double* pointer1 = &value;
			cout << "Address of value in main(): " << &value << endl;
			cout << "Address in pointer in main(): " << pointer1 << endl;
			cout << "Address of pointer in main(): " << &pointer1 << endl;
			cout << "Value of a in main(): " << value << endl;
			cout << endl;

			Foo(pointer1);

			cout << endl;
			cout << "Value of a in main(): " << value << endl;
			break;
		}
		case 5:
		{
			cout << "5 Task:" << endl;
			// 1 пункт
			double* arrayOfDoubleNumbers = new double[8]
				{1.0, 15.0, -8.2, -3.5, 12.6, 38.4, -0.5, 4.5};
			cout << "Array of double:" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << arrayOfDoubleNumbers[i] << " ";
			}
			cout << endl;
			delete[] arrayOfDoubleNumbers;

			cout << endl;

			// 2 пункт
			bool* arrayOfBoolElements = new bool[8]
				{true, false, true, true, false, true, false, false};
			cout << "Array of bool:" << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << arrayOfBoolElements[i] << " ";
			}
			cout << endl;
			delete[] arrayOfBoolElements;

			cout << endl;

			// 3 пункт
			int n;
			cout << "Enter char array size: ";
			cin >> n;
			char* arrayOfCharsElements = new char[n];
			for (int i = 0; i < n; i++)
			{
				cout << "Enter a[" << i << "]: ";
				cin >> *(arrayOfCharsElements + i);
			}
			cout << "Your char array is: " << endl;
			for (int i = 0; i < n; i++)
			{
				cout << *(arrayOfCharsElements + i) << " ";
			}
			cout << endl;
			delete[] arrayOfCharsElements;

			cout << endl;

			// 4 пункт
			arrayOfDoubleNumbers = new double[10]
				{1.0, 15.0, -8.2, -3.5, 12.6, 38.4, -0.5, 4.5, 16.7, 4.5};
			cout << "Array of double:" << endl;
			for (int i = 0; i < 10; i++)
			{
				cout << arrayOfDoubleNumbers[i] << " ";
			}
			cout << endl;
			cout << "Sorted array of double:" << endl;
			double key;
			int j;
			for (int i = 0; i < 10; i++)
			{
				key = arrayOfDoubleNumbers[i];
				j = i;
				while (arrayOfDoubleNumbers[j - 1] > key && j > 0)
				{
					arrayOfDoubleNumbers[j] = arrayOfDoubleNumbers[j - 1];
					j = j - 1;
				}
				arrayOfDoubleNumbers[j] = key;
			}
			for (int i = 0; i < 10; i++)
			{
				cout << arrayOfDoubleNumbers[i] << " ";
			}
			cout << "\n";
			cout << endl;
			delete[] arrayOfDoubleNumbers;

			// 5 пункт
			int* arrayOfIntElements = new int[10]
				{1, 15, -8, -3, 12, 38, 0, 4, 16, 4};
			cout << "Int array:" << endl;
			for (int i = 0; i < 10; i++)
			{
				cout << arrayOfIntElements[i] << " ";
			}
			cout << endl;
			int searchingValue;
			cout << "Enter searching value: ";
			cin >> searchingValue;
			cout << "\n";
			cout << "Index of searching value " << searchingValue << " is: ";
			int countNumbersInArrayIfAreMoreThanSearchingValue = 0;
			for (int i = 0; i < 12; i++)
			{
				if (*(arrayOfIntElements + i) == searchingValue)
				{
					cout << i;
					break;
				}
			}
			cout << endl;
			cout << endl;
			delete[] arrayOfIntElements;

			// 6 пункт
			arrayOfCharsElements = new char[15]
				{'a', '5', 'm', 'i', '%', '!', 's', 'p', '*', '9', 'f', '^', ';',
				'q', 'k'};
			int counterOfCharsElementsIfAreLetters = 0;
			cout << "Char array is:" << endl;
			for (int i = 0; i < 15; i++)
			{
				cout << arrayOfCharsElements[i] << " ";
			}
			cout << endl;
			cout << "Letters in array:" << endl;
			for (int i = 0; i < 15; i++)
			{
				if (arrayOfCharsElements[i] > 'a' &&
					arrayOfCharsElements[i] < 'z')
				{
					cout << arrayOfCharsElements[i] << ' ';
					counterOfCharsElementsIfAreLetters++;
				}
			}
			cout << endl;
			cout << "Count of letters in array: " <<
				counterOfCharsElementsIfAreLetters << endl;
			delete[] arrayOfCharsElements;
			cout << endl;

			// 7 пункт
			cout << "Random array of 5:" << endl;
			int* randomArray = MakeRandomArray(5);
			for (int i = 0; i < 5; i++)
			{
				cout << randomArray[i] << " ";
			}
			cout << endl;
			cout << endl;
			delete[] randomArray;

			cout << "Random array of 8:" << endl;
			randomArray = MakeRandomArray(8);
			for (int i = 0; i < 8; i++)
			{
				cout << randomArray[i] << " ";
			}
			cout << endl;
			cout << endl;
			delete[] randomArray;

			cout << "Random array of 13:" << endl;
			randomArray = MakeRandomArray(13);
			for (int i = 0; i < 13; i++)
			{
				cout << randomArray[i] << " ";
			}
			cout << endl;
			delete[] randomArray;
			cout << endl;
			break;
		}
		case 6:
		{
			cout << "6 Task:" << endl;
			Task1FindPersonByLastName();
			break;
		}
		default:
		{
			cout << "Wrong number of Task." <<
				"Please input correct number from 1 to 6" << endl;
			break;
		}
		}
	}
}