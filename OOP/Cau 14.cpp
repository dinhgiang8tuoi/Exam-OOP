#include <iostream>
#include <iomanip>

using namespace std;

class nguoi{
private:
    string hoten, namsinh;
public:
    void nhap(){
        cout << "Hoten: ";
        getline(cin >> ws, hoten);
        cout << "Namsinh: ";
        cin >> namsinh;
    }
    void xuat(){
        cout << left << setw(23) << hoten << setw(13) << namsinh;
    }
};
class giangvien :public nguoi{
private:
    string bomoncongtac, bomongiangday;
public:
    void nhap(){
        nguoi::nhap();
        cout << "BoMonCongTac: ";
        getline(cin >> ws, bomoncongtac);
        cout << "BoMonGiangDay: ";
        getline(cin >> ws, bomongiangday);
    }
    void xuat(){
        nguoi::xuat();
        cout << left << setw(13) << bomoncongtac << setw(13) << bomongiangday << endl;
    }
    string getBomoncongtac(){
        return bomoncongtac;
    }
};

void listGV(giangvien *&gv, int &n){
    cout << "So luong giang vien: ";
    cin >> n;
    gv = new giangvien[n];

    for (int i = 0; i < n; i++){
        gv[i].nhap();
    }
}

void sort(giangvien *&gv, int n){
    for (int i = 0; i < n-1; i++)
    for (int j = i +1; j < n; j++){
        if (gv[i].getBomoncongtac() > gv[j].getBomoncongtac()) 
        swap(gv[i], gv[j]);
    }
}

void idk(giangvien *gv, int n){
    for (int i = 0; i < n; i++){
        gv[i].xuat();
    }
}

void displayInfo(){
    cout << "-----------------------------DANH SACH GIANG VIEN----------------------" << endl;
    cout << left << setw(23) << "Hoten" << setw(13) << "Namsinh" << setw(13) << "Bomoncongtac" << setw(13) << "Bomongiangday" << endl;
}

int main(){
    int n = 0;
    giangvien *gv = nullptr;

    listGV(gv ,n);
    sort(gv, n);
    displayInfo();
    idk(gv, n);

}