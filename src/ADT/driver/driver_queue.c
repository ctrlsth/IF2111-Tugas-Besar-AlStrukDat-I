#include <stdio.h>
#include "../queue.h"
#include "../array.h"

int main()
{
    // Membuat sebuah queue kosong
    Queue q;
    CreateQueue(&q);
    printf("Dengan begitu, queue yang kosong sudah dibuat.\n");

    // Mengecek apakah queue kosong atau tidak

    isEmpty(q); // Seharusnya jawabannya iya, karena masih belum dimasukkan apa-apa ke dalam queue
    printf("Karena queue yang dibuat masih kosong, maka isEmpty akan mengeluarkan true.\n");

    // Memasukkan value, misalnya nama sebuah game, ke dalam antrian atau queue kosong

    STARTCMD(true);
    printf("Dengan dimulainya prosedur STARTCMD, maka pita kata akan dibaca oleh program.\n");
    enqueue(&q, currentCommand);
    printf("Setelah itu, kata pertama yang dibaca akan dimasukkan ke dalam queue\n");

    // Menampilkan isi dari antrian/queue    

    displayQueue(q);
    printf("Setelah fungsi displayQueue dipanggil, akan ditampilkan antrian atau queue game yang dimiliki oleh user.\n");
    
    // Mengecek apakah isi dari queue penuh (seharusnya tidak penuh)

    isFull(q);
    printf("Karena hanya satu game yang baru dimasukkan ke dalam antrian, maka seharusnya tidak full.\n");

    // Mengeluarkan value dari queue (Queue akan kembali kosong)
    
    Word val;
    dequeue(&q, &val);
    displayQueue(q); //Seharusnya menampilkan bahwa antrian kosong
    printf("Sejak di-dequeue, ketika ditampilkan kembali, queue akan menjadi kosong.\n");

    // Mengecek apakah elemen yang kita ingin cari ada pada queue
    isInQueue(q, currentCommand);
    printf("Akan dicek apakah game yang di-input di awal program adalah game yang kita ingin cari dan berada di queue.\n");
}
