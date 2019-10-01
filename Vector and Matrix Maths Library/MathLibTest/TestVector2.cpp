#include <cstdlib>
#include <ctime>


#include "CppUnitTest.h"
#include "amathlib.h"
#include "mathlib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathLibTest
{		
	TEST_CLASS(TestVector2)
	{
		TEST_CLASS_INITIALIZE(testInit)
		{
			srand((unsigned int) time(nullptr));
		}

		CVector2 rCvector2() {
			return CVector2(
				(float) ((rand() % 10000) + 1000) - 5000,
				(float) ((rand() % 10000) + 1000) - 5000
			);
		}

		ACVector2 ACvector2FromCVector2(CVector2 a_other) {
			// Only valid once square bracket tests have passed
			return ACVector2(a_other[0], a_other[1]);
		}

	public:	
		TEST_METHOD(ConstructorsSqBrackets)
		{
			CVector2 test(4.0f, 5.0f);
			Assert::AreEqual(test[0], 4.0f);
			Assert::AreEqual(test[1], 5.0f);
		}

		TEST_METHOD(ConstructorsSqBrackets_large)
		{
			CVector2 test(30000.0f, 50000.0f);

			Assert::AreEqual(test[0], 30000.0f);
			Assert::AreEqual(test[1], 50000.0f);
		}

		TEST_METHOD(ConstructorsSqBrackets_small)
		{
			CVector2 test(0.00001f, 0.00001f);

			Assert::AreEqual(test[0], 0.00001f);
			Assert::AreEqual(test[1], 0.00001f);
		}


		TEST_METHOD(magnitudesq)
		{
			CVector2 test = rCvector2();
			ACVector2 tester = ACvector2FromCVector2(test);

			Assert::IsTrue(abs(tester.magnitude() - test.magnitude()) < FLT_EPSILON);
		}

		TEST_METHOD(magnitude)
		{
			CVector2 test = rCvector2();
			ACVector2 tester = ACvector2FromCVector2(test);

			Assert::IsTrue(abs(tester.magnitudeSq() - test.magnitudeSq()) < FLT_EPSILON);
		}

		TEST_METHOD(distanceSq)
		{
			CVector2 test = rCvector2();
			CVector2 test1 = rCvector2();

			ACVector2 atest = ACvector2FromCVector2(test);
			ACVector2 atest1 = ACvector2FromCVector2(test1);

			Assert::IsTrue(abs(atest.distanceSq(atest1) - test.distanceSq(test1)) < FLT_EPSILON);
		}

		TEST_METHOD(distance)
		{
			CVector2 test = rCvector2();
			CVector2 test1 = rCvector2();

			ACVector2 atest = ACvector2FromCVector2(test);
			ACVector2 atest1 = ACvector2FromCVector2(test1);

			Assert::IsTrue(abs(atest.distance(atest1) - test.distance(test1)) < FLT_EPSILON);
		}

		TEST_METHOD(crossproduct)
		{
			//For vector 2 crossproduct is perpendicular

			CVector2 test = rCvector2();
			ACVector2 atest = ACvector2FromCVector2(test);

			atest = atest.crossProduct();

			Assert::AreEqual(test.crossProduct()[0], atest[0]);
			Assert::AreEqual(test.crossProduct()[1], atest[1]);
		}

		TEST_METHOD(dotproduct)
		{
			CVector2 test = rCvector2();
			CVector2 test1 = rCvector2();

			ACVector2 atest = ACvector2FromCVector2(test);
			ACVector2 atest1 = ACvector2FromCVector2(test1);

			Assert::IsTrue(abs(atest.dotProduct(atest1) - test.dotProduct(test1)) < FLT_EPSILON);
		}

		TEST_METHOD(normalise)
		{
			CVector2 test = rCvector2();

			CVector2 normalised = test.normalised();
			test.normalise();

			Assert::AreEqual(normalised[0], test[0]);
			Assert::AreEqual(normalised[1], test[1]);

			float expectedMag = 1.0f;

			Assert::IsTrue(abs(expectedMag - test.magnitude()) < FLT_EPSILON);
			Assert::IsTrue(abs(expectedMag - normalised.magnitude()) < FLT_EPSILON);
		}

		TEST_METHOD(multiply)
		{
			CVector2 test = rCvector2();
			CVector2 test1 = rCvector2();

			ACVector2 atest = ACvector2FromCVector2(test);
			ACVector2 atest1 = ACvector2FromCVector2(test1);

			CVector2 result = test * test1;
			ACVector2 aresult = atest * atest1;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
		}

		TEST_METHOD(multiplyScalar)
		{
			CVector2 test = rCvector2();
			ACVector2 atest = ACvector2FromCVector2(test);

			float c = ((float)(rand() % 10000) + 1000) - 5000;

			CVector2 result = test * c;
			ACVector2 aresult = atest * c;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
		}

		TEST_METHOD(divide)
		{
			CVector2 test = rCvector2();
			CVector2 test1 = rCvector2();

			ACVector2 atest = ACvector2FromCVector2(test);
			ACVector2 atest1 = ACvector2FromCVector2(test1);

			CVector2 result = test / test1;
			ACVector2 aresult = atest / atest1;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
		}

		TEST_METHOD(divideScalar)
		{
			CVector2 test = rCvector2();
			ACVector2 atest = ACvector2FromCVector2(test);

			float c = ((float)(rand() % 10000) + 1000) - 5000;

			CVector2 result = test / c;
			ACVector2 aresult = atest / c;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
		}

		TEST_METHOD(add)
		{
			CVector2 test = rCvector2();
			CVector2 test1 = rCvector2();

			ACVector2 atest = ACvector2FromCVector2(test);
			ACVector2 atest1 = ACvector2FromCVector2(test1);

			CVector2 result = test + test1;
			ACVector2 aresult = atest + atest1;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
		}

		TEST_METHOD(subtract)
		{
			CVector2 test = rCvector2();
			CVector2 test1 = rCvector2();

			ACVector2 atest = ACvector2FromCVector2(test);
			ACVector2 atest1 = ACvector2FromCVector2(test1);

			CVector2 result = test - test1;
			ACVector2 aresult = atest - atest1;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
		}

	};
}