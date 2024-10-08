#include<iostream>
template<typename T>
void Swap(T& a, T& b);

struct job
{
	char name[40];
	double salary;
	int floor;
};
template<>  void Swap<job>(job& j1, job& j2);
void show(job& j);
int main()
{
	using namespace std;
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10, j = 20;
	cout << "i,j = " << i << ", " << j << ".\n";
	cout << "Using compiler-generated int swapper:\n";
	Swap(i, j);
	cout << "Now i,j = " << i << ", " << j << ".\n";

	job sue = { "Susan Yaffee", 73000.60,7 };
	job sidney = { "Sidney Taffee",78060.72,9 };
	cout << "Before job swapping:\n";
	show(sue);
	show(sidney);
	Swap(sue, sidney);
	cout << "After job swapping:\n";
	show(sue);
	show(sidney);
	return 0;
}
template<typename T>
void Swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
template<> void Swap<job>(job& j1, job& j2)
{
	double s2;
	int f2;
	s2 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = s2;
	f2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = f2;
}
void show(job& j)
{
	using namespace std;
	cout << j.name << ": $" << j.salary
		<< " on floor " << j.floor << endl;
}