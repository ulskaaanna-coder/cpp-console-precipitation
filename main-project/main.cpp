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
        for (int i = 0; i < size; i++)
        {
            cout << records[i]->day << " "
                << records[i]->month << " "
                << records[i]->amount << " "
                << records[i]->characteristic << '\n';
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
