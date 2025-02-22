#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 10  // Maximum players in the leaderboard

// Structure to store player information
struct Player {
    char name[50];
    int score;
};

// Array to store players
struct Player leaderboard[MAX_PLAYERS];
int player_count = 0;  // Number of players added

// Function to add or update a player's score
void add_score(char name[], int score) {
    // Check if player already exists and update their score
    for (int i = 0; i < player_count; i++) {
        if (strcmp(leaderboard[i].name, name) == 0) {
            if (score > leaderboard[i].score) {
                leaderboard[i].score = score; // Update score if it's higher
            }
            return; // Exit function since player already exists
        }
    }

    if (player_count >= MAX_PLAYERS) {
        printf("Leaderboard is full! Cannot add more players.\n");
        return;
    }

    // Add new player to the leaderboard
    strcpy(leaderboard[player_count].name, name);
    leaderboard[player_count].score = score;
    player_count++;

    // Sort leaderboard using Insertion Sort
    for (int i = 1; i < player_count; i++) {
        struct Player key = leaderboard[i];
        int j = i - 1;

        // Move elements that are smaller than key one position ahead
        while (j >= 0 && leaderboard[j].score < key.score) {
            leaderboard[j + 1] = leaderboard[j];
            j--;
        }
        leaderboard[j + 1] = key;
    }
}

// Function to display the leaderboard
void display_leaderboard() {
    printf("\nLeaderboard:\n");
    printf("----------------------\n");
    for (int i = 0; i < player_count; i++) {
        printf("%d. %s - %d\n", i + 1, leaderboard[i].name, leaderboard[i].score);
    }
    printf("----------------------\n");
}

// Main function
int main() {
    int choice;
    char name[50];
    int score;

    while (1) {
        printf("\n1. Add Player Score\n2. Display Leaderboard\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter player name: ");
                scanf("%s", name);
                printf("Enter score: ");
                scanf("%d", &score);
                add_score(name, score);
                break;
            case 2:
                display_leaderboard();
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please enter 1, 2, or 3.\n");
        }
    }
}
