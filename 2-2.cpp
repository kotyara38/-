#include <iostream>
using namespace std;

int main()
{
    int num, space, stars;

    cout << "Enter the quantity of stars: ";
    cin >> num;

    if (num % 2 == 0) {  
        stars = 2;
        space = num / 2 - 1;
        for (int i = 0; i < num; i += 2) {
            cout << endl;
            
            for (int i = space; i != 0; i--) {
                cout << " ";
            }
            for (int j = stars; j != 0; j--) {
                cout << "*";
            }
            stars += 2;
            space--;
        }
    }

   
    else {
        stars = 1;
        space = num/2;
        for (int i = 0; i<num; i+=2) {

            for (int i = space; i != 0; i--) {
                cout << " ";
            }
            for (int j = stars; j != 0; j--) {
                cout << "*";
            }
            cout << endl;
            stars += 2;
            space--;
        }
       
    }

    return 0;
}
