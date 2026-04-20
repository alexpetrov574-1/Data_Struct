#include "HashTable.h"
#include <iostream>

using namespace std;

/// <summary>
/// Порог перехеширования
/// </summary>
const double HashTable::LOAD_FACTOR_THRESHOLD = 0.75;

/// <summary>
/// Таблица Пирсона для вычисления хеша
/// </summary>
static const int PEARSON_TABLE[256] =
{
    98, 6, 85, 150, 36, 23, 112, 164, 135, 207, 169, 5, 26, 64, 165, 219,
    61, 20, 68, 89, 130, 63, 52, 102, 24, 229, 132, 245, 80, 216, 195, 115,
    90, 168, 156, 203, 177, 120, 2, 190, 188, 7, 100, 185, 174, 243, 162, 10,
    237, 18, 253, 225, 8, 208, 172, 244, 255, 126, 101, 79, 145, 235, 228, 121,
    123, 251, 67, 250, 161, 0, 107, 97, 241, 111, 181, 82, 249, 33, 69, 55,
    59, 153, 29, 9, 213, 167, 84, 93, 30, 46, 94, 75, 151, 114, 73, 222,
    197, 96, 210, 45, 16, 227, 248, 202, 51, 152, 252, 125, 81, 206, 215, 186,
    39, 158, 178, 187, 131, 136, 1, 49, 50, 17, 141, 91, 47, 129, 60, 99,
    154, 35, 86, 171, 105, 34, 38, 200, 147, 58, 77, 118, 173, 246, 76, 254,
    133, 232, 196, 144, 198, 124, 53, 4, 108, 74, 223, 234, 134, 230, 157, 139,
    189, 205, 199, 128, 176, 19, 211, 236, 127, 192, 231, 70, 233, 88, 146, 44,
    183, 201, 22, 83, 13, 214, 116, 109, 159, 32, 95, 226, 140, 220, 57, 12,
    221, 31, 209, 182, 143, 92, 149, 184, 148, 62, 113, 65, 37, 27, 106, 166,
    3, 14, 204, 72, 21, 41, 56, 66, 28, 193, 40, 217, 25, 54, 179, 117,
    238, 87, 240, 155, 180, 170, 242, 212, 191, 163, 78, 218, 137, 194, 175, 110,
    43, 119, 224, 71, 122, 142, 42, 160, 104, 48, 247, 103, 15, 11, 138, 239
};

/// <summary>
/// Конструктор узла
/// </summary>
/// <param name="k">Ключ</param>
/// <param name="v">Значение</param>
HashTable::Node::Node(string& k, string& v) : Key(k), Value(v), Next(nullptr)
{
}

/// <summary>
/// Конструктор хеш-таблицы
/// </summary>
/// <param name="initialCapacity">Начальная вместимость таблицы</param>
HashTable::HashTable(int initialCapacity) : Capacity(initialCapacity), Size(0)
{
    Table.resize(Capacity, nullptr);
}

/// <summary>
/// Деструктор хеш-таблицы
/// </summary>
HashTable::~HashTable()
{
    for (int i = 0; i < Capacity; ++i)
    {
        ClearChain(Table[i]);
    }
}

