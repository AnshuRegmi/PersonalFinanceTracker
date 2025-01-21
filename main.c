#include <stdio.h>
#include "financial.h"

// aba chai global variables set gareko
int monthlyBudget = 0;
int currentExpenditure = 0;

int main() {
    int choice;

    loadRecordsFromFile(); // program suru hune bela records file bata load garcha

    do {
        printf("\nPersonal Finance Tracker\n");
        printf("1. Set Monthly Expenditure Target\n");
        printf("2. Add Financial Record\n");
        printf("3. Display Financial Records\n");
        printf("4. Delete Financial Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // sabai leftover input clear garcha

        switch (choice) {
            case 1:
                printf("Enter new monthly budget: ");
                scanf("%d", &monthlyBudget);
                getchar(); // Clear newline character
                printf("Monthly budget set to %d.\n", monthlyBudget);
                break;
            case 2:
                if (addFinancialRecord()) {
                    checkBudget(); // budget check garcha after adding a record
                }
                break;
            case 3:
                displayFinancialRecords();
                break;
            case 4:
                printf("Enter Record ID to Delete: ");
                int id;
                scanf("%d", &id);
                getchar(); 
                deleteFinancialRecord(id);
                break;
            case 5:
                printf("Exiting... Add after your new expense\n");
                break;
            default:
                printf("Invalid choice. Please try again.later\n");
        }
    } while (choice != 5);

    return 0;
}
