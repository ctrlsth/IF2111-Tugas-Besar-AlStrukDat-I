#include "hangman.h"

//berhasil
void CreateListH(ListH *LSoal, int digit){
	int i;
	for(i=0;i<digit;i++){
		LSoal->kata[i] = MARKK;
	}
}

//berhasil
void CreateEmptyH(ListH *Lsalah){
	(*Lsalah).panjang = IDX_UNDEF;
}

//berhasil
int printSoal(int urutan){
	if (urutan == 1){
		printf("Di rumah makan Padang, selain pakai sendok kita makan pakai?\n");
	} else if (urutan == 2){
		printf("Seseorang yang memimpin sebuah desa, biasanya dipanggil pak?\n");
	} else if (urutan == 3){
		printf("Senikmat-nikmatnya makan di luar lebih nikmat makan di?\n");
	} else if (urutan == 4){
		printf("Ikan bernapas di air dengan?\n");
	} else if (urutan == 5){
		printf("Yang dibeli seorang cowok untuk pasangannya di saat Valentine biasanya?\n");
	} else if (urutan == 6){
		printf("Seorang barber mencukur rambut pelanggan dengan?\n");
	} else if (urutan == 7){
		printf("Lorenzo, Marquez, Rossi kejar-kejaran, salip menyalip di?\n");
	} else if (urutan == 8){
		printf("Burung bisa terbang karena memiliki?\n");
	} else if (urutan == 9){
		printf("Bendera NKRI warnanya?\n");
	} else if (urutan == 10){
		printf("Galang menyimpan buku di . . .\n");
	}
}

//berhasil
void variasiSoal(int urutan, ListH *L){
	if (urutan == 1){
		(*L).panjang = 6;
		(*L).kata[0] = 'T';
		(*L).kata[1] = 'E';
		(*L).kata[2] = 'N';
		(*L).kata[3] = 'A';
		(*L).kata[4] = 'G';
		(*L).kata[5] = 'A';
	} else if (urutan == 2){
		(*L).kata[0] = 'N';
		(*L).kata[1] = 'O';
		(*L).kata[2] = 'L';
		(*L).kata[3] = 'E';
		(*L).kata[4] = 'H';
		(*L).panjang = 5;
	} else if (urutan == 3){
		(*L).kata[0] = 'T';
		(*L).kata[1] = 'E';
		(*L).kata[2] = 'L';
		(*L).kata[3] = 'A';
		(*L).kata[4] = 'N';
		(*L).panjang = 5;
	} else if (urutan == 4){
		(*L).kata[0] = 'T';
		(*L).kata[1] = 'E';
		(*L).kata[2] = 'N';
		(*L).kata[3] = 'A';
		(*L).kata[4] = 'N';
		(*L).kata[5] = 'G';
		(*L).panjang = 6;
	} else if (urutan == 5){
		(*L).kata[0] = 'B';
		(*L).kata[1] = 'A';
		(*L).kata[2] = 'Y';
		(*L).kata[3] = 'A';
		(*L).kata[4] = 'R';
		(*L).panjang = 5;
	} else if (urutan == 6){
		(*L).kata[0] = 'G';
		(*L).kata[1] = 'A';
		(*L).kata[2] = 'N';
		(*L).kata[3] = 'T';
		(*L).kata[4] = 'I';
		(*L).kata[5] = 'A';
		(*L).kata[6] = 'N';
		(*L).panjang = 7;
	} else if (urutan == 7){
		(*L).kata[0] = 'B';
		(*L).kata[1] = 'I';
		(*L).kata[2] = 'A';
		(*L).kata[3] = 'R';
		(*L).kata[4] = 'K';
		(*L).kata[5] = 'A';
		(*L).kata[6] = 'N';
		(*L).panjang = 7;
	} else if (urutan == 8){
		(*L).kata[0] = 'B';
		(*L).kata[1] = 'A';
		(*L).kata[2] = 'K';
		(*L).kata[3] = 'A';
		(*L).kata[4] = 'T';
		(*L).panjang = 5;
	} else if (urutan == 9){
		(*L).kata[0] = 'C';
		(*L).kata[1] = 'U';
		(*L).kata[2] = 'M';
		(*L).kata[3] = 'A';
		(*L).kata[4] = 'D';
		(*L).kata[5] = 'U';
		(*L).kata[6] = 'A';
		(*L).kata[7] = 'A';
		(*L).kata[8] = 'J';
		(*L).kata[9] = 'A';
		(*L).panjang = 10;
	} else if (urutan == 10){
		(*L).kata[0] = 'M';
		(*L).kata[1] = 'A';
		(*L).kata[2] = 'S';
		(*L).panjang = 3;
	}
}

