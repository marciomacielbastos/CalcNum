#include <iostream>
#include <cmath>
using namespace std;

class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "A exception happened";
  }
} myex;

class Matrix{
    private: int rows;
    private: int cols;
    private: float** matrix;
    private: float D;
    public: Matrix():matrix(NULL),rows(0),cols(0),D(0){}
    public: Matrix(int rows,int cols):rows(rows),cols(cols),D(0){
        try{
            matrix =new float*[rows];
            for(int i=0;i<rows;i++){
                matrix[i]=new float[cols];
            }
        }
        catch(exception e){
            cerr<<e.what()<<endl;
        }
    }
    public: Matrix(int r, int c,float **matrix):rows(r),cols(c),matrix(matrix){
        this->D=Det();
    }
    public: int getRows(){
        return this->rows;
    }
    public: int getCols(){
        return this->cols;
    }
    public: float det(){
        try{
            if(rows!=cols){
             throw myex;
            }
            else
                return D;
        }
        catch(exception e){
            cerr<<e.what()<<endl;
        }
    }
    public: float** getMatrix(){
            return this->matrix;
    }
    public: void setMatrix(){
        try{
            for(int i=0;i<this->rows;i++){
                for(int j=0;j<this->cols;j++){
                    cout<<"Set elem: A["<<i+1<<"]["<<j+1<<"]"<<endl;
                    cin>>matrix[i][j];
                }
            }
            this->D=Det();
        }
        catch(exception e){
            cerr<<e.what()<<endl;
        }
    }
    public: void setMatrix(int r, int c,float value){
        try{
            matrix[r][c]=value;
            this->D=Det();
        }
        catch(exception e){
            cerr<<e.what()<<endl;
        }
    }
    private: float Det(){
        try{
            float det=1,p;
            int I=0;
            float a;
            if(rows==cols){
                float **mat=new float *[rows];
                for(int i=0;i<rows;i++){
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
                if(det==0||abs(det)<(1/float(100000))){
                return 0;
            }
            else
                return det;
            }
        }
        catch(exception e){
            cerr<<e.what()<<endl;
        }
    }
    public: Matrix operator *(Matrix& that){
        try{

                if(cols!=that.getRows()){
                    throw myex;
                }
                int c;
                Matrix result=Matrix(rows,that.getCols());
                for(int i=0;i<rows;i++){
                    for(int k=0;k<that.getCols();k++){
                        c=0;
                        for(int j=0;j<that.getCols();j++){
                            c+=matrix[i][j]*that.getMatrix()[j][k];
                        }
                        result.setMatrix(i,k,c);
                    }
                }
                return result;
        }
        catch(exception e){
            cerr<<e.what()<<endl;
        }
    }
    public: Matrix operator ,(Matrix& that){
        try{
            if(this->rows!=that.getRows()&&this->cols!=that.getCols()){
                throw myex;
            }
            Matrix result=Matrix(rows,cols);
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    result.setMatrix(i,j,this->matrix[i][j]*that.getMatrix()[i][j]);
                }
            }
            return result;
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
    public: Matrix inv(){
        try{
                if(rows!=cols||D==0){
                    throw myex;
                }
                Matrix inv=Matrix(rows,cols);
                for(int i=0;i<rows;i++){
                        inv.setMatrix(i,i,1);
                }

        }
        catch(exception e){
            cerr<<e.what()<<endl;
        }
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
    Matrix A=Matrix(3,3,matrix);
    Matrix B=Matrix(3,3);
    B.setMatrix();
    cout<<"det="<<B.det()<<endl;
    Matrix C = B;
    for(int i=0;i<C.getRows();i++){
        for(int j=0;j<C.getCols();j++){
            cout<<C.getMatrix()[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
