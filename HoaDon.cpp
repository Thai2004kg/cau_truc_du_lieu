#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <conio.h>
#include <cstdio>
#include"HoaDon.h"
using namespace std;

    CTHD::CTHD() {
        MaVT = 0;
        SoLuong = 0;
        DonGia = 0;
        VAT = 0;
    }

   CTHD::CTHD(int maVT, int soLuong, double donGia, double vat) {
        MaVT = maVT;
        SoLuong = soLuong;
        DonGia = donGia;
        VAT = vat;
    }

    void  CTHD::nhapChiTietHoaDon() {
    	int maVT;
    	int soLuong;
    	double donGia;
    	double vat;
        cout << "Nhap ma vat tu: ";
        cin >> maVT;
        cout << "Nhap so luong: ";
        cin >> soLuong;
        cout << "Nhap don gia:  ";
        cin >> donGia;
        cout << "Nhap %VAT: ";
        cin >> vat;
        this->MaVT=maVT;
		this->SoLuong=soLuong;
		this->DonGia=donGia;
		this->VAT=vat;
    }

    void  CTHD::hienThi() {
        cout << "ma vat tu: " << MaVT << " ";
        cout << "so luong: " << SoLuong << " ";
        cout << "don gia: " << DonGia << " ";
        cout << "thue VAT: " << VAT << " \n";
    }
     void  CTHD::update(int ma_vt, int sl, double d, double vat) {
      
            MaVT = ma_vt;
            SoLuong = sl;
        	DonGia = d;
            VAT = vat;
        }
               
    CTHDNode::CTHDNode(CTHD ct) {
        DuLieu = ct;
        next = NULL;
    }


	DanhSachChiTietHoaDon::DanhSachChiTietHoaDon(){
		head=NULL;
	}
	void DanhSachChiTietHoaDon::insertHead(CTHD d){
		CTHDNode* p=new CTHDNode(d);
		p->next=head;
		head=p;
	}
	void DanhSachChiTietHoaDon::taoDanhSach(){
	
		char t;
		do{
				CTHD ct;
				ct.nhapChiTietHoaDon();
				insertHead(ct);
		
		cout<<"tiep tuc?(y): ";
		cin>>t;
	}
		while(t=='y');
		
	}
	
	void DanhSachChiTietHoaDon::hienThi(){
		CTHDNode* current=head;
		while(current!=NULL){
			current->DuLieu.hienThi();
			current=current->next;
		}
	}
	void DanhSachChiTietHoaDon::Luu(char* filename) {
        ofstream file_out(filename, ios::binary);
        if (!file_out) {
            cerr << "khong the mo tep: " << filename << endl;
            return;
        }

        CTHDNode* current = head;
        while (current != NULL) {
            file_out.write(reinterpret_cast<const char*>(&current->DuLieu), sizeof(CTHD));
            current = current->next;
        }

        file_out.close();
        cout << "ghi thanh cong " << filename << endl;
    }
    void DanhSachChiTietHoaDon::Doc(char* filename) {
    ifstream file_in(filename, ios::binary);
    if (!file_in) {
        cerr << "Khong the mo tep: " << filename << endl;
        return;
    }

    CTHD ct;
    while (file_in.read(reinterpret_cast<char*>(&ct), sizeof(CTHD))) {
       insertHead(ct);
	 }	    
	hienThi();
    

    file_in.close();
    cout << "Doc thanh cong " << filename << endl;
}

	
//HoaDon
	HoaDon::HoaDon(){
		SoHD =0;
		strcpy(NgayLap,"");
		strcpy(Loai,"");	
	}
    HoaDon::HoaDon(int soHD, char* ngayLap, char* loai) {
        SoHD = soHD;
        strcpy(NgayLap, ngayLap);
        strcpy(Loai, loai);
    }

    void HoaDon::nhapHoaDon() {
        cout << "Nhap SoHD: ";
        cin >> SoHD;
        cout << "Nhap NgayLap: ";
        cin >> NgayLap;
        bool nhapLai = true;
        while (nhapLai) {
            cout << "Nhap Loai (X/N): ";
            cin >> Loai;

            if (strcmp(Loai, "X") == 0 || strcmp(Loai, "N") == 0) {
                nhapLai = false;
            } else {
                cout << "Loai khong hop le. Vui long nhap lai (X/N)." << endl;
            }
        }
        cout<<"nhap chi tiet hoa don: \n";
        dscthd.taoDanhSach();
    }
    void HoaDon::hienThi() {
        cout << "soHD: " << SoHD << " ";
        cout << "ngay lap: " << NgayLap << " ";
        cout << "loai: " << Loai << " ";
		cout<<"\n";
		cout<<"\t";
		dscthd.hienThi();
    }


