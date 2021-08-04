/*
	Program		: queue.c
	Author		: Muhammad Faza Hardiansyah (201524016)
				  Muhammad Fikri Hidayatulloh (201524017)
				  Syahda Afia Dhiya Ulhaq Tajudin (201524030)
	Kelompok	: A9
	Deskripsi	: Aplikasi layanan Dokter Hewan (mendata, menampilkan, dan memanggil antrian)
	Compiler	: DevC++ TDM-GCC 4.9.2 64-bit Release
*/

#include "VetService.h"
#include "queue.h"
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
   Author : M.Fikri Hidayatulloh.
 */
addrNQ Alokasi (infotype X){
	//deklarasi
	addrNQ P;
	
	//algoritma
	P = (addrNQ)malloc(sizeof(NodeQueue)); //memesan tempat di memori sebesar Node Queue (1 antrian)
	if (P != NULL){ //jika alokasi berhasil
		P->info = X; 
		P->next = NULL;
		return P;
	} else return NULL; //jika alokasi gagal
}

/* Melakukan dealokasi elemen P (pointer menunjuk ke alamat node queue).
   I.S.: P terdefinisi.
   F.S.: P dikembalikan ke sistem.
   Author : M.Fikri Hidayatulloh.
 */
void Dealokasi (addrNQ *P){
	//algoritma
	free(*P); //membebaskan pointer P
}


/*** Manajemen Queue ***/
/* Membuat sebuah Queue kosong dengan Q.fornt = NULL dan Q.rear = NULL. 
   I.S. Belum terbentuk Queue 
   F.S. Sudah terbentuk Queue
   Author : M.Fikri Hidayatulloh.
*/
void BuatAntrian (Queue *Q){
	//algoritma
	//belum ada antrian (antrian masih kosong)
	(*Q).front = NULL; 
	(*Q).rear = NULL;
}

/* Mengetahui apakah Queue kosong atau tidak. 
   mengirimkan 1, jika Queue kosong yaitu Q.front = NULL dan Q.rear = NULL.
   mengirimkan 0, jika Queue tidak kosong.
   Author : M.Fikri Hidayatulloh.
*/
int CekAntrianKosong (Queue Q){
	//algoritma
	if(Q.front == NULL){ //jika belum ada antrian atau antrian kosong
		return 1;
	} else return 0; //jika sudah ada antrian atau antrian tidak kosong
}

/* Memasukkan info baru ke dalam Queue dengan aturan FIFO.
   I.S. Q mungkin kosong atau Q mungkin berisi antrian.
   F.S. info baru telah masuk ke dalam Queue.
   Author : M.Fikri Hidayatulloh.
*/ 
void MasukAntrian (Queue *Q, infotype data){
	//deklarasi
	addrNQ P;
	
	//algoritma
	P = Alokasi(data); //memesan tempat di memori untuk antrian baru
	if (CekAntrianKosong(*Q) == 1){ //jika antrian masih kosong
		(*Q).front = P;
		(*Q).rear = P;
	} else { //jika antrian tidak kosong
		(*Q).rear->next = P;
		(*Q).rear = P;
	}
}

/* Menghapus node dari Queue dengan aturan FIFO .
   I.S. Q mungkin kosong atau Q mungkin berisi antrian.
   F.S. Node sudah terhapus.
   Author : Syahda Afia.
*/ 
void MulaiService (Queue *Q){
	//deklarasi
	addrNQ P;
	
	//algoritma
	PrintPanggilAntrian();
	
	if ((*Q).front == NULL){ //jika belum ada antrian
		printf ("Antrian Masih Kosong\n\n");
	}else { //jika sudah ada antrian
		printf("Antrian dengan nama %s sudah dipanggil \n\n", (*Q).front->info.nama);
		if ((*Q).front == (*Q).rear){ //jika antrian hanya satu
			P = (*Q).front;
			(*Q).rear = (*Q).rear->next;
			(*Q).front = (*Q).front->next;
			P->next = NULL;
		}else { //jika antrian lebih dari satu
			P = (*Q).front;
			(*Q).front = (*Q).front->next;
			P->next = NULL;
		}
	}
}