/// <summary>
/// Вычисляет хеш-код для ключа с использованием алгоритма Пирсона
/// </summary>
/// <param name="key">Ключ для хеширования</param>
/// <param name="showProcess">Флаг отображения процесса вычисления</param>
/// <param name="hashSteps">Вектор для сохранения шагов хеширования</param>
int HashTable::PearsonHash(string& key, bool showProcess, vector<string>& hashSteps)
{
    int hash = 0;

    if (showProcess)
    {
        hashSteps.push_back("ВЫЧИСЛЕНИЕ ХЕША ПИРСОНА");
        hashSteps.push_back("Ключ: \"" + key + "\"");
        hashSteps.push_back("Длина ключа: " + to_string(key.length()));
        hashSteps.push_back("Начальное значение hash: 0");
    }

    for (int i = 0; i < key.length(); i++)
    {
        int c = static_cast<int>(key[i]);
        int old_hash = hash;
        int xor_result = hash ^ c;
        hash = PEARSON_TABLE[xor_result];

        if (showProcess)
        {
            string step = "Шаг " + to_string(i + 1) + ": символ '" + string(1, key[i]) + "' (код: " + to_string(c) + ")";
            hashSteps.push_back(step);
            hashSteps.push_back("  hash(" + to_string(old_hash) + ") ^ " + to_string(c) + " = " + to_string(xor_result));
            hashSteps.push_back("  PEARSON_TABLE[" + to_string(xor_result) + "] = " + to_string(hash));
            hashSteps.push_back("  Новый hash = " + to_string(hash));
            hashSteps.push_back("");
        }
    }

    int index = hash % Capacity;

    if (showProcess)
    {
        hashSteps.push_back("\n");
        hashSteps.push_back("Итоговый хеш: " + to_string(hash));
        hashSteps.push_back("Индекс в таблице: " + to_string(hash) + " % " + to_string(Capacity) + " = " + to_string(index));
        hashSteps.push_back("Ключ \"" + key + "\" будет помещен в ячейку [" + to_string(index) + "]");
        hashSteps.push_back("\n");
    }

    return index;
}

/// <summary>
/// Получает процесс вычисления хеша для ключа
/// </summary>
/// <param name="key">Ключ для анализа</param>
/// <param name="hashSteps">Вектор для сохранения шагов хеширования</param>
void HashTable::GetHashProcess(string& key, vector<string>& hashSteps)
{
    PearsonHash(key, true, hashSteps);
}

/// <summary>
/// Разрешает коллизию в цепочке, добавляя новый узел или обновляя существующий
/// </summary>
/// <param name="head">Голова цепочки</param>
/// <param name="key">Ключ</param>
/// <param name="value">Значение</param>
/// <returns>Новая голова цепочки или nullptr при дубликате key-value</returns>
HashTable::Node* HashTable::ResolveCollision(Node* head, string& key, string& value)
{
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr)
    {
        if (current->Key == key)
        {
            if (current->Value == value)
            {
                return nullptr;
            }
            current->Value = value;
            return head;
        }
        prev = current;
        current = current->Next;
    }

    Node* newNode = new Node(key, value);
    newNode->Next = head;
    return newNode;
}

/// <summary>
/// Вставляет пару ключ-значение в таблицу
/// </summary>
/// <param name="key">Ключ</param>
/// <param name="value">Значение</param>
/// <returns>true если успешно, false при дубликате key-value</returns>
bool HashTable::Insert(string& key, string& value)
{
    if (key.empty())
    {
        return false;
    }

    vector<string> hashSteps;

    int index = PearsonHash(key, true, hashSteps);

    for (int i = 0; i < hashSteps.size(); i++)
    {
        cout << hashSteps[i] << endl;
    }

    Node* newHead = ResolveCollision(Table[index], key, value);

    if (newHead == nullptr)
    {
        cout << "Дубликат key-value: {" << key << ":" << value << "} - не добавляется" << endl;
        return false;
    }

    if (newHead != Table[index])
    {
        Table[index] = newHead;
        Size++;

        cout << "Ключ \"" << key << "\" добавлен в ячейку [" << index << "]" << endl;

        if (GetLoadFactor() >= LOAD_FACTOR_THRESHOLD)
        {
            Rehash();
        }
    }
    else
    {
        cout << "Значение ключа \"" << key << "\" обновлено в ячейке [" << index << "]" << endl;
    }

    return true;
}

/// <summary>
/// Удаляет элемент с указанным ключом
/// </summary>
/// <param name="key">Ключ для удаления</param>
/// <returns>true если удалено, false если ключ не найден</returns>
bool HashTable::Remove(string& key)
{
    if (key.empty())
    {
        return false;
    }

    vector<string> hashSteps;

    int index = PearsonHash(key, false, hashSteps);

    Node* current = Table[index];
    Node* prev = nullptr;

    while (current != nullptr)
    {
        if (current->Key == key)
        {
            if (prev == nullptr)
            {
                Table[index] = current->Next;
            }
            else
            {
                prev->Next = current->Next;
            }
            delete current;
            Size--;
            return true;
        }

        prev = current;
        current = current->Next;
    }

    return false;
}

