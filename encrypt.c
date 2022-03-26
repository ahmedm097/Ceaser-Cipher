#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//By: Mohammed Ahmed 214396428

int main(int argc, char *argv[])

{

FILE * filen;

   char d;
char *xx;

int x = atoi(argv[2]);

//if shift amount is not between 1-25
if(x < 1 || x > 25 ){
  printf("Shift amount has to be a valid integer between 1-25 \n");
  exit(1);
}

FILE *fish = fopen(argv[1], "r");
//if file contains anything
   if (fish == NULL){
       printf("File doesnt contain anything");
  exit(1);
        //could not open file
}
//make space
   xx = malloc(1000);

strcpy(xx, argv[1]);
strcat(xx, ".enc");
filen = fopen(xx, "w+");
//

while((d = fgetc(fish)) != EOF){


 if(d >= 'a' && d <= 'z'){ //if its between a -z

   putc(((( d - 'a') + x) % 26 + 'a'), filen); //shift
 }
 else if (d >= 'A' && d <= 'Z')
   putc(((( d - 'A') + x) % 26 + 'A'), filen); //shift
else
  putc(d,filen); //if its not a character

}
fclose(fish);
fclose(filen);

}
