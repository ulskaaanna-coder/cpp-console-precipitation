#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/precipitation.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	TEST_CLASS(unittestproject)
	{
	public:
		precipitation* create_record(int day, int month, double amount, const char* characteristic)
		{
			precipitation* item = new precipitation;
			item->day = day;
			item->month = month;
			item->amount = amount;
			strcpy_s(item->characteristic, characteristic);
			return item;
		}

		// Тест 1: Несколько записей за нужный месяц (март = 3)
		TEST_METHOD(TestMultipleRecordsInMonth)
		{
			const int size = 4;
			precipitation* records[size];
			*(records + 0) = create_record(15, 3, 2.4, "дождь");
			*(records + 1) = create_record(10, 1, 0.8, "снег");
			*(records + 2) = create_record(3, 3, 1.6, "дождь");
			*(records + 3) = create_record(22, 5, 3.5, "дождь");

			double actual = process(records, size, 3);
			Assert::AreEqual(4.0, actual, 0.0001);

			for (int i = 0; i < size; i++) delete* (records + i);
		}

		// Тест 2: Записи за нужный месяц (август = 8) отсутствуют
		TEST_METHOD(TestNoRecordsInMonth)
		{
			const int size = 3;
			precipitation* records[size];
			*(records + 0) = create_record(5, 5, 1.2, "дождь");
			*(records + 1) = create_record(12, 1, 1.9, "снег");
			*(records + 2) = create_record(7, 11, 0.5, "снег");

			double actual = process(records, size, 8);
			Assert::AreEqual(0.0, actual, 0.0001);

			for (int i = 0; i < size; i++) delete* (records + i);
		}

		// Тест 3: В массиве одна запись и она за нужный месяц (апрель = 4)
		TEST_METHOD(TestSingleMatchingRecord)
		{
			const int size = 1;
			precipitation* records[size];
			*(records + 0) = create_record(18, 4, 2.75, "морось");

			double actual = process(records, size, 4);
			Assert::AreEqual(2.75, actual, 0.0001);

			delete* (records + 0);
		}
	};
}
