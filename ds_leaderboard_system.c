#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 10 

struct Player {
    char name[50];
    int score;
};

struct Player leaderboard[MAX_PLAYERS];
int player_count = 0;  

void sort_leaderboard() {
    for (int i = 0; i < player_count - 1; i++) {
        for (int j = 0; j < player_count - i - 1; j++) {
            if (leaderboard[j].score < leaderboard[j + 1].score) {
                struct Player temp = leaderboard[j];
                leaderboard[j] = leaderboard[j + 1];
                leaderboard[j + 1] = temp;
            }
        }
    }
}

void add_score(char name[], int score) {
    for (int i = 0; i < player_count; i++) {
        if (strcmp(leaderboard[i].name, name) == 0) {
            if (score > leaderboard[i].score) {
                leaderboard[i].score = score; 
                sort_leaderboard();
            }
            return; 
        }
    }

    if (player_count >= MAX_PLAYERS) {
        printf("Leaderboard is full! Cannot add more players.\n");
        return;
    }

    strcpy(leaderboard[player_count].name, name);
    leaderboard[player_count].score = score;
    player_count++;
    
    sort_leaderboard();
}

void display_leaderboard() {
    printf("\nLeaderboard:\n");
    printf("----------------------\n");
    for (int i = 0; i < player_count; i++) {
        printf("%d. %s - %d\n", i + 1, leaderboard[i].name, leaderboard[i].score);
    }
    printf("----------------------\n");
}

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
