#include <cstdlib>
#include <ctime>


#include "CppUnitTest.h"
#include "amathlib.h"
#include "mathlib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace MathLibTest
{
	TEST_CLASS(TestMatrix3)
	{
		TEST_CLASS_INITIALIZE(testInit)
		{
			srand((unsigned int)time(nullptr));
		}

		CMatrix3 rCMatrix3() {
			return CMatrix3(
				(float)((rand() % 10000) + 1000) - 5000,
				(float)((rand() % 10000) + 1000) - 5000,
				(float)((rand() % 10000) + 1000) - 5000,

				(float)((rand() % 10000) + 1000) - 5000,
				(float)((rand() % 10000) + 1000) - 5000,
				(float)((rand() % 10000) + 1000) - 5000,

				(float)((rand() % 10000) + 1000) - 5000,
				(float)((rand() % 10000) + 1000) - 5000,
				(float)((rand() % 10000) + 1000) - 5000
			);
		}

		CMatrix3 copyCMatrix(CMatrix3 a_other) {
			// Only valid once square bracket tests have passed
			return CMatrix3(a_other[0], a_other[1], a_other[2],
				a_other[3], a_other[4], a_other[5],
				a_other[6], a_other[7], a_other[8]
			);
		}

		ACMatrix3 ACMatrix3FromCMatrix3(CMatrix3 a_other) {
			// Only valid once square bracket tests have passed
			return ACMatrix3(a_other[0], a_other[1], a_other[2],
				a_other[3], a_other[4], a_other[5],
				a_other[6], a_other[7], a_other[8]
			);
		}

	public:
		TEST_METHOD(ConstructorsSqBrackets)
		{
			CMatrix3 test(4.0f, 5.0f, 6.0f,
				4.0f, 5.0f, 6.0f,
				4.0f, 5.0f, 6.0f
			);

			Assert::AreEqual(test[0], 4.0f);
			Assert::AreEqual(test[1], 5.0f);
			Assert::AreEqual(test[2], 6.0f);
			Assert::AreEqual(test[3], 4.0f);
			Assert::AreEqual(test[4], 5.0f);
			Assert::AreEqual(test[5], 6.0f);
			Assert::AreEqual(test[6], 4.0f);
			Assert::AreEqual(test[7], 5.0f);
			Assert::AreEqual(test[8], 6.0f);
		}

		TEST_METHOD(GetRow)
		{
			CMatrix3 test = rCMatrix3();
			ACMatrix3 test1 = ACMatrix3FromCMatrix3(test);

			CVector3 row1 = test.GetRow(0);
			CVector3 row2 = test.GetRow(1);
			CVector3 row3 = test.GetRow(2);

			ACVector3 arow1 = test1.GetRow(0);
			ACVector3 arow2 = test1.GetRow(1);
			ACVector3 arow3 = test1.GetRow(2);

			Assert::AreEqual(row1[0], arow1[0]);
			Assert::AreEqual(row2[0], arow2[0]);
			Assert::AreEqual(row3[0], arow3[0]);

			Assert::AreEqual(row1[1], arow1[1]);
			Assert::AreEqual(row2[1], arow2[1]);
			Assert::AreEqual(row3[1], arow3[1]);

			Assert::AreEqual(row1[2], arow1[2]);
			Assert::AreEqual(row2[2], arow2[2]);
			Assert::AreEqual(row3[2], arow3[2]);
		}

		TEST_METHOD(SetRow)
		{
			CMatrix3 test = rCMatrix3();
			CMatrix3 test1 = rCMatrix3();

			test1.SetRow(0, test.GetRow(0));
			test1.SetRow(1, test.GetRow(1));
			test1.SetRow(2, test.GetRow(2));

			Assert::AreEqual(test[0], test1[0]);
			Assert::AreEqual(test[1], test1[1]);
			Assert::AreEqual(test[2], test1[2]);

			Assert::AreEqual(test[3], test1[3]);
			Assert::AreEqual(test[4], test1[4]);
			Assert::AreEqual(test[5], test1[5]);

			Assert::AreEqual(test[6], test1[6]);
			Assert::AreEqual(test[7], test1[7]);
			Assert::AreEqual(test[8], test1[8]);
		}

		TEST_METHOD(ConstructorsFltPtr)
		{
			float fltAr[] = { 4.0f, 5.0f, 6.0f,
							4.0f, 5.0f, 6.0f,
							4.0f, 5.0f, 6.0f };

			CMatrix3 test(fltAr);

			Assert::AreEqual(test[0], 4.0f);
			Assert::AreEqual(test[1], 5.0f);
			Assert::AreEqual(test[2], 6.0f);
			Assert::AreEqual(test[3], 4.0f);
			Assert::AreEqual(test[4], 5.0f);
			Assert::AreEqual(test[5], 6.0f);
			Assert::AreEqual(test[6], 4.0f);
			Assert::AreEqual(test[7], 5.0f);
			Assert::AreEqual(test[8], 6.0f);
		}

		TEST_METHOD(ConstructorsSqBrackets_large)
		{
			CMatrix3 test(20000.0f, 50000.0f, 20500.0f,
				20000.0f, 50000.0f, 20500.0f,
				20000.0f, 50000.0f, 20500.0f
			);

			Assert::AreEqual(test[0], 20000.0f);
			Assert::AreEqual(test[1], 50000.0f);
			Assert::AreEqual(test[2], 20500.0f);
			Assert::AreEqual(test[3], 20000.0f);
			Assert::AreEqual(test[4], 50000.0f);
			Assert::AreEqual(test[5], 20500.0f);
			Assert::AreEqual(test[6], 20000.0f);
			Assert::AreEqual(test[7], 50000.0f);
			Assert::AreEqual(test[8], 20500.0f);
		}

		TEST_METHOD(ConstructorsSqBrackets_small)
		{
			CMatrix3 test(0.00001f, 0.00001f, 0.00001f,
				0.00001f, 0.00001f, 0.00001f,
				0.00001f, 0.00001f, 0.00001f
			);

			Assert::AreEqual(test[0], 0.00001f);
			Assert::AreEqual(test[1], 0.00001f);
			Assert::AreEqual(test[2], 0.00001f);
			Assert::AreEqual(test[3], 0.00001f);
			Assert::AreEqual(test[4], 0.00001f);
			Assert::AreEqual(test[5], 0.00001f);
			Assert::AreEqual(test[6], 0.00001f);
			Assert::AreEqual(test[7], 0.00001f);
			Assert::AreEqual(test[8], 0.00001f);
		}


		TEST_METHOD(multiply)
		{
			CMatrix3 test = rCMatrix3();
			CMatrix3 test1 = rCMatrix3();

			ACMatrix3 atest = ACMatrix3FromCMatrix3(test);
			ACMatrix3 atest1 = ACMatrix3FromCMatrix3(test1);

			CMatrix3 result = test * test1;
			ACMatrix3 aresult = atest * atest1;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[2] - aresult[2]) < FLT_EPSILON);

			Assert::IsTrue(abs(result[3] - aresult[3]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[4] - aresult[4]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[5] - aresult[5]) < FLT_EPSILON);

			Assert::IsTrue(abs(result[6] - aresult[6]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[7] - aresult[7]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[8] - aresult[8]) < FLT_EPSILON);
		}

		TEST_METHOD(multiplyInPlace)
		{
			CMatrix3 test = rCMatrix3();
			CMatrix3 test1 = rCMatrix3();

			ACMatrix3 atest = ACMatrix3FromCMatrix3(test);
			ACMatrix3 atest1 = ACMatrix3FromCMatrix3(test1);

			test *= test1;
			atest *= atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);

			Assert::IsTrue(abs(test[3] - atest[3]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[4] - atest[4]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[5] - atest[5]) < FLT_EPSILON);

			Assert::IsTrue(abs(test[6] - atest[6]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[7] - atest[7]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[8] - atest[8]) < FLT_EPSILON);
		}

		TEST_METHOD(multiplyScalar)
		{
			CMatrix3 test = rCMatrix3();
			ACMatrix3 atest = ACMatrix3FromCMatrix3(test);

			float c = ((float)(rand() % 10000) + 1000) - 5000;

			CMatrix3 result = test * c;
			ACMatrix3 aresult = atest * c;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[2] - aresult[2]) < FLT_EPSILON);

			Assert::IsTrue(abs(result[3] - aresult[3]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[4] - aresult[4]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[5] - aresult[5]) < FLT_EPSILON);

			Assert::IsTrue(abs(result[6] - aresult[6]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[7] - aresult[7]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[8] - aresult[8]) < FLT_EPSILON);
		}

		TEST_METHOD(multiplyScalarInPlace)
		{
			CMatrix3 test = rCMatrix3();
			ACMatrix3 atest = ACMatrix3FromCMatrix3(test);

			float c = ((float)(rand() % 10000) + 1000) - 5000;

			test *= c;
			atest *= c;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);

			Assert::IsTrue(abs(test[3] - atest[3]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[4] - atest[4]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[5] - atest[5]) < FLT_EPSILON);

			Assert::IsTrue(abs(test[6] - atest[6]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[7] - atest[7]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[8] - atest[8]) < FLT_EPSILON);
		}

		TEST_METHOD(add)
		{
			CMatrix3 test = rCMatrix3();
			CMatrix3 test1 = rCMatrix3();

			ACMatrix3 atest = ACMatrix3FromCMatrix3(test);
			ACMatrix3 atest1 = ACMatrix3FromCMatrix3(test1);

			CMatrix3 result = test + test1;
			ACMatrix3 aresult = atest + atest1;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[2] - aresult[2]) < FLT_EPSILON);

			Assert::IsTrue(abs(result[3] - aresult[3]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[4] - aresult[4]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[5] - aresult[5]) < FLT_EPSILON);

			Assert::IsTrue(abs(result[6] - aresult[6]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[7] - aresult[7]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[8] - aresult[8]) < FLT_EPSILON);
		}

		TEST_METHOD(addInPlace)
		{
			CMatrix3 test = rCMatrix3();
			CMatrix3 test1 = rCMatrix3();

			ACMatrix3 atest = ACMatrix3FromCMatrix3(test);
			ACMatrix3 atest1 = ACMatrix3FromCMatrix3(test1);

			test += test1;
			atest += atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);

			Assert::IsTrue(abs(test[3] - atest[3]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[4] - atest[4]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[5] - atest[5]) < FLT_EPSILON);

			Assert::IsTrue(abs(test[6] - atest[6]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[7] - atest[7]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[8] - atest[8]) < FLT_EPSILON);
		}

		TEST_METHOD(subtract)
		{
			CMatrix3 test = rCMatrix3();
			CMatrix3 test1 = rCMatrix3();

			ACMatrix3 atest = ACMatrix3FromCMatrix3(test);
			ACMatrix3 atest1 = ACMatrix3FromCMatrix3(test1);

			CMatrix3 result = test - test1;
			ACMatrix3 aresult = atest - atest1;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[2] - aresult[2]) < FLT_EPSILON);

			Assert::IsTrue(abs(result[3] - aresult[3]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[4] - aresult[4]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[5] - aresult[5]) < FLT_EPSILON);

			Assert::IsTrue(abs(result[6] - aresult[6]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[7] - aresult[7]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[8] - aresult[8]) < FLT_EPSILON);
		}

		TEST_METHOD(rotateX)
		{
			CMatrix3 test = rCMatrix3();

			ACMatrix3 atest = ACMatrix3FromCMatrix3(test);
			
			float c = ((float)(rand() % 10000) + 1000) - 5000;

			CMatrix3 result = test.RotateX(c);
			ACMatrix3 aresult = atest.RotateX(c);

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[2] - aresult[2]) < FLT_EPSILON);

			Assert::IsTrue(abs(result[3] - aresult[3]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[4] - aresult[4]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[5] - aresult[5]) < FLT_EPSILON);

			Assert::IsTrue(abs(result[6] - aresult[6]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[7] - aresult[7]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[8] - aresult[8]) < FLT_EPSILON);
		}

		TEST_METHOD(rotateY)
		{
			CMatrix3 test = rCMatrix3();

			ACMatrix3 atest = ACMatrix3FromCMatrix3(test);

			float c = ((float)(rand() % 10000) + 1000) - 5000;

			CMatrix3 result = test.RotateY(c);
			ACMatrix3 aresult = atest.RotateY(c);

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[2] - aresult[2]) < FLT_EPSILON);

			Assert::IsTrue(abs(result[3] - aresult[3]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[4] - aresult[4]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[5] - aresult[5]) < FLT_EPSILON);

			Assert::IsTrue(abs(result[6] - aresult[6]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[7] - aresult[7]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[8] - aresult[8]) < FLT_EPSILON);
		}

		TEST_METHOD(rotateZ)
		{
			CMatrix3 test = rCMatrix3();

			ACMatrix3 atest = ACMatrix3FromCMatrix3(test);

			float c = ((float)(rand() % 10000) + 1000) - 5000;

			CMatrix3 result = test.RotateZ(c);
			ACMatrix3 aresult = atest.RotateZ(c);

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[2] - aresult[2]) < FLT_EPSILON);

			Assert::IsTrue(abs(result[3] - aresult[3]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[4] - aresult[4]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[5] - aresult[5]) < FLT_EPSILON);

			Assert::IsTrue(abs(result[6] - aresult[6]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[7] - aresult[7]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[8] - aresult[8]) < FLT_EPSILON);
		}

		TEST_METHOD(subtractInPlace)
		{
			CMatrix3 test = rCMatrix3();
			CMatrix3 test1 = rCMatrix3();

			ACMatrix3 atest = ACMatrix3FromCMatrix3(test);
			ACMatrix3 atest1 = ACMatrix3FromCMatrix3(test1);

			test -= test1;
			atest -= atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);

			Assert::IsTrue(abs(test[3] - atest[3]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[4] - atest[4]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[5] - atest[5]) < FLT_EPSILON);

			Assert::IsTrue(abs(test[6] - atest[6]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[7] - atest[7]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[8] - atest[8]) < FLT_EPSILON);
		}

		TEST_METHOD(equality)
		{
			CMatrix3 test = rCMatrix3();
			CMatrix3 test1 = copyCMatrix(test);

			CMatrix3 test2 = rCMatrix3();

			Assert::IsTrue(test == test1);
			Assert::IsFalse(test == test2);

			Assert::IsTrue(test != test2);
			Assert::IsFalse(test != test1);
		}
	};
}
