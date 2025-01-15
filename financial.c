#ifndef FINANCIAL_H
#define FINANCIAL_H

#include <stdbool.h>

typedef struct {
    int id;
    int amount;
    char description[100];
} FinancialRecord;

void checkBudget();
bool addFinancialRecord();
void displayFinancialRecords();
void deleteFinancialRecord(int id);

#endif
