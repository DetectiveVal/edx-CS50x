#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
//declaring functions
double get_words(string Text, char CurrentVal);
double get_sentences(string Text, char CurrentVal);
double get_letters(string Text, char CurrentVal);
void get_grade(double index);

int main(void)
{
    //initializing variables
    char CurrentVal = 'a';
    string Text = get_string("Enter text:");
    double thesentences = get_sentences(Text, CurrentVal);
    double theletters = get_letters(Text, CurrentVal);
    double thewords = get_words(Text, CurrentVal);
    //This makes it so even if a text has less than 100 words the average used in the Coleman-Liau index is based on 100
    double L = theletters / thewords * 100;
    double S = thesentences / thewords * 100;
    // calculates grade using The Coleman-Liau index
    double index = round(0.0588 * L - 0.296 * S - 15.8);
    get_grade(index);
}
//Counts how many words in string
double get_words(string Text, char CurrentVal)
{
    double words = 1;
    int i = 0;
    do
    {
        CurrentVal = Text[i];
        if (CurrentVal == ' ')
        {
            words++;
        }
        i++;
    }
    while (i < strlen(Text));
    return words;
}

//Counts how many sentences in string
double get_sentences(string Text, char CurrentVal)
{
    int i = 0;
    double sentences = 0;
    do
    {
        CurrentVal = Text[i];
        if (CurrentVal == '!' || CurrentVal == '.' || CurrentVal == '?')
        {
            sentences++;
        }
        i++;
    }
    while (i < strlen(Text));
    return sentences;
}
//Counts how many letters in string
double get_letters(string Text, char CurrentVal)
{
    double Letters = 0;
    int i = 0;
    do
    {
        CurrentVal = Text[i];
        if (isalpha(CurrentVal))
        {
            Letters++;
        }
        i++;
    }
    while (i < strlen(Text));
    return Letters;
}
//prints the grade based on index size
void get_grade(double index)
{
    //if the grade is less than 1 it will say so and anything with an index value of above 16 will be above 16.
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", (int)index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}