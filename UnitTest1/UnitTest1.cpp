#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\vladt\source\repos\Pr 6.7 OOP\Pr 6.7 OOP\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[] = { 1, -1, 0 };
			Assert::AreEqual(1, accumulate(&a[0], &a[1]));
		}
	};
}
