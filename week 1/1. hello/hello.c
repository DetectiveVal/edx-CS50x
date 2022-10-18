#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name? "); //Gets the user's name
    printf("hello, %s\n", name);//prints the user's name with hello.
}