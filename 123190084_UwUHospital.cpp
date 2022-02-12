#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

struct dataJalan
{
	string namaPasien;
	char kelamin;
	string alamat;
	string diagnosa;
	string namaDokter;
	int hargaObat;
	int totalPembayaran;	
};

dataJalan jalan [100];

struct dataInap
{
	string namaPasien;
	char kelamin;
	string alamat;
	string diagnosa;
	string namaDokter;
	int hargaObat;
	int totalPembayaran;
	int lamaInap;
	string ruangan;
	string operasi;	
};

dataInap inap [100];

void inputJalan(int *); //pointer
void inputInap(int *);
void daftarJalan(int ); //rekursif
void daftarInap(int ); 
void searchingNama(int ,int );
void searchingDokter(int ,int );
void sortingNama(int ,int );
void sortingKelamin(int ,int );
void sortingAlamat(int ,int );
void sortingDiagnosa(int ,int );
void sortingPembayaran(int ,int );
void bayar(int ,int );

string allUpCase(std::string& str); //fungsi untuk menjadikan seluruh string menjadi uppercase agar menjadi insensitive case

int jmlInap=0;
int jmlJalan=0;
int pilihan;
int jumlahPasienJalan;
int jumlahPasienInap;
int rawat;
char kembali;

int main()
{                
	do
	{
		system("cls");
		cout << "+======================================+" << endl;      
		cout << "|  _   | | |   | | |     _ _        _  |" << endl;
		cout << "| | |  |_|.|_|_|.|_|.   (_) |      | | |" << endl;
		cout << "| | |___  ___  ___ _ __  _| |_ __ _| | |" << endl;
		cout << "| |  _  || _ || __|  _ || | __| _  | | |" << endl;
		cout << "| | | | |((_))|__ | |_) | | || (_| | | |" << endl;
		cout << "| |_| |_||___||___|  __||_|___|__ _|_| |" << endl;
		cout << "|                 | |                  |" << endl;
		cout << "|                 |_|                  |" << endl;
		cout << "+======================================+" << endl;                
		cout << "|            UWU HOSPITAL              |" << endl;
		cout << "|      SPESIALIS PENYAKIT DALAM        |" << endl; 
		cout << "+======================================+" << endl;
		cout << endl;                                                                  
		cout << "1. Input Data Pasien" << endl;
		cout << "2. Daftar Pasien" << endl;
		cout << "3. Cari Data Pasien" << endl;
		cout << "4. Urutkan Data Pasien" << endl;
		cout << "5. Pembayaran Administrasi Pasien" << endl;
		cout << "6. Keluar" << endl;
		cout << "==================================== " << endl;  

		cout << "\nMasukkan pilihan menu : ";
		cin >> pilihan;
		cout << endl;
		
		system("cls");
		switch (pilihan)
		{	
			case 1:
			{
				bool wrong;
				do
				{
					wrong = false;
					cout << "\nPilihan Input Data Pasien" << endl << endl;
					cout << "\n1. Pasien Rawat Jalan" << endl;
					cout << "2. Pasien Rawat Inap" << endl;
					cout << "3. Kembali ke menu utama" << endl;
					cout << "\nMasukkan pilihan input : ";
					cin >> rawat;
					system("cls");
					
					if(rawat==1)
					{			
						inputJalan(&jumlahPasienJalan);
					}
					
					else if(rawat==2)
					{
						inputInap(&jumlahPasienInap);
					}
					
					else if(rawat==3)
					{
						break;
					}
					
					else
					{
						cout << "Menu yang anda pilih tidak ada, mohon masukkan pilihan menu dengan benar!" << endl;
						system("pause");
						system("cls");
						wrong=true;
					}
				}
				while(wrong==true);
			}
			break;
			
			case 2:
			{
				bool wrong;
				do
				{
					wrong = false;
					cout << "\nPilihan Data Pasien" << endl << endl;
					cout << "\n1. Pasien Rawat Jalan" << endl;
					cout << "2. Pasien Rawat Inap" << endl;
					cout << "3. Kembali ke menu utama" << endl;
					cout << "\nMasukkan pilihan data : ";
					cin >> rawat;
					system("cls");
					
					if(rawat==1)
					{			
						cout << "Riwayat Pasien Rawat Jalan Sejumlah " << jmlJalan << " Pasien." << endl;
						if(jumlahPasienJalan > 0)
						{
							daftarJalan(jmlJalan-1);
						}
						else
						{
							cout << "\nBelum ada riwayat data pasien rawat jalan." << endl;
						}
					}
					
					else if(rawat==2)
					{
						cout << "Riwayat Pasien Rawat Inap Sejumlah " << jmlInap << " Pasien." << endl;
						if(jumlahPasienInap > 0)
						{
							daftarInap(jmlInap-1);
						}
						else
						{
							cout << "\nBelum ada riwayat data pasien rawat inap." << endl;
						}
					}
					
					else if(rawat==3)
					{
						break;
					}
					
					else
					{
						cout << "Menu yang anda pilih tidak ada, mohon masukkan pilihan menu dengan benar!" << endl;
						system("pause");
						system("cls");
						wrong=true;
					}
				}
				while(wrong==true);
			}
			break;
			
			case 3:
			{
				int searchopt;
				bool wrong;
				do
				{
					wrong = false;
					cout << "\nPilihan Pencarian" << endl;
					cout << "\n1. Cari berdasar Nama Pasien" << endl;
					cout << "2. Cari berdasar Nama Dokter" << endl;
					cout << "3. Kembali ke menu utama" << endl;
					cout << "\nMasukkan pilihan pencarian : ";
					cin >> searchopt;
					system("cls");
					
					if(searchopt==1)
					{
						searchingNama(jumlahPasienJalan,jumlahPasienInap);
					}
					
					else if(searchopt==2)
					{
						searchingDokter(jumlahPasienJalan,jumlahPasienInap);
					}
					
					else if(searchopt==3)
					{
						break;
					}
					
					else
					{
						cout << "Menu yang anda pilih tidak ada, mohon masukkan pilihan menu dengan benar!" << endl;
						system("pause");
						system("cls");
						wrong=true;
					}
				}
				while(wrong==true);
			}
			break;
			
			case 4:
			{
				int sortopt;
				bool wrong;
				do
				{
					wrong = false;
					cout << "\nUrutkan Data Berdasar : " << endl;
					cout << "\n1. Nama" << endl;
					cout << "2. Jenis Kelamin" << endl;
					cout << "3. Alamat" << endl;
					cout << "4. Dokter dan Diagnosa" << endl;
					cout << "5. Pembayaran" << endl;
					cout << "6. Kembali ke menu utama" << endl;
					cout << "\nMasukkan pilihan pencarian : ";
					cin >> sortopt;
					system("cls");
				
					if(sortopt==1)
					{
						sortingNama(jumlahPasienJalan,jumlahPasienInap);
					}
					
					else if(sortopt==2)
					{
						sortingKelamin(jumlahPasienJalan,jumlahPasienInap);
					}
					
					else if(sortopt==3)
					{	
						sortingAlamat(jumlahPasienJalan,jumlahPasienInap);
					}
					
					else if(sortopt==4)
					{		
						sortingDiagnosa(jumlahPasienJalan,jumlahPasienInap);
					}
					
					else if(sortopt==5)
					{	
						sortingPembayaran(jumlahPasienJalan,jumlahPasienInap);
					}
					
					else if(sortopt==6)
					{
						break;
					}
					
					else
					{
						cout << "Menu yang anda pilih tidak ada, mohon masukkan pilihan menu dengan benar!" << endl;
						system("pause");
						system("cls");
						wrong=true;
					}
				}
				while(wrong==true);
			}
			break;
			
			case 5:
			{
				bool wrong;
				int bayaropt;
				do
				{
					wrong = false;
					
					cout << "\nYakin melanjutkan ke pembayaran?" << endl;
					cout << "\n1. Yakin" << endl;
					cout << "2. Kembali ke menu" << endl;
					cout << "\nMasukan pilihan : ";
					cin >> bayaropt;
					system("cls");
					
					if(bayaropt==1)
					{
						bayar(jumlahPasienJalan,jumlahPasienInap);
					}
					
					else if(bayaropt==2)
					{
						break;
					}
					
					else
					{
						cout << "\nMenu yang anda pilih tidak ada, mohon masukkan pilihan menu dengan benar!" << endl;
						system("pause");
						system("cls");
						wrong=true;
					}
				}
				while(wrong==true);
			}
			break;
			
			case 6:
			{
				cout << "+======================================+" << endl;      
				cout << "|  _   | | |   | | |     _ _        _  |" << endl;
				cout << "| | |  |_|.|_|_|.|_|.   (_) |      | | |" << endl;
				cout << "| | |___  ___  ___ _ __  _| |_ __ _| | |" << endl;
				cout << "| |  _  || _ || __|  _ || | __| _  | | |" << endl;
				cout << "| | | | |((_))|__ | |_) | | || (_| | | |" << endl;
				cout << "| |_| |_||___||___|  __||_|___|__ _|_| |" << endl;
				cout << "|                 | |                  |" << endl;
				cout << "|                 |_|                  |" << endl;
				cout << "+======================================+" << endl;                
			    cout << "|            UWU HOSPITAL              |" << endl;
				cout << "|      SPESIALIS PENYAKIT DALAM        |" << endl; 
				cout << "+======================================+" << endl;
				cout << endl;
				cout << "Terimakasih atas kunjungannya, semoga lekas sembuh. :)" << endl; 
				return 0;
				system("cls");                          
			}              
			break;
			
			default:
			{
				cout << "\nMenu yang anda pilih tidak ada!" << endl;
			}
			break;
			
		}     
		
		cout << "\nKembali ke menu utama? (y/t) :  ";
		cin >> kembali;
                  
	}
	while(kembali == 'y' || kembali =='Y');                  
	
	system("cls");
	cout << "+======================================+" << endl;      
	cout << "|  _   | | |   | | |     _ _        _  |" << endl;
	cout << "| | |  |_|.|_|_|.|_|.   (_) |      | | |" << endl;
	cout << "| | |___  ___  ___ _ __  _| |_ __ _| | |" << endl;
	cout << "| |  _  || _ || __|  _ || | __| _  | | |" << endl;
	cout << "| | | | |((_))|__ | |_) | | || (_| | | |" << endl;
	cout << "| |_| |_||___||___|  __||_|___|__ _|_| |" << endl;
	cout << "|                 | |                  |" << endl;
	cout << "|                 |_|                  |" << endl;
	cout << "+======================================+" << endl;                
    cout << "|            UWU HOSPITAL              |" << endl;
	cout << "|      SPESIALIS PENYAKIT DALAM        |" << endl; 
	cout << "+======================================+" << endl;
	cout << endl;
	cout << "Terimakasih atas kunjungannya, semoga lekas sembuh. :)" << endl;   
	return 0;
	system("cls");                          
	                  
}

