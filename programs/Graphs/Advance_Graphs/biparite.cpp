#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


bool getBiparite(vector<int> * edges ,int n){

	if(n==0)
	return true;
	unordered_set<int> set[2];
	
	vector<int> pending;
	set[0].insert(0);
	pending.push_back(0);
	while(pending.size()>0){
		int element=pending.back();
		pending.pop_back();
		int currentSet=set[0].count(element) > 0 ? 0 : 1;
		for(int i=0;i<edges[element].size();i++){
			
			int neighbour=edges[element][i];
			
			if(set[0].count(neighbour)==0 && 						set[1].count(neighbour)==0){
				set[1-currentSet].insert(neighbour);
				pending.push_back(neighbour);
			}
			else if(set[currentSet].count(neighbour)>0){
				return false;
			}
		}
	}
	return true;
	
}

int main(){
	
	while(true){
		int n;
		cin>>n;
		if(n==0)
		break;
		
		vector<int> * edges=new vector<int>[n];
		int m;
		cin>>m;
		for(int i=0;i<m;i++){
			int j,k;
			cin>>j>>k;
			edges[j].push_back(k);
			edges[k].push_back(j);
		}
		
		bool result=getBiparite(edges,n);
		delete [] edges;
		if(result){
			cout<<"BICOLOURABLE.."<<endl;
		}
		else{
			cout<<"Not-BICOLOURABLE.."<<endl;
		}
		
	}
	
}
