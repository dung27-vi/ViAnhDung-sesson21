#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sach {
    char maSach[20];
    char tenSach[50];
    char tacGia[50];
    float giaTien;
    char theLoai[30];
};

struct Sach danhSachSach[100];
int soLuongSach = 0;

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void nhapThongTinSach() {
    int n;
    printf("Nhap so luong sach can them: ");
    scanf("%d", &n);
    clearBuffer();
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin sach thu %d:\n", soLuongSach + 1);
        printf("Ma sach: ");
        fgets(danhSachSach[soLuongSach].maSach, sizeof(danhSachSach[soLuongSach].maSach), stdin);
        danhSachSach[soLuongSach].maSach[strcspn(danhSachSach[soLuongSach].maSach, "\n")] = 0;

        printf("Ten sach: ");
        fgets(danhSachSach[soLuongSach].tenSach, sizeof(danhSachSach[soLuongSach].tenSach), stdin);
        danhSachSach[soLuongSach].tenSach[strcspn(danhSachSach[soLuongSach].tenSach, "\n")] = 0;

        printf("Tac gia: ");
        fgets(danhSachSach[soLuongSach].tacGia, sizeof(danhSachSach[soLuongSach].tacGia), stdin);
        danhSachSach[soLuongSach].tacGia[strcspn(danhSachSach[soLuongSach].tacGia, "\n")] = 0;

        printf("Gia tien: ");
        scanf("%f", &danhSachSach[soLuongSach].giaTien);
        clearBuffer();

        printf("The loai: ");
        fgets(danhSachSach[soLuongSach].theLoai, sizeof(danhSachSach[soLuongSach].theLoai), stdin);
        danhSachSach[soLuongSach].theLoai[strcspn(danhSachSach[soLuongSach].theLoai, "\n")] = 0;

        soLuongSach++;
    }
}

void hienThiThongTinSach() {
    printf("%-20s %-30s %-20s %-15s %-20s\n", "Ma sach", "Ten sach", "Tac gia", "Gia tien", "The loai");
    for (int i = 0; i < soLuongSach; i++) {
        printf("%-20s %-30s %-20s %-15.2f %-20s\n", 
               danhSachSach[i].maSach, 
               danhSachSach[i].tenSach, 
               danhSachSach[i].tacGia, 
               danhSachSach[i].giaTien, 
               danhSachSach[i].theLoai);
    }
}

void themSachVaoViTri() {
    int viTri;
    printf("Nhap vi tri can them (0 den %d): ", soLuongSach);
    scanf("%d", &viTri);
    clearBuffer();

    if (viTri < 0 || viTri > soLuongSach) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    for (int i = soLuongSach; i > viTri; i--) {
        danhSachSach[i] = danhSachSach[i - 1];
    }

    printf("Nhap thong tin sach moi:\n");
    printf("Ma sach: ");
    fgets(danhSachSach[viTri].maSach, sizeof(danhSachSach[viTri].maSach), stdin);
    danhSachSach[viTri].maSach[strcspn(danhSachSach[viTri].maSach, "\n")] = 0;

    printf("Ten sach: ");
    fgets(danhSachSach[viTri].tenSach, sizeof(danhSachSach[viTri].tenSach), stdin);
    danhSachSach[viTri].tenSach[strcspn(danhSachSach[viTri].tenSach, "\n")] = 0;
    
    printf("Tac gia: ");
    fgets(danhSachSach[viTri].tacGia, sizeof(danhSachSach[viTri].tacGia), stdin);
    danhSachSach[viTri].tacGia[strcspn(danhSachSach[viTri].tacGia, "\n")] = 0;

    printf("Gia tien: ");
    scanf("%f", &danhSachSach[viTri].giaTien);
    clearBuffer();

    printf("The loai: ");
    fgets(danhSachSach[viTri].theLoai, sizeof(danhSachSach[viTri].theLoai), stdin);
    danhSachSach[viTri].theLoai[strcspn(danhSachSach[viTri].theLoai, "\n")] = 0;

    soLuongSach++;
    printf("Da them sach thanh cong!\n");
}

