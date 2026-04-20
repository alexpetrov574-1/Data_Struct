#include "iostream"
#include "../Header Files/DynamicArray.h"

using namespace std;

DynamicArray::DynamicArray(int size, int capacity)
{
	_size = size;
	_capacity = capacity;
	_internalArray = new int[_capacity];
}

void DynamicArray::SetSize(int size)
{
	_size = size;
}
	
void DynamicArray::SetArray(int* array)
{
	_internalArray = array;
}

/// <summary>
/// изменение размера массива
/// </summary>
/// <param name="array">Массив</param>
/// <param name="isArrayIncrement">Увеличивается ли размер массива</param>
void DynamicArray::ResizeArray()
{
	int newCapacity = _capacity + 1;
	int* newArray = new int[newCapacity];

	for (int i = 0; i < _size; ++i)
	{
		*(i + newArray) = *(i + _internalArray);
	}

	delete[] _internalArray;
	_internalArray = newArray;
	delete[] newArray;
}

void DynamicArray::AddElement(int index, int value)
{
	// Проверяем, нужно ли увеличить вместимость
	if (GetSize() >= GetCapacity())
	{
		ResizeArray();
	}

	// Сдвигаем элементы вправо для освобождения места
	for (int i = _size; i > index; --i)
	{
		*(i + _internalArray) = *((i - 1) + _internalArray);
	}

	// Вставляем новый элемент
	*(index + _internalArray) = value;
	_size++;
}

void DynamicArray::RemoveByIndex(int index) 
{
	if (index < 0 || index >= _size)
	{
		throw out_of_range("Index out of range");
	}

	// сдвижение элементов влево для заполнения пустоты
	for (int i = index; i < _size - 1; ++i)
	{
		*(i + _internalArray) = *((i + 1) + _internalArray);
	}

	_size--;
}

void DynamicArray::RemoveByValue(int value) 
{
	for (int i = 0; i < _size; ++i)
	{
		if (*(i + _internalArray) == value)
		{
			RemoveByIndex(i);
			// Удаление только первого вхождения
			return;
		}
	}
}

void DynamicArray::InsertElementInBegin(int value)
{
	AddElement(0, value);
}

void DynamicArray::InsertElementInEnd(int value)
{
	AddElement(_size, value);
}

void DynamicArray::InsertElementAfterDefinedElement(int value, 
	int valueLastDefined)
{
	// Флажок найден ли элемент
	bool elementIsFounded = false;
	// Поиск индекса элемента, после которого нужно вставить
	for (int i = 0; i < _size; ++i)
	{
		if (*(i + _internalArray) == value && !(elementIsFounded))
		{
			AddElement(i + 1, valueLastDefined);
			elementIsFounded = true;
			return;
		}
	}
	// Элемент не найден, то вывод сообщения
	if (!(elementIsFounded))
	{
		cout << "Element is not found" << endl;
	}
}

void DynamicArray::SortArray() 
{
	// Selection sort
	for (int i = 0; i < _size; ++i)
	{
		int min = _internalArray[i];
		int indexMin = i;
		for (int j = i + 1; j < _size; ++j)
		{
			if (_internalArray[j] < min)
			{
				min = _internalArray[j];
				indexMin = j;
			}
		}
		swap(_internalArray[indexMin], _internalArray[i]);
	}
}

void DynamicArray::LinearSearch(int value) 
{
	bool isElementSearched = false;

	for (int i = 0; i < _size; ++i)
	{
		if (value == *(i + _internalArray) && !(isElementSearched))
		{
			cout << "Value " << value << 
				" founded on index " << i << endl;
			isElementSearched = true;
			break;
		}
	}

	if (!(isElementSearched))
	{
		cout << "Value " << value << " didn't find" << endl;
	}
}

void DynamicArray::BinarySearch(int value)
{
	int first = 0;
	int last = _size;

	while (first < last)
	{
		int middle = (first + last) / 2;
		if (value <= _internalArray[middle])
		{
			last = middle;
		}
		else
		{
			first = middle + 1;
		}
	}

	if (first == _size || _internalArray[first] != value)
	{
		cout << "Value: " << value << " didn't found" << endl;
	}
	else
	{
		cout << "Value: " << value <<
			" searched under index: " << first << endl;
	}
}
