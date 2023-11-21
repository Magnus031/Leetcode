#define DataSize (1024*32)
typedef struct{
    int key;
    int value;
}KeyAndValue;

typedef struct {
    KeyAndValue data[DataSize];
} MyHashMap;


MyHashMap* myHashMapCreate() {
    MyHashMap *p=(MyHashMap*)malloc(sizeof(MyHashMap));
    for(int i=0;i<DataSize;i++){
        p->data[i].key=-1;
        p->data[i].value=-1;
    }
    return p;
}
int gethash(int key){
    return key%DataSize;
    //avoid the case that data[DataSize] doesn't exit;
}
int nexthash(int hash){
    return (hash*5+1+3)%DataSize;
}
void myHashMapPut(MyHashMap* obj, int key, int value) {
    int hash = gethash(key);//To place in the bucket;
    while(1){
        int rekey=obj->data[hash].key;
        if(rekey==-1||rekey==key){
            obj->data[hash].key=key;
            obj->data[hash].value=value;
            return;
        }
        hash=nexthash(hash);
    }

}

int myHashMapGet(MyHashMap* obj, int key) {
    int hash = gethash(key);
    while(1){
        int rekey=obj->data[hash].key;
        if(rekey==key)
            return obj->data[hash].value;
        if(rekey==-1)//it doesn't exist;
            return -1;
        hash=nexthash(hash);//this step is to rehash;because it has 
    }
}

void myHashMapRemove(MyHashMap* obj, int key) {
    int hash = gethash(key);
    while(1){
        int rekey=obj->data[hash].key;
        if(rekey==key){
            obj->data[hash].key=-1;
            obj->data[hash].value=-1;
            return;
        }
        if(rekey==-1)
            return;
        hash = nexthash(hash);
    }
}

void myHashMapFree(MyHashMap* obj) {
    free(obj);
}