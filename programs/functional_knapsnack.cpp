#include<bits/stdc++.h>
using namespace std;


bool compare(pair<int,int> a,pair<int,int> b){

        double value1=((double)a.second)/a.first;
        double value2=((double)b.second)/b.first;

        return value1>value2;
}

int main(){

    int n,W;
    cin>>n>>W;

    pair<int,int> arr[n];

    for(int i=0;i<n;i++){

        cin>>arr[i].first>>arr[i].second;
    }

    sort(arr,arr+n,compare);

    int currW=0,currC=0;

    for(int i=0;i<n;i++){

        if(currW+arr[i].first<=W){
            currW+=arr[i].first;
            currC+=arr[i].second;
        }
        else{
            int remW=W-currW;
            currC+=arr[i].second*((double)remW)/arr[i].first;
            break;

        }
    }
    cout<<currC<<endl;

    return 0;
}
