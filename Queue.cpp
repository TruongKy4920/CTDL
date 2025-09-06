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
template <typename T>
struct Node{
    T data;
    Node* next;
    Node(){
        data=0;
        next=NULL;
    }
    Node(T value): data(value), next(NULL){}
};

template <typename T>
struct Queue {
    Node<T> * Head;
    Node<T> *Tail;
    int length;
    Queue():Head(NULL),Tail(NULL),length(0){}
    ~Queue(){}

    int& operator[](int index){
        int i=0;
        for(Node<T>* node=Head;node->next!=NULL;node=node->next){
            if(i==index) return node->data;
            i++;
        }
      
    }
    void print(){
        for(Node<T>* node=Head;node!=NULL;node=node->next){
           cout<<node->data<<" ";
        }
    }
    
    void enqueue(int value){
        Node<T>* new_node= new Node(value);
        length++;
        if(Head==NULL){
            Head=new_node;
            Tail=new_node;
            return;
        }
       Tail->next=new_node;
       Tail=new_node;
       
    }
   T dequeue(int index){
        length--;
        Node<T> * temp_node=Head;
        T result = temp_node->data;
        Head=Head->next;
        delete temp_node;
        return result;
   }
        
    
};


int main(){
    
    Queue <int> a;
    a.enqueue(2);
    a.enqueue(4);
    a.enqueue(8);
    a.enqueue(0);
    a.enqueue(6);
     a.print();
      //a.del(a.length-1);
    cout<<"dequeue "<<a.dequeue(2)<<"\n";
    a.print();
      
      
}