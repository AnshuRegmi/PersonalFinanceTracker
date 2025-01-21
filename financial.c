#include <stdio.h>
#include <string.h>
#include "financial.h"

#define MAX_RECORDS 100 // yo bhaneko total 100 wata samma record halna milcha

FinancialRecord records[MAX_RECORDS]; // yo chai hamro array ho record store garne
int recordCount = 0; // yesle financial records haru count garcha

// yo chai records save garna ko lagi function ho
void saveRecordsToFile() {
    FILE *file = fopen("financial_records.txt", "w"); // file open gareko write mode ma
    if (file == NULL) { // file na khuleko case ma
        printf("Error: Could not open file to save records.\n");
        return;
    }

    for (int i = 0; i < recordCount; i++) {
        fprintf(file, "%d;%s;%d\n", records[i].id, records[i].description, records[i].amount);
        // har ek record file ma write garcha
    }

    fclose(file); // file close garne
}

// yo chai records load garna ko lagi function ho
void loadRecordsFromFile() {
    FILE *file = fopen("financial_records.txt", "r"); // file open gareko read mode ma
    if (file == NULL) { // file exist nagareko case ma
        printf("No previous records found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "%d;%99[^;];%d\n", &records[recordCount].id, records[recordCount].description, &records[recordCount].amount) == 3) {
        // file bata record read garcha
        currentExpenditure += records[recordCount].amount; // expenses update garcha
        recordCount++; // record count increase garcha
    }

    fclose(file); // file close garne
}

// yo chai fiancial record add garna ko lagi banayeko function ho
int addFinancialRecord() {
    if (recordCount >= MAX_RECORDS) {
        printf("Record limit reached, you cannot add more records.\n");
        return 0;
    }

    FinancialRecord newRecord;
    newRecord.id = recordCount + 1; // +1 halyo bhane aafai atto increase hunchaa 
    printf("Enter description of your expense: ");
    fgets(newRecord.description, sizeof(newRecord.description), stdin);
    newRecord.description[strcspn(newRecord.description, "\n")] = '\0';
    printf("Enter amount you have spent: ");
    scanf("%d", &newRecord.amount);
    getchar(); // yesle newline character clear garcha jun baki input huncha tyo clear garcha

    records[recordCount++] = newRecord; // yesle array ko lago record add garcha
    currentExpenditure += newRecord.amount; // Yesle expenses chai add garcha matlab update garcha
    printf("Record added successfully!\n");

    saveRecordsToFile(); // record file ma save garcha
    return 1;
}

// yo function le chai sabai fiancial record display garcha
void displayFinancialRecords() {
    if (recordCount == 0) {
        printf("There are no financial records to display.\n");
        return;
    }

    printf("\nFinancial Records:\n");
    printf("ID\tDescription\t\tAmount\n");
    for (int i = 0; i < recordCount; i++) {
        printf("%d\t%s\t\t%d\n", records[i].id, records[i].description, records[i].amount);
    }
}

// Yo function chai fiancial record delete garna lagi banayeko ho
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

    currentExpenditure -= records[index].amount; // yesle chai expenditure lai adjust garcha

    for (int i = index; i < recordCount - 1; i++) {
        records[i] = records[i + 1]; // yesle records haru shift garcha
    }
    recordCount--;
    printf("Record deleted successfully.\n");

    saveRecordsToFile(); // record file ma save garcha after deletion
}

// yo function le chai budget check garcha
void checkBudget() {
    if (currentExpenditure > monthlyBudget) {
        printf("STOPPP! You have exceeded your monthly budget of %d!\n", monthlyBudget);
    } else {
        printf("You are within your budget. Remaining: %d\n", monthlyBudget - currentExpenditure);
    }
}
