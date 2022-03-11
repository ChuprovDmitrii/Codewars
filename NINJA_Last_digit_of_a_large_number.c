#include <string.h>
int last_digit(const char *a, const char *b)
{
  int i = strlen(a);
  char c ;
  char d[2];
  int j = strlen(b);
  int an = 0;

  c = a[i-1];

  d[0] = b[j-2];
  d[1] = b[j-1];
  if (c-48 == 0 || c-48 == 1 || c-48 == 5 || c-48 == 6){
    an=1;
  }
  else if (c-48 == 2 ||c-48 == 3 ||c-48 == 7 ||c-48 == 8){
    an=2;
  }
  else if(c-48 == 4 ||c-48 == 9){
    an=3;
  }
  
  if(j<2 && d[1] - 48 == 0){
    return 1;
  }
  if(j<2 && d[1] - 48 == 1){
    return c-48;
  }
  if(an==1){
    return c-48;
  }
  int z =0;
  int ans=0;
  if(an == 2){
    if(j>1){
      z=(d[0]-48)*10;
    }
    z =  z+(d[1]-48);
    i=1;
    ans= c-48;
    //printf("%d_%d\n",z%4,ans);
    while(i<z%4){
        
      ans= ans*(c-48);
      ans = ans%10;
      i++;
    }
    if(z%4==0){
      i=0;
          while(i<3){
        
      ans= ans*(c-48);
      ans = ans%10;
      i++;
    }
    }
    return ans;
  }
  if (an == 3){
    ans= c-48;
    if((d[1]-48)%2==0){
     ans= ans*ans;
      ans = ans%10;
    }
    return ans;
  }
  
  
    return 0;
}