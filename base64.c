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
  int x;

  if (argc > 2) {
      
      fprintf(stderr, "Usage: %s [FILE]\n", argv[0]);
      errx(1, "Too many arguments");
  } else if (argc == 2 && strcmp(argv[1], "-")) {
    
    inputFile = fopen(argv[1], "r");
  
  } else {
    
    inputFile = stdin;

    }
  for (;;) {
      uint8_t input_bytes[3] = {0};
      size_t n_read = fread(input_bytes, 1, 3, inputFile);
      if (n_read != 0) {
      int alph_ind[sizeof(inputFile)];
      alph_ind[0] = input_bytes[0] >> 2;
      alph_ind[1] = (input_bytes[0] << 4 | input_bytes[1] >> 4) & 0x3Fu;
      alph_ind[2] = input_bytes[1] >> 2 & 0x3Fu;
      alph_ind[3] = input_bytes[2] << 2 & 0x3Fu;

      char output[4];
      output[0] = b64_alphabet[alph_ind[0]];
      output[1] = b64_alphabet[alph_ind[1]];
      output[2] = b64_alphabet[alph_ind[2]];
      output[3] = b64_alphabet[alph_ind[3]];

      size_t n_write = fwrite(output, 1, sizeof(output), stdout);
      if (ferror(inputFile)) err(1, "%s", input_bytes);
  }
      int num_requested = 4;
      if (n_read < num_requested) {
        for (x = num_requested - n_read; x != 0; x--){
        fprintf(stdout, "=");
        }

    if (feof(inputFile)) break;
    if (ferror(inputFile)) err(1, "%s", input_bytes);

      }
}
if (inputFile != stdin) fclose(inputFile);
}
