#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class VatTu {
public:
    int MaVatTu;
    string TenVatTu;
    string DonViTinh;
    double SoLuongTon;

    VatTu() {
        MaVatTu = 0;
        TenVatTu = "";
        DonViTinh = "";
        SoLuongTon = 0;
    }

    VatTu(int m, string t, string d, double s) {
        MaVatTu = m;
        TenVatTu = t;
        DonViTinh = d;
        SoLuongTon = s;
    }

    void hienThi() {
        cout << "Ma Vat Tu: " << MaVatTu << endl;
        cout << "Ten Vat Tu: " << TenVatTu << endl;
        cout << "Don vi tinh: " << DonViTinh << endl;
        cout << "So luong ton: " << SoLuongTon << endl;
    }

    int nhapVatTu() {
        int m;
        string t, d;
        double s;
        cout << "nhap ma vat tu: (=0:thoat)";
        cin >> m;
        if (m == 0) {
            return 0;
        }
        cout << "nhap ten vat tu: ";
        cin >> t;
        cout << "nhap don vi tinh: ";
        cin >> d;
        cout << "nhap so luong ton: ";
        cin >> s;
        MaVatTu = m;
        TenVatTu = t;
        DonViTinh = d;
        SoLuongTon = s;
        return 1;
    }
};

class Node {
public:
    VatTu DuLieu;
    Node* Left;
    Node* Right;

    Node(int m, string t, string d, double s) {
        DuLieu.MaVatTu = m;
        DuLieu.TenVatTu = t;
        DuLieu.DonViTinh = d;
        DuLieu.SoLuongTon = s;
        Left = NULL;
        Right = NULL;
    }

    void ghiFile(ofstream& textFile) {
        textFile << DuLieu.MaVatTu << " " << DuLieu.TenVatTu << " " << DuLieu.DonViTinh << " " << DuLieu.SoLuongTon << "\n";
    }
};

class CayTimKiem {
public:
    Node* root;

    CayTimKiem() {
        root = NULL;
    }

    void insertNode(VatTu v) {
        root = insertNode(root, v.MaVatTu, v.TenVatTu, v.DonViTinh, v.SoLuongTon);
    }

    Node* insertNode(Node* p, int m, string t, string d, double s) {
        if (p == NULL) {
            return new Node(m, t, d, s);
        }
        if (m < p->DuLieu.MaVatTu)
            p->Left = insertNode(p->Left, m, t, d, s);
        else if (m > p->DuLieu.MaVatTu)
            p->Right = insertNode(p->Right, m, t, d, s);
        return p;
    }

    int createTree() {
        while (1) {
            VatTu v;
            if (v.nhapVatTu() == 0) {
                return 0;
            }
            else {
                insertNode(v);
            }
        }
    }

    void LNR(Node* p) {
        if (p != NULL) {
            LNR(p->Left);
            p->DuLieu.hienThi();
            LNR(p->Right);
        }
    }

    void LNR() {
        LNR(root);
        cout << endl;
    }

    void ghiFileLNR(Node* p, ofstream& textFile) {
        if (p != NULL) {
            ghiFileLNR(p->Left, textFile);
            p->ghiFile(textFile);
            ghiFileLNR(p->Right, textFile);
        }
    }

    void ghiFileLNR(string filename) {
        ofstream textFile("vatTu.txt");
        ghiFileLNR(root, textFile);
        textFile.close();
    }
};

void readVatTuFromFile(const string& fileName, CayTimKiem& t) {
    ifstream textFile(fileName);

    if (!textFile) {
        cerr << "Khong the mo tep van ban." << endl;
        return;
    }

    VatTu v;
    while (textFile >> v.MaVatTu >> v.TenVatTu >> v.DonViTinh >> v.SoLuongTon) {
        t.insertNode(v);
    }

    textFile.close();
}

int main() {
    CayTimKiem t;
    string f = "VatTu.txt";
    readVatTuFromFile(f, t);

    t.LNR();

    t.createTree();
    t.ghiFileLNR(f);

    cout << "Doc tu file sau khi ghi: " << endl;
    readVatTuFromFile(f, t);

    return 1;
}
