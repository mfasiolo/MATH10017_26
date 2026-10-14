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

/*
Create a simple edge image.
image: the original flattened image, stored in row-major order.
edges: an output array with room for Height * Width integers.

An interior pixel is an edge if its brightness differs from at least one of
its four neighbours by more than 100. Store 255 for an edge and 0 otherwise.
The first and last rows and columns should contain 0.
*/
void detect_edges(const int image[], int edges[], int Height, int Width)
{
    // TODO: Loop over every row and column.

    // TODO: Set boundary pixels to 0.

    // TODO: Compare interior pixels with their four neighbours.
}

int main(void)
{
    int image[45 * 44];
    int edges[45 * 44];

    printf("Reading 2D image matrix...");
    read_image(image);

    printf("done!. \n\nPlotting the image...\n");
    // TODO: uncomment the following line
    // image2char(image, 45, 44);

    printf("done! \n\n");

    printf("Detecting edges...\n");
    // TODO: complete detect_edges, then uncomment the following two lines
    // detect_edges(image, edges, 45, 44);
    // image2char(edges, 45, 44);

    printf("done! \n");
    return 0;
}
