#include "tubes.h"

void clear(){
    system("CLS");
}


int main()
{
        int pilihan, pilihan2;
        listDokter LD;
        listJadwalOP LJ;
        listRelasi LR;
        dokter X;
        jadwalOP Y;
        int C;
        bool check;
        adrDokter P, Prec;
        adrJadwalOP Q, prec2;
        adrRelasi R;

        createList_Dokter(LD);
        createList_jadwalOP(LJ);

        X.idDokter = "D001";
        X.namaDokter = "Bryan";
        X.spesialisDokter = "PenyakitDalam";
        X.masaKerjaDokter = 14;
        P = createElement_Dokter(X);
        insertLast_Dokter(LD, P);

        X.idDokter = "D002";
        X.namaDokter = "Monika";
        X.spesialisDokter = "Kandungan";
        X.masaKerjaDokter = 10;
        P = createElement_Dokter(X);
        insertLast_Dokter(LD, P);



        Y.idJadwalOp = "J001";
        Y.waktuOp = '9';
        Y.rumahSakit= "Pelita";
        Q = createElement_jadwalOP(Y);
        insertLast_jadwalOP(LJ, Q);

        Y.idJadwalOp = "J002";
        Y.waktuOp = '8';
        Y.rumahSakit= "Sahabat";
        Q = createElement_jadwalOP(Y);
        insertLast_jadwalOP(LJ, Q);

        connectParentdanChild(LD, LJ, "D001", "J001");
        connectParentdanChild(LD, LJ, "D001", "J002");
        connectParentdanChild(LD, LJ, "D002", "J001");



    do{
        pilihan = menuawal();
        cout<<endl;
        switch(pilihan){
            case 1:
                clear();
                pilihan2 = selectMenu_Dokter();
                cout<<endl;
                while(pilihan2 != 0){
                    switch(pilihan2){
                        case 1:
                            cout << "Masukkan ID Dokter                 : ";
                            cin >> X.idDokter;
                            cout << "Masukkan Nama Dokter               : ";
                            cin >> X.namaDokter;
                            cout << "Masukkan Spesialis Dokter          : ";
                            cin >> X.spesialisDokter;
                            cout << "Masukkan Masa Kerja Dokter (Tahun) : ";
                            cin >> X.masaKerjaDokter;
                            P = createElement_Dokter(X);
                            insertLast_Dokter(LD, P);
                            cout << endl;
                            cout << "---------------------------------------------------------------------" << endl;
                            cout << "Data Dokter Berhasil Ditambahkan!" << endl;
                            cout << "---------------------------------------------------------------------" << endl;
                            cout << endl;
                            system("PAUSE");
                            clear();
                            pilihan2 = selectMenu_Dokter();
                            break;
                        case 2:
                            P = first(LD);
                            Q = first(LJ);
                            R = nextRelasi(first(LD));
                            while(R!=NULL){
                                deleteElement_Relasi(LD, info(P).idDokter, info(Q).idJadwalOp);
                                R = next(R);
                                Q = next(Q);
                            }
                            cout<<"cek";
                            deleteFirst_Dokter(LD, P);
                            cout << endl;
                            cout << "---------------------------------------------------------------------" << endl;
                            cout << "Data Dokter Berhasil Dihapus!" << endl;
                            cout << "---------------------------------------------------------------------" << endl;
                            cout << endl;
                            system("PAUSE");
                            clear();
                            pilihan2 = selectMenu_Dokter();
                            break;
                        case 3:
                            R = nextRelasi(P);
                            while(R!=NULL){
                                deleteElement_Relasi(LD, info(P).idDokter, info(first(LJ)).idJadwalOp);
                                R = next(R);
                            }
                            deleteLast_Dokter(LD, P);
                            cout << endl;
                            cout << "---------------------------------------------------------------------" << endl;
                            cout << "Data Dokter Berhasil Dihapus!" << endl;
                            cout << "---------------------------------------------------------------------" << endl;
                            cout << endl;
                            system("PAUSE");
                            clear();
                            pilihan2 = selectMenu_Dokter();
                            break;
                        case 4:
                            cout << "Masukkan ID Dokter Yang Ingin Dihapus     : ";
                            cin >> X.idDokter;
                            Prec = searching_DokterID(LD, X.idDokter);
                            if (Prec == NULL){
                                cout << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << "Data Dokter Tidak Ditemukan!" << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << endl;
                            }else{
                                Q = first(LJ);
                                while(R!=NULL){
                                    deleteElement_Relasi(LD, info(Prec).idDokter, info(Q).idJadwalOp);
                                    R = next(R);
                                    Q = next(Q);
                                }
                                if(Prec == first(LD)){
                                    deleteFirst_Dokter(LD, P);
                                }else if(next(Prec) == NULL){
                                    deleteLast_Dokter(LD, P);
                                }else{
                                    deleteAfter_Dokter(LD,P,Prec);
                                }
                                cout << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << "Data Dokter Berhasil Dihapus!" << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << endl;
                            }
                            system("PAUSE");
                            clear();
                            pilihan2 = selectMenu_Dokter();
                            break;
                        case 5:
                            printList_Dokter(LD);
                            system("PAUSE");
                            clear();
                            pilihan2 = selectMenu_Dokter();
                            break;
                        case 6:
                            cout << "Masukkan ID Dokter Yang Ingin Dicari     : ";
                            cin >> X.idDokter;
                            P = searching_DokterID(LD,X.idDokter);
                            if (P != NULL){
                                cout << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << "Data Dokter Ditemukan!" << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << endl;
                                cout << "=========================================================" << endl;
                                cout << "ID Dokter          : " << info(P).idDokter << endl;
                                cout << "Nama Dokter        : " << info(P).namaDokter << endl;
                                cout << "Spesialis Dokter   : " << info(P).spesialisDokter << endl;
                                cout << "Masa Kerja Dokter  : " << info(P).masaKerjaDokter << endl;
                                cout << "=========================================================" << endl;
                            }else{
                                cout << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << "Data Dokter Tidak Ditemukan!" << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << endl;
                            }
                            system("PAUSE");
                            clear();
                            pilihan2 = selectMenu_Dokter();
                            break;
                        case 7:
                            cout << "Masukkan Nama Dokter Yang Ingin Dicari      : ";
                            cin >> X.namaDokter;
                            P = searching_DokterNama(LD,X.namaDokter);
                            if (P != NULL){
                                cout << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << "Data Dokter Ditemukan!" << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << endl;
                                cout << "=========================================================" << endl;
                                cout << "ID Dokter          : " << info(P).idDokter << endl;
                                cout << "Nama Dokter        : " << info(P).namaDokter << endl;
                                cout << "Spesialis Dokter   : " << info(P).spesialisDokter << endl;
                                cout << "Masa Kerja Dokter  : " << info(P).masaKerjaDokter << endl;
                                cout << "=========================================================" << endl;
                            }else{
                                cout << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << "Data Dokter Tidak Ditemukan!" << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << endl;
                            }
                            system("PAUSE");
                            clear();
                            pilihan2 = selectMenu_Dokter();
                            break;
                    }
              }
               clear();
               break;
            case 2:
                clear();
                pilihan2 = selectMenu_jadwalOP();
                cout<<endl;
                while(pilihan2 != 0){
                    switch(pilihan2){
                        case 1:
                            cout << "Masukkan ID Jadwal Operasi                     : ";
                            cin >> Y.idJadwalOp;
                            cout << "Masukkan Waktu Operasi (Jam)                   : ";
                            cin >> Y.waktuOp;
                            cout << "Masukkan Nama Rumah Sakit                      : ";
                            cin >> Y.rumahSakit;
                            Q = createElement_jadwalOP(Y);
                            insertLast_jadwalOP(LJ,Q);
                            cout << endl;
                            cout << "---------------------------------------------------------------------" << endl;
                            cout << "Data Jadwal Operasi Berhasil Ditambahkan!" << endl;
                            cout << "---------------------------------------------------------------------" << endl;
                            cout << endl;
                            system("PAUSE");
                            clear();
                            pilihan2 = selectMenu_jadwalOP();
                            break;
                        case 2:
                            deleteFirst_jadwalOP(LJ,Q);
                            cout << endl;
                            cout << "---------------------------------------------------------------------" << endl;
                            cout << "Data Jadwal Operasi Berhasil Dihapus!" << endl;
                            cout << "---------------------------------------------------------------------" << endl;
                            cout << endl;
                            system("PAUSE");
                            clear();
                            pilihan2 = selectMenu_jadwalOP();
                            break;
                        case 3:
                            deleteLast_jadwalOP(LJ,Q);
                            cout << endl;
                            cout << "---------------------------------------------------------------------" << endl;
                            cout << "Data Jadwal Operasi Berhasil Dihapus!" << endl;
                            cout << "---------------------------------------------------------------------" << endl;
                            cout << endl;
                            system("PAUSE");
                            clear();
                            pilihan2 = selectMenu_jadwalOP();
                            break;
                        case 4:
                            cout << "Masukkan ID Jadwal Operasi Yang Ingin Dicari       : ";
                            cin >> Y.idJadwalOp;
                            prec2 = searching_jadwalOP(LJ,Y.idJadwalOp);
                            if (prec2 == NULL){
                                cout << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << "Data Jadwal Operasi Tidak Ditemukan!" << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << endl;
                            }else{
                                deleteAfter_jadwalOP(LJ,Q,prec2);
                                cout << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << "Data Jadwal Operasi Berhasil Dihapus!" << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << endl;
                            }
                            system("PAUSE");
                            clear();
                            pilihan2 = selectMenu_jadwalOP();
                            break;
                        case 5:
                            printList_jadwalOP(LJ);
                            system("PAUSE");
                            clear();
                            pilihan2 = selectMenu_jadwalOP();
                            break;
                        case 6:
                            cout << "Masukkan ID Jadwal Operasi Yang Ingin Dicari      : ";
                            cin >> Y.idJadwalOp;
                            Q = searching_jadwalOP(LJ,Y.idJadwalOp);
                            if (Q != NULL){
                                cout << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << "Data Jadwal Operasi Ditemukan!" << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << endl;
                                cout << "=====================================================================" << endl;
                                cout << "ID Jadwal Operasi                      : " << info(Q).idJadwalOp << endl;
                                cout << "Waktu Operasi (Jam)                    : " << info(Q).waktuOp << endl;
                                cout << "Rumah Sakit                            : " << info(Q).rumahSakit << endl;
                                cout << "=====================================================================" << endl;
                            }else{
                                cout << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << "Data Jadwal Operasi Tidak Ditemukan!" << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << endl;
                            }
                            system("PAUSE");
                            clear();
                            pilihan2 = selectMenu_jadwalOP();
                            break;
                        }
                    }
                    clear();
                    break;
                case 3:
                    clear();
                    pilihan2 = selectMenu_Relasi();
                    cout<<endl;
                    while(pilihan2 != 0){
                        switch(pilihan2){
                        case 1 :
                            cout << "Masukkan ID Dokter                 : ";
                            cin >> X.idDokter;
                            cout << "Masukkan ID Jadwal Operasi         : ";
                            cin >> Y.idJadwalOp;
                            P = searching_DokterID(LD, X.idDokter);
                            Q = searching_jadwalOP(LJ, Y.idJadwalOp);
                            if (P != NULL && Q != NULL){
                                connectParentdanChild(LD, LJ, X.idDokter, Y.idJadwalOp);
                                cout << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << "Data Relasi Berhasil Ditambahkan!" << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << endl;
                            }else{
                                cout<<"Data yang diinputkan salah!!"<<endl;
                                cout<<"Masukkan ulang data yang tepat!!"<<endl;
                            }
                            system("PAUSE");
                            clear();
                            pilihan2 = selectMenu_Relasi();
                            break;
                        case 2 :
                            cout << "Masukkan ID Dokter yang ingin dihapus         :";
                            cin >> X.idDokter;
                            cout << "Masukkan ID Jadwal Operasi yang ingin dihapus : ";
                            cin >> Y.idJadwalOp;
                            P = searching_DokterID(LD, X.idDokter);
                            Q = searching_jadwalOP(LJ, Y.idJadwalOp);
                            if(P!= NULL && Q!=NULL){
                                deleteElement_Relasi(LD,X.idDokter,Y.idJadwalOp);
                                cout << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << "Data Relasi Berhasil Dihapus!" << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << endl;
                            }else{
                                cout<<"Data yang diinputkan salah!!"<<endl;
                                cout<<"Masukkan ulang data yang tepat!!"<<endl;
                            }
                            system("PAUSE");
                            clear();
                            pilihan2 = selectMenu_Relasi();
                            break;
                        case 3:
                            printRelasi(LR, LD, LJ);
                            system("PAUSE");
                            clear();
                            pilihan2 = selectMenu_Relasi();
                            break;
                        case 4 :
                            cout << "Masukkan ID Jadwal Operasi Yang Ingin Dicari     : ";
                            cin >> Y.idJadwalOp;
                            prec2 = searching_jadwalOP(LJ, Y.idJadwalOp);
                            check = false;
                            P = first(LD);
                            if (prec2 != NULL){
                                cout << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << "Data Jadwal Ditemukan!" << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << endl;
                                cout<<"List Dokter yang memiliki Jadwal Operasi di RS. "<<info(prec2).rumahSakit<<" pada pukul "<<info(prec2).waktuOp<<endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                    do{
                                        R = nextRelasi(P);
                                        while(R != NULL){
                                            if(childJadwal(R) == prec2){
                                                cout << "=========================================================" << endl;
                                                cout << "ID Dokter          : " <<info(P).idDokter << endl;
                                                cout << "Nama Dokter        : " <<info(P).namaDokter << endl;
                                                cout << "Spesialis          : " <<info(P).spesialisDokter<< endl<< endl;
                                                check = true;
                                            }
                                            R = next(R);
                                        }
                                        P = next(P);
                                    }while(P != NULL);

                                    if(check == false){
                                        cout << "Tidak ada dokter yang memiliki jadwal operasi yang dicari!" << endl;
                                        cout << "---------------------------------------------------------------------" << endl;
                                    }
                            }else{
                                cout << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << "Data Jadwal Tidak Ditemukan!" << endl;
                                cout << "---------------------------------------------------------------------" << endl;
                                cout << endl;
                            }
                            system("PAUSE");
                            clear();
                            pilihan2 = selectMenu_Relasi();
                            break;
                        case 5 :
                            cout<<"Masukkan ID DOkter yang ingin dihitung : ";
                            cin>>X.idDokter;
                            cout<<endl;
                            P = searching_DokterID(LD, X.idDokter);
                            if(P != NULL){
                                C = countRelasi(LD, X.idDokter);
                                cout<<"Data Child pada ID Dokter "<<X.idDokter<<" : "<<C<<endl<<endl;
                            }else{
                                cout<<"ID Dokter tidak ditemukan!"<<endl;
                            }
                            system("PAUSE");
                            clear();
                            pilihan2 = selectMenu_Relasi();
                            break;
                        }
                    }
                    clear();
                    break;
        }
    }while (pilihan != 0);
}

