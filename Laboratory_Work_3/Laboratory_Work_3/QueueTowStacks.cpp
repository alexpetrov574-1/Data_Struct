#include "QueueTwoStacks.h"

#include <iostream>

using namespace std;

QueueTwoStack::QueueTwoStack(int capacity)
{
    _inStack = new Stack(capacity);
    _outStack = new Stack(capacity);
}

QueueTwoStack::~QueueTwoStack()
{
    delete _inStack;
    delete _outStack;
}

void QueueTwoStack::TransferElements()
{
    int value;
    while (!_inStack->IsEmpty())
    {
        value = _inStack->Pop();
        _outStack->Push(value);
    }
}

bool QueueTwoStack::Enqueue(int value)
{
    bool result = _inStack->Push(value);
    if (result)
    {
        cout << "Элемент: " << value << " добавлен в стек" << endl;
    }
    return result;
}

int QueueTwoStack::Dequeue()
{
    if (IsEmpty())
    {
        cout << "стек пустой" << endl;
        return -1;
    }

    if (_outStack->IsEmpty())
    {
        TransferElements();
    }

    int value = _outStack->Pop();
    if (value != -1)
    {
        cout << "Значение: " << value << " извлечено из стека" << endl;
    }
    return value;
}

bool QueueTwoStack::Peek(int& value)
{
    if (IsEmpty())
    {
        cout << "Стек пустой" << endl;
        return false;
    }

    if (_outStack->IsEmpty())
    {
        TransferElements();
    }

    bool result = _outStack->Peek(value);
    if (result)
    {
        cout << "Значение элемента стека: " << value << endl;
    }
    return result;
}

bool QueueTwoStack::IsEmpty()
{
    return _inStack->IsEmpty() && _outStack->IsEmpty();
}

bool QueueTwoStack::IsFull()
{
    return GetSize() == GetCapacity();
}

int QueueTwoStack::GetSize()
{
    return _inStack->GetSize();
}

int QueueTwoStack::GetCapacity()
{
    return _inStack->GetCapacity();
}

int QueueTwoStack::GetFreeSpace()
{
    return GetCapacity() - GetSize();
}

bool QueueTwoStack::Resize(int newCapacity)
{
    if (newCapacity < GetSize())
    {
        cout << "Новая вместимость в очереди: " << newCapacity 
            << " размер очереди: " << GetSize() << endl;
        return false;
    }

    Stack* temp = new Stack(newCapacity);

    int value = 0;

    Stack tempOutput(*_outStack);
    while (!tempOutput.IsEmpty())
    {
        value = tempOutput.Pop();
        temp->Push(value);
    }

    Stack tempInput(*_inStack);
    Stack reversedInput(newCapacity);
    while (!tempInput.IsEmpty())
    {
        value = tempInput.Pop();
        reversedInput.Push(value);
    }

    while (!reversedInput.IsEmpty())
    {
        value = reversedInput.Pop();
        temp->Push(value);
    }

    delete _inStack;
    delete _outStack;

    _inStack = new Stack(newCapacity);
    _outStack = new Stack(newCapacity);

    Stack tempReversed(newCapacity);
    while (!temp->IsEmpty())
    {
        value = temp->Pop();
        tempReversed.Push(value);
    }

    while (!tempReversed.IsEmpty())
    {
        value = tempReversed.Pop();
        _outStack->Push(value);
    }

    delete temp;
    cout << "Новая вместимость очереди: " << newCapacity << endl;
    return true;
}

void QueueTwoStack::Clear()
{
    _inStack->Clear();
    _outStack->Clear();
    cout << "Очередь очищена" << endl;
}

void QueueTwoStack::Display()
{
    cout << "Вместимость: " << GetCapacity() << endl;
    cout << "Размер: " << GetSize() << " / свободно: " 
        << GetFreeSpace() << endl;
    cout << "Пустой: " << (IsEmpty() ? "Да" : "Нет") << endl;
    cout << "Полный: " << (IsFull() ? "Да" : "Нет") << endl;

    if (IsEmpty())
    {
        cout << "Очередь пуста" << endl;
    }
    else
    {
        cout << "Входной стек:" << endl;
        _inStack->Show();
        cout << "Выходной стек:" << endl;
        _outStack->Show();
    }
}

void QueueTwoStack::DisplayDetailed()
{
    cout << "Информация о очереди:" << endl;
    Display();
}