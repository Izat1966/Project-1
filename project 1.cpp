/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n,a,b,cnt = 0, moves = 0;
    int minelement=6;
    int maxelement=20;
    cout<<"Enter the size of an array (6-20)"<<endl;
    cin>>n;
    if (n<minelement || n>maxelement) {
        cout << "Invalid array size. Please enter a value between 6 and 20" << endl;
        return 1;
    }
    vector<int> arr(n);
    vector<int> found(n, 0);

    arr={1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10};
    arr.resize(n);
    random_device rd;
    default_random_engine rng(rd());
    shuffle(arr.begin(), arr.end(), rng);

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
        if (arr[a] == arr[b] && a!=b && a>=0 && b>=0) {
            cout << "These numbers are equal" << endl;
            found[a] = 1;
            found[b] = 1;
            cnt += 2;
        } else if (a==b) {
            cout << "The indices are two same numbers , they must be different" << endl;
        }else if (a<0 || b<0) {
            cout << "Invalid indices"<<endl;
        }else {
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
