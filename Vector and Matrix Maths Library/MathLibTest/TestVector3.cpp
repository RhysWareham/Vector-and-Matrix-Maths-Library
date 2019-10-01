#include <cstdlib>
#include <ctime>


#include "CppUnitTest.h"
#include "amathlib.h"
#include "mathlib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace MathLibTest
{
	TEST_CLASS(TestVector3)
	{
		TEST_CLASS_INITIALIZE(testInit)
		{
			srand((unsigned int)time(nullptr));
		}

		CVector3 rCVector3() {
			//Only works once all initialisation code is working
			return CVector3(
				(float)((rand() % 10000) + 1000) - 5000,
				(float)((rand() % 10000) + 1000) - 5000,
				(float)((rand() % 10000) + 1000) - 5000
			);
		}

		ACVector3 ACVector3FromCVector3(CVector3 a_other) {
			// Only valid once square bracket tests have passed
			return ACVector3(a_other[0], a_other[1], a_other[2]);
		}

	public:
		TEST_METHOD(ConstructorsSqBrackets)
		{
			CVector3 test(4.0f, 5.0f, 6.0f);
			Assert::AreEqual(test[0], 4.0f);
			Assert::AreEqual(test[1], 5.0f);
			Assert::AreEqual(test[2], 6.0f);
		}

		TEST_METHOD(ConstructorsSqBrackets_large)
		{
			CVector3 test(30000.0f, 50000.0f, 40000.0f);

			Assert::AreEqual(test[0], 30000.0f);
			Assert::AreEqual(test[1], 50000.0f);
			Assert::AreEqual(test[2], 40000.0f);
		}

		TEST_METHOD(ConstructorsSqBrackets_small)
		{
			CVector3 test(0.00001f, 0.00001f, 0.00001f);

			Assert::AreEqual(test[0], 0.00001f);
			Assert::AreEqual(test[1], 0.00001f);
			Assert::AreEqual(test[1], 0.00001f);
		}


		TEST_METHOD(magnitudesq)
		{
			CVector3 test = rCVector3();
			ACVector3 tester = ACVector3FromCVector3(test);

			Assert::IsTrue(abs(tester.magnitude() - test.magnitude()) < FLT_EPSILON);
		}

		TEST_METHOD(magnitude)
		{
			CVector3 test = rCVector3();
			ACVector3 tester = ACVector3FromCVector3(test);

			Assert::IsTrue(abs(tester.magnitudeSq() - test.magnitudeSq()) < FLT_EPSILON);
		}

		TEST_METHOD(distanceSq)
		{
			CVector3 test = rCVector3();
			CVector3 test1 = rCVector3();

			ACVector3 atest = ACVector3FromCVector3(test);
			ACVector3 atest1 = ACVector3FromCVector3(test1);

			Assert::IsTrue(abs(atest.distanceSq(atest1) - test.distanceSq(test1)) < FLT_EPSILON);
		}

		TEST_METHOD(distance)
		{
			CVector3 test = rCVector3();
			CVector3 test1 = rCVector3();

			ACVector3 atest = ACVector3FromCVector3(test);
			ACVector3 atest1 = ACVector3FromCVector3(test1);

			Assert::IsTrue(abs(atest.distance(atest1) - test.distance(test1)) < FLT_EPSILON);
		}

		TEST_METHOD(crossproduct)
		{
			CVector3 test = rCVector3();
			ACVector3 atest = ACVector3FromCVector3(test);

			CVector3 test1 = rCVector3();
			ACVector3 atest1 = ACVector3FromCVector3(test1);

			atest = atest.crossProduct(atest1);
			test = test.crossProduct(test1);

			Assert::AreEqual(test[0], atest[0]);
			Assert::AreEqual(test[1], atest[1]);
			Assert::AreEqual(test[2], atest[2]);
		}

		TEST_METHOD(dotproduct)
		{
			CVector3 test = rCVector3();
			CVector3 test1 = rCVector3();

			ACVector3 atest = ACVector3FromCVector3(test);
			ACVector3 atest1 = ACVector3FromCVector3(test1);

			Assert::IsTrue(abs(atest.dotProduct(atest1) - test.dotProduct(test1)) < FLT_EPSILON);
		}

		TEST_METHOD(normalise)
		{
			CVector3 test = rCVector3();

			CVector3 normalised = test.normalised();
			test.normalise();

			Assert::AreEqual(normalised[0], test[0]);
			Assert::AreEqual(normalised[1], test[1]);
			Assert::AreEqual(normalised[2], test[2]);

			float expectedMag = 1.0f;

			Assert::IsTrue(abs(expectedMag - test.magnitude()) < FLT_EPSILON);
			Assert::IsTrue(abs(expectedMag - normalised.magnitude()) < FLT_EPSILON);
		}

		TEST_METHOD(multiply)
		{
			CVector3 test = rCVector3();
			CVector3 test1 = rCVector3();

			ACVector3 atest = ACVector3FromCVector3(test);
			ACVector3 atest1 = ACVector3FromCVector3(test1);

			CVector3 result = test * test1;
			ACVector3 aresult = atest * atest1;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[2] - aresult[2]) < FLT_EPSILON);
		}

		TEST_METHOD(multiplyScalar)
		{
			CVector3 test = rCVector3();
			ACVector3 atest = ACVector3FromCVector3(test);

			float c = ((float)(rand() % 10000) + 1000) - 5000;

			CVector3 result = test * c;
			ACVector3 aresult = atest * c;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[2] - aresult[2]) < FLT_EPSILON);
		}

		TEST_METHOD(divide)
		{
			CVector3 test = rCVector3();
			CVector3 test1 = rCVector3();

			ACVector3 atest = ACVector3FromCVector3(test);
			ACVector3 atest1 = ACVector3FromCVector3(test1);

			CVector3 result = test / test1;
			ACVector3 aresult = atest / atest1;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[2] - aresult[2]) < FLT_EPSILON);
		}

		TEST_METHOD(divideScalar)
		{
			CVector3 test = rCVector3();
			ACVector3 atest = ACVector3FromCVector3(test);

			float c = ((float)(rand() % 10000) + 1000) - 5000;

			CVector3 result = test / c;
			ACVector3 aresult = atest / c;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[2] - aresult[2]) < FLT_EPSILON);
		}

		TEST_METHOD(add)
		{
			CVector3 test = rCVector3();
			CVector3 test1 = rCVector3();

			ACVector3 atest = ACVector3FromCVector3(test);
			ACVector3 atest1 = ACVector3FromCVector3(test1);

			CVector3 result = test + test1;
			ACVector3 aresult = atest + atest1;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[2] - aresult[2]) < FLT_EPSILON);
		}

		TEST_METHOD(subtract)
		{
			CVector3 test = rCVector3();
			CVector3 test1 = rCVector3();

			ACVector3 atest = ACVector3FromCVector3(test);
			ACVector3 atest1 = ACVector3FromCVector3(test1);

			CVector3 result = test - test1;
			ACVector3 aresult = atest - atest1;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[2] - aresult[2]) < FLT_EPSILON);
		}
	};
}
