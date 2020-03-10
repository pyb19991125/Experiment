#include "pch.h"
#include "CppUnitTest.h"
#include <cassert>
#include <iostream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

struct Line {
	int A;
	int B;
	int C;
};
struct Point {
	double x;
	double y;
};

namespace test
{
	TEST_CLASS(test)
	{
	public:
		cross_point* cross = new cross_point();
		Line line[10][10];
		int n[10];
		vector<struct Point> points[10];
		TEST_METHOD(TestMethod1)
		{
			n[0] = cross->input_and_deal("input1.txt", line[0]);
			n[1] = cross->input_and_deal("input2.txt", line[1]);
			n[2] = cross->input_and_deal("input3.txt", line[2]);
			n[3] = cross->input_and_deal("input4.txt", line[3]);
			n[4] = cross->input_and_deal("input5.txt", line[4]);
			Assert::IsTrue(line[4][0].A == -4);
			Assert::IsTrue(line[4][0].B == 1);
			Assert::IsTrue(line[4][0].C == -6);
			Assert::IsTrue(line[4][1].A == -2);
			Assert::IsTrue(line[4][1].B == 1);
			Assert::IsTrue(line[4][1].C == -4);
			Assert::IsTrue(line[4][2].A == 9);
			Assert::IsTrue(line[4][2].B == 2);
			Assert::IsTrue(line[4][2].C == -19);
			Assert::IsTrue(line[4][3].A == 0);
			Assert::IsTrue(line[4][3].B == 2);
			Assert::IsTrue(line[4][3].C == -4);
			/*n[5] = cross->input_and_deal("input6.txt", line[5]);
			n[6] = cross->input_and_deal("input7.txt", line[6]);
			n[7] = cross->input_and_deal("input8.txt", line[7]);
			n[8] = cross->input_and_deal("input9.txt", line[8]);
			n[9] = cross->input_and_deal("input10.txt", line[9]);*/
			cross->add_point(n[0], line[0], &points[0]);
			cross->add_point(n[1], line[1], &points[1]);
			cross->add_point(n[2], line[2], &points[2]);
			cross->add_point(n[3], line[3], &points[3]);
			cross->add_point(n[4], line[4], &points[4]);
			/*cross->add_point(n[5], line[5], points[5]);
			cross->add_point(n[6], line[6], points[6]);
			cross->add_point(n[7], line[7], points[7]);
			cross->add_point(n[8], line[8], points[8]);
			cross->add_point(n[0], line[9], points[9]);*/
			Assert::IsTrue((cross->point_number(&points[0])) == 1);
			Assert::IsTrue((cross->point_number(&points[1])) == 0);
			Assert::IsTrue((cross->point_number(&points[2])) == 3);
			Assert::IsTrue((cross->point_number(&points[3])) == 7);
			Assert::IsTrue((cross->point_number(&points[4])) == 12);
			/*Assert::IsTrue(cross->point_number(points[5]) == 1);
			Assert::IsTrue(cross->point_number(points[6]) == 1);
			Assert::IsTrue(cross->point_number(points[7]) == 1);
			Assert::IsTrue(cross->point_number(points[8]) == 1);
			Assert::IsTrue(cross->point_number(points[9]) == 1);*/
		}

		TEST_METHOD(TestMethod4)
		{
			Assert::IsTrue(cross->Maximum_common_factor(-20, -4)==4);
			Assert::IsTrue(cross->Maximum_common_factor(-1011, 11)== 1);
			Assert::IsTrue(cross->Maximum_common_factor(99, 33)== 33);
			Assert::IsTrue(cross->Maximum_common_factor(11, -10)== 1);
			Assert::IsTrue(cross->Maximum_common_factor(50, 24)==2);
			Assert::IsTrue(cross->Maximum_common_factor(-120, 80)== 40);
			Assert::IsTrue(cross->Maximum_common_factor(-220, -40)==20);
			Assert::IsTrue(cross->Maximum_common_factor(-100000, 10)== 10);
			Assert::IsTrue(cross->Maximum_common_factor(3, -2)==1);
			Assert::IsTrue(cross->Maximum_common_factor(-9, 5)==1);
		}
	};
}
