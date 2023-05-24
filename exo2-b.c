#include <stdio.h>
#include <stdlib.h>

#define MAX_COMPUTERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int stock;
    float price;
} Computer;

typedef enum {
    CPU,
    GPU,
    RAM,
    HDD,
    SSD
} Component;

Computer computers[MAX_COMPUTERS];
int numComputers = 0;

void addComputer() {
    if (numComputers >= MAX_COMPUTERS) {
        printf("Erreur : le nombre maximum d'ordinateurs est atteint.\n");
        return;
    }

    Computer computer;

    printf("ID de l'ordinateur : ");
    scanf("%d", &computer.id);

    printf("Nom de l'ordinateur : ");
    scanf("%s", computer.name);

    printf("Stock de l'ordinateur : ");
    scanf("%d", &computer.stock);

    printf("Prix de l'ordinateur : ");
    scanf("%f", &computer.price);

    computers[numComputers] = computer;
    numComputers++;

    printf("L'ordinateur a été ajouté avec succès.\n");
}

void displayComputerDetails(int computerId) {
    for (int i = 0; i < numComputers; i++) {
        if (computers[i].id == computerId) {
            printf("Détails de l'ordinateur (ID : %d)\n", computers[i].id);
            printf("Nom : %s\n", computers[i].name);
            printf("Stock : %d\n", computers[i].stock);
            printf("Prix : %.2f euros\n", computers[i].price);
            return;
        }
    }

    printf("Aucun ordinateur avec l'ID %d n'a été trouvé.\n", computerId);
}

void updateStock(int computerId, int newStock) {
    for (int i = 0; i < numComputers; i++) {
        if (computers[i].id == computerId) {
            computers[i].stock = newStock;
            printf("Le stock de l'ordinateur a été mis à jour.\n");
            return;
        }
    }

    printf("Aucun ordinateur avec l'ID %d n'a été trouvé.\n", computerId);
}

int main() {
    int choice;

    while (1) {
        printf("\nGestion de la boutique d'informatique\n");
        printf("1. Ajouter un nouvel ordinateur\n");
        printf("2. Consulter les détails d'un ordinateur\n");
        printf("3. Mettre à jour le stock d'un ordinateur\n");
        printf("4. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addComputer();
                break;
            case 2: {
                int computerId;
                printf("ID de l'ordinateur : ");
                scanf("%d", &computerId);
                displayComputerDetails(computerId);
                break;
            }
            case 3: {
                int computerId, newStock;
                printf("ID de l'ordinateur : ");
                scanf("%d", &computerId);
                printf("Nouveau stock : ");
                scanf("%d", &newStock);
                updateStock(computerId, newStock);
                break;
            }
            case 4:
                exit(0);
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    }

    return 0;
}
