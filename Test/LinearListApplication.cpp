#include "../LinearList.h"
using namespace std;

SqList<int> A, B, C;

void DispMenu() {
    cout << "————顺序表应用————" << endl;
    cout << "  1.集合并A=A∪B" << endl;
    cout << "  2.顺序表逆置" << endl;
    cout << "  3.多项式求和" << endl;
    cout << "  4.重置顺序表" << endl;
    cout << "  0.退出" << endl;
}

void SetSqlist() {
    int n1, n2;
    cout << "请输入顺序表A,B的长度：";
    cin.sync(); //清空缓冲区
    cin >> n1 >> n2;
    if (InitSqList(A, n1) && InitSqList(B, n2)) {
        cout << "顺序表A,B初始化成功！" << endl;
        cout << "请输入顺序表A的元素个数：";
        CreateSqList(A, n1);
        cout << "请输入顺序表B的元素个数：";
        CreateSqList(B, n2);
    } else {
        cerr << "顺序表A,B初始化失败！" << endl;
        exit(1); // 初始化失败则退出
    }
}


void Choice() {
    cout << "请输入操作编号：";
    int choice;
    cin.sync();
    cin >> choice;
    system("CLS");
    DispMenu();

    switch (choice) {
        case 1:
            cout << "正在执行集合并操作...." << endl;
            Union(A,B);
            cout << "集合并操作成功！合并后顺序表：" << endl;
            ListDisp(A);
            break;
        case 2:
            cout << "正在执行顺序表逆置操作...." << endl;
            cout << "逆置前顺序表：" << endl;
            cout << "A: ";
            ListDisp(A);
            cout << "B: ";
            ListDisp(B);
            Reverse(A);
            Reverse(B);
            cout << "顺序表逆置操作成功！逆置后顺序表：" << endl;
            cout << "A: ";
            ListDisp(A);
            cout << "B: ";
            ListDisp(B);
            break;
        case 3:
            cout << "正在执行多项式求和操作...." << endl;
            PolyAdd(A, B, C);
            cout << "多项式求和操作成功！" << endl;
            cout << "结果为: ";
            ListDisp(C);
            break;
        case 4:
            cout << "正在重置顺序表A,B,C" << endl;
            SetSqlist();
            break; // 添加break，防止fall-through
        case 0:
            cout << "正在退出...." << endl;
            exit(0);
        default:
            cout << "操作编号错误！" << endl;
            break;
    }
}

int main(int argc, char *argv[]) {
    DispMenu();
    cout << "设置顺序表A,B" << endl;
    SetSqlist();
    while (true) {
        Choice();
    }
}
