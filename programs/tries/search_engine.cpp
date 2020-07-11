#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class trieNode{
    public:
    trieNode ** children;
    int wi;
    
    trieNode(){
        children=new trieNode *[26];
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        wi=0;
    }
};

void insert(string s,int weight , trieNode * root){

    if(s.empty()){
        return;
    }
    trieNode * child;
    int index=s[0]-'a';
    if(root->children[index]){
        child=root->children[index];
    }
    else{
        child=new trieNode();
        root->children[index]=child;
        
    }
    
    if(root->wi<weight){
        root->wi=weight;
    }

    insert(s.substr(1),weight,child);
}

int search(string s, trieNode * root){

int bestWeigth=-1;
trieNode * current=root;
for(int i=0;i<s.length();i++){

    int index=s[i]-'a';
    trieNode * child=current->children[index]; 
    if(child){
       current=child;
       bestWeigth=child->wi;
    }
    else{
        return -1;
    }
}
return bestWeigth;

}

int main(){

    int n,q;
    cin>>n>>q;
    trieNode *root=new trieNode();
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int wi;
        cin>>wi;
        insert(s,wi,root);
    }
    for(int i=0;i<q;i++){
        string s;
        cin>>s;
        cout<<search(s,root)<<endl;
    }

}