//	HoaDonNode
	HoaDonNode::HoaDonNode(HoaDon dt){
		data = dt;
		next = NULL;
	}	

DSHoaDon::DSHoaDon(){
	head=NULL;
	}

void DSHoaDon::insertHead(HoaDon d){
		HoaDonNode* p=new HoaDonNode(d);
		p->next=head;
		head=p;
	}
void DSHoaDon::taoDanhSach(){
	
	char t;
	do{
		HoaDon hd;
		hd.nhapHoaDon();
		insertHead(hd);
		
		cout<<"tiep tuc?(y): ";
		cin>>t;
	}
		while(t=='y');
		
	}
	void DSHoaDon::hienThi(){
		HoaDonNode* current=head;
		while(current!=NULL){
			current->data.hienThi();
			current=current->next;
		}
		}
	void DSHoaDon::Luu(char* filename) {
        ofstream file_out(filename, ios::binary);
        if (!file_out) {
            cerr << "khong the mo tep: " << filename << endl;
            return;
        }

        HoaDonNode* current = head;
        while (current != NULL) {
            file_out.write(reinterpret_cast<const char*>(&current->data), sizeof(HoaDon));
            current = current->next;
        }

        file_out.close();
        cout << "ghi thanh cong: " << filename << endl;
    }
    
void DSHoaDon::Doc(char* filename) {
    ifstream file_in(filename, ios::binary);
    if (!file_in) {
        cerr << "Khong the mo tep: " << filename << endl;
        return;
    }

    HoaDon hd;
    while (file_in.read(reinterpret_cast<char*>(&hd), sizeof(HoaDon))) {
        insertHead(hd);
    }
    hienThi();

    file_in.close();
    cout << "Doc thanh cong " << filename << endl;
}
		
// NhanVien
NhanVien::NhanVien(){
}
NhanVien::NhanVien(int maNV, char* ho, char*ten, char* phai){
	MaNV=maNV;
	strcpy(Ho,ho);
	strcpy(Ten,ten);
	strcpy(Phai,phai);
}
void NhanVien::NhapNhanVien(){
		int maNV;
		char ho[MaxNV],ten[MaxNV],phai[MaxNV];
		cout<<"nhap ma nhan  vien:";
		cin>>maNV;
		cin.ignore();
		cout<<"Ho: ";
		cin.getline(ho,sizeof(ho));

		cout<<"Ten: ";
		cin.getline(ten,sizeof(ten));
	
		cout<<"Gioi tinh: ";
		cin.getline(phai,sizeof(phai)) ;
		
		this->MaNV=maNV;
		strcpy(this->Ho,ho);
		strcpy(this->Ten,ten);
		strcpy(this->Phai,phai);
	}
void NhanVien::HienThi(){
		cout << "ma nhan vien: " << MaNV << " ";
        cout << "Ho: " << Ho << " ";
        cout << "Ten: " << Ten << " ";
		cout<<"Gioi tinh: "<<Phai<<" \n";
	//	getch();
}

//DanhSachNhanVien
DanhSachNhanVien::DanhSachNhanVien(){
	SoNV=0;
}
void DanhSachNhanVien::nhap() {
    char tiepTuc;
    
    do {
        NhanVien nv;
        nv.NhapNhanVien();
        while(searchMaNV(nv.MaNV)!=-1){
        	cout<<"Trung ma nhan vien, hay nhap lai \n";
        	nv.NhapNhanVien();
		}
        dsnv[SoNV++] = nv;

        cout << "nhap tiep? (y/n): ";
        cin >> tiepTuc;
        cin.ignore();
    } while (tiepTuc == 'y' || tiepTuc == 'Y');
}

