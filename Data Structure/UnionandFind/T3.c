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
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int N = edgesSize;
    int *S=(int*)malloc(sizeof(int)*(N+1));
    for(int i=0;i<N;i++){
        S[i]=-1;
    }
    int *a = (int*)malloc(sizeof(int)*2);
    for(int i=0;i<2;i++){
        a[i]=0;
    }
    for(int i=0;i<N;i++){
        if(Find(S,edges[i][0])!=Find(S,edges[i][1])){
            Union(S,edges[i][0],edges[i][1]);
        }
        else{
            a[0]=edges[i][0];
            a[1]=edges[i][1];
            break;
        }
    }
    if(returnSize!=NULL){
        *returnSize = 2;
    }
    return a;
}