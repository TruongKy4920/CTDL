#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <math.h>
#define MAX 100
using namespace std;

std::ifstream input("input.txt");
std::ofstream output("output.txt");
struct Matrix
{
    int **arr;
    int m,n;
    Matrix(int hang,int cot): m(hang), n(cot){
        arr=new int*[m];
        for(int i=0;i<m;i++){
            arr[i]= new int [n];
        }
    }
    void print(){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) cout<<arr[i][j]<<" ";
            cout<<"\n";
        }
    }
    void set_value(int value,int i,int j){
        arr[i][j]=value;
    }
    Matrix& Multiply(const Matrix& matrix){
        int *temp= new int[m*matrix.n];
        int count=0;
        if(n==matrix.m){
            for(int i=0;i<m;i++){
                for(int j=0;j<matrix.n;j++){
                    
                    for(int k=0;k<n;k++){
                       temp[count]+=arr[i][k]*matrix.arr[k][j];
                    }
                    count++;
                }
            }
            count=0;
        }
        n=matrix.n;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                set_value(temp[count],i,j);
                count++;
            }
        }

        return *this;
    }
};

int main(){
    Matrix a(3,2);
    Matrix b(2,3);
    int value=1;
    int value2=1;
     for(int i=0;i<a.m;i++){
            for(int j=0;j<a.n;j++) {
                a.set_value(value++,i,j);
            }
        }
         for(int i=0;i<b.m;i++){
            for(int j=0;j<b.n;j++) {
                b.set_value(value2++,i,j);
            }
        }
   a.Multiply(b);
   a.print();
}