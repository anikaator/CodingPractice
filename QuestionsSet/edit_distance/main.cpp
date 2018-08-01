class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        int changes = 0;
        int i = 0; 
        int j = 0;
        while (i < m && j < n) {
            if(word1[i] != word2[j]) {
                //cout << i << ":" << word1[i] << "--" << j << ":" << word2[j] <<endl;
                if (word1[i] == word2[j+1]) {
                    changes++;
                    cout << "Insert " << i << ":" << word1[i] << "--" << j << ":" << word2[j] <<endl;

                    j++;
                } else if (word1[i+1] == word2[j]) {
                    changes++;
                    cout << "Remove " << i << ":" << word1[i] << "--" << j << ":" << word2[j] <<endl;                    
                    i++;
                } else {
                    changes++;
                    cout << "Replace " << i << ":" << word1[i] << "--" << j << ":" << word2[j] <<endl;                    
                    i++;
                    j++;                    
                }                                    
            } else {
                //cout << "Increment  " << i << ":" << word1[i] << "--" << j << ":" << word2[j] <<endl;                
                i++; j++;
            }
        }
        while (i < m){
            changes++;
            cout << "Remove " << i << ":" << word1[i] <<endl;
            i++;
        }
        while (j < n){
            changes++;
            cout << "Remove " << j << ":" << word2[j] <<endl;
            j++;
        }
        return changes;
    }
};
