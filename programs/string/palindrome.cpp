int maxLengthPlindrome(char [] s){
      int maxLen=0;
	int n=strlen(s);
    for(int i=0;i<n;i++){
        
        int l=i;
        int r=i;   
            l=i;
            r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                int currLen=r-l+1;
                if(currLen>maxLen){
                    maxLen=currLen;
                }
                l--;
                r++;
            }
        
        // Even Lenngth
             l=i;
             r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                int currLen=r-l+1;
                if(currLen>maxLen){
                    maxLen=currLen;
                }
                l--;
                r++;
            }
        
    }
    return maxLen;
}