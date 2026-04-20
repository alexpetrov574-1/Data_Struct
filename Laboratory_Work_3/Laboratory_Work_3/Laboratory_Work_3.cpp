#include "QueueRing.h"
#include "QueueTwoStacks.h"
#include "Stack.h"
#include "RingBuffer.h"
#include <iostream>

#define BOLD "\033[1m"
#define RESET "\033[0m"

using namespace std;

QueueRing* circularQueue = nullptr;
QueueTwoStack* stackQueue = nullptr;
Stack* stack = nullptr;
RingBuffer* circularBuffer = nullptr;

int GetIntInput(string prompt)
{
    int value;
    cout << prompt;
    cin >> value;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Ошибка: Неверный ввод. Пожалуйста, введите целое число." << endl;
        return -1;
    }
    return value;
}

void DisplayMainMenu()
{
    cout << BOLD << "Лабораторная работа - АСД" << RESET << endl;
    cout << endl;

    cout << BOLD << "Очереди:" << RESET << endl;
    if (circularQueue != nullptr)
    {
        cout << "  Кольцевой буфер: ";
        circularQueue->Display();
    }
    else
    {
        cout << "Очередь на кольцевом буфере: не создана" << endl;
    }

    if (stackQueue != nullptr)
    {
        cout << "Два стека: ";
        stackQueue->Display();
    }
    else
    {
        cout << "Очередь на двух стеках: не создана" << endl;
    }

    cout << BOLD << "Стек:" << RESET << endl;
    if (stack != nullptr)
    {
        cout << "  ";
        stack->Show();
    }
    else
    {
        cout << "Стек: не создан" << endl;
    }

    cout << BOLD << "Кольцевой буфер:" << RESET << endl;
    if (circularBuffer != nullptr)
    {
        cout << "  ";
        circularBuffer->DisplayLogical();
    }
    else {
        cout << "Кольцевой буфер: не создан" << endl;
    }

    cout << endl << BOLD << "Выберите тип структуры:" << RESET << endl;
    cout << "1. Работа с очередью на кольцевом буфере" << endl;
    cout << "2. Работа с очередью на двух стеках" << endl;
    cout << "3. Работа со стеком" << endl;
    cout << "4. Работа с кольцевым буфером" << endl;
    cout << "5. Создать очередь на кольцевом буфере" << endl;
    cout << "6. Создать очередь на двух стеках" << endl;
    cout << "7. Создать стек" << endl;
    cout << "8. Создать кольцевой буфер" << endl;
    cout << "0. Выход из программы" << endl;
    cout << endl << "Выберите действие > ";
}

void DisplayQueueMenu(const string& queueType)
{
    cout << BOLD << "Операции с " << queueType << RESET << endl;
    cout << "1. Добавить элемент (Enqueue)" << endl;
    cout << "2. Извлечь элемент (Dequeue)" << endl;
    cout << "3. Просмотреть первый элемент (Peek)" << endl;
    cout << "4. Проверить пустоту" << endl;
    cout << "5. Проверить заполненность" << endl;
    cout << "6. Получить размер" << endl;
    cout << "7. Получить вместимость" << endl;
    cout << "8. Получить свободное место" << endl;
    cout << "9. Изменить размер" << endl;
    cout << "10. Очистить очередь" << endl;
    cout << "11. Показать детальную информацию" << endl;
    cout << "0. Назад в главное меню" << endl;
    cout << endl << "Выберите действие > ";
}

void DisplayStackMenu()
{
    cout << BOLD << "Операции со стеком" << RESET << endl;
    cout << "1. Добавить элемент (Push)" << endl;
    cout << "2. Извлечь элемент (Pop)" << endl;
    cout << "3. Просмотреть вершину (Peek)" << endl;
    cout << "4. Проверить пустоту" << endl;
    cout << "5. Проверить заполненность" << endl;
    cout << "6. Получить размер" << endl;
    cout << "7. Получить вместимость" << endl;
    cout << "8. Очистить стек" << endl;
    cout << "9. Показать содержимое" << endl;
    cout << "0. Назад в главное меню" << endl;
    cout << endl << "Выберите действие > ";
}

