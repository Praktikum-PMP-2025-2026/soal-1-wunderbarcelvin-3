/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 3
 *   Hari dan Tanggal    : Senin, 27 April 2026
 *   Nama (NIM)          : Celvin Ello X. Silitonga (13224107)
 *   Nama File           : stormsensor.c
 *   Deskripsi           : Program memiliki beberapa fitur, yakni menambah praktikan baru, mengubah pemilihan soal, mengubah hasil cetakan, dan print nilai total
 *                         Fitur-fitur ini nantinya diubah menjadi subfungsi. Tipe structure yang digunakan memiliki beberapa member, yakni nama (string), NIM (integer),
 *                         pemilihan soal (integer), dan nilai test case dari 1-5 (integer). Adapun untuk tiga fungsi terakhir, karena dikhususkan untuk praktikan tertentu,
 *                         program membutuhkan masukan NIM dan akan dicocokkan dengan isi dynamic array. 
 * 
 * 
 * 
 * Kondisi/Aturan
1. Input berakhir saat membaca -1
2. Semua nilai sebelum -1 dianggap data valid
3. Jumlah data minimal 1
4. Setelah diurutkan naik:
• jika banyak data ganjil, median adalah elemen tengah
• jika genap, median adalah rata-rata dua elemen tengah, dicetak .50 atau .00 bila perlu

CONTOH EKSEKUSI PROGRAM

8 3 7 2 10 -1
COUNT 5
SORTED 2 3 7 8 10
MEDIAN 7
* */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

typedef struct DynamicArray
{
    int* data;
    int length;
} DynamicArray;


void load(DynamicArray* storage);
void bubbleSort(DynamicArray* storage); //coba pakai bubble sort algorithm
void median(DynamicArray* storage);

int main(void){
    DynamicArray array;
    array.length = 3;
    array.data = (int*) malloc(array.length * sizeof(int));

    load(&array);
    bubbleSort(&array);
    median(&array);
    
    free(array.data);
    return 0;
}


void load(DynamicArray* storage){
    int count=0, temp;
    char line[50];
    fgets(line, sizeof(line), stdin);
    
    char* token = strtok(line, " ");
    temp = atoi(token);
    
    while((token)&&(temp!=-1)){ //ketika identified tokennya dan nilai integernya tidak sama dengan -1

        count++;
        if(count>storage->length){
            int* temp = realloc(storage->data, count*sizeof(int));
            if(temp){
                storage->data = temp;
            } else{
                free(temp);
                exit(1);
            }
        }

        storage->data[count-1]=temp;

        token = strtok(NULL, " "); //parsing kembali
        temp = atoi(token);
    }
    
    storage->length = count;
    printf("COUNT %d ", storage->length);
}


void bubbleSort(DynamicArray* storage) {
    int n = storage->length;
    int swapped; //boolean
  
    for (int i = 0; i < n - 1; i++) {
        swapped=0;
        for (int j = 0; j < n - i - 1; j++) {
            if (storage->data[j] > storage->data[j + 1]) {
                int temp = storage->data[j+1];
                storage->data[j+1] = storage->data[j];
                storage->data[j] = temp;
                swapped = 1;
            }
        }
      
        // If no two elements were swapped, then break
        if (!swapped)
            break;
    }

    printf("SORTED ");
    for (int i = 0; i < storage->length; i++)
    {
        printf("%d ", storage->data[i]);
    }
}

void median(DynamicArray* storage){
    int mididx = storage->length/2;
    float median;

    if(storage->length%2==0){
        median = (storage->data[mididx]+storage->data[mididx-1])/2; 
        printf("MEDIAN %.2f", median);
    } else if (storage->length%2==1)
    {
        int temp = storage->data[mididx];
        printf("MEDIAN %d", temp);
    }
}