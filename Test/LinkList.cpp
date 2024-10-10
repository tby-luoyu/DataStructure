#include "../LinkList.h"
using namespace std;

void dispmenu() {
    cout<<"---------����������˵�---------"<<endl;
    cout<<endl;
    cout<<"        1.��ʼ������           "<<endl;
    cout<<"        2.β�巨����������      "<<endl;
    cout<<"        3.ͷ�巨����������      "<<endl;
    cout<<"        4.��ȡ��i���ڵ�Ԫ��     "<<endl;
    cout<<"        5.��ֵ����Ԫ����λ      "<<endl;
    cout<<"        6.�����i��Ԫ��        "<<endl;
    cout<<"        7.ɾ����i��Ԫ��        "<<endl;
    cout<<"        8.�޸ĵ�i��Ԫ��        "<<endl;
    cout<<"        9.�������            "<<endl;
    cout<<"        10.��������         "<<endl;
    cout<<"        11.�������Ƿ�Ϊ��      "<<endl;
    cout<<"        12.�������           "<<endl;
    cout<<"        13.��ֵ����ǰ��        "<<endl;
    cout<<"        0.�˳�                "<<endl;
    cout<<endl;
    cout<<"-----------------------------"<<endl;
}
void Choice() {
    int choice;
    cout<<"�����������ţ�";
    cin>>choice;
    system("CLS");
    dispmenu();
    LNode<int> *list;
    switch (choice) {
        case 1:
            cout<<"����ִ�г�ʼ���������...."<<endl;
            if(InitLinkList(list)) {
                cout<<"��ʼ������ɹ���"<<endl;
                break;
            }
            cerr<<"��ʼ������ʧ�ܣ�"<<endl;
            break;
        case 2:
            cout<<"����ִ��β�巨�������������...."<<endl;
            int num;
            cout<<"����������Ԫ�ظ�����";
            cin>>num;
            if(CreateLinkList_Tail(list, num)) {
                cout<<"��������ɹ���"<<endl;
                break;
            }
            cerr<<"��������ʧ�ܣ�"<<endl;
            break;
        case 3:
            cout<<"����ִ��ͷ�巨�������������...."<<endl;
            int num1;
            cout<<"����������Ԫ�ظ�����";
            cin>>num1;
            if(CreateLinkList_Head(list, num1)) {
                cout<<"��������ɹ���"<<endl;
                break;
            }
            cerr<<"��������ʧ�ܣ�"<<endl;
            break;
        case 4:
            cout<<"����ִ�л�ȡ��i���ڵ�Ԫ�ز���...."<<endl;
            int i,e;
            cout<<"������Ҫ��ȡ�Ľڵ�λ�ã�";
            cin>>i;
            if(GetElem_i(list, i,e)) {
                cout<<"��"<<i<<"���ڵ�Ԫ��Ϊ��"<<e<<endl;
                break;
            }
            cerr<<"��ȡ��"<<i<<"���ڵ�Ԫ��ʧ�ܣ�"<<endl;
            break;
        case 5:
            cout<<"����ִ�а�ֵ����Ԫ����λ����...."<<endl;
            int value;
            cout<<"���������Ԫ�أ�";
            cin>>value;
            if(LocateElem_e(list, value)!=-1) {
                cout<<"Ԫ���ڵ�"<<LocateElem_e(list, value)<<"��λ��"<<endl;
                break;
            }
            cout<<"Ԫ�ز����ڣ�"<<endl;
            break;
        case  6:
            cout<<"����ִ�в����i��Ԫ�ز���...."<<endl;
            cout<<"Ŀǰ����";
            ListDisp(list);
            int i1,e1;
            cout<<"������Ҫ�����λ������ֵ��";
            cin>>i1>>e1;
            if(InsertElem_i(list, i1, e1)) {
                cout<<"����ɹ���"<<endl;
                cout<<"���������";
                ListDisp(list);
                break;
            }
            cerr<<"����ʧ�ܣ�"<<endl;
            break;
        case 7:
            cout<<"����ִ��ɾ����i��Ԫ�ز���...."<<endl;
            cout<<"Ŀǰ����";
            ListDisp(list);
            int i2;
            cin>>i2;
            if(DeleteElem_i(list, i2)) {
                cout<<"ɾ���ɹ���"<<endl;
                cout<<"ɾ��������";
                ListDisp(list);
                break;
            }
            cerr<<"ɾ��ʧ�ܣ�"<<endl;
            break;
        case 8:
            cout<<"����ִ���޸ĵ�i��Ԫ�ز���...."<<endl;
            cout<<"Ŀǰ����";
            ListDisp(list);
            int i3,e3;
            cout<<"������Ҫ�޸ĵ�λ������ֵ��";
            cin>>i3>>e3;
            if(PutElem_i(list, i3, e3)) {
                cout<<"�޸ĳɹ���"<<endl;
                cout<<"�޸ĺ�����";
                ListDisp(list);
                break;
            }
            cerr<<"�޸�ʧ�ܣ�"<<endl;
            break;
        case 9:
            cout<<"����ִ������������...."<<endl;
            if(ClearList(list)) {
                cout<<"�������ɹ���"<<endl;
                break;
            }
            cerr<<"�������ʧ�ܣ�"<<endl;
            break;
        case 10:
            cout<<"����ִ�в������Ȳ���...."<<endl;
            cout<<"������Ϊ��"<<ListLength(list)<<endl;
            break;
        case 11:
            cout<<"����ִ�в������Ƿ�Ϊ�ղ���...."<<endl;
            if(IsEmpty(list)) {
                cout<<"����Ϊ�գ�"<<endl;
                break;
            }
            cout<<"����Ϊ�գ�"<<endl;
            break;
        case 12:
            cout<<"����ִ�б����������...."<<endl;
            ListDisp(list);
            break;
        case 13:
            cout<<"����ִ�а�ֵ����ǰ������...."<<endl;
            int value1,V;
            cout<<"���������Ԫ�أ�";
            cin>>value1;
            if(LocatePrev_e(list, value1, V)) {
                cout<<"ǰ��Ԫ��Ϊ��"<<V<<endl;
                break;
            }
            cout<<"û��ǰ��Ԫ�أ�"<<endl;
            break;
        case 14:
            dispmenu();
            break;
        case 0:
            cout<<"�����˳�...."<<endl;
            exit(0);
        default:
            cout<<"�������"<<endl;
    }
}
int main() {
    dispmenu();
    while (true) {
        Choice();
    }
}