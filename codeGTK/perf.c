#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

  char mot1[50], mot2[50], mot3[50], mot4[50], mot5[50];

  FILE* f = popen("top", "r");
  fscanf(f,"%s", mot1);
  while (f != NULL){
  fscanf(f,"%s", mot1);

  printf("%s", mot1);
  }
  pclose(f);



return 0;
}
