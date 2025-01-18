// financial.c
#include <stdio.h>
#include <string.h>
#include "financial.h"

#define MAX_RECORDS 100 // Maximum number of financial records

FinancialRecord records[MAX_RECORDS]; // Array to store records
int recordCount = 0; // Count of financial records

// Function to add a financial record
int addFinancialRecord() {
    if (recordCount >= MAX_RECORDS) {
        printf("Record limit reached. Cannot add more records.\n");
        return 0;
    }

    FinancialRecord newRecord;
    newRecord.id = recordCount + 1; // Auto-increment ID
    printf("Enter description: ");
    fgets(newRecord.description, sizeof(newRecord.description), stdin);
    newRecord.description[strcspn(newRecord.description, "\n")] = '\0'; // Remove newline
    printf("Enter amount: ");
    scanf("%d", &newRecord.amount);
    getchar(); // Clear newline character

    records[recordCount++] = newRecord; // Add record to array
    currentExpenditure += newRecord.amount; // Update expenditure
    printf("Record added successfully!\n");
    return 1;
}

// Function to display all financial records
void displayFinancialRecords() {
    if (recordCount == 0) {
        printf("No financial records to display.\n");
        return;
    }

    printf("\nFinancial Records:\n");
    printf("ID\tDescription\t\tAmount\n");
    for (int i = 0; i < recordCount; i++) {
        printf("%d\t%s\t\t%d\n", records[i].id, records[i].description, records[i].amount);
    }
}

// Function to delete a financial record
void deleteFinancialRecord(int id) {
    int index = -1;
    for (int i = 0; i < recordCount; i++) {
        if (records[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Record not found.\n");
        return;
    }

    currentExpenditure -= records[index].amount; // Adjust expenditure

    for (int i = index; i < recordCount - 1; i++) {
        records[i] = records[i + 1]; // Shift records
    }
    recordCount--;
    printf("Record deleted successfully.\n");
}

// Function to check the budget
void checkBudget() {
    if (currentExpenditure > monthlyBudget) {
        printf("Warning: You have exceeded your monthly budget of %d!\n", monthlyBudget);
    } else {
        printf("You are within your budget. Remaining: %d\n", monthlyBudget - currentExpenditure);
    }
}