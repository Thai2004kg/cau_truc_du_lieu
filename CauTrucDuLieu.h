#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <conio.h>
#include <cstdio>
#include <sstream>
using namespace std;

#define HDlength 100
#define MaxNV 200
#define maxlength 80

void CapNhatDanhMucVatTu(int mavt, char* loai,int soluong);//prototype

void HienThiChuoi(char* st, int size){
	for(int i=0;i<strlen(st);i++)
		cout<< st[i];
	for(int i=0;i<size-strlen(st);i++)
		cout<<" "; //ghi khoang trong ra man hinh khi chuoi st, ngan hon do dai can in
}

//ChiTietHoaDon
class CTHD {
public:
    int MaVT;
    int SoLuong;
    double DonGia;
    double VAT;
    int SoHD;
    CTHD();

    CTHD(int maVT, int soLuong, double donGia, double vat, int sohd) ;

    void nhapChiTietHoaDon(int sohd);

    void hienThi();
    void update(int ma_vt, int sl, double d, double vat, int sohd) ;
               
};

class CTHDNode {
public:
    CTHD DuLieu;
    CTHDNode* next;

    CTHDNode(CTHD ct);
};

class DanhSachChiTietHoaDon{
	public:	
		CTHDNode* head;
		DanhSachChiTietHoaDon();
	
	void insertHead(CTHD d);
	void taoDanhSach(int sohd, char* loai);
	void hienThi();
	void Luu(char* filename);
	void Doc(char* filename);
	
};

class HoaDon {
public:
    int SoHD;
    char NgayLap[HDlength];
    char Loai[HDlength];
    DanhSachChiTietHoaDon dscthd;
    int MaNV; //ma so nhan vien tao hoa don
	HoaDon();
    HoaDon(int soHD, char* ngayLap, char* loai, int manv);
    void nhapHoaDon() ;
    void hienThi() ;

};

class HoaDonNode {
public:
	HoaDon data;
	HoaDonNode* next;
	
	HoaDonNode(HoaDon dt);
};

class DSHoaDon{
public:	
	HoaDonNode* head;
	DSHoaDon();
void insertHead(HoaDon d);
void taoDanhSach(int manv);
void hienThi();
void Luu(char* filename);
void Doc(char* filename);
};

class NhanVien{
	public:
		int MaNV;
		char Ho[MaxNV];
		char Ten[MaxNV];
		char Phai[5];
		DSHoaDon dshd;
	NhanVien();
	NhanVien(int maNV,char* ho, char* ten, char* phai);
	void NhapNhanVien();
	void HienThi();
	};
	
class DanhSachNhanVien{
public:
	int SoNV;
	NhanVien dsnv[MaxNV];
	DanhSachNhanVien();
	void them(NhanVien nv);//them cuoi ds
	void nhap();
	void hienThi();
	int searchMaNV(int maNV);
	int searchTen(char* ten);
	void searchTen();
	void swap(NhanVien &a,NhanVien &b);
	void SapXep();
	void Luu(char* filename);
	void Doc(char* filename);
	int Login(); // return MaNV sau dang nhap thanh cong
	void XoaNhanVien();
};
	

//=======================
//BEGIN CTHD: Chi tiet Hoa Don
//=======================
    CTHD::CTHD() {
        MaVT = 0;
        SoLuong = 0;
        DonGia = 0;
        VAT = 0;
        SoHD=0;
    }

   CTHD::CTHD(int maVT, int soLuong, double donGia, double vat, int sohd) {
        MaVT = maVT;
        SoLuong = soLuong;
        DonGia = donGia;
        VAT = vat;
        SoHD=sohd;
    }

    void  CTHD::nhapChiTietHoaDon(int sohd) {
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
		this->SoHD=sohd;
    }

    void  CTHD::hienThi() {
        cout << "ma vat tu: " << MaVT << " ";
        cout << "so luong: " << SoLuong << " ";
        cout << "don gia: " << DonGia << " ";
        cout << "thue VAT: " << VAT<< " ";
        cout << "So Hoa Don " << SoHD << endl;
    }
  	void  CTHD::update(int ma_vt, int sl, double d, double vat, int sohd) {
      
            MaVT = ma_vt;
            SoLuong = sl;
        	DonGia = d;
            VAT = vat;
            SoHD=sohd;
        }
    
