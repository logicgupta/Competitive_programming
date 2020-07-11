#include <iostream>
using namespace std;
void mergeAll(int a[],int left,int mid,int right){

    int i=left;
    int j=mid;
    int k=0;
    int temp[right-left+1];

    while(i<mid && j<=right)
    {
        if(a[i]<=a[j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
        }
    }
    while(i<mid){
        temp[k++]=a[i++];
    }
    while(j<=right){
        temp[k++]=a[j++];
    }

    for(i=left,k=0;i<=right;i++,k++){
        a[i]=temp[k];
    }

}

void mergeS(int input[],int l,int size){

    int low=l,high=size-1;
    if(size==0){
        return;
    }
    while(low<=high){
        int mid=(low+high)/2;
        mergeS(input,low,mid);
        mergeS(input,mid+1,high);
        mergeAll(input,low,mid+1,high);
    }
}
int main() {
	// your code goes here
	int a[]={2,6,8,5,4,3};
	mergeS(a,0,6);
	for(int i=0;i<6;i++){
		cout<<a[i]<<" 1";
	}
	return 0;
}
