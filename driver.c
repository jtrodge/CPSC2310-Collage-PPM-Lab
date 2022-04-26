/*
  Jason Rodgers
  CPSC 2311 Sp22 Section 01
  Spring 22
  jtrodge@g.clemson.edu
*/

#include "ppm.h"

int main(int argc, char* argv[]) {
    FILE* in = fopen(argv[1], "r");
    FILE* out = fopen(argv[2], "w");
    // FILE* out2 = fopen(argv[3], "w");

    // Read in ppm image
    header_t* old_header;
    pixel_t** orig_pixel;
    old_header = readHeader(in);
    orig_pixel = readPPM(in, old_header);
    // 1st image of resizing
    pixel_t** copy_pixel;
    copy_pixel = allocateMemory(old_header);
    imageResize(old_header, orig_pixel, .5, copy_pixel);
    // 2nd image (not resized)
    pixel_t** copy_pixel2;
    copy_pixel2 = allocateMemory(old_header);
    imageResize(old_header, orig_pixel, 1, copy_pixel2);
    // Combines both images
    collageImages(old_header, copy_pixel, 1, copy_pixel2);
    grayScaleImage(old_header, copy_pixel2, out);
    // Free Memory
    freeMemory(orig_pixel, old_header);
    freeMemory(copy_pixel, old_header);
    freeMemory(copy_pixel2, old_header);

    return 0;
}
