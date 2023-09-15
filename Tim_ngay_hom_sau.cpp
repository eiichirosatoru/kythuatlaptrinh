#include <stdio.h>
#define KTNN(x) ((x)%4==0&&(x)%100!=0 || (x)%400==0)

struct date
{
	int ngay;
	int thang;
	int nam;
};

int N[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int KThople(date x);
void Nhap(date &x);
void Xuat(date x);
date Ngaythuong(date x);
date Ngaycuoithang(date x);
date Ngaycuoinam(date x);
date Timngayhomsau(date x);

int main()
{
	date x,ngayhomsau;
	Nhap(x);
	ngayhomsau=Timngayhomsau(x);
	Xuat(ngayhomsau);
}

int KThople(date x)
{
	if(KTNN(x.nam))
		N[2] = 29;
	if(!(x.nam>=1))
		return 0;
	if(!(x.thang>=1 && x.thang<=12))
		return 0;
	if(!(x.ngay>=1 && x.ngay<=N[x.thang]))
		return 0;
	return 1;
}

void Nhap(date &x)
{
	do
	{
		printf("Nhap_ngay_thang_nam: ");
		scanf("%d%d%d", &x.ngay, &x.thang, &x.nam);
	}
	while(!(KThople(x)));
}

void Xuat(date x)
{
	printf("Ngay_thang_nam: %d/%d/%d", x.ngay, x.thang, x.nam);
}

date Ngaythuong(date x)
{
	date kq={x.ngay+1,x.thang,x.nam};
	return kq;
}

date Ngaycuoithang(date x)
{
	date kq={1,x.thang+1,x.nam};
	return kq;
}

date Ngaycuoinam(date x)
{
	date kq={1,1,x.nam+1};
	return kq;
}

date Timngayhomsau(date x)
{
	date kq=Ngaythuong(x);
	if(x.thang==12 && x.ngay==31)
		return Ngaycuoinam(x);
	if(x.ngay==(N[x.thang]+(x.thang==2 && KTNN(x.nam))))
		return Ngaycuoithang(x);
	return kq;
}
