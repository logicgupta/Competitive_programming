#include<bits/stdc++.h>
using namespace std;

void  buildTree(int *arr,int *tree, int start,int end ,int treeNode){

    if(start==end){
        tree[treeNode]=arr[start];
        return;
    }

    int mid =(start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);

    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];

    }

void update(int *arr,int *tree,int start, int end , int treeNode,int index,int value){

    if(start==end){
        arr[start]=value;
        tree[treeNode]=value;
        return;
    }

    int mid=(start+end)/2;

    if(index>mid){
        update(arr,tree,mid+1,end,2*treeNode+1,index,value);
    }
    else{
        update(arr,tree,start,mid,2*treeNode,index,value);
    }

    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];

}

int query(int *tree,int start,int  end , int treeNode, int left,int right){

    if(start>right || end < left){
        return 0;
    }

    if(start>=left && end<=right){
        return tree[treeNode];
    }
    int mid=(start+end)/2;
    int ans1,ans2;
        ans2= query(tree,start,mid,2*treeNode,left,right);

      ans1=  query(tree,mid+1,end,2*treeNode+1,left,right);



    return min(ans1,ans2);

}

int main() {

	int n,q;
    cin>>n>>q;
    int *arr=new int[n];
    int *tree=new int [4*n];

    for (int i=0;i<n;i++){
        cin>>arr[i];
    }

    buildTree(arr,tree,0,n-1,1);

    char  q_Type,left,right,value;

    for(int i=0;i<q;i++){
        cin>>q_Type>>left>>right;
        if(q_Type=='q'){
            cout<<query(tree,0,n-1,1,left,right)<<endl;
        }
        else{
            //left-> Index
            // right-> value to be updated
            update(arr,tree,0,n-1,1,left,right);
        }

    }


     for(int i=1;i<2*n;i++){
        cout<<tree[i]<<endl;
    }
return 0;


}
