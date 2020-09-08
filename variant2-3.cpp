#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char letter;
	int quantity;
	cout << "Enter the quantity of variants: ";
	cin >> quantity;
	cout << "Enter the name: "; 
	cin >> letter;
	//int code = static_cast<int>((unsigned char)letter);
	//cout << code << endl;
	cout << "Your variant: " << letter % quantity + 1 << endl;
	return 0;
}