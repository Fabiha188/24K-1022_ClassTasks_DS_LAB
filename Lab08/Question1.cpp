using namespace std;
#include <iostream>
#include <string>

class node{
    public:
    string name;
    node* left;
    node* right;

    
   node(){
        name="";
        left=right=nullptr;
        
    } 
    node(string n){
        name=n;
        left=right=nullptr;    
    } 

};
class Tour{
     public:
    node* head;
   
    Tour(){
        head=nullptr;
    }
    
    node* insert(string nn,node* head){
        if(head==nullptr){
            head=new node(nn);
            return head;
        }
         if(nn> head->name){
            head->right=insert(nn,head->right);
        }
        else if(nn<head->name){
            head->left=insert(nn,head->left);
        }
        return head;
    }
    void inOrder(node* head){
        if(head==nullptr){
            return ;
        }
        inOrder(head->left);
        cout<<head->name<<" ";
        inOrder(head->right);
    }
};
int main(){
    Tour t;
    string cities[] = {"Tokyo", "NewYork", "London", "Sydney", "Dubai"};
    for (string city : cities) {
        t.head = t.insert(city, t.head);
    }


     cout << "Cities in order: ";
    t.inOrder(t.head);
}
