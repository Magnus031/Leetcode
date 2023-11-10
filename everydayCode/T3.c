//Find the max length of the substring.
int check(char *s,char x);
int lengthOfLongestSubstring(char* s){
    int length = strlen(s);
    int start=0;//put two points as the start/end of the substring;
    int count=1,num=1;
    for(start=0;start<length-1;start++){
        int end = start+1;
        while(end<length){
            num=end-start+1;
            char a[num+1];
            strncpy(a,s+start,num);
            a[num]='\0';//get the substring.
            if(check(a,s[end])==0){
                if(num>count)
                    count=num;
            }else 
                break;
            end++;
        }
    }
    return count;
    }
int check(char *s,char x){
    //this function is to check if x has appeared in the substring s.
    int N = strlen(s);
    for(int i = 0;i < N-1;i++){
        //traversal
        if(s[i] == x)
            return 1;
    } 
    return 0;
}

