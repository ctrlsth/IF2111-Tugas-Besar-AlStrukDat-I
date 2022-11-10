#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "boolean.h"
#include "DinnerDash.h"

const int IDX_UNDEF = -1;
const int CAPACITY = 15;

typedef struct {
    char Makanan[3];
    int DurasiMasak;
    int Ketahanan;
    int Harga;
} Pesanan;

typedef struct {
    Pesanan buffer[15];
    int IdxHead;
    int IdxTail;
    int Count;
} Queue;

void CreateQueue (Queue *q){
    (*q).IdxHead = IDX_UNDEF;
    (*q).IdxTail = IDX_UNDEF;
    (*q).Count = 0;
}

boolean IsEmpty(Queue q){
    return (((q).IdxHead == IDX_UNDEF) && ((q).IdxTail == IDX_UNDEF));
}

void TabelPesanan(Queue qPesanan){
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("—---------------------------------------------\n");
    if (IsEmpty(qPesanan)){
        printf("        |                |           |\n");
    } else {
        for(int i = 0; i<(qPesanan).Count; i++){
            printf("%s      | %d             | %d        | %d\n", (qPesanan).buffer[i].Makanan, (qPesanan).buffer[i].DurasiMasak, (qPesanan).buffer[i].Ketahanan, (qPesanan).buffer[i].Harga);
        }
    }
}

void TabelMasakan(Queue qDiMasak){
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("—-----------------------------\n");
    if (IsEmpty(qDiMasak)){
        printf("        |\n");
    } else {
        boolean found = false;
        for(int i = 0; i<(qDiMasak).Count; i++){
            if ((qDiMasak).buffer[i].DurasiMasak>0){
                printf(" %s      | %d\n", (qDiMasak).buffer[i].Makanan, (qDiMasak).buffer[i].DurasiMasak);
                found = true;
            }
        }

        //ini buat ngantisipasi kasus kalo yg di masak durasinya ga ad yg diatas 0
        if (!found){
            printf("        |\n");
        }
    }
}

void TabelSajian(Queue qDiMasak){
    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    printf("—-----------------------------\n");
    if (IsEmpty(qDiMasak)){
        printf("        |\n");
    } else {
        boolean found = false;
        for(int i = 0; i<(qDiMasak).Count; i++){
            if ((qDiMasak).buffer[i].DurasiMasak<=0 && (qDiMasak).buffer[i].Ketahanan>0){
                printf(" %s      | %d\n", (qDiMasak).buffer[i].Makanan, (qDiMasak).buffer[i].Ketahanan);
                found = true;
            }
        }
        
        //ini buat ngantisipasi kasus kalo ga ada yang ketahanannya diatas > 0
        if (!found){
            printf("        |\n");
        }
    }
}

Pesanan RandomPesanan(int noAntrian){
    Pesanan p;
    int x = AcakDurasi();
    int y = AcakDurasi();
    int z = AcakHarga();
    (p).Makanan[0] = 'M';
    if (noAntrian < 10){
        (p).Makanan[1] = noAntrian + 48; //biar jadi string, pake trik ASCII
        (p).Makanan[2] = '\0';
    } else {
        (p).Makanan[1] = '1';
        (p).Makanan[2] = noAntrian + 48;
        (p).Makanan[3] = '\0';
    }
    (p).DurasiMasak = x;
    (p).Ketahanan = y;
    (p).Harga = z;

    return (p);
}

int AcakHarga(){
    return ((rand()%40001) + 10000);
}

int AcakDurasi(){
    return ((rand()%5)+1);
}

void Inisialisasi(Queue *qPesanan){
    int i = 0;
    for (i; i<3; i++){
        Pesanan p = RandomPesanan(i);
        enqueue(qPesanan, p);
    }
}

void enqueue(Queue *q, Pesanan p){
    if (IsEmpty(*q)){
        (*q).IdxHead = 0;
        (*q).IdxTail = 0;
        (*q).buffer[0] = p;
        (*q).Count = 1;
    } else {
        (*q).IdxTail ++;
        (*q).buffer[(*q).IdxTail] = p;
        (*q).Count ++;
    }
}

void dequeue(Queue *q, Pesanan *p){
    *p = (*q).buffer[(*q).IdxTail];
    if ((*q).Count == 1){
        (*q).IdxHead = IDX_UNDEF;
        (*q).IdxTail = IDX_UNDEF;
        (*q).Count = 0;
    } else {
        for (int i = 0; i<((*q).IdxTail)+1; i++){
            (*q).buffer[i] = (*q).buffer[i+1];
        };
        (*q).IdxTail --;
        (*q).Count --;
    }
}

