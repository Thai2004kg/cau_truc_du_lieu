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
    
    CTHD() {
        MaVT = 0;
        SoLuong = 0;
        DonGia = 0;
        VAT = 0;
    }

    CTHD(int maVT, int soLuong, double donGia, double vat) {
        MaVT = maVT;
        SoLuong = soLuong;
        DonGia = donGia;
        VAT = vat;
    }

    void nhapChiTietHoaDon() {
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

    void hienThi() {
        cout << "ma vat tu: " << MaVT << " ";
        cout << "so luong: " << SoLuong << " ";
        cout << "don gia: " << DonGia << " ";
        cout << "thue VAT: " << VAT << " \n";
    }
     void update(int ma_vt, int sl, double d, double vat) {
      
            MaVT = ma_vt;
            SoLuong = sl;
        	DonGia = d;
            VAT = vat;
        }
               
};

class CTHDNode {
public:
    CTHD DuLieu;
    CTHDNode* next;

    CTHDNode(CTHD ct) {
        DuLieu = ct;
        next = NULL;
    }
};

class DanhSachChiTietHoaDon{
	public:	
		CTHDNode* head;
		DanhSachChiTietHoaDon(){
			head=NULL;
	}
	void insertHead(CTHD d){
		CTHDNode* p=new CTHDNode(d);
		p->next=head;
		head=p;
	}
	void taoDanhSach(){
	
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
	void hienThi(){
		CTHDNode* current=head;
		while(current!=NULL){
			current->DuLieu.hienThi();
			current=current->next;
		}
	}
	
	/*    bool searchCTHD(CTHDNode* dscthd, int maVT) {
        CTHDNode* current = dscthd;
        while (current != NULL) {
            if (current->DuLieu.MaVT == maVT) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void TimKiem() {
        int maVT;
        cout << "Nhap ma vat tu can tim: ";
        cin >> maVT;
        if (searchCTHD(dscthd, maVT)) {
            cout << "Tim thay chi tiet hoa don thong qua ma vat tu" << endl;
        } else {
            cout << "Khong tim thay chi tiet hoa don" << endl;
        }
    }

    void inputUpdateCTHD() {
        int m_vt;
        cout << "Nhap ma vat tu can sua: ";
        cin >> m_vt;
        cout << "Nhap so luong can sua: ";
        int sl;
        cin >> sl;
        cout << "Nhap don gia can sua: ";
        double d;
        cin >> d;
        cout << "Nhap thue VAT moi: ";
        double vat;
        cin >> vat;
        updateNode(m_vt, sl, d, vat);
    }

   
    }*/
	
};



class HoaDon {
public:
    int SoHD;
    char NgayLap[HDlength];
    char Loai[HDlength];
    DanhSachChiTietHoaDon dscthd;
	HoaDon(){
		SoHD =0;
		strcpy(NgayLap,"");
		strcpy(Loai,"");	
	}
    HoaDon(int soHD, char* ngayLap, char* loai) {
        SoHD = soHD;
        strcpy(NgayLap, ngayLap);
        strcpy(Loai, loai);
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

            if (strcmp(Loai, "X") == 0 || strcmp(Loai, "N") == 0) {
                nhapLai = false;
            } else {
                cout << "Loai khong hop le. Vui long nhap lai (X/N)." << endl;
            }
        }
        cout<<"nhap chi tiet hoa don: \n";
        dscthd.taoDanhSach();
    }
    void hienThi() {
        cout << "soHD: " << SoHD << " ";
        cout << "ngay lap: " << NgayLap << " ";
        cout << "loai: " << Loai << " ";
		cout<<"\n";
		cout<<"\t";
		dscthd.hienThi();
    }


};


class HoaDonNode {
public:
	HoaDon data;
	HoaDonNode* next;
	
	HoaDonNode(HoaDon dt){
		data = dt;
		next = NULL;
	}	
};

class DSHoaDon{
public:	
	HoaDonNode* head;
	DSHoaDon(){
	head=NULL;
	}
void insertHead(HoaDon d){
		HoaDonNode* p=new HoaDonNode(d);
		p->next=head;
		head=p;
	}
void taoDanhSach(){
	
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
	void hienThi(){
		HoaDonNode* current=head;
		while(current!=NULL){
			current->data.hienThi();
			current=current->next;
		}
		}

	
};
int main() {
   // CTHD ct;
   // ct.nhapChiTietHoaDon();
  //  ct.hienThi();
  
  /*DanhSachChiTietHoaDon ct;
  ct.taoDanhSach();
  ct.hienThi();
  */
  DSHoaDon ds;
  ds.taoDanhSach();
  ds.hienThi();
  //  HOADON* hoadon1 = new HOADON(0, "", "");
 //   hoadon1->nhapHoaDon();
 //   ct.TimKiem(s);
    
    

    return 0;
}

