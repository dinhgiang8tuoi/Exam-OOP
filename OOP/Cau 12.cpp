#include <iostream>
#include <iomanip>

using namespace std;

class monhoc{
private:
    string monhoc;
    float chuyencan, kiemtra, diemthi;
public:
    void nhap(){
        cout << "Monhoc: ";
        getline(cin >> ws, monhoc);
        cout << "Chuyencan: ";
        cin >> chuyencan;
        cout << "Kiemtra: ";
        cin >> kiemtra;
        cout << "Diemthi: ";
        cin >> diemthi;
    }
    void xuat(){
        cout << left << setw(23) << monhoc << setw(13) << chuyencan << setw(13) << kiemtra << setw(13) << diemthi << endl;
    }
    float getCC(){
        return chuyencan;
    }
    float getKT(){
        return kiemtra;
    }
    float getDT(){
        return diemthi;
    }
};
class sinhvien :public monhoc{
private:
    string hoten, lop, id;
public:
    void nhap(){
        cout << "Hoten: ";
        getline(cin >> ws, hoten);
        cout << "Lop: ";
        getline(cin >> ws, lop);
        cout << "Id: ";
        getline(cin >> ws, id);
        monhoc::nhap();
    }
    void xuat(){
        cout << left << setw(23) << hoten << setw(13) << lop << setw(13) << id;
        monhoc::xuat();
    }
    float calcuP(){
        return monhoc::getCC()* 0.1 + monhoc::getKT()* 0.3 + monhoc::getDT()* 0.6;
    }
    friend void banned(sinhvien *sv, int n);
};

void listSV(sinhvien *&sv, int &n){
    cout << "So luong sinh vien: ";
    cin >> n;
    sv = new sinhvien[n];

    for (int i = 0; i < n; i ++){
        sv[i].nhap();
    }
}

void displayInfo(){
    cout << "--------------------------------DANH SACH SINH VIEN BI CAM THI-----------------------------------" << endl;
    cout << left << setw(23) << "Hoten" << setw(13) << "Lop" << setw(13) << "Id" << setw(13) << "Chuyencan" << setw(13) << "Kiemtra" << setw(13) << "Diemthi" << endl;
}

void banned(sinhvien *sv, int n){
    for (int i = 0; i < n; i++){
        if (sv[i].getCC() < 5 || sv[i].getKT() == 0){
            sv[i].xuat();
        }
    }
}

int main(){
    int n = 0;
    sinhvien *sv = nullptr;

    listSV(sv, n);
    displayInfo();
    banned(sv ,n);

return 0;
}