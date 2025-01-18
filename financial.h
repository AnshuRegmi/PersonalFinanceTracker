
#ifndef FINANCIAL_H
#define FINANCIAL_H
// These lines prevent the header file from being included multiple times by mistake. #ifndef checks if FINANCIAL_H is not defined, and if it isn’t, it defines it. 

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