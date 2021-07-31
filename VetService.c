/*
	Program		: VetService.c
	Author		: Muhammad Faza Hardiansyah (201524016)
				  Muhammad Fikri Hidayatulloh (201524017)
				  Syahda Afia Dhiya Ulhaq Tajudin (201524030)
	Kelompok	: A9
	Deskripsi	: Aplikasi layanan Dokter Hewan (mendata, menampilkan, dan memanggil antrian)
	Compiler	: DevC++ TDM-GCC 4.9.2 64-bit Release
*/

#include "VetService.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


			/* Implementasi ADT */
/*========================================*/

/*** MANAJEMEN MEMORI ***/
/* Mengirimkan address hasil alokasi sebuah elemen dengan info X.
   Jika alokasi berhasil, modul mengembalikan P; P->info = X, = NULL.
   P adalah pointer yang menunjuk ke node Queue sebagai hasil alokasi.
   Jika alokasi gagal, modul mengembalikan NULL.
 */
addrNQ Alokasi (infotype X){
	//deklarasi
	addrNQ P;
	
	//algoritma
	P = (addrNQ)malloc(sizeof(NodeQueue));
	if (P != NULL){
		P->info = X;
		P->next = NULL;
		return P;
	} else return NULL;
}

/* Melakukan dealokasi elemen P (pointer menunjuk ke alamat node queue).
   I.S.: P terdefinisi.
   F.S.: P dikembalikan ke sistem.
 */
void Dealokasi (addrNQ *P){
	//algoritma
	free(*P);
}


/*** Manajemen Queue ***/
/* Membuat sebuah Queue kosong dengan Q.fornt = NULL dan Q.rear = NULL. 
   I.S. Belum terbentuk Queue 
   F.S. Sudah terbentuk Queue
*/
void BuatAntrian (Queue *Q){
	//algoritma
	(*Q).front = NULL;
	(*Q).rear = NULL;
}

/* Mengetahui apakah Queue kosong atau tidak. 
   mengirimkan 1, jika Queue kosong yaitu Q.front = NULL dan Q.rear = NULL.
   mengirimkan 0, jika Queue tidak kosong.
*/
int CekAntrianKosong (Queue Q){
	//algoritma
	if(Q.front == NULL){
		return 1;
	} else return 0;
}

/* Memasukkan info baru ke dalam Queue dengan aturan FIFO.
   I.S. Q mungkin kosong atau Q mungkin berisi antrian.
   F.S. info baru telah masuk ke dalam Queue.
*/ 
void Antrian (Queue *Q, infotype data){
	//deklarasi
	addrNQ P;
	
	//algoritma
	P = Alokasi(data);
	if (CekAntrianKosong(*Q) == 1){
		(*Q).front = P;
		(*Q).rear = P;
	} else {
		(*Q).rear->next = P;
		(*Q).rear = P;
	}
}

/* Menghapus node dari Queue dengan aturan FIFO .
   I.S. Q mungkin kosong atau Q mungkin berisi antrian.
   F.S. Node sudah terhapus.
*/ 
void MulaiService (Queue *Q, infotype *data){
	//deklarasi
	addrNQ P;
	
	//algoritma
	system("cls");
	if ((*Q).front==NULL){
		printf ("Antrian Masih Kosong\n\n");
	}else {
		(*data)=(*Q).front->info;
		P=(*Q).front;
		(*Q).front = (*Q).front->next;
		P->next=NULL;
		printf("Antrian sudah dipanggil \n\n");
	}
}


/*** MANAJEMEN WAKTU ***/
/* Menghitung waktu service.
   Mengembalikan waktu service sesuai dengan kategori penyakit.
*/
int HitungWaktuService (char data[]){
	//algoritma
	//membandingkan kata, jika sama maka mengembalikan waktu service
	if(strcmp(data, "Ringan") == 0){
		return 15;
	}else if(strcmp(data, "Sedang") == 0){
		return 30;
	}else if(strcmp(data, "Berat") == 0){
		return 45;
	}
}

/* Menghitung waktu selesai layanan. 
   Mengembalikan hasil dari WDatang + WTunggu + WService.
*/
int HitungWaktuSelesai (infotype data){
	return data.WDatang + data.WTunggu + data.WService;
}

/* Menghitung waktu tunggu layanan apabila tidak ada pertukaran antrian.
   Mengembalikan hasil dari WSelesai (rear)- WDaftar.
*/
int HitungWaktuTunggu1(addrNQ P, int WDaftar){
	//algoritma
	if(P == NULL){
		return 0;
	}else if(WDaftar < P->info.WSelesai){
			return P->info.WSelesai-WDaftar;
		}else{
			return 0;
	}
}

