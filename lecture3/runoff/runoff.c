#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
// for example voter 1 has preferences of candidate j as the first preferences
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    // if the candidate count is more than max candidates
    // print "Too much!"
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    // iterate through candidate
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    // if the voter count more than max_voters
    // print too much voter
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            // keep asking for vote until
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            // if won is true then break
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                // it candidate eliminated == false then
                // print candidate name that is not eliminated
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        // do the function for eliminating candidate with lowest vote
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            // reset the candidate to 0 after eliminating the candidate
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    // iterate through the array of candidates
    // if its match return true else return false
    // using strcmp?
    for (int i = 0; i < candidate_count; i++)
    {
        // if the name of the vote same as the candidate then do something
        if (strcmp(candidates[i].name, name) == 0)
        {
            // set voter preferences
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    // update the number of votes each candidate have
    // vote for top-preferred candidate
    // if candidate eliminated = false do something

    for (int i = 0; i < voter_count; i++)
    {
        // update the vote
        for (int j = 0; j < candidate_count; j++)
        {
            int candidate_index = preferences[i][j];
            if (!candidates[candidate_index].eliminated)
            {
                candidates[candidate_index].votes++;
                break;
            }
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        printf("Candidate %s: %i votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    // if candidate has more than 50% of the vote print their name and return true
    // else return false
    for (int i = 0; i < candidate_count; i++)
    {
        // iterate through the candidate and find if the votes bigger than 50%
        // check through the candidate votes
        if (candidates[i].votes > voter_count / 2)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int minimum_votes = INT_MAX;
    // TODO should return the minimum vote total for each candidate in election
    for (int i = 0; i < candidate_count; i++)
    {
        // if candidate still on election and not eliminated
        if (!candidates[i].eliminated)
        {
            // for every candiadte look for the smallest votes
            if (candidates[i].votes < minimum_votes)
            {
                minimum_votes = candidates[i].votes;
            }
        }
    }
    return minimum_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{

    // TODO if candidate still in election have the same vote count return true
    for (int i = 0; i < candidate_count; i++)
    {
        // if candidate is not eliminated
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO take the minimum number of votes that anyone in the election currently has
    // if candidate having the minimum vote eliminate the candidate
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