//=======================
//BEGIN DanhSachChiTietHoaDon: Danh sach Chi tiet Hoa Don
//=======================       
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
	void DanhSachChiTietHoaDon::taoDanhSach(int sohd, char* loai){
		//CayTimKiem cayVatTu;
		char t;
		do{
				CTHD ct;
				ct.nhapChiTietHoaDon(sohd);
				insertHead(ct);
				CapNhatDanhMucVatTu(ct.MaVT,loai,ct.SoLuong);
		cout<<"tiep tuc nhap chi tiet hoa don?(y): ";
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
	//Luu chi tiet hoa don, gom co So Hoa Don
	void DanhSachChiTietHoaDon::Luu(char* filename) {
		 
    	std::ofstream outputFile(filename);

    // Check if the file is successfully opened
    if (!outputFile.is_open()) {
        std::cerr << "Loi mo file " << std::endl;
        return; 
    }
    
        CTHDNode* current = head;
        while (current != NULL) {
           outputFile<<current->DuLieu.MaVT<<","<<current->DuLieu.SoLuong<<","<<current->DuLieu.DonGia<<","<<current->DuLieu.VAT<<","<<current->DuLieu.SoHD<<endl;
            current = current->next;
        }

        outputFile.close();
        cout << "ghi thanh cong " << filename << endl;
    }
    void DanhSachChiTietHoaDon::Doc(char* filename) {
     ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Loi mo file" << std::endl;
        return ;
    }

    string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        string smaVT,ssoluong, sdongia,svat,ssoHD;
       
        getline(ss,smaVT,',');
        getline(ss,ssoluong,',');
        getline(ss,sdongia,',');
        getline(ss,svat,',');
        getline(ss,ssoHD,',');
        int soHD=stoi(ssoHD);
        int maVT=stoi(smaVT);//doi chuoi thanh int
        int soluong=stoi(ssoluong);
        double dongia=stod(sdongia);//doi chuoi thanh double
        double vat=stod(svat);
        CTHD ct(maVT,soluong,dongia,vat,soHD);
        insertHead(ct);
         
	
    }

    inFile.close();

	hienThi();
    
    cout << "Doc thanh cong " << filename << endl;
}

    
//=======================
//BEGIN HoaDon: Hoa Don
//=======================  

	HoaDon::HoaDon(){
		SoHD =0;
		strcpy(NgayLap,"");
		strcpy(Loai,"");
		MaNV=0;	
	}
    HoaDon::HoaDon(int soHD, char* ngayLap, char* loai, int manv) {
        SoHD = soHD;
        strcpy(NgayLap, ngayLap);
        strcpy(Loai, loai);
        MaNV=manv;
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
           // Loai=toupper(Loai);

            if (strcmp(Loai, "X") == 0 || strcmp(Loai, "N") == 0) {
                nhapLai = false;
            } else {
                cout << "Loai khong hop le. Vui long nhap lai (X/N)." << endl;
            }
        }
        
        cout<<"nhap chi tiet hoa don: \n";
        dscthd.taoDanhSach(SoHD, Loai);
    }
    void HoaDon::hienThi() {
        cout << "soHD: " << SoHD << " ";
        cout << "ngay lap: " << NgayLap << " ";
        cout << "loai: " << Loai << " ";
        cout <<"Ma nhan vien tao: " <<MaNV;
		cout<<"\n";
		cout<<"\t";
		dscthd.hienThi();
    }

//=======================
//BEGIN DSHoaDon: Danh sach Hoa Don
//=======================  
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
void DSHoaDon::taoDanhSach(int manv){
	
	char t;
	do{
		HoaDon hd;
		hd.nhapHoaDon();
		hd.MaNV=manv;
		insertHead(hd);
		
		cout<<"tiep tuc nhap hoa don ?(y): ";
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
        
	
    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cerr << "Loi mo file!" << filename<<endl;
        return; // Return an error code
    }
		
        HoaDonNode* current = head;
        while (current != NULL) {
            outputFile<<current->data.SoHD<<","<<current->data.NgayLap<<","<<current->data.Loai<<","<<current->data.MaNV<<endl;
            current = current->next;
        }

        outputFile.close();
        cout << "ghi thanh cong: " << filename << endl;
    }
    
void DSHoaDon::Doc(char* filename) {
   
   
   ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Loi mo file" << std::endl;
        return;
    }

    string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        string ssoHD,sNgay, sLoai,smaNV;

        getline(ss,ssoHD,',');
        getline(ss,sNgay,',');
        getline(ss,sLoai,',');
        getline(ss,smaNV,',');
        int soHD=stoi(ssoHD);//doi chuoi thanh int
		int maNV=stoi(smaNV);
        char* cngay = const_cast<char*>(sNgay.c_str());//doi kieu string sang mang char
        char* cloai = const_cast<char*>(sLoai.c_str());
        HoaDon hd(soHD,cngay,cloai,maNV);
        insertHead(hd);
    }

    inFile.close();

    hienThi();

    cout << "Doc thanh cong " << filename << endl;
}
		
