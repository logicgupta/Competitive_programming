#include<bits/stdc++.h>
using namespace std;

struct Job{
    int start,finish,cost;
};

bool compare(struct Job a,struct Job b){

    return a.finish<b.finish;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    Job arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].finish>>arr[i].cost;
    }

    sort(arr,arr+n,compare);

   /* for(int i=0;i<n;i++){
        cout<<arr[i].start<<" "<<arr[i].finish<<"   "<<arr[i].cost;
    }*/

    int profit[n+1];
    memset(profit,0,sizeof(profit));
    profit[0]=arr[0].cost;
    for(int i=1;i<n;i++){
            int including=arr[i].cost;
            int unConflict=-1;
        for(int j=i-1;j>=0;j--){
            if(arr[j].finish<=arr[i].start){
                unConflict=j;
                break;
            }
        }
        if(unConflict>-1){
            including+=profit[unConflict];
        }
        profit[i]=max(including,profit[i-1]);
    }
    cout<<profit[n-1];


    return 0;
}
