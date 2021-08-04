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
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

			/* Implementasi ADT */
/*========================================*/

/*** MODUL PRINT ***/
/* Menampilkan main menu.
   I.S. Layar kosong.
   F.S. Tampilan main menu.
   Author : M.Faza Hardiansyah.
*/ 
void PrintMainMenu (){
	printf ("===========================================\n");
	printf ("||      APLIKASI LAYANAN DOKTER HEWAN    ||\n");
	printf ("||              --MAIN MENU--            ||\n");
	printf ("===========================================\n");
	printf ("||1. Login                               ||\n");
	printf ("||2. How To Use                          ||\n");
	printf ("||3. Exit                                ||\n");
	printf ("||                                       ||\n");
	printf ("===========================================\n\n");
	printf ("Pilihan Anda : "); 
}

/* Menampilkan menu login.
   I.S. Layar kosong.
   F.S. Tampilan login.
   Author : M.Faza Hardiansyah.
*/ 
void PrintMenuLogin (){
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
	printf ("Pilihan Anda : "); 
}

/* Menampilkan menu pelanggan.
   I.S. Layar kosong.
   F.S. Tampilan menu pelanggan.
   Author : M.Faza Hardiansyah.
*/ 
void PrintMenuPelanggan (){
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
	printf ("Pilihan Anda : "); 	
}

/* Menampilkan menu dokter.
   I.S. Layar kosong.
   F.S. Tampilan menu dokter.
   Author : M.Faza Hardiansyah.
*/ 
void PrintMenuDokter(){
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
	printf ("Pilihan Anda : "); 
}

/* Menampilkan menu dokter.
   I.S. Layar kosong.
   F.S. Tampilan menu pendaftaran.
   Author : M.Faza Hardiansyah.
*/ 
void PrintMenuPendaftaran(){
	system ("cls");
	printf ("===========================================\n");
	printf ("||      APLIKASI LAYANAN DOKTER HEWAN    ||\n");
	printf ("||              --PENDAFTARAN--          ||\n");
	printf ("===========================================\n");
}

/* Menampilkan menu dokter.
   I.S. Layar kosong.
   F.S. Tampilan menu lihat antrian.
   Author : M.Faza Hardiansyah.
*/ 
void PrintMenuLihatAntrian(){
	system ("cls");
	printf ("===========================================\n");
	printf ("||      APLIKASI LAYANAN DOKTER HEWAN    ||\n");
	printf ("||           --DAFTAR ANTRIAN--          ||\n");
	printf ("===========================================\n");
}

/* Menampilkan menu panggil antrian.
   I.S. Layar kosong.
   F.S. Tampilan menu panggil antrian.
   Author : M.Faza Hardiansyah.
*/ 
void PrintPanggilAntrian(){
	system("cls");
	printf ("===========================================\n");
	printf ("||      APLIKASI LAYANAN DOKTER HEWAN    ||\n");
	printf ("||         --PEMANGGILAN ANTRIAN--       ||\n");
	printf ("===========================================\n");
}

/* Menampilkan penyakit yang dialami hewan.
   I.S. Layar kosong.
   F.S. Tampilan penyakit yang dialami hewan.
   Author : Syahda Afia.
*/ 
void PrintPenyakit(addrNQ temp){
	//algoritma
	if (temp->info.jumlahPenyakit==3){ //menampilkan 3 penyakit yang dialami hewan
		printf ("Penyakit		: %s - %s - %s\n", temp->info.penyakit.penyakit1, 
		temp->info.penyakit.penyakit2, temp->info.penyakit.penyakit3);
	} else if (temp->info.jumlahPenyakit==2){ //menampilkan 2 penyakit yang dialami hewan
		printf ("Penyakit		: %s - %s\n", temp->info.penyakit.penyakit1, 
		temp->info.penyakit.penyakit2);
	} else if (temp->info.jumlahPenyakit==1){ //menampilkan 1 penyakit yang dialami hewan
		printf ("Penyakit		: %s\n", temp->info.penyakit.penyakit1);
	}
}