//=======================
//BEGIN NhanVien: Nhan Vien
//=======================  

NhanVien::NhanVien(){
}
NhanVien::NhanVien(int maNV, char* ho, char*ten, char* phai){
	MaNV=maNV;
	strcpy(Ho,ho);
	strcpy(Ten,ten);
	strcpy(Phai,phai);
}
void NhanVien::NhapNhanVien() {
    int maNV;
    char ho[MaxNV], ten[MaxNV], phai[MaxNV];
    cout << "Nhap ma nhan vien: ";
    cin >> maNV;
    do {
        cout << "Ho: ";
        cin.ignore();
        cin.getline(ho, sizeof(ho));
        if (strlen(ho) == 0) {
            cout << "Ho khong duoc bo trong. Vui long nhap lai.\n";
        }
    } while (strlen(ho) == 0);
    do {
        cout << "Ten: ";
        cin.getline(ten, sizeof(ten));
        if (strlen(ten) == 0) {
            cout << "Ten khong duoc bo trong. Vui long nhap lai.\n";
        }
    } while (strlen(ten) == 0);
    cout << "Gioi tinh: ";
    cin.getline(phai, sizeof(phai));
    this->MaNV = maNV;
    strcpy(this->Ho, ho);
    strcpy(this->Ten, ten);
    strcpy(this->Phai, phai);
}

void NhanVien::HienThi(){
		cout << "ma nhan vien: " << MaNV << " ";
        cout << "Ho: " << Ho << " ";
        cout << "Ten: " << Ten << " ";
		cout<<"Gioi tinh: "<<Phai<<" \n";
	//	getch();
}

//=======================
//BEGIN DanhSachNhanVien: Danh sach Nhan Vien
//=======================
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
	SapXep();
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
	char ten[80];
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

void DanhSachNhanVien::SapXep() {
    for (int i = 0; i < SoNV - 1; i++) {
        for (int j = 0; j < SoNV - i - 1; j++) {
            int compareResult = strcmp(dsnv[j].Ten, dsnv[j + 1].Ten);

            if (compareResult > 0 || (compareResult == 0 && strcmp(dsnv[j].Ho, dsnv[j + 1].Ho) > 0)) {
                swap(dsnv[j], dsnv[j + 1]);
            }
        }
    }
}


void DanhSachNhanVien::Luu(char* filename){
	
 	ofstream file(filename,ios::out);
	if(file.fail()){
		cout<<"khong mo duoc file";
		file.clear();
	}
	else{
		for (int i=0;i<SoNV;i++){
			 file<<dsnv[i].MaNV<<","<<dsnv[i].Ho<<","<<dsnv[i].Ten<<","<<dsnv[i].Phai<<endl;
		}
		
		cout<<"ghi thanh cong vao tep "<<filename;
		file.close();
	}

}

void DanhSachNhanVien::them(NhanVien nv){//them cuoi ds
		dsnv[SoNV]=nv;
		SoNV++;
}
void DanhSachNhanVien::Doc(char* filename){

    ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Loi mo file" << std::endl;
    }

    string line;
    
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        string smanv,sho,sten,sphai;
        getline(ss,smanv,',');
        getline(ss,sho,',');
        getline(ss,sten,',');
        getline(ss,sphai,',');
        int maNV=stoi(smanv);//doi chuoi thanh int
        char* t = const_cast<char*>(sten.c_str());//doi kieu string sang mang char
        char* h = const_cast<char*>(sho.c_str());
        char* p = const_cast<char*>(sphai.c_str());
       	NhanVien nv(maNV,h,t,p);
       	them(nv);
    }
    inFile.close();
}


//input: Danh sach nhan vien
//		MaSo Nhan vien
//		PASSWORD (dinh nghia trong mylib.h; #define PASSWORD "abc")
//output: Ma so nhan vien co trong danh sach

int DanhSachNhanVien::Login(){
		system("cls"); //xoa man hinh
int maNV,i,check;
do{	cout<<"Tai khoan: ";
	cin>>maNV;
	i=searchMaNV(maNV);
	if (i==-1){
		cout<<"sai tai khoan\n";
		}
}
while(i==-1);
//goi ham hien thi menu o day
//	dsnv[i].HienThi();
//	getch();
return maNV;
	}

	
