#include <stdio.h>
#include <stdlib.h>

/*
Read the image file to an array, don't change it.
This function uses file operations that you are not expected to understand or modify.
*/
void read_image(int image[])
{
    FILE *in = fopen("surprise.dat", "rb");
    int count = 0;
    unsigned char b = fgetc(in);
    while (!feof(in))
    {
        image[count] = b;
        b = fgetc(in);
        count++;
    }
    fclose(in);
}

/*
Print the flattened image matrix
image: an array stores the flattened image in ROW MAJOR FASHION.
height: height of the image
width: width of the image

Conversion Rule:
print ' ' if the pixel value at coordinate i,j is at most 85;
print 'I' if the pixel value at coordinate i,j is bigger than 85 but at most 170;
print 'M' Otherwise;
*/
void image2char(int image[], int Height, int Width)
{
    // TODO: Write your code here.

}

int main(void)
{
    int image[45 * 44];

    printf("Reading 2D image matrix...");
    read_image(image);

    printf("done!. \n\nPlotting the image...\n");
    // TODO: uncomment the following line
    // image2char(image, 45, 44);

    printf("done! \n");
    return 0;
}
