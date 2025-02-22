#include <iostream>
#include <fstream>
#include <string>
#include<cstdlib>


int main() {

    using namespace std;
    const int Grand_Amount = 10000;
    string file_name;
    ifstream in_file_handle;

    struct Patron {
        string name;
        double amount;
    };

    int contribute_num = 0;
    cout << "Enter a file name: ";

    getline(cin, file_name);  // ��һ���У���ĩ�س����ų�
    in_file_handle.open(file_name.c_str());

    if (!in_file_handle.is_open())
    {
        cout << "can't open file " << file_name << endl;
        exit(EXIT_FAILURE);
    }

    in_file_handle >> contribute_num;
    in_file_handle.get();  // �����հ�(������������ĩ�Ļس���)

    Patron* p_contribution = new Patron[contribute_num];
    for (int i = 0; i < contribute_num; ++i) {
        /*
         * 4 Sam Stone
         * 2000
         * Freida Flass
         * 100500
         * Tammy Tubbs
         * 5000
         * Rich Raptor
         * 55000
         *
         */
        getline(in_file_handle, p_contribution[i].name);
        in_file_handle >> p_contribution[i].amount;
        in_file_handle.get();   // �����հ�(������������ĩ�Ļس���)
    }
    in_file_handle.close();

    unsigned int grand_amount_n = 0;
    cout << "\nGrand patron: " << endl;
    for (int i = 0; i < contribute_num; ++i) {

        if (p_contribution[i].amount > Grand_Amount) {
            cout << "Contributor name: " << p_contribution[i].name << "\n"
                << "Contributor amount: " << p_contribution[i].amount << endl;
            ++grand_amount_n;
        }
    }

    if (grand_amount_n == 0) {
        cout << "None" << endl;
    }

    bool is_empty = true;
    cout << "\nPatrons: " << endl;
    for (int i = 0; i < contribute_num; ++i) {
        cout << "Contributor name: " << p_contribution[i].name << "\n"
            << "Contributor amount: " << p_contribution[i].amount << endl;

        is_empty = false;
    }

    if (is_empty) {
        cout << "** None **" << endl;
    }

    delete[] p_contribution;
    return 0;
}