//berhasil
void TampilanGaris(ListH Lsalah){
	if (Lsalah.panjang == 1){
		printf("======================================\n");
		printf("                                      \n");
		printf("                                      \n");
		printf("                                      \n");
		printf("                                      \n");
		printf("                                      \n");
		printf("                                      \n");
		printf("                          ||          \n");
		printf("======================================\n");
	} else if (Lsalah.panjang == 2){
		printf("======================================\n");
		printf("                                      \n");
		printf("                                      \n");
		printf("                                      \n");
		printf("                                      \n");
		printf("                                      \n");
		printf("                          ||          \n");
		printf("                          ||          \n");
		printf("======================================\n");
	} else if (Lsalah.panjang == 3){
		printf("======================================\n");
		printf("                                      \n");
		printf("                                      \n");
		printf("                                      \n");
		printf("                                      \n");
		printf("                          ||          \n");
		printf("                          ||          \n");
		printf("                          ||          \n");
		printf("======================================\n");
	} else if (Lsalah.panjang == 4){
		printf("======================================\n");
		printf("                                      \n");
		printf("                                      \n");
		printf("                   -------||          \n");
		printf("                          ||          \n");
		printf("                          ||          \n");
		printf("                          ||          \n");
		printf("                          ||          \n");
		printf("======================================\n");
	} else if (Lsalah.panjang == 5){
		printf("======================================\n");
		printf("                                      \n");
		printf("                                      \n");
		printf("                   -------||          \n");
		printf("                   O      ||          \n");
		printf("                          ||          \n");
		printf("                          ||          \n");
		printf("                          ||          \n");
		printf("======================================\n");
	} else if (Lsalah.panjang == 6){
		printf("======================================\n");
		printf("                                      \n");
		printf("                                      \n");
		printf("                   -------||          \n");
		printf("                   O      ||          \n");
		printf("                  /       ||          \n");
		printf("                          ||          \n");
		printf("                          ||          \n");
		printf("======================================\n");
	} else if (Lsalah.panjang == 7){
		printf("======================================\n");
		printf("                                      \n");
		printf("                                      \n");
		printf("                   -------||          \n");
		printf("                   O      ||          \n");
		printf("                  / \'    ||          \n");
		printf("                          ||          \n");
		printf("                          ||          \n");
		printf("======================================\n");
	} else if (Lsalah.panjang == 8){
		printf("======================================\n");
		printf("                                      \n");
		printf("                                      \n");
		printf("                   -------||          \n");
		printf("                   O      ||          \n");
		printf("                  /|\'    ||          \n");
		printf("                          ||          \n");
		printf("                          ||          \n");
		printf("======================================\n");
	} else if (Lsalah.panjang == 9){
		printf("======================================\n");
		printf("        EHH KOK GUA DISINI!!??        \n");
		printf("             TOLONGGG!!!              \n");
		printf("                   -------||          \n");
		printf("                   O      ||          \n");
		printf("                  /|\'    ||          \n");
		printf("                  /       ||          \n");
		printf("                          ||          \n");
		printf("======================================\n");
	} else if (Lsalah.panjang == 10){
		printf("======================================\n");
		printf("            TIIIIDAAAAKKK!!!!!!       \n");
		printf("        AARGHHH!!     AAAAAARGHHH!!   \n");
		printf("     AAAARGHHH!!   -------||  ARGHH!  \n");
		printf("        AARGHHH!!  O      || ARGHH!   \n");
		printf("     AAAARGHHH!!  /|\'    ||  ARGHH!  \n");
		printf("        AARGHHH!! / \'    || ARGHH!   \n");
		printf("     AAAARGHHH!!          ||  ARGHH!  \n");
		printf("======================================\n");
	}
}


void DeleteAtH(ListH *Lbenar, ListH LSoal, int indeks){
	int j;
	for(j=indeks;j<=LSoal.panjang;j++){
		(*Lbenar).kata[j] = (*Lbenar).kata[j+1];
	}
}


//berhasil
void InsertAtH(ListH *Lbenar, ListH LSoal, int indeks){
	int j;
	ListH Lbenartemp;
	for(j=indeks;j<=LSoal.panjang;j++){
		(Lbenartemp).kata[j] = (*Lbenar).kata[j];
	}
	for(j=indeks;j<=LSoal.panjang;j++){
		(*Lbenar).kata[j+1] = (Lbenartemp).kata[j];
	}
	(*Lbenar).kata[indeks] = LSoal.kata[indeks];
}

