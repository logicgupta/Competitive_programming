#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    int t,n,m,i;
    int l,r;
    cin>>t;
    while(t--){

        cin>>n>>m;
        vector<pair<int,int>> time;
        int p[m];
        for(i=0;i<n;i++){
            cin>>l>>r;
            time.push_back(make_pair(l,r));
        }

        for(i=0;i<m;i++)
            cin>>p[i];


        sort(time.begin(),time.end());
        for(i=0;i<n;i++){
            int x=*lower_bound(time.begin(),time.end(),make_pair(p[i],numeric_limits<int>::min()));
            cout<<x;
        }


    }
    return 0;

}
