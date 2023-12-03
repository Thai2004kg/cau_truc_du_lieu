#ifndef VATTU_H
#define VATTU_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#define maxlength 255

class VatTu {
public:
    int MaVatTu;
    char TenVatTu[maxlength];
    char DonViTinh[maxlength];
    double SoLuongTon;

    VatTu();
    VatTu(int m, char* t, char* d, double s);

    void hienThi();
    int nhapVatTu();
};

class Node {
public:
    VatTu DuLieu;
    Node* Left;
    Node* Right;

    Node(int m, char* t, char* d, double s);
    Node(VatTu v);
    void ghiDuLieu(std::ofstream& file);
};

class CayTimKiem {
public:
    Node* root;

    CayTimKiem();
    Node* insertNode(Node* p, int m, char* t, char* d, double s);
    Node* insertNode(Node* p, VatTu v);
    void insertNode(VatTu v);
    Node* searchNode(Node* p, int ma_vt);
    void searchNode(int ma_vt);
    void inputUpdateVatTu();
    void updateNode(int ma_vt, char* t, char* d, double sl);
    bool deleteNode(int ma_vt);
    Node* deleteNode(Node* p, int ma_vt);
    Node* minValueNode(Node* node);
    int createTree();
    int createTree(char* filename);
    void LNR(Node* p);
    void LNR();
    void ghiFileLNR(Node* p, std::ofstream& file);
    void ghiFileLNR(std::ofstream& file);
};

void readVatTuFromFile(char* filename);
int docFileVatTu(char* filename);

#endif 