/* Menghitung waktu tunggu layanan apabila ada pertukaran antrian.
   Mengembalikan hasil dari WSelesai (Node sebelumnya)- WDaftar.
*/
int HitungWaktuTunggu2 (addrNQ P, int WDaftar){
	//algoritma
	if (WDaftar < P->info.WSelesai){
		return P->info.WSelesai-WDaftar;
	}else return 0;
}

/* Menghitung waktu tunggu layanan.
   Mengembalikan hasil dari WDatang + WTunggu.
*/
int HitungWaktuMulai (addrNQ P, int WDaftar){
	//algoritma
	if(P == NULL || WDaftar > P->info.WSelesai){
		return WDaftar;
	}else return P->info.WSelesai;
}

/*** MANAJEMEN MENU NAVIGASI ***/
/* Menampilkan menu login.
   I.S. Layar kosong.
   F.S. Tampilan main menu.
*/ 
void MenuLogin (Queue Q){
	//deklarasi
	int choice;
	
	//algoritma
	//menampilkan menu login selama user belum login
	do { 
		system ("cls");
		printf ("===========================================\n");
		printf ("||      APLIKASI LAYANAN DOKTER HEWAN    ||\n");
		printf ("||              --LOGIN--                ||\n");
		printf ("===========================================\n");
		printf ("||Login sebagai :                        ||\n");
		printf ("||1. Pelanggan                           ||\n");
		printf ("||2. Dokter                              ||\n");
		printf ("||                                       ||\n");
		printf ("===========================================\n\n");
		printf ("Pilihan Anda : "); scanf("%d", &choice);
		
		switch (choice){
			case 1 : MenuPelanggan(Q); break;
			case 2 : MenuDokter(Q); break;
			default: printf("Wrong input menu, please try again . . .\n"); fflush(stdin); break;
		}
		system ("pause");
	} while (choice != 1 && choice !=2); 
}

/* Menampilkan menu pelanggan.
   I.S. Layar kosong.
   F.S. Tampilan menu pelanggan.
*/ 
void MenuPelanggan (Queue Q){
	//deklarasi
	int choice;
	
	//algoritma
	//menampilkan menu pelanggan selama user tidak memilih exit
	do {
		system("cls");
		printf ("===========================================\n");
		printf ("||      APLIKASI LAYANAN DOKTER HEWAN    ||\n");
		printf ("||              --PELANGGAN--            ||\n");
		printf ("===========================================\n");
		printf ("||1. Daftar                              ||\n");
		printf ("||2. Lihat Antrian                       ||\n");
		printf ("||3. Back                                ||\n");
		printf ("||4. Exit                                ||\n");
		printf ("||                                       ||\n");
		printf ("===========================================\n\n");
		printf ("Pilihan Anda : "); scanf("%d", &choice);
		
		switch (choice){
			case 1 	: DaftarAntrian(&Q); break;
			case 2 	: PrintAntrian(Q); break;
			case 3	: MenuLogin (Q); break;
			case 4 	: exit(0);
			default : printf ("Wrong input menu, please try again . . .\n"); break;
		}
		system ("pause");
	} while (choice!=3);
}

/* Menampilkan menu dokter.
   I.S. Layar kosong.
   F.S. Tampilan menu dokter.
*/ 
void MenuDokter(Queue Q){
	//deklarasi
	int choice;
	infotype Data;
	
	//algoritma
	//menampilkan menu dokter selama user tidak memilih exit
	do {
		system ("cls");
		printf ("===========================================\n");
		printf ("||      APLIKASI LAYANAN DOKTER HEWAN    ||\n");
		printf ("||              --DOKTER--               ||\n");
		printf ("===========================================\n");
		printf ("||1. Lihat Antrian                       ||\n");
		printf ("||2. Panggil Antrian                     ||\n");
		printf ("||3. Back                                ||\n");
		printf ("||4. Exit                                ||\n");
		printf ("||                                       ||\n");
		printf ("===========================================\n\n");
		printf ("Pilihan Anda : "); scanf("%d", &choice);
		
		switch (choice){
			case 1 	: PrintAntrian(Q); break;
			case 2 	: MulaiService(&Q, &Data); break;
			case 3 	: MenuLogin (Q); break;
			case 4 	: exit(0);
			default : printf ("Wrong input menu, please try again . . .\n"); fflush(stdin); break;
		}
		system ("pause");
	} while (choice!=3);
}

