int Find(int S[],int x){
    if(S[x]<0)
        return x;
    else 
        return S[x]=Find(S,S[x]);
}
int minSwapsCouples(int* row, int rowSize) {
    int N = rowSize;
    int *S = (int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i=i+2){
        S[i]=-1;
        S[i+1]=i;
    }
    int count=0;
    int j=0;
    for(int i=0;i<N-1;i++){
        int a = Find(S,row[i]);
        int b = Find(S,row[i+1]);
        j = i+1;
        if(a!=b){
            while(Find(S,row[j])!=a)
                j++;
            int temp = row[i+1];
            row[i+1] = row[j];
            row[j] =temp;
            count++;
        }
        i++; 
    }
    return count;
}