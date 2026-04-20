#include <iostream>
#include "../Header Files/DynamicArray.h"

using namespace std;

int main()
{
	DynamicArray dynamicArray(0, 8);

	// Добавление новых элементов в массив реализуется через функцию AddElement, 
	// т.к. прямое взаимодействие недоступно

	dynamicArray.InsertElementInEnd(12);
	dynamicArray.InsertElementInEnd(3);
	dynamicArray.InsertElementInEnd(8);
	dynamicArray.InsertElementInEnd(25);

	int* insertArray = dynamicArray.GetArray();

	cout << "Current array:" << endl;
	for(int i = 0; i < dynamicArray.GetSize(); ++i)
	{
		cout << insertArray[i];
		if (i < dynamicArray.GetSize() - 1)
		{
			cout << ", ";
		}
	}
	cout << endl;

	int numberTask = 0;

    cout << "Select the action you want to do:" << endl;
	cout << "1) Remove an element by index from an array\n" << 
		"2) Remove an element by value from an array\n" << 
		"3) Insert an element at the beginning\n" << 
		"4) Insert an element at the end\n" << 
		"5) Insert after a certain element\n" << 
		"6) Sort array\n" << 
		"7) Linear search for an element in an array\n" << 
		"8) Binary search for an element in an array" << endl;

	int index;
	int value;
	while (true)
	{
		cout << "Your input: ";
		cin >> numberTask;

		switch (numberTask)
		{
		case 1:
		{
			cout << "Remove an element by index from an array" << endl;

			cout << "Please, input number-index: ";
			cin >> index;
			cout << endl;

			cout << endl;

			dynamicArray.RemoveByIndex(index);

			cout << "Current array:" << endl;
			for (int i = 0; i < dynamicArray.GetSize(); ++i)
			{
				cout << *(i + insertArray);
				if (i < dynamicArray.GetSize() - 1)
				{
					cout << ", ";
				}
			}
			cout << endl;

			break;
		}
		case 2:
		{
			cout << "Remove an element by value from an array" << endl;

			cout << "Please, input number-value: ";
			cin >> value;
			cout << endl;

			cout << endl;

			dynamicArray.RemoveByValue(value);

			cout << "Current array:" << endl;
			for (int i = 0; i < dynamicArray.GetSize(); ++i)
			{
				cout << insertArray[i];
				if (i < dynamicArray.GetSize() - 1)
				{
					cout << ", ";
				}
			}
			cout << endl;

			break;
		}
		case 3:
		{
			cout << "Insert an element at the beginning" << endl;

			cout << "Please, input number-value: ";
			cin >> value;
            cout << endl;

			cout << endl;

			dynamicArray.InsertElementInBegin(value);

			cout << "Current array:" << endl;
			for (int i = 0; i < dynamicArray.GetSize(); ++i)
			{
				cout << insertArray[i];
				if (i < dynamicArray.GetSize() - 1)
				{
					cout << ", ";
				}
			}
			cout << endl;

			break;
		}
		case 4:
		{
			cout << "Insert an element at the end" << endl;

			cout << "Please, input number-value: ";
			cin >> value;

			cout << endl;

			dynamicArray.InsertElementInEnd(value);

			cout << "Current array:" << endl;
			for (int i = 0; i < dynamicArray.GetSize(); ++i)
			{
				cout << insertArray[i];
				if (i < dynamicArray.GetSize() - 1)
				{
					cout << ", ";
				}
			}
			cout << endl;

			break;
		}
		case 5:
		{
			int valueLastDefined;

			cout << "Insert after a certain element" << endl;

			cout << "Please, input value: ";
			cin >> value;
			cout << endl;

			cout << "Please, input value, last defined: ";
			cin >> valueLastDefined;
			cout << endl;

			cout << endl;

			dynamicArray.InsertElementAfterDefinedElement(valueLastDefined, value);

			cout << "Current array:" << endl;
			for (int i = 0; i < dynamicArray.GetSize(); ++i)
			{
				cout << insertArray[i];
				if (i < dynamicArray.GetSize() - 1)
				{
					cout << ", ";
				}
			}
			cout << endl;

			break;
		}
		case 6:
		{
			cout << "Sort array" << endl;

			dynamicArray.SortArray();

			cout << "Sorting array:" << endl;
			for (int i = 0; i < dynamicArray.GetSize(); ++i)
			{
				cout << insertArray[i];
				if (i < dynamicArray.GetSize() - 1)
				{
					cout << ", ";
				}
			}
			cout << endl;
			break;
		}
		case 7:
		{
			cout << "Linear search for an element in an array" << endl;

			cout << "Please, input value for search element: ";
			cin >> value;
			cout << endl;

			dynamicArray.LinearSearch(value);

			break;
		}
		case 8:
		{
			dynamicArray.SortArray();

			cout << "Binary search for an element in an array" << endl;

			cout << "Please, input value for search element: ";
			cin >> value;
			dynamicArray.BinarySearch(value);

			break;
		}
		default:
		{
			cout << "Unknown command. Try entering the command again" << endl;
			break;
		}
		}
	}
}