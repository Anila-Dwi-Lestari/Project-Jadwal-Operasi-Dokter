#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

// List Parent Dokter Menggunakan SLL (Single Linked List)
#define first(L) L.first
#define next(P) (P)->next
#define info(P) (P)->info
#define childJadwal(P) (P)->childJadwal
#define nextRelasi(P) (P)->nextRelasi

struct dokter{
    string idDokter, namaDokter, spesialisDokter;
    int masaKerjaDokter;
};

struct jadwalOP{
    string idJadwalOp, waktuOp, rumahSakit;
};

typedef struct elmListDokter *adrDokter;
typedef struct elmListJadwalOP *adrJadwalOP;
typedef struct elmListRelasi *adrRelasi;

struct listRelasi{
    adrRelasi first;
};

struct elmListDokter{
    dokter info;
    adrRelasi nextRelasi;
    adrDokter next;
};

struct elmListJadwalOP{
    jadwalOP info;
    adrJadwalOP next;
};

struct elmListRelasi{
    adrJadwalOP childJadwal;
    adrRelasi next;
};

struct listDokter{
    adrDokter first;
};

struct listJadwalOP{
    adrJadwalOP first;
};

///////////////////
//PRIMITIF DOKTER//
///////////////////
//createList untuk Dokter
void createList_Dokter(listDokter &L);
//alokasi untuk elemen dokter
adrDokter createElement_Dokter(dokter X);

// Procedure Insert
void insertFirst_Dokter(listDokter &L, adrDokter P);
void insertLast_Dokter(listDokter &L, adrDokter P);
void insertAfter_Dokter(listDokter &L, adrDokter P, adrDokter Prec);

// Procedure Delete
void deleteFirst_Dokter(listDokter &L, adrDokter &P);
void deleteLast_Dokter(listDokter &L, adrDokter &P);
void deleteAfter_Dokter(listDokter &L, adrDokter &P, adrDokter Prec);

// Show List
void printList_Dokter(listDokter L);

// Searching Berdasarkan ID Dokter
adrDokter searching_DokterID(listDokter L, string idDokter);

// Searching Berdasarkan Nama Dokter
adrDokter searching_DokterNama(listDokter L, string namaDokter);

//Count Dokter
int countDokter(listDokter L);

// Menu Dokter
int selectMenu_Dokter();
int mainMenu();
int mainDokter(listDokter &LD);
int menuawal();

///////////////////////////
//PRIMITIF JADWAL OPERASI//
///////////////////////////
void createList_jadwalOP(listJadwalOP &L);
adrJadwalOP createElement_jadwalOP(jadwalOP X);

// Procedure Insert
void insertFirst_jadwalOP(listJadwalOP &L, adrJadwalOP P);
void insertLast_jadwalOP(listJadwalOP &L, adrJadwalOP P);
void insertAfter_jadwalOP(listJadwalOP &L, adrJadwalOP P, adrJadwalOP Prec);

// Procedure Delete
void deleteFirst_jadwalOP(listJadwalOP &L, adrJadwalOP &P);
void deleteLast_jadwalOP(listJadwalOP &L, adrJadwalOP &P);
void deleteAfter_jadwalOP(listJadwalOP &L, adrJadwalOP &P, adrJadwalOP Prec);

// Show List
void printList_jadwalOP(listJadwalOP L);

// Searching Berdasarkan ID Jadwal OP
adrJadwalOP searching_jadwalOP(listJadwalOP L, string idJadwalOp);

//countRelasi
int countJadwalOp(listJadwalOP L);


// Menu Jadwal OP
int selectMenu_jadwalOP();
int mainJadwalOP(listJadwalOP &LJ);
int mainMenu();

///////////////////
//PRIMITIF RELASI//
///////////////////
adrRelasi createElement_Relasi(adrJadwalOP P);
void insertLast_Relasi(listRelasi &L, adrRelasi P);
void deleteElement_Relasi(listDokter L, string idDokter, string idJadwal);
adrRelasi findElement(listDokter L, string PX, string CX);
void printRelasi(listRelasi LR, listDokter LP, listJadwalOP LJ);
void connectParentdanChild(listDokter LD, listJadwalOP, string idDokter, string idJadwal);
int countRelasi(listDokter L, string id);
adrRelasi searchingJadwalfromDokter(listDokter LD, string idJadwal, string idDokter);

int selectMenu_Relasi();
int mainRelasi(listRelasi &LR);
int mainMenu();
#endif // TUBES_H_INCLUDED