void eliminate(Queue *q, char FoodId[]){
    for (int idx = GetIdx((*q), FoodId); idx<(*q).IdxTail; idx++){
        (*q).buffer[idx] = (*q).buffer[idx + 1];
    }
}

int GetIdx(Queue q, char FoodId[]){
    boolean found = false;
    int idx = 0;
    if (IsDuaDigit(FoodId)){
        //nyari yg dua digit, biar perbandingannya ga susah
        while(!IsDuaDigit((q).buffer[idx].Makanan)){
            idx++;
        }
        while((idx<=q.IdxTail) && (!found)){
            if (q.buffer[idx].Makanan[2] == FoodId[2]){
                found = true;
            }
            idx ++;
        }
        if (found){
            return (idx-1);
        } else {
            return (IDX_UNDEF);
        }
    } else {
        while((idx<=q.IdxTail) && (!found)){
            if (q.buffer[idx].Makanan[1] == FoodId[1]){
                found = true;
            }
            idx ++;
        }
        if (found){
            return (idx-1);
        } else {
            return (IDX_UNDEF);
        }

    }
}

boolean IsDuaDigit(char str[]){
    if (str[1] == '1' && str[3] == '\0'){
        return (true);
    }else {
        return (false);
    }
}

int GetId(char str[]){
    if (IsDuaDigit(str)){
        return (10 + (str[2]-48));
    } else {
        return (str[1]-48);
    }
}

boolean IsFinish(Queue qPesanan, Queue qSelesai){
    return ((qPesanan).Count==8 || (qSelesai).Count==15); //count == 8 biar lebih dari 7
}

void Berkurang(Queue *qDiMasak){
    for(int i = 0; i < (*qDiMasak).IdxTail + 1; i++){
        if((*qDiMasak).buffer[i].DurasiMasak <= 0){
            (*qDiMasak).buffer[i].Ketahanan --; 
        } else {
            (*qDiMasak).buffer[i].DurasiMasak --;
        }
    }
}

void Cook(Queue qPesanan, Queue *qDiMasak, char FoodId[]){
    if ((*qDiMasak).Count < 6){
        enqueue(qDiMasak, qPesanan.buffer[GetIdx(qPesanan, FoodId)]);
        if (GetIdx(qPesanan, FoodId) != IDX_UNDEF){
            printf("Berhasil memasak M%d", GetId(FoodId));
        }
    } else {
        printf("Memasak > 5 makanan dalam satu waktu merupakan sebuah tindakan yang dilarang");
    }
}

void Serve(Queue *qPesanan, Queue *qDiMasak, Queue *qSelesai, char FoodId[]){
    if (GetIdx(*qDiMasak, FoodId) == IDX_UNDEF){
        printf("Pesanan M%d belum dimasak\n", GetId(FoodId));
    } else {
        if ((*qDiMasak).buffer[GetIdx(*qDiMasak, FoodId)].DurasiMasak > 0){
            printf("Pesanan M%d belum selesai dimasak\n", GetId(FoodId));
        } else {
            Pesanan p;
            int idx = 0;
            while ((*qDiMasak).buffer[idx].Ketahanan<=0){
                dequeue(qDiMasak, &p);
                idx++;
            }
            int idxsec = GetIdx(*qDiMasak, FoodId);
            if (idxsec>0){
                printf("M%d belum bisa disediakan, karena %s belum selesai\n", (*qDiMasak).buffer[idxsec].Makanan, (*qDiMasak).buffer[0].Makanan);
            }else{
                dequeue(qDiMasak, &p);
                enqueue(qDiMasak, p);
                eliminate(qDiMasak, FoodId);
                (*qDiMasak).IdxTail --;
                (*qDiMasak).Count --;
            }
        }
    }
}

boolean IsCook(char command[]){
    boolean lengkap = false;
    if ((command[0] == 'C') || (command[0] == 'c')){
        if ((command[1] == 'O') || (command[1] == 'o')){
            if ((command[2] == 'O') || (command[2] == 'o')){
                if ((command[3] == 'K') || (command[0] == 'k')){
                    lengkap = true;
                }
            }
        }
    }

    return (lengkap);
}

boolean IsServe(char command[]){
    boolean lengkap = false;
    if ((command[0] == 'S') || (command[0] == 's')){
        if ((command[1] == 'E') || (command[1] == 'e')){
            if ((command[2] == 'R') || (command[2] == 'r')){
                if ((command[3] == 'V') || (command[0] == 'v')){
                    if ((command[4] == 'E') || (command[4] == 'e')){
                        lengkap = true;
                    }
                }
            }
        }
    }

    return (lengkap);
}

