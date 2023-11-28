#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

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
        file << DuLieu.MaVatTu << " " << DuLieu.TenVatTu << " " << DuLieu.DonViTinh << " " << DuLieu.SoLuongTon << endl;
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
            return new Node(m, t, d, s);
        }
        if (m < p->DuLieu.MaVatTu)
            p->Left = insertNode(p->Left, m, t, d, s);
        else if (m > p->DuLieu.MaVatTu)
            p->Right = insertNode(p->Right, m, t, d, s);
        return p;
    }

    Node* insertNode(Node* p, VatTu v) {
        if (p == NULL) {
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

    void insertNode(VatTu v) {
        Node* p = insertNode(root, v);
        if (p == NULL)
            cout << "ma vat tu bi trung" << endl;
        else
            root = p;
    }

    Node* searchNode(Node* p, int ma_vt) {
        if (p == NULL)
            return NULL;
        if (ma_vt == p->DuLieu.MaVatTu)
            return p;
        else if (ma_vt < p->DuLieu.MaVatTu)
            return searchNode(p->Left, ma_vt);
        else if (ma_vt > p->DuLieu.MaVatTu)
            return searchNode(p->Right, ma_vt);
    }

    void searchNode(int ma_vt) {
        Node* p = searchNode(root, ma_vt);
        if (p == NULL)
            cout << "khong tim gap" << endl;
        else
            p->DuLieu.hienThi();
    }

    void inputUpdateVatTu() {
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

    void updateNode(int ma_vt, char* t, char* d, double sl) {
        Node* p = searchNode(root, ma_vt);
        if (p != NULL) {
            strcpy(p->DuLieu.TenVatTu, t);
            strcpy(p->DuLieu.DonViTinh, d);
            p->DuLieu.SoLuongTon = sl;
        } else
            cout << "ma vat tu khong ton tai" << endl;
    }

    bool deleteNode(int ma_vt) {
        Node* p = deleteNode(root, ma_vt);
        if (p == NULL) {
            cout << "No VatTu found with ID " << ma_vt << endl;
            return false;
        }
        cout << "VatTu with ID " << ma_vt << " has been deleted." << endl;
        return true;
    }

    Node* deleteNode(Node* p, int ma_vt) {
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

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->Left != NULL) {
            current = current->Left;
        }
        return current;
    }

    int createTree() {
        while (1) {
            VatTu v;
            if (v.nhapVatTu() == 0) {
                return 0;
            } else {
                insertNode(v);
            }
        }
    }

    int createTree(char* filename) {
        ifstream file_obj;
        file_obj.open(filename, ios::in);

        if (!file_obj) {
            cerr << "Error opening file for reading: " << filename << endl;
            return 0;
        }

        VatTu obj;

        while (file_obj >> obj.MaVatTu >> obj.TenVatTu >> obj.DonViTinh >> obj.SoLuongTon) {
            insertNode(obj);
        }

        file_obj.close();

        return 1;
    }

    void LNR(Node* p) {
        if (p != NULL) {
            LNR(p->Left);
            p->DuLieu.hienThi();
            LNR(p->Right);
        }
    }

    void LNR() {
        cout << "Duyet cay LNR \n";
        LNR(root);
        cout << endl;
    }

    void ghiFileLNR(Node* p, std::ofstream& file) {
        if (p != NULL) {
            ghiFileLNR(p->Left, file);
            p->ghiDuLieu(file);
            ghiFileLNR(p->Right, file);
        }
    }

    void ghiFileLNR(std::ofstream& file) {
        ghiFileLNR(root, file);
    }
};

void readVatTuFromFile(char* filename) {
    ifstream inputFile(filename, ios::binary);

    if (!inputFile) {
        std::cerr << "Error opening the file for reading." << std::endl;
        return;
    }

    VatTu v;
    cout << "Thong tin vat tu: " << endl;
    while (inputFile >> v.MaVatTu >> v.TenVatTu >> v.DonViTinh >> v.SoLuongTon) {
        cout << "Ma vat tu: " << v.MaVatTu << "-Ten vat tu: " << v.TenVatTu << " -Don vi tinh: " << v.DonViTinh << " -So luong ton: " << v.SoLuongTon;
        cout << endl;
    }
    inputFile.close();
}

int docFileVatTu(char* filename) {
    ifstream file_obj(filename, ios::in);

    if (!file_obj) {
        cerr << "Error opening file for reading: " << filename << endl;
        return 1;
    }

    VatTu obj;

    while (file_obj >> obj.MaVatTu >> obj.TenVatTu >> obj.DonViTinh >> obj.SoLuongTon) {
        cout << "Ma VT: " << obj.MaVatTu << "; Ten VT: " << obj.TenVatTu << "; Don vi tinh: " << obj.DonViTinh << "; So luong ton: " << obj.SoLuongTon << endl;
    }

    file_obj.close();

    return 0;
}

int main() {
   
	CayTimKiem t;

//	t.LNR();
	
	char* filename="vattu.dat";
	t.createTree(filename);
	t.LNR();
	
	t.createTree();
	
	cout<<"nhap ma vat tu can tim :";
	int s;
	cin>>s;
	t.searchNode(s);
	
	cout<<"nhap ma vat tu can xoa: ";
	cin>>s;
	t.deleteNode(s);
	t.inputUpdateVatTu();
	
	
	ofstream outstream;
	outstream.open(filename); 
   if (outstream.fail()) {
    cerr << "Loi ghi file" << endl;
    outstream.clear();
} else {
   t.ghiFileLNR(outstream); 
    outstream.close();
    cout << "Data written to file successfully." << endl;
}
   
    
	cout<<"doc tu file: "<<endl;

	docFileVatTu(filename);
	return 1;
}
