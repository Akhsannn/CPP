#include <iostream>
#include <limits>
#include <fstream>

using namespace std;

struct Nasabah{
    int id;
    char nama[25];
    char alamat[25];
    char status[25];
    char jenkel[25];
    char tanggal[25];
};

int getOption();
void checkDatabase(fstream &data);
void writeData(fstream &data, int posisi, Nasabah &inputNasabah);
int getDataSize(fstream &data);
Nasabah readData(fstream &data, int posisi);
void addDataNasabah(fstream &data);
void displayDataNasabah(fstream &data);
void updateRecord(fstream &data);
void deleteRecord(fstream &data);

int main(){

	fstream data;

	checkDatabase(data);

	int pilihan = getOption();
	char is_continue;

	enum option{CREATE = 1, READ, UPDATE, DELETE, FINISH};

	while(pilihan != FINISH){

		switch(pilihan){
			case CREATE:
				cout << "Menambah data Nasabah" << endl;
				addDataNasabah(data);
				break;
			case READ:
				cout << "Tampilkan data Nasabah" << endl;
				displayDataNasabah(data);
				break;
			case UPDATE:
				cout << "Ubah data Nasabah" << endl;
				displayDataNasabah(data);
				updateRecord(data);
				displayDataNasabah(data);
				break;
			case DELETE:
				cout << "Hapus data Nasabah" << endl;
				displayDataNasabah(data);
				deleteRecord(data);
				displayDataNasabah(data);
				break;
			default:
				cout << "Pilihan tidak ditemukan" << endl;
				break;
		}

		lanjut:

		cout << "Lanjutkan?(y/n) : ";
		cin >> is_continue;
		if ( (is_continue == 'y') | (is_continue == 'Y')){
			pilihan = getOption();
		} else if ((is_continue == 'n') | (is_continue == 'N')){
			break;
		} else {
			goto lanjut;
		}
	}
	cin.get();
	return 0;
}

void writeData(fstream &data, int posisi, Nasabah &inputNasabah){
	data.seekp((posisi - 1)*sizeof(Nasabah), ios::beg);
	data.write(reinterpret_cast<char*>(&inputNasabah),sizeof(Nasabah));
}

Nasabah readData(fstream &data, int posisi){
	Nasabah readNasabah;
	data.seekg((posisi - 1)*sizeof(Nasabah),ios::beg);
	data.read(reinterpret_cast<char*>(&readNasabah),sizeof(Nasabah));
	return readNasabah;
}

void displayDataNasabah(fstream &data){
	int size = getDataSize(data);
	Nasabah showNasabah;
	cout << "no.\tID.\tNama.\tAlamat.\t\tJ.Kelamin.\tTanggal Lahir" << endl;
	for(int i = 1; i <= size; i++){
		showNasabah = readData(data,i);
		cout << i << "\t";
		cout << showNasabah.id << "\t";
		cout << showNasabah.nama << "\t";
		cout << showNasabah.alamat << "\t\t";
		cout << showNasabah.status << "\t";
		cout << showNasabah.jenkel << "\t";
		cout << showNasabah.tanggal << endl;
	}
}



void deleteRecord(fstream &data){
	int nomor,size,offset;
	Nasabah blankNasabah, tempNasabah;
	fstream dataSementara;

	size = getDataSize(data);
	// 1. pilih nomor
	cout << "Hapus nomor: ";
	cin >> nomor;
	// 2. di posisi ini diisi dengan data kosong
	writeData(data,nomor,blankNasabah);
	// 3. kita cek data yang ada dari file data.bin, kalau ada data
	//    kita pindahkan ke file sementara
	dataSementara.open("temp.dat", ios::trunc|ios::out|ios::in|ios::binary);

	offset = 0;

	for (int i=1 ; i <=size ; i++){
		tempNasabah = readData(data,i);

		if (i != nomor){
			writeData(dataSementara,i - offset,tempNasabah);
		} else {
			offset = 1;
			cout << "deleted item" << endl;
		}
	}
	// 4. kita pindahkan data dari file sementara ke data.bin
	size = getDataSize(dataSementara);
	data.close();
	data.open("data.bin",ios::trunc|ios::out|ios::binary);
	data.close();
	data.open("data.bin",ios::out|ios::in|ios::binary);

	for(int i = 1; i <= size; i++){
		tempNasabah = readData(dataSementara,i);
		writeData(data,i,tempNasabah);
	}
}

