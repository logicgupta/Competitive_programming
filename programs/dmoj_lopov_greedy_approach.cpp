#include<bits/stdc++.h>
using  namespace std;

bool  compare(const pair<int,int> &a,const pair<int,int> &b){

    if(a.second!=b.second){

        return  a.second>b.second;
    }
    return  a.first<b.first;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;

    multiset<int>  bags;

    pair<int,int>  *arr=new pair<int,int>[n];

    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        cin>>arr[i].second;

    }
    sort(arr,arr+n,compare);

    int x;
    for(int i=0;i<k;i++){
        cin>>x;
        bags.insert(x);
    }
    long  ans=0;
    for(int i=0;i<n;i++){

        int value=arr[i].second;
        if(bags.empty()){
            break;
        }
        else if(bags.lower_bound(value)!=bags.end()){
            ans+=value;
            bags.erase(bags.lower_bound(value));
        }
   }
   cout<<ans<<endl;

    return  0;
}
