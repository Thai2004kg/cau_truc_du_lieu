#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include "CauTrucDuLieu.h"
#include "GiaoDien.h"


using namespace std;
const int MAXLIST =20000;

const int so_item = 14;
const int dong =14;
const int cot = 30 ;
const int Up = 72; // Extended code 
const int Down = 80;

char thucdon [so_item][50] = {"1. Liet ke danh sach      ",
			                  "2. Tim kiem nhan vien      ",
			                  "3. Them nhan vien          ",
			                  "4. Xoa nhan vien          ",
			                  "5. Cap nhat nhan vien          ",
			                  "6. Liet ke vat tu         ",
			                  "7. Hieu chinh vat tu        ",
			                "8.Them vat tu         ",
			                 "9. Xoa vat tu        ",
			                 "10. Lap hoa don        ",
			                  "11. In hoa don        ",
			                  "12. Thong ke hoa don        ",
			                  "13. Top 10 Vat Tu        ",
							  "14. Ket thuc chuong trinh  "};

int MenuDong(char td [so_item][50]){

  Normal(); system("cls");
  int chon =0;
  int i; 
  for ( i=0; i< so_item ; i++)
  { gotoxy(cot, dong +i);
    cout << td[i];
  }
  HighLight();
  gotoxy(cot,dong+chon);
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon+1 >1)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon --;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Down :if (chon+1 <so_item)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon ++;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case 13 : return chon+1;
  }  // end switch
  } while (1);
}


void LietKeVatTu(CayTimKiem t, char* filename){
			//t.createTree(filename);
			cout<<"Ma Vat Tu | Ten Vat Tu | Don vi tinh | So luong ton";
			t=readFromFileByTen(filename);
			t.LNR();
			getch();
}

void HieuChinh(CayTimKiem t, char* filename){
	t=readFromFileByMa(filename);
	cout<<"Ma VT| Ten Vat Tu  | Don vi tinh | So luong ton" << endl;
	t.LNR();
	t.inputUpdateVatTu();
	t.ghiFileLNR(filename);
	cout<<"Hieu chinh thanh cong!";
	getch();	
}
void ThemVatTu(CayTimKiem t, char* filename){
	t=readFromFileByMa(filename);
	cout<<"Ma VT| Ten Vat Tu  | Don vi tinh | So luong ton" << endl;
	t.LNR();
	t.createTree();
	t.ghiFileLNR(filename);
//	getch();
}
void XoaVatTu(CayTimKiem t, char* filename){
	system ("cls");
	
	//doc tu file, tao cay tiem kiem t, theo ma vat tu
	t=readFromFileByMa(filename);
	
	//xoa
	int ma_vt;
	cout<<"nhap ma vat tu can xoa: ";
	cin>>ma_vt;
	//Kiem tra xem vat tu da co HoaDonNhapXuat hay chua?
	//Tuc la kiem tra Ma vat tu co ton tai trong file ChiTietHoaDon.txt hay chua? neu co thi bao loi, nguoc lai
	DanhSachChiTietHoaDon dsChiTietVatTu;
	dsChiTietVatTu.Doc("ChiTietHoaDon.txt");
	int gap=dsChiTietVatTu.timVatTu(ma_vt);
	cout<<gap;
	if(gap!=0)
	{
	cout<<"Khong the xoa vi Vat tu nay da lap Hoa don";
		}
	else{
		t.deleteNode(ma_vt);
		//ghi lai file
		t.ghiFileLNR(filename);
	}
	
	getch();
}


void LapHoaDon(DSHoaDon hd, int manv, char* fileHoaDon, char* fileChiTietHD){
	hd.Doc(fileHoaDon);
	hd.taoDanhSach(manv); // PHai lien ket voi vat tu, de tim vat tu N (tang so luong); X (giam so luong);
	//Luu hoa don
	hd.Luu(fileHoaDon);//
	//Nhap chi tiet hoa don, luu chi tiet hoa don
	hd.head->data.dscthd.Doc(fileChiTietHD);
	hd.head->data.dscthd.Luu(fileChiTietHD); // Can sua khong luu so hoa don cho tat ca giong nhau
}

