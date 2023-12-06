#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class person{
private:
    string name;
    int birthY;
public:
    person(): name(" "), birthY(0){}
    person(string name, int birthY): name(name), birthY(birthY){}

    void inPut(){
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Birth: ";
        cin >> birthY;
    }
    void outPut(){
        cout << left << setw(17) << name << setw(13) << birthY;
    }
    string getName(){
        return name;
    }
};
class MH{
private:
    string nameMH;
    float CC, KT, DT;
public:
    MH(): nameMH(" "), CC(0), KT(0), DT(0){}
    MH(string nameMH, float CC, float KT, float DT): nameMH(nameMH), CC(CC), KT(KT), DT(DT){}

    void inPut(){
        cout << "NameMH: ";
        cin.ignore();
        getline(cin, nameMH);
        cout << "Point CC: ";
        cin >> CC;
        cout << "Point KT: ";
        cin >> KT;
        cout << "Point DT: ";
        cin >> DT;
    }
    void outPut(){
        cout << left << setw(17) << nameMH << setw(13) << CC << setw(13) << KT << setw(13) << DT;
    }
    float getCC(){
        return CC;
    }
    float getKT(){
        return KT;
    }
    float getDT(){
        return DT;
    }
};
class students :public person, public MH{
private:
    string id;
    float gpa;
public:
    students(): id(" "), gpa(0){}
    students(string name, int birthY, string nameMH, float CC, float KT, float DT, string id, float gpa): person(name, birthY), MH(nameMH, CC, KT, DT), id(id), gpa(gpa){}
    void inPut(){
        person::inPut();
        MH::inPut();
        cout << "Id: ";
        cin.ignore();
        getline(cin, id);
        cout << "GPA: ";
        cin >> gpa;
    }
    void outPut(){
        person::outPut();
        MH::outPut();
        cout << left << setw(13) << id << setw(13) << gpa << endl;
    }
    float getGPA(){
        return gpa;
    }
    string getID(){
        return id;
    }
};
class listStudents :public students{
private:
    int size;
    students *student = NULL;
public:
    listStudents(){
        cout << "Enter number of students: ";
        cin >> size;
        //cin.ignore();
        student = new students[size];
        for (int i=0; i<size; i++){
            cout << "Enter infomation student " << i+1 << ": " << endl;
            student[i].inPut();
        }
    }
    ~listStudents(){
        delete [] student;
    }
    void find(){
        cout << "Enter id or name to search: ";
        string search;
        cin.ignore();
        getline(cin, search);
        displayInfo("Finded");
        bool kt = false;
        for (int i=0; i<size; i++){
            if (student[i].getID() == search || student[i].getName() == search){
            student[i].outPut();
            kt = true;
            } 
        if (!kt) cout << "Not Found" << endl;
        }
    }
    void topRank(){
        float result = student[0].getCC() + student[0].getKT() + student[0].getDT();
        int postion = 0;
        for (int i=1; i<size; i++){
            float temp = student[i].getCC() + student[i].getKT() + student[i].getDT();
            if (temp > result){
                result = temp;
                postion = i;
            }
        }
        if (size > 0){
            displayInfo("TopRank");
            student[postion].outPut();
        }else cout << "Not Found" << endl;  
    }
    void banned(){
        //cout << "-------------------------------------------------------------List Banned-------------------------------------------------------------------" << endl;
        displayInfo("Banned");
        for (int i=0; i<size; i++){
            if (student[i].getCC() < 5 || student[i].getKT() == 0)
            student[i].outPut();
        }
    }
    void sort(){
        for (int i=0; i<size; i++)
        for (int j=i+1; j<size; j++){
            if (student[i].getGPA() < student[j].getGPA()) 
            swap(student[i], student[j]);
        }
    }
    void printf(){
        for (int i=0; i<size; i++){
            student[i].outPut();
        }
    }
    void displayInfo(string s){
    cout << "----------------------------------------------List " + s <<  "-------------------------------------------------" << endl;
    cout << left << setw(17) << "NAME" << setw(13) << "BirthYear" << setw(17) << "NAMEMH" << setw(13) << "CC" << setw(13) << "KT" << setw(13) << "DT" << setw(13) << "ID" << setw(13) << "GPA" << endl;
    }
};


int main(){
    listStudents L;
    L.displayInfo("Students");
    L.sort();
    L.printf();
    L.banned();
    L.find();
    L.topRank();
}