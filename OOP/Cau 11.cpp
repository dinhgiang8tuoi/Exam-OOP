#include <iostream>
#include <iomanip>

using namespace std;

class nhansu{
private:
    string id, hoten;
    int namsinh;
public:
    void nhap(){
        cout << "Id: ";
        getline(cin >> ws, id);
        cout << "Hoten: ";
        getline(cin >> ws, hoten);
        cout << "Namsinh: ";
        cin >> namsinh;
    }
    void xuat(){
        cout << left << setw(13) << id << setw(23) << hoten << setw(13) << namsinh;
    }
};
class congnhan :public nhansu{
private:
    int ngaycong;
public:
    void nhap(){
        nhansu::nhap();
        cout << "Ngaycong: ";
        cin >> ngaycong;
    }
    void xuat(){
        nhansu::xuat();
        cout << left << setw(13) << ngaycong;
    }
    friend void tienthuong(congnhan *cn, int n);
};

void tienthuong(congnhan *cn, int n){
    for (int i = 0; i < n; i++){
        if (cn[i].ngaycong > 26){
            cn[i].xuat();
            cout << left << setw(13) << (cn[i].ngaycong - 26) * 100000 << endl;
        }
    }
}

void listCN(congnhan *&cn, int &n){
    cout << "So luong cong nhan: ";
    cin >> n;
    cn = new congnhan[n];

    for (int i = 0; i < n; i++){
        cn[i].nhap();
    }
}

void displayInFo(){
    cout << "------------------------------DANH SACH CONG NHAN DUOC THUONG-------------------------------" << endl;
    cout << left << setw(13) << "Id" << setw(23) << "Hoten" << setw(13) << "Namsinh" << setw(13) << "Ngaycong" << setw(13) << "Tienthuong" << endl;
}

int main(){
    int n = 0;
    congnhan *cn = nullptr;

    listCN(cn, n);
    displayInFo();
    tienthuong(cn, n);
}