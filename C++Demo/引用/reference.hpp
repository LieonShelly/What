#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

enum Season {
	Spring,
	Summer,
	Fall,
	Winter
};

struct Student {
	int age;
};

int test111() {
    int v1 = 20;
    int v2 = 30;
    swap(v1, v2);

    /// 定一个引用相当于给变量给起别名
    int age = 20;
    int &rage = age;
    rage = 20;

//    int *p = &age;

    int &rage1 = rage;
    int &rage2 = rage1;

    Season season;
    Season &rSeason = season;
    rSeason = Winter;

    Student stu;
    Student &rStu = stu;
    rStu.age = 20;

    int a = 10;
    int b = 20;
    int *p = &a;

    int *&rP = p;

    rP = &b;
    *rP = a;
    *p = 30;

    int array[4] = {10, 20, 30, 10};
    int rA[3] = {10, 10, 20};
    int (&rArray)[3] = rA;
    int *c[4] = {p, p, p, p};
    int (*d)[4] = &array;
    rArray[0] = 100;
    cout << "a: " << a << "  rArray[0]: " << rArray[0] << endl;
    return 0;
}
