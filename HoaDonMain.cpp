#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "HoaDon.h"
#define HDlength 100

using namespace std;

int main() {
    CTHD ct;
   // ct.nhapChiTietHoaDon();
  //  ct.hienThi();
  
  /*DanhSachChiTietHoaDon ct;
  ct.taoDanhSach();
  ct.hienThi();
  */
 /* DSHoaDon ds;
  ds.taoDanhSach();
  ds.hienThi();*/
  //  HOADON* hoadon1 = new HOADON(0, "", "");
 //   hoadon1->nhapHoaDon();
 //   ct.TimKiem(s);
  DanhSachNhanVien nv;
  
 
 
 char* fileNV = const_cast<char*>("NhanVien.dat");
 	nv.Doc(fileNV);
 	nv.Login();
	nv.hienThi();
 
  nv.nhap();
  nv.hienThi();
  nv.SapXep();
  cout<<"Sau sap xep \n";
  nv.hienThi();

 nv.Luu(fileNV);
 char* fileDSHD = const_cast<char*>("DSHD.dat");
 char* fileDSCTHD = const_cast<char*>("DScthd.dat");
 DSHoaDon danhSachHoaDon;
DanhSachChiTietHoaDon danhSachChiTietHoaDon;

danhSachHoaDon.Luu(fileDSHD);
danhSachChiTietHoaDon.Luu(fileDSCTHD);

danhSachHoaDon.Doc(fileDSHD);
danhSachChiTietHoaDon.Doc(fileDSCTHD);
    return 0;
}    

