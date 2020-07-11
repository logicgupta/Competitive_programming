#include<bits/stdc++.h>
using namespace std;

int knapsnack(int *wt, int *v, int n,int W){

    int dp[n+1][W+1];

    for(int i=0;i<=n;i++){

        dp[i][0]=0;
    }
    for(int i=0;i<=W;i++){
        dp[0][i]=0;
    }

    for(int i=1;i<=n;i++){
    for(int w=0;w<=W;w++){

        dp[i][w]=dp[i-1][w];
        if(wt[i-1]<=w){
        dp[i][w]=max(dp[i][w],v[i-1]+dp[i-1][w-wt[i-1]]);
        }
    }

    }
    return dp[n][W];

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v[]={5,4,8,6};
    int wt[]={1,3,4,5};

    int maxW=5;
    int n=4;
    cout<<knapsnack(wt,v,n,maxW)<<endl;

}
