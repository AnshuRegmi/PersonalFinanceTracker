// financial.h
#ifndef FINANCIAL_H
#define FINANCIAL_H

// Global variables
extern int monthlyBudget;
extern int currentExpenditure;

// Structure for financial records
typedef struct {
    int id;
    char description[100];
    int amount;
} FinancialRecord;

// Function prototypes
int addFinancialRecord();
void displayFinancialRecords();
void deleteFinancialRecord(int id);
void checkBudget();

#endif