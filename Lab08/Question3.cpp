using namespace std;
#include <iostream>

class node{
    public:
    int data;
    node* left;
    node* right;

    
   node(){
        data=0;
        left=right=nullptr;
        
    } 
    node(int n){
        data=n;
        left=right=nullptr;    
    } 

};
class DataAnalysyt{
     public:
    node* head;
   
    DataAnalysyt(){
        head=nullptr;
    }
    
    node* insert(int nn,node* head){
        if(head==nullptr){
            head=new node(nn);
            return head;
        }
         if(nn > head->data){
            head->right=insert(nn,head->right);
        }
        else if(nn < head->data){
            head->left=insert(nn,head->left);
        }
        return head;
    }
    void inOrder(node* head){
        if(head==nullptr){
            return ;
        }
        inOrder(head->left);
        cout<<head->data<<" ";
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
            return -1;
        }
        int leftHeight=height(head->left);
        int rightHeight=height(head->right);
        return 1+max(leftHeight,rightHeight);
    }
    
   
    bool isFullBinaryTree(node* head){
        if(head == nullptr){
            return true;
        }
        
        // 0
        if(head->left == nullptr && head->right == nullptr){
            return true;
        }
        
        //2
        if(head->left != nullptr && head->right != nullptr){
            return isFullBinaryTree(head->left) && isFullBinaryTree(head->right);
        }
        
        //1 child
        return false;
    }
    
  
    void checkFullBinaryTree(){
        if(isFullBinaryTree(head)){
            cout << "The tree is a FULL BINARY TREE" << endl;
        } else {
            cout << "The tree is NOT a full binary tree" << endl;
        }
    }
};

int main(){
    DataAnalysyt d;
    int numbers[] = {2,7,9,3,5,12,33};
    
    for (int num : numbers) {
        d.head = d.insert(num, d.head);
    }

    cout << "Tree elements in order: ";
    d.inOrder(d.head);
    cout << endl;

    cout << "Total nodes: " << d.countNode(d.head) << endl;
    cout << "Leaf nodes: " << d.countLeave(d.head) << endl;
    cout << "Height of tree: " << d.height(d.head) << endl;
    
    
    d.checkFullBinaryTree();

    return 0;
}
