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

/* Atribut ADT */
/*=============================================================*/
typedef struct NodeQueue *addrNQ;
typedef struct InfoPelangganVetService infotype;

typedef struct InfoPelangganVetService{
	char nama[50];
	char penyakit[50];
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








#endif
