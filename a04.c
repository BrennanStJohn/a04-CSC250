#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getNames(int n, FILE *inGrades, char arr[][10]);
void getGrades(int numStudent, int numAssign, FILE *inGrades, int arar1[][numStudent], char arr[][10]);
void average(int numAssign, int numStudent, int arr4[numAssign][numStudent], char sumArr[numStudent]);
void finalGrades(int numStudent, int numAssign,int grades[][numStudent], char names[][10]);

int main(int argc, char *argv[]) {

	if (argc != 2) {
		
		printf("\n\tUsage: '%s filename'\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	FILE *inGrades;
	
	inGrades = fopen(argv[1], "r");

	int numStudent = 0;
	int numAssign = 0;
	
	puts(" ---------------- ");
	puts("|                |");
	puts("| Grade Checker  |");
	puts("|     v1.1       |");
	puts("|                |");
	puts(" ---------------- ");
	
	puts("");
	
	//printf("%s", "How many students? ");
	fscanf(inGrades, "%d", &numStudent);
	
	char names[numStudent][10];
	
	//printf("%s", "How many assignments? ");
	fscanf(inGrades, "%d", &numAssign);
	
	if (inGrades == NULL) {
		
		printf("The file could not be opened.\n");
		exit(EXIT_FAILURE);
	}
	
	int grade[numAssign][numStudent];
	
	getNames(numStudent, inGrades, names); 
	
	getGrades(numStudent, numAssign, inGrades, grade, names);
	
	finalGrades(numStudent, numAssign, grade, names);
	
	char sumArr[numStudent];
	
	average(numAssign, numStudent, grade, sumArr);
	
	fclose(inGrades);
	
}

void getNames(int numStudent, FILE *inGrades, char arr[numStudent][10]) {
	
	int i;
	
	for (i = 0; i < numStudent; i++) {
		//printf("Enter the name for Student %d: ", i);
		fscanf(inGrades, "%s", &arr[i]);
		
	}
	
}

void getGrades(int numStudent, int numAssign, FILE *inGrades, int arr1[numAssign][numStudent], char arr2[numStudent][10]) {
	
	int i;
	int j;
	
	
	for (i = 0; i < numAssign; i++) {
		
		for (j = 0; j < numStudent; j++) {
			
			//printf("Enter grade for Assignment %d for %s: ", i, arr2[j]);
			fscanf(inGrades, "%d", &arr1[i][j]);
			
			
		}
	}
	
}

void average(int numAssign, int numStudent, int arr3[numAssign][numStudent], char sumArr[numStudent]) {
	
	int i = 0;
	int j = 0;
	int sum = 0;
	int avg = 0;
	
	for ( j = 0; j < numStudent; j++){
		sum = 0;
		avg = 0;
		for (i = 0; i < numAssign; i++) {
	
			sum = arr3[i][j] + sum;
		
		}
		
		avg = sum/numAssign;
		
		if (avg >=90) {
			sumArr[i] = 'A';
		}
		else if (avg >= 80) {
			sumArr[i] = 'B';
		}
		else if (avg >= 70) {
			sumArr[i] = 'C';
		}
		else if (avg >= 60) {
			sumArr[i] = 'D';
		}
		else if (avg >= 50) {
			sumArr[i] = 'F';
		}
		printf("%10c ", sumArr[i]);
	}

	
}

void finalGrades(int numStudent, int numAssign, int arr4[numAssign][numStudent], char arr5[numStudent][10]) {
	
	int i;
	int j;
	int x;
	
	for (i = 0; i < numStudent; i++) {
		
		printf("%10s ", arr5[i]);
	} 
	
	puts("");
	
	for (j = 0; j < numAssign; j++) {
		
		for (x = 0; x < numStudent; x++) {
			
			printf("%10d ", arr4[j][x]);

		}
		puts("");

	}
}