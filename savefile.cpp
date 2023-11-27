#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class VatTu{
public: 
	int MaVatTu; // qui tac Pácal
	string TenVatTu;
	string DonViTinh;
	double SoLuongTon;
		VatTu() {
		MaVatTu=0;
		TenVatTu="";
		DonViTinh="";
		SoLuongTon=0;
		}
	VatTu(int m, string t, string d, double s) {
		MaVatTu=m;
		TenVatTu=t;
		DonViTinh=d;
		SoLuongTon=s;
		}
	void hienThi()//qui tac con lac da, camel
	{
	cout<<"Ma Vat Tu: " <<this->MaVatTu<<endl;//khong co chu this cung duoc 
	cout<<"Ten Vat Tu: "<<this->TenVatTu<<endl;
	cout<<"Don vi tinh: "<<this->DonViTinh<<endl;
	cout<<"So luong ton: "<<this->SoLuongTon<<endl;
	 
	}
	

	
	int nhapVatTu(){
		int m;
		string t,d;
		double s;
		cout<<"nhap ma vat tu: (=0:thoat)";
		cin>>m;
		if (m==0){
			return 0;
		}
		cout<<"nhap ten vat tu: ";
		cin>>t;
		cout<<"nhap don vi tinh: ";
		cin>>d;
		cout<<"nhap so luong ton: ";
		cin>>s;
		MaVatTu=m;
		TenVatTu=t;
		DonViTinh=d;
		SoLuongTon=s;
		return 1;
	}
			
}; //ket thuc lop 

class Node{
	public:
		VatTu DuLieu;
		Node* Left;
		Node* Right;
		Node(int m, string t, string d, double s){
			DuLieu.MaVatTu=m;
			DuLieu.TenVatTu=t;
			DuLieu.DonViTinh=d;
			DuLieu.SoLuongTon=s;
			Left=NULL;
			Right=NULL;
		}
		void ghiFile(string& fileName){
		        
       ofstream binaryFile(fileName.c_str(), ios::out | ios::app | ios::binary);


    	if (!binaryFile) {
        	cerr << "Khong the mo tep." << endl;
        	return;
    		}

    	binaryFile.write((char*)&DuLieu, sizeof(VatTu));
        binaryFile.close();
   		 }
	
};
class CayTimKiem{
	public:
	Node* root;
	CayTimKiem(){//tao cay rong
		root=NULL;
	}
	void insertNode(VatTu v){
		root=insertNode(root,v.MaVatTu,v.TenVatTu,v.DonViTinh,v.SoLuongTon);
	}
	Node* insertNode(Node* p,int m, string t, string d, double s){
		if(p==NULL){
			return new Node(m,t,d,s);
		
		}
		if(m<p->DuLieu.MaVatTu)
			p->Left  =	insertNode(p->Left,m,t,d,s);
		else if(m>p->DuLieu.MaVatTu)
			p->Right = insertNode(p->Right,m,t,d,s);	
	return p;
	}
int createTree(){
	while(1){
		VatTu v;
		if (v.nhapVatTu()==0){
			return 0;}
		else{
			insertNode(v);
		}
	}
}

void LNR(Node *p) { // duyet cay con trai ; goc ; duyet cay con phai 
		if (p != NULL) {
			LNR(p->Left);
			p->DuLieu.hienThi();
			// viet gia tri nut goc
			LNR(p->Right);
		}
	}
	void LNR() {
		LNR(root);
		cout << endl;
	}
	
	void ghiFileLNR(Node *p,string filename) { // duyet cay con trai ; goc ; duyet cay con phai 
		if (p != NULL) {
			ghiFileLNR(p->Left,filename);
			p->ghiFile(filename);
			// viet gia tri nut goc
			ghiFileLNR(p->Right,filename);
		}
	}
		void ghiFileLNR(string filename) { 
		ghiFileLNR(root,filename);
	}
	
};
// Hàm d?c t?p nh? phân và in d? li?u ra màn hình
void readVatTuFromFile(const string& fileName) {
    ifstream binaryFile(fileName.c_str(), ios::in | ios::binary);

    if (!binaryFile) {
        cerr << "khong the mo tep nhi phan." << endl;
        return;
    }

    	VatTu v; //*
    while (binaryFile.read((char*)&v, sizeof(VatTu))) {
        cout << "Ma VT: " << v.MaVatTu << ", Ten VT: " << v.TenVatTu <<", Don vi tinh: "<<v.DonViTinh<<", So luong: "
		<<v.SoLuongTon<<endl;
    }

    binaryFile.close();
}

int main(){
	CayTimKiem t;
	t.createTree();
	t.LNR();
	string f="VatTu.dat";
	t.ghiFileLNR(f);
	cout<<"doc tu file: "<<endl;
	readVatTuFromFile(f);
	return 1;
}
	
	
