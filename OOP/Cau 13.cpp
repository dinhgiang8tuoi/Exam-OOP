#include <iostream>

using namespace std;

class matran{
private:
    int hang, cot;
    int **arr;
public:
    void nhap(){
        cout << "Hang: ";
        cin >> hang;
        cout << "Cot: ";
        cin >> cot;
        arr = new int*[hang];
        for (int i = 0; i < hang; i++){
            arr[i] = new int[cot];
        }

        for (int i = 0; i < hang; i++)
        for (int j = 0; j < cot; j++){
            cout << "Arr[" << i+1 << ", " << j+1 << "]: ";
            cin >> arr[i][j];
        }
    }
    void xuat(){
        for (int i =0; i < hang; i++)
        for (int j =0; j < cot; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    friend matran operator+(matran other);
};

matran operator+(matran other){
    m
}

int main(){
    matran a,b;
    a.nhap();
    b.nhap();

}