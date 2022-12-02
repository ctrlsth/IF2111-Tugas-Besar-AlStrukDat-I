#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

MatrixNode* create_node(){

    MatrixNode *temp = (MatrixNode *)malloc(sizeof(MatrixNode));
    if(temp == NULL){
        printf("Alokasi Memori error\n");
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

void create_linked_list_matrix(List *head, int rows, int cols, int headrow, int headcols){
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
}

void createsnake(List* head,int headrow, int headcols, int *n){
    int col_temp = headcols;
    int row_temp = headrow;
    head->First->info = " H ";
    addressNode P = head->First;
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

char *makebody(int n){
    char* body;
    int jumlah_badan = n;
    int i = 0;
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
    addressNode row = head->Last;

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

    if (move == 'D'){
        row->prev = row->next_col; //Prev(row) menjadi next col
        row->prev->next = row; //Next(Prev(row)) menjadi row
        row = row->prev; 
        huruf = row->info;
        row->info = del_huruf;
    }
    else if (move == 'A'){
        row->prev = row->prev_col;
        row->prev->next = row;
        row = row->prev;
        huruf = row->info;
        row->info = del_huruf;
    }
    else if(move == 'S'){
        row->prev = row->next_row;
        row->prev->next = row;
        row = row->prev;
        huruf = row->info;
        row->info = del_huruf;
    }
    else if(move == 'W'){
        row->prev = row->prev_row;
        row->prev->next = row;
        row = row->prev;
        huruf = row->info;
        row->info = del_huruf;
    }

    if (head->First->info != head->Last->info){
        head->First = row; //row menjadi head->first
        head->Last = head->Last->prev; //head->Last maju karena ekornya juga maju
    }
    else{
        head->First = row; // head->first dan head->last menjadi row karena hanya tersisa kepala saja
        head->Last = row;
    }

    if( (strcompare(huruf," o "))){ //Memakan makanan
            addressNode tail = head->Last;
            if ((strcompare(tail->prev_col->info,"   "))){
                tail->next = tail->prev_col;
                tail = tail->next;
                tail->info = makebody(*n);
                tail->prev = tail->next_col;
                head->Last = tail;
            }
            else if (strcompare(tail->next_col->info,"   ")){
                tail->next = tail->next_col;
                tail = tail->next;
                tail->info = makebody(*n);
                tail->prev = tail->prev_col;
                head->Last = tail;
            }
            else if(strcompare(tail->prev_row->info,"   ")){
                tail->next = tail->prev_row;
                tail = tail->next;
                tail->info = makebody(*n);
                tail->prev = tail->next_row;
                head->Last = tail;
            }
            else if(strcompare(tail->next_row->info,"   ")){
                tail->next = tail->next_row;
                tail = tail->next;
                tail->info = makebody(*n);
                tail->prev = tail->prev_row;
                head->Last = tail;
            }
            *n +=1;
        }
}

void MakeFood(List head, addressNode *food, int n_row, int n_cols){
    *food = head.zero;
    int row = rand() % n_row;
    int cols = rand() % n_cols;
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

void SummonFood(List *head, int n_row, int n_cols){
    addressNode food = head->zero;
    if(!isFood(*head,n_row,n_cols)){
        MakeFood(*head,&food,n_row,n_cols);
        while(!(strcompare(food->info,"   "))){
            MakeFood(*head,&food,n_row,n_cols);
        }
        food->info = " o ";
    }
}


boolean isFood(List head,int n_row, int n_cols){
    addressNode row = head.zero;
    boolean found = false;
    int baris = 0;
    int kolom = 0;
    while(baris < n_row && !found){
        addressNode cols = row;
        while(kolom < n_cols && !found){
            if(strcompare(cols->info," o ")){
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
    //apakah ular nabrak obstacle
    boolean nabrak = false;
    addressNode P = head.First;
    if (input == 'D'){
        if (strcompare(P->next_col->info," X ")){
            nabrak = true;
        }
    }
    else if(input == 'W'){
        if(strcompare(P->prev_row->info," X ")){
            nabrak = true;
        }
    }
    else if(input == 'A'){
        if(strcompare(P->prev_col->info," X ")){
            nabrak = true;
        }
    }
    else if(input == 'S'){
        if(strcompare(P->next_row->info," X ")){
            nabrak = true;
        }
    }
    return nabrak;
}

boolean isNabrakBody(List head, char input){
    addressNode P = head.First;
    boolean nabrak = false;
    if (input == 'D'){
        if (!strcompare(P->next_col->info, "   ") && !strcompare(P->next_col->info, " X ") && !strcompare(P->next_col->info, " o ") && !strcompare(P->next_col->info, " M ")){
            if(P->next == head.Last){
                nabrak = true;
            }
            else{
                // printf("%s\n",P->next->info);
                if(P->next_col != head.Last){
                    nabrak = true;
                }
            }
        }
    }
    else if(input == 'W'){
        if((!strcompare(P->prev_row->info,"   ") && !strcompare(P->prev_row->info," X ") && !strcompare(P->prev_row->info," o ") && !strcompare(P->prev_row->info," M "))){
            if(P->next == head.Last){
                nabrak = true;
            }
            else{
                // printf("%s\n",P->next->info);
                if(P->prev_row != head.Last){
                    nabrak = true;
                }
            }
        }
    }
    else if(input == 'A'){
        if((!strcompare(P->prev_col->info,"   ") && !strcompare(P->prev_col->info," X ") && !strcompare(P->prev_col->info, " o ") && !strcompare(P->prev_col->info," M "))){
            if(P->next == head.Last){
                nabrak = true;
            }
            else{
                // printf("%s\n",P->next->info);
                if(P->prev_col != head.Last){
                    nabrak = true;
                }
            }
        }
    }
    else if(input == 'S'){
        if((!strcompare(P->next_row->info,"   ") && !strcompare(P->next_row->info," X ") && !strcompare(P->next_row->info, " o ") && !strcompare(P->next_row->info," M "))){
            if(P->next == head.Last){
                nabrak = true;
            }
            else{
                // printf("%s\n",P->next->info);
                if(P->next_row != head.Last){
                    nabrak = true;
                }
            }
        }
    }
    return nabrak;
}

boolean isNotMoveable(List head){
    return (isNabrakBody(head,'A') && isNabrakBody(head,'W') && isNabrakBody(head,'S') && isNabrakBody(head,'D'));
}

void MakeMeteor(List head, addressNode *meteor, int n_row, int n_cols){
    *meteor = head.zero;
    int baris = rand() % n_row;
    int kolom = rand() % n_cols;
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

void SummonMeteor(List *head, boolean* end, int *n, int n_row, int n_cols){
    addressNode meteor = head->zero;
    MakeMeteor(*head,&meteor,n_row,n_cols);
    while(strcompare(meteor->info," o ") || strcompare(meteor->info, " X ")){
        MakeMeteor(*head,&meteor,n_row,n_cols);
    }
    if(meteor->info != "   "){
        if(strcompare(meteor->info, " H ")){
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
            meteor->prev->next = NULL;
            meteor->prev = NULL;
            *n -=1;
        }
        else{
            printf("Anda terkena meteor!\n");
            addressNode tail = head->Last;
            addressNode body = tail->prev;
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
            //tail->prev == meteor
            tail->prev = meteor->prev;
            tail->info = makebody(count);
            tail = tail->prev;
            tail->next = meteor->next;
            meteor->info = " M ";
            meteor->prev = NULL;
            meteor->next = NULL;
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

void MeteorDisappear(List *head, int n_row, int n_cols){
    int i,j;
    addressNode row = head->zero;
    int baris = 0;
    int kolom = 0;
    while(baris < n_row){
        addressNode col = row;
        while(kolom < n_cols){
            if(strcompare(col->info, " M ")){
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
    addressNode P = head.First;
    if (input == 'D'){
        if (strcompare(P->next_col->info, " M ")){
            nabrak = true;
        }
    }
    else if(input == 'W'){
        if(strcompare(P->prev_row->info," M ")){
            nabrak = true;
        }
    }
    else if(input == 'A'){
        if(strcompare(P->prev_col->info," M ")){
            nabrak = true;
        }
    }
    else if(input == 'S'){
        if(strcompare(P->next_row->info," M ")){
            nabrak = true;
        }
    }
    return nabrak;
}

void makeobstacle(List head, addressNode *obstacle,int n_row, int n_cols){
    *obstacle = head.zero;
    int baris = rand() % n_row;
    int kolom = rand() % n_cols;
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

void summonobstacle(List* head, int count,int n_row, int n_cols){
    int i = 0;
    addressNode obstacle;
    while(i < count){
        makeobstacle(*head,&obstacle,n_row,n_cols);
        while(!strcompare(obstacle->info, "   ")){
            makeobstacle(*head,&obstacle,n_row,n_cols);
        }
        obstacle->info = " X ";
        i +=1;
    }
}