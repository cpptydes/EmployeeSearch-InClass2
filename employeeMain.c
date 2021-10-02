//Compile using the follwing command:   gcc employeeMain.c employeeTable.c employeeOne.c
// gcc employeeMain.c employeeTable.c employeeTwo.c

#include <string.h>
#include <stdlib.h>
#include "employee.h"
int main(void){
    //defined in employeeOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int tableSize, char * targetPhone);
    PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary);

    //defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; //Declaration

    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "213-555-1211"); //not found
    if (matchPtr != NULL)
        printf("Employee PHONE 213-555-1211 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee PHONE 213-555-1211 is NOT found in the record\n");

    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "213-555-1212"); //found
    if (matchPtr != NULL)
        printf("Employee PHONE 213-555-1212 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee PHONE 213-555-1212 is NOT found in the record\n");

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 7.81); //not found
    if (matchPtr != NULL)
        printf("Employee SALARY 7.81 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee SALARY 7.81 is NOT found in the record\n");

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 7.80); //not found
    if (matchPtr != NULL)
        printf("Employee SALARY 7.80 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee SALARY 7.80 is NOT found in the record\n");
        
    return EXIT_SUCCESS;
}