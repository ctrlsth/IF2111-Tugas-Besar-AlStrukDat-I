#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "hangman.h"

void CreateWord (Word *LSoal, int digit, boolean mark){
    int i;
    if (mark){
        for(i=0;i<digit;i++){
            LSoal->TabChar[i] = LINE;
        }
        LSoal->Length = digit;
    }
    else{
        for(i=0;i<digit;i++){
            LSoal->TabChar[i] = ' ';
        }
        LSoal->Length = 0;
    }
}

void ListofWord(TabWord* arrayWord, TabWord*arraySoal, boolean *openSuccess){
    char * filename = "data/hangman.txt";
    int n;
    int i; 
    STARTWORD(filename,openSuccess);
    if(openSuccess){
        n = toInt(currentWord);
        ADVWORD();
        if(!EndWord){
            for (i = 0;i<n;i++){
                UPPER(&currentWord); 
                InsertLast(arrayWord,currentWord);
                ADVWORD();
            }
            arrayWord->Neff = n;
        }
        
        if(!EndWord){
            n = toInt(currentWord);
            ADVWORD();
            for(i = 0;i< n ;i++){
                UPPER(&currentWord);
                InsertLast(arraySoal,currentWord);
                ADVWORD();
            }
            arraySoal->Neff = n;
        }
    }
}

void menuawal(TabWord*arrayWord,TabWord *arraySoal,boolean* game_started){
    boolean end_game = false;
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

        printf("        __       _        _    _       ___        ");                 printf("         _  __  __           _  __  __\n");
        printf("_\\/_    )_) )   /_) \\_)  / _  /_) )\\/) )_         ");              printf("_\\/_    /_) ) ) ) ) \\  X  / / ) )_) ) )\n");
        printf(" /\\    /   (__ / /   /  (__/ / / (  ( (__         ");                printf(" /\\    / / /_/ /_/   \\/ \\/ (_/ / \\ /_/ \n");
        printf("\n");
        printf("\n");
        printf("         _      ___ ___\n"); 
        printf("_\\/_    / ) / /  )   ) \n"); 
        printf(" /\\    (_X (_/ _(_  (  \n"); 
        printf("\n");
        printf("\n");
    while(!(*game_started) && !end_game){
        printf("Masukkan Command (PLAYGAME/ADDWORD/QUIT): ");
        STARTCMD(true);
        // printf("PLAYGAME - untuk memainkan game\n");
        // printf("ADDWORD - untuk menambahkan kata\n");
        // printf("QUIT - untuk keluar dari permainan!\n");
        //clear();
        if(compareWord(currentCommand,"PLAYGAME")){
            printf("Loading...\n");
            *game_started = true;
        }
        else if(compareWord(currentCommand,"ADDWORD")){
            Word soal;
            Word jawaban;
            printf("Masukkan kata berupa jawaban yang ingin dimasukkan : ");
            STARTCMD(true);
            wordCopy(&jawaban,currentCommand);
            UPPER(&jawaban);
            if(isMemberArray(*arrayWord,jawaban)){
                printf("Kata %s sudah terdapat di dalam list jawaban\n", toString(currentCommand));
                printf("Kata %s gagal dimasukkan ke dalam list jawaban\n",toString(currentCommand));
            }
            else{
                if(jawaban.Length == 0){
                    printf("Masukkan jawaban Kosong!\n");
                    printf("Kata %s gagal dimasukkan ke dalam list jawaban\n",toString(currentCommand));
                }
                else{
                    printf("Masukan soal dari jawaban yang ingin dimasukkan: ");
                    STARTCMD(true);
                    wordCopy(&soal,currentCommand);
                    UPPER(&soal);
                    if(isMemberArray(*arraySoal,currentCommand)){
                        printf("Soal %s sudah terdapat di dalam list\n", toString(currentCommand));
                        printf("Kata %s gagal dimasukkan ke dalam list jawaban\n",toString(jawaban));
                        printf("Kata %s gagal dimasukkan ke dalam list soal\n",toString(currentCommand));
                    }
                    else{
                        if(currentCommand.Length == 0){
                            printf("Masukkan Soal Kosong!\n");
                            printf("Kata %s gagal dimasukkan ke dalam list jawaban\n",toString(jawaban));
                            printf("Kata %s gagal dimasukkan ke dalam list soal\n",toString(currentCommand));
                        }
                        else{
                            InsertLast(arrayWord,jawaban);
                            InsertLast(arraySoal,soal);
                            printf("Kata %s berhasil dimasukkan ke dalam list jawaban\n",toString(jawaban));
                            printf("Soal %s berhasil dimasukkan ke dalam list soal\n",toString(soal));
                        }
                    }   
                }
            }
        }
        else if(compareWord(currentCommand,"QUIT")){
            printf("Anda keluar dari permainan\n");
            end_game = true;
        }
        else{
            printf("Command tidak valid! \n");
        }
    }
}

