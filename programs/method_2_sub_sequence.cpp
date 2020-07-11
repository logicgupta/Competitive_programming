#include<bits/stdc++.h>
using namespace std;

void print_sub_seq(string input,string output){

    if(input.empty()){

        cout<<output<<endl;
        return;
    }

    print_sub_seq(input.substr(1),output);
    print_sub_seq(input.substr(1),output+input[0]);
}

int main(){
string s="abc";
string o="";
print_sub_seq(s,o);
return 0;
}
