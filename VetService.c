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
	addrNQ New;
	New = (addrNQ)malloc(sizeof(NodeQueue));
	if (New != NULL){
		New->info = X;
		New->next = NULL;
		return New;
	} else return NULL;
}

/* Melakukan dealokasi elemen P (pointer menunjuk ke alamat node queue).
   I.S.: P terdefinisi.
   F.S.: P dikembalikan ke sistem.
 */
void Dealokasi (addrNQ *P){
	free(*P);
}

/*** Manajemen Queue ***/
/* Membuat sebuah Queue kosong dengan Q.fornt = NULL dan Q.rear = NULL. 
   I.S. Belum terbentuk Queue 
   F.S. Sudah terbentuk Queue
*/
void BuatAntrian (Queue *Q){
	(*Q).front = NULL;
	(*Q).rear = NULL;
}

/* Mengetahui apakah Queue kosong atau tidak. 
   mengirimkan 1, jika Queue kosong yaitu Q.front = NULL dan Q.rear = NULL.
   mengirimkan 0, jika Queue tidak kosong.
*/
int CekAntrianKosong (Queue Q){
	if(Q.front == NULL){
		return 1;
	} else return 0;
}

/* Memasukkan info baru ke dalam Queue dengan aturan FIFO.
   I.S. Q mungkin kosong atau Q mungkin berisi antrian.
   F.S. info baru telah masuk ke dalam Queue.
*/ 
void Antrian (Queue *Q, infotype data){
	addrNQ P;
	
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
	addrNQ P;
	
	(*data)=(*Q).front->info;
	P=(*Q).front;
	
	if (CekAntrianKosong(*Q)==0){
		(*Q).front = (*Q).front->next;
		P->next=NULL;
	}else printf ("Antrian Kosong");
}

