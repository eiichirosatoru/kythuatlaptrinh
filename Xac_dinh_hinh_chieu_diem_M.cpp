#include <stdio.h>
#include <conio.h>
#include <math.h>

typedef struct DIEM
{
	float x;
	float y;
}DIEM;
typedef struct DUONG_THANG
{
	float a;
	float b;
	float c;
}DUONG_THANG;

void Nhap_diem(DIEM &M)
{
	printf("Nhap toa do diem x: ");
	scanf("%f", &M.x);
	printf("Nhap toa do diem y: ");
	scanf("%f", &M.y);
}

void Nhap_duong_thang(DUONG_THANG &D)
{
	do
	{
		printf("He so a: ");
		scanf("%f", &D.a);
		printf("He so b: ");
		scanf("%f", &D.b);
		printf("He so c: ");
		scanf("%f", &D.c);
	}
	while (D.a*D.a+D.b*D.b<=0);
}

DUONG_THANG Tao_duong_vuong_goc(DIEM M, DUONG_THANG D)
{
	DUONG_THANG Kq;
	Kq.a = -D.b;
	Kq.b = D.a;
	return Kq;
}

DIEM Xac_dinh_giao_diem(DUONG_THANG D1, DUONG_THANG D)
{
	DIEM Kq;
	float delta;
	float deltax;
	float deltay;
	delta = D.a*D1.b-D.b*D1.a;
	deltax = D.b*D1.c-D1.b*D.c;
	deltay = D1.a*D.c-D1.c*D.a;
	Kq.x = deltax/delta;
	Kq.y = deltay/delta;
	return Kq;
}

void Xuat_diem(DIEM M)
{
	printf("Toa do hinh chieu cua diem M len duong thang (D) la: H(%5.2f;%5.2f)\n", M.x,M.y);
}

int main()
{
	DIEM M;
	DUONG_THANG D;
	DIEM H;
	DUONG_THANG D1;
	Nhap_diem(M);
	Nhap_duong_thang(D);
	D1 = Tao_duong_vuong_goc(M,D);
	H = Xac_dinh_giao_diem(D1,D);
	Xuat_diem(H);
}
