//Выбор варианта по номеру в списке
#include <iostream>
using namespace std;

int main()
{
	int number, quantity, variant;
	cin >> number >> quantity;
	variant = number % quantity +1;
	cout << variant << endl;
	return 0;
}