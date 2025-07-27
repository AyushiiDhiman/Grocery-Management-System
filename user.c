#include <stdio.h>
#include <string.h>

void registerUser() {
    char username[30], password[30];
    FILE *fp = fopen("users.txt", "a");
    printf("Enter new username: ");
    scanf("%s", username);
    printf("Enter new password: ");
    scanf("%s", password);
    fprintf(fp, "%s %s\n", username, password);
    fclose(fp);
    printf("Registration successful!\n");
}

int login() {
    char username[30], password[30], u[30], p[30];
    FILE *fp = fopen("users.txt", "r");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    while (fscanf(fp, "%s %s", u, p) != EOF) {
        if (strcmp(username, u) == 0 && strcmp(password, p) == 0) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
