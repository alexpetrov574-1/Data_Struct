#pragma once
#include "Stack.h"

/// <summary>
/// Очередь на двух стеках
/// </summary>
class QueueTwoStack
{
private:
	/// <summary>
	/// Основной стек, в который будут добавляться элементы.
	/// </summary>
	Stack* _inStack;
	
	/// <summary>
	/// Второстепенный стек, из которого будут возвращаться элементы.
	/// </summary>
	Stack* _outStack;

	/// <summary>
	/// Приватный метод для перекладывания элементов из входного стека в выходной
	/// Используется когда выходной стек пуст, а требуется операция извлечения
	/// </summary>
	void TransferElements();
public:
	
    /// <summary>
    /// Конструктор очереди на двух стеках
    /// </summary>
    /// <param name="capacity">Вместимость очереди (по умолчанию 10)</param>
    QueueTwoStack(int capacity);

    /// <summary>
    /// Деструктор очереди на двух стеках
    /// Освобождает память, занятую стеками
    /// </summary>
    ~QueueTwoStack();

    /// <summary>
    /// Добавляет элемент в конец очереди
    /// </summary>
    /// <param name="value">Значение для добавления</param>
    bool Enqueue(int value);

    /// <summary>
    /// Извлекает элемент из начала очереди
    /// </summary>
    int Dequeue();

    /// <summary>
    /// Просматривает первый элемент очереди без его извлечения
    /// </summary>
    /// <param name="value">Ссылка для сохранения значения первого элемента</param>
    bool Peek(int& value);

    /// <summary>
    /// Проверяет, является ли очередь пустой
    /// </summary>
    bool IsEmpty();

    /// <summary>
    /// Проверяет, является ли очередь полной
    /// </summary>
    bool IsFull();

    /// <summary>
    /// Возвращает текущее количество элементов в очереди
    /// </summary>
    int GetSize();

    /// <summary>
    /// Возвращает максимальную вместимость очереди
    /// </summary>
    int GetCapacity();

    /// <summary>
    /// Возвращает количество свободных мест в очереди
    /// </summary>
    int GetFreeSpace();

    /// <summary>
    /// Изменяет размер очереди
    /// </summary>
    /// <param name="newCapacity">Новая вместимость очереди</param>
    bool Resize(int newCapacity);

    /// <summary>
    /// Очищает очередь, удаляя все элементы
    /// </summary>
    void Clear();

    /// <summary>
    /// Отображает содержимое очереди в компактном формате
    /// Показывает основные параметры и элементы в порядке извлечения
    /// </summary>
    void Display();

    /// <summary>
    /// Отображает детальную информацию об очереди
    /// Включает состояние обоих стеков и принцип работы
    /// </summary>
    void DisplayDetailed();
};
