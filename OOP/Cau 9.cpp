#include <iostream>
#include <iomanip>

using namespace std;

class nhanVien{
private:
    string hoten, chucvu, gioitinh, quequan;
    int namsinh, namvaolam;
public:
    friend istream &operator >>(istream &is, nhanVien &p){
        cout << "Hoten: ";
        getline(is >> ws, p.hoten);
        cout << "Chuc vu: ";
        getline(is >> ws, p.chucvu);
        cout << "Gioi tinh: ";
        getline(is >> ws, p.gioitinh);
        cout << "Nam sinh: ";
        is >> p.namsinh;
        cout << "Que quan: ";
        getline(is >> ws, p.quequan);
        cout << "Nam vao lam: ";
        is >> p.namvaolam;

    return is;
    }
    friend ostream &operator << (ostream &os, nhanVien p){
        os << left << setw(23) << p.hoten << setw(13) << p.chucvu << setw(13) << p.gioitinh << setw(13) << p.namsinh << setw(13) << p.quequan << setw(13) << p.namvaolam;
        return os;
    }
    int getNamvaolam(){
        return namvaolam;
    }
};  

void listNV(nhanVien *&nv, int &n){
    cout << "So luong nhan vien: ";
    cin >> n;
    nv = new nhanVien[n];

    for (int i = 0; i < n; i++){
        cout << "Thong tin nv " << i+1 << ": " << endl;
        cin >> nv[i];
    }       
}

void displayInfo(){
    cout << "---------------------DANH SACH NHAN VIEN-----------------------" << endl;
    cout << left << setw(23) << "HoTen" << setw(13) << "ChucVu" << setw(13) << "GIoiTinh" << setw(13) << "NamSinh" << setw(13) << "QueQuan" << setw(13) << "NamVaoLAm" << setw(13) << "NamLamViec" << endl;
}

void tren20Nam(nhanVien *nv, int n){
    for (int i = 0; i < n; i++){
        if (2023 - nv[i].getNamvaolam() > 20){
            cout << nv[i];
            cout << left << setw(13) << 2023 - nv[i].getNamvaolam();
            cout << endl;
        }
    }
}

int main(){
    int n = 0;
    nhanVien *nv = nullptr;
    
    listNV(nv, n);
    displayInfo();
    tren20Nam(nv, n);
}