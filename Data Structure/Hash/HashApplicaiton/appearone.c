//To find the elements that has appeared once.
/*
示例 1 ：

输入：nums = [2,2,1]
输出：1
示例 2 ：

输入：nums = [4,1,2,1,2]
输出：4
示例 3 ：

输入：nums = [1]
输出：1
*/
int singleNumber(int* nums, int numsSize) {
    int a[60001]={0};
    for(int i=0;i<numsSize;i++){
        if(a[nums[i]+30000]==0)
            a[nums[i]+30000]=1;
        else
            a[nums[i]+30000]=0;
    }
    for(int i=0;i<numsSize;i++){
        if(a[nums[i]+30000]==1)
            return nums[i];
    }
    return 0;
}
//I use the hash to vertify if the element has appeared again.