void DisplayCircularBufferMenu()
{
    cout << BOLD << "Операции с кольцевым буфером" << RESET << endl;
    cout << "1. Добавить элемент (Enqueue)" << endl;
    cout << "2. Извлечь элемент (Dequeue)" << endl;
    cout << "3. Просмотреть первый элемент (Peek)" << endl;
    cout << "4. Проверить пустоту" << endl;
    cout << "5. Проверить заполненность" << endl;
    cout << "6. Получить размер" << endl;
    cout << "7. Получить вместимость" << endl;
    cout << "8. Получить свободное место" << endl;
    cout << "9. Изменить размер" << endl;
    cout << "10. Очистить буфер" << endl;
    cout << "11. Показать логическое представление" << endl;
    cout << "12. Показать физическое представление" << endl;
    cout << "0. Назад в главное меню" << endl;
    cout << endl << "Выберите действие > ";
}

void CreateCircularBufferQueueMenu()
{
    cout << BOLD << "Создание очереди на кольцевом буфере" << RESET << endl;

    if (circularQueue != nullptr) {
        delete circularQueue;
        cout << "Старая очередь удалена." << endl;
    }

    int capacity = GetIntInput("Введите вместимость очереди: ");
    if (capacity > 0)
    {
        circularQueue = new QueueRing(capacity);
        cout << "Очередь успешно создана!" << endl;
    }
    else
    {
        cout << "Ошибка: Вместимость должна быть положительным числом." << endl;
    }
}

void CreateStackQueueMenu()
{
    cout << BOLD << "Создание очереди на двух стеках" << RESET << endl;

    if (stackQueue != nullptr)
    {
        delete stackQueue;
        cout << "Старая очередь удалена." << endl;
    }

    int capacity = GetIntInput("Введите вместимость очереди: ");
    if (capacity > 0)
    {
        stackQueue = new QueueTwoStack(capacity);
        cout << "Очередь успешно создана!" << endl;
    }
    else
    {
        cout << "Ошибка: Вместимость должна быть положительным числом." << endl;
    }
}

void CreateStackMenu()
{
    cout << BOLD << "Создание стека" << RESET << endl;

    if (stack != nullptr)
    {
        delete stack;
        cout << "Старый стек удален." << endl;
    }

    int capacity = GetIntInput("Введите вместимость стека: ");
    if (capacity > 0)
    {
        stack = new Stack(capacity);
        cout << "Стек успешно создан!" << endl;
    }
    else
    {
        cout << "Ошибка: Вместимость должна быть положительным числом." << endl;
    }
}

void CreateCircularBufferMenu()
{
    cout << BOLD << "Создание кольцевого буфера" << RESET << endl;

    if (circularBuffer != nullptr)
    {
        delete circularBuffer;
        cout << "Старый буфер удален." << endl;
    }

    int capacity = GetIntInput("Введите вместимость буфера: ");
    if (capacity > 0)
    {
        circularBuffer = new RingBuffer(capacity);
        cout << "Кольцевой буфер успешно создан!" << endl;
    }
    else
    {
        cout << "Ошибка: Вместимость должна быть положительным числом." << endl;
    }
}