/// <summary>
/// Ищет значение по ключу
/// </summary>
/// <param name="key">Ключ для поиска</param>
/// <returns>Найденное значение или пустую строку</returns>
string HashTable::Search(string& key)
{
    if (key.empty())
    {
        return "";
    }

    vector<string> hashSteps;
    int index = PearsonHash(key, false, hashSteps);
    Node* current = Table[index];

    while (current != nullptr)
    {
        if (current->Key == key)
        {
            return current->Value;
        }
        current = current->Next;
    }

    return "";
}

/// <summary>
/// Увеличивает вместимость таблицы и перераспределяет все элементы
/// </summary>
void HashTable::Rehash()
{
    cout << "\nПЕРЕХЕШИРОВАНИЕ" << endl;
    cout << "Коэффициент заполнения " << GetLoadFactor() * 100 << "% >= " << LOAD_FACTOR_THRESHOLD * 100 << "%" << endl;
    cout << "Старая вместимость: " << Capacity << endl;

    int oldCapacity = Capacity;
    vector<Node*> oldTable = Table;

    Capacity *= 2;
    Size = 0;
    Table.clear();
    Table.resize(Capacity, nullptr);

    for (int i = 0; i < oldCapacity; ++i)
    {
        Node* current = oldTable[i];
        while (current != nullptr)
        {
            Node* next = current->Next;

            vector<string> hashSteps;
            int newIndex = PearsonHash(current->Key, false, hashSteps);

            current->Next = Table[newIndex];
            Table[newIndex] = current;
            Size++;

            current = next;
        }
    }

    cout << "Новая вместимость: " << Capacity << endl;
    cout << "Перехеширование завершено!\n" << endl;
}

/// <summary>
/// Очищает цепочку узлов
/// </summary>
/// <param name="head">Голова цепочки</param>
void HashTable::ClearChain(Node* Head)
{
    Node* current = Head;
    while (current != nullptr)
    {
        Node* temp = current;
        current = current->Next;
        delete temp;
    }
}

/// <summary>
/// Возвращает текущее количество элементов в таблице
/// </summary>
int HashTable::GetSize()
{
    return Size;
}

/// <summary>
/// Возвращает текущую вместимость таблицы
/// </summary>
int HashTable::GetCapacity()
{
    return Capacity;
}

/// <summary>
/// Возвращает коэффициент заполнения таблицы
/// </summary>
/// <returns>Коэффициент заполнения (size / capacity)</returns>
double HashTable::GetLoadFactor()
{
    return static_cast<double>(Size) / Capacity;
}

/// <summary>
/// Получает состояние таблицы
/// </summary>
/// <param name="tableInfo">Информация о таблице</param>
/// <param name="tableContent">Содержимое таблицы</param>
void HashTable::GetTableState(vector<string>& tableInfo, vector<string>& tableContent)
{
    tableInfo.push_back("Элементов: " + to_string(Size));
    tableInfo.push_back("Вместимость: " + to_string(Capacity));
    tableInfo.push_back("Коэффициент заполнения: " + to_string(GetLoadFactor() * 100) + "%");
    tableInfo.push_back("Порог перехеширования: " + to_string(LOAD_FACTOR_THRESHOLD * 100) + "%");

    for (int i = 0; i < Capacity; ++i)
    {
        string cellContent = "[" + to_string(i) + "]: ";

        if (Table[i] == nullptr)
        {
            cellContent += "ПУСТО";
        }
        else
        {
            Node* current = Table[i];
            while (current != nullptr)
            {
                cellContent += "{" + current->Key + "-" + current->Value + "}";
                if (current->Next != nullptr)
                {
                    cellContent += " -> ";
                }
                current = current->Next;
            }
        }
        tableContent.push_back(cellContent);
    }
}
