#include <iostream>

using namespace std;

int gcd(int a, int b){
    while (a != b){
        if (a > b)
            a = a -b;
        else b = b -a;
    }
    return a;
}

class PS1{
protected:
    int ts, ms;
public:
    void nhap(){
        do{
            cout << "TS: ";
            cin >> ts;
            cout << "MS: ";
            cin >> ms;
            if (ms < 0){
                ts = ts *-1;
                ms = ms *-1;
            }
        }while(ms == 0);
    }
    void xuat(){
        cout << "PS: " << ts << "/" << ms << endl;
    }
    void toigian(){
        int temp = gcd(abs(ts), ms);
        ts = ts / temp;
        ms = ms / temp;
    }
    int getTS(){
        return ts;
    }
    int getMS(){
        return ms;
    }
};
class PS2 :public PS1{
public:
    PS2 operator =(PS1 other){
        this->ts = other.getTS();
        this->ms = other.getMS();
        return *this;
    }
    bool operator <(PS2 other){
        return (this->ts *other.ms < this->ms * other.ts);
    }
};

void listPS2(PS2 *&ps, int &n){
    do{
        cout << "Nhap so luong phan so: ";
        cin >> n;
        ps = new PS2[n];
    }while(n > 10);

    for (int i = 0; i < n; i++){
        ps[i].nhap();
        ps[i].toigian();
    }
}

void findMaxMin(PS2 *ps, int n){
    PS2 max = ps[0];
    PS2 min = ps[0];

    for (int i =0; i < n; i++){
        if (ps[i] < min){
            min = ps[i];
        }else max = ps[i];
    }
    cout << "Min: ";
    min.xuat();
    cout << endl << "Max: ";
    max.xuat();
    cout << endl;
}

int main(){
    int n = 0;
    PS2 *ps = nullptr;

    listPS2(ps, n);
    findMaxMin(ps, n);


delete [] ps;
}