#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char *morse[55] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", "...-..-", ".--.-.", "...---..."};  
const char *ascii[55] = {"A",  "B",    "C",    "D",   "E", "F",    "G",   "H",    "I",  "J",    "K",   "L",    "M",  "N",  "O",   "P",    "Q",    "R",   "S",   "T", "U",   "V",    "W",   "X",    "Y",    "Z",    "0",     "1",     "2",     "3",     "4",     "5",     "6",     "7",     "8",     "9",     ".",      ",",      "?",      "'",      "!",      "/",     "(",     ")",      "&",     ":",      ";",      "=",     "+",     "-",      "_",      "\"",     "$",       "@",      "SOS"};

char *decode_morse(const char* morse_code) 
{
    int i=0 ;
    int j=0 ;
  
    char *answer;
    int k=0;
    answer = (char *) malloc(1);
   answer[0]= '\0';
  
  
    char let[20]={0};
    int i_let =0 ;
    int space=1;
    
    
     if ( morse_code[i] == '-' || morse_code[i] == '.' )  {

        
         let[i_let]=morse_code[i];
          let[i_let+1]='\0';
          i_let++;

      	}
    
  
  i++;
  
  
  
  
  
  
  
  
  
  while ( morse_code[i] != '\0' ) {
        if ( morse_code[i] == '-' || morse_code[i] == '.' )  {

        
         let[i_let]=morse_code[i];
          let[i_let+1]='\0';
          i_let++;

      	}
		    else if (morse_code[i] == ' ') {
          
          
		    
          if (let[0] != '\0') {
            
            j = 0 ;
       	
       		    while ( strcmp ( morse[j] , let ) ) {
        	
       		       j++ ;
        	
        	    }
        	let[i_let]='0';
        	    let[0]='\0';
        	    i_let=0;
        	    
        

          if(j==54){
            k=k+4;
          }
        	    
        	   
             k++;
        	   answer = (char *) realloc(answer,k+1);
             while(answer==0) answer = (char *) realloc(answer,k+1);
        	   strcat(answer, ascii[j]);
            space=0;
        	
            
            
          }
          else if(morse_code[i-1] ==  ' ' && morse_code[i+1] ==  ' ' && space ==0){
              k++;
        	   answer = (char *) realloc(answer,k+1);
             while(answer==0) answer = (char *) realloc(answer,k+1);
        	   strcat(answer, " ");
            space++;
          }
          

          
        }
        
    	i++ ;
    }
        
        
  
  
  
  
  
    if (let[0]!='\0')
        {
        
        j = 0 ;
        while ( strcmp ( morse[j] , let ) ){
          j++ ;
        }
           if(j==54){
            k=k+4;
          }
        	k++;
        	answer = (char *) realloc(answer,k+1);
          while(answer==0) answer = (char *) realloc(answer,k+1);
        	strcat(answer, ascii[j]);
        	
        }
        if (answer[strlen(answer)-1] == ' '){
          
          answer[strlen(answer)-1]='\0';
        }
         
          
    //  <----  hajime!
 
    return  answer;
}
    
 