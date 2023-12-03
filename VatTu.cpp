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
            return new Node(m, t, d, s);
        }
        if (m < p->DuLieu.MaVatTu)
            p->Left = insertNode(p->Left, m, t, d, s);
        else if (m > p->DuLieu.MaVatTu)
            p->Right = insertNode(p->Right, m, t, d, s);
        return p;
    }

Node* CayTimKiem::insertNode(Node* p, VatTu v) {
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

void CayTimKiem::insertNode(VatTu v) {
      Node* p = insertNode(root, v);
        if (p == NULL)
            cout << "ma vat tu bi trung" << endl;
        else
            root = p;
    }
 Node* CayTimKiem::searchNode(Node* p, int ma_vt) {
        if (p == NULL)
            return NULL;
        if (ma_vt == p->DuLieu.MaVatTu)
            return p;
        else if (ma_vt < p->DuLieu.MaVatTu)
            return searchNode(p->Left, ma_vt);
        else if (ma_vt > p->DuLieu.MaVatTu)
            return searchNode(p->Right, ma_vt);
    }

    // Search for a node by MaVatTu value and display its information
    void CayTimKiem::searchNode(int ma_vt) {
        Node* p = searchNode(root, ma_vt);
        if (p == NULL)
            cout << "khong tim gap" << endl;
        else
            p->DuLieu.hienThi();
    }

    // Update information for a VatTu object in the tree
    void CayTimKiem::inputUpdateVatTu() {
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

    // Update information for a node in the tree
    void CayTimKiem::updateNode(int ma_vt, char* t, char* d, double sl) {
        Node* p = searchNode(root, ma_vt);
        if (p != NULL) {
            strcpy(p->DuLieu.TenVatTu, t);
            strcpy(p->DuLieu.DonViTinh, d);
            p->DuLieu.SoLuongTon = sl;
        } else
            cout << "ma vat tu khong ton tai" << endl;
    }

    // Delete a node with a specific MaVatTu value
    bool CayTimKiem::deleteNode(int ma_vt) {
        Node* p = deleteNode(root, ma_vt);
        if (p == NULL) {
            cout << "No VatTu found with ID " << ma_vt << endl;
            return false;
        }
        cout << "VatTu with ID " << ma_vt << " has been deleted." << endl;
        return true;
    }

    // Recursive function to delete a node with a specific MaVatTu value
    Node* CayTimKiem::deleteNode(Node* p, int ma_vt) {
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

    // Find the node with the smallest value in a subtree
    Node* CayTimKiem::minValueNode(Node* node) {
        Node* current = node;
        while (current->Left != NULL) {
            current = current->Left;
        }
        return current;
    }

    // Create a tree by continuously inputting VatTu objects until the user enters 0
    int CayTimKiem::createTree() {
        while (1) {
            VatTu v;
            if (v.nhapVatTu() == 0) {
                return 0;
            } else {
                insertNode(v);
            }
        }
    }

    // Create a tree by reading VatTu objects from a binary file
    int CayTimKiem::createTree(char* filename) {
        ifstream file_obj;
        file_obj.open(filename, ios::in | ios::binary);

        if (!file_obj) {
            cerr << "Error opening file for reading: " << filename << endl;
            return 0;
        }

        VatTu obj;

        while (file_obj.read((char*)&obj, sizeof(VatTu))) {
            insertNode(obj);
        }

        file_obj.close();

        return 1;
    }

    // In-order traversal of the tree and display information of each node
    void CayTimKiem::LNR(Node* p) {
        if (p != NULL) {
            LNR(p->Left);
            p->DuLieu.hienThi();
            LNR(p->Right);
        }
    }

    // Wrapper function for LNR traversal
    void CayTimKiem::LNR() {
        cout << "Duyet cay LNR \n";
        LNR(root);
        cout << endl;
    }

    // In-order traversal of the tree and write data to a binary file
    void CayTimKiem::ghiFileLNR(Node* p, std::ofstream& file) {
        if (p != NULL) {
            ghiFileLNR(p->Left, file);
            p->ghiDuLieu(file);
            ghiFileLNR(p->Right, file);
        }
    }

    // Wrapper function for writing tree data to a binary file
    void CayTimKiem::ghiFileLNR(std::ofstream& file) {
        ghiFileLNR(root, file);
    }
};
// het cay tim kiem
void readVatTuFromFile(char* filename) {
   ifstream inputFile(filename, ios::binary);

    if (!inputFile) {
        std::cerr << "Error opening the file for reading." << std::endl;
        return;
    }

    VatTu v;
    cout << "Thong tin vat tu: " << endl;
    while (inputFile.read(reinterpret_cast<char*>(&v), sizeof(VatTu))) {
        cout << "Ma vat tu: " << v.MaVatTu << "-Ten vat tu: " << v.TenVatTu
             << " -Don vi tinh: " << v.DonViTinh << " -So luong ton: " << v.SoLuongTon;
        cout << endl;
    }
    inputFile.close();
}


int docFileVatTu(char* filename) {
    ifstream file_obj;

    file_obj.open(filename, ios::in);

    VatTu obj;

    file_obj.read((char*)&obj, sizeof(obj));

    while (!file_obj.eof()) {
        cout << "Ma VT: " << obj.MaVatTu << "; Ten VT: " << obj.TenVatTu
             << "; Don vi tinh: " << obj.DonViTinh << "; So luong ton: " << obj.SoLuongTon << endl;
        file_obj.read((char*)&obj, sizeof(obj));
    }

    file_obj.close();

    return 0;
}


