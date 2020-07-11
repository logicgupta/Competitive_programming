#include<bits/stdc++.h>
using namespace std;

// Optimized Recursive Approach

int min_path(int ** input, int si,int sj , int ei,int ej,int **output){

    if(si==ei && sj==ej){
        return input[si][sj];
    }
    if(si>ei || sj >ej ){
        return INT_MAX;
    }
      if(output[si][sj]>-1){
        return output[si][sj];
      }
    int firstOutput=min_path(input,si,sj+1,ei,ej,output);
    int secondOutput=min_path(input,si+1,sj+1,ei,ej,output);
    int thirdoutput=min_path(input,si+1,sj,ei,ej,output);
   output[si][sj]= input[si][sj]+ min(firstOutput,min(secondOutput,thirdoutput));
        return output[si][sj];
}

// Iterative Approach

int compute_path(int **input,int n,int m){

    int **output=new int*[3];
    output[0]=new int[3];
    output[1]=new int[3];
    output[2]=new int[3];
    output[n-1][m-1]=input[n-1][m-1];
    for(int i=n-2;i>=0;i--){
        output[i][m-1]=input[i][m-1]+output[i+1][m-1];
    }

    for(int i=m-2;i>=0;i--){
        output[n-1][i]=input[n-1][i]+output[n-1][i+1];
    }

    for(int i=n-2;i>=0;i--){

        for(int j=m-2;j>=0;j--){

            output[i][j]=input[i][j]+min(output[i][j+1],min(output[i+1][j+1],output[i+1][j]));
        }
    }
    // We need to delete memory whatever  is being created
    return output[0][0];

}

int main(){

    int ** arr=new int*[3];
    arr[0]=new int[3];
    arr[1]=new int[3];
    arr[2]=new int[3];
    arr[0][0]=4;
    arr[0][1]=3;
    arr[0][2]=5;
    arr[1][0]=1;
    arr[1][1]=1;
    arr[1][2]=6;
    arr[2][0]=1;
    arr[2][1]=5;
    arr[2][2]=8;
    int **output=new int*[3];
    for(int i=0;i<3;i++){
        output[i]=new int[3];
        for(int j=0;j<3;j++){
            output[i][j]=-1;
        }
    }

    cout<<min_path(arr,0,0,2,2,output)<<endl;
    cout<<compute_path(arr,3,3);


    delete arr[0];
    delete arr[1];
    delete arr[2];
    delete []arr ;
    return 0;
}
