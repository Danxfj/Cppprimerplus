#include<iostream>
#include<string>
using namespace std;
int main()
{
	string firstName;
	string lastName;
	char grade;
	int age;

	cout << "What is your first name? ";
	getline(cin,firstName);
	cout << "What is your last name?";
	getline(cin,lastName);
	cout << "What letter grade do you deserve?";
	cin >> grade;
	cout << "What is your age?";
	cin >> age;

	cout << "Name: " << lastName << ", " << firstName << endl;
	cout << "Grade: " << char(grade + 1) << endl;
	cout << "Age: " << age;
	return 0;
}