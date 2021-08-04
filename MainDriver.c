/*
	Program		: MainDriver.c
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

int main (){
	//deklarasi
	Queue Q;
	int choice;
	
	//algoritma
	BuatAntrian(&Q);
	
	//menampilkan main menu selama user tidak memilih exit
	do {
		PrintMainMenu ();
		scanf("%d", &choice); //menerima inputan pilihan menu dari user

		switch (choice){
			case 1 : UserLogin(Q); break; //masuk ke menu login
			case 2 : HowToUse(); break; //masuk ke menu how to use
			case 3 : exit(0); //keluar dari program
			default: printf("Wrong input menu, please try again . . .\n"); fflush(stdin); break; //jika input tidak sesuai
		}
		system("pause");
		system ("cls");
	} while (choice!=3);
	
	return 0;
}
