#include "hangman.h"

static FILE *saveFile;
// static FILE *pita;
// static int retval;

int LengthList(ListH L)
{
    int i = 0;
    while (toString(L.kalimat[i]) != '\0')
    {
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
        int count = LengthList(guessword);
        fprintf(saveFile, "%d", count);
        fprintf(saveFile, "\n");
        for (int i = 0; i < count; i++)
        {
            // Word word = GetWord(guessword, i);
            for (int j = 0; j < strLength(toString(guessword.kalimat[i])); j++)
            {
                fprintf(saveFile, "%c", guessword.kalimat[i].TabChar[j]); // ini masih salah, helppp
            }
            fprintf(saveFile, "\n");
        }
        retval = 1;
        fclose(saveFile);
    }

    return retval;
}

// FILE *STARTF(char *source)
// {
//     pita = fopen(source, "r");
//     if (pita != NULL)
//     {
//         ADVFL();
//     }
//     return pita;
// }

void CopyList(ListH L, Word *W, int urutan)
{
    (*W) = L.kalimat[urutan];
}

// void ADVFL()
// {
//     retval = fscanf(pita, "%c", &currentCommand);
// }

// FILE *StartWord(Word source)
// {
//     FILE *pita;
//     pita = STARTF(toString(source));
//     if (pita != NULL)
//     {
//         CreateWord(&currentWord);
//         ADVWORD();
//     }
//     return pita;
// }

void loadfile(ListH *SoalorJawaban)
{
    SoalorJawaban->panjang = toInt(currentWord);
    printf("Soal or Jawaban = %d\n", SoalorJawaban->panjang);
    ADVWORD();

    int i = 0;
    while (!EOP)
    {
        SoalorJawaban->kalimat[i] = currentWord;
        ADVWORD();
        i++;
    }

    // Ngeprint
    for (i = 0; i < SoalorJawaban->panjang; i++)
    {
        printWord(SoalorJawaban->kalimat[i]);
        printf("\n");
    }
    printf("\n");
    
    /* Ini punya anda: */
    // FILE *pita;
    // ListH guessword;
    // pita = StartWord(source);
    // CreateList(&guessword);
    // int count = toInt(currentWord);
    // for (int i = 0; i < count; i++)
    // {
    //     ADVWORD();
    //     InsertLastH(&guessword, currentWord);
    // }

    // return guessword;
}

void CreateList(ListH *L)
{
    (*L).panjang = IDX_UNDEF;
}

void InsertLastH(ListH *L, Word kata)
{
    (*L).kalimat[(*L).panjang + 1] = kata;
}

// _ _ _ _
// berhasil
void CreateWord(Word *Wsalah)
{
    (*Wsalah).Length = IDX_UNDEF;
}

