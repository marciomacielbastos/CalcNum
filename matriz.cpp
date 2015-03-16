#include <iostream>
#include <cmath>
using namespace std;

class Matrix{
    private: int rows;
    private: int cols;
    private: float** matrix;
    public: Matrix():matrix(NULL),rows(0),cols(0){}
    public: Matrix(int rows,int cols):rows(rows),cols(cols){
        try{
            matrix =new float*[rows];
            for(int i=0;i<3;i++){
                matrix[i]=new float[cols];
            }
        }
        catch(exception e){
            cerr<<e.what()<<endl;
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
    public: float det(){
        try{
            float det=1,p;
            int I=0;
            float a;
            if(rows==cols){
                float **mat=new float *[rows];
                for(int i=0;i<3;i++){
                    mat[i]=new float[cols];
                }
                for(int i=0;i<rows;i++){
                    for(int j=0;j<cols;j++){
                        mat[i][j]=matrix[i][j];;
                    }
                }
                while(I<rows && det!=0){
                    pivot(I,mat,&det);
                    p=mat[I][I];
                    det=det*p;
                    if(p){
                        for(int j=I;j<rows;j++){
                            mat[I][j]=mat[I][j]/p;
                        }
                        for(int k=I+1;k<rows;k++){
                            p=mat[k][I];
                            for(int j=I;j<rows;j++){
                                mat[k][j]=mat[k][j]-p*mat[I][j];
                            }
                        }

                    }I++;
                }
            }
            return det;
        }
        catch(exception e){
            cerr<<e.what()<<endl;
        }
    }
    private: void pivot(int I,float **mat,float *det){
        try{
            float c=mat[I][I];
            int l=I;
            for(int k=I+1;k<rows;k++){
                if(abs(c)<abs(mat[k][I])){
                    c=mat[k][I];
                    l=k;
                }
            }
            if(l!=I){
                *det=-*det;
                for(int j=0;j<cols;j++){
                    swap(mat[I][j],mat[l][j]);
                }
            }
        }
        catch(exception e){
            cerr<<e.what()<<endl;
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
        k+=2;
    }
    Matrix matrixx=Matrix(matrix);
    Matrix matriz=Matrix(3,3);
    matriz.setMatrix(matrix);
    matriz.setMatrix();
    cout<<"det="<<matriz.det()<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<matriz.getMatrix()[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
