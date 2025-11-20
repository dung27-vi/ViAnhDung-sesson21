#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float grade;
};
struct Student students[5];
void inputStudents(struct Student s[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Nhap thong tin cho hoc sinh thu %d:\n", i + 1);
        printf("Ten: ");
        getchar(); 
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = 0;
        printf("Tuoi: ");
        scanf("%d", &s[i].age);
        printf("Diem trung binh: ");
        scanf("%f", &s[i].grade);
    }
}
void searchStudentByName(struct Student s[], int size, char* searchName) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcasecmp(s[i].name, searchName) == 0) {
            printf("\nDa tim thay hoc sinh:\n");
            printf("Ten: %s\n", s[i].name);
            printf("Tuoi: %d\n", s[i].age);
            printf("Diem trung binh: %.2f\n", s[i].grade);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nKhong tim thay hoc sinh co ten \"%s\".\n", searchName);
    }
}
int main() {
    inputStudents(students, 5);
    char searchName[50];
    printf("\nNhap ten hoc sinh can tim kiem: ");
    getchar();
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = 0;
    searchStudentByName(students, 5, searchName);

    return 0;
}
