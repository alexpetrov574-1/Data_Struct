
#pragma once

/// <summary>
/// Класс реализующий кольцевой буфер фиксированного размера.
/// Использует массив и два указателя (head и tail) для циклического доступа.
/// </summary>
class RingBuffer
{
private:
    /// <summary>
    /// Массив для хранения элементов буфера.
    /// </summary>
    int* buffer;

    /// <summary>
    /// Максимальная вместимость буфера.
    /// </summary>
    int capacity;

    /// <summary>
    /// Указатель на начало.
    /// </summary>
    int head;

    /// <summary>
    /// Указатель на конец.
    /// </summary>
    int tail;

    /// <summary>
    /// Текущее количество элементов в буфере.
    /// </summary>
    int count;

public:
    /// <summary>
    /// Конструктор кольцевого буфера.
    /// </summary>
    /// <param name="initialCapacity">Начальная вместимость буфера (по умолчанию 10)</param>
    RingBuffer(int initialCapacity = 10);

    /// <summary>
    /// Деструктор кольцевого буфера.
    /// Освобождает память, занятую буфером.
    /// </summary>
    ~RingBuffer();

    /// <summary>
    /// Добавляет элемент в буфер.
    /// </summary>
    /// <param name="value">Значение для добавления</param>
    /// <returns>true если элемент успешно добавлен, false если буфер полон</returns>
    bool Enqueue(int value);

    /// <summary>
    /// Извлекает элемент из буфера.
    /// </summary>
    /// <param name="value">Ссылка для сохранения извлеченного значения</param>
    /// <returns>true если элемент успешно извлечен, false если буфер пуст</returns>
    bool Dequeue(int& value);

    /// <summary>
    /// Возвращает количество свободных мест в буфере.
    /// </summary>
    int GetFreeSpace();

    /// <summary>
    /// Возвращает количество занятых мест в буфере.
    /// </summary>
    int GetUsedSpace();

    /// <summary>
    /// Проверяет, является ли буфер пустым.
    /// </summary>
    bool IsEmpty();

    /// <summary>
    /// Проверяет, является ли буфер полным.
    /// </summary>
    bool IsFull();

    /// <summary>
    /// Просматривает первый элемент без его извлечения.
    /// </summary>
    /// <param name="value">Ссылка для сохранения значения</param>
    bool Peek(int& value);

    /// <summary>
    /// Изменяет размер буфера.
    /// </summary>
    /// <param name="newCapacity">Новая вместимость буфера</param>
    bool Resize(int newCapacity);

    /// <summary>
    /// Получает текущую вместимость буфера.
    /// </summary>
    int GetCapacity();

    /// <summary>
    /// Очищает буфер, удаляя все элементы.
    /// </summary>
    void Clear();

    /// <summary>
    /// Отображает содержимое буфера.
    /// Показывает физическое расположение элементов в массиве.
    /// </summary>
    void Display();

    /// <summary>
    /// Отображает логическое содержимое буфера.
    /// Показывает элементы в порядке их извлечения.
    /// </summary>
    void DisplayLogical();
};
