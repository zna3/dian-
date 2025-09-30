#include <stdio.h>
#include <string.h>

#define FLOORS 5
#define DAYS 7
#define ROWS 4
#define COLS 4

const char *dayNames[] = {
    "Monday", "Tuesday", "Wednesday", "Thursday", 
    "Friday", "Saturday", "Sunday"
};

int seats[FLOORS][DAYS][ROWS][COLS] = {0};

char currentUser[20] = "";


int findDayIndex(const char *dayStr) {
    for (int i = 0; i < 7; i++) {
        if (strcmp(dayStr, dayNames[i]) == 0)
            return i;
    }
    return -1;
}

void showFloor(int dayIndex, int floor) {
    printf("%s Floor %d:\n", dayNames[dayIndex], floor);
    
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("%d", seats[floor-1][dayIndex][r][c]);
        }
        printf("\n");
    }
}

void reserveSeat(int dayIndex, int floor, int row, int col) {
   
    if (seats[floor-1][dayIndex][row-1][col-1] == 1) {
        printf("Seat already taken\n");
        return;
    }
    
    
    seats[floor-1][dayIndex][row-1][col-1] = 1;
    printf("OK\n");
}


void showReservations() {
    printf("All reservations:\n");
    int found = 0;
    
    for (int f = 0; f < FLOORS; f++) {
        for (int d = 0; d < DAYS; d++) {
            for (int r = 0; r < ROWS; r++) {
                for (int c = 0; c < COLS; c++) {
                    if (seats[f][d][r][c] == 1) {
                        printf("%s Floor %d Seat %d %d\n", 
                               dayNames[d], f+1, r+1, c+1);
                        found = 1;
                    }
                }
            }
        }
    }
    
    if (!found) {
        printf("No reservations\n");
    }
}

int main() {
    printf("=== Library System ===\n");
    
    printf("Enter username: ");
    scanf("%s", currentUser);
    printf("Login successful as %s\n", currentUser);
    
    char command[100];
    
    while (1) {
        printf("\nCommands:\n");
        printf("1. Monday Floor 1 (show seats)\n");
        printf("2. Reserve Monday Floor 1 Seat 1 1 (reserve seat)\n");
        printf("3. Reservation (show all reservations)\n");
        printf("4. exit (quit program)\n");
        printf("Enter command: ");
        
        scanf(" %[^\n]", command);
        
        if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else if (strcmp(command, "Reservation") == 0) {
            showReservations();
        }
        else if (strncmp(command, "Reserve ", 8) == 0) {
            char dayStr[20];
            int floor, row, col;
            
            if (sscanf(command, "Reserve %s Floor %d Seat %d %d", 
                       dayStr, &floor, &row, &col) == 4) {
                int dayIndex = findDayIndex(dayStr);
                if (dayIndex == -1) {
                    printf("Invalid day\n");
                } else if (floor < 1 || floor > 5) {
                    printf("Floor must be 1-5\n");
                } else if (row < 1 || row > 4 || col < 1 || col > 4) {
                    printf("Seat must be 1-4\n");
                } else {
                    reserveSeat(dayIndex, floor, row, col);
                }
            } else {
                printf("Usage: Reserve Monday Floor 1 Seat 1 1\n");
            }
        }
        else {
            
            char dayStr[20];
            int floor;
            
            if (sscanf(command, "%s Floor %d", dayStr, &floor) == 2) {
                int dayIndex = findDayIndex(dayStr);
                if (dayIndex == -1) {
                    printf("Invalid day\n");
                } else if (floor < 1 || floor > 5) {
                    printf("Floor must be 1-5\n");
                } else {
                    showFloor(dayIndex, floor);
                }
            } else {
                printf("Unknown command\n");
            }
        }
    }
    
    return 0;
}