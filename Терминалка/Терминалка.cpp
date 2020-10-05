﻿#include <stdio.h>
#include <math.h>
#include <locale.h>
//#define p 3.1415

int main()
{
	setlocale(LC_ALL, "Rus");
	printf_s("Введите координаты вектора a \n");
	int x1 = 0, y1 = 0, z1 = 0;
	scanf_s("%d %d %d", &x1, &y1, &z1);
	printf("Введите координаты вектора b \n");
	int x2 = 0, y2 = 0, z2 = 0;
	scanf_s("%d %d %d", &x2, &y2, &z2);
	printf("Введите координаты вектора c \n");
	int x3 = 0, y3 = 0, z3 = 0;
	scanf_s("%d %d %d", &x3, &y3, &z3);
	int kom = 0;
	
	if (x1 * (y2 * z3 - y3 * z2) - y1 * (x2 * z3 - x3 * z2) + z1 * (x2 * y3 - x3 * y2) == 0) {
		kom = 1;
		printf_s("Вектора a(%d,%d,%d), b(%d,%d,%d) и с(%d,%d,%d) компланарны \n", x1, y1, z1, x2, y2, z2, x3, y3, z3);

	}
	else printf_s("Вектора a(%d,%d,%d), b(%d,%d,%d) и с(%d,%d,%d) не компланарны \n", x1, y1, z1, x2, y2, z2, x3, y3, z3);
	
	int kol = 0;
	if (y1*z2-y2*z1==0 && x1 * z2 - x2 * z1 == 0 && x1 * y2 - x2 * y1 == 0) {
		printf_s("Вектора a(%d,%d,%d) и b(%d,%d,%d) коллинеарны \n", x1, y1, z1, x2, y2, z2);
		kol ++;
	}
	
	if (y3 * z2 - y2 * z3 == 0 && x3 * z2 - x2 * z3 == 0 && x3 * y2 - x2 * y3 == 0) {
		printf("Вектора b(%d,%d,%d) и c(%d,%d,%d) коллинеарны \n", x2, y2, z2, x3, y3, z3);
		kol++;
	}
	if (y3 * z1 - y1 * z3 == 0 && x3 * z1 - x1 * z3 == 0 && x3 * y1 - x1 * y3 == 0) {
		printf("Вектора a(%d,%d,%d) и c(%d,%d,%d) коллинеарны \n", x1, y1, z1, x3, y3, z3);
		kol ++;
		}
	
	if (kol>1) {
		printf("Ранг системы 1 \n");
	}
	else if (kom==1) printf("Ранг системы 2 \n");
	else printf("Ранг системы 3 \n");
	if (kom == 1 && kol==0) {
		int a = 0, b = 0;
		b = (x2 * y1 - x1 * y2) / (x2 * y3 - x3 * y2);
		a = (x1 - b * x3) / x2;
		printf("a=%d*b + %d*c \n", a,b);
	}
	return 0;
}