void updateRecord(fstream &data){
	int nomor;
	Nasabah updateNasabah;
	cout << "pilih no: ";
	cin >> nomor;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	updateNasabah = readData(data,nomor);

	cout << "\n\npilihan data: " << endl;
	cout << "Nama          : " << updateNasabah.nama << endl;
	cout << "Alamat        : " << updateNasabah.alamat << endl;
	cout << "Status        : " << updateNasabah.status << endl;
	cout << "Jenis Kelamin : " << updateNasabah.jenkel << endl;
	cout << "Tanggal Lahir : " << updateNasabah.tanggal << endl;

	cout << "\nMerubah data: "<< endl;
	cout << "Nama          :";
	cin.get(updateNasabah.nama,25);
	cin.ignore();
	cout << "Alamat        :";
	cin.get(updateNasabah.alamat,25);
	cin.ignore();
	cout << "Status        :";
	cin.get(updateNasabah.status,25);
	cin.ignore();
	cout << "Jenis Kelamin :";
	cin.get(updateNasabah.jenkel,25);
	cin.ignore();
	cout << "Tanggal Lahir :";
	cin.get(updateNasabah.tanggal,25);
	cin.ignore();
	writeData(data,nomor,updateNasabah);

}

void checkDatabase(fstream &data){
	data.open("data.bin", ios::out | ios::in | ios::binary);

	// check file ada atau tidak
	if (data.is_open()){
		cout << "database ditemukan" << endl;
	} else {
		cout << "database tidak ditemukan, buat database baru" << endl;
		data.close();
		data.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary);
	}
}

int getOption(){
	int input;
	system("cls");
	cout << "\nProgram Pendataan Nasabah" << endl;
	cout << "=============================" << endl;
	cout << "1. Tambah data Nasabah" << endl;
	cout << "2. Tampilkan data Nasabah" << endl;
	cout << "3. Ubah data Nasabah" << endl;
	cout << "4. Hapus data Nasabah" << endl;
	cout << "5. Selesai" << endl;
	cout << "=============================" << endl;
	cout << "pilih menu : ";
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	return input;
}


void addDataNasabah(fstream &data){

	Nasabah inputNasabah, lastNasabah;

	int size = getDataSize(data);

	if(size == 0){
		inputNasabah.id = 1;
		cout << "ID : " << inputNasabah.id << endl;
	} else {
		lastNasabah = readData(data,size);
		cout << "ID : " << lastNasabah.id << endl;
		inputNasabah.id = lastNasabah.id + 1;
	}

	cout << "Nama          : ";
	cin.get( inputNasabah.nama,25);
	cin.ignore();
	cout << "Alamat        : ";
	cin.get( inputNasabah.alamat,25);
	cin.ignore();
	cout << "Status        : ";
	cin.get( inputNasabah.status,25);
	cin.ignore();
	cout << "Jenis Kelamin : ";
	cin.get( inputNasabah.jenkel,25);
	cin.ignore();
	cout << "Tanggl Lahir  : ";
	cin.get( inputNasabah.tanggal,25);
	cin.ignore();
	writeData(data,size+1,inputNasabah);

}

int getDataSize(fstream &data){
	int start, end;
	data.seekg(0,ios::beg);
	start = data.tellg();
	data.seekg(0,ios::end);
	end = data.tellg();
	return (end-start)/sizeof(Nasabah);
}