void inputJalan(int *jumlahPasienJalan)
{
	int ulangInput;
	do
	{
		ulangInput = 0;
		cout << "============================================================================ " << endl;
		cout << "DAFTAR DIAGNOSA : " << endl;
		cout << "1. HIPERTENSI                  4. PENYAKIT JANTUNG" << endl;
		cout << "2. GAGAL GINJAL                5. GANGGUAN SALURAN PERNAPASAN" << endl;
		cout << "3. DIABETES" << endl;
		cout << "============================================================================ " << endl;
		
		cout << "Masukkan banyak pasien rawat jalan yang akan didata : ";
		cin >> *jumlahPasienJalan;
		cout << endl;
		
		for (int i=0;i<*jumlahPasienJalan;i++)
		{
			cout << "+------------------------+" << endl;
			cout << "|Pasien Rawat Jalan No. " << jmlJalan+1 << "|" << endl;
			cout << "+------------------------+" << endl;
			
			cout << "Nama Pasien\t\t\t : ";
			cin.ignore();
			getline(cin,jalan[jmlJalan].namaPasien);
			
			cout << "Jenis Kelamin Pasien(L/P)\t : ";
			cin >> jalan[jmlJalan].kelamin;
			
			if(jalan[jmlJalan].kelamin == 'L' || jalan[jmlJalan].kelamin == 'l')
			{
				jalan[jmlJalan].kelamin = 'L';
			}
			else if(jalan[jmlJalan].kelamin == 'P' || jalan[jmlJalan].kelamin == 'p')
			{
				jalan[jmlJalan].kelamin = 'P';
			}
			else
			{
				cout << "\nMohon input data pasien dengan benar! Penginputan diulang.\n";
				ulangInput=1;
				system("pause");
				system("cls");
				break;
			}
			
			cout << "Alamat Pasien\t\t\t : ";
			cin.ignore();
			getline(cin,jalan[jmlJalan].alamat);
			
			cout << "Diagnosa Pasien\t\t\t : ";
			cin >> jalan[jmlJalan].diagnosa;
			
			if(jalan[jmlJalan].diagnosa == "1")
			{
				jalan[jmlJalan].diagnosa = "Hipertensi";
				jalan[jmlJalan].namaDokter = "dr.Astaghfirullah,SpPD.";
				jalan[jmlJalan].hargaObat = 150000;
				jalan[jmlJalan].totalPembayaran = jalan[jmlJalan].hargaObat;
			}
			else if(jalan[jmlJalan].diagnosa == "2")
			{
				jalan[jmlJalan].diagnosa = "Gagal Ginjal";	
				jalan[jmlJalan].namaDokter = "dr.Bekantan,SpPD.";
				jalan[jmlJalan].hargaObat = 240000;
				jalan[jmlJalan].totalPembayaran = jalan[jmlJalan].hargaObat;
			}
			else if(jalan[jmlJalan].diagnosa == "3")
			{
				jalan[jmlJalan].diagnosa = "Diabetes";
				jalan[jmlJalan].namaDokter = "dr.Ci Luk Ba,SpPD.";
				jalan[jmlJalan].hargaObat = 180000;
				jalan[jmlJalan].totalPembayaran = jalan[jmlJalan].hargaObat;
			}
			else if(jalan[jmlJalan].diagnosa == "4")
			{ 
				jalan[jmlJalan].diagnosa = "Penyakit Jantung";
				jalan[jmlJalan].namaDokter = "dr.Dipa Nusantara,SpPD.";
				jalan[jmlJalan].hargaObat = 210000;
				jalan[jmlJalan].totalPembayaran = jalan[jmlJalan].hargaObat;
			}
			else if(jalan[jmlJalan].diagnosa == "5")
			{
				jalan[jmlJalan].diagnosa = "Gangguan Saluran Pernapasan";
				jalan[jmlJalan].namaDokter = "dr.Emanok,SpPD.";
				jalan[jmlJalan].hargaObat = 120000;
				jalan[jmlJalan].totalPembayaran = jalan[jmlJalan].hargaObat;
			}
			else
			{
				cout << "\nMohon input data pasien dengan benar! Penginputan diulang.\n";
				ulangInput=1;
				system("pause");
				system("cls");
				break;
			}
			
			jmlJalan++;
			cout << endl;
			
		}
	
	} while(ulangInput == 1);
	
}

