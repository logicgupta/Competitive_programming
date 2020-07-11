#include<iostream.h>
#include<bits/stdc++.h>
using namespace std;

buildZArray(int * z,string str){

    int l=0;
    int r=0;
    int n=str.length();
    for(int i=1;i<n;i++){

        if(i>r){
            // i does not lie between l and r
            // z for this does nt exist
            l=i;
            r=i;
            while(r<n && str[r-l==str[r]]){
                r++;
            }
            z[i]=r-l;
            r--;
        }
        else{
            int k=i-1;
            if(z[k]<=r-l){
                // it lies between l and r
                z[i]=z[k];
            }
            else{
                // Some part of z is already included
                // You have to start matching further
                while(r<n && str[r-l==str[r]]){
                r++;
            }
            z[i]=r-l;
            r--;
            }
        }
    }

}

void searchPattern(string pattern,string text ){

    string str=pattern+"$"+text;
    int len =str.length();
    int * z =new int[len]();
    buildZArray(z,str);
    for(int i=0;i<len;i++){
        if(z[i]==pattern.length()){
            cout<<i-pattern.length()-1<<endl;
        }
    }
}

int main(){

    string pattern="bab";
    string text="ababbwbwbabaabbeee";
    searchPattern(pattern,text);

}
