#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool prefix_matches_string(char prefix[], char string[])
{
    for (int i = 0; i < strlen(prefix); i++) {
        if (string[i] != prefix[i]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    char entered_address[100];
    if (argc > 1) {
        strcpy(entered_address, argv[1]);
    }
    int address_count = 0;
    char address_list[42][100];

    while (scanf("%99s", address_list[address_count]) != EOF) { // getting list of adresses
        address_count++;
        if (address_count == 42) {
            break;
        }
    }
    for (int i = 0; i < address_count; i++) {
        printf("%s\n", address_list[i]);
        if (strcmp(entered_address, address_list[i]) == 0) {
            printf("Found : %s", entered_address);
        }
    }

    char possible_addresses[42][100];
    int possible_address_count = 0;
    char enabled_letters[30];
    int enabled_letters_count = 0;

    for (int i = 0; i < address_count; i++) {
        if (prefix_matches_string(entered_address, address_list[i])) {
            strcpy(possible_addresses[possible_address_count], address_list[i]);
            possible_address_count++;

            char next_letter = address_list[i][strlen(entered_address)];
            if(strchr(enabled_letters, next_letter) == NULL){
                enabled_letters[enabled_letters_count] = next_letter;
                enabled_letters_count++;
            }
        }
    }

    printf("enables : %s", enabled_letters);
    return 0;
}