/*** MANAJEMEN FITUR ***/
/* Memasukkan info pelanggan vet service.
   I.S. info pelanggan vet service masih kosong.
   F.S. info pelanggan vet service sudah terisi.
*/ 
void DaftarAntrian (Queue *Q){
	//deklarasi
	infotype Info;

	//algoritma
	system ("cls");
	printf ("===========================================\n");
	printf ("||      APLIKASI LAYANAN DOKTER HEWAN    ||\n");
	printf ("||              --PENDAFTARAN--          ||\n");
	printf ("===========================================\n");
	//mendata informasi pelanggan
	printf ("Nama Hewan	: "); scanf("%s", &Info.nama); fflush(stdin);
	printf ("Waktu Datang 	: "); scanf("%d", &Info.WDatang); fflush(stdin);
	printf ("Jumlah Penyakit : "); scanf("%d", &Info.jumlahPenyakit); fflush(stdin);
	InputPenyakit(Info.jumlahPenyakit, &Info);
	
	Info.kategori = KategoriPenyakit(Info.penyakit);
	Info.WService = HitungWaktuService(Info.kategori);
	Info.prioritas = Prioritas(Info.jumlahPenyakit, Info.kategori);
	
	//mengurutkan antrian baru berdasarkan prioritas atau waktu datang
	UrutAntrian(Q, Info);
}

/* Memasukkan info penyakit dari hewan sesuai jumlah penyakit.
   I.S. info penyakit masih kosong.
   F.S. info penyakit sudah terisi.
*/ 
void InputPenyakit (int JumlahPenyakit, infotype *x){
	//deklarasi
	Sakit sakit;
	
	//algoritma
	if (JumlahPenyakit == 3){
		printf ("Penyakit 1	: "); scanf("%s", &sakit.penyakit1); fflush(stdin);
		printf ("Penyakit 2	: "); scanf("%s", &sakit.penyakit2); fflush(stdin);
		printf ("Penyakit 3	: "); scanf("%s", &sakit.penyakit3); fflush(stdin);
	}else if (JumlahPenyakit == 2){
		printf ("Penyakit 1	: "); scanf("%s", &sakit.penyakit1); fflush(stdin);
		printf ("Penyakit 2	: "); scanf("%s", &sakit.penyakit2); fflush(stdin);
	}else if (JumlahPenyakit == 1){
		printf ("Penyakit 1	: "); scanf("%s", &sakit.penyakit1); fflush(stdin);
	}
	
	(*x).penyakit = sakit;
}

/* Menampilkan info pelanggan vet service.
   I.S. info pelanggan vet service belum ditampilkan.
   F.S. info pelanggan vet service sudah ditampilkan.
*/ 
void PrintAntrian (Queue Q){
	//deklarasi
	addrNQ temp;
	int i;
	
	//algoritma
	system ("cls");
	printf ("===========================================\n");
	printf ("||      APLIKASI LAYANAN DOKTER HEWAN    ||\n");
	printf ("||           --DAFTAR ANTRIAN--          ||\n");
	printf ("===========================================\n");
	
	temp = Q.front;
	i=0;
	
	if (temp == NULL){
		printf ("Antrian Masih Kosong\n\n");
	}
	
	while (temp != NULL){
		printf("%d\n", ++i); //print nomor antrian
		printf ("Nama Hewan		: %s\n", temp->info.nama);
		printf ("Waktu Kedatangan	: %d\n", temp->info.WDatang);
		
		//print penyakit sesuai jumlah penyakit
		if (temp->info.jumlahPenyakit==3){
			printf ("Penyakit		: %s - %s - %s\n", temp->info.penyakit.penyakit1, 
			temp->info.penyakit.penyakit2, temp->info.penyakit.penyakit3);
		} else if (temp->info.jumlahPenyakit==2){
				printf ("Penyakit		: %s - %s\n", temp->info.penyakit.penyakit1, 
				temp->info.penyakit.penyakit2);
		} else if (temp->info.jumlahPenyakit==1){
				printf ("Penyakit		: %s\n", temp->info.penyakit.penyakit1);
		}
		
		printf ("Kategori Penyakit	: %s\n", temp->info.kategori);
		printf ("Waktu Pelayanan		: %d\n", temp->info.WService);
		printf ("Waktu Tunggu		: %d\n", temp->info.WTunggu);
		printf ("Waktu Mulai		: %d\n", temp->info.WMulai);
		printf ("Waktu Selesai		: %d\n\n\n", temp->info.WSelesai);
		temp=(*temp).next;
	}
}

/* Mengembalikan kategori penyakit dari 
   penyakit-penyakit yang diinputkan.
*/
char* KategoriPenyakit (Sakit sakit){
	//algoritma
	//mengecek apakah ada penyakit tertentu di dalam penyakit pelanggan
	char *PenyakitRingan = "kutu bersin demam";
	char *Ringan = sakit.penyakit1;
	char *kategori1 = strstr(PenyakitRingan, Ringan);
	
	char *PenyakitSedang = "cacingan diare rabies";
	char *Sedang = sakit.penyakit1;
	char *kategori2 = strstr(PenyakitSedang, Sedang);
	
	char *PenyakitBerat = "radang infeksi kuning";
	char *Berat = sakit.penyakit1;
	char *kategori3 = strstr(PenyakitBerat, Berat);
	
	//mengambilkan jenis kategori penyakit sesuai penyakit yang dialami
	if(kategori1){
	    return "Ringan";
	}else if (kategori2){
		return "Sedang";
	}else if (kategori3){
		return "Berat";
	}
}

