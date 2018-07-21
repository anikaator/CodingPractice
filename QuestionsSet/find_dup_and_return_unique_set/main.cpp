#include <iostream>
#include <array>
#include <stddef.h>

using namespace std;
int main() {
    array<int,15> arr = {2,2,3,4,5,5,5,6,6,6,7,7,8,9,9};

    cout << "\nArray looks like :\n";
    for (auto &x : arr) {
        cout << "-" << x;
    }
    int *ptr, marker;
    bool second = false;
    for (int i = 0; i < arr.size(); i++) {
        if (i  == 0) {
            ptr = &arr[0];
            marker = arr[0];
            second = false;
            ptr++;
            continue;
        }

        //printf("\nPointer is pointing to : %d - marked %d - index %d - bool %s",*ptr,marker,i,(second ? "true" : "false"));
        if (marker == arr[i]){
            if (second == false) {
                second = true;
                *ptr = arr[i];
                ptr ++;
            } else {
                cout << "\nSkipped :" << arr[i];
            }

        } else {
            marker = arr[i];
            *ptr = arr[i];
            second = false;
            ptr++;
        }
    }

    ptrdiff_t diff = (ptr - &arr[0]);
    cout << "\nLenght of array is : " << diff;
    cout << "\nArray looks like :\n";
    for (auto &x : arr) {
        if (diff == 0) break;
        cout << "-" << x;
        diff--;
    }
    cout <<endl;
    return 0;
}


        


