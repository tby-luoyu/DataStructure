#include <iostream>
using namespace std;

template<class DT>
struct LNode {
    DT data; //存储数据
    LNode<DT> *next; //指向下一个节点的指针
};

template<class DT>
bool InitLinkList(LNode<DT> *&List) {
    //申请头结点内存
    List = new LNode<DT>;
    //判断内存是否申请成功
    if(!List){cerr<<"Memory allocation failed! failed to initialize LinkList."<<endl;}
    List->next = NULL;
    return true;
}

template<class DT>
bool CreateLinkList(LNode<DT> *&List, int n ) {
    //设置尾指针指向头节点
    LNode<DT> *p = List;
    for(int i=0; i<n; i++) {
        //申请内存
        LNode<DT> *q = new LNode<DT>;
        //判断内存是否申请成功
        if(!q){cout<<"Memory allocation failed! failed to create LinkList.创建链表失败内存不足"<<endl; return false;}
        //输入数据
        cin>>q->data;
        p->next = q;
        q->next = NULL;
        p = q;
    }
    return true;
}

template<class DT>
void ListDisp(LNode<DT> *List) {
    //设置尾指针指向头节点
    LNode<DT> *p = List->next;
    while(p) {
        cout<<p->data<<" ";
        p = p->next;
        }
    cout<<endl; //换行
}