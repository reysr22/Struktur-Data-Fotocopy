#ifndef FOTOCOPY_H_INCLUDED
#define FOTOCOPY_H_INCLUDED

#include <iostream>

#define first(L) L.first
#define last(L) L.last
#define infoP(P) P->infoP
#define next(P) P->next
#define prev(P) P->prev
#define addressT(P) P->addressT
#define infoT(T) T->infoT

using namespace std;

//ADT ANAK(TUGAS) <SLL>
struct tugas{
    string namaFileTugas;
    int jumlahHalaman;
    string ukuranKertas;

};
typedef tugas infotypeT;
typedef struct elmlistT *addressT;

struct elmlistT{
    infotypeT infoT;
    addressT next;
};

struct ListTugas{
    addressT first;
    addressT last;
};

//ADT PARENT(PRINTER) <DLL>

struct printer{
    string namaPrinter;
    string jenisPrinter;

};
typedef printer infotypeP;
typedef struct elmlistP *addressP;

struct elmlistP{
    infotypeP infoP;
    addressP next;
    addressP prev;
    ListTugas addressT;
};

struct ListPrinter{
    addressP first;
    addressP last;
};


//============================================PRINTER============================================================
void createListPrinter(ListPrinter &LP);
addressP createElemenPrinter(infotypeP printerBaru);

void insertFirstPrinter(ListPrinter &LP, addressP P);
void insertPrinter(ListPrinter &LP, addressP P);
void showPrinter(ListPrinter &LP);

void deleteFirstPrinter(ListPrinter &LP, addressP &P);
void deleteLastPrinter(ListPrinter &LP, addressP &P);
void deleteAfterPrinter(ListPrinter &LP, addressP &P);
void deletePrinter(ListPrinter &LP, addressP &P, string namaPrinter); // menghapus printer tertentu

addressP findPrinter(ListPrinter &LP, string printerName);
void findPrinterSpesifik(ListPrinter &LP, string printerName);
void updateDataPrinter(ListPrinter &LP, string printerName);


//=============================================TUGAS================================================================

void createListTugas(ListTugas &LT);
addressT createElemenTugas(infotypeT tugasBaru);

void insertTugaskePrinter(ListPrinter &LP, string namaPrinter, infotypeT tugasBaru);

void deleteTugas(ListPrinter &LP, string namaPrinter, string namaFile); //menghapus tugas pada parent tertentu


void findTugasSpesifik(ListPrinter &LP, string namaFileTugas);

void updateDataTugas(ListPrinter &LP, string namaPrinter, string namaFileTugas);

int totalAllPage(ListPrinter &LP);
void showTugasPerPrinter(ListPrinter &LP);

int allMenu();


#endif // FOTOCOPY_H_INCLUDED
