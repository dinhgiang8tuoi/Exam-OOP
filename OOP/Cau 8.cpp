#include <iostream>

using namespace std;

class maTran{
private:
    int hang, cot;
    int **arr;
public:
    void nhap(){
        cout << "Nhap lan luot so Hang, Cot: ";
        cin >> hang >> cot;
        arr = new int*[hang];
        for (int i = 0; i < hang; i++)
        arr[i] = new int[cot];

        for (int i = 0; i < hang; i++)
        for (int j = 0; j < cot; j++){
            cout << "Arr[" << i+1 << ", " << j+1 << "]: ";
            cin >> arr[i][j];
        }
    }
    void xuat(){
        for (int i = 0; i < hang; i++){
        for (int j = 0; j < cot; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
        }
    }
    friend void sum(maTran M);
    friend void huy(maTran M);
};

void sum(maTran M){
    int sum = 0;
    for (int i = 0; i < M.hang; i++)
    for (int j = 0; j < M.cot; j++){
        if (i == 0 || i == M.hang - 1 || j == 0 || j == M.cot -1 )
        sum += M.arr[i][j];
    }
    cout << "Tong phan tu tren 4 duong vien: " << sum << endl;
}

void huy(maTran M){
    for (int i = 0; i < M.hang; i++)
    delete [] M.arr[i];
    delete [] M.arr;
}
int main(){
    maTran M;
    M.nhap();
    M.xuat();
    sum(M);
    huy(M);
}