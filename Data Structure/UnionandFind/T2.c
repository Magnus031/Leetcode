int Find(int S[],int a){
    if(S[a]<0)
        return a;
    else
        return S[a]=Find(S,S[a]);
}
void Union(int S[],int a,int b){
    int c = Find(S,a);
    int d = Find(S,b);
    if(c!=d){
        if(S[c]<=S[d]){
            S[c]+=S[d];
            S[d]=c;
        }else{
            S[d]+=S[c];
            S[c]=d;
        }
    }
}
int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int N=isConnectedSize;
    int *S=(int*)malloc(sizeof(int)*(N+1));
    for(int i=0;i<N;i++)
        S[i]=-1;
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            if(isConnected[i][j]==1){
                Union(S,i,j);
            }
        }
    }
    int count = 0;
    for(int i=0;i<N;i++){
        if(S[i]<0)
            count++;
    }
    return count;
}