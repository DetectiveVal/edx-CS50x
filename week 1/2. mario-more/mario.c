#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int userheight;
    do
    {
        //gets input
        userheight = get_int("Enter height: ");
        //must be a positive number that is less than 8
    }
    while (userheight < 1 || userheight > 8);
    //number of lines
    for (int column = 0; column < userheight; column++)
    {
        //number of spaces before the pyramid
        for (int gap = userheight - column - 1; gap > 0; gap--)
        {
            printf(" ");
        }
        //left column
        for (int row = 0; row <= column; row++)
        {
            printf("#");
        }
        //space inbetween
        printf("  ");
        //right column
        for (int rowright = 0; rowright <= column; rowright++)
        {
            printf("#");
        }

        //make a new line after every column

        printf("\n");
    }

}