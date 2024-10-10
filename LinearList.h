#include <iostream>
using namespace std;
template<class DT>
struct SqList {
    DT *addr; //Data Array
    int length; //Data Length
    int size; //Data Size
};
//初始化顺序表
template<class  DT>
bool InitSqList(SqList<DT> &List,int size) {
    //申请动态内存数组
    List.addr = new DT[size];
    if (List.addr == NULL) { //申请失败，抛出异常
        cerr<< "Memory allocation failed! failed to initialize SqList.申请内存失败"<<endl;
    }
    //初始化顺序表信息
    List.length = 0;
    List.size = size;
    return true;
}

//创建顺序表
template<class DT>
bool CreateSqList(SqList<DT> &list, int n) {
    //判断创建顺序表是否有合适的内存空间
    if (n>list.size) {
        cerr<< "The length of the list is less than the number of elements to be inserted. 申请内存失败"<<endl;
        return false;
    }
    //向顺序表内存入元素
    for (int i = 0; i < n; i++) {
         cin>>list.addr[i];
    }
    //更新顺序表长度
    list.length = n;
    return true;
}

//销毁顺序表
template<class DT>
void DestorySqList(SqList<DT> &list) {
    //释放动态数组内存
    delete[] list.addr;
    //重置顺序表信息
    list.size =0;
    list.length =0;
}
//按位序查找
template<class DT>
bool GetElem_i(SqList<DT> list,int i, DT &e) {
    //判断位序是否合法
    if(i<=0 || i>list.length) {
        cerr<<"查询范围越界."<<endl;
    }else {
            e = list.addr[i-1];
            return true;
    }
    return false;
}
//按值查找
template<class DT>
int LocateElem_e(SqList<DT> list,DT e) {
    for (int i = 0; i < list.length; i++) {
        if(list.addr[i] == e) {
            return i;
        }
    }
    return -1;
}

//按位序插入元素
template<class DT>
bool InsertElem_i(SqList<DT> &List,int i,DT e) {
    if(List.length == List.size) {
        cout<<"顺序表已满"<<endl;
        return false;
    }
    if(i<0 || i>List.length+1) {
        cout<<"插入位置不合法"<<endl;
        return false;
    }
    //将i后面的元素后移一位
    for(int j=List.length-1;j>i-1;j--) {
        List.addr[j+1]=List.addr[j];
    }
    List.addr[i]=e;
    List.length++;
    return true;
}
//按位序删除元素
template<class DT>
bool DeleteElem_i(SqList<DT> &List,int i) {
    if(List.length == 0) {
        cout<<"顺序表为空"<<endl;
        return false;
    }
    if(i<1 || i>List.length) {
        cout<<"删除位置不合法"<<endl;
        return false;
    }
    for(;i<List.length-1;i++) {
        List.addr[i]=List.addr[i+1];
    }
    List.length--;
    return true;
}

//按位序修改元素值
template<class DT>
bool PutElem_i(SqList<DT> &List,int i,DT e) {
    if(i<1 || i>List.length) {
        cout<<"元素不存在"<<endl;
        return false;
    }
    List.addr[i] =e;
    return true;

}
//清空顺序表
template<class DT>
void ClearList(SqList<DT> &List) {
    List.length = 0;
}
//测表空
template<class DT>
bool ListEmpty(SqList<DT> List) {
    if(List.length == 0) {
        return true;
    }
    return false;
}
//测表长
template<class DT>
int ListLength(SqList<DT> List) {
    return List.length;
}
//测表满
template<class DT>
bool ListFull(SqList<DT> List) {
    if(List.length == List.size) {
        return true;
    }
    return false;
}
//遍历输出顺序表
template<class DT>
void ListDisp(SqList<DT> List) {
    for(int i=0;i<List.length;i++) {
        cout<<List.addr[i]<<" ";
    }
    cout<<endl;
}
//按值查找前驱
template<class DT>
bool PriorElem_e(SqList<DT> List,DT cur_e,DT &pre_e) {
    int i = LocateElem_e(List,cur_e);
    if(i==0) {
        cout<<"元素不存在或者没有前驱"<<endl;
        return false;
    }
    pre_e = List.addr[i-1];
    return true;
}