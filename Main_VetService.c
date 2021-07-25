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

int main (){
	system ("cls");
	Queue Q;
	
	BuatAntrian(&Q);
	int choice;
	do {
		printf ("===========================================\n");
		printf ("||      APLIKASI LAYANAN DOKTER HEWAN    ||\n");
		printf ("||              --MAIN MENU--            ||\n");
		printf ("===========================================\n");
		printf ("||1. Login                               ||\n");
		printf ("||2. How To Use                          ||\n");
		printf ("||3. Exit                                ||\n");
		printf ("||                                       ||\n");
		printf ("===========================================\n\n");
		printf ("Pilihan Anda : "); scanf("%d", &choice); 

		switch (choice){
			case 1 : MenuLogin(Q); break;
			case 2 : HowToUse(); break;
			case 3 : exit(0);
			default: printf("Wrong input menu, please try again . . .\n"); break;
		}
		system("pause");
		system ("cls");
	} while (choice!=3);
	return 0;
}
