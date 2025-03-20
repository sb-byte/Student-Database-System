#include <stdio.h>

// Define structure for student
typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

// Function prototypes
void addStudent(Student students[], int *count);
void displayStudents(Student students[], int count);
void searchStudent(Student students[], int count);
void updateGPA(Student students[], int count);
void deleteStudent(Student students[], int *count);

int main() {
    Student students[100]; // Fixed-size array
    int count = 0;
    int choice;

    do {
        printf("\nStudent Database System\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Update Student GPA\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                updateGPA(students, count);
                break;
            case 5:
                deleteStudent(students, &count);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to add a student
void addStudent(Student students[], int *count) {
    printf("Enter Student ID: ");
    scanf("%d", &students[*count].id);
    getchar(); // Consume newline character
    printf("Enter Name: ");
    fgets(students[*count].name, sizeof(students[*count].name), stdin);
    printf("Enter Age: ");
    scanf("%d", &students[*count].age);
    printf("Enter GPA: ");
    scanf("%f", &students[*count].gpa);
    (*count)++;
    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents(Student students[], int count) {
    if (count == 0) {
        printf("No students in the database.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("\nStudent ID: %d\n", students[i].id);
        printf("Name: %s", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("GPA: %.2f\n", students[i].gpa);
    }
}

// Function to search for a student by ID
void searchStudent(Student students[], int count) {
    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("\nStudent ID: %d\n", students[i].id);
            printf("Name: %s", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("GPA: %.2f\n", students[i].gpa);
            return;
        }
    }
    printf("Student not found!\n");
}

// Function to update a student's GPA
void updateGPA(Student students[], int count) {
    int id;
    printf("Enter Student ID to update GPA: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Enter new GPA: ");
            scanf("%f", &students[i].gpa);
            printf("GPA updated successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

// Function to delete a student
void deleteStudent(Student students[], int *count) {
    int id, index = -1;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Student not found!\n");
        return;
    }
    
    for (int i = index; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }

    (*count)--;
    printf("Student deleted successfully!\n");
}
