#include <iostream>
#include <iomanip>


using namespace std;

class canbo{
private:
    string macanbo, madonvi, hoten;
    int namsinh;
public:
    void nhap(){
        cout << "Macanbo: ";
        getline(cin >> ws, macanbo);
        cout << "Madonvi: ";
        getline(cin >> ws, madonvi);
        cout << "Hoten: ";
        getline(cin >> ws, hoten);
        cout << "Namsinh: ";
        cin >> namsinh;
    }
    void xuat(){
        cout << left << setw(13) << macanbo << setw(13) << madonvi << setw(23) << hoten << setw(13) << namsinh;
    }
};
class luong :public canbo{
private:
    int phucap, baohiem;
    float hesoluong;
public:
    void nhap(){
        canbo::nhap();
        cout << "Phucap: ";
        cin >> phucap;
        cout << "Baohiem: ";
        cin >> baohiem;
        cout << "HeSoLuong: ";
        cin >> hesoluong;
    }
    void xuat(){
        canbo::xuat();
        cout << left << setw(13) << phucap << setw(13) << baohiem << setw(13)<< hesoluong;
    }
    friend void luong(canbo *cb, int n);
};

void listCB(canbo *&cb, int &n){
    cout << "SoLuongCanBo: ";
    cin >> n;
    cb = new canbo[n];

    for (int i = 0; i < n; i ++){
        cb[i].nhap();
    }
}

void tinhluong(canbo *cb, int n){
    int luong = 0;
    for (int i = 0; i < n; i++){
        luong = cb[i].hesoluong *290000 + cb[i].phucap - cb[i].baohiem;
        cb[i].xuat();
        cout << left << setw(13) << luong << endl;
    }
}

int main(){
    int n = 0;
    canbo *cb = nullptr;

    listCB(cb, n);
    tinhluong(cb, n);
}