/*** MODUL MENJALANKAN MENU ***/
/* Menjalankan halaman login.
   I.S. Tampilan menu login.
   F.S. Tampilan menu pelanggan/dokter.
   Author : Syahda Afia.
*/ 
void UserLogin (Queue Q){
	//deklarasi
	int choice;
	
	//algoritma
	//menampilkan menu login selama user belum login
	do { 
		PrintMenuLogin();
		scanf("%d", &choice); //menerima inputan pilihan login dari user
		
		switch (choice){
			case 1 : TransaksiPelanggan(Q); break; //masuk ke menu pelanggan
			case 2 : TransaksiDokter(Q); break; //masuk ke menu dokter
			default: printf("Wrong input menu, please try again . . .\n"); fflush(stdin); break; //jika input tidak sesuai
		}
		system ("pause");
	} while (choice != 1 && choice !=2); 
}

/* Menjalankan halaman pelanggan.
   I.S. Tampilan menu pelanggan.
   F.S. Tampilan menu pendaftaran/daftar antrian/login/exit.
   Author : Syahda Afia.
*/ 
void TransaksiPelanggan (Queue Q){
	//deklarasi
	int choice;
	
	//algoritma
	//menampilkan menu pelanggan selama user tidak memilih exit
	do {
		PrintMenuPelanggan();
		scanf("%d", &choice); //menerima inputan pilihan menu dari pelanggan
		
		switch (choice){
			case 1 	: DaftarAntrian(&Q); break; //masuk ke menu pendaftaran
			case 2 	: LihatAntrian(Q); break; //masuk ke menu lihat antrian
			case 3	: UserLogin (Q); break; //kembali ke main menu
			case 4 	: exit(0); //keluar dari program
			default : printf ("Wrong input menu, please try again . . .\n"); fflush(stdin); break; //jika input salah
		}
		system ("pause");
	} while (choice!=4);
}

/* Menampilkan halaman dokter.
   I.S. Tampilan menu dokter.
   F.S. Tampilan menu daftar antrian/panggil antrian/login/exit.
   Author : Syahda Afia.
*/ 
void TransaksiDokter(Queue Q){
	//deklarasi
	int choice;
	infotype Data;
	
	//algoritma
	//menampilkan menu dokter selama user tidak memilih exit
	do {
		PrintMenuDokter();
		scanf("%d", &choice); //menerima inputan pilihan menu dari pelanggan
		
		switch (choice){
			case 1 	: LihatAntrian(Q); break; //masuk ke menu lihat antrian
			case 2 	: MulaiService(&Q); break; //masuk ke menu panggil antrian
			case 3 	: UserLogin (Q); break; //kembali ke menu login
			case 4 	: exit(0); //keluar dari program
			default : printf ("Wrong input menu, please try again . . .\n"); fflush(stdin); break; //jika input salah
		}
		system ("pause");
	} while (choice!=4);
}

/*** MANAJEMEN FITUR ***/
/* Memasukkan info pelanggan vet service.
   I.S. info pelanggan vet service masih kosong.
   F.S. info pelanggan vet service sudah terisi.
   Author : Syahda Afia.
*/ 
void DaftarAntrian (Queue *Q){
	//deklarasi
	infotype Info;

	//algoritma
	PrintMenuPendaftaran();
	
	//mendata informasi pelanggan
	printf ("Nama Hewan	: ");		scanf("%s", &Info.nama); fflush(stdin); //menerima input nama hewan dari pelanggan
	printf ("Waktu Datang 	: ");	scanf("%d", &Info.WDatang); fflush(stdin); //menerima input waktu datang dari pelanggan
	printf ("Jumlah Penyakit : ");	scanf("%d", &Info.jumlahPenyakit); fflush(stdin); //menerima input jumlah penyakit dari pelanggan
	InputPenyakit(Info.jumlahPenyakit, &Info); //menerima input penyakit yang dialami hewan dari pelanggan
	
	Info.kategori = KategoriPenyakit(Info.penyakit); //mendapatkan kategori dari penyakit yang dialami
	Info.WService = HitungWaktuService(Info.jumlahPenyakit, Info.kategori); //mendapat waktu service yang dibutuhkan
	Info.prioritas = Prioritas(Info.jumlahPenyakit, Info.kategori); //mendapat nilai prioritas
	
	//mengurutkan antrian baru berdasarkan prioritas atau waktu datang
	UrutAntrian(Q, Info);
}

