#pragma once
#include "RingBuffer.h"

#include <iostream>

using namespace std;

/// <summary>
/// Класс очереди, реализованной на базе кольцевого буфера.
/// </summary>
class QueueRing
{
private:
    /// <summary>
    /// Внутренний кольцевой буфер для хранения элементов очереди.
    /// </summary>
    RingBuffer* _buffer;

public:
    /// <summary>
    /// Конструктор очереди.
    /// </summary>
    /// <param name="capacity">Вместимость очереди (по умолчанию 10)</param>
    QueueRing(int capacity = 10);

    /// <summary>
    /// Деструктор очереди.
    /// Освобождает память, занятую внутренним буфером.
    /// </summary>
    ~QueueRing();

    /// <summary>
    /// Добавляет элемент в конец очереди.
    /// </summary>
    /// <param name="value">Значение для добавления</param>
    /// <returns>true если элемент успешно добавлен, false если очередь полна</returns>
    bool Enqueue(int value);

    /// <summary>
    /// Извлекает элемент из начала очереди.
    /// </summary>
    /// <param name="value">Ссылка для сохранения извлеченного значения</param>
    /// <returns>true если элемент успешно извлечен, false если очередь пуста</returns>
    bool Dequeue(int& value);

    /// <summary>
    /// Просматривает первый элемент очереди без его извлечения.
    /// </summary>
    /// <param name="value">Ссылка для сохранения значения</param>
    /// <returns>true если элемент успешно просмотрен, false если очередь пуста</returns>
    bool Peek(int& value);

    /// <summary>
    /// Проверяет, является ли очередь пустой.
    /// </summary>
    /// <returns>true если очередь пуста, иначе false</returns>
    bool IsEmpty();

    /// <summary>
    /// Проверяет, является ли очередь полной.
    /// </summary>
    /// <returns>true если очередь полна, иначе false</returns>
    bool IsFull();

    /// <summary>
    /// Возвращает текущее количество элементов в очереди.
    /// </summary>
    /// <returns>Количество элементов в очереди</returns>
    int GetSize();

    /// <summary>
    /// Возвращает максимальную вместимость очереди.
    /// </summary>
    /// <returns>Вместимость очереди</returns>
    int GetCapacity();

    /// <summary>
    /// Возвращает количество свободных мест в очереди.
    /// </summary>
    /// <returns>Количество свободных мест</returns>
    int GetFreeSpace();

    /// <summary>
    /// Изменяет размер очереди.
    /// </summary>
    /// <param name="newCapacity">Новая вместимость очереди</param>
    /// <returns>true если размер успешно изменен, false в противном случае</returns>
    bool Resize(int newCapacity);

    /// <summary>
    /// Очищает очередь, удаляя все элементы.
    /// </summary>
    void Clear();

    /// <summary>
    /// Отображает содержимое очереди.
    /// Показывает элементы в порядке их извлечения.
    /// </summary>
    void Display();

    /// <summary>
    /// Отображает детальную информацию об очереди и внутреннем буфере.
    /// </summary>
    void DisplayDetailed();
};