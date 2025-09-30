#include <stdio.h>
#include <string.h>

int seats[5][7][4][4] = {0};  

int main() {
    char command[100];
    char day[20];
    int floor, row, col;
    
    printf("Login: ");
    scanf("%s", command);
    printf("Login OK\n");
    
    while (1) {
        printf("> ");
        scanf(" %[^\n]", command);
        
        if (strcmp(command, "exit") == 0) {
            break;
        }
        else if (strcmp(command, "Reservation") == 0) {
            
            for (int f = 0; f < 5; f++) {
                for (int d = 0; d < 7; d++) {
                    for (int r = 0; r < 4; r++) {
                        for (int c = 0; c < 4; c++) {
                            if (seats[f][d][r][c] == 1) {
                                printf("Floor %d Seat %d %d\n", f+1, r+1, c+1);
                            }
                        }
                    }
                }
            }
        }
        else if (scanf(command, "Reserve %s Floor %d Seat %d %d", day, &floor, &row, &col) == 4) {
        
            if (seats[floor-1][0][row-1][col-1] == 0) {
                seats[floor-1][0][row-1][col-1] = 1;
                printf("OK\n");
            } else {
                printf("Seat taken\n");
            }
        }
        else if (sscanf(command, "%s Floor %d", day, &floor) == 2) {
          
            for (int r = 0; r < 4; r++) {
                for (int c = 0; c < 4; c++) {
                    printf("%d", seats[floor-1][0][r][c]);
                }
                printf("\n");
            }
        }
        else {
            printf("Error\n");
        }
    }
    
    return 0;
}
