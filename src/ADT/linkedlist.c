#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

MatrixNode* create_node(){

    MatrixNode *temp = (MatrixNode *)malloc(sizeof(MatrixNode));
    if(temp == NULL){
        printf("Memory alloc error");
    }
    temp->next_col = NULL;
    temp->next_row = NULL;
    temp->prev_col = NULL;
    temp->prev_row = NULL;
    temp->next = NULL;
    temp->prev = NULL;
    temp->info = "   ";
    return temp;
}

void create_linked_list_matrix(List *head, int rows, int cols, int headrow, int headcols, int *n){
    int row_temp = headrow;
    int col_temp = headcols;

    MatrixNode *node, *mat[rows][cols];
    int r, c;
    for(r = rows - 1; r >= 0; r--){
        for(c = cols - 1; c >=0; c--){
            node = create_node();
            if(r < rows - 1){
                node->next_row = mat[r+1][c];
            }
            if(c < cols - 1){
                node->next_col = mat[r][c+1];
            }
            mat[r][c] = node;
        }
    }
    for(r=0;r<=rows-1;r++){
        for(c=0;c<=cols-1;c++){
            if(r > 0){
                mat[r][c]->prev_row = mat[r-1][c];
                if (r == rows - 1){
                    mat[r][c]->next_row = mat[0][c];
                }
            }
            else if (r == 0){
                mat[r][c]->prev_row = mat[rows - 1][c];
            }
            if(c > 0){
                mat[r][c]->prev_col = mat[r][c-1];
                if (c == cols - 1){
                    mat[r][c]->next_col = mat[r][0];
                }
            }
            else if (c==0){
                mat[r][c]->prev_col = mat[r][cols-1];
            }
        }
    }
    head->zero = mat[0][0];
    head->First = mat[headrow][headcols];
    head->First->info = " H ";
    address P = head->First;
    while(*n<3){
        //next : dari head ke tail
        //prev: dari tail ke head
        if(col_temp == 0){
            P->next = P->prev_row;
            P = P->next;
            // char angka = n + '0'; 
            P->info = makebody(*n);
            P->prev = P->next_row;
            row_temp -=1;
        }
        else if(col_temp>0){
            P->next = P->prev_col;
            P = P->next; 
            P->info = makebody(*n);
            P->prev = P->next_col;
            col_temp -=1;
        }
        *n +=1;
    }
    head->Last = P;
    
}


// void display_matrix(List head){
//     address row = head.First;
//     while(row){
//         address col = row;
//         while(col){
//             printf("%s\t", col->info);
//             col = col->next_col;
//         }
//         printf("\n");
//         row = row->next_row;
//     }
// }

char *makebody(int n){
    char* body;
    int jumlah_badan = n;
    int i;
    body = (char*) malloc(4 * sizeof(char));
    body[0] = ' ';
    if(n <= 9){
        body[1] = jumlah_badan + '0';
        body[2] = ' ';
        body[3] = '\0';
    }
    else{
        while(jumlah_badan >=10){
            jumlah_badan -=10;
            i +=1;
        }
        body[1] = i + '0';
        body[2] = jumlah_badan + '0';
        body[3] = '\0';
    }
    return body;
}

void movesnake(List* head, char move, int *n){
    char* del_huruf = "   ";
    char* huruf;
    address row = head->Last;
    if (head->First != head->Last){
        head->Last = row->prev;
    }
    while(row != head->First){
        huruf = row->info;
        row->info = del_huruf;
        del_huruf = huruf;
        row = row->prev;
    }
    //row = head->first
    huruf = row->info;
    row->info = del_huruf;
    del_huruf = huruf;

    if (move == 'd'){
        row->prev = row->next_col;
        row = row->prev;
        huruf = row->info;
        row->info = del_huruf;
        head->First = row;
    }
    else if (move == 'a'){
        row->prev = row->prev_col;
        row = row->prev;
        huruf = row->info;
        row->info = del_huruf;
        head->First = row;
    }
    else if(move == 's'){
        row->prev = row->next_row;
        row = row->prev;
        huruf = row->info;
        row->info = del_huruf;
        head->First = row;
    }
    else if(move == 'w'){
        row->prev = row->prev_row;
        row = row->prev;
        huruf = row->info;
        row->info = del_huruf;
        head->First = row;
    }

    if(huruf == " o "){
            address tail = head->Last;
            if (tail->prev_col->info == "   "){
                tail->next = tail->prev_col;
                tail = tail->next;
                tail->info = makebody(*n);
                tail->prev = tail->next_col;
                head->Last = tail;
            }
            else if (tail->next_col->info == "   "){
                tail->next = tail->next_col;
                tail = tail->next;
                tail->info = makebody(*n);
                tail->prev = tail->prev_col;
                head->Last = tail;
            }
            else if(tail->prev_row->info == "   "){
                tail->next = tail->prev_row;
                tail = tail->next;
                tail->info = makebody(*n);
                tail->prev = tail->next_row;
                head->Last = tail;
            }
            else if(tail->next_row->info == "   "){
                tail->next = tail->next_row;
                tail = tail->next;
                tail->info = makebody(*n);
                tail->prev = tail->prev_row;
                head->Last = tail;
            }
            *n +=1;
        }
        // printf("%c\n",head->First->info);
}