// berhasil
void Ilustrasi(Word Wsalah)
{
    if (Wsalah.Length == 1)
    {
        printf("========================================\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                          ||          |\n");
        printf("========================================\n");
    }
    else if (Wsalah.Length == 2)
    {
        printf("========================================\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("========================================\n");
    }
    else if (Wsalah.Length == 3)
    {
        printf("========================================\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("========================================\n");
    }
    else if (Wsalah.Length == 4)
    {
        printf("========================================\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                   -------||          |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("========================================\n");
    }
    else if (Wsalah.Length == 5)
    {
        printf("========================================\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|                   -------||          |\n");
        printf("|                   O      ||          |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("|                          ||          |\n");
        printf("========================================\n");
    }
    else if (Wsalah.Length == 6)
    {
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
    }
    else if (Wsalah.Length == 7)
    {
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
    }
    else if (Wsalah.Length == 8)
    {
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
    }
    else if (Wsalah.Length == 9)
    {

        printf("========================================\n");
        printf("|        EHH KOK GUA DISINI!!??        |\n");
        printf("|             TOLONGGG!!!              |\n");
        printf("|                   -------||          |\n");
        printf("|                   O      ||          |\n");
        printf("|                  /|\\     ||          |\n");
        printf("|                  /       ||          |\n");
        printf("|                          ||          |\n");
        printf("========================================\n");
    }
    else if (Wsalah.Length == 10)
    {
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

void DeleteHuruf(Word *Wbenar, Word WSoal, int indeks)
{
    int j;
    for (j = indeks; j <= WSoal.Length; j++)
    {
        (*Wbenar).TabChar[j] = (*Wbenar).TabChar[j + 1];
    }
}

// berhasil
void InsertHuruf(Word *Wbenar, Word WSoal, int indeks)
{
    int j;
    Word Wbenartemp;
    for (j = indeks; j <= WSoal.Length; j++)
    {
        (Wbenartemp).TabChar[j] = (*Wbenar).TabChar[j];
    }
    for (j = indeks; j <= WSoal.Length; j++)
    {
        (*Wbenar).TabChar[j + 1] = (Wbenartemp).TabChar[j];
    }
    (*Wbenar).TabChar[indeks] = WSoal.TabChar[indeks];
}

//
void UbahHuruf(Word *WSoal, char huruf, Word *Wsalah, Word *Wbenar)
{
    int i = 0;
    int count = 0;
    while (i < (*WSoal).Length)
    {
        if ((*WSoal).TabChar[i] == huruf)
        {
            DeleteHuruf(Wbenar, *WSoal, i);
            InsertHuruf(Wbenar, *WSoal, i);
            (*Wbenar).Length--;
            count++;
        }
        i++;
    }
    if (count == 0)
    {
        (*Wsalah).TabChar[(*Wsalah).Length] = huruf;
        (*Wsalah).Length++;
    }
}

// berhasil
void PrintKalimat(Word W)
{
    for (int i = 0; i < W.Length; i++)
    {
        printf("%c", (W).TabChar[i]);
    }
}

boolean IsOne()
{
    return (currentCommand.Length == 1);
}

// berhasil
void TampilanGame(Word Wbenar, Word Wsalah, int urutan, Word WSoal)
{
    Ilustrasi(Wsalah);
    PrintKalimat(WSoal);
    printf("\n");
    printf("Tebakan sebelumnya : \n");
    PrintKalimat(Wsalah);
    printf("\n");
    printf("Kata : \n");
    PrintKalimat(Wbenar);
    printf("\n");
    printf("Kesempatan : ");
    printf("%d", (10 - (Wsalah).Length));
    printf("\n");
    printf("==========================================================================================\n");
}

// berhasil
boolean Ada(char huruf, Word Wsalah, Word Wbenar, Word WSoal)
{
    boolean found = false;
    int i = 0;
    while (i < KESEMPATAN && !found)
    {
        if (huruf == Wsalah.TabChar[i] || huruf == Wbenar.TabChar[i])
        {
            found = true;
        }
        i++;
    }
    return found;
}

/*
void HangMan(int *skorhangman){

    //inisiasi kebutuhan
    ListH LGame;
    ListH LJawaban; //dipake buat nyimpen dan ngakses jawaban dari jawaban.txt
    ListH LSoal; //dipake buat nyimpen dan ngakses jawaban dari soal.txt
    CreateList(&LGame);
    CreateList(&LJawaban);
    CreateList(&LSoal);
    Word WSoal = LGame.kalimat[0]; //dipake buat nampilin soal
    Word Wbenar = LGame.kalimat[1]; //dipake buat nyimpen '_ _ _' dengan data acuan dari WSoal.
    //panjang word ini dijadiin acuan buat ngukur apakah game sudah selesai 1 match atau belum
    Word Wsalah = LGame.kalimat[2]; //dipake buat nyimpen jawaban yang salah.
    //panjang word ini juga dipake buat ngukur apakah game sudah selesai atau belum.
    srand(time(0));
    int point;
    int jumlahMain = 0;
    int jumlahSalah = 0;
    boolean selesai = false;
    LJawaban = loadfile(toWord("jawaban.txt"));//manggil file txt
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

    //tampilan menu untuk memilih mau langsung main atau nambahin dictionary
    printf("Pilih yang mana yang kamu suka");
    printf("Pilih 'L' untuk langsung main");
    printf("Pilih 'S' untuk menambah dictionary");
    STARTCMD(true);
    char input;
    while(!IsOne){
        input = currentCommand.TabChar[0];
        if (input = 'S'){
            // **masukan fungsi untuk mengisi list soal dan jawaban baru**
        }
    }


    //permainan dimulai
    while(!selesai && jumlahMain < LSoal.panjang){
        int urutan = (rand()%LJawaban.panjang) + 1; //ngacak urutan dari list yg mau dipake
        // printf("%d\n", urutan);

        //inisiasi Word
        CreateWord(&WSoal);
        CreateWord(&Wbenar);
        CreateWord(&Wsalah);


        Wsalah.Length = 0;
        Wbenar.Length = WSoal.Length;
        for(int increment = 0; increment<Wbenar.Length; increment++){
            Wbenar.TabChar[increment] = CLUE;
        }
        CopyList(LSoal, WSoal, urutan);

        point = WSoal.Length;

        TampilanGame(Wbenar, Wsalah, urutan, WSoal);
        printf("Masukan Tebakanmu : ");
        STARTCMD(true);
        char input;
        if(IsOne){
            input = currentCommand.TabChar[0];
        }
        printf("\n");
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
        while(Wbenar.Length != 0 || Wsalah.Length != 10){
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

        //untuk merubah skor game
        if(Wbenar.Length == 0){
            skorhangman += point;
            printf("Skor : %d\n", skorhangman);
        } else if(Wsalah.Length > KESEMPATAN){
            selesai = true;
        }
        jumlahMain ++;

        //untuk memvalidasi kelanjutan permainan
        printf("Mau lanjut main lagi ga? (Y/N)");
        STARTCMD(true);
                if(IsOne){
                    input = currentCommand.TabChar[0];
                }
        while(!(input == 'Y' || input == 'N')){
            if(input == 'Y'){
                selesai = true;
            } else{
                jumlahSalah = Wsalah.Length;
                CreateWord(&Wsalah); //inisiasi isi dari kumpulan huruf yang salah
            }
        }
    }

    //closingan game
    if(selesai == true){
        printf("YAHHH!!!\n");
        printf("SEDIH BANGET DEH, KAMU BELOM MENCAPAI SKOR MAKSIMAL. SARAN KAMI SIH COBA LAGI (TAUN DPN YA!!)");
        printf("btw skor gamem situ saat ini ada di %d point yaaa", skorhangman);
    } else {
        printf("WADAWWW.. SITU KEREN BANGET BISA TAMATIN NI GAME!!\n");
        printf("Karena situ udh menang, aku kasi situ %d point dehhh yakk!!\n", skorhangman);\
    }
}
*/

void HangMan(int *skor)
{
    char pathSoal[] = "data/soal.txt";
    char pathJawaban[] = "data/jawaban.txt";
    boolean openSuccess;

    ListH Lsoal; CreateList(&Lsoal);
    ListH Ljawaban; CreateList(&Ljawaban);

    STARTWORD(pathSoal, &openSuccess);
    loadfile(&Lsoal);
    STARTWORD(pathJawaban, &openSuccess);
    loadfile(&Ljawaban);

    // ListH Lsoal = loadfile(toWord("Document/soal.txt"));
    // ListH Ljawaban = loadfile(toWord("Document/soal.txt"));
    Word WSoal;
    Word Wbenar;
    Word Wsalah;
    int point;
    int jumlahmain = 0;
    int jumlahkalah = 0;
    // char input;
    boolean selesai = false;
    srand(time(0));

    printf("\n\n***INI TAMPILAN AWAL***\n\n");

    while (selesai == false && jumlahmain != Lsoal.panjang)
    {
        CreateWord(&Wbenar);
        CreateWord(&WSoal);
        CreateWord(&Wsalah);

        int urutan = (rand() % Ljawaban.panjang) + 1;
        CopyList(Lsoal, &WSoal, urutan);
        for (int i = 0; i < WSoal.Length; i++)
        {
            Wbenar.TabChar[i] = CLUE;
        }
        Wsalah.Length = 0;
        point = WSoal.Length;

        TampilanGame(Wbenar, Wsalah, urutan, WSoal);
        printf("Masukan Tebakanmu : ");
        STARTCMD(true);
        char input;

        while (!IsOne())
        {
            printf("hurufnya jgn > 1 yak!\n");
            printf("Masukan Tebakanmu : ");
            STARTCMD(true);
        }
        input = currentCommand.TabChar[0];
        printf("\n");

        while (!(input >= 'A' && input <= 'Z'))
        {
            printf("******************************************************************************************\n");
            printf("*  Sori bro, coba situ input hurufnya di capslocskin dlu truss inputnya harus berupa huruf yakk!  *\n");
            printf("******************************************************************************************\n");
            printf("Masukan Tebakanmu : ");
            while (!IsOne())
            {
                printf("hurufnya jgn > 1 yak!\n");
                printf("Masukan Tebakanmu : ");
                STARTCMD(true);
            }
            input = currentCommand.TabChar[0];
            printf("\n");
        }
        UbahHuruf(&WSoal, input, &Wsalah, &Wbenar);
        while (Wbenar.Length != 0 && Wsalah.Length < KESEMPATAN)
        {
            TampilanGame(Wbenar, Wsalah, urutan, WSoal);
            printf("Masukan Tebakanmu : ");
            STARTCMD(true);
            while (!IsOne())
            {
                printf("hurufnya jgn > 1 yak!\n");
                printf("Masukan Tebakanmu : ");
                STARTCMD(true);
            }
            input = currentCommand.TabChar[0];
            printf("\n");
            while (!(input >= 'A' && input <= 'Z') || (Ada(input, Wsalah, Wbenar, WSoal)))
            {
                if ((Ada(input, Wsalah, Wbenar, WSoal)))
                {
                    printf("****************************************************************\n");
                    printf("*  btw, inputnya jangan huruf yang udh pernah ditebak yakk!!!  *\n");
                    printf("****************************************************************\n");
                }
                else
                {
                    printf("******************************************************************************************\n");
                    printf("*  Sori bro, coba situ input hurufnya di capslocsk dan tentu inputnya harus huruf yakk!  *\n");
                    printf("******************************************************************************************\n");
                }
                printf("Masukan Tebakanmu : ");
                STARTCMD(true);
                while (!IsOne())
                {
                    printf("hurufnya jgn > 1 yak!\n");
                    printf("Masukan Tebakanmu : ");
                    STARTCMD(true);
                }
                input = currentCommand.TabChar[0];
                printf("\n");
            }
            UbahHuruf(&WSoal, input, &Wsalah, &Wbenar);
        }

        if (Wbenar.Length == 0)
        {
            (*skor) += point;
            printf("Skor : %d\n", (*skor));
        }
        else if (Wsalah.Length > KESEMPATAN)
        {
            selesai = true;
        }
        jumlahmain++;

        printf("Mau lanjut main lagi ga? (Y/N)");
        STARTCMD(true);
        input = currentCommand.TabChar[0];
        
        while (!IsOne() && !(input == 'Y' || input == 'N'))
        {
            printf("Tolong sesuain jawabannya sama opsi kami yak!\n");
            printf("Mau lanjut main lagi ga? (Y/N) : ");
            STARTCMD(true);
        }

        printf("\n");
        if (input == 'N')
        {
            selesai = true;
        }
        else
        {
            jumlahkalah += Wsalah.Length;
        }
    }
}

int main()
{
    int skor = 10;
    HangMan(&skor);
}