void inputInap(int *jumlahPasienInap)
{
	int ulangInput;
	do
	{
		ulangInput = 0;
		char oprs;
		cout << "============================================================================ " << endl;
		cout << "DAFTAR DIAGNOSA : " << endl;
		cout << "1. HIPERTENSI                  4. PENYAKIT JANTUNG" << endl;
		cout << "2. GAGAL GINJAL                5. GANGGUAN SALURAN PERNAPASAN" << endl;
		cout << "3. DIABETES" << endl;
		cout << "============================================================================ " << endl;
	
		cout << "============================================================================ " << endl;
		cout << "DAFTAR RUANGAN INAP : " << endl;
		cout << "1. UMUM (Rp.200.000,00/hari)" << endl;
		cout << "2. VIP (Rp.500.000,00/hari)" << endl;
		cout << "3. PRESIDENT SUITE (Rp.1.000.000,00/hari)" << endl;
		cout << "============================================================================ " << endl;
		
		cout << "Masukkan banyak pasien rawat inap yang akan didata : ";
		cin >> *jumlahPasienInap;
		cout << endl;
		
		for (int i=0;i<*jumlahPasienInap;i++)
		{
			cout << "+-----------------------+" << endl;
			cout << "|Pasien Rawat Inap No. " << jmlInap+1 << "|" << endl;
			cout << "+-----------------------+" << endl;
			
			cout << "Nama Pasien\t\t\t : ";
			cin.ignore();
			getline(cin,inap[jmlInap].namaPasien);
			
			cout << "Jenis Kelamin Pasien(L/P)\t : ";
			cin >> inap[jmlInap].kelamin;
			
			if(inap[jmlInap].kelamin == 'L' || inap[jmlInap].kelamin == 'l')
			{
				inap[jmlInap].kelamin = 'L';
			}
			else if(inap[jmlInap].kelamin == 'P' || inap[jmlInap].kelamin == 'p')
			{
				inap[jmlInap].kelamin = 'P';
			}
			else
			{
				cout << "\nMohon input data pasien dengan benar! Penginputan diulang.\n";
				ulangInput=1;
				system("pause");
				system("cls");
				break;
			}
			
			cout << "Alamat Pasien\t\t\t : ";
			cin.ignore();
			getline(cin,inap[jmlInap].alamat);
			
			cout << "Diagnosa Pasien\t\t\t : ";
			cin >> inap[jmlInap].diagnosa;
			
			if(inap[jmlInap].diagnosa == "1")
			{
				inap[jmlInap].diagnosa = "Hipertensi";
				inap[jmlInap].namaDokter = "dr.Astaghfirullah,SpPD.";
				inap[jmlInap].hargaObat = 150000;
			}
			else if(inap[jmlInap].diagnosa == "2")
			{
				inap[jmlInap].diagnosa = "Gagal Ginjal";	
				inap[jmlInap].namaDokter = "dr.Bekantan,SpPD.";
				inap[jmlInap].hargaObat = 240000;
			}
			else if(inap[jmlInap].diagnosa == "3")
			{
				inap[jmlInap].diagnosa = "Diabetes";
				inap[jmlInap].namaDokter = "dr.Ci Luk Ba,SpPD.";
				inap[jmlInap].hargaObat = 180000;
			}
			else if(inap[jmlInap].diagnosa == "4")
			{ 
				inap[jmlInap].diagnosa = "Penyakit Jantung";
				inap[jmlInap].namaDokter = "dr.Dipa Nusantara,SpPD.";
				inap[jmlInap].hargaObat = 210000;
			}
			else if(inap[jmlInap].diagnosa == "5")
			{
				inap[jmlInap].diagnosa = "Gangguan Saluran Pernapasan";
				inap[jmlInap].namaDokter = "dr.Emanok,SpPD.";
				inap[jmlInap].hargaObat = 120000;
			}
			else
			{
				cout << "\nMohon input data pasien dengan benar! Penginputan diulang.\n";
				ulangInput=1;
				system("pause");
				system("cls");
				break;
			}
			
			cout << "Kelas Ruangan\t\t\t : ";
			cin >> inap[jmlInap].ruangan;
			
			if(inap[jmlInap].ruangan == "1")
			{
				inap[jmlInap].ruangan = "Umum";
				inap[jmlInap].totalPembayaran = inap[jmlInap].totalPembayaran + 200000;
			}
			else if(inap[jmlInap].ruangan == "2")
			{
				inap[jmlInap].ruangan = "VIP";
				inap[jmlInap].totalPembayaran = inap[jmlInap].totalPembayaran + 500000;
			}
			else if(inap[jmlInap].ruangan == "3")
			{
				inap[jmlInap].ruangan = "President Suite";
				inap[jmlInap].totalPembayaran = inap[jmlInap].totalPembayaran + 1000000;
			}
			else
			{
				cout << "\nMohon input data pasien dengan benar! Penginputan diulang.\n";
				ulangInput=1;
				system("pause");
				system("cls");
				break;
			}		
			
			cout << "Lama Inap(dalam hari)\t\t : ";
			cin >> inap[jmlInap].lamaInap;
			
			inap[jmlInap].totalPembayaran = inap[jmlInap].totalPembayaran * inap[jmlInap].lamaInap;
			
			cout << "Perlukah dilakukan operasi? (Biaya : Rp.3.000.000,00) (y/t) : ";
			cin >> oprs;
			
			if(oprs=='y' || oprs=='Y')
			{
				inap[jmlInap].operasi = "Ya";
				inap[jmlInap].totalPembayaran = inap[jmlInap].totalPembayaran + 3000000;
			}
			else if(oprs=='t' || oprs=='T')
			{
				inap[jmlInap].operasi = "Tidak";
			}
			else
			{
				cout << "\nMohon input data pasien dengan benar! Penginputan diulang.\n";
				ulangInput=1;
				system("pause");
				system("cls");
				break;
			}
			
			inap[jmlInap].totalPembayaran = inap[jmlInap].totalPembayaran + inap[jmlInap].hargaObat;
			
			jmlInap++;
			cout << endl;
			
		}
	
	} while(ulangInput == 1);
	
}

void daftarJalan(int jmlJalan)
{
	cout << endl;
	
	cout << "Pasien Rawat Jalan No. " << jmlJalan+1 << endl << endl;
	
	cout << "Nama pasien\t\t\t : " << jalan[jmlJalan].namaPasien << endl;

	cout << "Jenis kelamin pasien\t\t : " << jalan[jmlJalan].kelamin << endl;
		
	cout << "Alamat pasien\t\t\t : " << jalan[jmlJalan].alamat << endl;
		
	cout << "Diagnosa pasien\t\t\t : " << jalan[jmlJalan].diagnosa << endl;
		
	cout << "Nama dokter yang menangani\t : " << jalan[jmlJalan].namaDokter << endl;
		
	cout << "Harga obat\t\t\t : " << jalan[jmlJalan].hargaObat << " Rupiah." << endl;
		
	cout << "Total Pembayaran\t\t : " << jalan[jmlJalan].totalPembayaran << " Rupiah." << endl;
		
	if(jmlJalan>0) daftarJalan(jmlJalan-1);
}

void daftarInap(int jmlInap)
{
		cout << endl;
		
		cout << "Pasien Rawat Inap No. " << jmlInap+1 << endl << endl;
	
		cout << "Nama pasien\t\t\t : " << inap[jmlInap].namaPasien << endl;

		cout << "Jenis kelamin pasien\t\t : " << inap[jmlInap].kelamin << endl;
		
		cout << "Alamat pasien\t\t\t : " << inap[jmlInap].alamat << endl;
		
		cout << "Diagnosa pasien\t\t\t : " << inap[jmlInap].diagnosa << endl;
		
		cout << "Nama dokter yang menangani\t : " << inap[jmlInap].namaDokter << endl;
		
		cout << "Harga obat\t\t\t : " << inap[jmlInap].hargaObat << " Rupiah." << endl;
		
		cout << "Kelas ruangan pasien\t\t : " << inap[jmlInap].ruangan << endl;
		
		cout << "Lama pasien menginap\t\t : " << inap[jmlInap].lamaInap << " hari." << endl;
		
		cout << "Memerlukan operasi\t\t : " << inap[jmlInap].operasi << endl;
		
		cout << "Total Pembayaran\t\t : " << inap[jmlInap].totalPembayaran << " Rupiah." << endl;
			
	if(jmlInap>0) daftarInap(jmlInap-1);
}

