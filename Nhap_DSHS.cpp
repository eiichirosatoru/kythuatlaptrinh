#include <stdio.h>
#define MAX 50

struct date
{
	int ngay;
	int thang;
	int nam;
};

typedef struct HOCSINH
{
	char MSHS[6];
	char Hoten[31];
	struct date Ngaysinh;
	char Diachi[51];
	char phai[4];
	float diemtb;
}HOCSINH;

void Nhapnamsinh(date &d);
void Xuatnamsinh(date d);
void Nhap1HS(HOCSINH &hs);
void Xuat1HS(HOCSINH hs);
void NhapDSHS(HOCSINH lh[], int &n);
void XuatDSHS(HOCSINH lh[], int n);
int DemHSlenlop(HOCSINH lh[], int n);

int main()
{
	HOCSINH lh[MAX];
	int n, Sohsdau;
	NhapDSHS(lh,n);
	XuatDSHS(lh,n);
	Sohsdau=DemHSlenlop(lh,n);
	printf("\nSo luong hoc sinh duoc len lop la: %d", Sohsdau);
}

void Nhapnamsinh(date &d)
{
	printf("\nNhap vao ngay: ");
	scanf("%d", &d.ngay);
	printf("\nNhap vao thang: ");
	scanf("%d", &d.thang);
	printf("\nNhap vao nam: ");
	scanf("%d", &d.nam);
}

void Xuatnamsinh(date d)
{
	printf("%02d/%02d/%04d", d.ngay, d.thang, d.nam);
}

void Nhap1HS(HOCSINH &hs)
{
	float d;
	printf("\nNhap ma so hoc sinh: ");
		gets(hs.MSHS);
	printf("\nNhap ho ten hoc sinh: ");
		gets(hs.Hoten);
	printf("\nNhap ngay thang nam sinh: ");
		Nhapnamsinh(hs.Ngaysinh);
	printf("\nNhap vao dia chi: ");
		gets(hs.Diachi);
	printf("\nPhai: ");
		gets(hs.phai);
	printf("\nNhap vao diem trung binh: ");
		scanf("%f", &d);
		hs.diemtb=d;
}

void NhapDSHS(HOCSINH lh[], int &n)
{
	printf("\nNhap vao so luong hoc sinh: ");
	scanf("%d",&n);
	for(int i=0; i<n;i++)
	{
		printf("\nNhap vao thong tin cua hoc sinh thu %d:\n", i+1);
		Nhap1HS(lh[i]);
	}
}

void Xuat1HS(HOCSINH hs)
{
	printf("\nMa so hoc sinh: %s", hs.MSHS);
	printf("\nHo ten hoc sinh: %s", hs.Hoten);
	printf("\nNgay thang nam sinh: ");
		Xuatnamsinh(hs.Ngaysinh);
	printf("\nDia chi: %s", hs.Diachi);
	printf("\nPhai: %s", hs.phai);
	printf("\nDiem trung binh: %2.2f", hs.diemtb);
}

void XuatDSHS(HOCSINH lh[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\n\nThong tin hoc sinh thu %d:", i+1);
		Xuat1HS(lh[i]);
	}
}

int DemHSlenlop(HOCSINH lh[], int n)
{
	int d = 0;
	for(int i = 0; i<n;i++)
		if(lh[i].diemtb>=5.0)
			d++;
	return d;
}
