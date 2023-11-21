//To find the happy number;
/*
示例 1：

输入：n = 19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
示例 2：

输入：n = 2
输出：false
*/
#include<stdbool.h>
int get(int n){
    //this function is to get the sum of all digits' square of n;
    int sum=0;
    int rev=n;
    int digit=0;
    while(rev/10>0){
        digit=rev%10;
        sum+=pow(digit,2);
        rev=rev/10;
    }
    sum+=pow(rev,2);
    return sum;
}
bool isHappy(int n) {
    int a[10000]={0};
    int p=get(n);
    while(p!=1){
        a[p]=1;
        p=get(p);
        if(a[p]==1)//Use the hash set to vertify if the process entry loop;
            return false;
    }
    return true;
    
}