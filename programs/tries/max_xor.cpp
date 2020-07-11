#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class trieNode{
  public:
    trieNode *left;
    trieNode *right;
};

void insert(int n, trieNode *head){
    trieNode *tries=head;
    for (int i=31;i>=0;i--){
        int b=(n>>i)&1;
        if(b==0){
                if(!tries->left){
                    tries->left=new trieNode();
                }
                tries=tries->left;
        }
        else{
            if(!tries->right){
                tries->right=new trieNode();
            }
            tries=tries->right;

        }
    }
}

int findMaxXor(int * arr, int n, trieNode * head){

    int max_xor=INT_MIN;
    for(int i=0;i<n;i++){
        int el=arr[i];
        trieNode * tries=head;
        int curr_Xor=0;
        for(int j=31;j>=0;j--){
            int b= (el>>j)&1;
            if(b==0)
            {
                if(tries->right){
                    curr_Xor+=pow(2,j);
                    tries=tries->right;
                }
                else
                {
                    tries=tries->left;
                }
            }
            else{
                if(tries->left){
                    curr_Xor+=pow(2,j);
                    tries=tries->left;
                }
                else
                {
                    tries=tries->right;
                }
            }
        }
        max_xor=max(max_xor,curr_Xor);
    }
    return max_xor;
}
int main() {

    int n;
    cin>>n;
    
    int *arr=new int [n];
    
    trieNode *head=new trieNode();
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
        insert(arr[i],head);
    }
    cout<<findMaxXor(arr,n,head);
    
    

    
    
    
    
}