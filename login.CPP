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

const int so_item = 10;
const int dong =10;
const int cot = 30 ;
const int Up = 72; // Extended code 
const int Down = 80;

char thucdon [so_item][50] = {"1. Liet ke danh sach      ",
			                  "2. Tim kiem nhan vien      ",
			                  "3. Them nhan vien          ",
			                  "4. Xoa nhan vien          ",
			                  "5. Luu          ",
			                  "6. Liet ke vat tu         ",
			                  "7. Hieu chinh vat tu        ",
			                "8.Them vat tu         ",
			                 "9. Xoa vat tu        ",
							  "10. Ket thuc chuong trinh  "};

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
			t.createTree(filename);
			t.LNR();
			getch();
}

void HieuChinh(CayTimKiem t, char* filename){
	
	
	 ofstream file_obj;
     file_obj.open(filename, ios::out | ios::binary);

        if (!file_obj) {
            cerr << "Loi mo file: " << filename << endl;
            getch();
         return ;
        }
	
	t.inputUpdateVatTu();
	t.ghiFileLNR(file_obj);
	cout<<"Hieu chinh thanh cong!";
	getch();	
}
void ThemVatTu(CayTimKiem t, char* filename){
	getch();
}
void XoaVatTu(CayTimKiem t, char* filename){
	getch();
}

int MASO_NHANVIEN=-1;

int main (){ system ("cls");
 char fileNhanVien[80]="NhanVien.Dat";
 char fileVatTu[80]="vattu.dat";
 char ten[20]; 
  int chon,vitri;  
  DanhSachNhanVien ds; //Cau Truc Du lieu Luu Danh Sach NhanVien
 
  int masoNv; NhanVien nv; 
 
  CayTimKiem t; // Cau Truc du lieu Cay Luu thong tin VatTu
  
 ds.Doc(fileNhanVien);// doc filename, ghi len ds
 int check;
 MASO_NHANVIEN=ds.Login();
 if(MASO_NHANVIEN!=-1)
 	check=CheckPwd();
 if(check==1){
 
 do
  {
    chon = MenuDong (thucdon);
    system ("cls");
    switch (chon ){
    case 1: ds.hienThi(); break;
    case 2: ds.searchTen(); break;
	case 3: ds.nhap();
            break;
    case 4: ds.XoaNhanVien(); 
    		break;
    case 5: ds.Luu(fileNhanVien); break;
    case 6: {
		LietKeVatTu(t,fileVatTu);
		break;
	}
	case 7:{
		HieuChinh(t,fileVatTu);
		break;
	}
	case 8:{
		ThemVatTu(t,fileVatTu);
		break;
	}
	case 9:{
		XoaVatTu(t,fileVatTu);
	
	
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
