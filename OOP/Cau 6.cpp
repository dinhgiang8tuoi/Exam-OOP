#include <iostream>
#include <iomanip>

using namespace std;

class nguoi{
private:
    string hoten;
    int namsinh;
public:
    nguoi(): hoten(""), namsinh(0) {}
    nguoi(string hoten, int namsinh): hoten(hoten), namsinh(namsinh) {}

    void nhap(){
        cout << "HoTen: ";
        getline(cin >> ws, hoten);
        cout << "NamSinh: ";
        cin >> namsinh;
    }
    void xuat(){ 
        cout << left << setw(23) << hoten << setw(13) << namsinh;
    }
    string getHoten(){
        return hoten;
    }
};
class sinhVien :public nguoi{
private:
    string id;
    float gpa;
public:
    sinhVien(): nguoi(), id(""), gpa(0) {}
    sinhVien(string hoten, int namsinh, string id, float gpa): nguoi(), id(id), gpa(gpa) {}

    void nhap(){
        nguoi::nhap();
        cout << "ID: ";
        getline(cin >> ws, id);
        cout << "GPA: ";
        cin >> gpa;
    }
    void xuat(){
        nguoi::xuat();
        cout << left << setw(13) << id << setw(13) << gpa << endl;
    }
    string getID(){
        return id;
    }
};

void listSV(sinhVien *&S, int &n){
    cout << "So luong sinh vien: ";
    cin >> n;
    S = new sinhVien[n];

    for (int i = 0; i < n; i++){
        S[i].nhap();
    }
}

void displayInfo(){
    cout << "----------------------------------DANH SACH SINH VIEN---------------------------------" << endl;
    cout << left << setw(23) << "HoTen" << setw(13) << "Namsinh" << setw(13) << "ID" << setw(13) << "GPA" << endl;
}

void search(sinhVien *S, int n){
    string key = "";
    bool temp = false;
    displayInfo();
    cout << "Ho ten sinh vien or ID can tim kiem: ";
    getline(cin >> ws, key);
    for (int i = 0; i < n; i++){
        if (S[i].getHoten().compare(key) == 0 || S[i].getID().compare(key) == 0){
            S[i].xuat();
            temp = true;
        }
    }
    if (temp == false) cout << "NOT FOUND";
}

int main(){
    int n = 0;
    sinhVien *S = nullptr;

    listSV(S, n);
    search(S, n);

}