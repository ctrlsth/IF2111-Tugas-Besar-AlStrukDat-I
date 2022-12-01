#include "hangman.h"

static FILE *saveFile;
static FILE *pita;
static int retval;

int LenghtList(ListH L){
    int i = 0;
    while (toString(L.kalimat[i]) != '\0'){
        i++;
    }
    return i;
}

int savefile(ListH guessword, Word fileName){
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

FILE* STARTF(char *source)
{
    pita = fopen(source, "r");
    if (pita != NULL) {
        ADVFL();
    }
    return pita;
}

Word CopyList(ListH L, Word W, int urutan){
    for(int i = 0; i<strLength(toString(L.kalimat[urutan])); i++){
        W.TabChar[i] = L.kalimat[urutan].TabChar[i];
    }
}
void ADVFL()
{
    retval = fscanf(pita, "%c", &currentCommand);
}

FILE *StartWord(Word source){
    FILE *pita;
    pita = STARTF(toString(source));
    if (pita != NULL)
    {
        CreateWord(&currentWord);
        ADVWORD();
    }
    return pita;
}

ListH loadfile(Word source){
    FILE* pita;
    ListH guessword;
    pita = StartWord(source);
    CreateList(&guessword);
    int count = toInt(currentWord);
    for (int i = 0; i < count; i++)
    {
        ADVWORD();
        InsertLastH(&guessword, currentWord);
    }

    return guessword;
}

void CreateList(ListH *L){
    (*L).panjang = IDX_UNDEF;
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
int Ilustrasi(Word Wsalah){
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
        printf("|                  / \\     ||          |\n");
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
        printf("|                  /|\\     ||          |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("========================================\n");
    } else if (Wsalah.Length == 9){
        
        printf("========================================\n");
        printf("|        EHH KOK GUA DISINI!!??        |\n");
        printf("|             TOLONGGG!!!              |\n");
        printf("|                   -------||          |\n");
        printf("|                   O      ||          |\n");
        printf("|                  /|\\     ||          |\n");
        printf("|                  /       ||          |\n");
        printf("|                          ||          |\n");
        printf("========================================\n");
    } else if (Wsalah.Length == 10){
        printf("======================================\n");
        printf("|            TIIIIDAAAAKKK!!!!!!       |\n");
        printf("|        AARGHHH!!     AAAAAARGHHH!!   |\n");
        printf("|     AAAARGHHH!!   -------||  ARGHH!  |\n");
        printf("|        AARGHHH!!  O      || ARGHH!   |\n");
        printf("|     AAAARGHHH!!  /|\\     ||  ARGHH!  |\n");
        printf("|        AARGHHH!! / \\     || ARGHH!   |\n");
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

boolean IsOne(Word W){
    return(W.Length == 1);
}
//berhasil
int TampilanGame(Word Wbenar , Word Wsalah, int urutan, Word WSoal){
	Ilustrasi(Wsalah);
	PrintKalimat(WSoal);
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

void HangMan(int *skorhangman){
    char answer;
    ListH LGame;
    ListH LJawaban;
    ListH LSoal;
    CreateList(&LGame);
    CreateList(&LJawaban);
    CreateList(&LSoal);
    Word WSoal = LGame.kalimat[0];
    Word Wbenar = LGame.kalimat[1];
    Word Wsalah = LGame.kalimat[2];
    srand(time(0));
    int point;
    int jumlahMain = 0;
    int jumlahSalah = 0;
    boolean selesai = false;
    LJawaban = loadfile(toWord("jawaban.txt"));
    LSoal = loadfile(toWord("soal.txt"));

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
    

    while(!selesai || jumlahMain < LJawaban.panjang){
        int urutan = (rand()%LJawaban.panjang) + 1;
        // printf("%d\n", urutan);
        
        CreateWord(&WSoal);
        CreateWord(&Wbenar);
        CreateWord(&Wsalah);
        
        Wsalah.Length = jumlahSalah;
        Wbenar.Length = WSoal.Length;
        for(int increment = 0; increment<Wbenar.Length; increment++){
            Wbenar.TabChar[increment] = LJawaban.kalimat[urutan].TabChar[increment]; 
        }
        
        point = WSoal.Length;
       
        TampilanGame(Wbenar, Wsalah, urutan, WSoal);
        printf("Masukan Tebakanmu : ");
        STARTCMD(true);
        char input;
        if(IsOne){
            input = currentCommand.TabChar[0];
        }
        //scanf("%c", &input);
        printf("\n");
        //printf("%c", input);
        while(!(input >= 'A' && input <= 'Z')){
            printf("******************************************************************************************\n");
            printf("*  Sori bro, coba situ input hurufnya di capslocskin dlu truss inputnya harus berupa huruf yakk!  *\n");
            printf("******************************************************************************************\n");
            printf("Masukan Tebakanmu : ");
            STARTCMD(true);
            if(IsOne){
                input = currentCommand.TabChar[0];
            }
            printf("\n");
        }
        UbahHuruf(&WSoal, input, &Wsalah, &Wbenar);
        while(Wbenar.Length != 0 || Wsalah.Length < KESEMPATAN){
            TampilanGame(Wbenar, Wsalah, urutan, WSoal);
            printf("Masukan Tebakanmu : ");
            STARTCMD(true);
            if(IsOne){
                input = currentCommand.TabChar[0];
            }
            printf("\n");
            while(!(input >= 'A' && input <= 'Z') || (Ada(input, Wsalah, Wbenar, WSoal))){
                if((Ada(input, Wsalah, Wbenar, WSoal))){
                    printf("****************************************************************\n");
                    printf("*  btw, inputnya jangan huruf yang udh pernah ditebak yakk!!!  *\n");
                    printf("****************************************************************\n");
                }
                else{
                    printf("******************************************************************************************\n");
                    printf("*  Sori bro, coba situ input hurufnya di capslocsk dan tentu inputnya harus huruf yakk!  *\n");
                    printf("******************************************************************************************\n");
                }
                printf("Masukan Tebakanmu : ");
                STARTCMD(true);
                if(IsOne){
                    input = currentCommand.TabChar[0];
                }
                printf("\n");       
            }
            UbahHuruf(&WSoal, input, &Wsalah, &Wbenar);
            printf("\n\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n\n\n");
        }

        if(Wbenar.Length == 0){
            skorhangman += point;
            printf("Skor : %d\n", skorhangman);
        } else if(Wsalah.Length > KESEMPATAN){
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