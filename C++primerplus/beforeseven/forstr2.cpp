#include<iostream>
#include<string>
int main()
{
	using namespace std;
	string word;
	cout << "Enter a word: ";
	cin >> word;

	char temp;
	int i, j;
	for (j = 0, i = word.size() - 1; j < i; j++, i--)
	{
		temp = word[i];
		word[i] = word[j];
		word[j] = temp;
	}
	cout << word << "\nDone\n";
	return 0;
}