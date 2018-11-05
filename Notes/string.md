
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
