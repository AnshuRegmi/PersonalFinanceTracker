#include <stdio.h>
#include <string.h>
#include "financial.h"

#define MAX_RECORDS 100 // yo bhaneko total 100 wata samma record halna milcha

FinancialRecord records[MAX_RECORDS]; // yo chai hamro array ho record store garne
int recordCount = 0; // yesle financial records haru count garcha

// yo chai fiancial record add garna ko lagi banayeko function ho
int addFinancialRecord() {
    if (recordCount >= MAX_RECORDS) {
        printf("Record limit reached, you cannot add more records.\n");
        return 0;
    }

    FinancialRecord newRecord;
    newRecord.id = recordCount + 1; // +1 halyo bhane aafai atto increase hunchaa 
    // newRecord.id le chai automatically ID assign garcha based on the number of existing records.
    printf("Enter description of your expense: ");
    fgets(newRecord.description, sizeof(newRecord.description), stdin);
    newRecord.description[strcspn(newRecord.description, "\n")] = '\0';
     // yesko kaam chai newline remove garne ho
     // strcspn removes the newline character (\n) that fgets includes.
    printf("Enter amount you have spent: ");
    scanf("%d", &newRecord.amount);
    getchar(); // yesle newline character clear garcha jun jun baki input huncha tyo clear garcha

    records[recordCount++] = newRecord; // yesle array ko lago record add garcha
    currentExpenditure += newRecord.amount; // Yesle expenses chai add garcha matlab update garcha
    printf("Record added successfully!\n");
    return 1;
}

// yo function le chai sabai fianacial record dispaly garcha
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

// Yo function chai fiancial record delete garna  lagi banayeko ho
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
}

// yo function le chai budget check garcha kimdof notification
void checkBudget() {
    if (currentExpenditure > monthlyBudget) {
        printf("Warning: You have exceeded your monthly budget of %d!\n", monthlyBudget);
    } else {
        printf("You are within your budget. Remaining: %d\n", monthlyBudget - currentExpenditure);
    }
}