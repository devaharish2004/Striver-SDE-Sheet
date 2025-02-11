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

//TC : O(2*N*M)
//SC : O(N)+O(M)


// Optimal solution :
class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int rows = matrix.size();
            int columns = matrix[0].size();
            //vector<int>rowMatrix -> matrix[..][0]
            //vector<int>colMatrix -> matrix[0][..]
           
            int col0 = 1;
            for(int row = 0; row < rows; row++){
                for(int col = 0; col < columns; col++){
                    if(matrix[row][col] == 0){
                        //mark row
                        matrix[row][0] = 0;
                        //mark col
                        if(col == 0){
                            col0 = 0;
                        }
                        else{
                            matrix[0][col] = 0;
                        }
                    }
                }
            }
            //iterate for all rows and columns except the first ones
            for(int row = 1; row < rows; row++){
                for(int col = 1; col < columns; col++){
                    if(matrix[row][col] != 0){
                        if(matrix[row][0] == 0 || matrix[0][col] == 0){
                            matrix[row][col] = 0;
                        }
                    }
                }
            } 
            //for the first row
            if(matrix[0][0] == 0){
                for(int col = 0; col < columns; col++){
                    matrix[0][col] = 0;
                }
            }
            //for the first col
            if(col0 == 0){
                for(int row = 0; row < rows; row++){
                    matrix[row][0] = 0;
                }
            }
        }
    };

//TC: O(2*N*M)
//SC: O(1)

