#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./recover IMAGE\n");
    return 1;
  }
  FILE *input = fopen(argv[1], "r");
  if (input == NULL)
  {
    printf("The file can't be opened\n");
    return 1;
  }
  BYTE buffer[BLOCK_SIZE];
  int count = 0;
  FILE *pointer = NULL;
  char filename[8];
  while (fread(&buffer,1,BLOCK_SIZE, input) == BLOCK_SIZE)
  {
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
      if (!(count==0))
      {
        fclose(pointer);
      }
      sprintf(filename, "%03i.jpg", count);
      pointer = fopen(filename, "w");
      count++;
    }i
    if(!(count==0))
    {
      fwrite(&buffer,1,BLOCK_SIZE,pointer);
    }

  }
    fclose(pointer);
    fclose(input);

    return 0;
}