/*** MANAJEMEN WAKTU ***/
/* Menghitung waktu service.
   Mengembalikan waktu service sesuai dengan kategori penyakit.
*/
int HitungWaktuService (char* data){
	if(strcmp(data, "Ringan")==0){
		return 15;
	}else if(strcmp(data, "Sedang")== 0){
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

/* Menghitung waktu tunggu layanan.
   Mengembalikan hasil dari WSelesai (Node sebelumnya)- WDaftar.
*/
int HitungWaktuTunggu (){
	
}

/* Menghitung waktu tunggu layanan .
   Mengembalikan hasil dari WDatang + WTunggu.
*/
int HitungWaktuMulai (infotype data){
	return data.WDatang + data.WTunggu;
}


/*** MANAJEMEN MENU NAVIGASI ***/
/* Menampilkan menu login.
   I.S. Layar kosong.
   F.S. Tampilan main menu.
*/ 
void MenuLogin (){
	int choice;
	
	do {
	system ("cls");
	printf ("=======================================\n");
	printf ("      APLIKASI LAYANAN DOKTER HEWAN    \n");
	printf ("              --LOGIN--                \n");
	printf ("=======================================\n");
	printf ("Login sebagain :\n");
	printf ("1. Pelanggan\n");
	printf ("2. Dokter\n\n");
	printf ("Pilihan Anda : "); scanf("%d", &choice);
	
	switch (choice){
		case 1 : MenuPelanggan(); break;
		case 2 : MenuDokter(); break;
		default: printf("Wrong input menu, please try again . . .\n"); break;
	}
	system ("pause");
	system ("cls");
	} while (choice != 1 && choice !=2);
}

/* Menampilkan menu pelanggan.
   I.S. Layar kosong.
   F.S. Tampilan menu pelanggan.
*/ 
void MenuPelanggan (){
	int choice;
	Queue q;
	
	do {
	system ("cls");
	printf ("=======================================\n");
	printf ("      APLIKASI LAYANAN DOKTER HEWAN    \n");
	printf ("              --PELANGGAN--            \n");
	printf ("=======================================\n");
	printf ("1. Pendaftaran\n");
	printf ("2. Lihat Antrian\n");
	printf ("3. Exit\n\n");
	printf ("Pilihan Anda : "); scanf("%d", &choice);
	
	switch (choice){
		case 1 : DaftarAntrian(&q); break;
		case 2 : PrintAntrian(q); break;
		case 3 : break;
		default : printf ("Wrong input menu, please try again . . .\n"); break;
		}
		system ("pause");
	} while (choice!=3);
}

/* Menampilkan menu dokter.
   I.S. Layar kosong.
   F.S. Tampilan menu dokter.
*/ 
void MenuDokter(){
	int choice;
	Queue q;
	infotype Data;
	
	do {
	system ("cls");
	printf ("=======================================\n");
	printf ("      APLIKASI LAYANAN DOKTER HEWAN    \n");
	printf ("              --DOKTER--               \n");
	printf ("=======================================\n");
	printf ("1. Lihat Antrian\n");
	printf ("2. Panggil Antrian\n");
	printf ("3. Exit\n\n");
	printf ("Pilihan Anda : "); scanf("%d", &choice);
	
	switch (choice){
		case 1 : PrintAntrian(q); break;
		case 2 : MulaiService(&q,&Data); break;
		case 3 : break;
		default : printf ("Wrong input menu, please try again . . .\n"); break;
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
	infotype Info;
	addrNQ New;
	
	New = Alokasi(Info);
	system ("cls");
	printf ("=======================================\n");
	printf ("      APLIKASI LAYANAN DOKTER HEWAN    \n");
	printf ("              --PENDAFTARAN--          \n");
	printf ("=======================================\n");
	printf ("Nama Hewan	: "); scanf("%s", &Info.nama); fflush(stdin);
	printf ("Waktu Datang	: "); scanf("%d", &Info.WDatang); fflush(stdin);
	printf ("Jumlah Penyakit	: "); scanf("%d", &Info.jumlahPenyakit); 
	printf ("Penyakit	: "); scanf("%s", &Info.penyakit); 
	
	Info.kategori = KategoriPenyakit(New);
	Info.WService = HitungWaktuService(Info.kategori);
	Info.prioritas = Prioritas(Info.jumlahPenyakit, Info.kategori);
	UrutAntrian();
}

/* Menampilkan info pelanggan vet service.
   I.S. info pelanggan vet service belum ditampilkan.
   F.S. info pelanggan vet service sudah ditampilkan.
*/ 
void PrintAntrian (Queue Q){
	addrNQ P;
	
	system ("cls");
	printf ("=======================================\n");
	printf ("      APLIKASI LAYANAN DOKTER HEWAN    \n");
	printf ("           --DAFTAR ANTRIAN--          \n");
	printf ("=======================================\n");
	
	P=Q.front;
	while (P!=NULL){
		printf ("Nama Hewan : %s\n", P->info.nama);
		printf ("Waktu Kedatangan : %d\n", P->info.WDatang);
		printf ("Penyakit : %s\n", P->info.penyakit);
		printf ("Kategori Penyakit : %s", P->info.kategori);
		printf ("Waktu Pelayanan : %d\n", P->info.WService);
		printf ("Waktu Mulai : %d\n", P->info.WMulai);
		printf ("Waktu Selesai : %d\n\n\n", P->info.WSelesai);
		P=(*P).next;
	}
}

/* Mengembalikan kategori penyakit dari 
   penyakit-penyakit yang diinputkan.
*/
 char* KategoriPenyakit (addrNQ New){
 	toUpperStr(New->info.kategori);
 	
 	char *sent = New->info.kategori;
	char *kulit = "PENYAKIT KULIT";
	char *satu = strstr(sent, kulit);
	char *bersin = "BERSIN";
	char *dua = strstr(sent, bersin);
	char *lukaR = "LUKA RINGAN";
	char *tiga = strstr(sent, lukaR);
	
	char *cacingan = "CACINGAN";
	char *empat = strstr(sent, cacingan);
	char *diare = "DIARE";
	char *lima = strstr(sent, diare);
	char *lukaD = "LUKA DALAM";
	char *enam = strstr(sent, lukaD);
	
	char *gangguan = "GANGGUAN KERONGKONGAN";
	char *tujuh = strstr(sent, gangguan);
	char *virus = "TERKENA VIRUS";
	char *delapan = strstr(sent, virus);
	char *kuning = "KUNING";
	char *sembilan = strstr(sent, kuning);

	if(satu || dua || tiga){
		return "Ringan";
	} else if (empat || lima || enam){
		return "Sedang";
	} else if (tujuh || delapan || sembilan){
		return ("Berat");
	}
}

/* Mengembalikan nilai prioritas berdasarkan 
   parameter prioritas.
*/
int Prioritas (int JumlahPenyakit, char* Kategori){
	if(Kategori=="Ringan" && JumlahPenyakit>=3){
		return 2;
	}else if (Kategori=="Sedang" && JumlahPenyakit>=2){
		return 3;
	}else if (Kategori=="Berat" && JumlahPenyakit>=1){
		return 4;
	}else return 1;
}

/* Megurutkan daftar antrian sesuai waktu dan prioritas
   I.S. Antrian belum terurut.
   F.S. Antrian sudah terurut.
*/
void UrutAntrian (Queue *Q, addrNQ New){
	addrNQ x;
	infotype Info;
	
	x = (*Q).front;
	while (x != NULL){
		if (New->info.prioritas > x->info.prioritas){
			if (New->info.WDatang < x->info.WMulai){
				TukarAntrian (Q, New, x);
			} else x = (*x).next;
		} else if (New->info.prioritas == x->info.prioritas){
			if (New->info.WDatang < x->info.WMulai){
				TukarAntrian (Q, New, x);
			} else x = (*x).next;
		} else (*x).next;
	}
	
	New->info.WMulai = HitungWaktuMulai (Info);
	New->info.WTunggu = HitungWaktuTunggu ();
	New->info.WSelesai = HitungWaktuSelesai (Info);
	Antrian (Q, Info);
}

/* Menukar urutan antrian apabila ada antrian yang diprioritaskan
   I.S. Antrian belum ditukar.
   F.S. Antrian sudah ditukar.
*/
void TukarAntrian (Queue *Q, addrNQ Nu, addrNQ ex){
	addrNQ temp;
	
	temp = (*Q).front;
	while ((*temp).next != ex){
		temp = (*temp).next;
	}
	
	(*temp).next = Nu;
	(*Nu).next= ex;
	
	temp = (*Q).front;
	while (temp != NULL){
		temp->info.WTunggu = HitungWaktuTunggu ();
		temp->info.WMulai = HitungWaktuMulai (temp->info);
		temp->info.WSelesai = HitungWaktuSelesai (temp->info);
		temp = (*temp).next;
	}
}

/* Menampilkan tata cara penggunaan aplikasi.
   I.S. Layar kosong.
   F.S. Tampilan tata cara penggunaan aplikasi.
*/
void HowToUse (){
	system("cls");
	FILE *fp = fopen(HOW_TO_USE, "r");
	char c;
	
	if(fp != NULL)
	{
		while(!feof(fp))
		{
			c = fgetc(fp);
			printf("%c", c);
		}
	
		fclose(fp);
	}else if(fp == NULL)
		printf("Unable To Create the file \n\n\n");
}

/* Mengubah semua huruf menjadi kapital.
   I.S. huruf bisa jadi kecil bisa jadi kapital.
   F.S. huruf kapital semua.
*/
void toUpperStr(char str[]){
    int i;
    for(i = 0; str[i]!='\0'; i++){
        if(str[i]>='a' && str[i]<='z')
        {
            str[i] = str[i] - 32;
        }
    }
}
