/*
	Program		: VetService.h
	Author		: Muhammad Faza Hardiansyah (201524016)
				  Muhammad Fikri Hidayatulloh (201524017)
				  Syahda Afia Dhiya Ulhaq Tajudin (201524030)
	Kelompok	: A9
	Deskripsi	: Aplikasi layanan Dokter Hewan (mendata, menampilkan, dan memanggil antrian)
	Compiler	: DevC++ TDM-GCC 4.9.2 64-bit Release
*/

#ifndef VETSERVICE_H
#define VETSERVICE_H
#define HOW_TO_USE "howToUse.txt"

			/* Atribut ADT */
/*========================================*/
typedef struct NodeQueue *addrNQ;
typedef struct InfoPelangganVetService infotype;

typedef struct InfoPelangganVetService{
	char* nama;
	char penyakit[50];
	char* kategori;
	int jumlahPenyakit;
	int prioritas;
	int WDatang;
	int WTunggu;
	int WMulai;
	int WService;
	int WSelesai;
} InfoPelangganVetService;

typedef struct NodeQueue{
	infotype info;
	addrNQ next;	
} NodeQueue;

typedef struct Queue{
	addrNQ front;
	addrNQ rear;
}Queue;

		   	/* Operasi ADT */
/*========================================*/

/*** MANAJEMEN MEMORI ***/
/* Mengirimkan address hasil alokasi sebuah elemen dengan info X.
   Jika alokasi berhasil, modul mengembalikan P; P->info = X, = NULL.
   P adalah pointer yang menunjuk ke node Queue sebagai hasil alokasi.
   Jika alokasi gagal, modul mengembalikan NULL.
 */
addrNQ Alokasi (infotype X);

/* Melakukan dealokasi elemen P (pointer menunjuk ke alamat node queue).
   I.S.: P terdefinisi.
   F.S.: P dikembalikan ke sistem.
 */
void Dealokasi (addrNQ *P);

/*** Manajemen Queue ***/
/* Membuat sebuah Queue kosong dengan Q.fornt = NULL dan Q.rear = NULL. 
   I.S. Belum terbentuk Queue 
   F.S. Sudah terbentuk Queue
*/
void BuatAntrian (Queue *Q);

/* Mengetahui apakah Queue kosong atau tidak. 
   mengirimkan 1, jika Queue kosong yaitu Q.front = NULL dan Q.rear = NULL.
   mengirimkan 0, jika Queue tidak kosong.
*/
int CekAntrianKosong (Queue Q);

/* Memasukkan info baru ke dalam Queue dengan aturan FIFO.
   I.S. Q mungkin kosong atau Q mungkin berisi antrian.
   F.S. info baru telah masuk ke dalam Queue.
*/ 
void Antrian (Queue *Q, infotype data);

/* Menghapus node dari Queue dengan aturan FIFO .
   I.S. Q mungkin kosong atau Q mungkin berisi antrian.
   F.S. Node sudah terhapus.
*/ 
void MulaiService (Queue *Q, infotype *data);


/*** MANAJEMEN WAKTU ***/
/* Menghitung waktu service sesuai dengan kategori penyakit.
   if penyakit ... return ...
*/
int HitungWaktuService (char* data);

/* Menghitung waktu selesai layanan. 
   Mengembalikan hasil dari WDatang + WTunggu + WService.
*/
int HitungWaktuSelesai (infotype data);

/* Menghitung waktu tunggu layanan.
   Mengembalikan hasil dari WSelesai (Node sebelumnya)- WDaftar.
*/
int HitungWaktuTunggu ();

/* Menghitung waktu tunggu layanan .
   Mengembalikan hasil dari WDatang + WTunggu.
*/
int HitungWaktuMulai (infotype data);

/*** MANAJEMEN MENU NAVIGASI ***/
/* Menampilkan menu login.
   I.S. Layar kosong.
   F.S. Tampilan main menu.
*/ 
void MenuLogin ();

/* Menampilkan menu pelanggan.
   I.S. Layar kosong.
   F.S. Tampilan menu pelanggan.
*/ 
void MenuPelanggan ();

/* Menampilkan menu dokter.
   I.S. Layar kosong.
   F.S. Tampilan menu dokter.
*/ 
void MenuDokter();

/*** MANAJEMEN FITUR ***/
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

/* Mengembalikan kategori penyakit dari 
   penyakit-penyakit yang diinputkan.
*/
char* KategoriPenyakit (addrNQ New);

/* Mengembalikan nilai prioritas berdasarkan 
   parameter prioritas.
*/
int Prioritas (int JumlahPenyakit, char* Kategori);

/* Megurutkan daftar antrian sesuai waktu dan prioritas
   I.S. Antrian belum terurut.
   F.S. Antrian sudah terurut.
*/
void UrutAntrian ();

/* Menukar urutan antrian apabila ada antrian yang diprioritaskan
   I.S. Antrian belum ditukar.
   F.S. Antrian sudah ditukar.
*/
void TukarAntrian (Queue *Q, addrNQ Nu, addrNQ ex);

/* Menampilkan tata cara penggunaan aplikasi.
   I.S. Layar kosong.
   F.S. Tampilan tata cara penggunaan aplikasi.
*/
void HowToUse ();

/* Mengubah semua huruf menjadi kapital.
   I.S. huruf bisa jadi kecil bisa jadi kapital.
   F.S. huruf kapital semua.
*/
void toUpperStr(char str[]);
#endif
