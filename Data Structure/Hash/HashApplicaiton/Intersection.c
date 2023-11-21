//This function is to get the intersection of 2 sets;
#include <stdlib.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *c = (int *)malloc(sizeof(int) * 1000);
    int *hashTable = (int *)malloc(sizeof(int) * 1001);
    // 初始化哈希表
    for (int i = 0; i < 1001; i++) {
        hashTable[i] = 0;
    }
    // 在哈希表中标记第一个数组出现的元素
    for (int i = 0; i < nums1Size; i++) {
        hashTable[nums1[i]] = 1;
    }
    int count = 0;
    // 遍历第二个数组，找到交集
    for (int i = 0; i < nums2Size; i++) {
        if (hashTable[nums2[i]] == 1) {
            c[count++] = nums2[i];
            hashTable[nums2[i]] = 0; // 避免重复添加相同的元素
        }
    }
    *returnSize = count; // 更新returnSize参数
    free(hashTable);
    return c;
}