void searchingNama(int jumlahPasienJalan, int jumlahPasienInap)
{
	string cari;
	int i;
	bool jfound = false;
	bool ifound = false;
	
	cout << endl;
	cout << "\t===================================" << endl;
	cout << "\t=      SEARCHING NAMA PASIEN      =" << endl;
	cout << "\t===================================" << endl;
	cout << endl;
	
	cout << "Masukkan nama pasien yang dicari : ";
	cin >> cari;
	
	string carip = allUpCase(cari);
	
	cout << endl;

	cout << "+========================================================+" << endl;
	cout << "|        HASIL PENCARIAN PADA PASIEN RAWAT JALAN         |" << endl;
	cout << "+========================================================+" << endl;
	cout << endl;
	
	if(jmlJalan>0)
	{	
	    for (i=0; i<jmlJalan; i++) 
	    {
	    	string jpasien = allUpCase(jalan[i].namaPasien); //agar nama pasien dengan huruf kapital bisa tampil saat pencarian dengan huruf kecil
	        if(jpasien.find(carip) != string::npos)  //agar sistem menampilkan nilai variabel yang mengandung nilai tersebut
	        {
	        	jfound = true;
	        	
	            cout << "Pasien Rawat Jalan No. " << i+1 << endl << endl;
				
				cout << "Nama pasien\t\t\t : " << jalan[i].namaPasien << endl;
			
				cout << "Jenis kelamin pasien\t\t : " << jalan[i].kelamin << endl;
					
				cout << "Alamat pasien\t\t\t : " << jalan[i].alamat << endl;
					
				cout << "Diagnosa pasien\t\t\t : " << jalan[i].diagnosa << endl;
					
				cout << "Nama dokter yang menangani\t : " << jalan[i].namaDokter << endl;
					
				cout << "Harga obat\t\t\t : " << jalan[i].hargaObat << " Rupiah." << endl;
					
				cout << "Total Pembayaran\t\t : " << jalan[i].totalPembayaran << " Rupiah."<< endl;
				
				cout << endl;
	        }
	
		}
    }
    
    if(jfound==false)
    {
    	cout << "NAMA PASIEN YANG DICARI TIDAK ADA DI DAFTAR RAWAT JALAN" << endl << endl;
	}
    
	cout << "+=======================================================+" << endl;
	cout << "|        HASIL PENCARIAN PADA PASIEN RAWAT INAP         |" << endl;
	cout << "+=======================================================+" << endl;
	cout << endl;
	
	if(jmlInap>0)
    {
		for (i=0; i<jmlInap; i++) 
	    {
	    	string ipasien = allUpCase(inap[i].namaPasien);
	        if(ipasien.find(carip) != string::npos)
	        {
	        	ifound = true;
	        	
	            cout << "Pasien Rawat Inap No. " << i+1 << endl << endl;
				
				cout << "Nama pasien\t\t\t : " << inap[i].namaPasien << endl;
			
				cout << "Jenis kelamin pasien\t\t : " << inap[i].kelamin << endl;
					
				cout << "Alamat pasien\t\t\t : " << inap[i].alamat << endl;
					
				cout << "Diagnosa pasien\t\t\t : " << inap[i].diagnosa << endl;
					
				cout << "Nama dokter yang menangani\t : " << inap[i].namaDokter << endl;
					
				cout << "Harga obat\t\t\t : " << inap[i].hargaObat << " Rupiah." << endl;
					
				cout << "Kelas ruangan pasien\t\t : " << inap[i].ruangan << endl;
					
				cout << "Lama pasien menginap\t\t : " << inap[i].lamaInap << " hari." << endl;
					
				cout << "Memerlukan operasi\t\t : " << inap[i].operasi << endl;
					
				cout << "Total Pembayaran\t\t : " << inap[i].totalPembayaran << " Rupiah." << endl;
				
				cout << endl;
	        }
	        
	    }
    }
    
    if(ifound==false)
    {
    	cout << "NAMA PASIEN YANG DICARI TIDAK ADA DI DAFTAR RAWAT INAP" << endl << endl;
	}
    
}

void searchingDokter(int jumlahPasienJalan, int jumlahPasienInap)
{
	string cari;
	int i;
	bool jfound = false;
	bool ifound = false;
	
	cout << endl;
	cout << "\t===================================" << endl;
	cout << "\t=      SEARCHING NAMA DOKTER      =" << endl;
	cout << "\t===================================" << endl;
	cout << endl;
	
	cout << "Masukkan nama dokter yang dicari : ";
	cin >> cari;
	
	string carid = allUpCase(cari);
	
	cout << endl;

    cout << "+========================================================+" << endl;
	cout << "|        HASIL PENCARIAN PADA PASIEN RAWAT JALAN         |" << endl;
	cout << "+========================================================+" << endl;
	cout << endl;
	
	if(jmlJalan>0)
	{	
	    for (i=0; i<jmlJalan; i++) 
	    {
	    	string jdokter = allUpCase(jalan[i].namaDokter);
	        if(jdokter.find(carid) != string::npos)
	        {
	        	jfound = true;
	        	
	            cout << "Pasien Rawat Jalan No. " << i+1 << endl << endl;
				
				cout << "Nama pasien\t\t\t : " << jalan[i].namaPasien << endl;
			
				cout << "Jenis kelamin pasien\t\t : " << jalan[i].kelamin << endl;
					
				cout << "Alamat pasien\t\t\t : " << jalan[i].alamat << endl;
					
				cout << "Diagnosa pasien\t\t\t : " << jalan[i].diagnosa << endl;
					
				cout << "Nama dokter yang menangani\t : " << jalan[i].namaDokter << endl;
					
				cout << "Harga obat\t\t\t : " << jalan[i].hargaObat << " Rupiah." << endl;
					
				cout << "Total Pembayaran\t\t : " << jalan[i].totalPembayaran << " Rupiah."<< endl;
				
				cout << endl;
	        }
	        
		}
    }
    
    if(jfound==false)
    {
    	cout << "NAMA PASIEN YANG DICARI TIDAK ADA DI DAFTAR RAWAT JALAN" << endl << endl;
	}
    
	cout << "+=======================================================+" << endl;
	cout << "|        HASIL PENCARIAN PADA PASIEN RAWAT INAP         |" << endl;
	cout << "+=======================================================+" << endl;
	cout << endl;
	
	if(jmlInap>0)
    {
		for (i=0; i<jmlInap; i++) 
	    {
	    	string idokter = allUpCase(inap[i].namaDokter);
	        if(idokter.find(carid) != string::npos)
	        {
	        	ifound = true;
	        	
	            cout << "Pasien Rawat Inap No. " << i+1 << endl << endl;
				
				cout << "Nama pasien\t\t\t : " << inap[i].namaPasien << endl;
			
				cout << "Jenis kelamin pasien\t\t : " << inap[i].kelamin << endl;
					
				cout << "Alamat pasien\t\t\t : " << inap[i].alamat << endl;
					
				cout << "Diagnosa pasien\t\t\t : " << inap[i].diagnosa << endl;
					
				cout << "Nama dokter yang menangani\t : " << inap[i].namaDokter << endl;
					
				cout << "Harga obat\t\t\t : " << inap[i].hargaObat << " Rupiah." << endl;
					
				cout << "Kelas ruangan pasien\t\t : " << inap[i].ruangan << endl;
					
				cout << "Lama pasien menginap\t\t : " << inap[i].lamaInap << " hari." << endl;
					
				cout << "Memerlukan operasi\t\t : " << inap[i].operasi << endl;
					
				cout << "Total Pembayaran\t\t : " << inap[i].totalPembayaran << " Rupiah." << endl;
				
				cout << endl;
	        }
	        
	    }
    }
    
    if(ifound==false)
    {
    	cout << "NAMA PASIEN YANG DICARI TIDAK ADA DI DAFTAR RAWAT INAP" << endl << endl;
	}
	
}

