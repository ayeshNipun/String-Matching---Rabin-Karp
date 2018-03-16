#include <stdio.h>
#include <string.h>

#define d 256

void Search(char [], char[], int);

void main(){
  char txt[] = "ayesh nipun gamage ayeshn";
  char pat[] = "ayesh";
  int q = 101;
  Search(pat,txt,q);
}



void Search(char pat[], char txt[], int q){
  
  int m = strlen(pat);
  int n = strlen(txt);
  int i,j;
  int p = 0;
  int t = 0;
  int h = 1;
  
  for(i=0; i<m-1; i++){
    h = (h*d)%q;
  }

  for(i=0; i<m; i++){
    p = (p*d + pat[i])%q;
    t = (t*d + txt[i])%q;
  }
  
  //sliding pat over txt 
  for (i=0; i<n-m; i++){
    if(p==t){
      for(j=0; j<m; j++){
        if(txt[i+j]!=pat[j]){
          break;
        }
      }
      if(j==m){
        printf("Match found at %d",i);
        printf("\n");
      }
    }
    if(i<n-m){
      t=(d*(t-txt[i]*h) + txt[i+m])%q;
      if(t<0){
        t=t+q;
      }
    }
  }
  
}