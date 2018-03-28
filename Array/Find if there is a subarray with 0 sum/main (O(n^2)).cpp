#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	
	std::vector<int> input = { 4, 2, -3, 1 ,6};
	//std::vector<int> input = {4, 2, 0, 1, -6};
	for (int k=0; k < input.size(); k++){
	    int sum = 0;
    	for(int i=k; i < input.size(); i++) {
    	    sum = sum + input[i];
    	    if (sum == 0) {
    	        printf("Ohhh its zero\n");
    	        for (int j=k; j <= i; j++) {
    	            printf("-->%d", input[j]);
    	        }
    	        printf("\n");
    	    }
    	        
    	    
    	}
	}
	
	return 0;
}
