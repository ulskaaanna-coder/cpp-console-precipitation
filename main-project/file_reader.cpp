#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

void read(const char* file_name, precipitation* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        while (!file.eof())
        {
            precipitation* item = new precipitation;
            file >> item->day;
            file >> item->month;
            file >> item->amount;
            file.ignore(1);
            file.getline(item->characteristic, MAX_STRING_SIZE);
            if (strlen(item->characteristic) > 0)
            {
                array[size++] = item;
            }
            else
            {
                delete item;
            }
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}
