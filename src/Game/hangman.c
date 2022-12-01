#include "hangman.h"

static FILE *saveFile;

int LenghtList(ListH L){
    int i = 0;
    while (toString(L.kalimat[i]) != '\0'){
        i++;
    }
    return i;
}

int savefile(ListH guessword, Word fileName)
{
    int retval = 0;
    saveFile = NULL;
    saveFile = fopen(toString(fileName), "w+");

    if (saveFile == NULL)
    {
        fprintf(stderr, "Penyimpanan gagal, tidak dapat menyimpan dengan nama %s.\n", toString(fileName));
    }
    else
    {
        int count = LenghtList(guessword);
        fprintf(saveFile, "%d", count);
        fprintf(saveFile, "\n");
        for (int i = 0; i < count; i++)
        {
            //Word word = GetWord(guessword, i);
            for (int j = 0; j < strLength(toString(guessword.kalimat[i])); j++)
            {
                fprintf(saveFile, "%c", guessword.kalimat[i].TabChar[j]); //ini masih salah, helppp
            }
            fprintf(saveFile, "\n");
        }
        retval = 1;
        fclose(saveFile);
    }

    return retval;
}

FILE *STARTWORD(Word source)
{
    FILE *pita;
    pita = STARTF(GetString(&source));
    if (pita != NULL)
    {
        CreateWord(&currentWord);
        ADVWORD();
    }
    return pita;
}

ListH loadfile(Word source)
{
    FILE* pita;
    ListH guessword;
    pita = STARTWORD(source);
    CreateEmpty(&guessword);
    int count = toInt(currentWord);
    for (int i = 0; i < count; i++)
    {
        ADVWORD();
        InsertLastt(&guessword, currentWord);
    }

    return guessword;
}

//berhasil
void CreateClue(ListH *LSoal, int urutan){
	int i;
	for(i=0;i<(*LSoal).kalimat[urutan].Length;i++){
		(*LSoal).kalimat[urutan].TabChar[i] = CLUE;
	}
}

void InsertLastH(ListH *L, Word kata){
    (*L).kalimat[(*L).panjang + 1] = kata;
}

// _ _ _ _ 
//berhasil
void CreateWord(Word *Wsalah){
	(*Wsalah).Length = IDX_UNDEF;
}

