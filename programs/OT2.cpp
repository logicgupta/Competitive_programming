#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	int n,m,q,i,j;
	cin>>t;
	while(t--){
		int x,y,count=0;
		cin>>n>>m>>q;
		int a[n][m];
		memset(a, 0, sizeof(a[0][0]) * m * n);
		int b[q][2];
		for(i=0;i<q;i++){
			cin>>x>>y;
			b[i][0]=x;
			b[i][1]=y;
		}
		for(i=0;i<q;i++)
		{
			x=b[i][0];
			y=b[i][1];
			for(j=0;j<n;j++){
			a[x-1][j]+=1;
			}
			for(j=0;j<m;j++){
				a[j][y-1]+=1;
			}
		}

		for(int i=0;i<n;i++){
			for(j=0;j<m;j++)
			{
				if(a[i][j]%2!=0){
                    count++;
				}
			}

		}
		cout<<count<<endl;
	}
	return 0;
}
