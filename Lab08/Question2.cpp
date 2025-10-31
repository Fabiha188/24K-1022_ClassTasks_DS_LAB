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
class DataAnalysyt{
     public:
    node* head;
   
    DataAnalysyt(){
        head=nullptr;
    }
    
    node* insert(string nn,node* head){
        if(head==nullptr){
            head=new node(nn);
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
    int countNode(node* head){
        if(head==nullptr){
            return 0;
        }
        return 1+countNode(head->left)+countNode(head->right);
    }

    int countLeave(node* head){
        if(head==nullptr){
            return 0;
        }
        if(head->left==nullptr && head->right==nullptr){
            return 1;
        }
        return countLeave(head->left)+countLeave(head->right);
    }
    int height(node* head){
        if(head==nullptr){
            return 0;
        }
        int leftHeight=height(head->left);
        int rightHeight=height(head->right);
        return 1+max(leftHeight,rightHeight);
    }
};
int main(){
    DataAnalysyt d;
    string names[] = {"Ahmed", "Fatima", "Hassan", "Aisha", "Omar", "Zainab", "Yusuf"};
    for (string name : names) {
        d.head = d.insert(name, d.head);
    }

    cout << "Clients in order: ";
    d.inOrder(d.head);
    cout << endl;

    cout << "Total nodes: " << d.countNode(d.head) << endl;
    cout << "Leaf nodes: " << d.countLeave(d.head) << endl;
    cout << "Height of tree: " << d.height(d.head) << endl;

    return 0;
}
