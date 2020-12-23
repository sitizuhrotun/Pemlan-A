//BINARY SEARCH TREE
//Nama 	: Siti Zuhrotun Nafi'atur Rohmah
//NPM	: 19081010067
//Kelas	: Pemrograman Lanjut Paralel A

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct binary{
	int data;
	struct binary* kiri;
	struct binary* kanan;
};

typedef struct binary node;

node* buatnode(int nilai){
	node* nodebaru;
	nodebaru=(node*)malloc(sizeof (node));
	nodebaru->data=nilai;
	nodebaru->kiri=nodebaru->kanan=NULL;
	return nodebaru;
}

node* tambah(node* root,int nilai){
	if (root==NULL)
		root=buatnode(nilai);
	else if (nilai<=root->data)
		root->kiri=tambah(root->kiri,nilai);
	else 
		root->kanan=tambah(root->kanan,nilai);
			
	return root;
}

node* cari (node* root, int angka){
	if (root==NULL)
		return 0;
	else if (angka==root->data)
		return 1;
	else if (angka<=root->data)
		return cari(root->kiri,angka);
	else
		return cari (root->kanan,angka);
}

int main() {
	node* root=NULL;
	int proses,menu,jumlah=0,total,nilai,angka,i;

	while (proses<1){
		printf ("Siti Zuhrotun NR\nDeret NPM+tanggal lahir:19-08-10-1-006-72-005-20-00\n\n\n");
		printf ("PROGRAM BINARY SEARCH TREE\n");
		printf ("MENU PROGRAM\n");
		printf ("1. Memasukkan Nilai Node(WAJIB)\n");
		printf ("2. Cari Nilai\n");
		printf ("3. Keluar\n\n");

		printf("Masukkan menu pilihan anda : ");
		scanf("%d",&menu);
		fflush(stdin);       
		printf("\n");		

		if (menu==1) {
			printf ("\nMASUKKAN DERET BERJUMLAH 9 INI SEBAGAI NODE: \n19-08-10-1-006-72-005-20-00\n\n\n");
			printf ("masukkan total node: ");
			scanf ("%d",&total);
			printf ("\n");
			for (i=0; i<total; i++) {
				printf ("\nmasukkan nilai node: ");
				scanf ("%d",&nilai);
				root=tambah(root,nilai);		
			}				
		} 

		else if (menu==2){        	
			printf ("\n\nmasukkan angka yang ingin dicari: ");
			scanf ("%d",&angka);
			cari(root,angka);

			if (cari (root,angka)==1)
				printf ("\nangka yang anda cari ada pada node");
			else 
				printf ("\nangka yang anda cari tidak ditemukan pada node.");							
		}

		else if (menu==3){
			break;
		} 

		else {
		   printf("\nTidak ada di menu");
		}

		getch();
		system("cls");
    }   
return 0;  
}
