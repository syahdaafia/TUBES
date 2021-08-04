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
#include "queue.h"
#define HOW_TO_USE "howToUse.txt"

		   	/* Operasi ADT */
/*========================================*/

/*** MODUL PRINT MENU ***/
/* Menampilkan main menu.
   I.S. Layar kosong.
   F.S. Tampilan main menu.
   Author : M.Faza Hardiansyah.
*/ 
void PrintMainMenu ();

/* Menampilkan menu login.
   I.S. Layar kosong.
   F.S. Tampilan login.
   Author : M.Faza Hardiansyah.
*/ 
void PrintMenuLogin ();

/* Menampilkan menu pelanggan.
   I.S. Layar kosong.
   F.S. Tampilan menu pelanggan.
   Author : M.Faza Hardiansyah.
*/ 
void PrintMenuPelanggan ();

/* Menampilkan menu dokter.
   I.S. Layar kosong.
   F.S. Tampilan menu dokter.
   Author : M.Faza Hardiansyah.
*/ 
void PrintMenuDokter();

/* Menampilkan menu dokter.
   I.S. Layar kosong.
   F.S. Tampilan menu pendaftaran.
   Author : M.Faza Hardiansyah.
*/ 
void PrintMenuPendaftaran();

/* Menampilkan menu dokter.
   I.S. Layar kosong.
   F.S. Tampilan menu lihat antrian.
   Author : M.Faza Hardiansyah.
*/ 
void PrintMenuLihatAntrian();

/* Menampilkan menu panggil antrian.
   I.S. Layar kosong.
   F.S. Tampilan menu panggil antrian.
   Author : M.Faza Hardiansyah.
*/ 
void PrintPanggilAntrian();

/* Menampilkan penyakit yang dialami hewan.
   I.S. Layar kosong.
   F.S. Tampilan penyakit yang dialami hewan.
   Author : Syahda Afia.
*/ 
void PrintPenyakit(addrNQ temp);


/*** MANAJEMEN MENU ***/
/* Menjalankan halaman login.
   I.S. Tampilan menu login.
   F.S. Tampilan menu pelanggan/dokter.
   Author : Syahda Afia.
*/ 
void UserLogin (Queue Q);

/* Menjalankan halaman pelanggan.
   I.S. Tampilan menu pelanggan.
   F.S. Tampilan menu pendaftaran/daftar antrian/login/exit.
   Author : Syahda Afia.
*/ 
void TransaksiPelanggan (Queue Q);

/* Menampilkan halaman dokter.
   I.S. Tampilan menu dokter.
   F.S. Tampilan menu daftar antrian/panggil antrian/login/exit.
   Author : Syahda Afia.
*/ 
void TransaksiDokter(Queue Q);


/*** MANAJEMEN FITUR ***/
/* Memasukkan info pelanggan vet service.
   I.S. info pelanggan vet service masih kosong.
   F.S. info pelanggan vet service sudah terisi.
   Author : Syahda Afia.
*/ 
void DaftarAntrian (Queue *Q);

/* Memasukkan info penyakit dari hewan sesuai jumlah penyakit.
   I.S. info penyakit masih kosong.
   F.S. info penyakit sudah terisi.
   Author : Syahda Afia.
*/ 
void InputPenyakit (int JumlahPenyakit, infotype *x);

/* Menampilkan info pelanggan vet service.
   I.S. info pelanggan vet service belum ditampilkan.
   F.S. info pelanggan vet service sudah ditampilkan.
   Author : Syahda Afia.
*/ 
void LihatAntrian (Queue Q);

/* Mengembalikan kategori penyakit dari 
   penyakit-penyakit yang diinputkan.
   Author : Syahda Afia.
*/
char* KategoriPenyakit (Sakit sakit);

/* Mengembalikan nilai prioritas berdasarkan 
   parameter prioritas.
   Author : Syahda Afia.
*/
int Prioritas (int JumlahPenyakit, char Kategori[]);

/* Menampilkan tata cara penggunaan aplikasi.
   I.S. Layar kosong.
   F.S. Tampilan tata cara penggunaan aplikasi.
   author 		: M.Fauzi 
   modifikasi	: Syahda Afia
*/
void HowToUse ();


/*** MANAJEMEN WAKTU ***/
/* Menghitung waktu service sesuai dengan kategori penyakit.
   Mengembalikan waktu service sesuai dengan kategori penyakit.
   Author : Syahda Afia.
*/
int HitungWaktuService (int jumlahPenyakit, char kategori[]);

/* Menghitung waktu tunggu layanan apabila tidak ada pertukaran antrian.
   Mengembalikan hasil dari WSelesai (rear)- WDaftar.
   Author : Syahda Afia.
*/
int HitungWaktuTunggu1(addrNQ rear, int WDaftar);

/* Menghitung waktu tunggu layanan apabila ada pertukaran antrian.
   Mengembalikan hasil dari WSelesai (Node sebelumnya)- WDaftar.
   Author : Syahda Afia.
*/
int HitungWaktuTunggu2 (addrNQ temp, int WDaftar);

/* Menghitung waktu mulai layanan.
   Mengembalikan hasil dari Waktu Daftar atau Waktu Selesai node sebelumnya
   Author : Syahda Afia.
*/
int HitungWaktuMulai (addrNQ rear, int WDaftar);

/* Menghitung waktu selesai layanan. 
   Mengembalikan hasil dari WMulai + WService.
   Author : Syahda Afia.
*/
int HitungWaktuSelesai (infotype data);

#endif
