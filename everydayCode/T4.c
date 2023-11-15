//Find the median sorted Arrays
/*
示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
*/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int m=(nums1Size+nums2Size)%2;//m==1 represents we only need to get the middle number;
    int a[2001]={0};
    int i=0,j=0;
    while(i<nums1Size&&j<nums2Size){
        if(nums1[i]<nums2[j]){
            a[i+j]=nums1[i];
            i++;
        }else{
            a[i+j]=nums2[j];
            j++;
        }
    }
    if(i==nums1Size){
        for(int p=j;p<nums2Size;p++)
            a[p+i]=nums2[p];
    }else{
        for(int p=i;p<nums1Size;p++)
            a[p+j]=nums1[p];
    }
    if(m==1)
        return a[(nums1Size+nums2Size)/2];
    else
        return (double)(a[(nums1Size+nums2Size)/2]+a[(nums1Size+nums2Size)/2-1])/2;
}