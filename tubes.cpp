#include "tubes.h"

//CREATE LIST//
void createList_Dokter(listDokter &L){
    first(L) = NULL;
}

void createList_jadwalOP(listJadwalOP &L){
    first(L) = NULL;
}

//CREATE ELEMENT//
adrDokter createElement_Dokter(dokter X){
    adrDokter P;
    P = new elmListDokter;
    info(P) = X;
    next(P) = NULL;
    nextRelasi(P) = NULL;
    return P;
}

adrJadwalOP createElement_jadwalOP(jadwalOP X){
    adrJadwalOP P;
    P = new elmListJadwalOP;
    info(P) = X;
    next(P) = NULL;
    return P;
}

adrRelasi createElement_Relasi(adrJadwalOP C){
    adrRelasi R = new elmListRelasi;
    childJadwal(R) = C;
    next(R) = NULL;
    return R;
}



//INSERT DATA//
//Insert Dokter
void insertFirst_Dokter(listDokter &L, adrDokter P){
    adrDokter Q;
    if (first(L) == NULL){
        first(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLast_Dokter(listDokter &L, adrDokter P){
    adrDokter Q;
    if (first(L) == NULL){
        first(L) = P;

    }else{
        Q = first(L);
        while (next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void insertAfter_Dokter(listDokter &L, adrDokter P, adrDokter Prec){
    if (first(L) == NULL || Prec == NULL){
        cout << "Maaf, Data Dokter Kosong" << endl;
    }else if (next(Prec) == first(L)){
        next(P) = first(L);
        next(Prec) = P;
    }else{
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

//Insert Jadwal Operasi
void insertFirst_jadwalOP(listJadwalOP &L, adrJadwalOP P){
    adrJadwalOP Q;
    if (first(L) == NULL){
        first(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLast_jadwalOP(listJadwalOP &L, adrJadwalOP P){
    adrJadwalOP Q;
    if (first(L) == NULL){
        first(L) = P;
    }else{
        Q = first(L);
        while (next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void insertAfter_jadwalOP(listJadwalOP &L, adrJadwalOP P, adrJadwalOP Prec){
    if (first(L) == NULL || Prec == NULL){
        cout << "Maaf, Data Jadwal Operasi Kosong" << endl;
    }else if (next(Prec) == first(L)){
        next(P) = first(L);
        next(Prec) = P;
    }else{
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

//inseert relasi

void insertLastRelasi(listDokter LD, adrRelasi R, string idDokter) {
    adrDokter P;
    adrRelasi Q;

    P = searching_DokterID(LD, idDokter);
    Q = nextRelasi(P);
        if (Q == NULL) {
        nextRelasi(P) = R;
    } else {
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = R;
    }
}

//Connect Parent dan Child
void connectParentdanChild(listDokter LD, listJadwalOP LJ, string idDokter, string idJadwal){
    adrJadwalOP Q = searching_jadwalOP(LJ, idJadwal);
    adrRelasi R = createElement_Relasi(Q);

    insertLastRelasi(LD, R, idDokter);
}


//DELETE DATA//
//Data Dokter
void deleteFirst_Dokter(listDokter &L, adrDokter &P){
    P = first(L);
    if (next(first(L)) == NULL){
        first(L) = NULL;
        next(P) = NULL;
    }else{
        first(L) = next(first(L));
        next(P) = NULL;
    }
}

void deleteLast_Dokter(listDokter &L, adrDokter &P){
    adrDokter Q = first(L);
    if(first(L)==NULL){
        cout<<"DATA DOKTER KOSONG";
    }else if(next(Q) == NULL){
        first(L) = NULL;
    }else{
        while (next(next(Q)) != NULL){
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = NULL;
    }
}

void deleteAfter_Dokter(listDokter &L, adrDokter &P, adrDokter Prec){
    P = first(L);
    if ((first(L) == NULL) || (next(Prec) == NULL)){
        cout << "Data Dokter Gagal Dihapus!" << endl;
    }else{
        P = next(Prec);
        if (next(P) == NULL){
            next(Prec) = NULL;
        }else{
            next(Prec) = next(P);
            next(P) = NULL;
        }
    }
}

//Delete Jadwal Operasi
void deleteFirst_jadwalOP(listJadwalOP &L, adrJadwalOP &P){
    P = first(L);
    if (next(first(L)) == NULL){
        first(L) = NULL;
        next(P) = NULL;
    }else{
        first(L) = next(first(L));
        next(P) = NULL;
    }
}

void deleteLast_jadwalOP(listJadwalOP &L, adrJadwalOP &P){
    adrJadwalOP Q = first(L);
    while (next(next(Q)) != NULL){
        Q = next(Q);
    }
    P = next(Q);
    next(Q) = NULL;
}

void deleteAfter_jadwalOP(listJadwalOP &L, adrJadwalOP &P, adrJadwalOP Prec){
    P = first(L);
    if ((first(L) == NULL) || (next(Prec) == NULL)){
        cout << "Data Dokter Gagal Dihapus!" << endl;
    }else{
        P = next(Prec);
        if (next(P) == NULL){
            next(Prec) = NULL;
        }else{
            next(Prec) = next(P);
            next(P) = NULL;
        }
    }
}

//delete data Relasi
void deleteElement_Relasi(listDokter L, string idDokter, string idJadwal) {
    adrRelasi R, prec;
    adrDokter P = searching_DokterID(L, idDokter);
    R = findElement(L, idDokter, idJadwal);
    if (P == NULL) {
        cout << "data user dengan id " << idDokter << " tidak ditemukan" << endl;
    }else {
        if (nextRelasi(P) == R) {
            nextRelasi(P) = next(R);
        }else if(next(R) == NULL){
            prec = nextRelasi(P);
            while(next(prec)!=R){
                prec = next(prec);
            }
            next(prec) = NULL;
        }else{
            prec = nextRelasi(P);
            while (next(prec) != NULL) {
                prec = next(prec);
            }
            next(prec) = next(R);
        }
    }
}

//SHOW LIST//
void printList_Dokter(listDokter L){
    adrDokter P;
    if (first(L) == NULL){
        cout << "Data Dokter Kosong" << endl;
    }else{
        P = first(L);
        cout << "------------------------Data Dokter--------------------------------------------" << endl;
        while ((P) != NULL){
            cout << "ID Dokter          : " << info(P).idDokter << endl;
            cout << "Nama Dokter        : " << info(P).namaDokter << endl;
            cout << "Spesialis Dokter   : " << info(P).spesialisDokter << endl;
            cout << "Masa Kerja Dokter  : " << info(P).masaKerjaDokter << endl;
            cout << "  " << endl;
            P = next(P);
        }
        cout << endl;
    }
}

void printList_jadwalOP(listJadwalOP L){
    adrJadwalOP P;
    if (first(L) == NULL){
        cout << "Data Jadwal Operasi Kosong" << endl;
    }else{
        P = first(L);
            cout << "----------------------------DATA JADWAL OPERASI---------------------------------" << endl;
        while (P != NULL){
            cout << "ID Jadwal Operasi                      : " << info(P).idJadwalOp << endl;
            cout << "Waktu Operasi                          : " << info(P).waktuOp << endl;
            cout << "Rumah Sakit                            : " << info(P).rumahSakit << endl;
            cout << "" << endl;
            P = next(P);
        }
        cout << endl;
    }
}

void printRelasi(listRelasi LR, listDokter LP, listJadwalOP LC){
    adrDokter P = first(LP);
    int j;
    cout << "-------------------Daftar Dokter-----------------" << endl;
    while (P != NULL) {
        cout << "ID Dokter: " << info(P).idDokter << endl;
        cout << "Nama Dokter : " << info(P).namaDokter << endl<<endl;
        cout << "==Jadwal Operasi== " << endl;

        adrRelasi N = nextRelasi(P);
        j = 1;
        if(N == NULL){
            cout << "Tidak ada jadwal dalam waktu dekat!!"<<endl<<endl;
        }
        while (N != NULL){
            cout << "Jadwal ke-" << j << endl;
            cout <<"ID Jadwal : " << info(childJadwal(N)).idJadwalOp << endl;
            cout<<"Jam Operasi : " <<info(childJadwal(N)).waktuOp<< endl;
            cout<<"Rumah Sakit : " <<info(childJadwal(N)).rumahSakit<< endl<<endl;
            N = next(N);
            j++;
        }
        cout << "--------------------------";
        cout << "--------------------------";
        cout << endl;
        P = next(P);
    }
        cout << "--------------------------"<<endl;
}

//count Dokter
int countDokter(listDokter L) {
    int n = 0;
    adrDokter P = first(L);
    while(P != NULL){
        n++;
        P = next(P);
    }
    return n;
}

//count JadwalOP
int countJadwalOp(listJadwalOP L){
    int n = 0;
    adrJadwalOP p = first(L);

    while (p != NULL) {
        n++;
        p = next(p);
    }
    return n;
}

//Count Relasi
int countRelasi(listDokter L, string id) {
    adrRelasi t;
    adrDokter p = searching_DokterID(L, id);
    int n = 0;

    if(p == NULL){
        return 0;
    }else{
        t = nextRelasi(p);
        while(t!=NULL){
            n++;
            t = next(t);
        }
        return n;
    }
}

//SEARCHING DATA//
//Searching Dokter//
    //Berdasarkan ID Dokter
adrDokter searching_DokterID(listDokter L, string idDokter){
    adrDokter P = first(L);
        while(P != NULL){
            if (info(P).idDokter == idDokter){
                return P;
            }
            P = next(P);
        }
        return NULL;
}
    //Berdasarkan Nama Dokter
adrDokter searching_DokterNama(listDokter L, string namaDokter){
    adrDokter P = first(L);
        while(P != NULL){
            if (info(P).namaDokter == namaDokter){
                return P;
            }
            P = next(P);
        }
        return NULL;
}

// Searching Jadwal OP
    //Berdasarkan ID Jadwal Op
adrJadwalOP searching_jadwalOP(listJadwalOP L, string idJadwalOp){
    adrJadwalOP P = first(L);
        while(P != NULL){
            if (info(P).idJadwalOp == idJadwalOp){
                return P;
            }
            P = next(P);
         }
        return NULL;
}

//
adrRelasi findElement(listDokter L, string PX, string CX){
    adrDokter P = searching_DokterID(L, PX);
    adrRelasi R = nextRelasi(P);
    if(P!= NULL){
            if(R != NULL){
        do{
            if(info(childJadwal(R)).idJadwalOp == CX){
                return R;
        }
            R = next(R);
        }while(R!=nextRelasi(first(L)));
    }

    }
    return NULL;
}

adrRelasi searchingJadwalfromDokter(listDokter LD, string idJadwal, string idDokter) {
    adrDokter P;
    adrRelasi R;

    P = searching_DokterID(LD, idDokter);
    R = nextRelasi(P);
    while (R != NULL) {
        if ((info(childJadwal(R))).idJadwalOp == idJadwal) {
           return R;
        }
        R = next(R);
    }
    return NULL;
}

//MENU//
// Menu Dokter
int selectMenu_Dokter(){
    cout << "=====================================================================" << endl;
    cout << "=============== PROGRAM JADWAL PRAKTEK OPERASI DOKTER ===============" << endl;
    cout << "=====================================================================" << endl;
    cout << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "------------------ SILAHKAN PILIH MENU DATA DOKTER ------------------" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "(1) Menambah Data Dokter Diakhir List" << endl;
    cout << "(2) Menghapus Data Dokter Diawal List" << endl;
    cout << "(3) Menghapus Data Dokter Diakhir List" << endl;
    cout << "(4) Menghapus Data Dokter Tertentu" << endl;
    cout << "(5) Menampilkan Semua Data Dokter" << endl;
    cout << "(6) Mencari Data Dokter Berdasarkan ID Dokter" << endl;
    cout << "(7) Mencari Data Dokter Berdasarkan Nama Dokter" << endl;
    cout << "(0) Keluar Program Data Dokter" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    int input = 0;
    cout << "Pilih Menu : ";
    cin >> input;
    return input;
}

// Menu Jadwal OP
int selectMenu_jadwalOP(){
    cout << "=====================================================================" << endl;
    cout << "=============== PROGRAM JADWAL PRAKTEK OPERASI DOKTER ===============" << endl;
    cout << "=====================================================================" << endl;
    cout << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "-------------- SILAHKAN PILIH MENU DATA JADWAL OPERASI --------------" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "(1) Menambah Data Jadwal Operasi Diakhir List" << endl;
    cout << "(2) Menghapus Data Jadwal Operasi Diawal List" << endl;
    cout << "(3) Menghapus Data Jadwal Operasi Diakhir List" << endl;
    cout << "(4) Menghapus Data Jadwal Operasi Setelah Data Jadwal Operasi Tertentu" << endl;
    cout << "(5) Menampilkan Semua Data Jadwal Operasi" << endl;
    cout << "(6) Mencari Data Jadwal Operasi Berdasarkan ID Jadwal Operasi" << endl;
    cout << "(0) Keluar Program Data Jadwal Operasi" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    int input = 0;
    cout << "Pilih Menu : ";
    cin >> input;
    return input;
}

int menuawal(){
        int pilihan;
        cout << "=====================================================================" << endl;
        cout << "=============== PROGRAM JADWAL PRAKTEK OPERASI DOKTER ===============" << endl;
        cout << "=====================================================================" << endl;
        cout << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "------------------------ SILAHKAN PILIH MENU ------------------------" << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "(1) Data Dokter" << endl;
        cout << "(2) Data Jadwal Operasi" << endl;
        cout << "(3) Data Relasi        " << endl;
        cout << "(0) Keluar Program Data Dokter" << endl;
        cout << "---------------------------------------------------------------------" << endl;

        cout << "Masukkan Pilihan   : ";
        cin >> pilihan;
        return pilihan;
}

int selectMenu_Relasi(){
    cout << "=====================================================================" << endl;
    cout << "=============== PROGRAM JADWAL PRAKTEK OPERASI DOKTER ===============" << endl;
    cout << "=====================================================================" << endl;
    cout << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "-------------- SILAHKAN PILIH MENU DATA RELASI-----------------------" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "(1) Menambah Data Relasi " << endl;
    cout << "(2) Menghapus Data Relasi" << endl;
    cout << "(3) Menampilkan Data Relasi" << endl;
    cout << "(4) Mencari data Child pada Parent" << endl;
    cout << "(5) Menghitung data relasi berdasarkan ID Dokter" << endl;
    cout << "(0) Keluar Program Data Jadwal Operasi" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    int input = 0;
    cout << "Pilih Menu : ";
    cin >> input;
    return input;
}

