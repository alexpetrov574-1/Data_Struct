
#include "QueueRing.h"
#include <iostream>

using namespace std;

/// <summary>
/// Конструктор очереди.
/// Создает внутренний кольцевой буфер заданной вместимости.
/// </summary>
/// <param name="capacity">Вместимость очереди</param>
QueueRing::QueueRing(int capacity)
{
    _buffer = new RingBuffer(capacity);
    cout << "Очередь на кольцевом буфере создана с вместимостью: " << capacity << endl;
}

/// <summary>
/// Деструктор очереди.
/// </summary>
QueueRing::~QueueRing()
{
    delete _buffer;
    cout << "Очередь на кольцевом буфере уничтожена" << endl;
}

/// <summary>
/// Добавляет элемент в конец очереди.
/// Использует метод Enqueue внутреннего буфера.
/// </summary>
/// <param name="value">Значение для добавления</param>
bool QueueRing::Enqueue(int value)
{
    bool result = _buffer->Enqueue(value);
    if (result)
    {
        cout << "Элемент " << value << " добавлен в очередь" << endl;
    }
    return result;
}

/// <summary>
/// Извлекает элемент из начала очереди.
/// Использует метод Dequeue внутреннего буфера.
/// </summary>
/// <param name="value">Ссылка для сохранения извлеченного значения</param>
bool QueueRing::Dequeue(int& value)
{
    bool result = _buffer->Dequeue(value);
    if (result)
    {
        cout << "Элемент " << value << " извлечен из очереди" << endl;
    }
    return result;
}

/// <summary>
/// Просматривает первый элемент очереди без его извлечения.
/// Использует метод Peek внутреннего буфера.
/// </summary>
/// <param name="value">Ссылка для сохранения значения</param>
bool QueueRing::Peek(int& value)
{
    bool result = _buffer->Peek(value);
    if (result)
    {
        cout << "Первый элемент в очереди: " << value << endl;
    }
    return result;
}

/// <summary>
/// Проверяет, является ли очередь пустой.
/// Использует метод IsEmpty внутреннего буфера.
/// </summary>
bool QueueRing::IsEmpty()
{
    return _buffer->IsEmpty();
}

/// <summary>
/// Проверяет, является ли очередь полной.
/// Использует метод IsFull внутреннего буфера.
/// </summary>
bool QueueRing::IsFull()
{
    return _buffer->IsFull();
}

/// <summary>
/// Возвращает текущее количество элементов в очереди.
/// Использует метод GetUsedSpace внутреннего буфера.
/// </summary>
int QueueRing::GetSize()
{
    return _buffer->GetUsedSpace();
}

/// <summary>
/// Возвращает максимальную вместимость очереди.
/// Использует метод GetCapacity внутреннего буфера.
/// </summary>
int QueueRing::GetCapacity()
{
    return _buffer->GetCapacity();
}

/// <summary>
/// Возвращает количество свободных мест в очереди.
/// Использует метод GetFreeSpace внутреннего буфера.
/// </summary>
int QueueRing::GetFreeSpace()
{
    return _buffer->GetFreeSpace();
}

/// <summary>
/// Изменяет размер очереди.
/// Использует метод Resize внутреннего буфера.
/// </summary>
/// <param name="newCapacity">Новая вместимость очереди</param>
bool QueueRing::Resize(int newCapacity)
{
    bool result = _buffer->Resize(newCapacity);
    if (result)
    {
        cout << "Размер очереди изменен на: " << newCapacity << endl;
    }
    return result;
}

/// <summary>
/// Очищает очередь, удаляя все элементы.
/// Использует метод Clear внутреннего буфера.
/// </summary>
void QueueRing::Clear()
{
    _buffer->Clear();
    cout << "Очередь очищена" << endl;
}

/// <summary>
/// Отображает содержимое очереди.
/// Показывает элементы в порядке их извлечения.
/// </summary>
void QueueRing::Display()
{
    cout << "Состояние Очереди" << endl;
    cout << "Вместимость: " << GetCapacity() << endl;
    cout << "Размер: " << GetSize() << " / Свободно: " << GetFreeSpace() << endl;
    cout << "Пустой: " << (IsEmpty() ? "Да" : "Нет") << endl;
    cout << "Полный: " << (IsFull() ? "Да" : "Нет") << endl;

    _buffer->DisplayLogical();
}

/// <summary>
/// Отображает детальную информацию об очереди и внутреннем буфере.
/// </summary>
void QueueRing::DisplayDetailed()
{
    cout << "Детальная информация об Очереди" << endl;
    Display();
    _buffer->Display();
}