#include "../LinearList.h"

using namespace std;

void dispmenu() {
    cout<<"---------˳�������˵�---------"<<endl;
    cout<<endl;
    cout<<"        1.��ʼ��˳���          "<<endl;
    cout<<"        2.����˳���           "<<endl;
    cout<<"        3.��ȡ��i��Ԫ��     "<<endl;
    cout<<"        4.��ֵ����Ԫ����λ      "<<endl;
    cout<<"        5.�����i��Ԫ��        "<<endl;
    cout<<"        6.ɾ����i��Ԫ��        "<<endl;
    cout<<"        7.�޸ĵ�i��Ԫ��        "<<endl;
    cout<<"        8.��ձ�              "<<endl;
    cout<<"        9.�����         "<<endl;
    cout<<"        10.����Ƿ�Ϊ��      "<<endl;
    cout<<"        11.����Ƿ�����           "<<endl;
    cout<<"        12.��ʾ��           "<<endl;
    cout<<"        13.��ֵ����ǰ��        "<<endl;
    cout<<"        0.�˳�                "<<endl;
    cout<<endl;
    cout<<"-----------------------------"<<endl;
}

void Choice(){
    int choice;
    cout<<"�����������ţ�";
    cin.sync();
    cin>>choice;
    system("CLS");
    dispmenu();
    SqList<int> list;
    switch (choice)
    {
    case 1:
        cout<<"����ִ�г�ʼ���������...."<<endl;
        cout<<"������˳����ȣ�";
        int n;
        cin>>n;
        if(InitSqList(list,n)) {
            cout<<"��ʼ������ɹ���"<<endl;
            break;
        }
        cerr<<"��ʼ������ʧ�ܣ�"<<endl;
        break;
    case 2:
        cout<<"����ִ�д���˳������...."<<endl;
        cout<<"�������ʼԪ��Ԫ�س��ȣ�"<<"(��ǰ˳���ռ�Ϊ"<<list.size<<")";
        int n1;
        cin>>n1;
        if(CreateSqList(list,n1)) {
            cout<<"����˳���ɹ���"<<endl;
            break;
        }
        cerr<<"����˳���ʧ�ܣ�"<<endl;
        break;
    case 3:
        cout<<"����ִ�л�ȡ��i��Ԫ�ز���...."<<endl;
        cout<<"������Ҫ��ȡ��λ�ã�";
        int i;
        cin>>i;
        int e;
        if(GetElem_i(list,i,e)) {
            cout<<"��ȡ�ɹ���"<<endl;
            cout<<"��ȡԪ��Ϊ��"<<e<<endl;
            break;
        }
        break;
    case 4:
        cout<<"����ִ�а�ֵ����Ԫ����λ����...."<<endl;
        cout<<"������Ҫ���ҵ�Ԫ�أ�";
        int e1;
        cin>>e1;
        if(LocateElem_e(list,e1)!=-1) {
            cout<<"���ҳɹ���"<<endl;
            cout<<"Ԫ��λ��Ϊ��"<<LocateElem_e(list,e1)<<endl;
            break;
        }
        cout<<"Ԫ�ز����ڣ�"<<endl;
        break;    
    case 5:
        cout<<"����ִ�в����i��Ԫ�ز���...."<<endl;
        cout<<"Ŀǰ˳���";
        ListDisp(list);
        cout<<"���������λ����Ԫ��ֵ��";
        int i1,e2;
        cin>>i1>>e2;
        if(InsertElem_i(list,i1,e2)) {
            cout<<"����ɹ���"<<endl;
            cout<<"�����˳���";
            ListDisp(list);
            break;
        }
        cerr<<"����ʧ�ܣ�"<<endl;
        break;        
    case 6:
        cout<<"����ִ��ɾ����i��Ԫ�ز���...."<<endl;
        cout<<"Ŀǰ˳���";
        ListDisp(list);
        cout<<"������ɾ��λ�ã�";
        int i2;
        cin>>i2;
        if(DeleteElem_i(list,i2)) {
            cout<<"ɾ���ɹ���"<<endl;
            cout<<"ɾ����˳���";
            ListDisp(list);
            break;
        }
        cerr<<"ɾ��ʧ�ܣ�"<<endl;       
        break; 
    case 7:
        cout<<"����ִ���޸ĵ�i��Ԫ�ز���...."<<endl;
        cout<<"Ŀǰ˳���";
        ListDisp(list);
        cout<<"�������޸�λ����Ԫ��ֵ��";
        int i3,e3;
        cin>>i3>>e3;
        if(PutElem_i(list,i3,e3)) {
            cout<<"�޸ĳɹ���"<<endl;
            cout<<"�޸ĺ�˳���";
            ListDisp(list);
            break;
        }
        cerr<<"�޸�ʧ�ܣ�"<<endl;
        break;
    case 8:
        cout<<"����ִ����ձ����...."<<endl;
        ClearList(list);
        cout<<"��ձ�ɹ���"<<endl;
        break;
    case 9:
        cout<<"����ִ�в���Ȳ���...."<<endl;
        cout<<"��ǰ˳�����Ϊ��"<<ListLength(list)<<endl;
        break;
    case 10:
        cout<<"����ִ�в���Ƿ�Ϊ�ղ���...."<<endl;
        if(ListEmpty(list)) {
            cout<<"˳���Ϊ�գ�"<<endl;
            break;
        }
        cout<<"˳���Ϊ�գ�"<<endl;
        break;
    case 11:
        cout<<"����ִ�в���Ƿ���������...."<<endl;
        if(ListFull(list)) {
            cout<<"˳���������"<<endl;
            break;
        }
        cout<<"˳���δ����"<<endl;
        break;
    case 12:
        cout<<"����ִ����ʾ�����...."<<endl;
        ListDisp(list);
        break;
    case 13:
        cout<<"����ִ�а�ֵ����ǰ������...."<<endl;
        cout<<"������Ҫ���ҵ�Ԫ�أ�";
        int e4,v;
        cin>>e4;
        if(PriorElem_e(list,e4,v)) {
            cout<<"���ҳɹ���"<<endl;
            cout<<"ǰ��Ԫ��Ϊ��"<<v<<endl;
            break;
        }   
        cout<<"Ԫ�ز����ڣ�"<<endl;
        break;
    case 0:
        cout<<"�����˳�......"<<endl;
        exit(0);                                                                  
    default:
        break;
    }

}
int main(int argc, char const *argv[])
{
    dispmenu();
    while (1)
    {
        Choice();
    }
    return 0;
}