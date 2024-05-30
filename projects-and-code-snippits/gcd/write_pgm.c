/** @file */
#include <stdio.h>

int write_pgm(const char *name, unsigned char *buf,
              int xsize, int ysize, int maxvalue)
{
  FILE *out = fopen(name,"w");
  if (!out) return 0;
  fprintf(out,"P2\n%d %d\n%d\n", xsize, ysize, maxvalue);
  for (int y = 0; y < ysize; y++)
  {
    for (int x = 0; x < xsize; x++)
    {
      fprintf(out,"%d ",buf[y*xsize + x]);
    }
    fprintf(out,"\n");
  }
  fclose(out);
  return 1;
}
