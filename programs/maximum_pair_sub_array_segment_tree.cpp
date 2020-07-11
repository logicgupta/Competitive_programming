#include<bits/stdc++.h>
using namespace std;

struct	Node{
    int	maximum,smaximum;
};


void  buildTree(int	*arr,Node * tree,int	start,int end,int treeNode){

    if(start==end){

        tree[treeNode].maximum=arr[start];
        tree[treeNode].smaximum=INT_MIN;
        return;
    }
    int	mid=(start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);

    Node left=tree[2*treeNode];
    Node right=tree[2*treeNode+1];

    tree[treeNode].maximum=max(left.maximum,right.maximum);
    tree[treeNode].smaximum=min(max(left.maximum,right.smaximum),max(right.maximum,left.smaximum));

    return;


}

int query(Node	*tree,int start,int end,int treeNode,int left,int right){


    if(left >end || start>right){
        return 0;
    }

    if(start>=left && end<=right){
        return tree[treeNode].maximum;
    }

    int mid=(start+end)/2;

   int ans1= query(tree,start,mid,2*treeNode,left,right);

   int ans2= query(tree,mid+1,end,2*treeNode+1,left,right);

   int  x=0;
        x+=max(ans1,ans2);
    return x;



}

void update(int *arr,Node *tree,int start,int end,int treeNode,int index,int value){

    if(start==end){
        arr[index]=value;
        tree[treeNode].maximum=value;
        tree[treeNode].smaximum=INT_MIN;
        return;
    }

    int mid=(start+end)/2;
    if(index>mid){
        //  Right   SubTree
        update(arr,tree,mid+1,end,2*treeNode+1,index,value);
    }
    else{
        update(arr,tree,start,mid,2*treeNode,index,value);
    }




    Node left=tree[2*treeNode];
    Node right=tree[2*treeNode+1];

    tree[treeNode].maximum=max(left.maximum,right.maximum);
    tree[treeNode].smaximum=min(max(left.maximum,right.smaximum),max(right.maximum,left.smaximum));

    return;


}


int main() {

    int	n,q;
    cin>>n>>q;

    int	*arr=new int[n];
    for(int	i=0;i<n;i++){
        cin>>arr[i];

    }

    Node *tree=new Node[4*n];

    buildTree(arr,tree,0,n-1,1);
    while(q--){
        char	q_type;
        int	left,right;

        cin>>q_type>>left>>right;
        if(q_type=='U'){
            update(arr,tree,0,n-1,1,left-1,right);
        }
        else{
            cout<<query(tree,0,n-1,1,left-1,right-1)<<endl;
        }
    }



    return	0;
}