void savelist(TabWord arrayWord, TabWord arraySoal){
    char *filename = "hangman.txt";
    int i;
    FILE *savefile;
    char path[50] = "./data/";

    for (i = 7; i < strLength(filename) + 7; i++)
    {
        path[i] = filename[i - 7];
    }
    path[i] = '\0';

    savefile = fopen(path, "w+");
    // printf("Passed\n");
    if (savefile == NULL)
    {
        printf("\n------------------------------------------------\n");
        printf("Gagal membuka / membuat file. Silahkan coba lagi!\n");
        printf("------------------------------------------------\n");
    }
    else
    {
        // printf("Passed\n");
        char num[3];
        sprintf(num, "%d", Length(arrayWord));
        // printf("PassedX\n");
        fputs(num, savefile);
        // printf("PassedY\n");
        fputs("\n", savefile);
        // printf("PassedZ\n");
        for (i = 0; i < arrayWord.Neff; i++)
        {
            // printf("Passed %d\n", i);
            char *gamejawaban = toString(Get(arrayWord, i));
            fputs(gamejawaban, savefile);
            fputs("\n", savefile);
        }
        // printf("Passed loop\n");
        sprintf(num, "%d", Length(arraySoal));
        // // printf("PassedX\n");
        fputs(num, savefile);
        // // printf("PassedY\n");
        fputs("\n", savefile);
        // // printf("PassedZ\n");
        for (i = 0; i < arraySoal.Neff; i++)
        {
            // printWord(Get(arraySoal, i));
            char *gamesoal = toString(Get(arraySoal, i));
            // printf("After toString\n");
            fputs(gamesoal, savefile);
            // printf("After fputs\n");
            // printf("%d", i);
            if (i != arraySoal.Neff -1)
            {
                fputs("\n", savefile);
            }
            // printf("Passed if\n");
        }
        fclose(savefile);

        printf("\n-------------------------------\n");
        printf("Berhasil menyimpan listkata  ^^\n");
        printf("-------------------------------\n");
    }

}

