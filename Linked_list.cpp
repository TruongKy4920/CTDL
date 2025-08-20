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
struct Node{
    int data;
    Node* next;
    Node(){
        data=0;
        next=NULL;
    }
    Node(int value){
        data=value;
        next=NULL;
    }
};
struct Linked_list {
    Node* Head;
    int length;
    Linked_list(){
        Head=NULL;
        length=0;
    }
    ~Linked_list(){}
    int& operator[](int index){
        int i=0;
        for(Node* node=Head;node->next!=NULL;node=node->next){
            if(i==index) return node->data;
            i++;
        }
      
    }
    void print(){
        for(Node* node=Head;node!=NULL;node=node->next){
           cout<<node->data<<" ";
        }
    }
    
    void push_back(int value){
        Node* new_node= new Node(value);
        length++;
        if(Head==NULL){
            Head=new_node;
            return;
        }
        Node* node=Head;
        while(node->next!=NULL) node=node->next;
        node->next=new_node;
       
    }
   void erase(int index){
    length--;
    if(index<0 || index>length){
        cout<<"out of range";
        return;
    }
    if(index==0){
        Node* node= Head;
        Head = Head->next;
        delete node;
    }
    int i=0;
    Node* node=Head->next;
    Node* node2=Head;
    for(;node!=NULL;){
           if(i==index) {
            node2->next=node->next;
            delete node;
          
           }
           i++;
           node2=node;
           node=node->next;
           
        }
   }
        
    
};


int main(){
    
    Linked_list a;
    a.push_back(2);
    a.push_back(4);
    a.push_back(8);
    a.push_back(0);
    a.push_back(6);
      //a.del(a.length-1);
    a.erase(2);
    a.print();
      
      
}