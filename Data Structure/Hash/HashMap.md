#<center>HashMap</center>
> ####Actually, it is a mapping from key to value.

### Define a structure object;
```c
    #define datasize
    typedef {
        int key;
        int value;
    }keyandvalue;
    typedef{
        keyandvalue data[datasize];
    }hashmap;
```
#### <font color=red>There in order to let all objects can be the only to put in the array,I use the rehash(here is a function called nexthash).</font>

### Related Functions:
##### * Creat(void)
##### * Put(obj,key,value)
##### * gethash(key)
To get a hash value decide to put in which array index;
##### * nexthash(key)
If the index=hash ->has key1,but the key is not the same as We put (key,value);Colloquially speaking,it appears hash conflict!We take the measurement to rehash(nexthash function).
##### * Get(obj,key)
##### * Remove(obj,key)
##### * Free(obj)
