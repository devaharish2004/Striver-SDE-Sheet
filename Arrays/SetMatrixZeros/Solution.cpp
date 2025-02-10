/*
Brute Force:
    Change elements to -1, to keep track of the zeros
    TC : O(N*M) + O(N+M) + O(N*M)
    SC : O(1)
*/

/*
Better Approach :
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<int> rowMatrix(rows,0);
        vector<int> colMatrix(columns,0);
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < columns; col++){
                if(matrix[row][col] == 0){
                    rowMatrix[row] = 1;
                    colMatrix[col] = 1;
                }
            }
        }
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < columns; col++){
                if(rowMatrix[row] == 1 || colMatrix[col] == 1){
                    matrix[row][col] = 0;
                }
            }
        }
    }
};