void sortingNama(int jumlahPasienJalan,int jumlahPasienInap)
{
	dataJalan jtemp;
	dataInap itemp;

	cout << endl;
    cout << "\t\t===============================" << endl;
	cout << "\t\t=     HASIL SORTING NAMA      =" << endl;
	cout << "\t\t===============================" << endl;
	cout << endl;
	
	for (int i=0; i<jmlJalan; i++) //bubblesort
    {
    	string bk1 = allUpCase(jalan[i].namaPasien); //masuk ke fungsi untuk menjadikan seluruh string menjadi uppercase agar menjadi insensitive case
        for (int j=i+1; j<jmlJalan; j++)
        {
            string bk2 = allUpCase(jalan[j].namaPasien);
            if (bk1 > bk2)
            {
                jtemp = jalan[i];
                jalan[i] = jalan[j];
                jalan[j] = jtemp;
                if(bk1 > bk2)
                {
                	for (int i=0; i<jmlJalan; i++) //bubblesort
				    {
				    	string bk1 = allUpCase(jalan[i].namaPasien); //masuk ke fungsi untuk menjadikan seluruh string menjadi uppercase agar menjadi insensitive case
				        for (int j=i+1; j<jmlJalan; j++)
				        {
				            string bk2 = allUpCase(jalan[j].namaPasien);
				            if (bk1 > bk2)
				            {
				                jtemp = jalan[i];
				                jalan[i] = jalan[j];
				                jalan[j] = jtemp;
				            }
				        }
				    }
				}
            }
        }
    }
    
    for (int i=0; i<jmlInap; i++)
    {
        string bk1 = allUpCase(inap[i].namaPasien);
        for (int j=i+1; j<jmlInap; j++)
        {
            string bk2 = allUpCase(inap[j].namaPasien);
            if (bk1 > bk2)
            {
                itemp = inap[i];
                inap[i] = inap[j];
                inap[j] = itemp;
                if(bk1 > bk2)
                {
                	for (int i=0; i<jmlInap; i++)
				    {
				        string bk1 = allUpCase(inap[i].namaPasien);
				        for (int j=i+1; j<jmlInap; j++)
				        {
				            string bk2 = allUpCase(inap[j].namaPasien);
				            if (bk1 > bk2)
				            {
				                itemp = inap[i];
				                inap[i] = inap[j];
				                inap[j] = itemp;
				            }
				        }
				    }
				}
            }
        }
    }
    
    cout << "+=========================================================+" << endl;
	cout << "|        HASIL PENGURUTAN PADA PASIEN RAWAT JALAN         |" << endl;
	cout << "+=========================================================+" << endl;
	cout << endl;

	if(jmlJalan>0)
	{
	    for (int i=0; i<jmlJalan; i++)
	    {
			cout << "Nama pasien\t\t\t : " << jalan[i].namaPasien << endl;
	
			cout << "Jenis kelamin pasien\t\t : " << jalan[i].kelamin << endl;
				
			cout << "Alamat pasien\t\t\t : " << jalan[i].alamat << endl;
				
			cout << "Diagnosa pasien\t\t\t : " << jalan[i].diagnosa << endl;
				
			cout << "Nama dokter yang menangani\t : " << jalan[i].namaDokter << endl;
				
			cout << "Harga obat\t\t\t : " << jalan[i].hargaObat << " Rupiah." << endl;
				
			cout << "Total Pembayaran\t\t : " << jalan[i].totalPembayaran << " Rupiah." << endl;
			
			cout << endl;
	    }
	}
	
	else
	{
		cout << "DATA PASIEN PADA DAFTAR RAWAT JALAN KOSONG." << endl << endl;
	}
	
	cout << "+=======================================================+" << endl;
	cout << "|        HASIL PENGURUTAN PADA PASIEN RAWAT INAP         |" << endl;
	cout << "+=======================================================+" << endl;
	cout << endl;
		
	if(jmlInap>0)
	{
	    for (int i=0; i<jmlInap; i++)
	    {
			cout << "Nama pasien\t\t\t : " << inap[i].namaPasien << endl;
	
			cout << "Jenis kelamin pasien\t\t : " << inap[i].kelamin << endl;
				
			cout << "Alamat pasien\t\t\t : " << inap[i].alamat << endl;
				
			cout << "Diagnosa pasien\t\t\t : " << inap[i].diagnosa << endl;
				
			cout << "Nama dokter yang menangani\t : " << inap[i].namaDokter << endl;
				
			cout << "Harga obat\t\t\t : " << inap[i].hargaObat << " Rupiah." << endl;
				
			cout << "Kelas ruangan pasien\t\t : " << inap[i].ruangan << endl;
				
			cout << "Lama pasien menginap\t\t : " << inap[i].lamaInap << " hari." << endl;
				
			cout << "Memerlukan operasi\t\t : " << inap[i].operasi << endl;
				
			cout << "Total Pembayaran\t\t : " << inap[i].totalPembayaran << " Rupiah." << endl;
			
			cout << endl;
		}
	}
	
	else
	{
		cout << "DATA PASIEN PADA DAFTAR RAWAT INAP KOSONG." << endl << endl;
	}
	
}		

void sortingKelamin(int jumlahPasienJalan,int jumlahPasienInap)
{
	dataJalan jtemp;
	dataInap itemp;
	
	cout << endl;
    cout << "\t========================================" << endl;
	cout << "\t=     HASIL SORTING JENIS KELAMIN      =" << endl;
	cout << "\t========================================" << endl;
	cout << endl;
	
	for(int i=1; i<jmlJalan; i++) //insertion sort
	{
        int j = i;
        // selama kanan < kiri tukar terus
        while(j>0 && jalan[j].kelamin < jalan[j-1].kelamin) 
		{
            // tukar
            jtemp = jalan[j];
            jalan[j] = jalan[j-1];
            jalan[j-1] = jtemp;
            // pindah ke kiri
            j--;
        }
    }
    
    for(int i=1; i<jmlInap; i++)
	{
        int j = i;
        // selama kanan < kiri tukar terus
        while(j>0 && inap[j].kelamin < inap[j-1].kelamin) 
		{
            // tukar
            itemp = inap[j];
            inap[j] = inap[j-1];
            inap[j-1] = itemp;
            // pindah ke kiri
            j--;
        }
    }
    
    cout << "+=========================================================+" << endl;
	cout << "|        HASIL PENGURUTAN PADA PASIEN RAWAT JALAN         |" << endl;
	cout << "+=========================================================+" << endl;
	cout << endl;

	if(jmlJalan>0)
	{
	    for (int i=0; i<jmlJalan; i++)
	    {
			cout << "Nama pasien\t\t\t : " << jalan[i].namaPasien << endl;
	
			cout << "Jenis kelamin pasien\t\t : " << jalan[i].kelamin << endl;
				
			cout << "Alamat pasien\t\t\t : " << jalan[i].alamat << endl;
				
			cout << "Diagnosa pasien\t\t\t : " << jalan[i].diagnosa << endl;
				
			cout << "Nama dokter yang menangani\t : " << jalan[i].namaDokter << endl;
				
			cout << "Harga obat\t\t\t : " << jalan[i].hargaObat << " Rupiah." << endl;
				
			cout << "Total Pembayaran\t\t : " << jalan[i].totalPembayaran << " Rupiah." << endl;
			
			cout << endl;
	    }
	}
	
	else
	{
		cout << "DATA PASIEN PADA DAFTAR RAWAT JALAN KOSONG." << endl << endl;
	}
	
	cout << "+=======================================================+" << endl;
	cout << "|        HASIL PENGURUTAN PADA PASIEN RAWAT INAP         |" << endl;
	cout << "+=======================================================+" << endl;
	cout << endl;
		
	if(jmlInap>0)
	{
	    for (int i=0; i<jmlInap; i++)
	    {
			cout << "Nama pasien\t\t\t : " << inap[i].namaPasien << endl;
	
			cout << "Jenis kelamin pasien\t\t : " << inap[i].kelamin << endl;
				
			cout << "Alamat pasien\t\t\t : " << inap[i].alamat << endl;
				
			cout << "Diagnosa pasien\t\t\t : " << inap[i].diagnosa << endl;
				
			cout << "Nama dokter yang menangani\t : " << inap[i].namaDokter << endl;
				
			cout << "Harga obat\t\t\t : " << inap[i].hargaObat << " Rupiah." << endl;
				
			cout << "Kelas ruangan pasien\t\t : " << inap[i].ruangan << endl;
				
			cout << "Lama pasien menginap\t\t : " << inap[i].lamaInap << " hari." << endl;
				
			cout << "Memerlukan operasi\t\t : " << inap[i].operasi << endl;
				
			cout << "Total Pembayaran\t\t : " << inap[i].totalPembayaran << " Rupiah." << endl;
			
			cout << endl;
		}
	}
	
	else
	{
		cout << "DATA PASIEN PADA DAFTAR RAWAT INAP KOSONG." << endl << endl;
	}
	
}

