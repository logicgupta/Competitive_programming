#include<bits/stdc++.h>
using   namespace   std;

void buildTree(int *arr,int *tree,int start_i,int end_i ,int treeNode){

        if(start_i==end_i){
            tree[treeNode]=arr[start_i];
            return;
        }
        int mid=(start_i+end_i)/2;
        buildTree(arr,tree,start_i,mid,treeNode*2);
        buildTree(arr,tree,mid+1,end_i,treeNode*2+1);
        tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];

}

void  updateTree(int *arr,int *tree,int start_i,int end_i, int treeNode ,int indx,int  value){

    if(start_i==end_i){
        arr[start_i]=value;
        tree[treeNode]=value;
        return;
    }
    int mid=(start_i+end_i)/2;
    if(indx>mid){
        //  Right   SubTree
        updateTree(arr,tree,mid+1,end_i,2*treeNode+1,indx,value);
    }
    else{
        //  Left    SubTree
        updateTree(arr,tree,start_i,mid,2*treeNode,indx,value);
    }

    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];

}

int query(int *tree,int start,int  end_i , int treeNode, int left,int right){

    if(start>right || end_i < left){
        return 0;
    }

    if(start>=left && end_i<=right){
        return tree[treeNode];
    }

    int mid=(start+end_i)/2;
    int ans1,ans2;

      ans2= query(tree,start,mid,2*treeNode,left,right);

      ans1=  query(tree,mid+1,end_i,2*treeNode+1,left,right);


    return ans1+ans2;

}

int main(){

    int n;
    cin>>n;
    int *arr=new    int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int *tree=new int[4*n+1];

    buildTree(arr,tree,0,n-1,1);

    updateTree(arr,tree,0,n-1,1,3,8);



    for(int i=1;i<2*n;i++){
        cout<<tree[i]<<endl;
    }


    cout<<endl<<query(tree,0,n-1,1,2,4);

    return  0;

}