void QueueOperationsMenu(bool isCircularQueue)
{
    int choice;

    while (true)
    {

        if ((isCircularQueue && circularQueue == nullptr) || (!isCircularQueue && stackQueue == nullptr))
        {
            cout << "Ошибка: Очередь не создана!" << endl;
            return;
        }

        string queueType = isCircularQueue ? "очередью на кольцевом буфере" : "очередью на двух стеках";

        if (isCircularQueue)
        {
            circularQueue->Display();
        }
        else
        {
            stackQueue->Display();
        }

        cout << endl;
        DisplayQueueMenu(queueType);

        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Неизвестная команда. Попробуйте снова." << endl;
            continue;
        }

        cin.ignore(10000, '\n');

        if (choice == 0)
        {
            break;
        }

        switch (choice)
        {
        case 1:
        {
            int value = GetIntInput("Введите значение для добавления: ");
            if (value != -1) {
                bool result;
                if (isCircularQueue) {
                    result = circularQueue->Enqueue(value);
                }
                else {
                    result = stackQueue->Enqueue(value);
                }
                if (!result) {
                    cout << "Не удалось добавить элемент." << endl;
                }
            }
            break;
        }
        case 2:
        {
            int value;
            bool result;
            if (isCircularQueue) {
                result = circularQueue->Dequeue(value);
            }
            else {
                result = stackQueue->Dequeue();
            }
            if (!result) {
                cout << "Не удалось извлечь элемент." << endl;
            }
            break;
        }
        case 3:
        {
            int value;
            bool result;
            if (isCircularQueue) {
                result = circularQueue->Peek(value);
            }
            else {
                result = stackQueue->Peek(value);
            }
            if (!result) {
                cout << "Не удалось просмотреть элемент." << endl;
            }
            break;
        }
        case 4:
        {
            bool isEmpty;
            if (isCircularQueue) {
                isEmpty = circularQueue->IsEmpty();
            }
            else {
                isEmpty = stackQueue->IsEmpty();
            }
            cout << "Очередь " << (isEmpty ? "пуста" : "не пуста") << endl;
            break;
        }
        case 5:
        {
            bool isFull;
            if (isCircularQueue) {
                isFull = circularQueue->IsFull();
            }
            else {
                isFull = stackQueue->IsFull();
            }
            cout << "Очередь " << (isFull ? "полна" : "не полна") << endl;
            break;
        }
        case 6:
        {
            int size;
            if (isCircularQueue) {
                size = circularQueue->GetSize();
            }
            else {
                size = stackQueue->GetSize();
            }
            cout << "Текущий размер очереди: " << size << endl;
            break;
        }
        case 7:
        {
            int capacity;
            if (isCircularQueue) {
                capacity = circularQueue->GetCapacity();
            }
            else {
                capacity = stackQueue->GetCapacity();
            }
            cout << "Вместимость очереди: " << capacity << endl;
            break;
        }
        case 8:
        {
            int freeSpace;
            if (isCircularQueue) {
                freeSpace = circularQueue->GetFreeSpace();
            }
            else {
                freeSpace = stackQueue->GetFreeSpace();
            }
            cout << "Свободное место в очереди: " << freeSpace << endl;
            break;
        }
        case 9:
        {
            int newCapacity = GetIntInput("Введите новый размер: ");
            if (newCapacity > 0) {
                bool resizeResult;
                if (isCircularQueue) {
                    resizeResult = circularQueue->Resize(newCapacity);
                }
                else {
                    resizeResult = stackQueue->Resize(newCapacity);
                }
                if (!resizeResult) {
                    cout << "Не удалось изменить размер." << endl;
                }
            }
            break;
        }
        case 10:
            if (isCircularQueue) {
                circularQueue->Clear();
            }
            else {
                stackQueue->Clear();
            }
            cout << "Очередь очищена." << endl;
            break;
        case 11:
            if (isCircularQueue) {
                circularQueue->DisplayDetailed();
            }
            else {
                stackQueue->DisplayDetailed();
            }
            break;
        default:
            cout << "Неизвестная команда. Попробуйте снова." << endl;
            break;
        }
    }
}

void StackOperationsMenu()
{
    int choice;

    while (true)
    {

        if (stack == nullptr)
        {
            cout << "Ошибка: Стек не создан!" << endl;
            return;
        }

        stack->Show();
        cout << endl;
        DisplayStackMenu();

        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Неизвестная команда. Попробуйте снова." << endl;
            continue;
        }

        cin.ignore(10000, '\n');

        if (choice == 0)
        {
            break;
        }

        switch (choice)
        {
        case 1:
        {
            int value = GetIntInput("Введите значение для добавления: ");
            if (value != -1) {
                bool result = stack->Push(value);
                if (!result) {
                    cout << "Не удалось добавить элемент." << endl;
                }
            }
            break;
        }
        case 2:
        {
            int value = stack->Pop();
            if (value != -1) 
            {
                cout << "Извлечен элемент: " << value << endl;
            }
            break;
        }
        case 3:
        {
            int value;
            bool result = stack->Peek(value);
            if (!result) 
            {
                cout << "Не удалось просмотреть элемент." << endl;
            }
            break;
        }
        case 4:
        {
            bool isEmpty = stack->IsEmpty();
            cout << "Стек " << (isEmpty ? "пуст" : "не пуст") << endl;
            break;
        }
        case 5:
        {
            bool isFull = stack->IsFull();
            cout << "Стек " << (isFull ? "полон" : "не полон") << endl;
            break;
        }
        case 6:
        {
            int size = stack->GetSize();
            cout << "Текущий размер стека: " << size << endl;
            break;
        }
        case 7:
        {
            int capacity = stack->GetCapacity();
            cout << "Вместимость стека: " << capacity << endl;
            break;
        }
        case 8:
            stack->Clear();
            break;
        case 9:
            stack->Show();
            stack->~Stack();
            break;
        default:
            cout << "Неизвестная команда. Попробуйте снова." << endl;
            break;
        }
    }
}

