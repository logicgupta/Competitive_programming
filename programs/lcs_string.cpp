#include<bits/stdc++.h>
using namespace std;


int lcs1(char *s1,char *s2){


    if(s1[0]=='\0' || s2[0]=='\0'){

        return 0;
    }
    if(s1[0]==s2[0]){
        return 1+lcs1(s1+1,s2+1);
    }
    else{
        int first=lcs1(s1,s2+1);
        int second=lcs1(s1+1,s2);
        return max(first,second);
    }
}

int lcsI(char* s1, char* s2){


    int m=strlen(s1);
    int n=strlen(s2);

    int **dp=new int*[m+1];

    for(int i=0;i<=m;i++){
        dp[i]=new int[n+1];
    }

    int ans=0;
    for(int i=0;i<=m;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        dp[0][i]=0;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[m-i]==s2[n-j]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

     ans =dp[m][n];

     for(int i=0;i<=n;i++){
         delete [] dp[i];
     }
    delete [] dp;
     return ans;


}



int lcsHelper(char *s1,char *s2,int m,int n, int **dp){
    int ans=0;
    if(m==0 || n==0){
        return 0;
    }
    if(dp[m][n]>-1){
        return dp[m][n];
    }
     if(s1[0]==s2[0]){
        ans= 1+lcsHelper(s1+1,s2+1,m-1,n-1,dp);
    }
    else{
        int first=lcsHelper(s1,s2+1,m,n-1,dp);
        int second=lcsHelper(s1+1,s2,m-1,n,dp);
        ans= max(first,second);
    }
    dp[m][n]=ans;
    return ans;
}

int lcs2(char *s1,char *s2){

    int m=strlen(s1);
    int n=strlen(s2);

    int **dp=new int*[m+1];

    for(int i=0;i<=m;i++){
        dp[i]= new int[n+1];
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    int ans=lcsHelper(s1,s2,m,n,dp);
    for(int i=0;i<=n;i++){
        delete [] dp[i];
    }

    delete []  dp;
    return ans;


    }

int main(){


    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    char s1[100];
    char s2[100];

    cin>>s1;
    cin>>s2;

    cout<<"Faster "<<lcsI(s1,s2);
}
