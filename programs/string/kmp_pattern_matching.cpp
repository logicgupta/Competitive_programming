#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int *getLps(string pattern){

	int len=pattern.length();
	int *lps=new int [len];
	
	int i=1;
	int j=0;
	int lps[0]=0;
	
	while(i<len){
	
		if(pattern[i]==pattern[j]){
			lps[i]=j+1;
			i++;
			j++;
		}
		else{
			if(j!=0){
				j=lps[j-1];
			}
			else{
				lps[i]=0;
				i++;
			}
		}
	}
	return lps;
}

bool kmpsearch(string text,string pattern){
	
	int lenText=text.length();
	int lenPat=pattern.length();
	
	int i=0;
	int j=0;
	int *lps =getLps(pattern);
	while(i<lenText && j<lenPat){
		
		if(text[i]==pattern[i]){
			i++;
			j++;
		}
		else{
			if(j!=0){
			j=lps[j-1];
			}
			else{
			i++;
			}
		}
	}
	
	if(j==lenPat){
	return true;
	}
	else{
	return false;
	}

}
