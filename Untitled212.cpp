#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float grade;
};

int main() {
    struct Student student1;

    printf("Nhap ten hoc sinh: ");
    scanf("%s", student1.name);
    printf("Nhap tuoi hoc sinh: ");
    scanf("%d", &student1.age);
    printf("Nhap diem trung binh: ");
    scanf("%f", &student1.grade);
    printf("\n--- Thong tin hoc sinh ---\n");
    printf("Ten: %s\n", student1.name);
    printf("Tuoi: %d\n", student1.age);
    printf("Diem trung binh: %.2f\n", student1.grade);

    return 0;
}