void sortingAlamat(int jumlahPasienJalan,int jumlahPasienInap)
{
	dataJalan jtemp;
	dataInap itemp;
	
	cout << endl;
    cout << "\t=================================" << endl;
	cout << "\t=     HASIL SORTING ALAMAT      =" << endl;
	cout << "\t=================================" << endl;
	cout << endl;
	
	for (int i=0; i<jmlJalan; i++)
    {
        string bk1 = allUpCase(jalan[i].alamat);
        for (int j=i+1; j<jmlJalan; j++)
        {
            string bk2 = allUpCase(jalan[j].alamat);
            if (bk1 > bk2)
            {
                jtemp = jalan[i];
                jalan[i] = jalan[j];
                jalan[j] = jtemp;
                if(bk1 > bk2)
                {
                	for (int i=0; i<jmlJalan; i++)
				    {
				        string bk1 = allUpCase(jalan[i].alamat);
				        for (int j=i+1; j<jmlJalan; j++)
				        {
				            string bk2 = allUpCase(jalan[j].alamat);
				            if (bk1 > bk2)
				            {
				                jtemp = jalan[i];
				                jalan[i] = jalan[j];
				                jalan[j] = jtemp;
				            }
				        }
				    }
				}
            }
        }
    }
    
    for (int i=0; i<jmlInap; i++)
    {
        string bk1 = allUpCase(inap[i].alamat);
        for (int j=i+1; j<jmlInap; j++)
        {
            string bk2 = allUpCase(inap[j].alamat);
            if (bk1 > bk2)
            {
                itemp = inap[i];
                inap[i] = inap[j];
                inap[j] = itemp;
                if(bk1 > bk2)
                {
                	for (int i=0; i<jmlInap; i++)
				    {
				        string bk1 = allUpCase(inap[i].alamat);
				        for (int j=i+1; j<jmlInap; j++)
				        {
				            string bk2 = allUpCase(inap[j].alamat);
				            if (bk1 > bk2)
				            {
				                itemp = inap[i];
				                inap[i] = inap[j];
				                inap[j] = itemp;
				            }
				        }
				    }
				}
            }
        }
    }
    
    cout << "+=========================================================+" << endl;
	cout << "|        HASIL PENGURUTAN PADA PASIEN RAWAT JALAN         |" << endl;
	cout << "+=========================================================+" << endl;
	cout << endl;

	if(jmlJalan>0)
	{
	    for (int i=0; i<jmlJalan; i++)
	    {
			cout << "Nama pasien\t\t\t : " << jalan[i].namaPasien << endl;
	
			cout << "Jenis kelamin pasien\t\t : " << jalan[i].kelamin << endl;
				
			cout << "Alamat pasien\t\t\t : " << jalan[i].alamat << endl;
				
			cout << "Diagnosa pasien\t\t\t : " << jalan[i].diagnosa << endl;
				
			cout << "Nama dokter yang menangani\t : " << jalan[i].namaDokter << endl;
				
			cout << "Harga obat\t\t\t : " << jalan[i].hargaObat << " Rupiah." << endl;
				
			cout << "Total Pembayaran\t\t : " << jalan[i].totalPembayaran << " Rupiah." << endl;
			
			cout << endl;
	    }
	}
	
	else
	{
		cout << "DATA PASIEN PADA DAFTAR RAWAT JALAN KOSONG." << endl << endl;
	}
	
	cout << "+=======================================================+" << endl;
	cout << "|        HASIL PENGURUTAN PADA PASIEN RAWAT INAP         |" << endl;
	cout << "+=======================================================+" << endl;
	cout << endl;
		
	if(jmlInap>0)
	{
	    for (int i=0; i<jmlInap; i++)
	    {
			cout << "Nama pasien\t\t\t : " << inap[i].namaPasien << endl;
	
			cout << "Jenis kelamin pasien\t\t : " << inap[i].kelamin << endl;
				
			cout << "Alamat pasien\t\t\t : " << inap[i].alamat << endl;
				
			cout << "Diagnosa pasien\t\t\t : " << inap[i].diagnosa << endl;
				
			cout << "Nama dokter yang menangani\t : " << inap[i].namaDokter << endl;
				
			cout << "Harga obat\t\t\t : " << inap[i].hargaObat << " Rupiah." << endl;
				
			cout << "Kelas ruangan pasien\t\t : " << inap[i].ruangan << endl;
				
			cout << "Lama pasien menginap\t\t : " << inap[i].lamaInap << " hari." << endl;
				
			cout << "Memerlukan operasi\t\t : " << inap[i].operasi << endl;
				
			cout << "Total Pembayaran\t\t : " << inap[i].totalPembayaran << " Rupiah." << endl;
			
			cout << endl;
		}
	}
	
	else
	{
		cout << "DATA PASIEN PADA DAFTAR RAWAT INAP KOSONG." << endl << endl;
	}
	
}

void sortingDiagnosa(int jumlahPasienJalan,int jumlahPasienInap)
{
	dataJalan jtemp;
    dataInap itemp;
    
    cout << endl;
    cout << "\t===================================" << endl;
	cout << "\t=     HASIL SORTING DIAGNOSA      =" << endl;
	cout << "\t===================================" << endl;
	cout << endl;
	
    for (int i = jmlJalan/2; i > 0; i /= 2) //shellsort
	{
        for (int j = i; j < jmlJalan; j++) 
		{
            for (int k = j-i; k >= 0; k -= i) 
			{
                if (jalan[k + i].namaDokter >= jalan[k].namaDokter)  //yang dibandingkan variabel namaDokter karena setiap diagnosa hanya memiliki seorang dokter
				{
                    0;
                } else 
				{
                    jtemp = jalan[k];
                    jalan[k] = jalan[k + i];
                    jalan[k + i] = jtemp;
                }
            }
        }
    }
    
    for (int i = jmlInap/2; i > 0; i /= 2) 
	{
        for (int j = i; j < jmlInap; j++) 
		{
            for (int k = j-i; k >= 0; k -= i) 
			{
                if (inap[k + i].namaDokter >= inap[k].namaDokter) 
				{
                    0;
                } else 
				{
                    itemp = inap[k];
                    inap[k] = inap[k + i];
                    inap[k + i] = itemp;
                }
            }
        }
    }   
    
    cout << "+=========================================================+" << endl;
	cout << "|        HASIL PENGURUTAN PADA PASIEN RAWAT JALAN         |" << endl;
	cout << "+=========================================================+" << endl;
	cout << endl;

	if(jmlJalan>0)
	{
	    for (int i=0; i<jmlJalan; i++)
	    {
			cout << "Nama pasien\t\t\t : " << jalan[i].namaPasien << endl;
	
			cout << "Jenis kelamin pasien\t\t : " << jalan[i].kelamin << endl;
				
			cout << "Alamat pasien\t\t\t : " << jalan[i].alamat << endl;
				
			cout << "Diagnosa pasien\t\t\t : " << jalan[i].diagnosa << endl;
				
			cout << "Nama dokter yang menangani\t : " << jalan[i].namaDokter << endl;
				
			cout << "Harga obat\t\t\t : " << jalan[i].hargaObat << " Rupiah." << endl;
				
			cout << "Total Pembayaran\t\t : " << jalan[i].totalPembayaran << " Rupiah." << endl;
			
			cout << endl;
	    }
	}
	
	else
	{
		cout << "DATA PASIEN PADA DAFTAR RAWAT JALAN KOSONG." << endl << endl;
	}
	
	cout << "+=======================================================+" << endl;
	cout << "|        HASIL PENGURUTAN PADA PASIEN RAWAT INAP         |" << endl;
	cout << "+=======================================================+" << endl;
	cout << endl;
		
	if(jmlInap>0)
	{
	    for (int i=0; i<jmlInap; i++)
	    {
			cout << "Nama pasien\t\t\t : " << inap[i].namaPasien << endl;
	
			cout << "Jenis kelamin pasien\t\t : " << inap[i].kelamin << endl;
				
			cout << "Alamat pasien\t\t\t : " << inap[i].alamat << endl;
				
			cout << "Diagnosa pasien\t\t\t : " << inap[i].diagnosa << endl;
				
			cout << "Nama dokter yang menangani\t : " << inap[i].namaDokter << endl;
				
			cout << "Harga obat\t\t\t : " << inap[i].hargaObat << " Rupiah." << endl;
				
			cout << "Kelas ruangan pasien\t\t : " << inap[i].ruangan << endl;
				
			cout << "Lama pasien menginap\t\t : " << inap[i].lamaInap << " hari." << endl;
				
			cout << "Memerlukan operasi\t\t : " << inap[i].operasi << endl;
				
			cout << "Total Pembayaran\t\t : " << inap[i].totalPembayaran << " Rupiah." << endl;
			
			cout << endl;
		}
	}
	
	else
	{
		cout << "DATA PASIEN PADA DAFTAR RAWAT INAP KOSONG." << endl << endl;
	}
}

