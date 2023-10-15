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
      errno = EINVAL;
      err(1, "Too many arguments");
  } else if (argc == 2 && strcmp(argv[1], "-")) {
    
    inputFile = fopen(argv[1], "r");
  
  } else {
    
    inputFile = stdin;

    }
  for (i = 0; i < 3; i++) {
      uint8_t input_bytes[3] = {0};
      size_t n_read = fread(input_bytes, 1, 3, inputFile);
  }
