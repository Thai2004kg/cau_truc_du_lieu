#include <iostream>
#include <string>
#include <cstring>
#define HDlength 100
using namespace std;
class CTHD {
public:
    int MaVT;
    int SoLuong;
    double DonGia;
    double VAT;
    //CTHD* next;
    
    CTHD(){
    MaVT=0;
	SoLuong=0;
	DonGia=0;
	VAT=0;	
    }

    CTHD(int maVT, int soLuong, double donGia, double vat) {
        MaVT = maVT;
        SoLuong = soLuong;
        DonGia = donGia;
        VAT = vat;
    }
    
    int nhapChiTietHoaDon(){
		int maVT;
		double soLuong;
		double donGia;
		double vat;
		cout<<"nhap ma vat tu: ";
		cin>>maVT;
		cout<<"nhap so luong: ";
		cin>>soLuong;
		cout<<"nhap don gia:  ";
		cin>>donGia;
		cout<<"nhap %VAT: ";
		cin>>vat;
		this->MaVT=maVT;
		this->SoLuong=soLuong;
		this->DonGia=donGia;
		this->VAT=vat;
	}
	void hienThi(){
	cout<<"ma vat tu: "<<MaVT<<" ";
	cout<<"so luong: "<<SoLuong<<" ";
	cout<<"don gia: "<<DonGia<<" ";
	cout<<"thue VAT: "<<VAT<<" ";	
	}
};

class CTHDNode{
	public:
		CTHD DuLieu;
		CTHDNode* next;
		CTHDNode(CTHD ct){
			DuLieu=ct;
			next=NULL;
		}
		
};

class HOADON {
public:
    int SoHD;
   	char NgayLap[HDlength];
    char Loai[HDlength];
    CTHDNode* dscthd;
    HOADON(int soHD, char* ngayLap, char* loai) {
        SoHD = soHD;
       	strcpy(NgayLap, ngayLap);
        strcpy(Loai, loai);
        dscthd = NULL;
    }
   void nhapHoaDon() {
    cout << "Nhap SoHD: ";
    cin >> SoHD;
    cout << "Nhap NgayLap: ";
    cin >> NgayLap;
    bool nhapLai = true;
    while (nhapLai) {
        cout << "Nhap Loai (X/N): ";
        cin >> Loai;

        if (Loai == "X" || Loai == "N") {
            nhapLai = false;  
        } else {
            cout << "Loai khong hop le. Vui long nhap lai (X/N)." << endl;
        }
    }
}
 CTHDNode* insertNode(CTHD ct) {
        CTHDNode* newNode = new CTHDNode(ct);
        if (dscthd == NULL) {
            dscthd = newNode;
        } else {
            CTHDNode* current = dscthd;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
}
bool searchCTHD(CTHDNode* dscthd, int maVT) {
    CTHDNode* current = dscthd;  

    while (current != NULL) {
        if (current->DuLieu == dscthd->DuLieu.MaVT) {
            return true;
        }
        current = current->next;  
    }

    return false;
}

void TimKiem(){
	if (searchCTHD ==true){
		cout<<"tim thay chi tiet hoa don thong qua ma vat tu";	
		dscthd->DuLieu.hienThi();
	}
	else {
		cout<<"khong tim thay chi tiet hoa don";	
	}
}
	
void inputUpdateCTHD(){
int m_vt;
	cout<<"nhap ma vat tu can sua: ";
	cin>>m_vt;
	cout<<"nhap so luong can sua: ";
	int sl;
	cin>>sl;
	cout<<"nhap don gia can sua: ";
	double d;
	cin>>d;
	cout<<"nhap thue VAT moi: ";
	double vat;
	cin>>vat;
	updateCTHD(m_vt,sl,d,vat);
}
void updateNode(int ma_vt, int sl, double d, double vat){
	CTHDNode* dscthd=searchCTHD(dscthd,ma_vt);
	if(dscthd!=NULL){	
		dscthd->DuLieu.SoLuong=sl;
		dscthd->DuLieu.DonGia=d;
		dscthd->DuLieu.VAT=vat;	
	}
		else
		cout<<"ma vat tu khong ton tai"<<endl;
	
}


};
    
    

  


int main() {
 
 	CTHD ct;
	ct.nhapChiTietHoaDon();
	ct.hienThi();
	//HOADON* danhSachHoaDon = NULL;
    
    HOADON* hoadon1 = new HOADON(0, "", ""); 
    hoadon1->nhapHoaDon();
  //  hoadon1->next = danhSachHoaDon;
  //  danhSachHoaDon = hoadon1;
    
    return 0;
}

