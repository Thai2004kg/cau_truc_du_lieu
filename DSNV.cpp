#include <iostream>
#include <cstring>
#include <string>
#define MaxNV 200

using namespace std;

class NhanVien{
	public:
		char MaNV[MaxNV];
		char Ho[MaxNV];
		char Ten[MaxNV];
		char Phai[5];
		DSHoaDon dshd;
	NhanVien(){	}
	Nhan Vien(char* maNV,char* ho, char*ten, char* phai){
		strcpy(MaNV,maNV);
		strcpy(Ho,ho);
		strcpy(Ten,ten);
		strcpy(Phai,phai);
	}
	int NhapNhanVien(){
		char maNV[MaxNV], ho[MaxNV],ten[MaxNV],phai[MaxNV];
		cin.ignore();
		cout<<"nhap ma nhan  vien: (=0:thoat)";
		cin>>.getline(maNV,sizeof(maNV));
		if (maNV=="0"){
			return 0;
		}
		cout<<"Ho: ";
		cin.getline(ho,sizeof(ho));

		cout<<"Ten: ";
		cin.getline(ten,sizeof(ten));
	
		cout<<"Gioi tinh: ";
		cin.getline(phai,sizeof(phai)) ;
		
		strcpy(this->MaNV,maNV);
		strcpy(this->Ho,ho);
		strcpy(this->Ten,ten);
		strcpy(this->Phai,phai)
	
		return 1;
	}
void HienThi(){
		cout << "ma nhan vien: " << MaNV << " ";
        cout << "Ho: " << Ho << " ";
        cout << "Ten: " << Ten << " ";
		cout<<"Gioi tinh: "<<Phai<<" ";
}
};

class DanhSachNhanVien{
public: 
	int SoNV;
	NhanVien dsnv[MaxNV];
	DanhSachNhanVien();
DanhSachNhanVien(){
	SoNV=0;
}
void nhap() {
    char tiepTuc;
    
    do {
        NhanVien nv;
        nv.NhapNhanVien();
        dsnv[SoNV++] = nv;

        cout << "nhap tiep? (y/n): ";
        cin >> tiepTuc;
    } while (tiepTuc == 'y' || tiepTuc == 'Y');
}
void hienThi(){
	for(int i=0;i<SoNV;i++)
		dsnv[i].HienThi();
}

};
int main(){

}	




