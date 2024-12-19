#include"FOTOCOPY.h"

//===============================PRINTER=========================================

void createListPrinter(ListPrinter &LP){ //DLL
    first(LP) = NULL;
    last(LP) = NULL;
}

addressP createElemenPrinter(infotypeP printerBaru){
    addressP P;
    P = new elmlistP;
    infoP(P).namaPrinter = printerBaru.namaPrinter;
    infoP(P).jenisPrinter = printerBaru.jenisPrinter;
    next(P) = NULL;
    prev(P) = NULL;
    return P;

}


void insertFirstPrinter(ListPrinter &LP, addressP P){
    if(first(LP) == NULL){
        first(LP) = P;
        last(LP) = P;
    } else {
        prev(first(LP)) = P;
        next(P) = first(LP);
        first(LP) = P;
    }

}

void insertPrinter(ListPrinter &LP, addressP P) {
    int jumlah;
    infotypeP newPrinter;
    cout << "\n===================================\n";
    cout << "      *** INPUT DATA PRINTER ***    \n";
    cout << "===================================\n";
    cout << "Berapa jumlah printernya?: ";
    cin >> jumlah;
    while (jumlah > 0) {
        cout << "\nNama printer: ";
        cin >> newPrinter.namaPrinter;
        cout << "Jenis printer: ";
        cin >> newPrinter.jenisPrinter;
        P = createElemenPrinter(newPrinter);
        insertFirstPrinter(LP, P);
        cout << "\n[INFO] Data printer berhasil ditambahkan.\n";
        jumlah--;
    }
}

void showPrinter(ListPrinter &LP) {
    addressP P = first(LP);
    int i = 1;
    cout << "\n===================================\n";
    cout << "      *** DATA PRINTER ***         \n";
    cout << "===================================\n";
    if (P != NULL) {
        while (P != NULL) {
            cout << "\nData Printer Ke-" << i << "\n";
            cout << "-----------------------------------\n";
            cout << "Nama Printer  : " << infoP(P).namaPrinter << "\n";
            cout << "Jenis Printer : " << infoP(P).jenisPrinter << "\n";
            cout << "-----------------------------------\n";
            i++;
            P = next(P);
        }
    } else {
        cout << "Tidak ada data printer yang tersedia.\n";
    }
    cout << "===================================\n";
}


void deleteFirstPrinter(ListPrinter &LP, addressP &P){
    P = first(LP);
    if (first(LP) != last(LP)) {
        first(LP) = next(P);
        prev(first(LP)) = NULL;
        next(P) = NULL;
  } else {
        first(LP) = NULL;
        last(LP) = NULL;
  }

}
void deleteLastPrinter(ListPrinter &LP, addressP &P){
    P = last(LP);
    if (first(LP) != last(LP)) {
        last(LP) = prev(P);
        next(prev(P)) = NULL;
        prev(P) = NULL;
  } else {
    first(LP) = NULL;
    last(LP) = NULL;
  }

}
void deleteAfterPrinter(ListPrinter &LP, addressP &P){
    addressP q = next(P);
    next(P) = next(q);
    prev(next(q)) = P;
    next(q) = NULL;
    prev(q) = NULL;
}
void deletePrinter(ListPrinter &LP, addressP &P, string namaPrinter) {
    P = first(LP);
    if (P == NULL) {
        cout << "\n[ERROR] Data printer kosong!\n";
    } else {
        cout << "\nPrinter apa yang mau dihapus?: ";
        cin >> namaPrinter;
        P = findPrinter(LP, namaPrinter);
        if (P == NULL) {
            cout << "\n[ERROR] Printer dengan nama \"" << namaPrinter << "\" tidak ditemukan!\n";
        } else {
            if (P == first(LP)) {
                deleteFirstPrinter(LP, P);
            } else if (P == last(LP)) {
                deleteLastPrinter(LP, P);
            } else {
                deleteAfterPrinter(LP, prev(P));
            }
            cout << "\n[INFO] Data printer berhasil dihapus!\n";
        }
    }
}

