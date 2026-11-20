#include <iostream>
#include <iomanip>
#include "precipitation.h"
#include "file_reader.h"
#include "filter.h"
#include "constants.h"

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
    setlocale(LC_ALL, "Russian");
    cout << "Laboratory work #8. GIT\n";
    cout << "Variant #3. Precipitation\n";
    cout << "Author: Anna Ulskaya\n";
    cout << "Group: 26PInj1d1\n\n";

    precipitation* records[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", records, size);

        int filtered_size = 0;
        precipitation** rain_days = filter(records, size, check_is_rain, filtered_size);
        cout << "***** Дни, когда шёл дождь *****\n\n";
        for (int i = 0; i < filtered_size; i++)
        {
            output(rain_days[i]);
        }
        delete[] rain_days;

        precipitation** small_amount = filter(records, size, check_amount_less_1_5, filtered_size);
        cout << "***** Дни с осадками меньше 1.5 мм *****\n\n";
        for (int i = 0; i < filtered_size; i++)
        {
            output(small_amount[i]);
        }
        delete[] small_amount;

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
