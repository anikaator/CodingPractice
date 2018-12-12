
- You can use transform to run through the list(array, vector, string)
- istringstream will separate out string from space, remember it only split with space other special char are included.

```cpp
#include <string>
#include <iostream>
using namespace std; 


int main() 
{ 
    string name = "God is almight";
    transform(name.begin(), name.end(), name.begin(),::toupper);
    istringstream iss(name);
    string word;
    while(iss >> word) {
        cout << endl << word;
    }
	return 0; 
} 

Output:
GOD
IS
ALMIGHT
```

- Suffle array
```cpp
void randomize ( int arr[], int n ) 
{ 
    // Use a different seed value so that we don't get same 
    // result each time we run this program 
    srand ( time(NULL) ); 
  
    // Start from the last element and swap one by one. We don't 
    // need to run for the first element that's why i > 0 
    for (int i = n-1; i > 0; i--) 
    { 
        // Pick a random index from 0 to i 
        int j = rand() % (i+1); 
  
        // Swap arr[i] with the element at random index 
        swap(&arr[i], &arr[j]); 
    } 
} 
```
