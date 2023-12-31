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
    void update(int ma_vt, int sl, double d, double vat) ;
               
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
	void taoDanhSach();
	void hienThi();
	void Luu(int SoHoaDon,char* filename);
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
	
