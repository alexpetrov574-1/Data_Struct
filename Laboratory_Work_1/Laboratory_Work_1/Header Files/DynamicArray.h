#pragma once

//! \brief Структура динамического массива
struct DynamicArray
{
private:
    /// <summary>
    /// Размер массива
    /// </summary>
    int _size;

    /// <summary>
    /// Вместимость массива
    /// </summary>
    int _capacity;

    /// <summary>
    /// Указатель на массив
    /// </summary>
    int* _internalArray;

public:
    /// <summary>
    /// Конструктор для инициализации динамического массива
    /// </summary>
    /// <param name="size">Размер массива</param>
    /// <param name="capacity">Вместимость массива</param>
    DynamicArray(int size, int capacity);

    /// <summary>
    /// Функция, получающая размер массива
    /// </summary>
    /// <returns>размер массива</returns>
    int GetSize() { return _size; }

    /// <summary>
    /// Функция-сеттер, присваивающая размер массива
    /// </summary>
    /// <param name="size">Размер массива</param>
    void SetSize(int size);

    /// <summary>
    /// Функция, получающая вместимость для массива
    /// </summary>
    /// <returns>вместимость массива</returns>
    int GetCapacity() { return _capacity; }

    /// <summary>
    /// Функция, получающая внутренний массив
    /// </summary>
    /// <returns>внутренний</returns>
    int* GetArray() { return _internalArray; }

    /// <summary>
    /// Функция-сеттер, присваивающая внутренний массив
    /// </summary>
    /// <param name="internalArray"></param>
    void SetArray(int* internalArray);

    /// <summary>
    /// Изменение размера массива до максимально возможного
    /// </summary>
    /// <param name="isArrayIncrement">Увеличивается ли размер массива</param>
    void ResizeArray();

    /// <summary>
    /// Добавление элемента в массив
    /// </summary>
    /// <param name="index">Индекс элемента, которого надо добавить в массив</param>
    /// <param name="value">Значение элемента массива</param>
    void AddElement(int index, int value);

    /// <summary>
    /// Удаление элемента из массива по индексу
    /// </summary>
    /// <param name="index">Индекс элемента, которого надо удалить из массива</param>
    void RemoveByIndex(int index);

    /// <summary>
    /// Удаляет элемент массива по передаваемому значению
    /// </summary>
    /// <param name="value">Значение элемента, которого нужно удалить из массива</param>
    void RemoveByValue(int value);

    /// <summary>
    /// Вставка элемента в начало массива
    /// </summary>
    /// <param name="value">Значение элемента которого нужно вставить в начало массива</param>
    void InsertElementInBegin(int value);

    /// <summary>
    /// Вставка элемента в конец массива.
    /// </summary>
    /// <param name="value">Значение элемента, которого нужно вставить в конец массива</param>
    void InsertElementInEnd(int value);

    /// <summary>
    /// Вставка элемента после определенного элемента
    /// </summary>
    /// <param name="value">Значение элемента, которого нужно вставить после определенного элемента</param>
    /// <param name="valueLastDefined">Значение элемента, после которого нужно вставить value</param>
    void InsertElementAfterDefinedElement(int value, int valueLastDefined);

    /// <summary>
    /// Сортировка массива
    /// Нам дан 2 вариант - сортировка выбором (Selection Sort)
    /// </summary>
    void SortArray();

    /// <summary>
    /// Линейный поиск
    /// </summary>
    /// <param name="value">Искомое значение</param>
    void LinearSearch(int value);

    /// <summary>
    /// Бинарный поиск
    /// </summary>
    /// <param name="value">Искомое значение</param>
    void BinarySearch(int value);
};