void sortingPembayaran(int jumlahPasienJalan,int jumlahPasienInap)
{
    dataJalan jtemp;
    dataInap itemp;
    
    cout << endl;
	cout << "\t=====================================" << endl;
	cout << "\t=     HASIL SORTING PEMBAYARAN      =" << endl;
	cout << "\t=====================================" << endl;
	cout << endl;

	cout << endl;
	
    for (int i=0; i<jmlJalan; i++)
    {
        for (int j=i+1; j<jmlJalan; j++)
        {
            if (jalan[i].totalPembayaran > jalan[j].totalPembayaran)
            {
                jtemp = jalan[i];
                jalan[i] = jalan[j];
                jalan[j] = jtemp;
                if (jalan[i].totalPembayaran > jalan[j].totalPembayaran)
                {
                	for (int i=0; i<jmlJalan; i++)
				    {
				        for (int j=i+1; j<jmlJalan; j++)
				        {
				            if (jalan[i].totalPembayaran > jalan[j].totalPembayaran)
				            {
				                jtemp = jalan[i];
				                jalan[i] = jalan[j];
				                jalan[j] = jtemp;
				            }
				        }
				    }
				}
            }
        }
    }
    
    for (int i=0; i<jmlInap; i++)
    {
        for (int j=i+1; j<jmlInap; j++)
        {
            if (inap[i].totalPembayaran > inap[j].totalPembayaran)
            {
                itemp = inap[i];
                inap[i] = inap[j];
                inap[j] = itemp;
                if (inap[i].totalPembayaran > inap[j].totalPembayaran)
                {
                	for (int i=0; i<jmlInap; i++)
				    {
				        for (int j=i+1; j<jmlInap; j++)
				        {
				            if (inap[i].totalPembayaran > inap[j].totalPembayaran)
				            {
				                itemp = inap[i];
				                inap[i] = inap[j];
				                inap[j] = itemp;
				            }
				        }
				    }    
				}
            }
        }
    }    

	cout << "+=========================================================+" << endl;
	cout << "|        HASIL PENGURUTAN PADA PASIEN RAWAT JALAN         |" << endl;
	cout << "+=========================================================+" << endl;
	cout << endl;

	if(jmlJalan>0)
	{
	    for (int i=0; i<jmlJalan; i++)
	    {
			cout << "Nama pasien\t\t\t : " << jalan[i].namaPasien << endl;
	
			cout << "Jenis kelamin pasien\t\t : " << jalan[i].kelamin << endl;
				
			cout << "Alamat pasien\t\t\t : " << jalan[i].alamat << endl;
				
			cout << "Diagnosa pasien\t\t\t : " << jalan[i].diagnosa << endl;
				
			cout << "Nama dokter yang menangani\t : " << jalan[i].namaDokter << endl;
				
			cout << "Harga obat\t\t\t : " << jalan[i].hargaObat << " Rupiah." << endl;
				
			cout << "Total Pembayaran\t\t : " << jalan[i].totalPembayaran << " Rupiah." << endl;
			
			cout << endl;
	    }
	}
	
	else
	{
		cout << "DATA PASIEN PADA DAFTAR RAWAT JALAN KOSONG." << endl << endl;
	}
	
	cout << "+=======================================================+" << endl;
	cout << "|        HASIL PENGURUTAN PADA PASIEN RAWAT INAP         |" << endl;
	cout << "+=======================================================+" << endl;
	cout << endl;
		
	if(jmlInap>0)
	{
	    for (int i=0; i<jmlInap; i++)
	    {
			cout << "Nama pasien\t\t\t : " << inap[i].namaPasien << endl;
	
			cout << "Jenis kelamin pasien\t\t : " << inap[i].kelamin << endl;
				
			cout << "Alamat pasien\t\t\t : " << inap[i].alamat << endl;
				
			cout << "Diagnosa pasien\t\t\t : " << inap[i].diagnosa << endl;
				
			cout << "Nama dokter yang menangani\t : " << inap[i].namaDokter << endl;
				
			cout << "Harga obat\t\t\t : " << inap[i].hargaObat << " Rupiah." << endl;
				
			cout << "Kelas ruangan pasien\t\t : " << inap[i].ruangan << endl;
				
			cout << "Lama pasien menginap\t\t : " << inap[i].lamaInap << " hari." << endl;
				
			cout << "Memerlukan operasi\t\t : " << inap[i].operasi << endl;
				
			cout << "Total Pembayaran\t\t : " << inap[i].totalPembayaran << " Rupiah." << endl;
			
			cout << endl;
		}
	}
	
	else
	{
		cout << "DATA PASIEN PADA DAFTAR RAWAT INAP KOSONG." << endl << endl;
	}
    
}

