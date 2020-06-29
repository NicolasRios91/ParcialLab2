#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"


#include <string.h>

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

int employee_getMaxId(LinkedList* pArrayListEmployee,int* idNueva);


