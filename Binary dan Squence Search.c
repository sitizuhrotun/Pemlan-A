//Nama 	: Siti Zuhrotun Nafi'atur Rohmah
//NPM	: 19081010067
//Kelas	: Pemrograman Lanjut Paralel A

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct data{
	char npm[20],nama [50],kota[20],provinsi[20],prodi[50],fakultas[50],universitas[50];
	int uts,uas;
};
typedef struct data data;


int main() {
    int menu,cari,hapus, kiri=0,kanan,tengah,jumlah=0,flag=0,counter=0,proses=0,i,j,tmp;
    int nilai[100],nilai_2[100];

	data mhs;
	data *pmhs;

    while (proses<1) {
        printf("~~~~~~~~~~~~~MENU PROGRAM~~~~~~~~~~~~~\n\n");
        printf("1. Input Data(WAJIB)\n");
        printf("2. Lihat Data\n");
        printf("3. Urutkan Data\n");
        printf("4. Cari Data (Sequence Search)\n");
        printf("5. Cari Data (Binary Search)\n");
        printf("6. Hapus Elemen Array\n");
        printf("7. Mengembalikan Nilai Array\n");
        printf("8. Reset Data\n");
        printf("9. Keluar dari Program\n\n");


        printf("Masukkan pilihan anda : ");
        scanf("%d",&menu);
        fflush(stdin);       
        printf("\n");

        if (menu==1) {
        	if (jumlah>0)
				printf("slot data sudah diisi, pilih menu reset jika ingin menulis ulang data");
            else {
               	printf ("1. masukkan nama:");
				gets (mhs.nama);
							
				printf ("2. masukkan npm:");
				gets (mhs.npm);
            
				printf ("3. masukkan prodi:");
				gets (mhs.prodi);
				
				printf ("4. masukkan fakultas:");
				gets (mhs.fakultas);
				
				printf ("5. masukkan universitas:");
				gets (mhs.universitas);
				
				printf ("6. masukkan kota/kabupaten domisili:");
				gets (mhs.kota);
				
				printf ("7. masukkan provinsi domisili:");
				gets (mhs.provinsi);
				
				
				
				printf("\n8. masukkan jumlah ulangan harian dalam 1 semester(5-10) : ");
               	scanf("%d",&jumlah);
               	if (jumlah<0 || jumlah>10){
    				printf("angka error");
				}
	           	else {
	                for (i=0; i<jumlah; i++) {
						printf("\n~Masukkan nilai ulangan harian ke %d (rentang 1-99): ",i+1);
						scanf("%d",&nilai[i]);
						nilai_2[i]=nilai[i];
               		}	
				}
            }
        } 
		
		else if (menu==2) {           
			if (jumlah>0) {
               	printf ("\n\n\n~~~~~~~~~~~~~DATA MAHASISWA~~~~~~~~~~~~~\n\n");
				pmhs=&mhs;
				printf ("\n 1. Nama: %s",pmhs->nama);
				printf ("\n 2. NPM: %s",pmhs->npm);
				printf ("\n 3. Prodi: %s",pmhs->prodi);
				printf ("\n 4. Fakultas: %s",pmhs->fakultas);
				printf ("\n 5. Universitas: %s",pmhs->universitas);
				printf ("\n 6. Kota/Kabupaten Domisili: %s",pmhs->kota);
				printf ("\n 7. Provinsi Domisili: %s",pmhs->provinsi);
	            printf ("\n 8. NILAI ULANGAN HARIAN");
				for (i=0; i<jumlah; i++) {
	            	if (nilai[i]==NULL) printf("  "); 
					else
						printf("\n~nilai ulangan harian ke %d (rentang 1-99):",i+1);
						printf ("%d",nilai[i]);
	            }
            } 
			else {
                  printf("\nmasukkan data pada menu no.1 terlebih dahulu");
            }
        }
        
		else if (menu==3){
			if (jumlah>0){
				for (i=0; i<jumlah; i++) {
                	if (nilai[i]==NULL) printf("  "); 
					else
						printf("\nnilai ulangan harian: %d ",nilai[i]);
            	}
				for (i=1;i<=jumlah;i++){
					j=i;
					while(j>0&&nilai[j-1]>nilai[j]){
						tmp = nilai[j];
						nilai[j] = nilai[j-1];
						nilai[j-1] = tmp;
						j--;
					}
				}
				printf("\n\nHasil pengurutan sebagai berikut:\n");
				for (i = 0; i <= jumlah-1; i++){
					printf("%d ", nilai[i]);
				}
				printf("\n");
			}
			else {
                printf("\nmasukkan data pada menu no.1 terlebih dahulu");
            }
		}     
    	
    	else if (menu==4){
    		if (jumlah>0){
	    		for (i=0; i<jumlah; i++) {
	                if (nilai[i]==NULL) printf("  "); 
					else
						printf("\nnilai ulangan harian: %d ",nilai[i]);
	            }
	            
	            printf("\n\nmasukkan nilai data yang anda cari: ");
	            scanf("%d",&cari);
	            for (i=0;i<100;i++){
	            	if (nilai[i]==cari) {
						counter++;
						flag=1;	
					}          	
				}
				if (flag==1)
					printf ("\ndata yang anda cari ADA, sebanyak %d data",counter);
				else 
					printf ("\ndata yang anda cari TIDAK ADA");
					break;
			}
			else {
                printf("\nmasukkan data pada menu no.1 terlebih dahulu");
            }
		}
    	
    	else if (menu==5){
    		if (jumlah>0){
    		for (i=0; i<jumlah; i++) {
                if (nilai[i]==NULL) printf("  "); 
				else
					printf("\nnilai ulangan harian: %d ",nilai[i]);
            }
			for (i=1;i<=jumlah;i++){
				j=i;
				while(j>0&&nilai[j-1]>nilai[j]){
					tmp = nilai[j];
					nilai[j] = nilai[j-1];
					nilai[j-1] = tmp;
					j--;
				}
			}
			printf("\n\nHasil pengurutan sebagai berikut:\n");
			for (i = 0; i <= jumlah-1; i++){
			printf("%d ", nilai[i]);
			}
			printf("\n");
			
			kiri=0;
			kanan=i-1;
			
			printf("\nmasukkan nilai data yang anda cari: ");
			scanf("%d",&cari);
			while (kiri<=kanan&&flag==0){
				tengah=(kiri+kanan)/2;
				if(nilai[tengah]==cari)
					flag=1;

				else if(cari<nilai[tengah])
					kanan=tengah-1;
				
				else
					kiri=tengah+1;

			}
			if (flag==1)
				printf ("\ndata yang anda cari ADA");
			else
			printf ("\ndata yang anda cari TIDAK ADA");
			
			break;
    			
			}
			else{
                printf("\nmasukkan data pada menu no.1 terlebih dahulu");
            }
		}     
    	
		else if (menu==6) {
           if (jumlah>0) {
              printf("\nnilai mahasiswa :\n\n");
			  	for (i=0; i<jumlah; i++) {
			  		if (nilai[i]==NULL) printf("  "); 
					else
				  	printf("%d ",nilai[i]);
            	}
				printf("\nMasukkan bilangan yang akan dihapus : ");
				scanf("%d",&hapus);
				int jumlah_hapus=0;
				for (i=0; i<jumlah; i++) {
					if (nilai[i]==hapus){
					nilai[i]=NULL;jumlah_hapus++;
					}
				}
				if(jumlah_hapus>0) printf("\nPenghapusan sukses");
				else 
				printf("\tidak ada angka\n\npenghapusan gagal");
            } 
		   else {
                  printf("\nmasukkan data pada menu no.1 terlebih dahulu");
            }
        } 
		
		else if (menu==7) {
            if (jumlah>0) {
				for (i=0; i<jumlah; i++) {
					nilai[i]=nilai_2[i];
                }
                printf("Restore data berhasil");
            } 
			else {
                printf("\nmasukkan data pada menu no.1 terlebih dahulu");
            }
        } 
		
		else if (menu==8) {
           if (jumlah>0) {
				for (i=0; i<jumlah; i++) {
                	nilai[i]=NULL;
                }
	            jumlah=0;
	            printf("Reset data berhasil dilakukan");
	        } 
		  else {
				printf("\nmasukkan data pada menu no.1 terlebih dahulu");
            }            
				jumlah=0;
        } 
		
		else if (menu==9) {
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
