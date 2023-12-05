<<<<<<< HEAD
#include "vattu.h"

using namespace std;

// Implement VatTu class
VatTu::VatTu() {
    MaVatTu = 0;
    strcpy(TenVatTu, "");
    strcpy(DonViTinh, "");
    SoLuongTon = 0;
}

VatTu::VatTu(int m, char* t, char* d, double s) {
    MaVatTu = m;
    strcpy(TenVatTu, t);
    strcpy(DonViTinh, d);
    SoLuongTon = s;
}

void VatTu::hienThi() {
    cout << "Ma Vat Tu: " << MaVatTu << ", ";
    cout << "Ten Vat Tu: " << TenVatTu << ", ";
    cout << "Don vi tinh: " << DonViTinh << ", ";
    cout << "So luong ton: " << SoLuongTon << endl;
}

int VatTu::nhapVatTu() {
    int m;
    char t[maxlength], d[maxlength];
    double s;

    cout << "nhap ma vat tu: (=0:thoat)";
    cin >> m;
    if (m == 0) {
        return 0;
    }

    cin.ignore();
    cout << "nhap ten vat tu: ";
    cin.getline(t, sizeof(t));

    cout << "nhap don vi tinh: ";
    cin.getline(d, sizeof(d));

    cout << "nhap so luong ton: ";
    cin >> s;

    this->MaVatTu = m;
    strcpy(this->TenVatTu, t);
    strcpy(this->DonViTinh, d);
    this->SoLuongTon = s;

    return 1;
}

// Implement Node class
Node::Node(int m, char* t, char* d, double s) {
    DuLieu.MaVatTu = m;
    strcpy(DuLieu.TenVatTu, t);
    strcpy(DuLieu.DonViTinh, d);
    DuLieu.SoLuongTon = s;
    Left = NULL;
    Right = NULL;
}

Node::Node(VatTu v) {
    DuLieu = v;
    Left = NULL;
    Right = NULL;
}

void Node::ghiDuLieu(ofstream& file) {
    file.write(reinterpret_cast<const char*>(&DuLieu), sizeof(VatTu));
}

// Implement CayTimKiem class
CayTimKiem::CayTimKiem() {
    root = NULL;
}

