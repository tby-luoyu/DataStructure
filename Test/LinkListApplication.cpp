#include <iostream>
using namespace std;

struct PolyNode {
    float coef; //系数
    int exp;    //指数
    PolyNode *next; //指向下一个节点
};
//初始化多项式
void InitPoly(PolyNode *&p) {
    cout<<"初始化多项式"<<endl;
    p =new PolyNode;
    p->next = NULL;
}
//创建多项式
bool CreatePoly(PolyNode *&p,int n) {
    if(!p) {
        cerr<<"多项式未初始化"<<endl;
        return false;
    }
    cout<<"请输入多项式的系数和指数：";
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

//显示多项式
void DispPoly(PolyNode *p) {
    if(!p) {
        cout<<"多项式为空"<<endl;
        return;
    }
    cout<<"显示多项式"<<endl;
    PolyNode *q =p->next;
    while(q&&q->next) {
        cout<<q->coef<<"x^"<<q->exp<<" + ";
        q = q->next;
    }
    //the end
    cout<<q->coef<<"x^"<<q->exp<<endl;
}


