#include <iostream>
#include"FOTOCOPY.h"

using namespace std;

//MAIN SESUNGGUHNYA

int main()
{
    //deklarasi umum
    ListPrinter LP;
    ListTugas LT;
    int menu;
    addressT T;
    addressP P = new elmlistP;
    char YesOrNo; //buat opsi kembali ke menu
    int jumlah = 0;

    //deklarasi printer
    string namaPrinter;
    string namaBaru;
    string jenisBaru;
    string jenisPrinter;
    string hapusPrinter;
    infotypeP newPrinter;
    string cariPrinter;

    //deklarasi tugas
    infotypeT newTugas;
    string hapusFile;
    string cariTugas;
    string namaFile;
    int jumlahT = 0;


    createListPrinter(LP);
    createListTugas(LT);
    menu = allMenu();
    while(menu != 0){
        switch(menu){
        case 1:
            insertPrinter(LP, P);
            cout << ">>Kembali ke menu utama?(Y/N): ";
            cin >> YesOrNo;
            break;
        case 2:
            deletePrinter(LP, P, hapusPrinter);
            cout << ">> Kembali ke menu utama?(Y/N): ";
            cin >> YesOrNo;
            break;
        case 3:
            findPrinterSpesifik(LP, cariPrinter);
            cout << ">>Kembali ke menu utama?(Y/N): ";
            cin >> YesOrNo;
            break;
        case 4:
            updateDataPrinter(LP, namaPrinter);
            cout << "Kembali ke menu utama?(Y/N): ";
            cin >> YesOrNo;
            break;
        case 5:
            showPrinter(LP);
            cout << ">>Kembali ke menu utama?(Y/N): ";
            cin >> YesOrNo;
            break;
        case 6:
            insertTugaskePrinter(LP, namaPrinter, newTugas);
            cout << ">>Kembali ke menu utama?(Y/N): ";
            cin >> YesOrNo;
            break;
        case 7:
            deleteTugas(LP, namaPrinter, hapusFile);
            cout << ">> Kembali ke menu utama?(Y/N): ";
            cin >> YesOrNo;
            break;
        case 8:
            findTugasSpesifik(LP, namaFile);
            cout << ">>Kembali ke menu utama?(Y/N): ";
            cin >> YesOrNo;
            break;
        case 9:
            updateDataTugas(LP, namaPrinter, namaFile);
            cout << "Kembali ke menu utama?(Y/N): ";
            cin >> YesOrNo;
            break;
        case 10:
            showTugasPerPrinter(LP);
            cout << ">>Kembali ke menu utama?(Y/N): ";
            cin >> YesOrNo;
            break;
        case 11:
            int totalHalaman;
            totalHalaman = totalAllPage(LP);
            cout << ">>Kembali ke menu utama?(Y/N): ";
            cin >> YesOrNo;
            break;
        case 12:
            cout << endl;
            cout << "TERIMA KASIH SUDAH DATANG KE FOTOCOPY" << endl;
            return 0;

        default:
            cout << "Pilihan menu tidak valid." << endl;
            cout << ">>Kembali ke menu utama?(Y/N): ";
            cin >> YesOrNo;
        }
        // Pastikan `YesOrNo` dikendalikan dengan benar
        if(YesOrNo == 'Y' || YesOrNo == 'y'){
            menu = allMenu();
        } else {
            menu = 0;
        }
    }
    cout << endl;
    cout << "TERIMA KASIH SUDAH DATANG KE FOTOCOPY" << endl;
    return 0;
}