/* Megurutkan daftar antrian sesuai waktu dan prioritas
   I.S. Antrian belum terurut.
   F.S. Antrian sudah terurut.
   Author : Syahda Afia.
*/
void UrutAntrian (Queue *Q, infotype Info){
	//deklarasi
	addrNQ NewNode, x;
	int swap = 0;
	
	//algoritma
	NewNode = Alokasi(Info); //memesan tempat di memori untuk antrian baru
	x = (*Q).front;
	
	//mengecek nilai prioritas selama antrian tidak kosong dan belum ada perubahan antrian
	while (x != NULL && swap != 1){ 
		if (Info.prioritas > x->info.prioritas){ //jika nilai prioritas antrian baru > nilai prioritas antrian yang sudah ada
			if (Info.WDatang < x->info.WMulai){ //cek lagi jika antrian baru datang sebelum antrian yang sudah ada dimulai
				UbahAntrian (Q, NewNode, x);
				swap=1;
			}else x = (*x).next; //pindah ke antrian selanjutnya untuk mengecek kembali
		}else if (Info.prioritas == x->info.prioritas){ //jika nilai prioritas antrian baru = nilai prioritas antrian yang sudah ada
			if (Info.WDatang < x->info.WMulai){ //cek lagi jika antrian baru datang sebelum antrian yang sudah ada dimulai
				if (Info.WDatang < x->info.WDatang){ //cek lagi jika antrian baru datang sebelum antrian yang sudah ada datang
					UbahAntrian (Q, NewNode, x);
					swap=1;	
				}else x = (*x).next; //pindah ke antrian selanjutnya untuk mengecek kembali
			}else x = (*x).next; //pindah ke antrian selanjutnya untuk mengecek kembali
		}else x = (*x).next; //pindah ke antrian selanjutnya untuk mengecek kembali
	}
	
	/*jika antrian kosong atau nilai prioritasnya tidak lebih besar 
	dari antrian yang ada maka langsung masuk ke antrian*/
	if(x == NULL){	
		Info.WTunggu = HitungWaktuTunggu1 ((*Q).rear, Info.WDatang); //mendapatkan waktu tunggu antrian baru
		Info.WMulai = HitungWaktuMulai((*Q).rear, Info.WDatang); //mendapatkan waktu mulai antrian baru
		Info.WSelesai = HitungWaktuSelesai (Info); //mendapatkan waktu selesai antrian baru
		MasukAntrian (Q, Info); //memasukkan antrian baru ke dalam antrian
	}	
}

/* Mengubah urutan antrian apabila ada antrian yang diprioritaskan
   I.S. Antrian belum diubah.
   F.S. Antrian sudah diubah.
   Author : Syahda Afia.
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

	else { 	//jika node yang akan didahului bukan node pertama
		//agar temp menunjuk ke node sebelum node x
		while ((*temp).next != x){
			temp = (*temp).next;
		}
		(*temp).next = NewNode;
		(*NewNode).next= x;	
	} 

	//menghitung ulang waktu pelayanan setelah terjadi pengubahan antrian 
	while (NewNode != NULL ){
		if (NewNode == (*Q).front && done !=1){ //jika antrian baru merupakan antrian pertama dan belum dihitung waktu prosen layanan
			temp = (*Q).front;
			NewNode->info.WTunggu = 0; //menghitung ulang waktu tunggu
			NewNode->info.WMulai = NewNode->info.WDatang; //menghitung ulang waktu mulai
			NewNode->info.WSelesai = HitungWaktuSelesai (NewNode->info); //menghitung ulang waktu selesai
			NewNode = (*NewNode).next; //pindah ke antrian selanjutnya
			done = 1;
		}
		else { //jika antrian baru bukan antrian pertama 
			NewNode->info.WTunggu = HitungWaktuTunggu2 (temp, NewNode->info.WDatang); //menghitung ulang waktu tunggu
			NewNode->info.WMulai = HitungWaktuMulai(temp, NewNode->info.WDatang); //menghitung ulang waktu mulai
			NewNode->info.WSelesai = HitungWaktuSelesai (NewNode->info); //menghitung ulang waktu selesai
			NewNode = (*NewNode).next; //pindah ke antrian selanjutnya
			temp =(*temp).next; //pindah ke antrian selanjutnya
		}
	}
}