/* Memasukkan info penyakit dari hewan sesuai jumlah penyakit.
   I.S. info penyakit masih kosong.
   F.S. info penyakit sudah terisi.
   Author : Syahda Afia.
*/ 
void InputPenyakit (int JumlahPenyakit, infotype *x){
	//deklarasi
	Sakit sakit;
	
	//algoritma
	if (JumlahPenyakit == 3){ //menerima 3 input penyakit yang dialami hewan
		printf ("Penyakit 1	: "); scanf("%s", &sakit.penyakit1); fflush(stdin);
		printf ("Penyakit 2	: "); scanf("%s", &sakit.penyakit2); fflush(stdin);
		printf ("Penyakit 3	: "); scanf("%s", &sakit.penyakit3); fflush(stdin);
	}else if (JumlahPenyakit == 2){ //menerima 2 input penyakit yang dialami hewan
		printf ("Penyakit 1	: "); scanf("%s", &sakit.penyakit1); fflush(stdin);
		printf ("Penyakit 2	: "); scanf("%s", &sakit.penyakit2); fflush(stdin);
	}else if (JumlahPenyakit == 1){ //menerima 1 input penyakit yang dialami hewan
		printf ("Penyakit 1	: "); scanf("%s", &sakit.penyakit1); fflush(stdin);
	}
	
	(*x).penyakit = sakit; //mengisi info penyakit dengan nama penyakit yang sudah diinputkan
}

/* Menampilkan info pelanggan vet service.
   I.S. info pelanggan vet service belum ditampilkan.
   F.S. info pelanggan vet service sudah ditampilkan.
   Author : Syahda Afia.
*/ 
void LihatAntrian (Queue Q){
	//deklarasi
	addrNQ temp;
	int i;
	
	//algoritma
	PrintMenuLihatAntrian();
	temp = Q.front;
	i=0;
	
	if (temp == NULL){ //jika antrian kosong
		printf ("Antrian Masih Kosong\n\n");
	}
	
	while (temp != NULL){ //print info pelanggan selama antrian tidak kosong
		printf("%d\n", ++i); //menampilkan nomor antrian
		printf ("Nama Hewan		: %s\n", temp->info.nama); //menampilkan nama hewan 
		printf ("Waktu Kedatangan	: %d\n", temp->info.WDatang); //menampilkan waktu kedatangan
		PrintPenyakit(temp); //menampilkan penyakit yang dialami hewan
		printf ("Kategori Penyakit	: %s\n", temp->info.kategori); //menampilkan kategori penyakit
		printf ("Waktu Pelayanan		: %d\n", temp->info.WService); //menampilkan nomor antrian
		printf ("Waktu Tunggu		: %d\n", temp->info.WTunggu); //menampilkan waktu service
		printf ("Waktu Mulai		: %d\n", temp->info.WMulai); //menampilkan waktu mulai
		printf ("Waktu Selesai		: %d\n\n\n", temp->info.WSelesai); //menampilkan waktu selesai
		
		temp=(*temp).next; //pindah ke pelanggan selanjutnya
	}
}

/* Mengembalikan kategori penyakit dari 
   penyakit-penyakit yang diinputkan.
   Author : Syahda Afia.
*/
char* KategoriPenyakit (Sakit sakit){
	//algoritma
	//mengecek apakah ada penyakit ringan di dalam penyakit yang diinput pelanggan
	char *PenyakitRingan = "kutu bersin demam";
	char *Ringan = sakit.penyakit1;
	char *kategori1 = strstr(PenyakitRingan, Ringan);
	
	//mengecek apakah ada penyakit sedang di dalam penyakit yang diinput pelanggan
	char *PenyakitSedang = "cacingan diare rabies";
	char *Sedang = sakit.penyakit1;
	char *kategori2 = strstr(PenyakitSedang, Sedang);
			
	//mengecek apakah ada penyakit berat di dalam penyakit yang diinput pelanggan
	char *PenyakitBerat = "radang infeksi kuning";
	char *Berat = sakit.penyakit1;
	char *kategori3 = strstr(PenyakitBerat, Berat);
	
	//mengambilkan jenis kategori penyakit sesuai penyakit yang dialami
	if(kategori1){ //jika ada penyakit ringan
	    return "Ringan";
	}else if (kategori2){ //jika ada penyakit sedang
		return "Sedang";
	}else if (kategori3){ //jika ada penyakit berat
		return "Berat";
	}
}

