#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include "CrtCheckMemory.h"
#include "HashTable.h"
#include <vector>
using std::string;
using std::vector;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

static const int TABLE_SIZE = 10;

struct Book
{
	string Title;
	string Author;
	int Pages;
};

template<class K>
static int AsciiHashFunction(K key, size_t size)
{
	auto sum = 0;
	for (auto c : key)
		sum += c;
	return sum % size;
};

namespace UnitTests
{

	TEST_CLASS(HashTableTest)
	{
	public:

		TEST_METHOD(HashTableInsertTest)
		{
			CrtCheckMemory check;
			HashTable<string, Book> BooksMang(10, AsciiHashFunction);
			Book book1 = { "Best Book Ever", "One Author", 635 };
			BooksMang.Insert("0763757657", book1);

			Book book2 = { "Worst Book Ever", "Two Author", 452 };
			BooksMang.Insert("7063757765", book2);

			Book book3 = { "Caffeine Rehab", "Lucas Cordova", 1 };
			BooksMang.Insert("7063757234", book3);

			Assert::AreEqual(book1.Title, BooksMang["0763757657"].Title);
			Assert::AreEqual(book2.Title, BooksMang["7063757765"].Title);
			Assert::AreEqual(book3.Title, BooksMang["7063757234"].Title);
		}

		TEST_METHOD(HashTableCopyConstructorConst)
		{
			CrtCheckMemory check;
			HashTable<string, Book> BooksMang(10, AsciiHashFunction);
			Book book1 = { "Best Book Ever", "One Author", 635 };
			BooksMang.Insert("0763757657", book1);

			Book book2 = { "Worst Book Ever", "Two Author", 452 };
			BooksMang.Insert("7063757765", book2);

			Book book3 = { "Caffeine Rehab", "Lucas Cordova", 1 };
			BooksMang.Insert("7063757234", book3);

			const HashTable<string, Book> copy(BooksMang);

			Assert::AreEqual(BooksMang["0763757657"].Title, copy["0763757657"].Title);
			Assert::AreEqual(BooksMang["7063757765"].Title, copy["7063757765"].Title);
			Assert::AreEqual(BooksMang["7063757234"].Title, copy["7063757234"].Title);
		}


		TEST_METHOD(HashTableAssignmentOperatorConstTest)
		{
			CrtCheckMemory check;
			HashTable<string, Book> BooksMang(10, AsciiHashFunction);
			Book book1 = { "Best Book Ever", "One Author", 635 };
			BooksMang.Insert("0763757657", book1);

			Book book2 = { "Worst Book Ever", "Two Author", 452 };
			BooksMang.Insert("7063757765", book2);

			Book book3 = { "Caffeine Rehab", "Lucas Cordova", 1 };
			BooksMang.Insert("7063757234", book3);

			const HashTable<string, Book> copy1 = BooksMang;

			Assert::AreEqual(BooksMang["0763757657"].Title, copy1["0763757657"].Title);
			Assert::AreEqual(BooksMang["7063757765"].Title, copy1["7063757765"].Title);
			Assert::AreEqual(BooksMang["7063757234"].Title, copy1["7063757234"].Title);
		}

		TEST_METHOD(HashTableUpdateTest)
		{
			CrtCheckMemory check;
			HashTable<string, Book> BooksMang(10, AsciiHashFunction);
			Book book1 = { "Best Book Ever", "One Author", 635 };
			BooksMang.Insert("0763757657", book1);

			Book book2 = { "Worst Book Ever", "Two Author", 452 };
			BooksMang.Insert("7063757765", book2);

			Book book3 = { "Caffeine Rehab", "Lucas Cordova", 1 };
			BooksMang.Insert("7063757234", book3);

			Book newBook = { "NewTitle", "New Author", 42 };

			BooksMang.Update("7063757234", newBook);

			Assert::AreEqual(book1.Title, BooksMang["0763757657"].Title);
			Assert::AreEqual(book2.Title, BooksMang["7063757765"].Title);
			Assert::AreEqual(newBook.Title, BooksMang["7063757234"].Title);
		}

		TEST_METHOD(HashTableDeleteTest)
		{
			CrtCheckMemory check;
			HashTable<string, Book> BooksMang(10, AsciiHashFunction);
			Book book1 = { "Best Book Ever", "One Author", 635 };
			BooksMang.Insert("0763757657", book1);

			Book book2 = { "Worst Book Ever", "Two Author", 452 };
			BooksMang.Insert("7063757765", book2);

			Book book3 = { "Caffeine Rehab", "Lucas Cordova", 1 };
			BooksMang.Insert("7063757234", book3);

			Book newBook = { "NewTitle", "New Author", 42 };
			BooksMang.Insert("7063757235", newBook);

			BooksMang.Delete("7063757234");

			Assert::IsFalse(BooksMang.Find("7063757234"));
			Assert::AreEqual(book1.Title, BooksMang["0763757657"].Title);
			Assert::AreEqual(book2.Title, BooksMang["7063757765"].Title);
			Assert::AreEqual(newBook.Title, BooksMang["7063757235"].Title);
		}
	};
}