//给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 
/*
示例 1：

输入：nums = [1,2,3,1]
输出：true
示例 2：

输入：nums = [1,2,3,4]
输出：false
示例 3：

输入：nums = [1,1,1,3,3,4,3,2,4,2]
输出：true
*/
#include<stdbool.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

bool containsDuplicate(int* nums, int numsSize){
    int i,j;
    bool flag=false;
    for(i=0;i<numsSize-1;i++){
        for(j=numsSize-1;j>i;j--){
            if(nums[j]<nums[j-1]){
                swap(&nums[j],&nums[j-1]);
                flag=true;
            } 
            if(nums[j]==nums[j-1])
                return true;
        }
        if(flag==false)
            return false;
            }
    return false;
}