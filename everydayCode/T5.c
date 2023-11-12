//This is a O(N^3) time complexity algorithm.
int check(char *a){
    //To check if it is a Palindrome substring;
    int flag=1;
    int N = strlen(a);
    for(int i=0;i< N/2;i++){
        if(a[i]!=a[N-i-1])
            {
                flag=0;
                break;   
            }
    }
    return flag;
}
char* longestPalindrome(char *s) {
    int N = strlen(s);
    if (check(s))
        return s;
    int count = 1;
    int start0 = 0;
    for (int start = 0; start < N; start++) {
        for (int end = start + 1; end < N; end++) {
            char *q = (char *)malloc((end - start + 2) * sizeof(char));
            strncpy(q, s + start, end - start + 1);
            q[end - start + 1] = '\0';
            if (check(q)) {
                int num = strlen(q);
                if (num > count) {
                    count = num;
                    start0 = start;
                }
            }
            free(q); // Free the memory here
        }
    }
    char *p = (char *)malloc(sizeof(char) * (count + 1));
    strncpy(p, s + start0, count);
    p[count] = '\0';
    return p;
}

//Here is a O(N^2) algorithm Simply description:
//It is a way for Center expansion

char* longestPalindrome(char *s) {
    int N = strlen(s);
    int start=0;
    int length=1;//represents the max length of the substring.
    for(int i=0;i<N;i++){
        int left=i;
        int right=i;
        while(right<N&&s[right]==s[right+1])
            right++;
        while(left>0&&s[left-1]==s[right+1]){
            left--;
            right++;
        }
        if(right-left+1>length){
            start=left;
            length=right-left+1;
        }
    }
    char *p = (char *)malloc(sizeof(char) * (length + 1));
    strncpy(p, s + start, length);
    p[length] = '\0';
    return p;
}