void DanhSachNhanVien::hienThi(){
	for(int i=0;i<SoNV;i++)
		dsnv[i].HienThi();
		
getch();
}

int DanhSachNhanVien::searchMaNV(int maNV){
	for(int i=0; i<SoNV; i++)
		if(dsnv[i].MaNV==maNV)
			return i;
		
return -1;	
}
int DanhSachNhanVien::searchTen(char* ten){
	for(int i=0;i<SoNV;i++)
		if(strcmp(dsnv[i].Ten, ten) ==0)
			return i;
	return -1;		
}

void DanhSachNhanVien::searchTen(){
	char* ten;
	printf ("\n Ban ten nhan vien : ") ;
	        cin >> ten ;
	       int i;
	       for(i=0;i<SoNV;i++)
			if(strcmp(dsnv[i].Ten, ten) ==0)
			  		break;
			  		
			if(i==SoNV) //neu i==SoNV thi khong gap; vong for chay het ma khong break
				cout<<"Khong tim thay nhan vien ten "<<ten;
			else{// neu break i<SoNV, tuc la tim gap
				cout<<"Tim thay: "<<endl;
				dsnv[i].HienThi();
			}
			
			getch();
				
}

void DanhSachNhanVien::swap(NhanVien &a, NhanVien &b){
	NhanVien temp= a;
	a=b;
	b=temp;
}

void DanhSachNhanVien::SapXep(){
	for(int i=0;i<SoNV-1;i++){
		for(int j=0;j<SoNV-i-1;j++){
			if(dsnv[j].MaNV>dsnv[j+1].MaNV){
				swap(dsnv[j],dsnv[j+1]);
			}
		}
	}
	
}

void DanhSachNhanVien::Luu(char* filename){
	ofstream outstream;
	outstream.open(filename,ios::binary);
	if(outstream.fail()){
		cout<<"khong mo duoc file";
		outstream.clear();
	}
	else{
		for (int i=0;i<SoNV;i++)
			outstream.write(reinterpret_cast<const char*>(&dsnv[i]),sizeof(NhanVien));
		
		cout<<"ghi thanh cong vao tep "<<filename;
		outstream.close();
	}
}

void DanhSachNhanVien::them(NhanVien nv){//them cuoi ds
		dsnv[SoNV]=nv;
		SoNV++;
}
void DanhSachNhanVien::Doc(char* filename){

	// Create an input file stream
    ifstream file_obj;

    // Open the file in input binary mode
    file_obj.open(filename, ios::in | ios::binary);

    // Check if the file was successfully opened
    if (!file_obj) {
        cerr << "Loi mo file: " << filename << endl;
        return; // Return an error code to indicate failure
    }

    // Object of class VatTu to store data read from the file
    NhanVien obj;

    // Read data from the file into the object "obj"
    while (file_obj.read((char*)&obj, sizeof(NhanVien))) {
       them(obj);
    }

    // Close the file. It's good practice to close it after opening.
    file_obj.close();
}

int DanhSachNhanVien::Login(){
int maNV,i;
do{	cout<<"Dang nhap: ";
	cin>>maNV;
	i=searchMaNV(maNV);
	if (i==-1)
	cout<<"sai thong tin dang nhap\n";
}
while(i==-1);
//goi ham hien thi menu o day
	dsnv[i].HienThi();
	getch();
return maNV;

	}

	
void DanhSachNhanVien::XoaNhanVien() {
	int maso;
  cout << "nhap ma nhan vien can xoa: ";
  cin >> maso;
  int vitri = searchMaNV(maso);
  if (vitri != -1) {
    cout << "da xoa nhan vien: ";
    dsnv[vitri].HienThi();
    for (int j = vitri + 1; j < SoNV; j++) {
      dsnv[j - 1] = dsnv[j];
    }
    SoNV--;
    
    getch();
  } else {
    cout << "khong tim thay nhan vien co ma so " << maso << endl;
    getch();
  }
}






