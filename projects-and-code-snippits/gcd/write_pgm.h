#ifndef _WRITE_PGM_H
#define _WRITE_PGM_H

/**
 * Write the given two dimensional pixel buffer into a pgm file.
 *
 * @param name the name of the file to be written
 * @param buf a one dimensional buffer organized in row-major order
 * @param xsize the number of columns
 * @param ysize the number of rows.
 * @param maxvalue the highest value in the pixel buf.
 * @return 1 on success, otherwise 0.
 */
 int write_pgm(const char *name, unsigned char *buf,
              int xsize, int ysize, int maxvalue);
#endif