void bayar(int jumlahPasienJalan,int jumlahPasienInap)
{
	string cariNama,cariAlamat;
	int ulang,i,j,nominal;
	char sesuai;
	
	do
	{
		bool jfound = false;
		bool ifound = false;
		int jp = 0;
		int ip = 0;
		ulang = 0;
		cout << endl;
		cout << "+===========================================+" <<endl;
		cout << "|    PEMBAYARAN ADMINISTRASI RUMAH SAKIT    |" << endl;
		cout << "+===========================================+" <<endl;
		cout << endl;
		cout << "Masukkan nama lengkap pasien\t : ";
		cin.ignore();
		getline(cin,cariNama);
		cout << "Masukkan alamat lengkap pasien\t : ";
		cin.ignore();
		getline(cin,cariAlamat);
		cout << endl;

		cout << "+========================================================+" << endl;
		cout << "|        HASIL PENCARIAN PADA PASIEN RAWAT JALAN         |" << endl;
		cout << "+========================================================+" << endl;
		cout << endl;		

		if(jmlJalan>0)
		{	
		    for (i=0; i<jmlJalan; i++) 
		    {
		        if(jalan[i].namaPasien.find(cariNama) != string::npos)
		        {
		        	if(jalan[i].alamat.find(cariAlamat) != string::npos)
		        	{
			        	jfound = true;
			        	
			            cout << "Pasien Rawat Jalan No. " << i+1 << endl << endl;
						
						cout << "Nama pasien\t\t\t : " << jalan[i].namaPasien << endl;
					
						cout << "Jenis kelamin pasien\t\t : " << jalan[i].kelamin << endl;
							
						cout << "Alamat pasien\t\t\t : " << jalan[i].alamat << endl;
							
						cout << "Diagnosa pasien\t\t\t : " << jalan[i].diagnosa << endl;
							
						cout << "Nama dokter yang menangani\t : " << jalan[i].namaDokter << endl;
							
						cout << "Harga obat\t\t\t : " << jalan[i].hargaObat << " Rupiah." << endl;
							
						cout << "Total Pembayaran\t\t : " << jalan[i].totalPembayaran << " Rupiah."<< endl;
						
						jp++;
						
						cout << endl;
					}
		        }
		
			}
	    }
	    
	    if(jfound==false)
	    {
	    	cout << "PASIEN YANG DICARI TIDAK ADA DI DAFTAR RAWAT JALAN" << endl << endl;
		}
		
		cout << "+=======================================================+" << endl;
		cout << "|        HASIL PENCARIAN PADA PASIEN RAWAT INAP         |" << endl;
		cout << "+=======================================================+" << endl;
		cout << endl;
		
		if(jmlInap>0)
	    {
			for (i=0; i<jmlInap; i++) 
		    {
		        if(inap[i].namaPasien.find(cariNama) != string::npos)
		        {
		        	if(inap[i].alamat.find(cariAlamat) != string::npos)
		        	{
			        	ifound = true;
			        	
			            cout << "Pasien Rawat Inap No. " << i+1 << endl << endl;
						
						cout << "Nama pasien\t\t\t : " << inap[i].namaPasien << endl;
					
						cout << "Jenis kelamin pasien\t\t : " << inap[i].kelamin << endl;
							
						cout << "Alamat pasien\t\t\t : " << inap[i].alamat << endl;
							
						cout << "Diagnosa pasien\t\t\t : " << inap[i].diagnosa << endl;
							
						cout << "Nama dokter yang menangani\t : " << inap[i].namaDokter << endl;
							
						cout << "Harga obat\t\t\t : " << inap[i].hargaObat << " Rupiah." << endl;
							
						cout << "Kelas ruangan pasien\t\t : " << inap[i].ruangan << endl;
							
						cout << "Lama pasien menginap\t\t : " << inap[i].lamaInap << " hari." << endl;
							
						cout << "Memerlukan operasi\t\t : " << inap[i].operasi << endl;
							
						cout << "Total Pembayaran\t\t : " << inap[i].totalPembayaran << " Rupiah." << endl;
						
						ip++;
						
						cout << endl;
					}
		        }
		        
		    }
	    }
	    
	    if(ifound==false)
	    {
	    	cout << "PASIEN YANG DICARI TIDAK ADA DI DAFTAR RAWAT INAP" << endl << endl;
		}
		
		if(jfound==false && ifound==false)
		{
			cout << "Mohon maaf data pasien tidak ditemukan, ulangi pencarian!" << endl;
			ulang = 1;
			system("pause");
			system("cls");
		}
		
		if(jfound==true && ifound==true)
		{
			bool pilpasien=true;
			do
			{
				pilpasien=false;
				int pilrawat = 0;
				cout << "\nData pasien ditemukan di daftar rawat jalan dan rawat inap. Pilih salah satu : " << endl;
				cout << "1. Rawat Jalan" << endl;
				cout << "2. Rawat Inap" << endl;
				cout << "Masukkan pilihan : ";
				cin >> pilrawat;
				
				if(pilrawat == 1)
				{
					ifound = false;
				}
								
				else if(pilrawat==2)
				{
					jfound = false;
				}			
				
				else
				{
					cout << "Mohon masukkan pilihan dengan benar!" << endl;
					pilpasien = true;
				}
			}
			while(pilpasien==true);
		}
		
		if((jfound && jp>0) || (ifound && ip>0))
		{
			bool pilnomor=true;
			do
			{
				pilnomor=false;
				
				if(jfound && jp>0)
					{
						int jpil;
						cout << "\nMasukkan nomor pasien yang akan dibayarkan pada daftar rawat jalan : ";
						cin >> jpil;
						
						if(jpil > jmlJalan || jpil == 0)
						{
							cout << "\nTidak ada pasien dengan nomor tersebut. Ulangi input nomor pasien!" << endl;
							pilnomor=true;
						}
						else
						{
							j=jpil-1;
							cout << "\nAdministrasi pasien yang akan dibayarkan adalah pada pasien rawat jalan No." << jpil << "." << endl;
						}
					}
					
				else if(ifound && ip>0)
					{
						int ipil;
						cout << "\nMasukkan nomor pasien yang akan dibayarkan pada daftar rawat inap : ";
						cin >> ipil;
						
						if(ipil > jmlInap || ipil == 0)
						{
							cout << "\nTidak ada pasien dengan nomor tersebut. Ulangi input nomor pasien!" << endl;
							pilnomor=true;
						}
						else
						{
							i=ipil-1;
							cout << "\nAdministrasi pasien yang akan dibayarkan adalah pada pasien rawat inap No." << ipil << "." << endl;
						}
					}	
				
			}
			while(pilnomor==true);
		
			cout << "\nApakah data pasien yang ditampilkan dan dipilih sudah sesuai dengan yang dicari? (y/t) : ";
			cin >> sesuai;
			
			if(sesuai=='y' || sesuai=='Y')
			{
				do
				{
					nominal=0; //nilai awal variabel nominal=0
					if(jfound)
					{
						system("cls");
						cout << "Total Pembayaran\t : " << jalan[j].totalPembayaran << " Rupiah." << endl;
						
						 int bayar,uang;
						 char rek[99];
						 
						 cout << "\nPilih metode pembayaran" << endl << endl;
						 cout << "1. Tunai" << endl;
						 cout << "2. Transfer" << endl;
						 cout << "Masukkan Pilihan : ";
						 cin >> bayar;
						 
						 if (bayar==1)
						 {
						 	cout << "Total pembayaran = "<< jalan[j].totalPembayaran << " Rupiah." << endl;
							cout << "\nMasukkan nominal uang (dalam Rupiah) : ";
							cin >> uang;
							
							if (uang >= jalan[j].totalPembayaran)
							{
								cout << "\nPembayaran berhasil!" << endl;
								cout << "\nKembalian : " << uang - jalan[j].totalPembayaran << " Rupiah." << endl;
								jalan[j].totalPembayaran = 0;
							}
							else if (uang < jalan[j].totalPembayaran)
							{
								cout << "\nMaaf, nominal uang kurang!\n" << endl;
								nominal=1; //nilai nominal=1, maka terjadi pengulangan
							}	
						 }
						
						else if (bayar==2)
						{
							cout << "\nMasukkan Nomor Rekening : ";
							cin >> rek;
							cout << "\nPembayaran berhasil!" << endl;
							cout << "\nSaldo rekening dengan nomor " << rek << " telah dipotong sebesar " << jalan[j].totalPembayaran << " Rupiah." << endl;
							jalan[j].totalPembayaran = 0;
						}
						
						else
						{
							cout << "\nPilihan yang anda masukkan tidak ada! Ulangi input pilihan!" << endl;
							system("pause");
							nominal=1; //nilai nominal=1, maka terjadi pengulangan
						}
					}
					
					else if(ifound)
					{
						system("cls");
						cout << "Total Pembayaran\t : " << inap[i].totalPembayaran << endl;
						
						 int bayar,uang;
						 char rek[99];
						 
						 cout << "\nPilih metode pembayaran" << endl << endl;
						 cout << "1. Tunai" << endl;
						 cout << "2. Transfer" << endl;
						 cout << "Masukkan Pilihan : ";
						 cin >> bayar;
						 
						 if (bayar==1)
						{
							cout << "Total pembayaran = "<< inap[i].totalPembayaran << " Rupiah." << endl;
							cout << "\nMasukkan nominal uang (dalam Rupiah) : ";
							cin >> uang;
							
							if (uang >= inap[i].totalPembayaran)
							{
								cout << "\nPembayaran berhasil!" << endl;
								cout << "\nKembalian : " << uang - inap[i].totalPembayaran << " Rupiah." << endl;
								inap[i].totalPembayaran = 0;
							}
							else if (uang < inap[i].totalPembayaran)
							{
								cout << "\nMaaf, nominal uang kurang!\n" << endl;
								system("pause");
								nominal=1; //nilai nominal=1, maka terjadi pengulangan
							}
						}
						
						else if (bayar==2)
						{
							cout << "\nMasukkan Nomor Rekening : ";
							cin >> rek;
							cout << "\nPembayaran berhasil!" << endl;
							cout << "\nSaldo rekening dengan nomor " << rek << " telah dipotong sebesar " << inap[i].totalPembayaran << " Rupiah." << endl;
							inap[i].totalPembayaran = 0;
						}
						
						else
						{
							cout << "\nPilihan yang anda masukkan tidak ada! Ulangi input pilihan!" << endl;
							system("pause");
							nominal=1; //nilai nominal=1, maka terjadi pengulangan
						}
					}
					
					else
					{
						cout << "\nTidak ada data yang dipilih! Ulangi Pencarian! \n" << endl;
						system("pause");
						system("cls");
						ulang = 1;
					}
					
				}
				while(nominal==1);
			}
	
			else
			{
				system("cls");
				ulang = 1;
			}
		
		}
	
	}
	while(ulang==1);
}

string allUpCase(std::string& str)
{
	string converted;

	for (int i = 0; i < str.size(); i++)
		converted += toupper(str[i]);
	
	return converted;
}
