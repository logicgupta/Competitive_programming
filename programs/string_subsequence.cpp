#include<bits/stdc++.h>
using namespace std;
int subsequence(string s1,string *output){

    if(s1.empty()){
        output[0]="";
        return 1;
    }
    string smaallString=s1.substr(1);
    int smallOutput=subsequence(smaallString,output);
    for(int i=0;i<smalloutput;i++){
        output[i+smalloutput]=s1[0]+output[i];
     }
     return 2*smalloutput;
}

int main(){

 string s1;
 cin>>s1;
 string *s2=new string[1000];
 int l=subsequence(s1,s2);
 for(int i=0;i<l;i++){
    cout<<s2[i];
 }
 return 0;
 }
