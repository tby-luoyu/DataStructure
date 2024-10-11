#include <iostream>
using namespace std;

struct PolyNode {
    float coef; //ϵ��
    int exp;    //ָ��
    PolyNode *next; //ָ����һ���ڵ�
};
//��ʼ������ʽ
void InitPoly(PolyNode *&p) {
    cout<<"��ʼ������ʽ"<<endl;
    p =new PolyNode;
    p->next = NULL;
}
//��������ʽ
bool CreatePoly(PolyNode *&p,int n) {
    if(!p) {
        cerr<<"����ʽδ��ʼ��"<<endl;
        return false;
    }
    cout<<"���������ʽ��ϵ����ָ����";
    for(int i=0;i<n;i++) {
        PolyNode *q =new PolyNode;
        cin>>q->coef>>q->exp;
        q->next = NULL;
        p->next = q;
        p=q;
    }
}
void PolyAdd(PolyNode *&LA,PolyNode *&LB) {
    PolyNode *pa = LA->next;
    PolyNode *pb = LB->next;
    PolyNode *pc = LA;
    while(pa&&pb) {
        if(pa->exp<pb->exp) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }else if(pa->exp>pb->exp) {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }else {
            float sum = pa->coef+pb->coef;
            if(sum!=0) {
                pa->coef = sum;
                pc->next = pa;
                pc = pa;
                pa = pa->next;
                PolyNode *temp = pb;
                pb = pb->next;
                delete temp;
            }else {
                PolyNode *temp = pa;
                pa = pa->next;
                delete temp;
                temp = pb;
                pb = pb->next;
                delete temp;
            }
        }
    }
    pc->next = pa?pa:pb;
    delete LB;
}

//��ʾ����ʽ
void DispPoly(PolyNode *p) {
    if(!p) {
        cout<<"����ʽΪ��"<<endl;
        return;
    }
    cout<<"��ʾ����ʽ"<<endl;
    PolyNode *q =p->next;
    while(q&&q->next) {
        cout<<q->coef<<"x^"<<q->exp<<" + ";
        q = q->next;
    }
    //the end
    cout<<q->coef<<"x^"<<q->exp<<endl;
}


