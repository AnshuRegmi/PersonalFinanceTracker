#include <stdio.h>
#include "financial.h"


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
               setMonthlyTarget();
               break;
           case 2:
               addFinancialRecord();
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



