#include <iostream>
using namespace std;

class Matrix{
    int row, col;
    int **matrix;
    
    public:
    Matrix(int r, int c){
        row = r;
        col = c;
        matrix = new int *[row];
        for(int i = 0; i<row; i++){
            matrix[i] = new int[col];
        }
    }
    
    ~Matrix(){
        for(int i = 0; i < row; i++){
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    
    void read(){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cin >> matrix[i][j];
            }
        }
    }
    
    void display(){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    Matrix operator+(const Matrix &m){
        Matrix result(row,col);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                result.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
            }
        }
        return result;
    }
    Matrix operator-(const Matrix &m){
        Matrix result(row,col);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                result.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
            }
        }
        return result;
    }
};

int main(){
    int r,c;
    cin >> r >> c;
    
    Matrix m1(r,c), m2(r,c);
    m1.read();
    m2.read();
    
    cout <<"Addition: " << endl;
    Matrix result = m1 + m2;
    result.display();
    
    cout << "Subtraction: " << endl;
    result = m1 - m2;
    result.display();
    
    return 0;
}



