#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool substring_matches_string(char substring[], char string[]){
    for (int i = 0; i < strlen(substring); i++) {
        if(string[i] != substring[i]){
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
        if(address_count == 42){
            break;
        }
    }
    for(int i = 0;i < address_count;i++){
        printf("%s\n", address_list[i]);
        if (strcmp(entered_address, address_list[i]) == 0) {
            printf("Found : %s", entered_address);
        }
    }

    for (int i = 0; i < address_count; i++) {
        if (substring_matches_string(entered_address, address_list[i])) {
            
        }
    }

    return 0;
}
