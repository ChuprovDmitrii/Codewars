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
    int k=1;
    answer = (char *) malloc(1);
  
    char *let;
    int kk=0;
    let = (char *) malloc(1);
    
    
    while ( morse_code[i] != '\0' ) {
        if ( morse_code[i] == '-' || morse_code[i] == '.' )  {
        
          kk++;
    			let = (char *) realloc(let,kk+1);
    			let[kk-1]=morse_code[i];
        

      	}
		    else if (morse_code[i] == ' ') {
		    
          if (morse_code[i-1] == '.'||  morse_code[i-1] == '-') {
            
            j = 0 ;
       	
       		    while ( strcmp ( morse[j] , let ) ) {
        	
       		       j++ ;
        	
        	    }
        	
        	    free(let);
              let = (char *) malloc(1);
              kk=0;
              while (!let){
                let = (char *) malloc(1);
              }
          
        	    
        	    answer = (char *) realloc(answer,k+1);
              k++;
        	    strcat(answer, ascii[j]);
        	
            
            
          }
          
          else if (morse_code[i-1] ==  ' ' && morse_code[i+1] ==  ' ' && answer[k-2] != ' ' ) {
          		
          	answer = (char *) realloc(answer,k+1);
            k++;
   	        strcat(answer, " ");
            
            
          }
          
        }
        
    	i++ ;
    }
        
        if (strcmp ( "" , let )!=0)
        {
        
        j = 0 ;
        while ( strcmp ( morse[j] , let ) ){
          j++ ;
        }
        	k++;
        	answer = (char *) realloc(answer,k+1);
        	strcat(answer, ascii[j]);
        	
        }
    //  <----  hajime!
 
    return  answer;
}