//
void DigitBenar(ListH *LSoal, char huruf, ListH *Lsalah, ListH *Lbenar){
	int i = 0;
	int count = 0;
	while (i<(*LSoal).panjang ){
		if((*LSoal).kata[i] == huruf){
			DeleteAtH(Lbenar, *LSoal, i);
			InsertAtH(Lbenar, *LSoal, i);
			(*Lbenar).panjang--;
			count++;
		} 
		i++;
	}
	if(count==0){
		(*Lsalah).kata[(*Lsalah).panjang] = huruf;
		(*Lsalah).panjang++;
	}

}

//berhasil
void PrintListH(ListH L, int max){
	int i;
	for(i=0;i<max;i++){
		printf("%c", (L).kata[i]);
	}
}

//berhasil
void TampilanGame(ListH Lbenar ,ListH Lsalah, int urutan, ListH LSoal){
	TampilanGaris(Lsalah);
	printSoal(urutan);
	printf("==========================================================================================\n");

	printf("Tebakan sebelumnya : \n");
	PrintListH(Lsalah, Lsalah.panjang);
	printf("\n");
	printf("Kata : \n");
	PrintListH(Lbenar, LSoal.panjang);
	printf("\n");
	printf("Kesempatan : ");
	printf("%d", (10-(Lsalah).panjang));
	printf("\n");
	printf("==========================================================================================\n");
}

//berhasil
boolean isExistH (char huruf, ListH Lsalah, ListH Lbenar, ListH LSoal){
	boolean found = false;
	int i=0;
	while (i<KESEMPATAN && !found){
		if (huruf == Lsalah.kata[i] || huruf == Lbenar.kata[i]){
			found = true;
		}
		i++;
	}
	return found;
}

