#include <iostream>
#include <iomanip>
#include "precipitation.h"
#include "file_reader.h"
#include "constants.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Laboratory work #8. GIT\n";
    cout << "Variant #3. Precipitation\n";
    cout << "Author: Anna Ulskaya\n\n";

    precipitation* records[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", records, size);
        cout << "***** Осадки за период *****\n\n";
        for (int i = 0; i < size; i++)
        {
            cout << "Дата...........: "
                << setw(2) << setfill('0') << records[i]->day << "."
                << setw(2) << setfill('0') << records[i]->month << '\n';
            cout << "Количество (мм): " << records[i]->amount << '\n';
            cout << "Характеристика.: " << records[i]->characteristic << '\n';
            cout << '\n';
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