void DanhSachNhanVien::XoaNhanVien() {
 
  int maso;
  cout << "nhap ma nhan vien can xoa: ";
  cin >> maso;
  cin.ignore();
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
//=======================
//BEGIN: VatTu
//=======================

class VatTu {
	
public:
    int MaVatTu;
    char TenVatTu[maxlength];
    char DonViTinh[maxlength];
    double SoLuongTon;

    VatTu() {
        MaVatTu = 0;
        strcpy(TenVatTu, "");
        strcpy(DonViTinh, "");
        SoLuongTon = 0;
    }

    VatTu(int m, char* t, char* d, double s) {
        MaVatTu = m;
        strcpy(TenVatTu, t);
        strcpy(DonViTinh, d);
        SoLuongTon = s;
    }

    void hienThi() {
    	cout<<endl;
        cout << "  " << MaVatTu << "\t";
    //    cout << "  " << TenVatTu  << "";
    	HienThiChuoi(TenVatTu,20);
    	cout<<"\t";
    //cout << " " << DonViTinh << "";
    	HienThiChuoi(DonViTinh,15);
    	cout<<"\t";
        cout << " " << SoLuongTon;
    }

    int nhapVatTu() {
        int m;
        char t[maxlength], d[maxlength];
        double s;
        cout << "nhap ma vat tu: (=0:thoat)";
        cin >> m;
        if (m == 0) {
            return 0;
        }

        cin.ignore();
        cout << "nhap ten vat tu: ";
        cin.getline(t, sizeof(t));

        cout << "nhap don vi tinh: ";
        cin.getline(d, sizeof(d));

        cout << "nhap so luong ton: ";
        cin >> s;

        this->MaVatTu = m;
        strcpy(this->TenVatTu, t);
        strcpy(this->DonViTinh, d);
        this->SoLuongTon = s;

        return 1;
    }
};

//=======================
//BEGIN: Node: Danh de tao 1 nut cua CayTimKiem
//=======================

class Node {
public:
    VatTu DuLieu;
    Node* Left;
    Node* Right;

    Node(int m, char* t, char* d, double s) {
        DuLieu.MaVatTu = m;
        strcpy(DuLieu.TenVatTu, t);
        strcpy(DuLieu.DonViTinh, d);
        DuLieu.SoLuongTon = s;
        Left = NULL;
        Right = NULL;
    }

    Node(VatTu v) {
        DuLieu = v;
        Left = NULL;
        Right = NULL;
    }
   
      void ghiDuLieu(ofstream& file) {
        file << DuLieu.MaVatTu << "," << DuLieu.TenVatTu << "," << DuLieu.DonViTinh << "," << DuLieu.SoLuongTon << endl;
    }
};

//===================
//BEGIN: CayTimKiem - danh cho quan ly VatTu
//===================
class CayTimKiem {
public:
    Node* root;

    CayTimKiem() {
        root = NULL;
    }
   

    Node* insertNode(Node* p, int m, char* t, char* d, double s) {
        if (p == NULL) {
            return new Node(m, t, d, s);
        }
        if (m < p->DuLieu.MaVatTu)
            p->Left = insertNode(p->Left, m, t, d, s);
        else if (m > p->DuLieu.MaVatTu)
            p->Right = insertNode(p->Right, m, t, d, s);
        return p;
    }

    Node* insertNode(Node* p, VatTu v) {
        if (p == NULL) {
            return new Node(v);
        }
        if (v.MaVatTu < p->DuLieu.MaVatTu)
            p->Left = insertNode(p->Left, v);
        else if (v.MaVatTu > p->DuLieu.MaVatTu)
            p->Right = insertNode(p->Right, v);
        else
            return NULL;
        return p;
    }

    void insertNode(VatTu v) {
        Node* p = insertNode(root, v);
        if (p == NULL)
            cout << "ma vat tu bi trung" << endl;
        else
            root = p;
    }

    Node* searchNode(Node* p, int ma_vt) {
        if (p == NULL)
            return NULL;
        if (ma_vt == p->DuLieu.MaVatTu)
            return p;
        else if (ma_vt < p->DuLieu.MaVatTu)
            return searchNode(p->Left, ma_vt);
        else if (ma_vt > p->DuLieu.MaVatTu)
            return searchNode(p->Right, ma_vt);
    }

    void searchNode(int ma_vt) {
        Node* p = searchNode(root, ma_vt);
        if (p == NULL)
            cout << "khong tim gap" << endl;
        else
            p->DuLieu.hienThi();
    }

    void inputUpdateVatTu() {
        int mvt;
        cout << "nhap ma vat tu can sua: ";
        cin >> mvt;
        cin.ignore();
        cout << "nhap ten can sua: ";
        char t[maxlength];
        cin.getline(t, sizeof(t));
        cout << "don vi tinh: ";
        char d[maxlength];
        cin.getline(d, sizeof(d));
        cout << "nhap so luong: ";
        double s;
        cin >> s;
        updateNode(mvt, t, d, s);
    }

    void updateNode(int ma_vt, char* t, char* d, double sl) {
        Node* p = searchNode(root, ma_vt);
        if (p != NULL) {
            strcpy(p->DuLieu.TenVatTu, t);
            strcpy(p->DuLieu.DonViTinh, d);
            p->DuLieu.SoLuongTon = sl;
        } else
            cout << "ma vat tu khong ton tai" << endl;
    }
    
     void updateNodeSoluong(int ma_vt, double sl, char* loai) {
        Node* p = searchNode(root, ma_vt);
        if (p != NULL) {
        	if(strcmp(loai,"X")==0)
            	p->DuLieu.SoLuongTon -= sl;
            else
            	p->DuLieu.SoLuongTon += sl;
        } else
            cout << "ma vat tu khong ton tai" << endl;
    }

 bool deleteNode(int ma_vt) {
        Node* p = deleteNode(root, ma_vt);
        if (p == NULL) {
            cout << "Khong tim thay ma vat tu " << ma_vt << endl;
            return false;
        }
        cout << "Vat tu co ma " << ma_vt << " da duoc xoa." << endl;
        return true;
    }

Node* deleteNode(Node* p, int ma_vt) {
        if (p == NULL) {
            return p;
        }

        if (ma_vt < p->DuLieu.MaVatTu) {
            p->Left = deleteNode(p->Left, ma_vt);
        } else if (ma_vt > p->DuLieu.MaVatTu) {
            p->Right = deleteNode(p->Right, ma_vt);
        } else { //p.DuLieju.MaVatTu==ma_vt
            if (p->Left == NULL) {
                Node* temp = p->Right;
                delete p;
                return temp;
            } else if (p->Right == NULL) {
                Node* temp = p->Left;
                delete p;
                return temp;
            }

            Node* temp = minValueNode(p->Right);//Tim nut nho nhat (trai) cua cay con phai
            //p->DuLieu = temp->DuLieu;//thay the cho nut can xoa
            p->DuLieu.MaVatTu=temp->DuLieu.MaVatTu;
            
			strcpy(p->DuLieu.TenVatTu,temp->DuLieu.TenVatTu);
            
            strcpy(p->DuLieu.DonViTinh,temp->DuLieu.DonViTinh);
            p->DuLieu.SoLuongTon=temp->DuLieu.SoLuongTon;
            p->Right = deleteNode(p->Right, temp->DuLieu.MaVatTu);//xoa nut nho nhat tren cay con phai
        }

        return p;
    }
    

  Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->Left != NULL) {
            current = current->Left;
        }
        return current;
    }
    

    int createTree() {
        while (1) {
            VatTu v;
            if (v.nhapVatTu() == 0) {
                return 0;
            } else {
                insertNode(v);
            }
        }
    }

    int createTree(char* filename) {
        ifstream file_obj;
        file_obj.open(filename, ios::in);

        if (!file_obj) {
            cerr << "Error opening file for reading: " << filename << endl;
            return 0;
        }

        VatTu obj;

        while (file_obj >> obj.MaVatTu >> obj.TenVatTu >> obj.DonViTinh >> obj.SoLuongTon) {
            insertNode(obj);
        }

        file_obj.close();

        return 1;
    }

    void LNR(Node* p) {
        if (p != NULL) {
            LNR(p->Left);
            p->DuLieu.hienThi();
            LNR(p->Right);
        }
    }

    void LNR() {
        LNR(root);
        cout << endl;
    }

    void ghiFileLNR(Node* p, std::ofstream& file) {
        if (p != NULL) {
            ghiFileLNR(p->Left, file);
           // p->ghiDuLieu(file);
            file<<p->DuLieu.MaVatTu<<","<<p->DuLieu.TenVatTu<<","<<p->DuLieu.DonViTinh<<","<<p->DuLieu.SoLuongTon<<endl;
            ghiFileLNR(p->Right, file);
        }
    }

    void ghiFileLNR(std::ofstream& file) {
        ghiFileLNR(root, file);
    }
    
    void ghiFileLNR(char* filename) {
    	ofstream file(filename,ios::out);
        ghiFileLNR(root, file);
        file.close();
    }
    Node* insertNodeTen(Node* p, VatTu v) {
    	if (p == NULL) {
        	return new Node(v);
    	}

    	int compareResult = strcmp(v.TenVatTu, p->DuLieu.TenVatTu);

    	if (compareResult < 0) {
       		p->Left = insertNodeTen(p->Left, v);
    } else if (compareResult > 0) {
        	p->Right = insertNodeTen(p->Right, v);
    } else {
        	return NULL;  
    }

    return p;
}

