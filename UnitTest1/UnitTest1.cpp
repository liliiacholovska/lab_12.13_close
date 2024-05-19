#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12.13(2)/lab12.13(2).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestAddNote)
        {
            HashTable hashTable;
            Note note = { "Doe", "John", "123456789", {1, 4, 1990} };

            hashTable.addNote(note);
            vector<Note> result;
            bool found = hashTable.findNoteByLastName("Doe", result);

            Assert::IsTrue(found);
            Assert::AreEqual(1, static_cast<int>(result.size()));
            Assert::AreEqual(note.lastName, result[0].lastName);
            Assert::AreEqual(note.firstName, result[0].firstName);
            Assert::AreEqual(note.phoneNumber, result[0].phoneNumber);
            Assert::AreEqual(note.birthDate[0], result[0].birthDate[0]);
            Assert::AreEqual(note.birthDate[1], result[0].birthDate[1]);
            Assert::AreEqual(note.birthDate[2], result[0].birthDate[2]);
        }

        TEST_METHOD(TestDeleteNote)
        {
            HashTable hashTable;
            Note note1 = { "Doe", "John", "123456789", {1, 4, 1990} };
            Note note2 = { "Smith", "Alice", "987654321", {15, 8, 1985} };

            hashTable.addNote(note1);
            hashTable.addNote(note2);

            hashTable.deleteNote("Doe", "John");
            vector<Note> result;
            bool foundDoe = hashTable.findNoteByLastName("Doe", result);

            Assert::IsFalse(foundDoe);
            Assert::AreEqual(0, static_cast<int>(result.size()));
        }
	};
}