void TampilanGaris(int count_salah){
    if (count_salah == 0){
        printf("======================================\n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("======================================\n");
    }
    else if (count_salah == 1){
        printf("======================================\n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (count_salah == 2){
        printf("======================================\n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (count_salah == 3){
        printf("======================================\n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (count_salah == 4){
        printf("======================================\n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                   -------||          \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (count_salah == 5){
        printf("======================================\n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                   -------||          \n");
        printf("                   O      ||          \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (count_salah == 6){
        printf("======================================\n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                   -------||          \n");
        printf("                   O      ||          \n");
        printf("                  /       ||          \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (count_salah == 7){
        printf("======================================\n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                   -------||          \n");
        printf("                   O      ||          \n");
        printf("                  / \\     ||          \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (count_salah == 8){
        printf("======================================\n");
        printf("                                      \n");
        printf("                                      \n");
        printf("                   -------||          \n");
        printf("                   O      ||          \n");
        printf("                  /|\\     ||          \n");
        printf("                          ||          \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (count_salah == 9){
        printf("======================================\n");
        printf("        EHH KOK GUA DISINI!!??        \n");
        printf("             TOLONGGG!!!              \n");
        printf("                   -------||          \n");
        printf("                   O      ||          \n");
        printf("                  /|\\     ||          \n");
        printf("                  /       ||          \n");
        printf("                          ||          \n");
        printf("======================================\n");
    } else if (count_salah == 10){
        printf("======================================\n");
        printf("            TIIIIDAAAAKKK!!!!!!       \n");
        printf("        AARGHHH!!     AAAAAARGHHH!!   \n");
        printf("     AAAARGHHH!!   -------||  ARGHH!  \n");
        printf("        AARGHHH!!  O      || ARGHH!   \n");
        printf("     AAAARGHHH!!  /|\\     ||  ARGHH!  \n");
        printf("        AARGHHH!! / \\     || ARGHH!   \n");
        printf("     AAAARGHHH!!          ||  ARGHH!  \n");
        printf("======================================\n");
    }
}

void SetElmt(Word *Lbenar , char huruf, int indeks){
    Lbenar->TabChar[indeks] = huruf;
}

void DigitBenar(Word LSoal, char huruf, Word* Lsalah, Word* Lbenar, int *count_salah, int *point){
    int i = 0;
    int count = 0;
    boolean benar = false;
    while (i<LSoal.Length){
        if(LSoal.TabChar[i] == huruf){
            SetElmt(Lbenar,huruf,i);
            // Lbenar->panjang++;
            benar = true;
            count +=1;
        } 
        i++;
    }
    SetElmt(Lsalah,huruf,Lsalah->Length);
    Lsalah->Length++;
    if (!benar){
        printf("Anda salah menebak huruf, kesempatan berkurang 1\n");
        *count_salah +=1;
    }
    else if(benar){
        printf("Selamat anda berhasil menebak %d huruf pada giliran ini\n",count);
        // *point += count;
    }
}

void PrintList(Word L, boolean benar){
    int i;
    if(benar){
        for(i=0;i<(L).Length;i++){
            printf("%c ", (L).TabChar[i]);
        }
    }
    else{
        for(i=0;i<(L).Length;i++){
            printf("%c", (L).TabChar[i]);
        }
    }
}

void TampilanGame(Word Lbenar ,Word Lsalah, Word Lsoal,int urutan, int count_salah, int count_word_guessed){
    TampilanGaris(count_salah);
    // printSoal(urutan);
    printf("KATA %d\n",count_word_guessed + 1);
    printf("SOAL :");PrintList(Lsoal,false);printf("\n");
    printf("Tebakan sebelumnya : ");
    PrintList(Lsalah,true);
    printf("\nKata : ");
    PrintList(Lbenar,true);
    printf("\nKesempatan : ");
    printf("%d", (10-count_salah));
}

boolean isExist (char huruf, Word Lsalah){
    boolean found = false;
    int i=0;
    while (i<Lsalah.Length && !found){
        if (huruf == Lsalah.TabChar[i]){
            found = true;
        }
        i++;
    }
    return found;
}

boolean isMark(Word Lbenar){
    int i = 0;
    boolean mark = false;
    while(i<Lbenar.Length && !mark){
        if (Lbenar.TabChar[i] == LINE){
            mark = true;
        }
        i++;
    }
    return mark;
}

boolean IsFinished (int count_salah, TabWord array){
    return (count_salah >= KESEMPATAN || IsEmpty(array));
}

void TampilanKalah(int count_salah, int point, Word LJawaban){
    TampilanGaris(count_salah);
    printf("Disaat kesempatan sudah habis, disitulah kepala Anda terpenggal\n");
    printf("Anda berhasil mendapatkan %d point\n", point);
    printf("\nJawaban benar: ");
    PrintList(LJawaban,true);
    printf("\n");
}

void HangMan(int *score){
    srand(time(0));
    boolean opened_file = false;
    TabWord arrayWord;
    TabWord arraySoal;
    MakeTabWord(&arrayWord);
    MakeTabWord(&arraySoal);
    ListofWord(&arrayWord,&arraySoal,&opened_file);
    // PrintTabWord(arraySoal);
    // PrintTabWord(arrayWord);
    // PrintTabWord(arrayWord);
    if(opened_file){
        // printf("Selamat datang di game hangman!!\nSemoga kamu ga menyesal bermain game ini!!\n\n");
        boolean invalid_input;
        boolean word_guessed;
        boolean game_started = false;
        char input;
        int word_guessed_count = 0;
        int point = 0;
        int count_salah = 0;
        Word LJawaban;
        Word Lsalah;
        Word Lbenar;
        Word LSoal;
        menuawal(&arrayWord,&arraySoal,&game_started);
        if(game_started){
            TabWord CopyArrayWord = CopyTabWord(arrayWord);
            TabWord CopyArraySoal = CopyTabWord(arraySoal);
            while(!IsFinished(count_salah,CopyArrayWord)){
                word_guessed = false;
                int urutan = (rand()%CopyArrayWord.Neff);
                LJawaban = CopyArrayWord.TW[urutan];
                LSoal = CopyArraySoal.TW[urutan];
                CreateWord(&Lbenar, LJawaban.Length,true);
                CreateWord(&Lsalah,26,false);
                while(!IsFinished(count_salah, CopyArrayWord) && !word_guessed){
                    invalid_input = true;
                    TampilanGame(Lbenar, Lsalah, LSoal,urutan,count_salah, word_guessed_count);
                    // printf("\nJawaban: ");
                    // PrintList(LJawaban,true);
                    while(!IsFinished(count_salah,CopyArrayWord) && invalid_input && !word_guessed){
                        printf("\nMASUKAN TEBAKAN :");
                        STARTCMD(true);
                        if(currentCommand.Length == 1){
                            if(currentCommand.TabChar[0] >= 'A' && currentCommand.TabChar[0] <= 'Z'){
                                input = currentCommand.TabChar[0];
                                if(isExist(input,Lsalah)){
                                    printf("Bro... Lu dah pernah nebak huruf %c, coba tebak huruf lain\n",input);
                                }
                                else{
                                    //clear();
                                    DigitBenar(LJawaban, input, &Lsalah, &Lbenar,&count_salah,&point);
                                    invalid_input = false;
                                    if(!isMark(Lbenar)){
                                        printf("Selamat bro... Anda berhasil menebak kata\n");
                                        word_guessed = true;
                                        printf("\nJawaban benar: ");
                                        PrintList(LJawaban,true);
                                        point += LJawaban.Length;
                                        printf("\nPoint anda bertambah %d\n",LJawaban.Length);
                                        printf("Menuju kata selanjutnya\n");
                                        DeleteAt(&CopyArrayWord,urutan);
                                        DeleteAt(&CopyArraySoal,urutan);

                                        word_guessed_count +=1;
                                    }
                                }
                            }
                            else{
                                printf("Sori bro, coba situ input hurufnya di capslocsk dan tentu inputnya harus huruf yakk!\n"); 
                            }
                        }
                        else{
                            printf("Input tidak valid, coba dibenerin lagi bro inputannya\n");
                        }
                    }
                }
            }
            if (IsEmpty(CopyArrayWord)){
                printf("Selamat bro... Anda berhasil menebak semua kata dengan tepat\n");
                printf("Anda berhasil mendapatkan %d point\n", point);
            }
            else{
                TampilanKalah(count_salah,point,LJawaban);
            }
            *score = point;
        }
        else
        {
            *score = -999;
        }
        savelist(arrayWord,arraySoal);
    }
    else{
        printf("File tidak bisa dibuka\n");
    }
}

// int main(){
//     int score;
//     HangMan(&score);
// }