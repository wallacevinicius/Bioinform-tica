#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#define MAX_NUMBER 1000

int stop(){
    return 0;
}

void askMenu(){
    int op;

    printf("\nType your option: ");
    scanf("%d%*c", &op);

    switch(op){
        case 1:
            countDNA();
        case 2:
            becomeRNA();
        default:
            system("cls");
            system("clear");
            printf("OPÇÃO INVÁLIDA\n\n");
            menu();
    }
}

void menu(){
    printf("1. Count DNA\n"
            "2. Become RNA\n");
    askMenu();
}

void countDNA(){
    int i, count[4] = {0};
    char dna[MAX_NUMBER];
    char yn;

    system("cls");
    system("clear");

    printf("Type your DNA strand: ");
    fgets(dna, MAX_NUMBER, stdin);
    for(i = 0; i < strlen(dna)-1; i++){
        if(dna[i] == '\n')
            dna[i] == '\0';
    }

    for(i = 0; dna[i]; i++){
        dna[i] = toupper(dna[i]);
    }

    for(i = 0; dna[i]; i++){
        if(dna[i] ==  'A')
            count[0]++;
        else if(dna[i] == 'T')
            count[1]++;
        else if(dna[i] == 'C')
            count[2]++;
        else if(dna[i] == 'G')
            count[3]++;
    }

    printf("A = %d\n"
            "C = %d\n"
            "G = %d\n"
            "T = %d\n", count[0], count[2], count[3], count[1]);

    printf("\nDo you want to go back to menu? (y/n):");
    scanf("%c%*c", &yn);
    if(yn == 'y' || yn == 'Y'){
        system("cls");
        system("clear");
        menu();
    }else if(yn == 'n' || yn == 'N')
        stop();
}

void becomeRNA(){
    int i;
    char rna[MAX_NUMBER];
    char yn;

    system("cls");
    system("clear");

    printf("Type your DNA strand: ");
    fgets(rna, MAX_NUMBER, stdin);
    for(i = 0; rna[i]; i++){
        if(rna[i] == '\n')
            rna[i] == '\0';
    }

    for(i = 0; rna[i]; i++){
        rna[i] = toupper(rna[i]);
    }

    for(i = 0; rna[i]; i++){
        if(rna[i] == 'T')
            rna[i] = 'U';
    }

    printf("%s\n", rna);

    printf("Do you want to go back to menu? (y/n):");
    scanf("%c%*c", &yn);
    if(yn == 'y' || yn == 'Y'){
        system("cls");
        system("clear");
        menu();
    }else if(yn == 'n' || yn == 'N')
        stop();
}

int main(){
    menu();

    return 0;
}
