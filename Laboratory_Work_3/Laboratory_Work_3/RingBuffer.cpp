#include "RingBuffer.h"
#include <iostream>

using namespace std;

/// <summary>
/// Конструктор кольцевого буфера.
/// </summary>
/// <param name="initialCapacity">Начальная вместимость буфера</param>
RingBuffer::RingBuffer(int initialCapacity)
{
    capacity = initialCapacity;
    head = 0;
    tail = 0;
    count = 0;
    buffer = new int[capacity];
    cout << "Кольцевой буфер создан с вместимостью: " << capacity << endl;
}

/// <summary>
/// Деструктор кольцевого буфера.
/// </summary>
RingBuffer::~RingBuffer()
{
    delete[] buffer;
    cout << "Кольцевой буфер уничтожен" << endl;
}

/// <summary>
/// Добавляет элемент в буфер.
/// Элемент помещается в позицию tail, после чего tail перемещается вперед.
/// При достижении конца массива tail переходит в начало.
/// </summary>
/// <param name="value">Значение для добавления</param>
bool RingBuffer::Enqueue(int value)
{
    if (IsFull())
    {
        cout << "Буфер полон! Перезаписываем самый старый элемент " << buffer[head] << " на " << value << endl;

        buffer[tail] = value;
        head = (head + 1) % capacity;
        tail = (tail + 1) % capacity;

        cout << "Элемент " << value << " добавлен в буфер" << endl;
        return true;
    }

    buffer[tail] = value;
    tail = (tail + 1) % capacity;
    count++;

    cout << "Элемент " << value << " добавлен в буфер" << endl;
    return true;
}

/// <summary>
/// Извлекает элемент из буфера.
/// Элемент берется из позиции head, после чего head перемещается вперед.
/// При достижении конца массива head переходит в начало.
/// </summary>
/// <param name="value">Ссылка для сохранения извлеченного значения</param>
bool RingBuffer::Dequeue(int& value)
{
    if (IsEmpty())
    {
        cout << "Ошибка: Буфер пуст! Нечего извлекать" << endl;
        return false;
    }

    value = buffer[head];
    head = (head + 1) % capacity;
    count--;

    cout << "Элемент " << value << " извлечен из буфера" << endl;
    return true;
}

/// <summary>
/// Возвращает количество свободных мест в буфере.
/// </summary>
int RingBuffer::GetFreeSpace()
{
    return capacity - count;
}

/// <summary>
/// Возвращает количество занятых мест в буфере.
/// </summary>
int RingBuffer::GetUsedSpace()
{
    return count;
}

/// <summary>
/// Проверяет, является ли буфер пустым.
/// </summary>
bool RingBuffer::IsEmpty()
{
    return count == 0;
}

/// <summary>
/// Проверяет, является ли буфер полным.
/// </summary>
bool RingBuffer::IsFull()
{
    return count == capacity;
}

/// <summary>
/// Просматривает первый элемент без его извлечения.
/// Возвращает элемент на который указывает head.
/// </summary>
/// <param name="value">Ссылка для сохранения значения</param>
bool RingBuffer::Peek(int& value)
{
    if (IsEmpty())
    {
        cout << "Ошибка: Буфер пуст! Нечего просматривать" << endl;
        return false;
    }

    value = buffer[head];
    cout << "Первый элемент в буфере: " << value << endl;
    return true;
}

/// <summary>
/// Изменяет размер буфера.
/// Создает новый массив и копирует в него существующие элементы в правильном порядке.
/// </summary>
/// <param name="newCapacity">Новая вместимость буфера</param>
bool RingBuffer::Resize(int newCapacity)
{
    if (newCapacity < count)
    {
        cout << "Ошибка: Новый размер (" << newCapacity << ") меньше текущего количества элементов (" << count << ")" << endl;
        return false;
    }

    int* newBuffer = new int[newCapacity];

    for (int i = 0; i < count; i++)
    {
        newBuffer[i] = buffer[(head + i) % capacity];
    }

    delete[] buffer;

    buffer = newBuffer;
    head = 0;
    tail = count;

    cout << "Размер буфера изменен с " << capacity << " на " << newCapacity << endl;
    capacity = newCapacity;
    return true;
}

/// <summary>
/// Получает текущую вместимость буфера.
/// </summary>
int RingBuffer::GetCapacity()
{
    return capacity;
}

/// <summary>
/// Очищает буфер, удаляя все элементы.
/// </summary>
void RingBuffer::Clear()
{
    head = 0;
    tail = 0;
    count = 0;
    cout << "Буфер очищен" << endl;
}

/// <summary>
/// Отображает содержимое буфера.
/// Показывает расположение элементов в массиве с указанием head и tail.
/// </summary>
void RingBuffer::Display()
{
    cout << "Расположение элементов буфера" << endl;
    cout << "Вместимость: " << capacity << endl;
    cout << "Занято: " << count << " / Свободно: " << GetFreeSpace() << endl;
    cout << "Head: " << head << ", Tail: " << tail << endl;

    cout << "Индексы:  ";
    for (int i = 0; i < capacity; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Значения: ";
    for (int i = 0; i < capacity; i++)
    {
        if (i == head && i == tail && !IsEmpty())
        {
            cout << "H/T ";
        }
        else if (i == head)
        {
            cout << "H   ";
        }
        else if (i == tail)
        {
            cout << "T   ";
        }
        else
        {
            cout << "    ";
        }
    }
    cout << endl;

    cout << "          ";
    for (int i = 0; i < capacity; i++)
    {
        bool hasData = false;
        if (!IsEmpty())
        {
            if (head < tail)
            {
                hasData = (i >= head && i < tail);
            }
            else
            {
                hasData = (i >= head || i < tail);
            }
        }

        if (hasData)
        {
            cout << buffer[i] << " ";
        }
        else
        {
            cout << "[ ] ";
        }
    }
    cout << endl;
}

/// <summary>
/// Отображает логическое содержимое буфера.
/// </summary>
void RingBuffer::DisplayLogical()
{
    cout << "Кольцевой Буфер" << endl;

    if (IsEmpty())
    {
        cout << "Буфер пуст" << endl;
        return;
    }

    cout << "Элементы (порядок извлечения): ";
    for (int i = 0; i < count; i++)
    {
        int index = (head + i) % capacity;
        cout << buffer[index];
        if (i < count - 1)
        {
            cout << " -> ";
        }
    }
    cout << endl;
    cout << "Количество элементов: " << count << endl;
}