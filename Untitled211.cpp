#include <stdio.h>
#include <string.h>

struct Car {
    char model[50];
    int year;
    float price;
};

int main() {
    struct Car myCar;

    strcpy(myCar.model, "Toyota Camry");
    myCar.year = 2023;
    myCar.price = 9500000000;
    printf("Mau xe: %s\n", myCar.model);
    printf("Nam san xuat: %d\n", myCar.year);
    printf("Gia cua xe: %.2f VND\n", myCar.price);

    return 0;
}