void CircularBufferOperationsMenu()
{
    int choice;

    while (true)
    {

        if (circularBuffer == nullptr)
        {
            cout << "Ошибка: Кольцевой буфер не создан!" << endl;
            return;
        }

        circularBuffer->DisplayLogical();
        cout << endl;
        DisplayCircularBufferMenu();

        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Неизвестная команда. Попробуйте снова." << endl;
            continue;
        }

        cin.ignore(10000, '\n');

        if (choice == 0)
        {
            break;
        }

        switch (choice)
        {
        case 1:
        {
            int value = GetIntInput("Введите значение для добавления: ");
            if (value != -1) {
                bool result = circularBuffer->Enqueue(value);
                if (!result) {
                    cout << "Не удалось добавить элемент." << endl;
                }
            }
            break;
        }
        case 2:
        {
            int value;
            bool result = circularBuffer->Dequeue(value);
            if (!result) {
                cout << "Не удалось извлечь элемент." << endl;
            }
            break;
        }
        case 3:
        {
            int value;
            bool result = circularBuffer->Peek(value);
            if (!result) {
                cout << "Не удалось просмотреть элемент." << endl;
            }
            break;
        }
        case 4:
        {
            bool isEmpty = circularBuffer->IsEmpty();
            cout << "Буфер " << (isEmpty ? "пуст" : "не пуст") << endl;
            break;
        }
        case 5:
        {
            bool isFull = circularBuffer->IsFull();
            cout << "Буфер " << (isFull ? "полон" : "не полон") << endl;
            break;
        }
        case 6:
        {
            int size = circularBuffer->GetUsedSpace();
            cout << "Текущий размер буфера: " << size << endl;
            break;
        }
        case 7:
        {
            int capacity = circularBuffer->GetCapacity();
            cout << "Вместимость буфера: " << capacity << endl;
            break;
        }
        case 8:
        {
            int freeSpace = circularBuffer->GetFreeSpace();
            cout << "Свободное место в буфере: " << freeSpace << endl;
            break;
        }
        case 9:
        {
            int newCapacity = GetIntInput("Введите новый размер: ");
            if (newCapacity > 0) {
                bool result = circularBuffer->Resize(newCapacity);
                if (!result) {
                    cout << "Не удалось изменить размер." << endl;
                }
            }
            break;
        }
        case 10:
            circularBuffer->Clear();
            cout << "Буфер очищен." << endl;
            break;
        case 11:
            circularBuffer->DisplayLogical();
            break;
        case 12:
            circularBuffer->Display();
            break;
        default:
            cout << "Неизвестная команда. Попробуйте снова." << endl;
            break;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Ru");

    int choice;

    while (true)
    {
        DisplayMainMenu();

        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Неизвестная команда. Попробуйте снова." << endl;
            continue;
        }

        cin.ignore(10000, '\n');

        switch (choice)
        {
        case 0:
            if (circularQueue != nullptr) {
                circularQueue->Clear();
            }
            if (stackQueue != nullptr) {
                stackQueue->Clear();
            }
            if (stack != nullptr) {
                stack->Clear();
            }
            if (circularBuffer != nullptr) {
                circularBuffer->Clear();
            }
            cout << "Выход из программы..." << endl;
            return 0;
        case 1:
            if (circularQueue == nullptr) {
                cout << "Ошибка: Очередь на кольцевом буфере не создана!" << endl;
            }
            else {
                QueueOperationsMenu(true);
            }
            break;
        case 2:
            if (stackQueue == nullptr) {
                cout << "Ошибка: Очередь на двух стеках не создана!" << endl;
            }
            else {
                QueueOperationsMenu(false);
            }
            break;
        case 3:
            if (stack == nullptr) {
                cout << "Ошибка: Стек не создан!" << endl;
            }
            else {
                StackOperationsMenu();
            }
            break;
        case 4:
            if (circularBuffer == nullptr) {
                cout << "Ошибка: Кольцевой буфер не создан!" << endl;
            }
            else {
                CircularBufferOperationsMenu();
            }
            break;
        case 5:
            CreateCircularBufferQueueMenu();
            break;
        case 6:
            CreateStackQueueMenu();
            break;
        case 7:
            CreateStackMenu();
            break;
        case 8:
            CreateCircularBufferMenu();
            break;
        default:
            cout << "Неизвестная команда. Попробуйте снова." << endl;
            break;
        }
    }

    return 0;
}