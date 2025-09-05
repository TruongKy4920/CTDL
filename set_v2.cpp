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
    bool mark[MAX];
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
    // void insert(int value,int index){
    //         if(index==0){
    //             int* temp= new int[length+1];
    //             temp[0]=value;
                
    //             for(int i=0;i<length;i++) temp[i+1]=arr[i];

    //             delete[] arr;
    //             arr=temp;
    //             length++;
    //         }
            
    //         else {
    //             int* temp=new int[length+1];
                
                
    //             for(int i=0;i<index;i++)  temp[i]=arr[i];

    //             temp[index]=value;
                
    //             for(int i=index;i<length;i++) temp[i+1]=arr[i];
                
    //             length++;
    //             delete[] arr;
    //             arr=temp;
                
    //         }

    //     }

    // int find(int start,int end,int value){
    //     while(start<=end){
    //     int mid= (start+end)/2;
    //     if(arr[mid]==value) return mid;
    //     else if(arr[mid]<value) start=mid+1;
    //     else end=mid-1;
    //     }
    //     return -1;
    // }


    void add(int value){
            if(arr==NULL){
                arr= new int[1];
                mark[value]=true;
                arr[0]=value;
                length++;
                return;
            }
            int *temp= new int[length+1];
           for(int i=0;i<length;i++){
                temp[i]=arr[i];
           }
           if(mark[value]!=true){
            temp[length++]=value;
            mark[value]=true;
            delete[] arr;
            arr=temp;
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
    
//      Set intersection(const Set& other_set){
//         Set temp;
//         for(int i=0;i<other_set.length;i++){
//             if(find(0,length-1,other_set.arr[i])!=-1){
//                 int index=find(0,length-1,other_set.arr[i]);
//                 erase(index);
                
//             }

//         }

//         return temp;
    
        
//     }
//     Set uni(const Set& other_set){
//         Set temp;
//         Set temp2=other_set;
//          for(int i=0;i<other_set.length;i++){
//             if(find(0,length-1,temp2[i])!=-1){
                
//                 temp2.erase(i);
                
//             }
//             else temp.add(temp2[i]);

//         }
        
//         for(int i=0;i<length;i++) temp.add(arr[i]); 
    
//         return temp;
        
        
//     }

    Set intersection(const Set& other_set){
        Set temp;
        for(int i=0;i<length;i++){
            for(int j=0;j<other_set.length;j++){
                if(other_set.arr[j]==arr[i]){
                    temp.add(other_set.arr[j]);
                }
            }
        }
        return temp;
    }

    Set uni(const Set& other_set){
        Set temp;
        for(int i=0;i<length;i++){
           temp.add(arr[i]);
        }
        for(int i=0;i<other_set.length;i++){
           temp.add(other_set.arr[i]);
        }
        return temp;
    }
 };


int main(){
    
     Set a,b;
    a.add(2);
    a.add(1);
    a.add(7);
    a.add(3);
    a.add(1);
    a.add(4);
    a.add(7);
    a.add(9);
    b.add(0);
    b.add(3);
    b.add(7);
    b.add(11);
    a.print();
    cout<<"\n";
    b.print();
    cout<<"\n";
    Set c=a.intersection(b);

    c.print();
     cout<<"\n";
    Set d=a.uni(b);

    d.print();
    
    
}