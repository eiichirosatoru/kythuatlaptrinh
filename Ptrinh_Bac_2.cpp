#include <stdio.h>
#include <conio.h>
#include <math.h>

typedef struct TAM_THUC
{
	float a;
	float b;
	float c;
}TAM_THUC;

typedef struct NGHIEM
{
	float x1;
	float x2;
	int songhiem;
}NGHIEM;

void Nhap_tam_thuc(TAM_THUC &P);

NGHIEM Giai_phuong_trinh_bac_2(TAM_THUC P);

void Xuat_nghiem(NGHIEM Ng);

int main()
{
	TAM_THUC P;
	NGHIEM Ng;
	Nhap_tam_thuc(P);
	Ng=Giai_phuong_trinh_bac_2(P);
	Xuat_nghiem(Ng);
}

void Nhap_tam_thuc(TAM_THUC &P)
{
	do
	{
		printf("Nhap he so a cua P: ");
		scanf("%f",&P.a);
	}
	while(P.a == 0);
		printf("Nhap he so b cua P: ");
		scanf("%f",&P.b);
		printf("Nhap he so c cua P: ");
		scanf("%f", P.c); 
}

NGHIEM Giai_phuong_trinh_bac_2(TAM_THUC P)
{
	NGHIEM Kq;
	float delta;
	delta=P.b*P.b-4*P.a*P.c;
	if(delta<0)
		Kq.songhiem=0;
	else if(delta==0)
	{
		Kq.songhiem=1;
		Kq.x1=-P.b/(2*P.a);
		Kq.x2=Kq.x1;
	}
	else
	{
		Kq.songhiem=2;
		Kq.x1=(P.b-sqrt(delta))/(2*P.a);
		Kq.x2=(-P.b+sqrt(delta))/(2*P.a);
	}
return Kq;			
}

void Xuat_nghiem(NGHIEM Ng)
{
	if(Ng.songhiem==0)
		printf("Phuong trinh vo nghiem ");
	else if(Ng.songhiem==1)
	{
		printf("Phuong trinh co nghiem kep ");
		printf("\n\tx = %f", Ng.x1);
	}
	else if(Ng.songhiem==2)
	{
		printf("Phuong trinh co hai nghiem ");
		printf("\nx1=%5.2f\nx2=%5.2f", Ng.x1, Ng.x2);
	}
}
