/*
	Program		: VetService.c
	Author		: Muhammad Faza Hardiansyah (201524016)
				  Muhammad Fikri Hidayatulloh (201524017)
				  Syahda Afia Dhiya Ulhaq Tajudin (201524030)
	Kelompok	: A9
	Deskripsi	: Aplikasi layanan Dokter Hewan (mendata, menampilkan, dan memanggil antrian)
	Compiler	: DevC++ TDM-GCC 4.9.2 64-bit Release
*/

#include"VetService.h"
#include<stdio.h>


			/* Implementasi ADT */
/*========================================*/

/*** MANAJEMEN MEMORI ***/
/* Mengirimkan address hasil alokasi sebuah elemen dengan info X.
   Jika alokasi berhasil, modul mengembalikan P; P->info = X, = NULL.
   P adalah pointer yang menunjuk ke node Queue sebagai hasil alokasi.
   Jika alokasi gagal, modul mengembalikan NULL.
 */
addrNQ Alokasi (infotype X){
	addrNQ P;
	P = (addrNQ)malloc(sizeof(NodeQueue)):
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
	free(*p);
}

/*** Manajemen Queue ***/
/* Membuat sebuah Queue kosong dengan Q.fornt = NULL dan Q.rear = NULL. 
   I.S. Belum terbentuk Queue 
   F.S. Sudah terbentuk Queue
*/
void BuatAntrian (Queue *Q){
	Q.front = NULL;
	Q.rear = NULL;
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
		Q.front = P;
		Q.rear = P;
	} else {
		Q.rear.next = P;
		Q.rear = P;
	}
}

/* Menghapus node dari Queue dengan aturan FIFO .
   I.S. Q mungkin kosong atau Q mungkin berisi antrian.
   F.S. Node sudah terhapus.
*/ 
void MulaiService (Queue *Q, infotype *data);


/*** MANAJEMEN WAKTU ***/
/* Menghitung waktu service sesuai dengan kategori penyakit.
   if penyakit ... masuk ke kategori ... return ...
*/
int HitungWaktuService (infotype X);

/* Menghitung waktu selesai layanan. 
   Mengembalikan hasil dari WDatang + WTunggu + WService.
*/
int HitungWaktuSelesai (infotype X);

/* Menghitung waktu tunggu layanan.
   Mengembalikan hasil dari WSelesai (Node sebelumnya)- WDaftar.
*/
int HitungWaktuTunggu (addrNQ P, infotype X);

/* Menghitung waktu tunggu layanan .
   Mengembalikan hasil dari WDatang + WTunggu.
*/
int HitungWaktuMulai (infotype X);


/*** MANAJEMEN MENU ***/
/* Memasukkan info pelanggan vet service.
   I.S. info pelanggan vet service masih kosong.
   F.S. info pelanggan vet service sudah terisi.
*/ 
void DaftarAntrian (Queue *Q);

/* Menampilkan info pelanggan vet service.
   I.S. info pelanggan vet service belum ditampilkan.
   F.S. info pelanggan vet service sudah ditampilkan.
*/ 
void PrintAntrian (Queue Q);
