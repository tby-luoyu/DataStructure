#include <iostream>
using namespace std;
//链表结构
template<class DT>
struct LNode {
    DT data; //存储数据
    LNode<DT> *next; //指向下一个节点的指针
};
//初始化链表
template<class DT>
bool InitLinkList(LNode<DT> *&List) {
    //申请头结点内存
    List = new LNode<DT>;
    //判断内存是否申请成功
    if(!List){cerr<<"Memory allocation failed! failed to initialize LinkList."<<endl;}
    List->next = NULL;
    return true;
}
//创建链表(尾插法)
template<class DT>
bool CreateLinkList_Tail(LNode<DT> *&List, int n ) {
    //设置尾指针指向头节点
    LNode<DT> *p = List;
    for(int i=0; i<n; i++) {
        //申请内存
        LNode<DT> *q = new LNode<DT>;
        //判断内存是否申请成功
        if(!q){cerr<<"Memory allocation failed! failed to create LinkList.创建链表失败内存不足"<<endl; return false;}
        //输入数据
        cin>>q->data;
        p->next = q;
        q->next = NULL;
        p = q;
    }
    return true;
}
//创建链表(头插法)
template<class DT>
bool CreateLinkList_Head(LNode<DT> *&List, int n ) {
    //设置尾指针指向头节点
    LNode<DT> *p = List;
    for(int i=0; i<n; i++) {
        //申请内存
        LNode<DT> *q = new LNode<DT>;
        //判断内存是否申请成功
        if(!q){cerr<<"Memory allocation failed! failed to create LinkList.创建链表失败内存不足"<<endl; return false;}
        //输入数据
        cin>>q->data;
        p->next = q;
        p = q;
        p->next = NULL;
    }
    return true;
}


//销毁链表
template<class DT>
bool DestoryList(LNode<DT> *&List) {
    //设置尾指针指向头节点
    LNode<DT> *P = List;
    while(P) {
        //设置List指针指向下一个节点
        List = List->next;
        //释放当前节点内存
        delete P;
        //P指向List
        P=List;
    }
    List = NULL;
    return true;
}
//按位序查找
template<class DT>
bool GetElem_i(LNode<DT> *List, int i, DT &e) {
    //设置尾指针指向头节点
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
//按值查找
template<class DT>
int LocateElem_e(LNode<DT> *List, DT e) {
    LNode<DT> *p = List->next;//设置尾指针指向头节点
    int j = 0; //设置计数器
    while(p) {
        if(p->data == e) {
            return j; //找到元素，返回位置
        }
        p = p->next;
        j++;
    }
    return -1; //未找到元素
}
//按位序插入新元素
template<class DT>
bool InsertElem_i(LNode<DT> *&List, int i, DT e) {
    LNode<DT> *P = List->next; //设置尾指针指向头节点
    for(int j=0; j<i-1; j++) {
        if(!P) {
            cerr<<"Error: failed to insert element."<<endl;
            return false;
        }
        P = P->next;
    }
    LNode<DT> *s = new LNode<DT>; //设置尾指针指向头节点
    s->data = e;
    s->next = P->next;
    P->next = s;
    return true;
}
//按位序删除元素
template<class DT>
bool DeleteElem_i(LNode<DT> *&List, int i) {
    LNode<DT> *p =List; //设置尾指针指向头节点

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
//按位序修改元素值
template<class DT>
bool PutElem_i(LNode<DT> *&List,int i,DT e) {
    LNode<DT> *p = List; //设置尾指针指向头节点
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
//清空单链表
template<class DT>
bool ClearList(LNode<DT> *&List) {
    //设置尾指针指向头节点
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
//测表长
template<class DT>
int ListLength(LNode<DT> *List) {
    //设置尾指针指向头节点
    LNode<DT> *p = List->next;
    int j = 0;
    while(p) {
        p = p->next;
        j++;
    }
    return j;
}
//判断链表是否为空
template<class DT>
bool IsEmpty(LNode<DT> *List) {
    //设置尾指针指向头节点
    LNode<DT> *p = List->next;
    if(p) {
        return false;
    }
    return true;
}

//遍历链表
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
//按值查找前驱
template<class DT>
bool LocatePrev_e(LNode<DT> *List, DT e,DT &V) {
    int index;
    //获取查询值的位序
    index = LocateElem_e(List, e);
    //判断是否找到元素
    if(index>0) {
        GetElem_i(List, index-1, V);
        return true;
    }
    cerr << "找不到元素！" << endl;
    return false;
}

//链表反转
template<class DT>
bool ReverseList(LNode<DT> *&List) {
    //设置尾指针指向头节点
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