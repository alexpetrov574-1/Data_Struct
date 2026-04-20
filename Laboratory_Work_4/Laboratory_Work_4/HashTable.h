#pragma once

#include <string>
#include <vector>

using namespace std;

/// <summary>
/// Класс HashTable с методом цепочек для разрешения коллизий
/// Использует хеш-функцию Пирсона для вычисления индексов
/// </summary>
class HashTable {
private:
    /// <summary>
    /// Структура узла для хранения пары ключ-значение в цепочке
    /// </summary>
    struct Node {
        /// <summary>
        /// Ключ элемента.
        /// </summary>
        string Key;
        /// <summary>
        /// Значение элемента.
        /// </summary>
        string Value;

        /// <summary>
        /// Следующий узел.
        /// </summary>
        Node* Next;

        /// <summary>
        /// Конструктор узла
        /// </summary>
        /// <param name="k">Ключ</param>
        /// <param name="v">Значение</param>
        Node(string& k, string& v);
    };

    /// <summary>
    /// Массив указателей на цепочки.
    /// </summary>
    vector<Node*> Table;

    /// <summary>
    /// Вместимость таблицы.
    /// </summary>
    int Capacity;

    /// <summary>
    /// Количество элементов в таблице.
    /// </summary>
    int Size;

    /// <summary>
    /// Порог заполнения для перехеширования
    /// </summary>
    static const double LOAD_FACTOR_THRESHOLD;

    /// <summary>
    /// Вычисляет хеш-код для ключа с использованием алгоритма Пирсона
    /// </summary>
    /// <param name="key">Ключ для хеширования</param>
    /// <param name="showProcess">Флаг отображения процесса вычисления</param>
    /// <param name="hashSteps">Вектор для сохранения шагов хеширования</param>
    int PearsonHash(string& key, bool showProcess, vector<string>& hashSteps);

    /// <summary>
    /// Разрешает коллизию в цепочке, добавляя новый узел или обновляя существующий
    /// </summary>
    /// <param name="head">Голова цепочки</param>
    /// <param name="key">Ключ</param>
    /// <param name="value">Значение</param>
    /// <returns>Новая голова цепочки или nullptr при дубликате key-value</returns>
    Node* ResolveCollision(Node* head, string& key, string& value);

    /// <summary>
    /// Увеличивает вместимость таблицы и перераспределяет все элементы
    /// </summary>
    void Rehash();

    /// <summary>
    /// Очищает цепочку узлов
    /// </summary>
    /// <param name="head">Голова цепочки</param>
    void ClearChain(Node* head);

public:
    /// <summary>
    /// Конструктор хеш-таблицы
    /// </summary>
    /// <param name="initialCapacity">Начальная вместимость таблицы</param>
    HashTable(int initialCapacity = 8);

    /// <summary>
    /// Деструктор хеш-таблицы
    /// </summary>
    ~HashTable();

    /// <summary>
    /// Вставляет пару ключ-значение в таблицу
    /// </summary>
    /// <param name="key">Ключ</param>
    /// <param name="value">Значение</param>
    /// <returns>true если успешно, false при дубликате key-value</returns>
    bool Insert(string& key, string& value);

    /// <summary>
    /// Удаляет элемент с указанным ключом
    /// </summary>
    /// <param name="key">Ключ для удаления</param>
    /// <returns>true если удалено, false если ключ не найден</returns>
    bool Remove(string& key);

    /// <summary>
    /// Ищет значение по ключу
    /// </summary>
    /// <param name="key">Ключ для поиска</param>
    /// <returns>Найденное значение или пустую строку</returns>
    string Search(string& key);

    /// <summary>
    /// Получает процесс вычисления хеша для ключа
    /// </summary>
    /// <param name="key">Ключ для анализа</param>
    /// <param name="hashSteps">Вектор для сохранения шагов хеширования</param>
    void GetHashProcess(string& key, vector<string>& hashSteps);

    /// <summary>
    /// Возвращает текущее количество элементов в таблице
    /// </summary>
    int GetSize();

    /// <summary>
    /// Возвращает текущую вместимость таблицы
    /// </summary>
    int GetCapacity();

    /// <summary>
    /// Возвращает коэффициент заполнения таблицы
    /// </summary>
    /// <returns>Коэффициент заполнения (size / capacity)</returns>
    double GetLoadFactor();

    /// <summary>
    /// Получает состояние таблицы
    /// </summary>
    /// <param name="tableInfo">Информация о таблице</param>
    /// <param name="tableContent">Содержимое таблицы</param>
    void GetTableState(vector<string>& tableInfo, vector<string>& tableContent);
};
