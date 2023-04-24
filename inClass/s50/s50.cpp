#include <iostream>
using namespace std;

const int ROW = 10;
const int COL = 10;

//Fill it with random
//Print it
void FillMatrix(int mat[][COL], int& row, int& col);
void PrintMatrix(int mat[][COL], int row, int col); 

int main(){
    
    int matrix[ROW][COL] = {{1,2,3}, {5,6,7}};
    int row = 2;
    int col = 3;

    PrintMatrix(matrix,row,col);
    FillMatrix(matrix, row, col);
    PrintMatrix(matrix,row,col);
    return 0;
}

void FillMatrix(int mat[][COL], int& row, int& col){
    row = rand() % ROW + 1;
    col = rand() % COL + 1;
    for(int r = 0; r < row; ++r)
        for(int c = 0; c < col && mat[r][c] = rand() % 1000; ++c); 
     

}

void PrintMatrix(int mat[][COL], int row, int col){
    cout << "inside PrintMatrix()" << endl;
    for (int r = 0; r < row && cout << endl; ++r)
        for (int c = 0; c < col && cout << mat[r][c]; ++c); 
}
