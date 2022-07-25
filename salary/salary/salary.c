#include <stdio.h>

int callPersonSalary(int person, char organ[][6], int salary[]) {
	int i;
	int sum = 0;

	if (strcmp(organ[person], "NNNNN") == 0) {
		salary[person] = 1;
		return 1;
	}
	else {
		for (i = 0; i < 5; i++) {
			if (organ[person][i] == 'Y') {
				if (salary[i] == 0)
					salary[i] += callPersonSalary(i, organ, salary);

				sum += salary[i];
			}
		}
	}

	return sum;
}

int callPersonSalary2(int person, char organ[][6], int salary[]) {
	int i;
	int sum = 0;

	if (salary[person] != 0) {
		return salary[person];
	}

	if (strcmp(organ[person], "NNNNN") == 0) {
		salary[person] = 1;
		return 1;
	}
	else {
		for (i = 0; i < 5; i++) {
			if (organ[person][i] == 'Y') {
				sum += callPersonSalary(i, organ, salary);
			}
		}
	}

	salary[person] = sum;
	return sum;
}

void printSalary(int salary[], int size) {
	int i;

	for (i = 0; i < 5; i++)
		printf("%d ", salary[i]);

	printf("\n");
}

int main(void) {

	char organization[][6] = {
		"NYYNN",
		"NNNNN",
		"NNNYY",
		"NYNNN",
		"NNNNN"
	};

	/*
	char organization[][6] = {
		"NNNNN",
		"YNYYN",
		"YNNNY",
		"NNNNY",
		"NNNNN"
	};
	*/
	/*
	char organization[][6] = {
		"NNNNN",
		"YNYNN",
		"NNNYN",
		"NNNNN",
		"NYNYN"
	};
	*/

	int salary[5] = { 0 };
	int i;

	for (i = 0; i < 5; i++)
		salary[i] = callPersonSalary2(i, organization, salary);

	printSalary(salary, 5);
}