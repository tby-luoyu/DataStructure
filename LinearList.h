#include <iostream>
using namespace std;
template<class DT>
struct SqList {
    DT *addr; //Data Array
    int length; //Data Length
    int size; //Data Size
};
//��ʼ��˳���
template<class  DT>
bool InitSqList(SqList<DT> &List,int size) {
    //���붯̬�ڴ�����
    List.addr = new DT[size];
    if (List.addr == NULL) { //����ʧ�ܣ��׳��쳣
        cerr<< "Memory allocation failed! failed to initialize SqList.�����ڴ�ʧ��"<<endl;
    }
    //��ʼ��˳�����Ϣ
    List.length = 0;
    List.size = size;
    return true;
}

//����˳���
template<class DT>
bool CreateSqList(SqList<DT> &list, int n) {
    //�жϴ���˳����Ƿ��к��ʵ��ڴ�ռ�
    if (n>list.size) {
        cerr<< "The length of the list is less than the number of elements to be inserted. �����ڴ�ʧ��"<<endl;
        return false;
    }
    //��˳����ڴ���Ԫ��
    cout<<"������˳���Ԫ�أ�";
    for (int i = 0; i < n; i++) {
         cin>>list.addr[i];
    }
    //����˳�����
    list.length = n;
    return true;
}

//����˳���
template<class DT>
void DestorySqList(SqList<DT> &list) {
    //�ͷŶ�̬�����ڴ�
    delete[] list.addr;
    //����˳�����Ϣ
    list.size =0;
    list.length =0;
}
//��λ�����
template<class DT>
bool GetElem_i(SqList<DT> list,int i, DT &e) {
    //�ж�λ���Ƿ�Ϸ�
    if(i<=0 || i>list.length) {
        cerr<<"��ѯ��ΧԽ��."<<endl;
    }else {
            e = list.addr[i-1];
            return true;
    }
    return false;
}
//��ֵ����
template<class DT>
int LocateElem_e(SqList<DT> list,DT e) {
    for (int i = 0; i < list.length; i++) {
        if(list.addr[i] == e) {
            return i;
        }
    }
    return -1;
}

//��λ�����Ԫ��
template<class DT>
bool InsertElem_i(SqList<DT> &List,int i,DT e) {
    if(List.length == List.size) {
        cout<<"˳�������"<<endl;
        return false;
    }
    if(i<0 || i>List.length+1) {
        cout<<"����λ�ò��Ϸ�"<<endl;
        return false;
    }
    //��i�����Ԫ�غ���һλ
    for(int j=List.length-1;j>i-1;j--) {
        List.addr[j+1]=List.addr[j];
    }
    List.addr[i]=e;
    List.length++;
    return true;
}
//��λ��ɾ��Ԫ��
template<class DT>
bool DeleteElem_i(SqList<DT> &List,int i) {
    if(List.length == 0) {
        cout<<"˳���Ϊ��"<<endl;
        return false;
    }
    if(i<0 || i>List.length) {
        cout<<"ɾ��λ�ò��Ϸ�"<<endl;
        return false;
    }
    for(;i<List.length-1;i++) {
        List.addr[i]=List.addr[i+1];
    }
    List.length--;
    return true;
}

//��λ���޸�Ԫ��ֵ
template<class DT>
bool PutElem_i(SqList<DT> &List,int i,DT e) {
    if(i<0 || i>List.length) {
        cout<<"Ԫ�ز�����"<<endl;
        return false;
    }
    List.addr[i] =e;
    return true;

}
//���˳���
template<class DT>
void ClearList(SqList<DT> &List) {
    List.length = 0;
}
//����
template<class DT>
bool ListEmpty(SqList<DT> List) {
    if(List.length == 0) {
        return true;
    }
    return false;
}
//���
template<class DT>
int ListLength(SqList<DT> List) {
    return List.length;
}
//�����
template<class DT>
bool ListFull(SqList<DT> List) {
    if(List.length == List.size) {
        return true;
    }
    return false;
}
//�������˳���
template<class DT>
void ListDisp(SqList<DT> List) {
    for(int i=0;i<List.length;i++) {
        cout<<List.addr[i]<<" ";
    }
    cout<<endl;
}
template<class DT>
void Union(SqList<DT> &A, SqList<DT> &B) {
    int n1 = A.size + B.size;
    if (A.size == 0 || B.size == 0) {
        cout << "˳������ڻ�δ����ռ�" << endl;
        return;
    }

    SqList<DT> newlist;
    InitSqList(newlist,n1);
    if (!newlist.addr) {
        cerr << "��˳����ʼ��ʧ�ܣ�" << endl;
        return;
    }
    for (int i = 0; i < A.size; i++) {
        InsertElem_i(newlist, i, A.addr[i]);
    }
    for (int i = 0; i < B.size; i++) {
        InsertElem_i(newlist, A.size + i, B.addr[i]);
    }
    A = newlist;
}

template<class DT>
void Reverse(SqList<DT> &List) {
    if (List.size == 0) {
        cout << "˳������ڻ�δ����ռ�" << endl;
        return;
    }

    for (int i = 0; i < List.size / 2; i++) {
        swap(List.addr[i], List.addr[List.size - i - 1]);
    }
}

template<class DT>
void PolyAdd(const SqList<DT> &la, const SqList<DT> &lb, SqList<DT> &lc) {
    int n1=max(la.size, lb.size);
    InitSqList(lc,n1);
    if (!lc.addr) {
        cerr << "���˳����ʼ��ʧ�ܣ�" << endl;
        return;
    }

    int maxSize = max(la.size, lb.size);
    for (int i = 0; i < maxSize; i++) {
        DT valueA = (i < la.size) ? la.addr[i] : 0;
        DT valueB = (i < lb.size) ? lb.addr[i] : 0;
        InsertElem_i(lc, i, valueA + valueB);
    }
}

//��ֵ����ǰ��
template<class DT>
bool PriorElem_e(SqList<DT> List,DT cur_e,DT &pre_e) {
    int i = LocateElem_e(List,cur_e);
    if(i==0||i==-1) {
        cout<<"Ԫ�ز����ڻ���û��ǰ��"<<endl;
        return false;
    }
    pre_e = List.addr[i-1];
    return true;
}