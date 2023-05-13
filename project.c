#include <stdio.h>
#include <stdlib.h>

// Define a struct for student data
struct Student {
    char name[50];
    int roll_number;
    float marks;
    char grade;
};

// Function to calculate grade based on marks
char calculate_grade(float marks) {
    if (marks >= 90) {
        return 'A';
    } else if (marks >= 80) {
        return 'B';
    } else if (marks >= 70) {
        return 'C';
    } else if (marks >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    // Declare variables
    int num_students;
    struct Student *students;

    // Prompt the user to enter the number of students
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // Allocate memory for the students array
    students = (struct Student*) malloc(num_students * sizeof(struct Student));

    // Loop through each student and get their data
    for (int i = 0; i < num_students; i++) {
        printf("Enter the name of student %d : \n", i+1);
        scanf("%s", students[i].name);

        printf("\n Enter the roll number of student %d: ", i+1);
        scanf("%d", &students[i].roll_number);

        printf("\nEnter the marks of student %d: ", i+1);
        scanf("%f", &students[i].marks);

        // Calculate grade based on marks
        students[i].grade = calculate_grade(students[i].marks);
    }

    // Print out the student data
    printf("\nStudent Data:\n");
    printf("------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s |\n", "Name", "Roll No.", "Grade");
    printf("------------------------------------------------\n");
    for (int i = 0; i < num_students; i++) {
        printf("| %-20s | %-10d | %-10c |\n", students[i].name, students[i].roll_number, students[i].grade);
    }
    printf("------------------------------------------------\n");

    // Free memory allocated for the students array
    free(students);

    return 0;
}
