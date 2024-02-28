#include <cs50.h>
#include <stdio.h>
#include <strings.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
    int total;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool has_cycle (int w);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    for(int i = 0; i < pair_count; i ++)
    {
        printf("l97: %i = %i\n", i, pairs[i].total);
    }
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[]) // its not recording the vote's into preference
{
    for (int i = 0; i < candidate_count; i++)// TODO
    {
        if (strcasecmp (name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[]) //its correct
{
   for (int i = 0; i < candidate_count; i++) //for the vote
   {
        for (int j = i +1; j < candidate_count ; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
            //printf("ri %i, rj %i = %i \n", ranks[i],ranks[j], preferences[ranks[i]][ranks[j]]);
        }
   }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for(int i = 0; i < candidate_count; i++)// TODO
    {
        for(int j = i; j < candidate_count +1; j++)
        {
            if(preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pairs[pair_count].total = preferences[i][j] - preferences[j][i];
                pair_count++;
            }
            else if (preferences[i][j] < preferences [j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pairs[pair_count].total = preferences [j][i] - preferences[i][j];
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
       
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int p = 0; p < pair_count; p++)
    {
        if(has_cycle(p) == 0)// TODO
        {
            locked[pairs[p].winner][pairs[p].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)// TODO
    {
        bool win = true;
        for(int j = i +1; j < candidate_count; j++)
        {
            if(locked[i][j] == false)
            {
                win = false;
                break;
            }
        }
        if(win)
        {
            printf("%s\n", candidates[i]);
        }
    }
    return;
}

bool has_cycle (int w)
{
    for (int i = 0; i < pair_count; i++)
    {
        if(pairs[w].winner == pairs[i].loser)
        {
            return false;
        }
    }
    return true;
}
