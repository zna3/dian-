#include <stdio.h>
#include <string.h>

int main() {
    char input[100], line[100];
    FILE *file = fopen("data.txt", "r");
    
    while (1) {
        printf("请输入: ");
        scanf("%s", input);
        if (strcmp(input, "Quit") == 0) break;
        
        fseek(file, 0, SEEK_SET);
        int found = 0;
        
        while (fgets(line, 100, file)) {
            char *colon = strchr(line, ':');
            if (colon) {
                *colon = '\0';
                if (strcmp(input, line) == 0) {
                    printf("%s\n", colon + 1);
                    found = 1;
                    break;
                }
            }
        }
        
        if (!found) printf("Error\n");
    }
    
    fclose(file);
    return 0;
}