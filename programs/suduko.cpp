#include<bits/stdc++.h>
using namespace std;


bool findEmpty(int mat[9][9],int &r,int &c){
        for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
             if(mat[i][j]==0){
                    r=i;
                    c=j;
                return true;
                }
        }
    }

   return false;

}

bool checkRow(int mat[9][9],int row,int k){
    for(int j=0;j<9;j++){
            if(mat[row][j]==k ){
                return false;
            }
        }
        return true;
}

bool checkColumn(int mat[9][9],int col,int k){
     for(int j=0;j<9;j++){
            if(mat[j][col]==k ){
                return false;
            }
        }
}

bool checkSubMatrix(int mat[9][9],int row,int col,int k){
    //Sub-matrix

        int row_factor=row-(row%3);
        int column_factor=col-(col%3);

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(mat[i+row_factor][j+column_factor]==k){
                    return false;
                }
            }
        }

        return true;
}

bool checkCorrect(int mat[9][9],int row,int col,int k) {

        if( checkRow(mat,row,k) && checkColumn(mat,col,k) && checkSubMatrix(mat,row,col,k) )
            return true;
        else
            return false;

}



bool solveSuduko(int mat[9][9]){

    int row,col;
    if(!findEmpty(mat,row,col)){
        return true;
       }
         for(int k=1;k<=9;k++){
             mat[row][col]=k;
             if(checkCorrect(mat,row,col,k)){
                           if(solveSuduko(mat)){
                            return true;
                           }
                           mat[row][col]=0;
                        }
                    }

        return false;
}

int main(){

    int grid[9][9];

    for(int i=0;i<9;i++){
        string s;
        cin>>s;
        for(int j=0;j<s.length();j++){
            grid[i][j]=s[j]-'0';
        }
    }

    solveSuduko(grid);


    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
           cout<<grid[i][j];
        }
    }
}
