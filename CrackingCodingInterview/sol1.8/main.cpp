#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector <int>> matrix = { {1, 2, 3}, 
                                    {4, 0, 6},
                                    {0, 8, 9}
                                  };

    bool rowZero = false;
    bool colZero = false;
    for(int i = 0; i < matrix.size(); i++)
        for(int j = 0; j < matrix.size(); j++) {
            if (matrix[i][j] == 0) {
                if (i == 0 || j ==0) { 
                    if (i == 0)
                        colZero = true;
                    if (j == 0)
                        rowZero = true;
                } else {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
    for (int i = 1; i < matrix.size(); i++)
        if (matrix[0][i] == 0)
            for( int j = 1; j < matrix.size(); j++)
                matrix [j][i] = 0;


    for (int i = 1; i < matrix.size(); i++)
        if (matrix[i][0] == 0)
            for( int j = 1; j < matrix.size(); j++)
                matrix [i][j] = 0;


    if (rowZero == true)
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][0] = 0;

    if (colZero == true)
        for (int i = 0; i < matrix.size(); i++)
            matrix[0][i] = 0;

    cout << "Printing matrix:\n";
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix.size(); j++)
            cout << matrix[i][j];
        cout << endl;
    }


    return 0;
}
