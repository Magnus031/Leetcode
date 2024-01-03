int Find(int S[],int x){
    if(S[x]<0)
        return x;
    else 
        return S[x]=Find(S,S[x]);
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
int makeConnected(int n, int** connections, int connectionsSize, int* connectionsColSize) {
    int N = connectionsSize;
    int *S=(int*)malloc(sizeof(int)*(n));
    for(int i=0;i<n;i++){
        S[i]=-1;
    }
    int total=0;
    for(int i=0;i<N;i++){
        if(Find(S,connections[i][0])!=Find(S,connections[i][1]))
            Union(S,connections[i][0],connections[i][1]);
        else
            total++;
    }
    int count=0;
    int m=0;
    for(int i=0;i<n;i++){
        if(S[i]<0){
            count++;
            m+=S[i];
        }
    }
    m = m*(-1);
    int temp=count;
    count = n-m+temp-1;//count represents the number of connected components;
    if(total>=count)
        return count;
    else 
        return -1;

}