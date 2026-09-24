#include <stdio.h>

int main(void)
{

    int score = 55;

    if (score >= 70)
    {
        printf("First Class.\n");
    }
    else if (score >= 60)  // [A] No need for 60<=score && score<70, why?
    {
        printf("Two-One.\n");
    }
    else if (score >= 50)
    {
        printf("Two-Two.\n");
    }
    else if (score >= 40)
    {
        printf("Pass.\n");
    }
    else
    {
        printf("Fail\n");
    }

    return 0;
}

/* [B] Note that "if" part contains only one line of code (one statement), so we could remove ALL curly brackets above.
   However, this does not compile

   int x = 1;
   if(x > 0)
    int y = 2;

   because if(x > 0) must be followed by a statement, but int y = 2; is a declaration, not a statement. Instead this works:
   int x = 1;
   if(x > 0){
    int y = 2;
   }
   because the curly braces create a compound statement or block.
*/


/* [C] Note that C does not care about indentation, for example:

if(score > 70)
 printf("First Class \n");
 printf("Well Done! \n");

 always prints "Well Done!"
*/
