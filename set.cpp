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
struct Set{
    int *arr;
    int length;
    Set(){
        arr=NULL;
        length=0;
    }
    ~Set(){}
    int& operator[](int index){
        return arr[index];
    }
    void print(){
        for(int i=0;i<length;i++){
            cout<<arr[i]<<" ";
        }
    }
    void insert(int value,int index){
            if(index==0){
                int* temp= new int[length+1];
                temp[0]=value;
                
                for(int i=0;i<length;i++) temp[i+1]=arr[i];

                delete[] arr;
                arr=temp;
                length++;
            }
            
            else {
                int* temp=new int[length+1];
                
                
                for(int i=0;i<index;i++)  temp[i]=arr[i];

                temp[index]=value;
                
                for(int i=index;i<length;i++) temp[i+1]=arr[i];
                
                length++;
                delete[] arr;
                arr=temp;
                
            }

        }
    int find(int start,int end,int value){
        while(start<=end){
        int mid= (start+end)/2;
        if(arr[mid]==value) return mid;
        else if(arr[mid]<value) start=mid+1;
        else end=mid-1;
        }
        return -1;
    }
    void add(int value){
            if(arr==NULL){
                arr= new int[1];
                arr[0]=value;
                length++;
                return;
            }

            for(int i=0;i<length;i++){
                if(value<arr[i] && (find(0,length-1,value)==-1) ) {
                    insert(value,i);
                    break;
                }     
                else if(i==length-1){
                    int* temp=new int[length+1];
                    for(int i=0;i<length;i++){
                        temp[i]=arr[i];
                    }
                    if((find(0,length-1,value)==-1)) temp[length++]=value;
                    delete[] arr;
                    arr=temp;
                    break;
                }           
            }
            
    }

    void erase(int index){
        if(index==0){
            int *temp=new int[length-1];
            for(int i=0;i<length;i++) temp[i]=arr[i+1];
            delete[] arr;
            length--;
            arr=temp;
        }
        else {
            int *temp=new int[length-1];
            for(int i=0;i<index;i++) temp[i]=arr[i];
            for(int i=index+1;i<length;i++) temp[i-1]=arr[i];
            delete[] arr;
            length--;
            arr=temp;
        }
    }
    // void intersection(const Set& other_set){
    //     Set temp;
    //     int j=0;
    //     for(int i=0;i<other_set.length;i++){

    //         if(find(0,length-1,other_set.arr[i])!=-1){
    //             int index=find(0,length-1,other_set.arr[i]);
    //             temp.add(arr[index]);
    //         }

    //     }

    //     cout<<"Phan tu giao nhau cua 2 mang\n";
        
    //     temp.print();
    
        
    // }
    void intersection(const Set& other_set){
        int* temp=new int[other_set.length];
        int j=0;
        for(int i=0;i<other_set.length;i++){
            if(find(0,length-1,other_set.arr[i])!=-1){
                int index=find(0,length-1,other_set.arr[i]);
                temp[j]=arr[index];
                j++;
            }
           
        }
        cout<<"Phan tu giao nhau cua 2 mang\n";
        for(int i=0;i<j;i++){
            cout<<temp[i]<<" ";
        }
        
    }
    void uni(const Set& other_set){
        int* temp=new int[other_set.length];
        int j=0;
        for(int i=0;i<other_set.length;i++){
            if(find(0,length-1,other_set.arr[i])!=-1){
                int index=find(0,length-1,other_set.arr[i]);
                temp[j]=arr[index];
                j++;
            }
           
        }
        cout<<"Phan tu giao nhau cua 2 mang\n";
        for(int i=0;i<j;i++){
            cout<<temp[i]<<" ";
        }
        
    }
};


int main(){
    
     Set a,b;
    a.add(2);
    a.add(1);
    a.add(7);
    a.add(3);
    a.add(1);
    a.add(7);
    a.add(9);
    b.add(3);
    b.add(7);
    a.print();
    cout<<"\n";
    b.print();
    cout<<"\n";
    a.intersection(b);
    
}