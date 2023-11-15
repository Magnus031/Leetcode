//Find the max length of the substring.
/*
示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/
int check(char *s,char x);
int lengthOfLongestSubstring(char* s){
    int length = strlen(s);
    int start=0;//put two points as the start/end of the substring;
    int count=1,num=1;
    if(length==0)
        return 0;
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

