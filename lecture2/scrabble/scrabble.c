#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// global scopes
int scores[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// declare prototype
int get_score(string words);
int main(void)
{
    // assign value for alphabet
    // ask input for player
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // computer score of each word
    // biggest work will be here
    int score1 = get_score(player1);
    int score2 = get_score(player2);
    

    // print winner
    // compare the value of score player 1 and score player 2
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!");
    }
}

// get score function
int get_score(string words)
{
    int length = strlen(words);
    // detect input and assign to the alphabetical value
    int score = 0;
    for (int i = 0; i < length; i++)
    {
        // assign value A to the first integer

        if (isupper(words[i]))
        {
            // how does it connect? and know to assign the value somehow?  scores[0] is 1
            // ascii value word[i] = word[0] depends on user input. For example the value B = 66 -
            // 65 = 1 scores[1] would be 3
            score += scores[words[i] - 'A'];
        }
        else if (islower(words[i]))
        {
            score += scores[words[i] - 'a'];
        }
    }
    // return scores
    return score;
}
