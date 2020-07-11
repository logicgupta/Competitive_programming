#include<bits/stdc++.h>
using namespace std;
struct	Node{
  int  sum;
  int  max_sum;
  int	bss;			//Best	Suffix	Sum
  int	bps;			//Best	Prefix	Sum
};

	void	buildTree(int *arr,Node *tree,int start,int end,int treeNode){

        if(start==end){
            tree[treeNode].sum=arr[start];
            tree[treeNode].max_sum=arr[start];
            tree[treeNode].bss=0;
            tree[treeNode].bps=0;

            return;
        }
        int mid=(start+end)/2;
        buildTree(arr,tree,start,mid,2*treeNode);
        buildTree(arr,tree,mid+1,end,2*treeNode+1);
        Node left=tree[2*treeNode];
        Node right=tree[2*treeNode+1];
        tree[treeNode].sum=left.sum+right.sum;
        tree[treeNode].bps=max(left.bps,left.sum+right.bps);
        tree[treeNode].bss=max(right.bss,right.sum+left.bss);
        tree[treeNode].max_sum=max(left.sum,max(right.sum,max(tree[treeNode].sum,max( tree[treeNode].bps, tree[treeNode].bss))));

    }

	int	computeMaxSum(Node	*tree,int start,int end,int treeNode,int left,int right){

        if(end<left || right <start){
            return	0;
        }
        if(start>=left && end<=right	){
            tree[treeNode].max_sum;
        }
        int mid=(start+end)/2;
        int	ans1=computeMaxSum(tree,start,mid,treeNode,left,right);
        int	ans2=computeMaxSum(tree,mid+1,end,treeNode,left,right);

        return	(ans1+ans2);
    }


int main() {

	int	n,m;
    cin>>n;

    int	*arr=new int[n+1];

    for(int	i=0;i<n;i++){
        cin>>arr[i];
    }

    Node *tree=new	Node[3*n];

    buildTree(arr,tree,0,n-1,1);

   cin>>m;
    while(m--){

        int	left,right;

        cin>>left>>right;

        cout<<computeMaxSum(tree,0,n-1,1,left-1,right-1)<<endl;

    }

    for(int i=1;i<2*n;i++){
        cout<<tree[i].max_sum<<"    "<<tree[i].sum<<"   "<<tree[i].bps<<"   "<<tree[i].bss<<endl;
    }

   }
