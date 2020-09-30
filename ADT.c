//Nama		: Siti Zuhrotun Nafi'atur Rohmah
//NPM 		: 19081010067
//Kelas 	: Pemrograman Lanjut Paralel A

#include <stdio.h>
#include <string.h>


struct total {
	char nama [100], npm [11];
	float uts, uas, nilai;
};

typedef struct total total;
void main (){
	total m1;
	total *pm1;
	
	printf ("masukkan nama anda : \n");
	gets (m1.nama);	//saya memakai fungsi gets karena fungsi scanf terbatas pada penggunaan spasi

	printf ("masukkan 11 digit npm anda : \n");
	scanf ("%s",&m1.npm);

	printf ("masukkan nilai uts anda : \n");
	scanf ("%f",&m1.uts);
	
	printf ("masukkan nilai uas anda : \n");
	scanf ("%f",&m1.uas);

	printf ("\n\n\n~~~~~~~~~~~~~NILAI~~~~~~~~~~~~~\n\n");

	m1.nilai =(m1.uts+m1.uas)*0.5;	
	pm1= &m1;
	
	printf ("\n%s",pm1->nama);
	printf ("\n%s",pm1->npm);
	printf ("\nrata-rata nilai anda adalah: %lf",pm1->nilai);

getch ();
}

