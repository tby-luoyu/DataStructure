#include <iostream>
using namespace std;
//����ṹ
template<class DT>
struct LNode {
    DT data; //�洢����
    LNode<DT> *next; //ָ����һ���ڵ��ָ��
};
//��ʼ������
template<class DT>
bool InitLinkList(LNode<DT> *&List) {
    //����ͷ����ڴ�
    List = new LNode<DT>;
    //�ж��ڴ��Ƿ�����ɹ�
    if(!List){cerr<<"Memory allocation failed! failed to initialize LinkList."<<endl;}
    List->next = NULL;
    return true;
}
//��������(β�巨)
template<class DT>
bool CreateLinkList_Tail(LNode<DT> *&List, int n ) {
    //����βָ��ָ��ͷ�ڵ�
    LNode<DT> *p = List;
    for(int i=0; i<n; i++) {
        //�����ڴ�
        LNode<DT> *q = new LNode<DT>;
        //�ж��ڴ��Ƿ�����ɹ�
        if(!q){cerr<<"Memory allocation failed! failed to create LinkList.��������ʧ���ڴ治��"<<endl; return false;}
        //��������
        cin>>q->data;
        p->next = q;
        q->next = NULL;
        p = q;
    }
    return true;
}
//��������(ͷ�巨)
template<class DT>
bool CreateLinkList_Head(LNode<DT> *&List, int n ) {
    //����βָ��ָ��ͷ�ڵ�
    LNode<DT> *p = List;
    for(int i=0; i<n; i++) {
        //�����ڴ�
        LNode<DT> *q = new LNode<DT>;
        //�ж��ڴ��Ƿ�����ɹ�
        if(!q){cerr<<"Memory allocation failed! failed to create LinkList.��������ʧ���ڴ治��"<<endl; return false;}
        //��������
        cin>>q->data;
        p->next = q;
        p = q;
        p->next = NULL;
    }
    return true;
}


//��������
template<class DT>
bool DestoryList(LNode<DT> *&List) {
    //����βָ��ָ��ͷ�ڵ�
    LNode<DT> *P = List;
    while(P) {
        //����Listָ��ָ����һ���ڵ�
        List = List->next;
        //�ͷŵ�ǰ�ڵ��ڴ�
        delete P;
        //Pָ��List
        P=List;
    }
    List = NULL;
    return true;
}
//��λ�����
template<class DT>
bool GetElem_i(LNode<DT> *List, int i, DT &e) {
    //����βָ��ָ��ͷ�ڵ�
    LNode<DT> *p = List->next;
    if (i < 0) {
        cerr << "Error: invalid index." << endl;
        return false;
    }
    for (int j = 0; j < i; j++) {
        if (!p) {
            cerr << "Error: failed to find element." << endl;
            return false;
        }
        p = p->next;
    }
    if (p) {
        e = p->data;
        return true;
    }
    cerr << "Error: failed to find element." << endl;
    return false;
}
//��ֵ����
template<class DT>
int LocateElem_e(LNode<DT> *List, DT e) {
    LNode<DT> *p = List->next;//����βָ��ָ��ͷ�ڵ�
    int j = 0; //���ü�����
    while(p) {
        if(p->data == e) {
            return j; //�ҵ�Ԫ�أ�����λ��
        }
        p = p->next;
        j++;
    }
    return -1; //δ�ҵ�Ԫ��
}
//��λ�������Ԫ��
template<class DT>
bool InsertElem_i(LNode<DT> *&List, int i, DT e) {
    LNode<DT> *P = List->next; //����βָ��ָ��ͷ�ڵ�
    for(int j=0; j<i-1; j++) {
        if(!P) {
            cerr<<"Error: failed to insert element."<<endl;
            return false;
        }
        P = P->next;
    }
    LNode<DT> *s = new LNode<DT>; //����βָ��ָ��ͷ�ڵ�
    s->data = e;
    s->next = P->next;
    P->next = s;
    return true;
}
//��λ��ɾ��Ԫ��
template<class DT>
bool DeleteElem_i(LNode<DT> *&List, int i) {
    LNode<DT> *p =List; //����βָ��ָ��ͷ�ڵ�

    if(i<0) {
        cerr<<"Error: invalid index."<<endl;
        return false;
    }
    for(int j=0; j<i; j++) {
        if(!p) {
            cerr<<"Error: failed to delete element."<<endl;
            return false;
        }
        p = p->next;
    }
    LNode<DT> *q =p->next;
    p->next=q->next;
    delete q;
    return true;
}
//��λ���޸�Ԫ��ֵ
template<class DT>
bool PutElem_i(LNode<DT> *&List,int i,DT e) {
    LNode<DT> *p = List; //����βָ��ָ��ͷ�ڵ�
    if(i<0) {
        cerr<<"Error: invalid index."<<endl;
        return false;
    }
    for(int j=0; j<i; j++) {
        if(!p) {
            cerr<<"Error: failed to modify element."<<endl;
            return false;
        }
        p = p->next;
    }
    p=p->next;
    p->data = e;
    return true;
}
//��յ�����
template<class DT>
bool ClearList(LNode<DT> *&List) {
    //����βָ��ָ��ͷ�ڵ�
    LNode<DT> *p = List->next;
    LNode<DT> *q = NULL;
    while(!p) {
        q=p->next;
        delete p;
        p=q;
    }
    List->next = NULL;
    return true;
}
//���
template<class DT>
int ListLength(LNode<DT> *List) {
    //����βָ��ָ��ͷ�ڵ�
    LNode<DT> *p = List->next;
    int j = 0;
    while(p) {
        p = p->next;
        j++;
    }
    return j;
}
//�ж������Ƿ�Ϊ��
template<class DT>
bool IsEmpty(LNode<DT> *List) {
    //����βָ��ָ��ͷ�ڵ�
    LNode<DT> *p = List->next;
    if(p) {
        return false;
    }
    return true;
}

//��������
template<class DT>
void ListDisp(LNode<DT> *List) {
    //����βָ��ָ��ͷ�ڵ�
    LNode<DT> *p = List->next;
    while(p) {
        cout<<p->data<<" ";
        p = p->next;
        }
    cout<<endl; //����
}
//��ֵ����ǰ��
template<class DT>
bool LocatePrev_e(LNode<DT> *List, DT e,DT &V) {
    int index;
    //��ȡ��ѯֵ��λ��
    index = LocateElem_e(List, e);
    //�ж��Ƿ��ҵ�Ԫ��
    if(index>0) {
        GetElem_i(List, index-1, V);
        return true;
    }
    cerr << "�Ҳ���Ԫ�أ�" << endl;
    return false;
}

//����ת
template<class DT>
bool ReverseList(LNode<DT> *&List) {
    //����βָ��ָ��ͷ�ڵ�
    LNode<DT> *p = List->next;
    LNode<DT> *q = NULL;
    LNode<DT> *r = NULL;
    while(p) {
        q = p->next;
        p->next = r;
        r = p;
        p = q;
    }
    List->next = r;
    return true;
}