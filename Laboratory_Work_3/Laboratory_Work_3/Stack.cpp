#include "Stack.h"
#include <iostream>

using namespace std;

/// <summary>
/// Конструктор стека.
/// </summary>
Stack::Stack(int startCapacity)
{
    _top = nullptr;
    _capacity = startCapacity;
    _currentSize = 0;
}

/// <summary>
/// Деструктор стека.
/// </summary>
Stack::~Stack()
{
    Clear();
};

/// <summary>
/// Проверяет, является ли стек полным.
/// </summary>
bool Stack::isFullInternal()
{
    return _currentSize >= _capacity;
};

/// <summary>
/// Добавляет элемент на вершину стека.
/// Создает новый узел, устанавливает его как новую вершину стека.
/// </summary>
/// <param name="value">Значение для добавления в стек</param>
bool Stack::Push(int value)
{
    if (isFullInternal())
    {
        cout << "Ошибка: Стек полон! Не удалось добавить элемент " << value << endl;
        return false;
    }

    Node* newNode = new Node(value);

    newNode->SetNext(_top);
    _top = newNode;
    _currentSize++;

    return true;
}

int Stack::Pop() 
{
    if (IsEmpty())
    {
        cout << "Ошибка: Стек пуст!" << endl;
        return -1; // Специальное значение для обозначения ошибки
    }

    int value = _top->GetData();
    _top = _top->GetNext();

    _currentSize--;

    cout << "Осталось элементов : " << _currentSize << endl;
    return value;
}

bool Stack::Peek(int& value)
{
    if (IsEmpty())
    {
        cout << "Ошибка: Стек пуст! Нечего просматривать" << endl;
        return false;
    }

    value = _top->GetData();
    cout << "Вершина стека: " << value << endl;
    return true;
}

bool Stack::IsEmpty()
{
    return _top == nullptr;
}

bool Stack::IsFull()
{
    return isFullInternal();
}

int Stack::GetSize()
{
    return _currentSize;
}

int Stack::GetCapacity()
{
    return _capacity;
}

void Stack::Clear()
{
    int value;
    while (!IsEmpty())
    {
        Pop();
    }
    cout << "Стек очищен" << endl;
}

void Stack::Show() 
{
    if (IsEmpty())
    {
        cout << "Стек пуст" << endl;
        return;
    }

    cout << "Содержимое стека (от вершины к основанию): ";
    Node* current = _top;
    while (current != nullptr)
    {
        cout << current->GetData();
        if (current->GetNext() != nullptr)
        {
            cout << " -> ";
        }
        current = current->GetNext();
    }
    cout << endl;
    cout << "Размер: " << _currentSize << "/" << _capacity << endl;
}