//berhasil
void Ilustrasi(Word Wsalah){
    if (Wsalah.Length == 1){
        printf("========================================\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                          ||          |\n");
        printf("========================================\n");
    } else if (Wsalah.Length == 2){
        printf("========================================\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("========================================\n");
    } else if (Wsalah.Length == 3){
        printf("========================================\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("========================================\n");
    } else if (Wsalah.Length== 4){
        printf("========================================\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                   -------||          |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("========================================\n");
    } else if (Wsalah.Length == 5){
        printf("========================================\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                   -------||          |\n");
        printf("|                   O      ||          |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("========================================\n");
    } else if (Wsalah.Length == 6){
        printf("========================================\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                   -------||          |\n");
        printf("|                   O      ||          |\n");
        printf("|                  /       ||          |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("========================================\n");
    } else if (Wsalah.Length == 7){
        printf("========================================\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                   -------||          |\n");
        printf("|                   O      ||          |\n");
        printf("|                  / \\    ||          |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("========================================\n");
    } else if (Wsalah.Length == 8){
        printf("========================================\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                   -------||          |\n");
        printf("|                   O      ||          |\n");
        printf("|                  /|\\    ||          |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("========================================\n");
    } else if (Wsalah.Length == 9){
        
        printf("========================================\n");
        printf("|        EHH KOK GUA DISINI!!??        |\n");
        printf("|             TOLONGGG!!!              |\n");
        printf("|                   -------||          |\n");
        printf("|                   O      ||          |\n");
        printf("|                  /|\\    ||          |\n");
        printf("|                  /       ||          |\n");
        printf("|                          ||          |\n");
        printf("========================================\n");
    } else if (Wsalah.Length == 10){
        printf("======================================\n");
        printf("|            TIIIIDAAAAKKK!!!!!!       |\n");
        printf("|        AARGHHH!!     AAAAAARGHHH!!   |\n");
        printf("|     AAAARGHHH!!   -------||  ARGHH!  |\n");
        printf("|        AARGHHH!!  O      || ARGHH!   |\n");
        printf("|     AAAARGHHH!!  /|\\    ||  ARGHH!  |\n");
        printf("|        AARGHHH!! / \\    || ARGHH!   |\n");
        printf("|     AAAARGHHH!!          ||  ARGHH!  |\n");
        printf("======================================\n");
    }
}


void DeleteHuruf(Word *Wbenar, Word WSoal, int indeks){
	int j;
	for(j=indeks;j<=WSoal.Length;j++){
		(*Wbenar).TabChar[j] = (*Wbenar).TabChar[j+1];
	}
}


//berhasil
void InsertHuruf(Word *Wbenar, Word WSoal, int indeks){
	int j;
	Word Wbenartemp;
	for(j=indeks;j<=WSoal.Length;j++){
		(Wbenartemp).TabChar[j] = (*Wbenar).TabChar[j];
	}
	for(j=indeks;j<=WSoal.Length;j++){
		(*Wbenar).TabChar[j+1] = (Wbenartemp).TabChar[j];
	}
	(*Wbenar).TabChar[indeks] = WSoal.TabChar[indeks];
}

//
void UbahHuruf(Word *WSoal, char huruf, Word *Wsalah, Word *Wbenar){
	int i = 0;
	int count = 0;
	while (i<(*WSoal).Length ){
		if((*WSoal).TabChar[i] == huruf){
			DeleteHuruf(Wbenar, *WSoal, i);
			InsertHuruf(Wbenar, *WSoal, i);
			(*Wbenar).Length--;
			count++;
		} 
		i++;
	}
	if(count==0){
		(*Wsalah).TabChar[(*Wsalah).Length] = huruf;
		(*Wsalah).Length++;
	}

}

//berhasil
void PrintKalimat(Word W){
	for(int i=0;i<W.Length;i++){
		printf("%c", (W).TabChar[i]);
	}
}

//berhasil
void TampilanGame(Word Wbenar , Word Wsalah, int urutan, Word WSoal){
	Ilustrasi(Wsalah);
	PrintKalimat(WSoal);
	printf("==========================================================================================\n");
	printf("Tebakan sebelumnya : \n");
	PrintKalimat(Wsalah);
	printf("\n");
	printf("Kata : \n");
	PrintKalimat(Wbenar);
	printf("\n");
	printf("Kesempatan : ");
	printf("%d", (10-(Wsalah).Length));
	printf("\n");
	printf("==========================================================================================\n");
}

//berhasil
boolean Ada(char huruf, Word Wsalah, Word Wbenar, Word WSoal){
	boolean found = false;
	int i=0;
	while (i<KESEMPATAN && !found){
		if (huruf == Wsalah.TabChar[i] || huruf == Wbenar.TabChar[i]){
			found = true;
		}
		i++;
	}
	return found;
}

void HangMan (int *skorhangman){
    
    char answer;
    ListH LSoal;
    ListH Lbenar;
    ListH Lsalah;
    ListH jawaban;
    ListH soal;
    srand(time(0));
    int point;
    int jumlahMain = 0;
    int jumlahSalah = 0;
    boolean selesai = false;
    jawaban = Loadfile(toWord("data/jawaban.txt"));
    soal = Loadfile(toWord("data/soal.txt"));

    scanf(&answer);
    // y
    InsertLastt(&soal, toWord(answer));

	
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
        
        CreateEmpty(&LSoal);
        variasiSoal(urutan, &LSoal);
        CreateList(&Lbenar, LSoal.panjang);
        CreateEmpty(&Lsalah);
        
        LSoal.panjang = strLength(soal.kalimat[urutan]);
        Lsalah.panjang = jumlahSalah;
        Lbenar.panjang = soal.panjang;
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
            STARTCMD(true);
            Word Uinput = currentCommand;
            char input = Uinput.TabChar[0];
            printf("\n");
        }
        DigitBenar(&LSoal, input, &Lsalah, &Lbenar);
        while(Lbenar.panjang != 0 || Lsalah.panjang<=KESEMPATAN){
            TampilanGame(Lbenar, Lsalah, urutan, LSoal);
            printf("Masukan Tebakanmu : ");
            STARTCMD(true);
            Word Uinput = currentCommand;
            char input = Uinput.TabChar[0];
            printf("\n");
            while(!(input >= 'A' && input <= 'Z') || (isExist(input, Lsalah, Lbenar, LSoal))){
                printf("******************************************************************************************\n");
                if((isExist(input, Lsalah, Lbenar, LSoal))){
                    printf("btw, inputnya jangan huruf yang udh pernah ditebak yakk!!!\n");
                }
                else{
                    printf("Sori bro, coba situ input hurufnya di capslocsk dan tentu inputnya harus huruf yakk!\n");
                }
                printf("******************************************************************************************\n");
                printf("Masukan Tebakanmu : ");
                STARTCMD(true);
                Word Uinput = currentCommand;
                char input = Uinput.TabChar[0];
                printf("\n");       
            }
            DigitBenar(&LSoal, input, &Lsalah, &Lbenar);
        }

		if(Lbenar.panjang == 0){
			(*skorhangman) += point;
			printf("Skor : %d\n", (*skorhangman));
		} else if(Lsalah.panjang > KESEMPATAN){
			selesai = true;
		}
		jumlahMain ++;
	}
	if(selesai == true){
		printf("YAHAHHAA!!!\n");
		printf("MAAF ANDA KURANG BERUNTUNG. SARAN KAMI SIH COBA LAGI (TAUN DPN YA!!)");
		printf("btw skor gamem situ saat ini ada di %d point yaaa", (*skorhangman));
	} else {
		printf("WADAWWW.. SITU KEREN BANGET BISA MENANGIN NI GAME!!\n");
		printf("Karena situ udh menang, aku kasi situ %d point dehhh yakk!!\n", (*skorhangman));
	}

int main(){
    int skor = 10;
    HangMan(&skor);
}