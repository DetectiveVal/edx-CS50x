#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Gets card's number
    long card_number = get_long("Please enter your card number: ");
    //card number legth
    int number_counter = 0;
    long ccn = card_number;
    while (ccn > 0)
    {
        ccn = ccn / 10;
        number_counter++;
    }
    //check if one of the correct lenghts
    if (number_counter != 13 && number_counter != 15 && number_counter != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    //Luhn's algorithm
    int step1 = 0;
    int step2 = 0;
    long ccn2 = card_number;
    int total;
    int step2mod, step1mod, double_mod1, double_mod2;
    do
    {
        // second step of Luhn's algorithm
        step2mod = ccn2 % 10;
        ccn2 = ccn2 / 10;
        step2 = step2 + step2mod;
        //first step of Luhn's algorithm
        step1mod = ccn2 % 10;
        ccn2 = ccn2 / 10;
        step1mod = step1mod * 2;
        double_mod1 = step1mod % 10;
        double_mod2 = step1mod / 10;
        step1 = step1 + double_mod1 + double_mod2;
    }
    while (ccn2 > 0);

    total = step1 + step2;

    //last step of Luhn
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    // get last 2 digits
    long firstdigits = card_number;
    do
    {
        firstdigits = firstdigits / 10;
    }
    while (firstdigits > 100);
    //check which card
    if ((firstdigits / 10 == 5) && (0 < firstdigits % 10) && (6 > firstdigits % 10))
    {
        printf("MASTERCARD\n");
    }
    else if ((firstdigits / 10 == 3) && (firstdigits % 10 == 4 || firstdigits % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if (firstdigits / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }



}