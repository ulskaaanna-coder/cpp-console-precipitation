#include <iostream>
#include <iomanip>
#include "precipitation.h"
#include "file_reader.h"
#include "filter.h"
#include "sort.h"
#include "constants.h"
#include <windows.h>

using namespace std;

void output(precipitation* item)
{
    cout << "Дата...........: "
        << setw(2) << setfill('0') << item->day << "."
        << setw(2) << setfill('0') << item->month << '\n';
    cout << "Количество (мм): " << item->amount << '\n';
    cout << "Характеристика.: " << item->characteristic << '\n';
    cout << '\n';
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    cout << "Laboratory work #8. GIT\n";
    cout << "Variant #3. Precipitation\n";
    cout << "Author: Anna Ulskaya\n";
    cout << "Group: 26PInj1d1\n\n";

    precipitation* records[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", records, size);

        int choice = 0;
        cout << "Выберите действие:\n";
        cout << "1 - Вывести все данные\n";
        cout << "2 - Фильтр: дни, когда шёл дождь\n";
        cout << "3 - Фильтр: дни с осадками меньше 1.5 мм\n";
        cout << "4 - Сортировка (Шейкерная, по возрастанию количества осадков)\n";
        cout << "5 - Сортировка (Быстрая, по возрастанию количества осадков)\n";
        cout << "6 - Сортировка (Шейкерная, по характеристике, месяцу и дню)\n";
        cout << "7 - Сортировка (Быстрая, по характеристике, месяцу и дню)\n";
        cout << "Ваш выбор: ";
        cin >> choice;
        cout << '\n';

        switch (choice)
        {
        case 1:
            for (int i = 0; i < size; i++) output(records[i]);
            break;
        case 2:
        {
            int filtered_size = 0;
            precipitation** res = filter(records, size, check_is_rain, filtered_size);
            for (int i = 0; i < filtered_size; i++) output(res[i]);
            delete[] res;
            break;
        }
        case 3:
        {
            int filtered_size = 0;
            precipitation** res = filter(records, size, check_amount_less_1_5, filtered_size);
            for (int i = 0; i < filtered_size; i++) output(res[i]);
            delete[] res;
            break;
        }
        case 4:
            shaker_sort(records, size, compare_by_amount);
            for (int i = 0; i < size; i++) output(records[i]);
            break;
        case 5:
            quick_sort(records, size, compare_by_amount);
            for (int i = 0; i < size; i++) output(records[i]);
            break;
        case 6:
            shaker_sort(records, size, compare_by_characteristic_and_date);
            for (int i = 0; i < size; i++) output(records[i]);
            break;
        case 7:
            quick_sort(records, size, compare_by_characteristic_and_date);
            for (int i = 0; i < size; i++) output(records[i]);
            break;
        default:
            cout << "Неверный пункт меню!\n";
        }

        for (int i = 0; i < size; i++)
        {
            delete records[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}
