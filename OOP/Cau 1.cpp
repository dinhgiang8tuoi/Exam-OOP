#include <iostream>
#include <iomanip>

using namespace std;

class thiSinh{
private:
    string id, hoten;
    float toan, ly, hoa;
public:
    thiSinh(): id(""), hoten(""), toan(0), ly(0), hoa(0){}
    thiSinh(string id, string hoten, float toan, float ly, float hoa): id(id), hoten(hoten), toan(toan), ly(ly), hoa(hoa){}
    
    void nhap(){
        cout << "ID: ";
        getline(cin >> ws, id);
        cout << "HoTen: ";
        getline(cin >> ws, hoten);
        cout << "Toan: ";
        cin >> toan;
        cout << "Ly: ";
        cin >> ly;
        cout << "Hoa: ";
        cin >> hoa;
    }
    void xuat(){
        cout << left << setw(23) << id << setw(23) << hoten << setw(13) << toan << setw(13) << ly << setw(13) << hoa << endl;
    }
    float tinhDiem(){
        return toan + ly + hoa;
    }
    string getName(){
        return hoten;
    }
};

void displayInfo(){
    cout << "----------------------------DANH SACH THI SINH-----------------------------" << endl;
    cout << left << setw(23) << "ID" << setw(23) << "Hoten" << setw(13) << "Toan" << setw(13) << "Ly" << setw(13) << "Hoa" << endl;
}

void listT(thiSinh *&T, int &n){
    cout << "So luong thi sinh: ";
    cin >> n;
    T = new thiSinh[n];

    for (int i = 0; i < n; i++){
        T[i].nhap();
    }
}

void topPoint(thiSinh *T, int n){
    int position = 0;
    float max = T[0].tinhDiem();
    for (int i = 1; i < n; i++){
        if (T[i].tinhDiem() > max){
            max = T[i].tinhDiem();
            position = i;
        }
    }
    cout << "Thi sinh co tong diem cao nhat: " << endl;
    T[position].xuat();
}

void sort(thiSinh *&T, int n){
    for (int i = 0; i < n-1; i++)
    for (int j = i + 1; j < n; j++){
        if (T[i].getName() < T[j].getName()) swap(T[i], T[j]);
    }
    
    cout << "DANH SACH THI SINH SAU KHI DA SAP XEP: " << endl;
    for (int i = 0 ; i < n; i++){
        T[i].xuat();
    }
}

int main(){
    int n;
    thiSinh *T = nullptr;
    
    listT(T, n);
    displayInfo();
    topPoint(T, n);
    sort(T, n);

delete[] T;
}