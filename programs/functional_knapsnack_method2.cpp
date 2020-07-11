#include<bits/stdc++.h>
using namespace std;
struct Item{
int value,weight;
};

bool compare(struct Item a,struct Item b){

        double value1=((double)a.value)/a.weight;
        double value2=((double)b.value)/b.weight;

        return value1>value2;
}

int main(){

    int n,W;
    cin>>n>>W;

    Item arr[]={{60,20},{70,15},{80,40}};

    sort(arr,arr+n,compare);

    int currW=0,currC=0;

    for(int i=0;i<n;i++){

        if(currW+arr[i].weight<=W){
            currW+=arr[i].weight;
            currC+=arr[i].value;
        }
        else{
            int remW=W-currW;
            currC+=arr[i].value*((double)remW)/arr[i].weight;
            break;

        }
    }
    cout<<currC<<endl;

    return 0;
}
