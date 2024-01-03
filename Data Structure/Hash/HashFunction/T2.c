int check(int S[],int x){
    for(int i=0;i<96;i++){
        if(S[i]==x)
            return i;
    }
    return -1;
}
int isIsomorphic(char* s, char* t) {
    int N = strlen(s);
    int *a=(int*)malloc(sizeof(int)*96);
    for(int i=0;i<96;i++)
        a[i]=-1;
    for(int i=0;i<N;i++){
        if(a[s[i]-32]==-1&&check(a,t[i]-32)==-1)
            a[s[i]-32]=t[i]-32;
        else if(a[s[i]-32]!=t[i]-32)
            return 0;
        else if(a[s[i]-32]==-1&&check(a,t[i]-32)!=-1)
            return 0;
    }
    return 1;
}