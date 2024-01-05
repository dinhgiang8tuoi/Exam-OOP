#include<iostream>
using namespace std;

class DaThuc {
private:
    int bac;
    int* heso;
public:
    DaThuc(): bac(0), heso(NULL){}
    DaThuc(int bac) {
        this->bac = bac;
        heso = new int[bac+1];
    }

    void nhap() {
        do{
        cout << "Nhap bac da thuc: ";
        cin >> bac;
        heso = new int[bac+1];
        } while (bac < 1);
        cout << "Nhap he so da thuc co bac tu cao den thap:\n";
        for(int i = bac; i >= 0; i--) {
            cin >> heso[i];
        }
    }

    void xuat() {
        for(int i = bac; i > 0; i--) {
            if (heso[i]== 0) continue;
            (heso[i] > 0)
                ? cout << "+" << heso[i] << "x^" << i << ' '
                : cout << heso[i] << "x^" << i << ' ';
        }
        (heso[0] > 0) 
            ? cout << "+" << heso[0]
            : cout << heso[0];
    }

    DaThuc operator+(DaThuc const &obj) {
        int maxBac = max(this->bac, obj.bac);
        DaThuc tong(maxBac);

        for(int i = 0; i <= maxBac; i++) {
            tong.heso[i] = (i <= this->bac ? this->heso[i] : 0) + (i <= obj.bac ? obj.heso[i] : 0);
        }

        return tong;
    }

    DaThuc operator-(DaThuc const &obj) {
        int maxBac = max(this->bac, obj.bac);
        DaThuc hieu(maxBac);

        for(int i = 0; i <= maxBac; i++) {
            hieu.heso[i] = (i <= this->bac ? this->heso[i] : 0) - (i <= obj.bac ? obj.heso[i] : 0);
        }

        return hieu;
    }
};

int main(){
    DaThuc a, b, c;
    a.nhap();
    
    b.nhap();
   
    c = a - b;
    c.xuat();



}