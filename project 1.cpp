/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

int main() {
    int n = 10, a, b, cnt = 0, moves = 0;
    int arr[n] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    int found[n] = {0};
    
    random_device rd;
    default_random_engine rng(rd());
    shuffle(arr, arr + n, rng);
    
    while (true) {
        for (int i = 0; i < n; i++) {
            if (found[i] == 0) {
                cout << "? ";
            } else {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
        cout << "Enter two indices: ";
        cin >> a >> b;
        cout << "The number at index " << a << " is " << arr[a] << endl;
        cout << "The number at index " << b << " is " << arr[b] << endl;
        if (arr[a] == arr[b] && a!=b) {
            cout << "These numbers are equal" << endl;
            found[a] = 1;
            found[b] = 1;
            cnt += 2;
        } else {
            cout << "These numbers are not equal" << endl;
        }
        moves++; 
        if (cnt == n) {
            cout << "Great job! You found " << moves << " moves" << endl;
            break; 
        }
    }
    return 0;
}