Node* CayTimKiem::insertNode(Node* p, int m, char* t, char* d, double s) {
     if (p == NULL) {
=======
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;
#define maxlength 255

class VatTu {
public:
    int MaVatTu;
    char TenVatTu[maxlength];
    char DonViTinh[maxlength];
    double SoLuongTon;

    VatTu() {
        MaVatTu = 0;
        strcpy(TenVatTu, "");
        strcpy(DonViTinh, "");
        SoLuongTon = 0;
    }

    VatTu(int m, char* t, char* d, double s) {
        MaVatTu = m;
        strcpy(TenVatTu, t);
        strcpy(DonViTinh, d);
        SoLuongTon = s;
    }

    void hienThi() {
        cout << "Ma Vat Tu: " << MaVatTu << ", ";
        cout << "Ten Vat Tu: " << TenVatTu << ", ";
        cout << "Don vi tinh: " << DonViTinh << ", ";
        cout << "So luong ton: " << SoLuongTon << endl;
    }

    int nhapVatTu() {
        int m;
        char t[maxlength], d[maxlength];
        double s;
        cout << "nhap ma vat tu: (=0:thoat)";
        cin >> m;
        if (m == 0) {
            return 0;
        }

        cin.ignore();
        cout << "nhap ten vat tu: ";
        cin.getline(t, sizeof(t));

        cout << "nhap don vi tinh: ";
        cin.getline(d, sizeof(d));

        cout << "nhap so luong ton: ";
        cin >> s;

        this->MaVatTu = m;
        strcpy(this->TenVatTu, t);
        strcpy(this->DonViTinh, d);
        this->SoLuongTon = s;

        return 1;
    }
};

class Node {
public:
    VatTu DuLieu;
    Node* Left;
    Node* Right;

    Node(int m, char* t, char* d, double s) {
        DuLieu.MaVatTu = m;
        strcpy(DuLieu.TenVatTu, t);
        strcpy(DuLieu.DonViTinh, d);
        DuLieu.SoLuongTon = s;
        Left = NULL;
        Right = NULL;
    }

    Node(VatTu v) {
        DuLieu = v;
        Left = NULL;
        Right = NULL;
    }


    void ghiDuLieu(ofstream& file) {
        file << DuLieu.MaVatTu << "," << DuLieu.TenVatTu << "," << DuLieu.DonViTinh << "," << DuLieu.SoLuongTon << endl;
    }
};

class CayTimKiem {
public:
    Node* root;

    CayTimKiem() {
        root = NULL;
    }

    Node* insertNode(Node* p, int m, char* t, char* d, double s) {
        if (p == NULL) {
>>>>>>> b1d1d97d3ed518cab8da26d72c1e6d8d4a56d1c8
            return new Node(m, t, d, s);
        }
        if (m < p->DuLieu.MaVatTu)
            p->Left = insertNode(p->Left, m, t, d, s);
        else if (m > p->DuLieu.MaVatTu)
            p->Right = insertNode(p->Right, m, t, d, s);
        return p;
    }

<<<<<<< HEAD
Node* CayTimKiem::insertNode(Node* p, VatTu v) {
    if (p == NULL) {
=======
    Node* insertNode(Node* p, VatTu v) {
        if (p == NULL) {
>>>>>>> b1d1d97d3ed518cab8da26d72c1e6d8d4a56d1c8
            return new Node(v);
        }
        if (v.MaVatTu < p->DuLieu.MaVatTu)
            p->Left = insertNode(p->Left, v);
        else if (v.MaVatTu > p->DuLieu.MaVatTu)
            p->Right = insertNode(p->Right, v);
        else
            return NULL;
        return p;
    }

<<<<<<< HEAD
void CayTimKiem::insertNode(VatTu v) {
      Node* p = insertNode(root, v);
=======
    void insertNode(VatTu v) {
        Node* p = insertNode(root, v);
>>>>>>> b1d1d97d3ed518cab8da26d72c1e6d8d4a56d1c8
        if (p == NULL)
            cout << "ma vat tu bi trung" << endl;
        else
            root = p;
    }
<<<<<<< HEAD
 Node* CayTimKiem::searchNode(Node* p, int ma_vt) {
=======

    Node* searchNode(Node* p, int ma_vt) {
>>>>>>> b1d1d97d3ed518cab8da26d72c1e6d8d4a56d1c8
        if (p == NULL)
            return NULL;
        if (ma_vt == p->DuLieu.MaVatTu)
            return p;
        else if (ma_vt < p->DuLieu.MaVatTu)
            return searchNode(p->Left, ma_vt);
        else if (ma_vt > p->DuLieu.MaVatTu)
            return searchNode(p->Right, ma_vt);
    }

<<<<<<< HEAD
    // Search for a node by MaVatTu value and display its information
    void CayTimKiem::searchNode(int ma_vt) {
=======
    void searchNode(int ma_vt) {
>>>>>>> b1d1d97d3ed518cab8da26d72c1e6d8d4a56d1c8
        Node* p = searchNode(root, ma_vt);
        if (p == NULL)
            cout << "khong tim gap" << endl;
        else
            p->DuLieu.hienThi();
    }

<<<<<<< HEAD
    // Update information for a VatTu object in the tree
    void CayTimKiem::inputUpdateVatTu() {
=======
    void inputUpdateVatTu() {
>>>>>>> b1d1d97d3ed518cab8da26d72c1e6d8d4a56d1c8
        int mvt;
        cout << "nhap ma vat tu can sua: ";
        cin >> mvt;
        cin.ignore();
        cout << "nhap ten can sua: ";
        char t[maxlength];
        cin.getline(t, sizeof(t));
        cout << "don vi tinh: ";
        char d[maxlength];
        cin.getline(d, sizeof(d));
        cout << "nhap so luong: ";
        double s;
        cin >> s;
        updateNode(mvt, t, d, s);
    }

<<<<<<< HEAD
    // Update information for a node in the tree
    void CayTimKiem::updateNode(int ma_vt, char* t, char* d, double sl) {
=======
    void updateNode(int ma_vt, char* t, char* d, double sl) {
>>>>>>> b1d1d97d3ed518cab8da26d72c1e6d8d4a56d1c8
        Node* p = searchNode(root, ma_vt);
        if (p != NULL) {
            strcpy(p->DuLieu.TenVatTu, t);
            strcpy(p->DuLieu.DonViTinh, d);
            p->DuLieu.SoLuongTon = sl;
        } else
            cout << "ma vat tu khong ton tai" << endl;
    }

<<<<<<< HEAD
    // Delete a node with a specific MaVatTu value
    bool CayTimKiem::deleteNode(int ma_vt) {
=======
    bool deleteNode(int ma_vt) {
>>>>>>> b1d1d97d3ed518cab8da26d72c1e6d8d4a56d1c8
        Node* p = deleteNode(root, ma_vt);
        if (p == NULL) {
            cout << "No VatTu found with ID " << ma_vt << endl;
            return false;
        }
        cout << "VatTu with ID " << ma_vt << " has been deleted." << endl;
        return true;
    }

<<<<<<< HEAD
    // Recursive function to delete a node with a specific MaVatTu value
    Node* CayTimKiem::deleteNode(Node* p, int ma_vt) {
=======
    Node* deleteNode(Node* p, int ma_vt) {
>>>>>>> b1d1d97d3ed518cab8da26d72c1e6d8d4a56d1c8
        if (p == NULL) {
            return p;
        }

        if (ma_vt < p->DuLieu.MaVatTu) {
            p->Left = deleteNode(p->Left, ma_vt);
        } else if (ma_vt > p->DuLieu.MaVatTu) {
            p->Right = deleteNode(p->Right, ma_vt);
        } else {
            if (p->Left == NULL) {
                Node* temp = p->Right;
                delete p;
                return temp;
            } else if (p->Right == NULL) {
                Node* temp = p->Left;
                delete p;
                return temp;
            }

            Node* temp = minValueNode(p->Right);
            p->DuLieu = temp->DuLieu;
            p->Right = deleteNode(p->Right, temp->DuLieu.MaVatTu);
        }

        return p;
    }

<<<<<<< HEAD
    // Find the node with the smallest value in a subtree
    Node* CayTimKiem::minValueNode(Node* node) {
=======
    Node* minValueNode(Node* node) {
>>>>>>> b1d1d97d3ed518cab8da26d72c1e6d8d4a56d1c8
        Node* current = node;
        while (current->Left != NULL) {
            current = current->Left;
        }
        return current;
    }

<<<<<<< HEAD
    // Create a tree by continuously inputting VatTu objects until the user enters 0
    int CayTimKiem::createTree() {
=======
    int createTree() {
>>>>>>> b1d1d97d3ed518cab8da26d72c1e6d8d4a56d1c8
        while (1) {
            VatTu v;
            if (v.nhapVatTu() == 0) {
                return 0;
            } else {
                insertNode(v);
            }
        }
    }

<<<<<<< HEAD
    // Create a tree by reading VatTu objects from a binary file
    int CayTimKiem::createTree(char* filename) {
        ifstream file_obj;
        file_obj.open(filename, ios::in | ios::binary);

        if (!file_obj) {
            cerr << "Error opening file for reading: " << filename << endl;
=======
    int createTree(char* filename) {
        ifstream file_obj(filename);
        file_obj.open(filename, ios::in);

        if (!file_obj.is_open()) {
            cerr << "Loi mo file: " << filename << endl;
>>>>>>> b1d1d97d3ed518cab8da26d72c1e6d8d4a56d1c8
            return 0;
        }

        VatTu obj;

<<<<<<< HEAD
        while (file_obj.read((char*)&obj, sizeof(VatTu))) {
=======
        while (file_obj >> obj.MaVatTu >> obj.TenVatTu >> obj.DonViTinh >> obj.SoLuongTon) {
>>>>>>> b1d1d97d3ed518cab8da26d72c1e6d8d4a56d1c8
            insertNode(obj);
        }

        file_obj.close();

        return 1;
    }

<<<<<<< HEAD
    // In-order traversal of the tree and display information of each node
    void CayTimKiem::LNR(Node* p) {
=======
    void LNR(Node* p) {
>>>>>>> b1d1d97d3ed518cab8da26d72c1e6d8d4a56d1c8
        if (p != NULL) {
            LNR(p->Left);
            p->DuLieu.hienThi();
            LNR(p->Right);
        }
    }

<<<<<<< HEAD
    // Wrapper function for LNR traversal
    void CayTimKiem::LNR() {
=======
    void LNR() {
>>>>>>> b1d1d97d3ed518cab8da26d72c1e6d8d4a56d1c8
        cout << "Duyet cay LNR \n";
        LNR(root);
        cout << endl;
    }

<<<<<<< HEAD
    // In-order traversal of the tree and write data to a binary file
    void CayTimKiem::ghiFileLNR(Node* p, std::ofstream& file) {
        if (p != NULL) {
            ghiFileLNR(p->Left, file);
            p->ghiDuLieu(file);
=======
    void ghiFileLNR(Node* p, std::ofstream& file) {
        if (p != NULL) {
            ghiFileLNR(p->Left, file);
           // p->ghiDuLieu(file);
           file<<p->DuLieu.MaVatTu<<","<<p->DuLieu.TenVatTu<<","<<p->DuLieu.DonViTinh<<","<<p->DuLieu.SoLuongTon<<endl;
>>>>>>> b1d1d97d3ed518cab8da26d72c1e6d8d4a56d1c8
            ghiFileLNR(p->Right, file);
        }
    }

<<<<<<< HEAD
    // Wrapper function for writing tree data to a binary file
    void CayTimKiem::ghiFileLNR(std::ofstream& file) {
        ghiFileLNR(root, file);
    }
};
// het cay tim kiem
void readVatTuFromFile(char* filename) {
   ifstream inputFile(filename, ios::binary);
=======
    void ghiFileLNR(std::ofstream& file) {
        ghiFileLNR(root, file);
    }
    void ghiFileLNR(char* filename) {
    	ofstream file(filename,ios::out);
        ghiFileLNR(root, file);
        file.close();
    }
};

void readVatTuFromFile(char* filename) {
    ifstream inputFile(filename, ios::binary);
>>>>>>> b1d1d97d3ed518cab8da26d72c1e6d8d4a56d1c8

    if (!inputFile) {
        std::cerr << "Error opening the file for reading." << std::endl;
        return;
    }

    VatTu v;
    cout << "Thong tin vat tu: " << endl;
<<<<<<< HEAD
    while (inputFile.read(reinterpret_cast<char*>(&v), sizeof(VatTu))) {
        cout << "Ma vat tu: " << v.MaVatTu << "-Ten vat tu: " << v.TenVatTu
             << " -Don vi tinh: " << v.DonViTinh << " -So luong ton: " << v.SoLuongTon;
=======
    while (inputFile >> v.MaVatTu >> v.TenVatTu >> v.DonViTinh >> v.SoLuongTon) {
        cout << "Ma vat tu: " << v.MaVatTu << "-Ten vat tu: " << v.TenVatTu << " -Don vi tinh: " << v.DonViTinh << " -So luong ton: " << v.SoLuongTon;
>>>>>>> b1d1d97d3ed518cab8da26d72c1e6d8d4a56d1c8
        cout << endl;
    }
    inputFile.close();
}

<<<<<<< HEAD

int docFileVatTu(char* filename) {
    ifstream file_obj;

    file_obj.open(filename, ios::in);

    VatTu obj;

    file_obj.read((char*)&obj, sizeof(obj));

    while (!file_obj.eof()) {
        cout << "Ma VT: " << obj.MaVatTu << "; Ten VT: " << obj.TenVatTu
             << "; Don vi tinh: " << obj.DonViTinh << "; So luong ton: " << obj.SoLuongTon << endl;
        file_obj.read((char*)&obj, sizeof(obj));
=======
int docFileVatTu(char* filename) {
    ifstream file_obj(filename);

    if (!file_obj) {
        cerr << "Error opening file for reading: " << filename << endl;
        return 1;
    }

    VatTu obj;

    while (file_obj >> obj.MaVatTu >> obj.TenVatTu >> obj.DonViTinh >> obj.SoLuongTon) {
        cout << "Ma VT: " << obj.MaVatTu << "; Ten VT: " << obj.TenVatTu << "; Don vi tinh: " << obj.DonViTinh << "; So luong ton: " << obj.SoLuongTon << endl;
>>>>>>> b1d1d97d3ed518cab8da26d72c1e6d8d4a56d1c8
    }

    file_obj.close();

    return 0;
}

<<<<<<< HEAD

=======
CayTimKiem readFromFile(const std::string& filename) {
    CayTimKiem cayVatTu;
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Loi mo file" << std::endl;
        return cayVatTu;
    }

    string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        string smavt,ten, dvt,ssoluong;
               
        getline(ss,smavt,',');
        getline(ss,ten,',');
        getline(ss,dvt,',');
        getline(ss,ssoluong,',');
        int mavt=stoi(smavt);//doi chuoi thanh int
        double soluong=stod(ssoluong);//doi chuoi thanh double
      
        char* t = const_cast<char*>(ten.c_str());
        char* d = const_cast<char*>(dvt.c_str());
        VatTu v(mavt,t,d,soluong);
        cayVatTu.insertNode(v);
    }

    inFile.close();

    return cayVatTu;
}

int main() {
   
	CayTimKiem t;

	char filename[80]="VatTu.txt";

	t= readFromFile(filename);
	t.LNR();
	
	t.createTree();
	
	t.LNR();
	t.ghiFileLNR(filename);
	cout<<"ghi file thanh cong \n";
	cout<<"nhap ma vat tu can tim :";
	int s;
	cin>>s;
	t.searchNode(s);
	//xoa con sai
	cout<<"nhap ma vat tu can xoa: ";
	cin>>s;
	t.deleteNode(s);
	t.LNR();
	//sua con sai
	t.inputUpdateVatTu();
	t.ghiFileLNR(filename);
	
	t= readFromFile(filename);
	t.LNR();
	return 1;
}
>>>>>>> b1d1d97d3ed518cab8da26d72c1e6d8d4a56d1c8