void MakeFood(List head, address *food){
    *food = head.zero;
    int row = rand() % 5;
    int cols = rand() % 5;
    int m = 0;
    int n = 0;
    while(m < row){
        *food = (*food)->next_row;
        m +=1;
    }
    while(n < cols){
        *food = (*food)->next_col;
        n +=1;
    }
}

void SummonFood(List *head){
    address food = head->zero;
    if(!isFood(*head)){
        MakeFood(*head,&food);
        while(food->info != "   "){
            MakeFood(*head,&food);
        }
        food->info = " o ";
    }
}


boolean isFood(List head){
    address row = head.zero;
    boolean found = false;
    int baris = 0;
    int kolom = 0;
    while(baris < 5 && !found){
        address cols = row;
        while(kolom < 5 && !found){
            if(cols->info == " o "){
                found = true;
            }
            else{
                cols = cols->next_col; 
                kolom +=1;
            }
        }
        kolom = 0;
        row = row->next_row;
        baris +=1;
    }
    return found;
}

boolean isNabrak(List head, char input){
    boolean nabrak = false;
    address P = head.First;
    if (input == 'd'){
        if (P->next_col->info != "   " && P->next_col->info != " o "){
            nabrak = true;
        }
    }
    else if(input == 'w'){
        if(P->prev_row->info != "   " && P->prev_row->info != " o "){
            nabrak = true;
        }
    }
    else if(input == 'a'){
        if(P->prev_col->info != "   " && P->prev_col->info != " o "){
            nabrak = true;
        }
    }
    else if(input == 's'){
        if(P->next_row->info != "   " && P->next_row->info != " o "){
            nabrak = true;
        }
    }
    return nabrak;
}

void MakeMeteor(List head, address *meteor){
    *meteor = head.zero;
    int baris = rand() % 5;
    int kolom = rand() % 5;
    int m = 0;
    int n = 0;
    while(m < baris){
        *meteor = (*meteor)->next_row;
        m +=1;
    }
    while(n < kolom){
        *meteor = (*meteor)->next_col;
        n +=1;
    }
}

void SummonMeteor(List *head, boolean* end, int *n){
    address meteor = head->zero;
    MakeMeteor(*head,&meteor);
    while(meteor->info == " o " || meteor->info == " X "){
        MakeMeteor(*head,&meteor);
    }
    if(meteor->info != "   "){
        if(meteor->info == " H "){
            printf("Kepala snake terkena meteor!\n");
            printf("Game over!\n");
            *end = true;
            meteor->info = " M ";
            *n -=1;
        }
        else if(meteor == head->Last){
            printf("Anda terkena meteor!\n");
            head->Last = meteor->prev;
            meteor->info = " M ";
            meteor->prev = NULL;
            *n -=1;
        }
        else{
            printf("Anda terkena meteor!\n");
            address tail = head->Last;
            address body = tail->prev;
            int count = *n - 2;
            while(tail->prev != meteor){
                tail->info = makebody(count);
                count -=1;
                // tail->info = ' ';
                // tail->next = NULL;
                // tail = body;
                // body = body->next;
                tail = tail->prev;
            }
            tail->prev = meteor->prev;
            tail->info = makebody(count);
            meteor->info = " M ";
            meteor->prev = NULL;
            *n -=1;
        }
    }
    // else if(meteor->info == 'o'){
    //     printf("Makanan tertimpa!\n");
    // }
    else{
        printf("Anda beruntung tidak terkena meteor! Silahkan lanjutkan permainan\n");
        meteor->info = " M ";
    }
}

void MeteorDisappear(List *head){
    int i,j;
    address row = head->zero;
    int baris = 0;
    int kolom = 0;
    while(baris < 5){
        address col = row;
        while(kolom < 5){
            if(col->info == " M "){
                col->info = "   ";
            }
            col = col->next_col;
            kolom +=1;
        }
        kolom = 0;
        row = row->next_row;
        baris +=1;
    }
}

boolean isNabrakMeteor(List head, char input){
    boolean nabrak = false;
    address P = head.First;
    if (input == 'd'){
        if (P->next_col->info == " M "){
            nabrak = true;
        }
    }
    else if(input == 'w'){
        if(P->prev_row->info == " M "){
            nabrak = true;
        }
    }
    else if(input == 'a'){
        if(P->prev_col->info == " M "){
            nabrak = true;
        }
    }
    else if(input == 's'){
        if(P->next_row->info == " M "){
            nabrak = true;
        }
    }
    return nabrak;
}

void makeobstacle(List head, address *obstacle){
    *obstacle = head.zero;
    int baris = rand() % 5;
    int kolom = rand() % 5;
    int n = 0;
    int m = 0;
    while (m < baris){
        *obstacle = (*obstacle)->next_row;
        m +=1;
    }
    while (n < kolom){
        *obstacle = (*obstacle)->next_col;
        n +=1;
    }
}

void summonobstacle(List* head, int count){
    int i = 0;
    address obstacle;
    while(i < count){
        makeobstacle(*head,&obstacle);
        while(obstacle->info != "   "){
            makeobstacle(*head,&obstacle);
        }
        obstacle->info = " X ";
        i +=1;
    }
}