void insertNodeTen(VatTu v) {
    Node* p = insertNodeTen(root, v);
    if (p == NULL)
        cout << "ten vat tu bi trung" << endl;
    else
        root = p;
}

}; // End of CayTimKiem class


void readVatTuFromFile(char* filename) {
    ifstream inputFile(filename, ios::binary);

    if (!inputFile) {
        std::cerr << "Error opening the file for reading." << std::endl;
        return;
    }

    VatTu v;
    cout << "Thong tin vat tu: " << endl;
    while (inputFile >> v.MaVatTu >> v.TenVatTu >> v.DonViTinh >> v.SoLuongTon) {
        cout << "Ma vat tu: " << v.MaVatTu << "-Ten vat tu: " << v.TenVatTu << " -Don vi tinh: " << v.DonViTinh << " -So luong ton: " << v.SoLuongTon;
        cout << endl;
    }
    inputFile.close();
}

int docFileVatTu(char* filename) {
    ifstream file_obj(filename);

    if (!file_obj) {
        cerr << "Error opening file for reading: " << filename << endl;
        return 1;
    }

    VatTu obj;

    while (file_obj >> obj.MaVatTu >> obj.TenVatTu >> obj.DonViTinh >> obj.SoLuongTon) {
        cout << "Ma VT: " << obj.MaVatTu << "; Ten VT: " << obj.TenVatTu << "; Don vi tinh: " << obj.DonViTinh << "; So luong ton: " << obj.SoLuongTon << endl;
    }

    file_obj.close();

    return 0;
}

