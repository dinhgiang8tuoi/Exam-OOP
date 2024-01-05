#include <iostream>
#include <cmath>

using namespace std;

class SP1{
protected:
    float thuc, ao;
public:
    SP1(): thuc(0), ao(0) {}
    SP1(float thuc, float ao): thuc(thuc), ao(ao) {}

    void nhap(){
        cout << "Thuc: ";
        cin >> thuc;
        cout << "Ao: ";
        cin >> ao;
    }
    void xuat(){
        if (ao > 0)
            cout << thuc << " + " << ao << "i" << endl;
        else cout << thuc << " " << ao << "i" << endl;
    }
    float module(){
        return sqrt(pow(thuc, 2) + pow(ao ,2));
    }
    float getThuc(){
        return thuc;
    }
    float getAo(){
        return ao;
    }
};
class SP2 :public SP1{
public:
    SP2 operator =(SP1 other){
        this->thuc = other.getThuc();
        this->ao = other.getAo();
        return *this;
    }
    bool operator >(SP2 other){
        return (this->module() > other.module());
    }
};

void listSP2(SP2 *&sp, int &n){
    do{
        cout << "So luong SP: ";
        cin >> n;
        sp = new SP2[n];
    }while (n > 10);

    for (int i = 0; i < n; i++){
        sp[i].nhap();
    }
}
void sort(SP2 *&sp, int n){
    for (int i = 0; i < n-1; i++)
    for (int j = i + 1; j < n; j++){
        if (sp[j] > sp[i]) swap(sp[i], sp[j]);
    }
}

void print(SP2 *sp, int n){
    cout << "Sorted: " << endl;
    for (int i =0; i< n; i++){
        sp[i].xuat();
    }
}

int main(){
    int n = 0;
    SP2 *sp = nullptr;

    listSP2(sp, n);
    sort(sp, n);
    print(sp , n);
   
delete [] sp;
}