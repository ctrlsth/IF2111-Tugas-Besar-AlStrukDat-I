#include "hangman.h"

static FILE *saveFile;

int LenghtList(List L){
    int i = 0;
    while (L.kata[i] != '\0'){
        i++;
    }
    return i;
}

int savefile(List guessword, Word fileName)
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
            for (int j = 0; j < strLength(guessword.kata[i]); j++)
            {
                fprintf(saveFile, "%c", guessword.kata[i][j]); //ini masih salah, helppp
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

List loadfile(Word source)
{
    FILE* pita;
    List guessword;
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
void CreateListH(ListH *LSoal, int digit){
	int i;
	for(i=0;i<digit;i++){
		LSoal->kata[i] = MARKK;
	}
}

void InsertLastt(List *L, Word kata){
    (*L).kata[(*L).panjang] = *toString(kata);
}

// _ _ _ _ 
//berhasil
void CreateEmptyH(ListH *Lsalah){
	(*Lsalah).panjang = IDX_UNDEF;
}

//berhasil
void TampilanGaris(List Lsalah){
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
        printf("                  / \\'    ||          \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (Lsalah.panjang == 8){
        printf("======================================\n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                   -------||          \n");
        printf("                   O      ||          \n");
        printf("                  /|\\'    ||          \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (Lsalah.panjang == 9){
        printf("======================================\n");
        printf("        EHH KOK GUA DISINI!!??        \n");
        printf("             TOLONGGG!!!              \n");
        printf("                   -------||          \n");
        printf("                   O      ||          \n");
        printf("                  /|\\'    ||          \n");
        printf("                  /       ||          \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (Lsalah.panjang == 10){
        printf("======================================\n");
        printf("            TIIIIDAAAAKKK!!!!!!       \n");
        printf("        AARGHHH!!     AAAAAARGHHH!!   \n");
        printf("     AAAARGHHH!!   -------||  ARGHH!  \n");
        printf("        AARGHHH!!  O      || ARGHH!   \n");
        printf("     AAAARGHHH!!  /|\\'    ||  ARGHH!  \n");
        printf("        AARGHHH!! / \\'    || ARGHH!   \n");
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
    
    char answer;
    List LSoal;
    List Lbenar;
    List Lsalah;
    List jawaban;
    List soal;
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
        
        LSoal.panjang = strLength(soal.kata[urutan]);
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
}

int main(){
    int skor = 10;
    HangMan(&skor);
}