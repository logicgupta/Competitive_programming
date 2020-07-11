#include<bits/stdc++.h>
using namespace std;
#define m 1000000009;
int main(){

    string s;
    cin>>s;

    long long sum=s[0]-'0';
    long long lastNumber=s[0]-'0';
    for(int i=1;i<s.length();i++){
            lastNumber=lastNumber*10+(s[i]-'0')*(i+1);
            lastNumber=lastNumber%m;
            sum=(sum+lastNumber)%m;
    }
    cout<<sum;
    return 0;
}