void xoaSachTheoMa() {
    char maSachCanXoa[20];
    printf("Nhap ma sach can xoa: ");
    fgets(maSachCanXoa, sizeof(maSachCanXoa), stdin);
    maSachCanXoa[strcspn(maSachCanXoa, "\n")] = 0;

    int timThay = 0;
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(danhSachSach[i].maSach, maSachCanXoa) == 0) {
            for (int j = i; j < soLuongSach - 1; j++) {
                danhSachSach[j] = danhSachSach[j + 1];
            }
            soLuongSach--;
            timThay = 1;
            printf("Da xoa sach thanh cong!\n");
            break;
        }
    }

    if (!timThay) {
        printf("Khong tim thay sach co ma %s!\n", maSachCanXoa);
    }
}

void capNhatThongTinSach() {
    char maSachCanCapNhat[20];
    printf("Nhap ma sach can cap nhat: ");
    fgets(maSachCanCapNhat, sizeof(maSachCanCapNhat), stdin);
    maSachCanCapNhat[strcspn(maSachCanCapNhat, "\n")] = 0;

    int timThay = 0;
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(danhSachSach[i].maSach, maSachCanCapNhat) == 0) {
            printf("Nhap thong tin moi cho sach (Bo qua Ma sach):\n");
            printf("Ten sach: ");
            fgets(danhSachSach[i].tenSach, sizeof(danhSachSach[i].tenSach), stdin);
            danhSachSach[i].tenSach[strcspn(danhSachSach[i].tenSach, "\n")] = 0;

            printf("Tac gia: ");
            fgets(danhSachSach[i].tacGia, sizeof(danhSachSach[i].tacGia), stdin);
            danhSachSach[i].tacGia[strcspn(danhSachSach[i].tacGia, "\n")] = 0;

            printf("Gia tien: ");
            scanf("%f", &danhSachSach[i].giaTien);
            clearBuffer();

            printf("The loai: ");
            fgets(danhSachSach[i].theLoai, sizeof(danhSachSach[i].theLoai), stdin);
            danhSachSach[i].theLoai[strcspn(danhSachSach[i].theLoai, "\n")] = 0;

            timThay = 1;
            printf("Da cap nhat thong tin sach thanh cong!\n");
            break;
        }
    }

    if (!timThay) {
        printf("Khong tim thay sach co ma %s!\n", maSachCanCapNhat);
    }
}

void sapXepSachTheoGia() {
    int luaChon;
    printf("Sap xep theo gia (1: Tang dan, 2: Giam dan): ");
    scanf("%d", &luaChon);
    clearBuffer();

    for (int i = 0; i < soLuongSach - 1; i++) {
        for (int j = i + 1; j < soLuongSach; j++) {
            if ((luaChon == 1 && danhSachSach[i].giaTien > danhSachSach[j].giaTien) || 
                (luaChon == 2 && danhSachSach[i].giaTien < danhSachSach[j].giaTien)) {
                struct Sach temp = danhSachSach[i];
                danhSachSach[i] = danhSachSach[j];
                danhSachSach[j] = temp;
            }
        }
    }
    printf("Da sap xep sach theo gia thanh cong!\n");
}

void timKiemSachTheoTen() {
    char tenSachCanTim[50];
    printf("Nhap ten sach can tim: ");
    fgets(tenSachCanTim, sizeof(tenSachCanTim), stdin);
    tenSachCanTim[strcspn(tenSachCanTim, "\n")] = 0;

    int timThay = 0;
    printf("%-20s %-30s %-20s %-15s %-20s\n", "Ma sach", "Ten sach", "Tac gia", "Gia tien", "The loai");
    for (int i = 0; i < soLuongSach; i++) {
        if (strstr(danhSachSach[i].tenSach, tenSachCanTim) != NULL) {
            printf("%-20s %-30s %-20s %-15.2f %-20s\n", 
                   danhSachSach[i].maSach, 
                   danhSachSach[i].tenSach, 
                   danhSachSach[i].tacGia, 
                   danhSachSach[i].giaTien, 
                   danhSachSach[i].theLoai);
            timThay = 1;
        }
    }

    if (!timThay) {
        printf("Khong tim thay sach nao co ten chua '%s'!\n", tenSachCanTim);
    }
}
