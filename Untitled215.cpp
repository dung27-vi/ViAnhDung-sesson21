#include <stdio.h>

struct Product {
    char name[50];
    float price;
    int quantity;
};

struct Product products[5];
void inputProducts() {
    for (int i = 0; i < 5; i++) {
        printf("Nhap thong tin cho san pham  %d:\n", i + 1);
        printf("Ten: ");
        scanf("%s", products[i].name);
        printf("Gia: ");
        scanf("%f", &products[i].price);
        printf("So luong: ");
        scanf("%d", &products[i].quantity);
    }
}
float calculateTotalValue() {
    float totalValue = 0.0;
    for (int i = 0; i < 5; i++) {
        totalValue += products[i].price * products[i].quantity;
    }
    return totalValue;
}
void printTotalValue(float total) {
    printf("Tung gia tri cua tat ca s?a pham la: %.2f\n", total);
}
int main() {
    inputProducts();
    float total = calculateTotalValue();
    printTotalValue(total);
    return 0;
}
