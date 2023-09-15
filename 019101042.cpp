#include <iostream>
#include <string.h>

typedef struct structSinhVien
{
 char maSo[5];
 char hoTen[100];
 int gioiTinh;
 char soDienThoai[20];
 char maLop[5];
 int namTuyenSinh;
} SinhVien;

typedef struct structLopHoc
{
 char maLop[5];
 char tenLop[100];
 char tenCTDT[100];
 int soHocSinh;
 SinhVien *danhSachSinhVien;
} LopHoc;

bool kiemTraTrungMaSo(SinhVien sinhVien1, SinhVien sinhVien2)
{
 return strcmp(sinhVien1.maSo, sinhVien2.maSo) == 0;
}

bool kiemTraMaSo(SinhVien *danhSachSinhVien, int n, SinhVien sinhVien)
{
 for (int i = 0; i < n; i++)
 {
  if (kiemTraTrungMaSo(danhSachSinhVien[i], sinhVien))
  {
   return false;
  }
 }
 
 return true;
}

void nhapThongTinhLopHoc(LopHoc &lopHoc)
{
 printf("Nhap ma lop hoc: ");
 fgets(lopHoc.maLop, sizeof(lopHoc.maLop), stdin);
 fflush(stdin);
 
 printf("Nhap ten lop hoc: ");
 fgets(lopHoc.tenLop, sizeof(lopHoc.tenLop), stdin);
 fflush(stdin);
 
 printf("Nhap ten chuong trinh dao tao: ");
 fgets(lopHoc.tenCTDT, sizeof(lopHoc.tenCTDT), stdin);
 fflush(stdin);
 
 printf("Nhap so hoc sinh: ");
 scanf("%d", &lopHoc.soHocSinh);
 getchar();
 
 lopHoc.danhSachSinhVien = new SinhVien[lopHoc.soHocSinh];
 for (int i = 0; i < lopHoc.soHocSinh; i++) 
 {
  SinhVien sinhVien;
  
  printf("-----------------------\n");
  printf("Nhap vao sinh vien thu %d\n", i + 1);
  
  do
  {
   printf("Nhap ma so sinh vien: ");
   fgets(sinhVien.maSo, sizeof(sinhVien.maSo), stdin);
   fflush(stdin);
   
   if (kiemTraMaSo(lopHoc.danhSachSinhVien, i, sinhVien) == false)
   {
    printf("Ma sinh vien da ton tai\n");
   }
  }
  while (kiemTraMaSo(lopHoc.danhSachSinhVien, i, sinhVien) == false);
  
  printf("Nhap ho ten sinh vien: ");
  fgets(sinhVien.hoTen, sizeof(sinhVien.hoTen), stdin);
  fflush(stdin);
  
  printf("Nhap gioi tinh (0: Nu | 1: Nam): ");
  scanf("%d", &sinhVien.gioiTinh);
  getchar();
  
  printf("Nhap so dien thoai: ");
  fgets(sinhVien.soDienThoai, sizeof(sinhVien.soDienThoai), stdin);
  fflush(stdin);
  
  strcpy(sinhVien.maLop, lopHoc.maLop);
  
  printf("Nhap nam tuyen sinh: ");
  scanf("%d", &sinhVien.namTuyenSinh);
  getchar();
  
  lopHoc.danhSachSinhVien[i] = sinhVien;
 }
}

void xuatThongTinLopHoc(LopHoc lopHoc) 
{
	 printf("---------------------------------\n");
	 printf("Thong tin lop Hoc\n");
	 printf("Ma lop: %s", lopHoc.maLop);
	 printf("Ten lop: %s", lopHoc.tenLop);
	 printf("Ten chuong trinh dao tao: %s", lopHoc.tenCTDT);
	 printf("So luong hoc sinh trong lop: %d", lopHoc.soHocSinh);
 
 		for (int i = 0; i < lopHoc.soHocSinh; i++)
 			{
			  	SinhVien sinhVien = lopHoc.danhSachSinhVien[i];
			  	printf("\n---------------------\n", i + 1);
			  	printf("Thong tin sinh vien thu %d", i + 1);
			  	printf("\nMa so sinh vien: %s", sinhVien.maSo);
			  	printf("Ho ten: %s", sinhVien.hoTen);
			  	printf("Gioi Tinh: %s", sinhVien.gioiTinh == 0 ? "Nu" : "Nam");
			  	printf("\nSo Dien Thoai: %s", sinhVien.soDienThoai);
			  	printf("Ma lop: %s", sinhVien.maLop);
			  	printf("Nam tuyen sinh: %d", sinhVien.namTuyenSinh);
 			}
}
int main(int argc, char** argv) 
{    
 	LopHoc lopHoc;
 	nhapThongTinhLopHoc(lopHoc);
 	xuatThongTinLopHoc(lopHoc);
 
    return 0;
}

