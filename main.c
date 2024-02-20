#include <stdlib.h>
#include <stdio.h>
#include <time.h>

enum Choice
{
    ROCK,
    PAPER,
    SCISSORS
};

const char *ChoiceStrings[] = {"Rock", "Paper", "Scissors"};

int generateComputerChoice(void);

void computerWins(void);
void playerWins(void);

int main()
{
    srand(time(NULL));

    printf("Rock Paper Scissors, made by SirGolem\n\n");

    printf("\tRock: %d\n", ROCK);
    printf("\tPaper: %d\n", PAPER);
    printf("\tScissors: %d\n\n", SCISSORS);

    int computerChoice = generateComputerChoice();
    int playerChoice;

    do
    {
        if (playerChoice == computerChoice)
        {
            computerChoice = generateComputerChoice();
            printf("Match! Try again.\n");
        }

        printf("> Make your selection: ");
        scanf("%d", &playerChoice);
    } while (playerChoice < ROCK || playerChoice > SCISSORS || playerChoice == computerChoice);

    printf("\tComputer: %s\n", ChoiceStrings[computerChoice]);
    printf("\tYou: %s\n", ChoiceStrings[playerChoice]);

    switch (computerChoice)
    {
    case ROCK:
        if (playerChoice == PAPER)
            playerWins();
        else
            computerWins();
        break;
    case PAPER:
        if (playerChoice == SCISSORS)
            playerWins();
        else
            computerWins();
        break;
    case SCISSORS:
        if (playerChoice == ROCK)
            playerWins();
        else
            computerWins();
        break;
    }

    return 0;
}

int generateComputerChoice()
{
    return rand() % (SCISSORS + 1);
}

void computerWins()
{
    printf("> You lost. Better luck next time.\n");
}

void playerWins()
{
    printf("> Congratulations, you won!\n");
}