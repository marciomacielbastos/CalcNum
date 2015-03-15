#include <iostream>
using namespace std;

class Matrix{
    private: int rows;
    private: int cols;
    private: float** matrix;
    public: Matrix():matrix(NULL),rows(0),cols(0){}
    public: Matrix(int rows,int cols):rows(rows),cols(cols){
        matrix =new (nothrow) float*[rows];
        for(int i=0;i<3;i++){
            matrix[i]=new (nothrow) float[cols];
        }
    }
    public: Matrix(float **matrix){
        this->matrix=matrix;
    }
    public: int numbRows(){
        return this->rows;
    }
    public: int numbCols(){
        return this->cols;
    }
    public: float** getMatrix(){
            return this->matrix;
    }
    public: void setMatrix(){
        for(int i=0;i<this->rows;i++){
            for(int j=0;j<this->cols;j++){
                cout<<"Set elem: A["<<i+1<<"]["<<j+1<<"]"<<endl;
                cin>>matrix[i][j];
            }
        }
    }
    public: void setMatrix(float **matrix){
        this->matrix=matrix;
    }



};

int main ()
{
    float **matrix;
    matrix =new (nothrow) float*[3];
    for(int i=0;i<3;i++){
        matrix[i]=new (nothrow) float[3];
    }
    float k=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            matrix[i][j]=i+j+k;
        }
        k+=32.15;
    }
    Matrix matrixx=Matrix(matrix);
    Matrix matriz=Matrix(3,3);
    matriz.setMatrix(matrix);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<matriz.getMatrix()[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