void TongHopHoaDon(char* fileHoaDon, char* fileChiTietHD, char* fileVatTu, char* fileNhanVien){
	int SoHoaDon;
	cout<<"Nhap so hoa don ";
	cin>> SoHoaDon;
	
	DSHoaDon hd;
	hd.Doc(fileHoaDon);
	HoaDon d=hd.TimHoaDon(SoHoaDon);
	if(d.SoHD!=0){
	//	d.hienThi();
		
		DanhSachNhanVien dsNhanVien;
		dsNhanVien.Doc(fileNhanVien);
		NhanVien nv;
		nv=dsNhanVien.searchbyMaNV(d.MaNV);
			string Ho,Ten;
		if(nv.MaNV!=0){
			Ho=nv.Ho;
			Ten=nv.Ten;
		}
	//	cout<<Ho<<" "<<Ten;
		
		DanhSachChiTietHoaDon dsChiTiet;
		dsChiTiet.DocBy(fileChiTietHD,SoHoaDon);
		
		CayTimKiem cay=readFromFileByMa(fileVatTu);
		
		DanhSachHoaDonIn dsHoaDonIn;
	
		CTHDNode* current=dsChiTiet.head;
		while(current!=NULL){
		//	cout<<current->DuLieu.MaVT<<endl;
			Node* nut=cay.searchNode(cay.root,current->DuLieu.MaVT);
		//	cout<<nut->DuLieu.TenVatTu<<endl;
			HoaDonIn hdin(SoHoaDon,d.NgayLap,Ho,Ten,d.Loai,nut->DuLieu.TenVatTu,current->DuLieu.SoLuong,current->DuLieu.DonGia,current->DuLieu.VAT);
			dsHoaDonIn.Them(hdin);
			current=current->next;
		}
		dsHoaDonIn.InHoaDon();
	
}
else
	cout<<"So hoa don khong ton tai ";
	
	getch();
}

//Thong ke Hoa don cau g
void ThongKeHoaDon(char* fileHoaDon, char* fileChiTietHD, char* fileNhanVien){
	string tungay,denngay;
	cout<<"Tu ngay: ";
	cin>> tungay;
	
	cout<<"Den ngay: ";
	cin>> denngay;
	
	DSHoaDon dshd;
	//dshd.Doc(fileHoaDon);
	dshd.DocTheoNgay(fileHoaDon,tungay,denngay);
//	dshd.hienThi();
	DanhSachNhanVien dsNhanVien;
	dsNhanVien.Doc(fileNhanVien);
	
	DanhSachChiTietHoaDon dsChiTiet;
	dsChiTiet.Doc(fileChiTietHD);
	HoaDonNode *p=dshd.head;
	double triGia=0;

	DanhSachHoaDonIn dsHoaDonIn;
	dsHoaDonIn.SoPhanTu=0;//Lam rong danh sach
	while(p!=NULL){
		
		triGia=dsChiTiet.TongTriGia(p->data.SoHD);
		NhanVien nv=dsNhanVien.searchbyMaNV(p->data.MaNV);
		HoaDonIn hdin(p->data.SoHD, p->data.NgayLap,nv.Ho,nv.Ten,p->data.Loai,triGia);
		dsHoaDonIn.Them(hdin);
		p=p->next;
	}
	dsHoaDonIn.InThongKe(tungay, denngay);

	getch();
}