boolean IsSkip(char command[]){
    boolean lengkap = false;
    if ((command[0] == 'S') || (command[0] == 's')){
        if ((command[1] == 'K') || (command[1] == 'k')){
            if ((command[2] == 'I') || (command[2] == 'i')){
                if ((command[3] == 'P') || (command[0] == 'p')){
                    lengkap = true;
                }
            }
        }
    }

    return (lengkap);
}

boolean IsCommandValid(char command[], char FoodId[], Queue qPesanan, Queue qDiMasak){
    boolean benar = false;
    if (IsCook(command)){
        int idx = GetIdx(qPesanan, FoodId);
        if (idx != IDX_UNDEF){
            int jumlahMasak = 0;
            for (int i = 0; idx<qDiMasak.Count; i++){
                if (qDiMasak.buffer[i].DurasiMasak>0){
                    jumlahMasak ++;
                }
            }
            if (jumlahMasak <= 5){
                benar = true;
            } else {
                printf("Tidak bisa masak lebih dari 5 makanan\n");
            }
        } else {
            printf("Tidak ada pesanan M%d\n", GetId(FoodId));
        }  
    } else if (IsServe(command)){
        int val = GetIdx(qDiMasak, FoodId);
        if (val != IDX_UNDEF){
            if (qDiMasak.buffer[val].DurasiMasak <= 0){
                Pesanan p;
                int idx = 0;
                while(qDiMasak.buffer[idx].Ketahanan <= 0){
                    dequeue (&qDiMasak, &p);
                    idx ++;
                }
                int val0 = GetIdx(qDiMasak, FoodId);
                if (val0 == 0){
                    benar = true;
                } else {
                    printf("%s belum bisa disajikan sebab %s belum selesai dimasak\n", (qDiMasak).buffer[val0].Makanan, (qDiMasak).buffer[0].Makanan);
                }
            } else {
                printf("M%d belum selesai dimasak\n", GetId(FoodId));
            }
        } else{
            printf("M%d tidak sedang dimasak\n", GetId(FoodId));
        }   
    } else if (IsSkip(command)){
        benar = true;
    } else {
        printf("Command tidak sesuai\n");
    }
}

void Komando(char command[], char FoodId[], Queue *qPesanan, Queue *qDiMasak, Queue *qSelesai){
    if (IsCook){
        Cook(*qPesanan, qDiMasak, FoodId);
    } else if (IsSkip){

    } else if (IsServe){
        Serve(qPesanan, qDiMasak, qSelesai, FoodId);
    }
}

int main (){
    printf("\nSelamat Datang di Diner Dash!\n");

    Queue qPesanan, qDiMasak, qSelesai;
    CreateQueue(&qPesanan);
    CreateQueue(&qDiMasak);
    CreateQueue(&qSelesai);
    int saldo = 0;
    int antrian = 2;

    Inisialisasi(&qPesanan);
    while(!IsFinish(qPesanan, qSelesai)){
        TabelPesanan(qPesanan);
        printf("\n");
        TabelMasakan(qDiMasak);
        printf("\n");
        TabelSajian(qDiMasak);
        printf("\n\n");

        Berkurang(&qDiMasak);
        printf("MASUKKAN COMMAND: ");
        char command[5];
        char FoodId[3];
        scanf("%s", command);
        if (IsSkip(command)) {
            
        } else {
            scanf("%s", FoodId);
        }
        while (!IsCommandValid(command, FoodId, qPesanan, qDiMasak)) {
            printf("\nMasukkan Invalid\n");
            printf("MASUKKAN COMMAND: ");
            scanf("%s", command);
            scanf("%s", FoodId);
        }

        printf("\n"); 

        Komando(command, FoodId, &qPesanan, &qDiMasak, &qSelesai);
        antrian++;
        Pesanan p;
        p = RandomPesanan(antrian);
        enqueue(&qPesanan, p);

        printf("\n");
        saldo = 0;
        for (int i = 0; i <= qSelesai.IdxTail; i++){
            saldo += qSelesai.buffer[i].Harga;
        }
        printf("\n");



    } while (!IsFinish(qPesanan, qSelesai));

    printf("\nPermainan Selesai\n");
    printf("qSelesai : %d\n", qSelesai.Count);
    if (qSelesai.Count >= 15) {
        printf("Anda Menang\n");
    } else {
        printf("Anda Kalah\n");
    }



}
    
