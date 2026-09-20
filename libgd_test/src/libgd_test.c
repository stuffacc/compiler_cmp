#include <stdio.h>
#include <gd.h>

int main(int argc, char **argv)
{
    FILE* input;
    FILE* output;
    gdImagePtr gdImage;

    input = fopen("input.png", "rb");

    if (input == NULL) {
        fprintf(stderr, "Cannot open input.png\n");
        return 1;
    }

    gdImage = gdImageCreateFromPng(input);
    fclose(input);

    if (gdImage == NULL) {
        fprintf(stderr, "Cannot decode input.png\n");
        return 1;
    }

    gdImageGaussianBlur(gdImage);



    output = fopen("output.png", "wb");

    if (output == NULL) {
        fprintf(stderr, "Cannot open output.png\n");
        return 1;
    }

    gdImagePng(gdImage, output);

    fclose(output);
    gdImageDestroy(gdImage);
    return 0;
}