/* Mengembalikan nilai prioritas berdasarkan 
   parameter prioritas.
   Author : Syahda Afia.
*/
int Prioritas (int JumlahPenyakit, char Kategori[]){
	//algoritma
	if(strcmp(Kategori, "Ringan") == 0){ //jika minimal ada 3 penyakit ringan
		if (JumlahPenyakit>=3){
			return 2;
		}
	}else if(strcmp(Kategori, "Sedang") == 0){ //jika minimal ada 2 penyakit sedang
		if (JumlahPenyakit>=2){
			return 3;
		}
	}else if(strcmp(Kategori, "Berat") == 0){ //jika minimal ada 1 penyakit berat
		if (JumlahPenyakit>=1){
			return 4;
		}
	}else return 1; //selain dari ketiga kondisi sebelumnya
}

/* Menampilkan tata cara penggunaan aplikasi.
   I.S. Layar kosong.
   F.S. Tampilan tata cara penggunaan aplikasi.
   author 		: M.Fauzi.
   modifikasi	: Syahda Afia.
*/
void HowToUse (){
	//deklarasi
	FILE *fp;
	char c;
	
	//algoritma
	system("cls");
	fp = fopen(HOW_TO_USE, "r"); //membaca file how to use
	
	if(fp != NULL){ //jika file ditemukan
		while(!feof(fp)){ //menampilkan text pada file ke layar selama pointer belum menunjuk ke akhir text
			c = fgetc(fp);
			printf("%c", c); 
		}
		fclose(fp); //menutup file how to use
	}else if(fp == NULL){ //jika file tidak ditemukan
		printf("Unable To Create the file \n\n");
	}
}


/*** MANAJEMEN WAKTU ***/
/* Menghitung waktu service.
   Mengembalikan waktu service sesuai dengan kategori penyakit.
   Author : Syahda Afia.
*/
int HitungWaktuService (int jumlahPenyakit, char kategori[]){
	//algoritma
	//membandingkan kata, jika sama maka mengembalikan waktu service
	if(strcmp(kategori, "Ringan") == 0){ //waktu service untuk kategori ringan
		return jumlahPenyakit*15;
	}else if(strcmp(kategori, "Sedang") == 0){ //waktu service untuk kategori sedang
		return jumlahPenyakit*30;
	}else if(strcmp(kategori, "Berat") == 0){ //waktu service untuk kategori berat
		return jumlahPenyakit*45;
	}
}

/* Menghitung waktu tunggu layanan apabila tidak ada pertukaran antrian.
   Mengembalikan hasil dari WSelesai (rear)- WDaftar.
   Author : Syahda Afia
*/
int HitungWaktuTunggu1(addrNQ rear, int WDaftar){
	//algoritma
	if(rear == NULL){ //jika antrian kosong
		return 0;
	}else if(WDaftar < rear->info.WSelesai){ //jika antrian baru datang sebelum antrian sebelumnya selesai
		return rear->info.WSelesai-WDaftar;
	}else{ //jika antrian baru datang setelah antrian sebelumnya selesai
		return 0;
	}
}

/* Menghitung waktu tunggu layanan apabila ada pertukaran antrian.
   Mengembalikan hasil dari WSelesai (Node sebelumnya)- WDaftar.
   Author : Syahda Afia
*/
int HitungWaktuTunggu2 (addrNQ temp, int WDaftar){
	//algoritma
	if (WDaftar < temp->info.WSelesai){ //jika antrian baru datang sebelum antrian sebelumnya selesai
		return temp->info.WSelesai-WDaftar;
	}else return 0; //jika antrian baru datang setelah antrian sebelumnya selesai
}

/* Menghitung waktu mulai layanan.
   Mengembalikan hasil dari Waktu Daftar atau Waktu Selesai node sebelumnya
   Author : syahda Afia
*/
int HitungWaktuMulai (addrNQ rear, int WDaftar){
	//algoritma
	if(rear == NULL || WDaftar > rear->info.WSelesai){ //jika antrian kosong atau jika antrian baru datang setelah antrian sebelumnya selesai
		return WDaftar;
	}else return rear->info.WSelesai; //jika antrian baru datang sebelum antrian sebelumnya selesai
}

/* Menghitung waktu selesai layanan. 
   Mengembalikan hasil dari WMulai + WService.
   Author : Syahda Afia.
*/
int HitungWaktuSelesai (infotype data){
	//algoritma
	return data.WMulai + data.WService; //waktu selesai = waktu mulai + waktu service
}
