#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>
#include <err.h>


static char const b64_alphabet[] =
   "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
   "abcdefghijklmnopqrstuvwxyz"
   "0123456789"
   "+/";

int main(int argc, char *argv[])
   {
    FILE *inputFile;
    int i;

    if (argc > 2) {
      fprintf(stderr, "Usage: %s [FILE]\n", argv[0]);
      errx(1, "Too many arguments");
    }
    else if (argc == 2 && strcmp(argv[1], "-")){

        inputFile = fopen(argv[1], "r");
      }
    else {
        inputFile = stdin;
      }
   }