addressP findPrinter(ListPrinter &LP, string printerName){ // mencari berdasarkan nama printer
    addressP P = first(LP);
    while(P != NULL){
        if(infoP(P).namaPrinter == printerName){
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void findPrinterSpesifik(ListPrinter &LP, string printerName) {
    addressP P = first(LP);
    bool ketemu = false;
    cout << "\n===================================\n";
    cout << "      *** CARI DATA PRINTER ***    \n";
    cout << "===================================\n";
    if (P != NULL) {
        cout << "Printer apa yang mau dicari?: ";
        cin >> printerName;
        while (P != NULL) {
            if (infoP(P).namaPrinter == printerName) {
                cout << "\n[INFO] Printer ditemukan!\n";
                cout << "Nama Printer  : " << infoP(P).namaPrinter << "\n";
                cout << "Jenis Printer : " << infoP(P).jenisPrinter << "\n";
                ketemu = true;
            }
            P = next(P);
        }
        if (!ketemu) {
            cout << "\n[ERROR] Printer tidak ditemukan.\n";
        }
    } else {
        cout << "\n[ERROR] Data printer kosong!\n";
    }
    cout << "===================================\n";
}


void updateDataPrinter(ListPrinter &LP, string printerName) {
    addressP P = first(LP);
    bool ketemu = false;
    string newName;
    string newJenis;

    if (P != NULL) {
        cout << "\n===================================\n";
        cout << "    *** UPDATE DATA PRINTER ***      \n";
        cout << "===================================\n";
        cout << "Masukkan nama printer yang akan diupdate: ";
        cin >> printerName;
        cout << "\nMencari data printer...\n" << endl;

        while (P != NULL) {
            if (infoP(P).namaPrinter == printerName) {
                ketemu = true;

                cout << "\nData printer ditemukan!" << endl;
                cout << "-----------------------------------------------" << endl;
                cout << "Nama Printer  : " << infoP(P).namaPrinter << endl;
                cout << "Jenis Printer : " << infoP(P).jenisPrinter << endl;
                cout << "-----------------------------------------------\n" << endl;

                cout << "Masukkan data printer yang baru:\n" << endl;
                cout << "   Nama printer baru  : ";
                cin >> newName;
                cout << "   Jenis printer baru : ";
                cin >> newJenis;

                // Memperbarui data
                infoP(P).namaPrinter = newName;
                infoP(P).jenisPrinter = newJenis;

                cout << "\nData berhasil diupdate!" << endl;
                cout << "-----------------------------------------------" << endl;
                cout << "Nama Printer Baru  : " << infoP(P).namaPrinter << endl;
                cout << "Jenis Printer Baru : " << infoP(P).jenisPrinter << endl;
                cout << "-----------------------------------------------\n" << endl;
                break;
            }
            P = next(P);
        }

        if (!ketemu) {
            cout << "\nPrinter dengan nama \"" << printerName << "\" tidak ditemukan.\n" << endl;
        }
    } else {
        cout << "\n[ERROR] Data printer kosong. Tidak ada yang bisa diupdate.\n" << endl;
    }
}
//===========================================TUGAS============================================

void createListTugas(ListTugas &LT){ //SLL
    first(LT) = NULL;
}

addressT createElemenTugas(infotypeT tugasBaru){
    addressT T;
    T = new elmlistT;
    infoT(T).namaFileTugas = tugasBaru.namaFileTugas;
    infoT(T).jumlahHalaman = tugasBaru.jumlahHalaman;
    infoT(T).ukuranKertas = tugasBaru.ukuranKertas;
    infoT(T) = tugasBaru;
    next(T) = NULL;
    return T;
}

//insert child ke parent
void insertTugaskePrinter(ListPrinter &LP, string namaPrinter, infotypeT tugasBaru) {
    cout << "\n===================================\n";
    cout << "  *** INSERT TUGAS KE PRINTER ***               " << endl;
    cout << "===================================\n";
    cout << "Pilih printer: ";
    cin >> namaPrinter;
    addressP P = findPrinter(LP, namaPrinter);

    if (P == NULL) {
        cout << "Printer tidak ditemukan.\n" << endl;
        return;
    }

    cout << "\nMasukkan data tugas: \n" << endl;
    cout << "Nama File Tugas: ";
    cin >> tugasBaru.namaFileTugas;
    cout << "Jumlah Halaman : ";
    cin >> tugasBaru.jumlahHalaman;
    cout << "Ukuran Kertas  : ";
    cin >> tugasBaru.ukuranKertas;

    addressT T = createElemenTugas(tugasBaru);
    if (first(addressT(P)) == NULL) {
        first(addressT(P)) = T;
        last(addressT(P)) = T;
    } else {
        next(last(addressT(P))) = T;
        last(addressT(P)) = T;
    }

    cout << "\nTugas berhasil dimasukkan ke printer \"" << namaPrinter << "\".\n" << endl;
}


void showTugasPerPrinter(ListPrinter &LP) {
    cout << "\n===================================\n";
    cout << "    *** TUGAS PER PRINTER ***         " << endl;
    cout << "===================================\n";

    addressP P = first(LP);
    if(P == NULL){
        cout << "[ERROR] Tidak ada data printer dan tugas" << endl;
        cout << endl;
    } else {
        while (P != NULL) {
            cout << "Printer: " << infoP(P).namaPrinter << endl;
            addressT T = first(addressT(P));
            if (T != NULL) {
                cout << "Antrian Tugas:" << endl;
                while (T != NULL) {
                    cout << " - Nama File : " << infoT(T).namaFileTugas << endl;
                    cout << "   Halaman   : " << infoT(T).jumlahHalaman << endl;
                    cout << "   Kertas    : " << infoT(T).ukuranKertas << endl;
                    cout << endl;
                    T = next(T);
                }
            } else {
                cout << "Tidak ada antrian tugas." << endl;
                cout << endl;
            }
            P = next(P);
        }
    }
}



void deleteTugas(ListPrinter &LP, string namaPrinter, string namaFileTugas) {
    cout << "\n===================================" << endl;
    cout << "        *** DELETE TUGAS ***         " << endl;
    cout << "===================================\n" << endl;
    addressP P = findPrinter(LP, namaPrinter);
    if(P == NULL) {
            cout << "Belum ada data tugas!" << endl;
            cout << endl;
    } else {
        cout << "Pilih printer: ";
        cin >> namaPrinter;

        if(P != NULL){
            cout << "File apa yang mau dihapus?: ";
            cin >> namaFileTugas;
            if (P != NULL) {
                addressT T = first(addressT(P));
                addressT prevT = NULL;

                while (T != NULL && infoT(T).namaFileTugas != namaFileTugas) {
                    prevT = T;
                    T = next(T);
                }

                if (T != NULL) {
                    if (T == first(addressT(P))) {
                        first(addressT(P)) = next(T);
                        if (first(addressT(P)) == NULL) {
                            last(addressT(P)) = NULL;
                        }
                    } else if (T == last(addressT(P))) {
                        last(addressT(P)) = prevT;
                        next(prevT) = NULL;
                    } else {
                        next(prevT) = next(T);
                    }
                    delete T;
                    cout << "\nTugas berhasil dihapus.\n" << endl;
                } else {
                    cout << "\n[ERROR] Tugas tidak ditemukan.\n" << endl;
                }
            } else {
                cout << "\n[ERROR] Printer tidak ditemukan.\n" << endl;
            }
        } else {
            cout << "[ERROR] Belum ada data printer!" << endl;
        }
    }

}



void findTugasSpesifik(ListPrinter &LP, string namaFileTugas) {
    cout << "\n===================================" << endl;
    cout << "    *** CARI TUGAS SPESIFIK ***      " << endl;
    cout << "===================================\n" << endl;
    addressP P = first(LP);
    if(P == NULL){
        cout << "Belum ada data tugas!" << endl;
        cout << endl;
    }else{
        cout << "Cari file apa?: ";
        cin >> namaFileTugas;

        bool ketemu = false;

        while (P != NULL) {
            addressT T = first(addressT(P));
            while (T != NULL) {
                if (infoT(T).namaFileTugas == namaFileTugas) {
                    cout << "\nTugas ditemukan di Printer: " << infoP(P).namaPrinter << endl;
                    cout << " - Nama File : " << infoT(T).namaFileTugas << endl;
                    cout << "   Halaman   : " << infoT(T).jumlahHalaman << endl;
                    cout << "   Kertas    : " << infoT(T).ukuranKertas << endl;
                    ketemu = true;
                    break;
                }
                T = next(T);
            }
            if (ketemu) break;
            P = next(P);
        }

        if (!ketemu) {
            cout << "\n[ERROR]Tugas tidak ditemukan.\n" << endl;
        }
    }
}

void updateDataTugas(ListPrinter &LP, string namaPrinter, string namaFileTugas) {
    string newName;
    int newHalaman;
    string newUkuran;
    cout << "\n===================================" << endl;
    cout << "     *** UPDATE DATA TUGAS ***       " << endl;
    cout << "===================================\n" << endl;
    addressP Q = first(LP);
    if(Q == NULL){
            cout << "Belum ada data tugas!" << endl;
            cout << endl;
    } else {
        cout << "Pilih printer: ";
        cin >> namaPrinter;

        addressP P = findPrinter(LP, namaPrinter);
        if (P != NULL) {
            addressT T = first(addressT(P));
            cout << "File apa yang mau di edit?: ";
            cin >> namaFileTugas;
            while (T != NULL && infoT(T).namaFileTugas != namaFileTugas) {
                T = next(T);
            }

            if (T != NULL) {
                cout << "\nFile ditemukan! Masukkan data baru:\n" << endl;
                cout << "Nama File Baru    : ";
                cin >> newName;
                cout << "Jumlah Halaman Baru: ";
                cin >> newHalaman;
                cout << "Ukuran Kertas Baru : ";
                cin >> newUkuran;

                infoT(T).namaFileTugas = newName;
                infoT(T).jumlahHalaman = newHalaman;
                infoT(T).ukuranKertas = newUkuran;

                cout << "\nTugas berhasil diupdate!\n" << endl;
                cout << "+-----------------------------------------------+" << endl;
                cout << " - Nama File Baru    : " << infoT(T).namaFileTugas << endl;
                cout << "   Jumlah Halaman Baru: " << infoT(T).jumlahHalaman << endl;
                cout << "   Ukuran Kertas Baru : " << infoT(T).ukuranKertas << endl;
                cout << "+-----------------------------------------------+\n" << endl;
            } else {
                cout << "\n[ERROR]Tugas tidak ditemukan.\n" << endl;
            }
        } else {
            cout << "\n[ERROR]Printer tidak ditemukan.\n" << endl;
        }
    }
}
int totalAllPage(ListPrinter &LP) {
    cout << "\n===================================" << endl;
    cout << " *** TOTAL HALAMAN SEMUA TUGAS ***   " << endl;
    cout << "===================================\n" << endl;

    int totalHalamanSemuaPrinter = 0;
    addressP P = first(LP);
        if(P == NULL){
            cout << "[ERROR] Tidak ada antrian tugas!" << endl;
            cout << endl;
        }else {
            while (P != NULL) {
                int totalHalamanPrinter = 0;
                addressT T = first(addressT(P));
                while (T != NULL) {
                    totalHalamanPrinter += infoT(T).jumlahHalaman;
                    T = next(T);
                }
                cout << "Total halaman di Printer \"" << infoP(P).namaPrinter << "\": " << totalHalamanPrinter << endl;
                totalHalamanSemuaPrinter += totalHalamanPrinter;
                P = next(P);
            }
            cout << "\nTotal halaman di semua printer: " << totalHalamanSemuaPrinter << endl;
            return totalHalamanSemuaPrinter;
        }
    }


//===========================================MENU============================================

int allMenu(){
    cout << "===================================" << endl;
    cout << "          *** FOTOCOPY ***         " << endl;
    cout << "===================================" << endl;
    cout << "|           MENU UTAMA            |" << endl;
    cout << "===================================" << endl;
    cout << "| [1] > Input data printer        |" << endl;
    cout << "| [2] x Hapus data printer        |" << endl;
    cout << "| [3] ? Cari data printer         |" << endl;
    cout << "| [4] ~ Update data printer       |" << endl;
    cout << "| [5] # Show data printer         |" << endl;
    cout << "-----------------------------------" << endl;
    cout << "| [6] + Input data tugas          |" << endl;
    cout << "| [7] x Hapus data tugas          |" << endl;
    cout << "| [8] ? Cari data tugas           |" << endl;
    cout << "| [9] ~ Update data tugas         |" << endl;
    cout << "| [10] # Show data tugas          |" << endl;
    cout << "| [11] = Jumlah seluruh halaman   |" << endl;
    cout << "-----------------------------------" << endl;
    cout << "| [12] EXIT                       |" << endl;
    cout << "===================================" << endl;

    cout << "Pilih opsi: ";

    int input = 0;
    cin >> input;

    return input;
}
