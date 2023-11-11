//Design a hash list
typedef struct {
    int num;
    int *set;
} MyHashSet;

MyHashSet* myHashSetCreate() {
    MyHashSet *p=(MyHashSet*)malloc(sizeof(MyHashSet));
    p->num=0;
    p->set=(int *)malloc(sizeof(int)*1000001);
    return p;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    if(obj->set[key]==0){
        obj->set[key]=1;
        obj->num++;
    }
    obj->set[key]=1;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    if(obj->set[key]==1){
        obj->num--;
        obj->set[key]=0;
    }
}

int myHashSetContains(MyHashSet* obj, int key) {
    if(obj->set[key]==1)
        return 1;
    return 0;
}

void myHashSetFree(MyHashSet* obj) {
    obj->num=0;
    free(obj->set);
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/