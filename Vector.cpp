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

struct Vector {
    int* arr;
    int length;
    Vector(){
        arr=NULL;
        length=0;
    }
    ~Vector(){}
    int& operator[](int index){
        return arr[index];
    }
    int binary_search(int start,int end,int value){
        while(start<=end){
        int mid= (start+end)/2;
        if(arr[mid]==value) return mid;
        else if(arr[mid]<value) start=mid+1;
        else end=mid-1;
        }
        return -1;
    }
    void del(int value){
        if(arr[0]==value){
            int* temp= new int[length-1];
            int j=0;

            for(int i=1;i<length;i++) temp[j++]=arr[i];
            length--;
            delete[] arr;
            arr=temp;
            
        }
        else if(arr[length-1]==value){
            int* temp= new int[length-1];

            for(int i=0;i<length-1;i++) temp[i]=arr[i];
            length--;
            delete[] arr;
            arr=temp;
           
        }
        else {
            int del_index=binary_search(0,length,value);
            int* temp=new int[length-1];
            int j=del_index;

            for(int i=0;i<del_index;i++)  temp[i]=arr[i];
            
            for(int i=del_index+1;i<length;i++){
                temp[j]=arr[i];
                j++;
            }
            length--;
            delete[] arr;
            arr=temp;
            
        }

    }
    void push_back(int value){
        if(arr==NULL){
            arr= new int[1];
            arr[0]=value;
            length++;
            return;
        }
        int *temp=new int[length+1];
        for (int i=0;i<length;i++){
            temp[i]=arr[i];
        }
        temp[length++]=value;
        delete[] arr;
        arr=temp;
    }
    void insert(int value,int index){
            if(index==0){
                int* temp= new int[length+1];
                temp[0]=value;
                int j=1;
                for(int i=0;i<length;i++) temp[j++]=arr[i];

                delete[] arr;
                arr=temp;
                length++;
            }
            else if(index==length-1){
                int* temp= new int[length+1];
                temp[index]=value;
                int j=index-1;
                for(int i=length-1;i>=0;i--) temp[j--]=arr[i];
            
                delete[] arr;
                arr=temp;
                length++;
            }
            else {
                int* temp=new int[length+1];
                
                
                for(int i=0;i<index;i++)  temp[i]=arr[i];
                temp[index]=value;
                int j=index+1;
                for(int i=index;i<length;i++){
                    temp[j]=arr[i];
                    j++;
                }
                length++;
                delete[] arr;
                arr=temp;
                
            }

        }
        
    
};


int main(){
    
      Vector a;
      a.push_back(2);
      a.push_back(4);
      a.push_back(8);
      a.push_back(0);
      a.push_back(6);
      
      for(int i=0;i<a.length;i++){
        cout<<a[i]<<" ";
      }
      
      
}