/* Mengembalikan nilai prioritas berdasarkan 
   parameter prioritas.
*/
int Prioritas (int JumlahPenyakit, char Kategori[]){
	//algoritma
	if(strcmp(Kategori, "Ringan") == 0){
		if (JumlahPenyakit>=3){
			return 2;
		}
	}else if(strcmp(Kategori, "Sedang") == 0){
		if (JumlahPenyakit>=2){
			return 3;
		}
	}else if(strcmp(Kategori, "Berat") == 0){
		if (JumlahPenyakit>=1){
			return 4;
		}
	}else return 1;
}

/* Megurutkan daftar antrian sesuai waktu dan prioritas
   I.S. Antrian belum terurut.
   F.S. Antrian sudah terurut.
*/
void UrutAntrian (Queue *Q, infotype Info){
	//deklarasi
	addrNQ NewNode, x;
	int swap = 0;
	
	//algoritma
	NewNode = Alokasi(Info);
	x = (*Q).front;
	
	//jika antrian tidak kosong dan belum ditukar maka dicek dulu
	while (x != NULL && swap != 1){ 
		if (Info.prioritas > x->info.prioritas){
			UbahAntrian (Q, NewNode, x);
			swap=1;
		} else if (Info.prioritas == x->info.prioritas){
			if (Info.WDatang < x->info.WDatang){
				UbahAntrian (Q, NewNode, x);
				swap=1;	
			} else x = (*x).next;
		} else x = (*x).next;
	}
	
	/*jika antrian kosong atau nilai prioritasnya tidak lebih besar 
	dari yang ada maka langsung masuk ke antrian*/
	if(x == NULL){	
		Info.WTunggu = HitungWaktuTunggu1 ((*Q).rear, Info.WDatang);
		Info.WMulai = HitungWaktuMulai((*Q).rear, Info.WDatang);
		Info.WSelesai = HitungWaktuSelesai (Info);
		Antrian (Q, Info);
	}	
}

/* Mengubah urutan antrian apabila ada antrian yang diprioritaskan
   I.S. Antrian belum diubah.
   F.S. Antrian sudah diubah.
*/
void UbahAntrian (Queue *Q, addrNQ NewNode, addrNQ x){
	//deklarasi
	addrNQ temp; //pointer untuk menunjuk ke node sebelum node x
	int done;
	
	//algoritma
	temp = (*Q).front;
	
	//jika node yang akan didahului adalah node pertama
	if (x == (*Q).front){
		(*NewNode).next = x;
		(*Q).front = NewNode;
	}

	else {
		//agar temp menunjuk ke node sebelum node x
		while ((*temp).next != x){
			temp = (*temp).next;
		}
		(*temp).next = NewNode;
		(*NewNode).next= x;	
	} 

	//menghitung ulang waktu pelayanan setelah terjadi pengubahan antrian
	while (NewNode != NULL ){
		if (NewNode == (*Q).front && done !=1){
			temp = (*Q).front;
			NewNode->info.WTunggu = 0;
			NewNode->info.WMulai = NewNode->info.WDatang;
			NewNode->info.WSelesai = HitungWaktuSelesai (NewNode->info);
			NewNode = (*NewNode).next;
			done = 1;
		}
		else {
			NewNode->info.WTunggu = HitungWaktuTunggu2 (temp, NewNode->info.WDatang);
			NewNode->info.WMulai = temp->info.WSelesai;
			NewNode->info.WSelesai = HitungWaktuSelesai (NewNode->info);
			NewNode = (*NewNode).next;
			temp =(*temp).next;
		}
	}
}

/* Menampilkan tata cara penggunaan aplikasi.
   I.S. Layar kosong.
   F.S. Tampilan tata cara penggunaan aplikasi.
   author 		: M.Fauzi 
   modifikasi	: Syahda Afia
*/
void HowToUse (){
	//deklarasi
	FILE *fp;
	char c;
	
	//algoritma
	system("cls");
	fp = fopen(HOW_TO_USE, "r");
	
	if(fp != NULL)
	{
		while(!feof(fp)){
			c = fgetc(fp);
			printf("%c", c); //menampilkan text pada file ke layar
		}
		fclose(fp);
	}else if(fp == NULL){
		printf("Unable To Create the file \n\n");
	}
}
