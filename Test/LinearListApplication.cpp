#include "../LinearList.h"
using namespace std;

SqList<int> A, B, C;

void DispMenu() {
    cout << "��������˳���Ӧ�á�������" << endl;
    cout << "  1.���ϲ�A=A��B" << endl;
    cout << "  2.˳�������" << endl;
    cout << "  3.����ʽ���" << endl;
    cout << "  4.����˳���" << endl;
    cout << "  0.�˳�" << endl;
}

void SetSqlist() {
    int n1, n2;
    cout << "������˳���A,B�ĳ��ȣ�";
    cin.sync(); //��ջ�����
    cin >> n1 >> n2;
    if (InitSqList(A, n1) && InitSqList(B, n2)) {
        cout << "˳���A,B��ʼ���ɹ���" << endl;
        cout << "������˳���A��Ԫ�ظ�����";
        CreateSqList(A, n1);
        cout << "������˳���B��Ԫ�ظ�����";
        CreateSqList(B, n2);
    } else {
        cerr << "˳���A,B��ʼ��ʧ�ܣ�" << endl;
        exit(1); // ��ʼ��ʧ�����˳�
    }
}


void Choice() {
    cout << "�����������ţ�";
    int choice;
    cin.sync();
    cin >> choice;
    system("CLS");
    DispMenu();

    switch (choice) {
        case 1:
            cout << "����ִ�м��ϲ�����...." << endl;
            Union(A,B);
            cout << "���ϲ������ɹ����ϲ���˳���" << endl;
            ListDisp(A);
            break;
        case 2:
            cout << "����ִ��˳������ò���...." << endl;
            cout << "����ǰ˳���" << endl;
            cout << "A: ";
            ListDisp(A);
            cout << "B: ";
            ListDisp(B);
            Reverse(A);
            Reverse(B);
            cout << "˳������ò����ɹ������ú�˳���" << endl;
            cout << "A: ";
            ListDisp(A);
            cout << "B: ";
            ListDisp(B);
            break;
        case 3:
            cout << "����ִ�ж���ʽ��Ͳ���...." << endl;
            PolyAdd(A, B, C);
            cout << "����ʽ��Ͳ����ɹ���" << endl;
            cout << "���Ϊ: ";
            ListDisp(C);
            break;
        case 4:
            cout << "��������˳���A,B,C" << endl;
            SetSqlist();
            break; // ���break����ֹfall-through
        case 0:
            cout << "�����˳�...." << endl;
            exit(0);
        default:
            cout << "������Ŵ���" << endl;
            break;
    }
}

int main(int argc, char *argv[]) {
    DispMenu();
    cout << "����˳���A,B" << endl;
    SetSqlist();
    while (true) {
        Choice();
    }
}
