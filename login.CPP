#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include "HoaDon.h"
#include "mylib.h"

using namespace std;
const int MAXLIST =20000;

const int so_item = 7;
const int dong =10;
const int cot = 30 ;
const int Up = 72; // Extended code 
const int Down = 80;

char thucdon [so_item][50] = {"1. Liet ke danh sach      ",
			                  "2. Tim kiem nhan vien      ",
			                  "3. Them nhan vien          ",
			                  "4. Xoa nhan vien          ",
			                  "5. Mo  danh sach          ",
			                  "6. Luu                    ",
			                  "7. Ket thuc chuong trinh  "};

void Normal () {
	SetColor(15);
	SetBGColor(0);
}
void HighLight () {
	SetColor(15);
	SetBGColor(1);
}
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

void BaoLoi (const char *s){
  int x=wherex() , y=wherey();
  gotoxy (10,24);
  cout <<s;
  Sleep(2000);
  gotoxy(10,24);
  clreol();
  gotoxy(x,y);
}

void NhapChuoi(const char *tieude, char *S, size_t size) {
    std::cout << tieude;
    std::cin.getline(S, size);
    
    while (strcmp(S, "") == 0) {
        std::cout << "Khong duoc nhap chuoi rong. " << tieude;
        std::cin.getline(S, size);
    }
}

void NhapChuoi (char *tieude, char *S) {
	cout << tieude ;  fflush(stdin);
    do
	  gets(S); 
    while (strcmp(S,"")==0)  ;	
}

int MASO_NHANVIEN=-1;

int main (){ system ("cls");
 char filename[80]="NhanVien.Dat";
 char ten[20]; 
  int chon,vitri;  DanhSachNhanVien ds; int masoNv; NhanVien nv; 
 // OpenFile(ds,filename);
 
 ds.Doc(filename);// doc filename, ghi len ds
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
    case 5: ds.hienThi(); break;
    case 6: ds.Luu(filename); break;
    case so_item : { ds.Luu(filename); return 0;}
   }
  } while (1);
}
else{
	cout<<"Sai mat khau 3 lan, thoat va chay lai ";
}
	
  return 0;
  }
