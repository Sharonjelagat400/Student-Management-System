#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 10

struct Student {
    char id[MAX_ID_LENGTH];
    char name[MAX_NAME_LENGTH];
    int age;
    float gpa;
};

struct Student students[MAX_STUDENTS];
int numStudents = 0;

void addStudent(const char *id, const char *name, int age, float gpa) {
    if (numStudents < MAX_STUDENTS) {
        strcpy(students[numStudents].id, id);
        strcpy(students[numStudents].name, name);
        students[numStudents].age = age;
        students[numStudents].gpa = gpa;
        numStudents++;
        printf("Student added successfully!\n");
    } else {
        printf("Cannot add student. Student list is full.\n");
    }
}

void displayStudent(int index) {
    printf("Student Information:\n");
    printf("ID: %s\n", students[index].id);
    printf("Name: %s\n", students[index].name);
    printf("Age: %d\n", students[index].age);
    printf("GPA: %.2f\n", students[index].gpa);
}

int searchStudent(const char *id) {
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].id, id) == 0) {
            return i;
        }
    }
    return -1; // Student not found
}

void updateStudent(int index, const char *name, int age, float gpa) {
    strcpy(students[index].name, name);
    students[index].age = age;
    students[index].gpa = gpa;
    printf("Student information updated successfully!\n");
}

void deleteStudent(int index) {
    for (int i = index; i < numStudents - 1; i++) {
        strcpy(students[i].id, students[i + 1].id);
        strcpy(students[i].name, students[i + 1].name);
        students[i].age = students[i + 1].age;
        students[i].gpa = students[i + 1].gpa;
    }
    numStudents--;
    printf("Student deleted successfully!\n");
}

int main() {
    int choice;
    char id[MAX_ID_LENGTH];
    char name[MAX_NAME_LENGTH];
    int age;
    float gpa;
    int index;

    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Student Information\n");
        printf("3. Search Student\n");
        printf("4. Update Student Information\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student ID: ");
                scanf("%s", id);
                printf("Enter student name: ");
                scanf("%s", name);
                printf("Enter student age: ");
                scanf("%d", &age);
                printf("Enter student GPA: ");
                scanf("%f", &gpa);
                addStudent(id, name, age, gpa);
                break;
            case 2:
                printf("Enter student index: ");
                scanf("%d", &index);
                if (index >= 0 && index < numStudents) {
                    displayStudent(index);
                } else {
                    printf("Invalid student index.\n");
                }
                break;
            case 3:
                printf("Enter student ID to search: ");
                scanf("%s", id);
                index = searchStudent(id);
                if (index != -1) {
                    displayStudent(index);
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 4:
                printf("Enter student ID to update: ");
                scanf("%s", id);
                index = searchStudent(id);
                if (index != -1) {
                    printf("Enter updated student name: ");
                    scanf("%s", name);
                    printf("Enter updated student age: ");
                    scanf("%d", &age);
                    printf("Enter updated student GPA: ");
                    scanf("%f", &gpa);
                    updateStudent(index, name, age, gpa);
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 5:
                printf("Enter student ID to delete: ");
                scanf("%s", id);
                index = searchStudent(id);
                if (index != -1) {
                    deleteStudent(index);
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
