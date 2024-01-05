#include <iostream>
#include <iomanip>

using namespace std;

class nguoi{
private:
    string hoten;
    int namsinh;
public:
    void nhap(){
        cout << "HoTen: ";
        getline(cin >> ws, hoten);
        cout << "NamSinh: ";
        cin >> namsinh;
    }
    void xuat(){
        cout << left << setw(23) << hoten << setw(13) << namsinh;
    }
};
class sinhVien :public nguoi{
private:
    string id;
    float gpa;
public:
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
    float getGPA(){
        return gpa;
    }
};

void listSV(sinhVien *&S, int &n){
    cout << "So luong sinh vien: ";
    cin >> n;
    S = new sinhVien[n];

    for (int i = 0 ; i < n; i++){
        S[i].nhap();
    }
}

void sort(sinhVien *&S, int n){
    for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++){
        if (S[i].getGPA() < S[j].getGPA()) 
        swap(S[i], S[j]);
    }
}
void printf(sinhVien *S, int n){
    for (int i = 0; i < n; i++){
        S[i].xuat();
    }
}
void displayInfo(){
    cout << "-------------------------------DANH SACH SINH VIEN-------------------------------------" << endl;
    cout << left << setw(23) << "HoTen" << setw(13) << "NamSinh" << setw(13) << "ID" << setw(13) << "GPA" << endl;
}

int main(){
    int n = 0;
    sinhVien *S = nullptr;

    listSV(S, n);
    displayInfo();
    sort(S, n);
    printf(S, n);



delete [] S;
}