//Top 10 Vat Ti co doanh thu cao nhat trong 1 khoang thoi gian *Cau h
void Top10VatTu(char* fileHoaDon, char* fileChiTietHD, char* fileVatTu){
	string tungay,denngay;
	cout<<"Tu ngay: ";
	cin>> tungay;
	
	cout<<"Den ngay: ";
	cin>> denngay;
	
	CayTimKiem cay=readFromFileByMa(fileVatTu);
	

	DSHoaDon dshd;
	dshd.DocTheoLoaiNgay(fileHoaDon,'X',tungay,denngay);//chi lay hoa don X (xuat kho, ban)
//	dshd.hienThi();
	
	HoaDonNode *p=dshd.head;
	double triGia=0;

	DanhSachHoaDonIn dsHoaDonIn;
	dsHoaDonIn.SoPhanTu=0;
	while(p!=NULL){//Lap qua Danh Sach HoaDon(co nhieu chi tiet hoaDon
		DanhSachChiTietHoaDon dsChiTiet;
		dsChiTiet.DocBy(fileChiTietHD,p->data.SoHD);//doc chi tiet hoa don ung voi so hoa don
		CTHDNode* c=dsChiTiet.head;
		while(c!=NULL){//Lap qua danh sach ChitietHoaDon de tao Mau tin in
			Node* nodeVatTu=cay.searchNode(cay.root,c->DuLieu.MaVT);
			string TenVatTu=nodeVatTu->DuLieu.TenVatTu;
			HoaDonIn hdin(c->DuLieu.MaVT, TenVatTu, c->DuLieu.SoLuong, c->DuLieu.DonGia,c->DuLieu.VAT);//HoaDonIn; lop co cac Truong de in
			dsHoaDonIn.Them(hdin);//Them vao danh sach hoa don in
			c=c->next;
		}
		
		p=p->next;
	}
	dsHoaDonIn.InTop10TriGia();

	getch();
}

int MASO_NHANVIEN=-1;

int main (){ system ("cls");
 char fileNhanVien[80]="NhanVien.txt";
 char fileVatTu[80]="VatTu.txt";
 char fileHoaDon[80]="HoaDon.txt";
  char fileChitietHoaDon[80]="ChiTietHoaDon.txt";
 char ten[20]; 
  int chon,vitri;  
  DanhSachNhanVien ds; //Cau Truc Du lieu Luu Danh Sach NhanVien
 
  int masoNv; NhanVien nv; 
  DSHoaDon hd;
  CayTimKiem t; // Cau Truc du lieu Cay Luu thong tin VatTu
  
 ds.Doc(fileNhanVien);// doc filename, ghi len ds
 int check;
 MASO_NHANVIEN=ds.Login();
 if(MASO_NHANVIEN!=-1)
 	check=CheckPwd();
 if(check==1){
 //	t= readFromFile(fileVatTu);
 do
  {
    chon = MenuDong (thucdon);
    system ("cls");
    //nhanvien
    switch (chon ){
    case 1: ds.hienThi(); break;
    case 2: ds.searchTen(); break;
	case 3: ds.nhap();
			ds.SapXep();
			ds.Luu(fileNhanVien);
            break;
    case 4: ds.XoaNhanVien(); 
    		ds.Luu(fileNhanVien);
    		break;
   case 5:
    ds.ChinhSuaNhanVien();
    ds.Luu(fileNhanVien);
    break;

    case 6: {
		LietKeVatTu(t,fileVatTu);//Cay Tim kiem nhi phan theo ten
		break;
	}
	case 7:{
		HieuChinh(t,fileVatTu);
		break;
	}
	case 8:{
		ThemVatTu(t,fileVatTu);//cay tim kiem nhi phan theo ma
		break;
	}
	case 9:{
		
		XoaVatTu(t,fileVatTu); // bo sung kiem tra ma vat tu trong ChiTietHoaDon neu ton tai thi bao loi
	
	
		break;
	}
	case 10:{
		
		LapHoaDon(hd,MASO_NHANVIEN ,fileHoaDon,fileChitietHoaDon);	
	
		break;
	}
	case 11:{
	
		TongHopHoaDon(fileHoaDon, fileChitietHoaDon, fileVatTu, fileNhanVien);
	
		break;
	}
	case 12:{
		ThongKeHoaDon(fileHoaDon, fileChitietHoaDon, fileNhanVien);
		
		break;
	}
	case 13:{		
		Top10VatTu(fileHoaDon, fileChitietHoaDon, fileVatTu);
		break;
	}
    case so_item : { ds.Luu(fileNhanVien); return 0;}
}
  } while (1);
}
else{
	cout<<"Sai mat khau 3 lan, thoat va chay lai ";
}
	
  return 0;
  }
