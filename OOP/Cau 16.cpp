#include <iostream>

using namespace std;

class hinhvuong{
protected:
    int a;
public:
    void nhap(){
        cout << "Nhap canh a: ";
        cin >> a;
    }
    void xuat(){
        cout << "Canh a: " << a << endl;
    }
    int dientichhv(){
        return a *a;
    }
    int chuvihv(){
        return 4 *a;
    }
};
class hcn :public hinhvuong{
private:    
    int b;
public:
    void nhap(){
        hinhvuong::nhap();
        cout << "Canh b: ";
        cin >> b;
    }
    void xuat(){
        hinhvuong::xuat();
        cout << "Canh b: " << b << endl;
    }
    int dientichhcn(){
        return hinhvuong::a *b;
    }
    int chuvihcn(){
        return (hinhvuong::a+ b)*2;
    }
};

void listHCN(hcn *&hn, int &n){
    cout << "So luong hinh vuong: ";
    cin >> n;
    hn = new hcn[n];

    for (int i = 0; i < n; i++){
        hn[i].nhap();
    }
}

void bigMax(hcn *hn, int n){
    int max = hn[0].dientichhv();
    int postition = 0;
    for (int i = 1; i < n; i++){
        if (hn[i].dientichhv() > max){
            max = hn[i].dientichhv();
            postition = i;
        }
    }
    cout << "Hinh vuong lon nhat: " ; << endl;
    hn[postition].xuat();
    cout << endl;
    cout << "Vi tri: " << postition << endl;
}

int main(){
    int n = 0;
    hcn *hn = nullptr;

    listHCN(hn, n);
    bigMax(hn, n);
}