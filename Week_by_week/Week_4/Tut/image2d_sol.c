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
Print a flattened image array. 
image: an array stores the flattened image.
Height: the height of the image.
Width: the width of the image.
*/
void image2char(int image[], int Height, int Width)
{
    for(int i = 0; i < Height; i++){
        for(int j = 0; j < Width; j++){
            if( image[i*Width + j] <= 85){
                printf(" ");
            }
            else if(image[i*Width + j] <= 170){
                printf("I");
            }else{
                printf("M");
            }
        }
        printf("\n");
    }
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
    for (int i = 0; i < Height; i++) {
        for (int j = 0; j < Width; j++) {
            int index = i * Width + j;

            if (i == 0 || i == Height - 1 || j == 0 || j == Width - 1) {
                edges[index] = 0;
            } else {
                int pixel = image[index];

                if (abs(pixel - image[index - Width]) > 100 ||
                    abs(pixel - image[index + Width]) > 100 ||
                    abs(pixel - image[index - 1]) > 100 ||
                    abs(pixel - image[index + 1]) > 100) {
                    edges[index] = 255;
                } else {
                    edges[index] = 0;
                }
            }
        }
    }
}

int main(void)
{
    int image[45 * 44];
    int edges[45 * 44];

    printf("Reading 2D image matrix...");

    read_image(image);

    printf("done!. \n\nPlotting the image...\n");
    image2char(image, 45, 44);

    printf("done! \n\n");

    printf("Detecting edges...\n");
    detect_edges(image, edges, 45, 44);
    image2char(edges, 45, 44);

    printf("done! \n");
    return 0;
}
