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
class canbo :public nhansu{
private:
    int luongcoban;
    float hesoluong;
public:
    void nhap(){
        nhansu::nhap();
        cout << "Luong co ban: ";
        cin >> luongcoban;
        cout << "Hesoluong: ";
        cin >> hesoluong;
    }
    void xuat(){
        nhansu::xuat();
        cout << left << setw(13) << luongcoban << setw(13) << hesoluong;
    }
    friend void sort(canbo *&cb, int n);
    friend int calcu(canbo *cb, int index);
};

int calcu(canbo *cb, int index){
    return cb[index].hesoluong* cb[index].luongcoban;
}

void sort(canbo *&cb, int n){
    for (int i = 0; i < n-1; i++){
        for (int j = i + 1; j < n; j++){
            if(calcu(cb, i) < calcu(cb, j)) 
                swap(cb[i], cb[j]);
        }
    }
}

void listCB(canbo *&cb, int &n){
    cout << "So luong can bo: ";
    cin >> n;
    cb = new canbo[n];

    for (int i = 0; i < n; i++){
        cb[i].nhap();
    }
}
void displayInfo(){
    cout << "-----------------------------DANH SACH CAN BO---------------------------" << endl;
    cout << left << setw(13) << "Id" << setw(23) << "Hoten" << setw(13) << "Namsinh" << setw(13) << "Luongcoban" << setw(13) << "Hesoluong" << setw(13) << "Luong" << endl;
}

void port(canbo *cb, int n){
    for (int i = 0; i < n; i++){
        cb[i].xuat();
        cout << left << setw(13) << calcu(cb, i) << endl;
    }
}

int main(){
    int n = 0;
    canbo *cb = nullptr;
    
    listCB(cb, n);
    sort(cb ,n);
    displayInfo();
    port(cb, n);

}