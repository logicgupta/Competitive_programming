#include<bits/stdc++.h>
using namespace std;

// Advance Graphs Video Solution Question 1


void DFS(vector<int>* edges ,int start_index,unordered_set<int> * component, bool * visited ){

	visited[start_index]=true;
	component->insert(start_index);
	for(int i=0;i<	edges[start_index].size();i++){
	
		int next=edges[start_index][i];
		if(!visited[next]){
			DFS(edges,next,component,visited);
		}
	}

}

 unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges , int n){
 	
 	bool * visited=new bool[n]();
 	for(int i=0;i<n;i++){
 	visited[i]=false;
 	}
 	
 	unordered_set<unordered_set<int>*>* output=new unordered_set<unordered_set<int>*>();
 	
 	for(int i=0;i<n;i++){
	 	
	 	if(!visited[i]){
	 	unordered_set<int> * component=new unordered_set<int> ();
	 	
	 	DFS(edges,i,component,visited);
	 	output->insert(component);
 	
 		}
 	
 	}
 	
 	delete [] visited;
 	
 	return output;
 
 }


// Advance Graphs Video Solution Question 1


int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<int>* edges=new vector<int>[n];

	int x,y;	
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		edges[x-1].push_back(y-1);
		edges[y-1].push_back(x-1);
	}
	
	unordered_set< unordered_set<int>*>*  components=getComponents(edges,n);

	unordered_set<unordered_set<int>*>::iterator itr=components->begin();
	
	while(itr!=components->end()){
	
		unordered_set<int>* component=*itr;
		
		unordered_set<int> ::iterator it=component->begin();
		while(it!=component->end())
		{
			cout<<*it+1<<" ";
			it++;
		}
		cout<<endl;
		
		delete component;
		itr++;
	
	}
	delete components;
	delete edges;
	return 0;	

}
