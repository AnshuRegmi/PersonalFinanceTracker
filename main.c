#include <stdio.h>
#include "financial.h"

int monthlyBudget = 0;  // Global variable to store the monthly budget
int currentExpenditure = 0;  // Global variable to track current expenditure

int main() {
    int choice;
    do {
        printf("\nPersonal Finance Tracker\n");
        printf("1. Set Monthly Expenditure Target\n");
        printf("2. Add Financial Record\n");
        printf("3. Display Financial Records\n");
        printf("4. Delete Financial Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character

        switch(choice) {
            case 1:
                printf("Enter new monthly budget: ");
                scanf("%d", &monthlyBudget);
                getchar();
                break;
            case 2:
                if(addFinancialRecord()) {
                    checkBudget();
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}
