#include <alloc.h>  //chua sua loi
#include <stdio.h>

void Nhap(int *a, int n);
void Xuat(int *a, int n);
int GiatriMax(int *a, int n);
void Swap(int *a, int n);
void Sapxep(int *a, int n);

int main()
{
	int *a, int n;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d", &n);
	a = new int[n];
	Nhap(a,n);
	printf(GiatriMax(a,n));
	Sapxep(a,n);
	Xuat(a,n);
	delete a;
}

void Nhap(int *a, int n)
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d",(a+i));
}

void Xuat(int *a, int n)
{
	for(int i=0;i<n;i++)
		printf("%d".*(a+i));
}

int GiatriMax(int *a, int n)
{
	int Max=*a;
	for(int i = 1;i<n;i++)
		if(*(a+i)>Max)
			Max=*(a+i);
	return Max;
}

void Swap(int *a, int n)
{
	int t = *a;
	*a=*b;
	*b=t;
}

void Sapxep(int *a, int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(*(a+i)>*(a+j))
				Swap(a+i,a+j);
}
