//reverse the integer;
#include<limits.h>
int reverse(int x){
  int rev=0;
  while(x!=0){
    if(rev<INT_MIN/10||rev>INT_MAX/10){
      // over the range;
      return 0;
    }
    int digit = x%10;
    x/=10;
    rev = rev*10+digit;
  }
  return rev;
}