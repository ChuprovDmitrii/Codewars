#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare( const void *arg1, const void *arg2 )
{
  if ( *(int *)arg1 == *(int *)arg2 ){
   
    return 0;
 
  }
  else{
         
    return  *(int *)arg2 - *(int *)arg1;
 
  }

    
}

char* mix(char* s1, char* s2) {
    
  int jfors1[26] = {0};
 
  int jfors2[26] = {0};
  int ansjfors[26][3] = {0};
 
  //97-a
  int i = 0;
  
  while ( s1[i] != '\0' ){
      
        if( 96 < s1[i] && s1[i] < 123){
       
            jfors1[s1[i]-97]++;
        
      }
    
      i++;
    
    }
  
  i=0;
  
 while ( s2[i] != '\0' ){
      
        if( 96 < s2[i] && s2[i] < 123){
        
            jfors2[s2[i]-97]++;
         
        }
    
      i++;
    
}

  
char *answer;
int k=2;
answer = (char *) malloc(2);
answer[0]= '\0';
 
i=0;
  
 while ( i < 26 ){
       
    if ( jfors1[i] > jfors2[i] ) {
        ansjfors[i][0] = jfors1[i];
        ansjfors[i][1] = i;
        ansjfors[i][2]=1;
    }
    else if (jfors1[i] < jfors2[i]){
        ansjfors[i][0]=jfors2[i];
        ansjfors[i][1]=i;
        ansjfors[i][2]=2;
    }
    else if ( jfors1[i] == jfors2[i] ){
        ansjfors[i][0]=jfors2[i];
        ansjfors[i][1]=i;
        ansjfors[i][2]=3;
     }
     
    i++;
}
qsort(ansjfors,sizeof(ansjfors)/12,12,compare);
/*i=0;
while (i<26){
      printf("%d--%d--%d--%c\n",ansjfors[i][0],ansjfors[i][1],ansjfors[i][2],ansjfors[i][1]+97);
  i++;
      
  }*/
  /*i=0;
  while (i<26){
      if(ansjfors[i][0] == ansjfors[i+1][0] && ansjfors[i][1] < ansjfors[i][+1]){
          printf("eror");
      }
      
  i++;
      
  }
  */
  
  //        test
/*i=0;
char ze[2];
ze[0]=',';
ze[1]='\0';
int j=0;
int perm[26][2] = {0};
int jj = 0;
int jjj = 0;
int jjjj = 0;
while ( i < 26 ){
  if ( ansjfors[i][0] > 1 ){
      if (ansjfors[i][2]!=3){
          if (jj > 0 && perm[0][0] > ansjfors[i][0] ){
              jjj = 0;
            while ( jj > jjj && perm[jjj][0] > ansjfors[i][0] ){
                k=k+2;
            answer = (char *) realloc(answer,k+1);
            while(answer==0) answer = (char *) realloc(answer,k+1); 
            strcat(answer, "=:");
            jjjj = 0;
            while(jjjj < perm[jjj][0]){
            k=k+1;
            answer = (char *) realloc(answer,k+1);
            while(answer==0) answer = (char *) realloc(answer,k+1); 
                ze[0] = perm[jjj][1]+97;
                strcat(answer, ze);
                jjjj++;
            }
            k=k+1;
            answer = (char *) realloc(answer,k+1);
            while(answer==0) answer = (char *) realloc(answer,k+1); 
            strcat(answer, "/");
            //k++;
            //answer = (char *) realloc(answer,k+1);
            //while(answer==0) answer = (char *) realloc(answer,k+1);
            //ze[0] = ansjfors[i][1]+97;
            //strcat(answer, ze);
            jjj++;    
            }
              memset(perm,0,jjj*8);
              
              jj=jj-jjj;
              qsort(perm,sizeof(perm)/8,8,compare);
          }
        
        k=k+2;
        answer = (char *) realloc(answer,k+1);
        while(answer==0) answer = (char *) realloc(answer,k+1);          
        
        ze[0] = ansjfors[i][2]+48;
        strcat(answer, ze);
        strcat(answer, ":");
        
        j=0;
        while (ansjfors[i][0] > j){
            k++;
            answer = (char *) realloc(answer,k+1);
            while(answer==0) answer = (char *) realloc(answer,k+1);
            ze[0] = ansjfors[i][1]+97;
            strcat(answer, ze);
            j++;    
        }
            k=k+2;
            answer = (char *) realloc(answer,k+1);
            while(answer==0) answer = (char *) realloc(answer,k+1); 
           strcat(answer, "/");
          
      }
      else{
          perm[jj][0] = ansjfors[i][0];
          perm[jj][1] = ansjfors[i][1];
          jj++;
      }
 

    
  }    
  i++;
      
  }
            if (jj > 0  ){
              jjj = 0;
            while ( jj > jjj ){
                k=k+2;
            answer = (char *) realloc(answer,k+1);
            while(answer==0) answer = (char *) realloc(answer,k+1); 
            strcat(answer, "=:");
            jjjj = 0;
            while(jjjj < perm[jjj][0]){
            k=k+1;
            answer = (char *) realloc(answer,k+1);
            while(answer==0) answer = (char *) realloc(answer,k+1); 
                ze[0] = perm[jjj][1]+97;
                strcat(answer, ze);
                jjjj++;
            }
             k=k+2;
            answer = (char *) realloc(answer,k+1);
            while(answer==0) answer = (char *) realloc(answer,k+1); 
           strcat(answer, "/");
            //k++;
            //answer = (char *) realloc(answer,k+1);
            //while(answer==0) answer = (char *) realloc(answer,k+1);
            //ze[0] = ansjfors[i][1]+97;
            //strcat(answer, ze);
            jjj++;    
            }
            
            
          }
          
          answer[strlen(answer)-1]='\0';
          */
//  printf("%s\n",answer);

i=0;
int max=0;

char perm2[26][2] = {0};
int pe2 = 0;
char perm3[26][2] = {0};
int pe3 = 0;

char ze[2];
ze[0]='0';
ze[1]='\0';

int j = 0;
int jj = 0;

max = ansjfors[i][0];

while(i < 26){
    if(ansjfors[i][0] > 1){
        if (ansjfors[i][0] < max){
            // exo past
            if (pe2 > 0){
                jj = 0;
                while (jj < pe2){
                    k=k+2;
                    answer = (char *) realloc(answer,k+1);
                    while(answer==0) answer = (char *) realloc(answer,k+1); 
                    strcat(answer, "2:");    
                    j = 0;
                    
                    while (j <perm2[jj][0]){
                         k++;
                        answer = (char *) realloc(answer,k+1);
                        while(answer==0) answer = (char *) realloc(answer,k+1);
                        ze[0] = perm2[jj][1]+97;
                        strcat(answer, ze);    
                        j++;
                    }
                    k++;
                    answer = (char *) realloc(answer,k+1);
                    while(answer==0) answer = (char *) realloc(answer,k+1);
                    strcat(answer, "/");    
                    jj++;
                }
                memset(perm2,0,pe2*8);
                pe2 = 0;
                
            }
            if (pe3 > 0){
                jj = 0;
                while (jj < pe3){
                    k=k+2;
                    answer = (char *) realloc(answer,k+1);
                    while(answer==0) answer = (char *) realloc(answer,k+1); 
                    strcat(answer, "=:"); 
                    //printf("%c\n",perm3[pe3][1]+97);
                    j = 0;
                    while (j <perm3[jj][0]){
                         k++;
                        answer = (char *) realloc(answer,k+1);
                        while(answer==0) answer = (char *) realloc(answer,k+1);
                        ze[0] = perm3[jj][1]+97;
                        strcat(answer, ze);    
                        j++;
                    }
                    k++;
                    answer = (char *) realloc(answer,k+1);
                    while(answer==0) answer = (char *) realloc(answer,k+1);
                    strcat(answer, "/");    
                    jj++;
              
                }
                memset(perm3,0,pe3*8);
                pe3 = 0;      
                                
            }
        
           max = ansjfors[i][0];
        }
        if(ansjfors[i][2] == 1){
        k=k+2;
        answer = (char *) realloc(answer,k+1);
        while(answer==0) answer = (char *) realloc(answer,k+1); 
        strcat(answer, "1:"); 
        j = 0;
        while (j < ansjfors[i][0]){
            k++;
            answer = (char *) realloc(answer,k+1);
            while(answer==0) answer = (char *) realloc(answer,k+1);
            ze[0] = ansjfors[i][1]+97;
            strcat(answer, ze);            
            
            
            j++;
        }
        k++;
        answer = (char *) realloc(answer,k+1);
        while(answer==0) answer = (char *) realloc(answer,k+1);
        strcat(answer, "/");            
        }
        else if (ansjfors[i][2] == 2){
            perm2[pe2][0] = ansjfors[i][0];
            perm2[pe2][1] = ansjfors[i][1];
            pe2++;
        }
        else if (ansjfors[i][2] == 3){
            perm3[pe3][0] = ansjfors[i][0];
            perm3[pe3][1] = ansjfors[i][1]; 
            pe3++;
        }
        
    }
    
    i++;
}
            if (pe2 > 0){
                jj = 0;
                while (jj < pe2){
                    k=k+2;
                    answer = (char *) realloc(answer,k+1);
                    while(answer==0) answer = (char *) realloc(answer,k+1); 
                    strcat(answer, "2:");    
                    j = 0;
                    while (j <perm2[jj][0]){
                         k++;
                        answer = (char *) realloc(answer,k+1);
                        while(answer==0) answer = (char *) realloc(answer,k+1);
                        ze[0] = perm2[jj][1]+97;
                        strcat(answer, ze);    
                        j++;
                    }
                    k++;
                    answer = (char *) realloc(answer,k+1);
                    while(answer==0) answer = (char *) realloc(answer,k+1);
                    strcat(answer, "/");    
                    jj++;
                }
                memset(perm2,0,pe2*8);
                pe2 = 0;
                
            }
            if (pe3 > 0){
                jj = 0;
                while (jj < pe3){
                    k=k+2;
                    answer = (char *) realloc(answer,k+1);
                    while(answer==0) answer = (char *) realloc(answer,k+1); 
                    strcat(answer, "=:"); 
                    //printf("%c\n",perm3[pe3][1]+97);
                    j = 0;
                    while (j <perm3[jj][0]){
                         k++;
                        answer = (char *) realloc(answer,k+1);
                        while(answer==0) answer = (char *) realloc(answer,k+1);
                        ze[0] = perm3[jj][1]+97;
                        strcat(answer, ze);    
                        j++;
                    }
                    k++;
                    answer = (char *) realloc(answer,k+1);
                    while(answer==0) answer = (char *) realloc(answer,k+1);
                    strcat(answer, "/");    
                    jj++;
                  
                }
             memset(perm3,0,pe3*8);
            pe3 = 0;                    
            }
 


    answer[strlen(answer)-1]='\0';
  return answer;
  // your code
}