void HangMan (int *skorhangman){

	ListH LSoal;
	ListH Lbenar;
	ListH Lsalah;
	srand(time(0));
	int point;
	int jumlahMain = 0;
	int jumlahSalah = 0;
	boolean selesai = false;

	
	// printf("%d\n", LSoal.panjang);
	// printf("%d\n", Lbenar.panjang);
	// printf("%d\n", Lsalah.panjang);

	printf("\n");
	printf("  /$$$$$$            /$$                                     /$$           /$$                          \n");
	printf(" /$$__  $$          | $$                                    | $$          | $$                          \n");
	printf("| $$  \\__/  /$$$$$$ | $$  /$$$$$$  /$$$$$$/$$$$   /$$$$$$  /$$$$$$        | $$$$$$$   /$$$$$$   /$$$$$$ \n");
	printf("|  $$$$$$  /$$__  $$| $$ |____  $$| $$_  $$_  $$ |____  $$|_  $$_/        | $$__  $$ /$$__  $$ /$$__  $$\n");
	printf(" \\____  $$| $$$$$$$$| $$  /$$$$$$$| $$ \\ $$ \\ $$  /$$$$$$$  | $$          | $$  \\ $$| $$$$$$$$| $$  \\__/\n");
	printf(" /$$  \\ $$| $$_____/| $$ /$$__  $$| $$ | $$ | $$ /$$__  $$  | $$ /$$      | $$  | $$| $$_____/| $$      \n");
	printf("|  $$$$$$/|  $$$$$$$| $$|  $$$$$$$| $$ | $$ | $$|  $$$$$$$  |  $$$$/      | $$$$$$$/|  $$$$$$$| $$      \n");
	printf(" \\______/  \\_______/|__/ \\_______/|__/ |__/ |__/ \\_______/   \\___/        |_______/  \\_______/|__/      \n");
	printf("\n");
	printf("\n");
	printf("             /$$   /$$  /$$$$$$  /$$   /$$  /$$$$$$  /$$      /$$  /$$$$$$  /$$   /$$                   \n");
	printf("            | $$  | $$ /$$__  $$| $$$ | $$ /$$__  $$| $$$    /$$$ /$$__  $$| $$$ | $$                   \n");
	printf("            | $$  | $$| $$  \\ $$| $$$$| $$| $$  \\__/| $$$$  /$$$$| $$  \\ $$| $$$$| $$                   \n");
	printf("            | $$$$$$$$| $$$$$$$$| $$ $$ $$| $$ /$$$$| $$ $$/$$ $$| $$$$$$$$| $$ $$ $$                   \n");
	printf("            | $$__  $$| $$__  $$| $$  $$$$| $$|_  $$| $$  $$$| $$| $$__  $$| $$  $$$$                   \n");
	printf("            | $$  | $$| $$  | $$| $$\\  $$$| $$  \\ $$| $$\\  $ | $$| $$  | $$| $$\\  $$$                   \n");
	printf("            | $$  | $$| $$  | $$| $$ \\  $$|  $$$$$$/| $$ \\/  | $$| $$  | $$| $$ \\  $$                   \n");
	printf("            |__/  |__/|__/  |__/|__/  \\__/ \\______/ |__/     |__/|__/  |__/|__/  \\__/                   \n");
	printf("\n");
	printf("\n");
	printf("                                         /$$           /$$ /$$                                          \n");
	printf("                                        |__/          | $$| $$                                          \n");
	printf("                                /$$$$$$  /$$  /$$$$$$ | $$| $$                                          \n");
	printf("                               /$$__  $$| $$ |____  $$| $$| $$                                          \n");
	printf("                              | $$  \\__/| $$  /$$$$$$$|__/|__/                                          \n");
	printf("                              | $$      | $$ /$$__  $$                                                  \n");
	printf("                              | $$      | $$|  $$$$$$$ /$$ /$$                                          \n");
	printf("                              |__/      |__/ \\_______/|__/|__/                                          \n");
	printf("\n");
	printf("\n");
	
	while(selesai == false || jumlahMain == 10){
		int urutan = (rand()%10) + 1;
		// printf("%d\n", urutan);
		
		CreateEmptyH(&LSoal);
		variasiSoal(urutan, &LSoal);
		CreateListH(&Lbenar, LSoal.panjang);
		CreateEmptyH(&Lsalah);

		Lsalah.panjang = jumlahSalah;
		Lbenar.panjang = LSoal.panjang;
		point = LSoal.panjang;

		TampilanGame(Lbenar, Lsalah, urutan, LSoal);
		printf("Masukan Tebakanmu : ");
		STARTCMD(true);
		Word Uinput = currentCommand;
		char input = Uinput.TabChar[0];
		//scanf("%c", &input);
		printf("\n");
		//printf("%c", input);
		while(!(input >= 'A' && input <= 'Z')){
			printf("******************************************************************************************\n");
			printf("Sori bro, coba situ input hurufnya di capslocskin dlu truss inputnya harus berupa huruf yakk!\n");
			printf("******************************************************************************************\n");
			printf("Masukan Tebakanmu : ");
			scanf("%c", &input);
			printf("\n");
		}
		DigitBenar(&LSoal, input, &Lsalah, &Lbenar);
		while(Lbenar.panjang != 0 || Lsalah.panjang<=KESEMPATAN){
			TampilanGame(Lbenar, Lsalah, urutan, LSoal);
			printf("Masukan Tebakanmu : ");
			scanf(" %c", &input);
			printf("\n");
			while(!(input >= 'A' && input <= 'Z') || (isExistH(input, Lsalah, Lbenar, LSoal))){
				printf("******************************************************************************************\n");
				if((isExistH(input, Lsalah, Lbenar, LSoal))){
					printf("btw, inputnya jangan huruf yang udh pernah ditebak yakk!!!\n");
				}
				else{
					printf("Sori bro, coba situ input hurufnya di capslocsk dan tentu inputnya harus huruf yakk!\n");
				}
				printf("******************************************************************************************\n");
				printf("Masukan Tebakanmu : ");
				scanf(" %c", &input);
				printf("\n");       
			}
			DigitBenar(&LSoal, input, &Lsalah, &Lbenar);
		}

		if(Lbenar.panjang == 0){
			skorhangman += point;
			printf("Skor : %d\n", skorhangman);
		} else if(Lsalah.panjang > KESEMPATAN){
			selesai = true;
		}
		jumlahMain ++;
	}
	if(selesai == true){
		printf("YAHAHHAA!!!\n");
		printf("MAAF ANDA KURANG BERUNTUNG. SARAN KAMI SIH COBA LAGI (TAUN DPN YA!!)");
		printf("btw skor gamem situ saat ini ada di %d point yaaa", skorhangman);
	} else {
		printf("WADAWWW.. SITU KEREN BANGET BISA MENANGIN NI GAME!!\n");
		printf("Karena situ udh menang, aku kasi situ %d point dehhh yakk!!\n", skorhangman);\
	}

	return;
}