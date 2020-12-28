//PROGRAM MANAJEMEN DATA PEGAWAI
/*Nama Anggota	: 
Nabila Ayu Puspita (19081010006)
Siti Zuhrotun Nafi'atur Rohmah (19081010067)
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct data{
	char nama [50],alamat[50],jabatan[20],telp[20];
	int kode;
};
typedef struct data data;

void bubbleSort(int arr[], int jumlah){
  int i, j, tmp;
  for(i=0;i<jumlah;i++){
    for(j=0;j<jumlah-i-1;j++){
      if(arr[j] > arr[j+1]){
        tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }
}

int main() {
    int proses=0,menu,jumlah=0,total=0,gaji,lembur,cari,posisi,kiri,kanan,tengah,flag,tmp,hapus,penghapusan=0,i,j;
    int jam[10],jam_2[10];
	char pilih;
	char nama[30];
	char user[10],pw[10];
	data pegawai;
	data *ppegawai;
	
	printf("\t\t\t\t\tPROGRAM DATA PEGAWAI PT. JAYA WIJAYA\n");
	printf("Masukan Username : ");
    scanf("%s",&user);
    printf("Masukan Password : ");
    scanf("%s",&pw);
    if(strcmp(user,"pegawai")==0 && strcmp(pw,"2020")==0){
        printf("Akses diterima\n\n\n");
        system("CLS");
    
		while (proses<1) {
	        printf("~~~~~~~~~~~~~~MENU PROGRAM~~~~~~~~~~~~~~~\n|\t\t\t\t\t|\n");
		    printf("|1. Input Data Pegawai\t\t\t|\n");
		    printf("|2. Lihat Data Pegawai\t\t\t|\n");
		    printf("|3. Hitung Gaji Pegawai\t\t\t|\n");
			printf("|4. Urutkan Jam Kerja Pegawai\t\t|\n");
			printf("|5. Cari Jam Kerja Pegawai\t\t|\n");
		    printf("|6. Hapus Nilai Jam Kerja\t\t|\n");
		    printf("|7. Restore Data\t\t\t|\n");
		    printf("|8. Reset Data Pegawai\t\t\t|\n");
		    printf("|9. Keluar dari Program\t\t\t|\n");
		    printf("----------------------------------------|\n");
	
	
	        printf("Masukkan pilihan anda : ");
	        scanf("%d",&menu);
	        printf("\n");
	        system("CLS");
	
	        if (menu==1) {
	        	if (jumlah>0)
					printf("slot data sudah diisi, pilih menu reset jika ingin menulis ulang data");
	            else {
		        	printf ("Kode Pegawai:\n1. Manager	(3000)\n2. Supervisor	(31xx)\n3. Staf		(32xx)");
		        	
					printf ("\n1. masukkan kode nomor pegawai anda	:");
					scanf ("%d",&pegawai.kode);
					fflush(stdin);
		            
		           	printf ("2. masukkan nama anda		: ");
					gets (pegawai.nama);
								
					printf ("3. masukkan alamat anda		: ");
					gets (pegawai.alamat);
						
					printf ("4. masukkan kontak anda		: ");
					gets (pegawai.telp);			
						
					printf ("5. masukkan jabatan anda	: ");
					gets (pegawai.jabatan);
										
					printf("6. masukkan jumlah kehadiran anda dalam minggu ini: ");
					scanf("%d",&jumlah);
					for (i=0;i<jumlah;i++) {
						printf("\n>>Masukkan lama jam kerja anda pada hari ke-%d: ",i+1);
						scanf("%d",&jam[i]);
						jam_2[i]=jam[i];
					}			
				
	            }
	        } 
			
			else if (menu==2) {           
				if (jumlah>0) {
					printf ("\n\n\n~~~~~~~~~~~~~DATA PEGAWAI~~~~~~~~~~~~~\n\n");
					
					ppegawai=&pegawai;
					
					printf ("\n 1. Nomor Kode	: %d",ppegawai->kode);			
					printf ("\n 2. Nama	: %s",ppegawai->nama);
					printf ("\n 3. Alamat	: %s",ppegawai->alamat);
					printf ("\n 4. Kontak	: %s",ppegawai->telp);
					printf ("\n 5. Jabatan	: %s",ppegawai->jabatan);
			        printf ("\n 6. Kehadiran	:");
					for (i=0; i<jumlah; i++) {
						printf("\n >> Lama jam kerja hari ke-%d: ",i+1);
						printf ("%d",jam[i]);
			        }
	            } 
				else 
	                printf("\nmasukkan data pada menu no.1 terlebih dahulu");            
	        }
	        
	        else if (menu==3){
	        	if (jumlah>0){
					ppegawai=&pegawai;
					
					printf ("RINCIAN GAJI PEGAWAI KODE: %d",ppegawai->kode);
					printf ("\n\nKEHADIRAN PEGAWAI");
					for (i=0;i<jumlah;i++) {
						printf("\n >> Lama jam kerja hari ke-%d: ",i+1);
						printf ("%d",jam[i]);
						total=total+jam[i];
			        }	
					printf ("\n\n >>> Total jam kerja dalam minggu ini adalah: %d",total);
					
					printf ("\n\nNOTE: \nDalam satu minggu, jam kerja minimal yang harus terpenuhi adalah 40 jam (tidak termasuk jam istirahat 12.00-13.00).");
					printf ("\nJika jam kerja lebih dari ketentuan minimal maka akan mendapat bonus lembur sebesar 2 persen dari total gaji mingguan.");
					
					printf ("\n\nJABATAN PADA DIVISI PEMASARAN : \na. Manager\nb. Supervisor\nc. Staf");
					printf ("\nPilih jabatan dalam divisi: ");
					scanf ("%s",&pilih);
					
					if (pilih=='a'||pilih=='A'){
						gaji=3000000;
						if (total<40){
							printf ("Silakan hubungi bagian HRD untuk informasi lebih lanjut.");
						}
						else if (total==40){
							gaji=gaji;
							printf ("Gaji anda sebagai manager satu minggu ini adalah: %d",gaji);
						}
						else if (total>40){
							lembur=total-40;
							gaji=gaji+(lembur*60000);
							printf ("Gaji anda sebagai manager satu minggu ini adalah: %d",gaji);
						}
					}
					else if(pilih=='b'||pilih=='B'){
						gaji=1750000;
						if (total<40){
							printf ("Silakan hubungi bagian HRD untuk informasi lebih lanjut.");
						}
						else if (total==40){
							gaji=gaji;
							printf ("Gaji anda sebagai Supervisor satu minggu ini adalah: %d",gaji);
						}
						else if (total>40){
							lembur=total-40;
							gaji=gaji+(lembur*35000);
							printf ("Gaji anda sebagai Supervisor satu minggu ini adalah: %d",gaji);
						}
					}
					else if(pilih=='c'||pilih=='C'){
						gaji=1000000;
						if (total<40){
							printf ("Silakan hubungi bagian HRD untuk informasi lebih lanjut.");
						}
						else if (total==40){
							gaji=gaji;
							printf ("Gaji anda sebagai Staf satu minggu ini adalah: %d",gaji);
						}
						else if (total>40){
							lembur=total-40;
							gaji=gaji+(lembur*20000);
							printf ("Gaji anda sebagai Staf satu minggu ini adalah: %d",gaji);
						}
					}
					else
						printf ("\npilihan yang anda masukkan tidak ada.");					
				}
				else
	                printf("\nmasukkan data pada menu no.1 terlebih dahulu");
			}   			
			
			else if (menu==4){
	        	if (jumlah>0){
					ppegawai=&pegawai;
					printf ("\nKEHADIRAN PEGAWAI KODE: %d",ppegawai->kode);
					for (i=0; i<jumlah; i++){
						printf("\n >> Lama jam kerja hari ke-%d: ",i+1);
						printf ("%d",jam[i]);
			        }		    	
					
					bubbleSort(jam,jumlah);
					printf("\n\nHasil pengurutan bubble sort sebagai berikut:\n");
					for(i = 0; i < jumlah; i++){
						printf("%d ", jam[i]);
					}
					printf("\n");
				}
				else
	                printf("\nmasukkan data pada menu no.1 terlebih dahulu");
			} 
	
			else if (menu==5){
				if (jumlah>0){
					bubbleSort(jam,jumlah);
					printf("\n\nHasil pengurutan bubble sort sebagai berikut:\n");
					for(i = 0; i < jumlah; i++){
						printf("%d ", jam[i]);
					}
					
					kiri=0;
					kanan=i-1;
					
					printf ("\n\n\nPencarian Binary Search");
					printf("\nmasukkan nilai data yang anda cari: ");
					scanf("%d",&cari);
					while (kiri<=kanan&&flag==0){
						tengah=(kiri+kanan)/2;
						if(jam[tengah]==cari){
							flag=1;
						}
		
						else if(cari<jam[tengah])
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
				else 
	            	printf("\nmasukkan data pada menu no.1 terlebih dahulu");
			}     
			
			else if (menu==6){
	    		if (jumlah>0){
					ppegawai=&pegawai;
					printf ("\nKEHADIRAN PEGAWAI KODE: %d",ppegawai->kode);
					for (i=0; i<jumlah; i++){
						printf("\n >> Lama jam kerja hari ke-%d: ",i+1);
						printf ("%d",jam[i]);
			        }
					printf("\nMasukkan nilai jam kerja yang akan dihapus : ");
					scanf("%d",&hapus);
					
					for (i=0;i<jumlah;i++){
						if (jam[i]==hapus){
							jam[i]=NULL;
							penghapusan++;
						}
					}
					if(penghapusan>0) 
						printf("\nPenghapusan data sukses");
					else 
						printf("\Tidak ada angka tersebut dalam array jam kerja\n\nPenghapusan data gagal");
				}
				else
	                printf("\nmasukkan data pada menu no.1 terlebih dahulu");
			}
	    	
	    	else if (menu==7){
	    		if (jumlah>0){
					for (i=0;i<jumlah;i++) {
						jam[i]=jam_2[i];
	                }
	                printf("Restore data berhasil dilakukan");
				}
				else{
	                printf("\nmasukkan data pada menu no.1 terlebih dahulu");
	            }
			}     		
			       
	    	else if (menu==8){
	    		if (jumlah>0){
		            jumlah=0;
		            printf("Reset data berhasil dilakukan");
				}
				else {
	                printf("\nmasukkan data pada menu no.1 terlebih dahulu");
	            }
			}		    
			    
			    
			else if (menu==9){
				break;
	        } 
	
			else {
	           printf("\nTidak ada di menu");
	        }
	        
	        getch();
	        system("cls");
	    }   
	    system("pause");
	    }
	     
    else{
         printf("Username dan Password tidak match\n");
         system("pause");
         exit(1);
    }
return 0;  
}
