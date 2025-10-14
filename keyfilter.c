#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool prefix_matches_string(char prefix[], char string[])
{
    size_t n = strlen(prefix); // using size_t because otherwise it gives an error when compared to strlen
    for (size_t i = 0; i < n; i++) {
        if (string[i] != prefix[i]) {
            return false;
        }
    }
    return true;
}

void uppercase(char *str)
{
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        str[i] = toupper(str[i]);
    }
}

void lowercase(char *str)
{
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        str[i] = tolower(str[i]);
    }
}

void sort_alphabetically(char *str)
{
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    char entered_address[101];
    if (argc > 1) { // read entered address
        strcpy(entered_address, argv[1]);
        lowercase(entered_address);
    } else {
        strcpy(entered_address, "");
    }
    int address_count = 0;
    char address_list[43][101];
    bool address_found = false;

    while (scanf("%99s", address_list[address_count]) != EOF) { // getting list of addresses
        lowercase(address_list[address_count]);
        address_count++;
        if (address_count == 43) {
            break;
        }
    }
    for (int i = 0; i < address_count; i++) { // check if entered address matches any addresses from the list
        if (strcmp(entered_address, address_list[i]) == 0) {
            uppercase(entered_address);
            printf("Found: %s\n", entered_address);
            address_found = true;
        }
    }

    char possible_addresses[50][101];
    int possible_address_count = 0;
    char enabled_letters[50];
    int enabled_letters_count = 0;

    for (int i = 0; i < address_count; i++) {
        if (prefix_matches_string(entered_address, address_list[i])) {
            strcpy(possible_addresses[possible_address_count], address_list[i]);
            possible_address_count++;

            char next_letter = address_list[i][strlen(entered_address)];
            if (strchr(enabled_letters, next_letter) == NULL) {
                enabled_letters[enabled_letters_count] = next_letter;
                enabled_letters_count++;
            }
        }
    }
    uppercase(enabled_letters);
    sort_alphabetically(enabled_letters);

    if (!address_found && enabled_letters_count == 0) {
        printf("Not found");
    } else if (possible_address_count == 1 && !address_found) {
        possible_addresses[0][0] = toupper(possible_addresses[0][0]);
        uppercase(possible_addresses[0]);
        printf("Found: %s", possible_addresses[0]);
    } else if (enabled_letters_count > 0) {
        printf("Enable: %s", enabled_letters);
    }
    return 0;
}
