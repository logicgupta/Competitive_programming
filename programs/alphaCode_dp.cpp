#include<bits/stdc++.h>
using namespace std;
#define mod 1000000009
int compute(int arr[], int n){
    if(n==1){
        return 1;
    }
    if(n==0){
        return 0;
    }
    int output[n+1];
    memset(output,0,sizeof(output));
    output[0]=1;
    output[1]=1;
    for(int i=2;i<n;i++){
        if(arr[i-1]==0){
            if(arr[i-2]>2 || arr[i-2]==0){
                return 0;
            }
              output[i] = output[i-2];
            continue;
        }
        output[i] = output[i-1];
        if(arr[i-2]!=0 && (arr[i-2]*10 + arr[i-1]) <=26 ){
            output[i] += output[i-2];
        }
    }
    int ans = output[n-1]%mod;
   return ans;

}

int main(){

    while(1){

        string s;
        cin>>s;
        if(s=="0"){
        break;
        }
        else{
                int a[s.length()+1];
                for(int i=0;i<s.length();i++){
                    a[i]=s[i]-'0';
                }
                cout<<compute(a,s.length());


        }
    }
}
