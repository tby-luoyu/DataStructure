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
    cout<<endl;
    cout<<"-----------------------------"<<endl;
}

int main() {
    dispmenu();
    int choice;
    cin>>choice;
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

    }
    return 0;
}