CayTimKiem readFromFileByTen(const std::string& filename) {
    CayTimKiem cayVatTu;
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Loi mo file" << std::endl;
        return cayVatTu;
    }

    string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        string smavt,ten, dvt,ssoluong;

        getline(ss,smavt,',');
        getline(ss,ten,',');
        getline(ss,dvt,',');
        getline(ss,ssoluong,',');
        int mavt=stoi(smavt);//doi chuoi thanh int
        double soluong=stod(ssoluong);//doi chuoi thanh double

        char* t = const_cast<char*>(ten.c_str());//doi kieu string sang mang char
        char* d = const_cast<char*>(dvt.c_str());
        VatTu v(mavt,t,d,soluong);
        cayVatTu.insertNodeTen(v);
    }

    inFile.close();

    return cayVatTu;
}
    
CayTimKiem readFromFileByMa(const std::string& filename) {
    CayTimKiem cayVatTu;
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Loi mo file" << std::endl;
        return cayVatTu;
    }

    string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        string smavt,ten, dvt,ssoluong;

        getline(ss,smavt,',');
        getline(ss,ten,',');
        getline(ss,dvt,',');
        getline(ss,ssoluong,',');
        int mavt=stoi(smavt);//doi chuoi thanh int
        double soluong=stod(ssoluong);//doi chuoi thanh double

        char* t = const_cast<char*>(ten.c_str());//doi kieu string sang mang char
        char* d = const_cast<char*>(dvt.c_str());
        VatTu v(mavt,t,d,soluong);
        cayVatTu.insertNode(v);
    }

    inFile.close();

    return cayVatTu;
}
 
    void CapNhatDanhMucVatTu(int mavt, char* loai, int soluong){
    	//Doc tep nap len cay
    	 CayTimKiem cayVatTu=readFromFileByMa("vatTu.txt");
    	
    	//Tim mavt trong cay; sua so luong
    	cayVatTu.updateNodeSoluong(mavt,soluong,loai);
    	//Ghi cay lai tep
    	
    	cayVatTu.ghiFileLNR("vatTu.txt");
    	
	}

