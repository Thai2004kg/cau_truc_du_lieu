 CayTimKiem readFromFileByMa(const std::string& filename) {
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

        char* t = const_cast<char*>(ten.c_str());//doi kieu string sang mang char
        char* d = const_cast<char*>(dvt.c_str());
        VatTu v(mavt,t,d,soluong);
        cayVatTu.insertNode(v);
    }

    inFile.close();

    return cayVatTu;
}

 void ghiFileLNR(char* filename) {
    	ofstream file(filename,ios::out);
        ghiFileLNR(root, file);
        file.close();
    }
    
void ghiFileLNR(Node* p, std::ofstream& file) {
        if (p != NULL) {
            ghiFileLNR(p->Left, file);
           // p->ghiDuLieu(file);
            file<<p->DuLieu.MaVatTu<<","<<p->DuLieu.TenVatTu<<","<<p->DuLieu.DonViTinh<<","<<p->DuLieu.SoLuongTon<<endl;
            ghiFileLNR(p->Right, file);
        }
    }
    
