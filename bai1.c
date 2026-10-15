#include <stdio.h>
#include <string.h>

#define MAX_NV 50

typedef struct {
    int maNV;
    char hoTen[50];
    int soPhutDiMuon;
    float luongCoBan;
} NhanVien;

int timTheoMaNV(NhanVien ds[], int n, int ma);
int themNhanVien(NhanVien ds[], int n);
void hienThiDanhSach(NhanVien ds[], int n);
void capNhatPhutDiMuon(NhanVien ds[], int n);
void timKiemNhanVien(NhanVien ds[], int n);

int timTheoMaNV(NhanVien ds[], int n, int ma) {
    for (int i = 0; i < n; i++)
        if (ds[i].maNV == ma) return i;
    return -1;
}

int themNhanVien(NhanVien ds[], int n) {
    if (n >= MAX_NV) {
        printf("Danh sach da day!\n");
        return n;
    }

    NhanVien nv;
    printf("Nhap ma NV: ");
    if (scanf("%d", &nv.maNV) != 1) {
        printf("Ma NV khong hop le!\n");
        while (getchar() != '\n');
        return n;
    }
    getchar();

    if (timTheoMaNV(ds, n, nv.maNV) != -1) {
        printf("Ma NV da ton tai!\n");
        return n;
    }

    printf("Nhap ho ten: ");
    fgets(nv.hoTen, sizeof(nv.hoTen), stdin);
    nv.hoTen[strcspn(nv.hoTen, "\n")] = '\0';

    printf("Nhap so phut di muon: ");
    if (scanf("%d", &nv.soPhutDiMuon) != 1 || nv.soPhutDiMuon < 0) {
        printf("So phut khong hop le!\n");
        while (getchar() != '\n');
        return n;
    }

    printf("Nhap luong co ban: ");
    if (scanf("%f", &nv.luongCoBan) != 1 || nv.luongCoBan < 0) {
        printf("Luong khong hop le!\n");
        while (getchar() != '\n');
        return n;
    }

    ds[n] = nv;
    printf("Them nhan vien thanh cong!\n");
    return n + 1;
}

void hienThiDanhSach(NhanVien ds[], int n) {
    if (n == 0) {
        printf("Danh sach rong!\n");
        return;
    }

    printf("\n--- DANH SACH NHAN VIEN ---\n");
    printf("Ma NV | Ho ten | Phut muon | Luong thuc nhan\n");

    for (int i = 0; i < n; i++) {
        float phat = ds[i].soPhutDiMuon > 15 ? 50000 : 0;
        printf("%d | %s | %d | %.0f\n",
               ds[i].maNV, ds[i].hoTen,
               ds[i].soPhutDiMuon, ds[i].luongCoBan - phat);
    }
}

void capNhatPhutDiMuon(NhanVien ds[], int n) {
    int ma, phut;

    if (n == 0) {
        printf("Danh sach rong!\n");
        return;
    }

    printf("Nhap ma NV can cap nhat: ");
    if (scanf("%d", &ma) != 1) {
        printf("Ma NV khong hop le!\n");
        while (getchar() != '\n');
        return;
    }

    int vt = timTheoMaNV(ds, n, ma);
    if (vt == -1) {
        printf("Khong tim thay nhan vien!\n");
        return;
    }

    printf("Nhap so phut di muon moi: ");
    if (scanf("%d", &phut) != 1 || phut < 0) {
        printf("So phut khong hop le!\n");
        while (getchar() != '\n');
        return;
    }

    ds[vt].soPhutDiMuon = phut;
    printf("Cap nhat thanh cong!\n");
}

void timKiemNhanVien(NhanVien ds[], int n) {
    int ma;

    if (n == 0) {
        printf("Danh sach rong!\n");
        return;
    }

    printf("Nhap ma NV can tim: ");
    if (scanf("%d", &ma) != 1) {
        printf("Ma NV khong hop le!\n");
        while (getchar() != '\n');
        return;
    }

    int vt = timTheoMaNV(ds, n, ma);
    if (vt == -1) {
        printf("Khong tim thay nhan vien!\n");
        return;
    }

    float phat = ds[vt].soPhutDiMuon > 15 ? 50000 : 0;
    printf("Ma NV: %d\nHo ten: %s\nPhut di muon: %d\nLuong thuc nhan: %.0f\n",
           ds[vt].maNV, ds[vt].hoTen, ds[vt].soPhutDiMuon,
           ds[vt].luongCoBan - phat);
}

int main(void) {
    NhanVien ds[MAX_NV];
    int n = 0, chon;

    do {
        printf("\n===== HE THONG QUAN LY CHAM CONG HRM =====\n");
        printf("1. Them nhan vien moi\n");
        printf("2. Hien thi danh sach va tinh luong\n");
        printf("3. Cap nhat so phut di muon\n");
        printf("4. Tim kiem nhan vien theo ma\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");

        if (scanf("%d", &chon) != 1) {
            printf("Lua chon khong hop le!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (chon) {
            case 1: n = themNhanVien(ds, n); break;
            case 2: hienThiDanhSach(ds, n); break;
            case 3: capNhatPhutDiMuon(ds, n); break;
            case 4: timKiemNhanVien(ds, n); break;
            case 0: printf("Ket thuc chuong trinh!\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (chon != 0);

    return 0;
}