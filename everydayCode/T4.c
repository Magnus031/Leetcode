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