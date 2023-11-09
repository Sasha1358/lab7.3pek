#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.3pek/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73pek
{
	TEST_CLASS(UnitTest73pek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 3;
			int** a = new int* [n];
			for (int i = 0; i < n; i++) {
				a[i] = new int[n];
			}

			// Ініціалізація масиву

			a[0][0] = 1;a[0][1] = 2;a[0][2] = 3;
			a[1][0] = 4;a[1][1] = 5;a[1][2] = 6;
			a[2][0] = 7;a[2][1] = 8;a[2][2] = 9;


			int k = Sum(a, 0, 0, n);


			Assert::AreEqual(k, 11);

			for (int i = 0; i < n; i++) {
				delete[] a[i];
			}
			delete[] a;
		}
	};
}
