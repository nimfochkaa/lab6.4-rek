#include "pch.h"
#include "CppUnitTest.h"
#include "../6.4 рек/6.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My64
{
	TEST_CLASS(My64)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 5;
			float a[n];
			Create(a, n, -10, 10);

			for (int i = 0; i < n; i++) {
				Assert::IsTrue(a[i] >= -10 && a[i] <= 10);
			}
		}
	};
}
