#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[50];
    float price;
};

int main() {
    struct Book books[3];
    int i;
    for (i = 0; i < 3; i++) {
        printf("Nhap thong tin cho cuon sach thu %d:\n", i + 1);
        printf("Ten sach: ");
        fgets(books[i].title, 100, stdin);
        books[i].title[strcspn(books[i].title, "\n")] = 0;

        printf("Tac gia: ");
        fgets(books[i].author, 50, stdin);
        books[i].author[strcspn(books[i].author, "\n")] = 0;

        printf("Gia: ");
        scanf("%f", &books[i].price);
        while (getchar() != '\n'); 
    }
    printf("\n--- Thong tin cac cuon sach da nhap ---\n");
    for (i = 0; i < 3; i++) {
        printf("Cuon sach %d:\n", i + 1);
        printf("Ten sach: %s\n", books[i].title);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia: %.2f\n", books[i].price);
    }

    return 0;
}
