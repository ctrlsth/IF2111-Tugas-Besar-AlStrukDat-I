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
    printf("Karena queue yang dibuat masih kosong, maka isEmpty akan mengeluarkan true.\n")

    STARTCMD();
    //Memasukkan value ke dalam antrian atau queue kosong
    printf("")
    enqueue(&q, currentCommand);
    //Mengecek apakah isi dari queue penuh (seharusnya tidak penuh)
    isFull(q);
    //Menampilkan isi dari antrian/queue
    displayQueue(q);
    //Mengeluarkan value dari queue (Queue akan kembali kosong)
    Word val;
    dequeue(&q, &val);
    displayQueue(q); //Seharusnya menampilkan bahwa antrian kosong
}

