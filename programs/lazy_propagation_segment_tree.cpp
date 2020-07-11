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

    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);

}

void  update_Lazy(int *tree,int *lazy,int start,int end,int treeNode,int left,int right,int inc){

    if(start>end){
        return;
    }

    if(lazy[treeNode]!=0){

            tree[treeNode]+=lazy[treeNode];
            if(start!=end){
                lazy[2*treeNode]+=lazy[treeNode];
                lazy[2*treeNode+1]+=lazy[treeNode];
            }
            lazy[treeNode]=0;

        }
    if(end <left &&  start >right ){
        return;
    }

    if(start>=left || end<=right ){


            tree[treeNode]+=inc;
            if(start!=end){
                lazy[2*treeNode]+=inc;
                lazy[2*treeNode+1]+=inc;
            }
            return;
     }

   int mid=(start+end)/2;

   update_Lazy(tree,lazy,start,mid,2*treeNode,left,right,inc);
   update_Lazy(tree,lazy,mid+1,end,2*treeNode+1,left,right,inc);

   tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];

   return;

}

int Query(int *tree,int *lazy,int start,int end,int treeNode, int left,int  right){
        if(start>end){
            return  INT_MIN;
        }

        if(left >end || start>right){
            return  INT_MAX;
        }

        if(lazy[treeNode]!=0){

            tree[treeNode]+=lazy[treeNode];
            if(start!=end){
                lazy[2*treeNode]+=lazy[treeNode];
                lazy[2*treeNode+1]+=lazy[treeNode];
            }
            lazy[treeNode]=0;
        }

        if(start>=left && end<=right ){
            if(lazy[treeNode]!=0){
                tree[treeNode]+=lazy[treeNode];
                lazy[treeNode]=0;
                return tree[treeNode];
            }
            else{
               return tree[treeNode];
            }
        }
        int mid=(start+end)/2;
        int ans1=Query(tree,lazy,start,mid,2*treeNode,left,right);
        int ans2=Query(tree,lazy,mid+1,end,2*treeNode,left,right);

        return  min(ans1,ans2);
         

}



int main() {

	int n,q;
	cin>>n;
	
    int *arr=new int[n];
    int *tree=new int [4*n];
    int *lazy=new int[4*n]();

    for (int i=0;i<n;i+
        cin>>arr[i];
    }

    buildTree(arr,tree,0,n-1,1);
    update_Lazy(tree,lazy,0,n-1,1,1,4,2);
    for(int i=1;i<2*n;i++){
        cout<<" "<<tree[i]<<endl;
    }

    cout<<Query(tree,lazy,0,n-1,1,1,2);


    return 0;



}
