/******************************************************************************
Lab Work #2
Experiement 3
Section A, B, C, D, E
Utku Halis
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct persalary
{
	int month;
	long salary;
};

struct employee
{
	int empnr;
	char name[12];
	struct persalary salaries[3];
	long total;
	float average;
} empList[4];

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    count += last_comma < (a_str + strlen(a_str) - 1);
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

void calcAndDisp(){
    float average;
    int total, i, j;
    int sum;
    
    for (i = 0; i < 4; i++) {
        sum = 0;
        total = 0;
        
        for (j = 0; j < 3; j++) {
            sum += empList[i].salaries[j].salary;
            if(total < empList[i].salaries[j].salary){
                total = empList[i].salaries[j].salary;
            }
        }
        
        average = (float) sum / 3;
        empList[i].average = average;
        empList[i].total = total;
    }
    
    printf("Employee No\tName\tAverage\t\tTotal\n");
    for (i = 0; i < 4; i++) {
        printf("%d\t\t%s\t\%0.2f\t%li\n", empList[i].empnr, empList[i].name, empList[i].average, empList[i].total);
    }
    
}

void Disp(){
    int i;
    char *months[] = {
        "January",
        "February",
        "March    ",
        "April    ",
        "May     ",
        "June    ",
        "July    ",
        "August",
        "September",
        "October    ",
        "November",
        "December"
    };
    printf("Employee No\tName\tMonth\t\tSalary\n");
    for (i = 0; i < 4; i++) {
        printf("%d\t\t%s\t%s\t%li\n", empList[i].empnr, empList[i].name, months[empList[i].salaries[0].month-1], empList[i].salaries[0].salary);
        printf("\t\t\t%s\t%li\n", months[empList[i].salaries[1].month - 1], empList[i].salaries[1].salary);
        printf("\t\t\t%s\t%li\n", months[empList[i].salaries[2].month - 1], empList[i].salaries[2].salary);
    }
}

void rFile(){
    char text[100];
    FILE *file = fopen("emp.txt", "r");;
    int count = 0;
    char** tokens;
    if (file == NULL){
        printf("File reading error..");
        return;
    }

    while(fgets(text, 60, file)){
    	tokens = str_split(text, ' ');
    	
    	int empnr = atoi(*(tokens));
    	empList[count].empnr = empnr;
    	
    	strcpy(empList[count].name, *(tokens+1));
    	
    	int month0 = atoi(*(tokens+2));
    	empList[count].salaries[0].month = month0;
    	
    	int salary0 = atoi(*(tokens+3));
    	empList[count].salaries[0].salary = salary0;
    	
    	int month1 = atoi(*(tokens+4));
    	empList[count].salaries[1].month = month1;
    	
    	int salary1 = atoi(*(tokens+5));
    	empList[count].salaries[1].salary = salary1;
    	
    	int month2 = atoi(*(tokens+6));
    	empList[count].salaries[2].month = month2;
    	
    	int salary2 = atoi(*(tokens+7));
    	empList[count].salaries[2].salary = salary2;

        count++;
    }
    fclose(file);
}

int main()
{
    rFile();
	Disp();
	printf("\n\n");
 	calcAndDisp();
	
    return 0;
}
