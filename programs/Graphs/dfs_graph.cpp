#include<bits/stdc++.h>
using namespace std;


void print(int **edges,int n,int start_vertex,int *visted){

	cout<<start_vertex<<endl;
	visted[start_vertex]=1;
	for(int i=0;i<n;i++){
		  
		if(start_vertex==i){
		continue;
		}
		
		
		if(edges[start_vertex][i]==1){
		if(visted[i]==1){
		continue;
		}
		print(edges,n,i,visted);
		}
	}


}


int main(){
	int n,e;
	cin>>n>>e;
	int start_vertex=0;
	int **edges =new int*[n+1];
	for(int i=0;i<=n;i++){
	edges[i]=new int[n+1];
	for(int j=0;j<n+1;j++)
	edges[i][j]=0;
	}
	
	for(int i=0;i<e;i++){
	int f,s;
	cin>>f>>s;
	edges[f][s]=1;
	edges[s][f]=1;
	}
	
	int * visted=new int[n]();
	
	print(edges,n,start_vertex,visted);
	
	// DELETE ARRAY  MEMORY ALLOCATED
	for(int i=0;i<n;i++){
	delete [] edges[i];
	}
	delete [] edges;
	
	delete [] visted;
	return 0;	
}
