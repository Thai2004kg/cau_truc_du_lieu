#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include "CauTrucDuLieu.h"
#include "GiaoDien.h"
int main(){
	
	string tungay,denngay;
	cout<<"Tu ngay: ";
	cin>> tungay;
	
	cout<<"Den ngay: ";
	cin>> denngay;
	
//	CayTimKiem cay=readFromFileByMa("VatTu.txt");
	

	DSHoaDon dshd;
	dshd.DocTheoLoaiNgay("HoaDon.txt",'X',tungay,denngay);
	dshd.hienThi();
	
	return 1;
	
}
