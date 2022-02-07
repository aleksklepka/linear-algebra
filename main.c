#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MATRIX_MENU_EXIT_CODE 5

typedef struct _matrix { //node
	unsigned rows;
	unsigned cols;
	char name;  // A-Z
	double* arr;
	struct matrix *next;
} matrix;

typedef struct _matrixList {
	matrix* head;
	struct _matrixList* next;
} matrixList;

void mainMenu(void);
void printMenu(void);
void matrixMenu(void);
void printMatrixMenu(void);
matrix createMatrix(void);
void printMatrix(matrix *m);
void deleteMatrix(matrix *m);
int readOptions(void);
//void addMatrix2List(void);

int main(void) {
	mainMenu();
	return 0;
}

void mainMenu() {
	system("cls");
	printMenu();
	int userChoice = readOptions();
	while(userChoice != 10){
        switch (userChoice) {
        case 1:
            printf("This chapter is too complex! Come back later!\n");
            break;
        case 9:
            matrixMenu();
            printMenu();
            break;
        default:
            printf("No such option exists!");
            break;
        }
        userChoice = readOptions();
	}
	return;
}

void printMenu(void) {
	printf("Welcome to the Linear Algebra App!\n");
	printf("Please choose an option (1-10) to proceed:\n");
	printf("1) Complex Numbers\n");
	printf("9) Matrix\n");
	printf("10) Exit the program \n");
	return;
}

void printMatrixMenu(void) {
	printf("| Matrix Menu |\n");
	printf("1) Add Matrix\n");
	printf("2) Delete Matrix\n");
	printf("3) Print Matrix\n");
	printf("4) Print Matrix Menu\n");
	printf("5) Return to Main Menu\n");
}

int readOptions() {
	unsigned option = 0;
	char buff[21];
	do {
		printf("Option: ");
		fgets(buff, 20, stdin);
	} while (sscanf(buff, "%u ", &option) != 1);
	return option;
}

void matrixMenu() {
	system("cls");
	printMatrixMenu();
	int matrixOption = 0;
	matrix mainMatrix;
	while(matrixOption != MATRIX_MENU_EXIT_CODE){
        matrixOption = readOptions();
        switch (matrixOption) {
            case 1:
                mainMatrix = createMatrix();
                printf("Matrix created successfully \n");
                break;
            case 2:
                deleteMatrix(&mainMatrix);
                printf("Matrix deleted \n");
                break;
            case 3:
                printMatrix(&mainMatrix);
                break;
            case 4:
                printMatrixMenu();
                break;
            case MATRIX_MENU_EXIT_CODE:
                printf("Returning to main menu\n\n");
                break;
            default: // help
                break;
        }
	}
}

// add matrix - size, values, allocate memory
// delete matrix - free memory
// print matrix - for loop
// print marix list (A-Z, 26 total)
// matrix operations
// return to main menu
// help

matrix createMatrix(void) {
	matrix* tmp = (matrix*)malloc(sizeof(matrix));
	unsigned r, c;
	char buff[21];
	r = c = 0;
	if (tmp) {
		do {
			printf("Rows: ");
			fgets(buff, 20, stdin);
		} while (sscanf(buff, "%u ", &r) != 1);
		do {
			printf("Columns: ");
			fgets(buff, 20, stdin);
		} while (sscanf(buff, "%u ", &c) != 1);
		if (!tmp) {
			return;
		}
		tmp->rows = r;
		tmp->cols = c;
		tmp->arr = calloc(r * c, sizeof(double));
		printf("Enter the matrix values (by rows):\n");
		for (int i = 0; i < r * c; i++) {
			scanf("%lf", &tmp->arr[i]);
		}
		for (int i = 0; i < r * c; i++) {
			printf("%5.2lf ", tmp->arr[i]);
			if ((i+1) % c == 0)
				printf("\n");
		}
	}
	return *tmp;
}

void printMatrix(matrix* m) {
    printf("Matrix name: %s\n", m->name == NULL ? "(Not set)" : m->name);
    printf("Matrix size: %d X %d\n\n", m->rows, m->cols);
    int currentPos = 0;
    while(currentPos < m->rows*m->cols){
        printf("%5.2lf ", m->arr[currentPos]);
        if((currentPos+1) % m->rows == 0 && currentPos != 0) printf("\n");
        currentPos++;
    }
    printf("\n");
}

void deleteMatrix(matrix *m){
    m->next = NULL;
    free(m->name);
    free(m->arr);
    free(m);
}


//void addMatrix2List(matrixList) {
//	if (matrixList == NULL) {
//		matrixList->head = martix;
//		matrix->name = 'A';
//		matrix->next = NULL;
//		return;
//	}
//	matrix* tmp = matrixList->head;
//	if (temp != NULL) {
//		t
//	}
//}
