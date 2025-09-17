#include <stdio.h>
struct Student {
 int roll;
 char name[50];
 float marks;};
struct Student A[100];
int n = 0;
void createStudent();
void displayStudent();
void editStudent();
void deleteStudent();
void searchStudent();
void sortStudent();
int main() {
 int choice;
 do {
printf("\n Student Database\n1.create\n2.display all\n3.edit student\n4.delete student\n5.search student\n6.sort by roll no.\n7.exit\n enter your choice :");

 scanf("%d", &choice);
 switch(choice) {
 case 1: createStudent();
 break;
 case 2: displayStudent();
 break;
 case 3: editStudent();
 break;
 case 4: deleteStudent();
 break;
 case 5: searchStudent();
 break;
 case 6: sortStudent();
 break;
 case 7: printf("Exiting\n");
 break;
 default:
 printf("Invalid choice!\n");
 }
 } while(choice != 7);
}
void createStudent() {
 printf("Enter Roll No: ");
 scanf("%d", &A[n].roll);
 printf("Enter Name: ");
 scanf("%s", A[n].name);
 printf("Enter Marks: ");
 scanf("%f", &A[n].marks);
 n++;
 printf("Student added successfully!\n");}
void displayStudent() {
 if(n == 0) {
 printf("No records found.\n");
 }else
 printf("\nRoll\tName\tMarks\n");
 for(int a = 0; a < n; a++)
 printf("%d\t%s\t%.2f\n", A[a].roll, A[a].name, A[a].marks);}
void editStudent() {
 int roll, found ;
 printf("Enter Roll No to edit: ");
 scanf("%d", &roll);
 for(int a = 0; a < n; a++) {
 if(A[a].roll == roll) {
 printf("Enter new Name: ");
 scanf("%s", A[a].name);
 printf("Enter new Marks: ");
 scanf("%f", &A[a].marks);
 printf("Record updated successfully!\n");
 found = 1;
 break;}}

 if(!found) printf("Record not found.\n");}
void deleteStudent() {
 int roll, found ;
 printf("Enter Roll No to delete: ");
 scanf("%d", &roll);
 for(int a = 0; a < n; a++) {
 if(A[a].roll == roll) {
 for(int b = a; b < n-1; b++)
 A[b] = A[b+1]; n--;
 printf("Record deleted successfully!\n");
 found = 1;
 break;}}
 if(!found) printf("Record not found.\n");}
void searchStudent() {
 int roll, found ;
 printf("Enter Roll No to search: ");
 scanf("%d", &roll);
 for(int a = 0; a < n; a++) {
 if(A[a].roll == roll) {
 printf("Found: %d %s %.2f\n", A[a].roll, A[a].name, A[a].marks);
 found = 1;
 break;}}

 if(!found) printf("Record not found.\n");}
void sortStudent() {
 for(int a = 0; a < n-1; a++) {
 for(int b = a+1; b < n; b++) {
 if(A[a].roll > A[b].roll) {
 struct Student temp = A[a];
 A[a] = A[b];
 A[b] = temp;}}}
 printf("Records sorted by Roll No.\n");
}