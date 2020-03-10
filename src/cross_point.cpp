#include <iostream>
#include <vector>
#include<fstream>
#include "cross_point.h"
#define maxlineNumber 500000
#define eps 1e-20
using namespace std;
cross_point::cross_point() {}
struct Line {
	int A;
	int B;
	int C;
};
struct Point {
	double x;
	double y;
};

int cross_point::Maximum_common_factor(const int x, const int y) {
	int remainder, divider, dividend;
	int a = x;
	int b = y;
	if (a < 0) {
		a = -a;
	}
	if (b < 0) {
		b = -b;
	}
	if (a >= b) {
		dividend = a;
		divider = b;
	}
	else {
		dividend = b;
		divider = a;
	}
	while (1) {
		remainder = dividend % divider;
		if (remainder == 0) {
			break;
		}
		else {
			dividend = divider;
			divider = remainder;
		}
	}
	return divider;
}
int cross_point::str2int(char* s) {
	int i = 0;
	int number = 0;
	if (!((s[0] <= '9') && (s[0] >= '0'))) {
		if (s[1] == '\0') {
			return (int)s[0];
		}
		else {
			i = 1;
		}
	}
	for (; s[i] != '\0'; i++) {
		number = number * 10 + (s[i] - '0');
	}
	if (s[0] == '-') {
		return -number;
	}
	return number;
}

int cross_point::input_and_deal(const char *file, Line* line) {
	int n;
	char buffer[100];
	char c[10][100];
	ifstream readfile(file);
	readfile.getline(buffer, sizeof(buffer));
	n = str2int(buffer);
	//Ax+By+C=0
	int i, left_x, left_y, right_x, right_y, A, B, C, temp, i1, i2, i3;
	for (i = 0; i < n; i++) {
		readfile.getline(buffer, sizeof(buffer));
		i2 = 0;
		i3 = 0;
		for (i1 = 0; buffer[i1]!='\0'; i1++) {
			if (buffer[i1] == ' ')
			{
				c[i2][i3] = '\0';
				i3 = 0;
				i2++;
				continue;
			}
			else {
				c[i2][i3] = buffer[i1];
				i3++;
			}
		}
		c[i2][i3] = '\0';
		left_x = str2int(c[1]);
		left_y = str2int(c[2]);
		right_x = str2int(c[3]);
		right_y = str2int(c[4]);
		A = left_y - right_y;
		B = -(left_x - right_x);
		C = -A * left_x - B * left_y;
		if ((A != 0) && (B != 0)) {
			temp = Maximum_common_factor(A, B);
			A = A / temp;
			B = B / temp;
			C = C / temp;
		}
		if (B < 0) {
			A = -A;
			B = -B;
			C = -C;
		}
		line[i].A = A;
		line[i].B = B;
		line[i].C = C;
	}
	return n;
}

void cross_point::add_point(const int n, const Line * line, vector<struct Point>* points) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if ((line[i].A==line[j].A)&&(line[i].B == line[j].B)) {
				continue;
			}
			else {
				double A1 = line[i].A;
				double A2 = line[j].A;
				double B1 = line[i].B;
				double B2 = line[j].B;
				double C1 = line[i].C;
				double C2 = line[j].C;
				Point p;
				if (A1 == 0) {
					p.y = -C1/B1;
					p.x = (B2 * C1 - B1 * C2)/ (A2 * B1);
				}
				else if (B1 == 0) {
					p.x = -C1/ A1;
					p.y = (A2 * C1 - A1 * C2)/(A1 * B2);
				}
				else if (A2 == 0) {
					p.y = -C2/ B2;
					p.x = (B1 * C2 - B2 * C1)/(A1 * B2);
				}
				else if (B2 == 0) {
					p.x = -C2/ A2;
					p.y = (A1 * C2 - A2 * C1)/ A2 * B1;
				}
				else {
					p.y = (A1 * C2 - A2 * C1) / (B1 * A2 - A1 * B2);
					p.x = (B1 * C2 - B2 * C1)/(A1 * B2 - A2 * B1);
				}
				points->push_back(p);
			}
		}
	}
}

int cross_point::point_number(const vector<struct Point> *points) {
	int number = points->size();
	int i,j;
	int count = 0;
	if (number != 0) {
		count++;
	}
	for (i = 0; i < number - 1; i++) {
		for (j = i + 1; j < number; j++) {
			if ((abs((*points)[i].x - (*points)[j].x) < eps) && (abs((*points)[i].y - (*points)[j].y) < eps)) {
				break;
			}
		}
		if (j != number) {
			continue;
		}
		else {
			count++;
		}
	}
	return count;
}

int main(int argc, char** argv) {
	Line* line=(Line*)malloc(sizeof(struct Line)*maxlineNumber);
	vector<struct Point> points;
	cross_point* c = new cross_point();
	int n = c->input_and_deal(argv[2],line);
	c->add_point(n,line,&points);
	ofstream writefile(argv[4]);
	writefile << (c->point_number(&points));
	return 0;
}