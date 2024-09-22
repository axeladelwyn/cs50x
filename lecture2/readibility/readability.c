#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);
int main(void)
{
    // prompt a text input
    string text = get_string("Text: ");

    int letters = count_letters(text);
    // printf("letters is %i\n", letters);

    int words = count_words(text);
    // printf("Words is %i\n", words);

    int sentences = count_sentences(text);
    // printf("Sentences is %i\n", sentences);

    // do some algorithm to calculate text level
    // Coleman-Liau index, index = 0.0588 * L - 0.296 * S - 15.8
    // L is average number of letters per 100 words
    // S is the average number of sentences per 100 words
    // L = total letters / 100
    // S = total sentences/ 100
    // how do you decide its a sentence or not?

    // how do you count total letters

    // how do you count total sentences
    float L = ( (float)letters /  words) * 100.0;
    float S = ( (float)sentences /  words) * 100.0;
    // printf("L and S is %f %f\n", L, S);

    float grade = (0.0588 * (float)L) - (0.296 * (float)S) - 15.8;
    // printf("grade is %f\n", grade);

    int rounded_grade = round(grade);
    // printf("Rounded grade is %i\n", rounded_grade);

    if (rounded_grade < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (rounded_grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", rounded_grade);
    }
}

int count_letters(string s)
{
    // done
    // count the amount of letters , space are excluded
    // isalpha
    int counter = 0;
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        if (isalpha(s[i]))
        {
            counter++;
        }
    }
    return counter;
}

int count_words(string s)
{
    // count the amount of space + 1
    int counter = 0;
    int length = strlen(s);
    // how to implement this?
    // how do i check a space in the string
    // how do i count the amount of space in string + 1 ?
    for (int i = 0; i < length; i++)
    {
        if (isspace(s[i]))
        {
            counter++;
        }
    }
    return counter + 1;
}

int count_sentences(string s)
{
    int counter = 0;
    int length = strlen(s);
    // count punctuation mark such as ! . ?
    for (int i = 0; i < length; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            counter++;
        }
    }

    return counter;
}
