#include <iostream>

using namespace std;

class matran{
private:
    int bac;
    int **arr;
public:
    
    void nhap(){
        cout << "Bac cua ma tran: ";
        cin >> bac;
        arr = new int*[bac];
        for (int i = 0; i < bac; i++){
            arr[i] = new int[bac];
        }

        for (int i = 0; i < bac; i++)
        for (int j = 0; j < bac; j++){
            cout << "arr[" << i+1 << ", " << j+1 << "]: ";
            cin >> arr[i][j];
        }
    }
    void xuat(){
        for (int i = 0; i < bac; i++){
            for (int j = 0; j < bac; j++){
                cout << arr[i][i] << " ";
            }
            cout << endl;
        }
    }
    friend int cheochinh(matran M);
    friend int cheophu(matran M);
    friend void destroy(matran M);
};

int cheochinh(matran M){
    int sum = 0;
    for (int i = 0; i < M.bac; i++){
        sum += M.arr[i][i];
    }
    return sum;
}
int cheophu(matran M){
    int sum = 0;
    for (int i = 0; i < M.bac; i++){
        sum += M.arr[i][M.bac - i - 1];
    }
    return sum;
}

void destroy(matran M){
    for (int i = 0; i < M.bac; i++){
        delete [] M.arr[i];
    }
    delete [] M.arr;
}
int main(){
    matran M;
    M.nhap();
    M.xuat();
    cout << cheochinh(M) << endl;
    cout << cheophu(M) << endl;
    destroy(M);
}