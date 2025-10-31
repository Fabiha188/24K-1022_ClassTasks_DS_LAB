using namespace std;
#include <iostream>
#include <string>
#include <algorithm>

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
    
    
    bool hasSubtreeWithSum(int target) {
        return checkSubtreeSum(head, target);
    }
    
    bool checkSubtreeSum(node* root, int target) {
        if (root == nullptr) return false;
        
        
        int sum = 0;
        calculateSum(root, sum);
        if (sum == target) return true;
        
        
        return checkSubtreeSum(root->left, target) || checkSubtreeSum(root->right, target);
    }
    
    void calculateSum(node* root, int &sum) {
        if (root == nullptr) return;
        sum += root->data;
        calculateSum(root->left, sum);
        calculateSum(root->right, sum);
    }
};

int main(){
    DataAnalysyt d;
    int values[] = {10, 5, 15, 3, 7, 12, 18};
    for (int value : values) {
        d.head = d.insert(value, d.head);
    }

    cout << "Tree in-order: ";
    d.inOrder(d.head);
    cout << endl;

    
    cout << "Subtree with sum 30: " << (d.hasSubtreeWithSum(30) ? "Found" : "Not found") << endl;
    cout << "Subtree with sum 15: " << (d.hasSubtreeWithSum(15) ? "Found" : "Not found") << endl;
    cout << "Subtree with sum 45: " << (d.hasSubtreeWithSum(45) ? "Found" : "Not found") << endl;
    cout << "Subtree with sum 100: " << (d.hasSubtreeWithSum(100) ? "Found" : "Not found") << endl;

    return 0;
}
