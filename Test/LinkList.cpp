#include "../LinkList.h"
using namespace std;

void dispmenu() {
    cout<<"---------单链表操作菜单---------"<<endl;
    cout<<endl;
    cout<<"        1.初始化链表           "<<endl;
    cout<<"        2.尾插法创建单链表      "<<endl;
    cout<<"        3.头插法创建单链表      "<<endl;
    cout<<"        4.获取第i个节点元素     "<<endl;
    cout<<"        5.按值查找元素序位      "<<endl;
    cout<<"        6.插入第i个元素        "<<endl;
    cout<<"        7.删除第i个元素        "<<endl;
    cout<<"        8.修改第i个元素        "<<endl;
    cout<<"        9.清空链表            "<<endl;
    cout<<"        10.测链表长度         "<<endl;
    cout<<"        11.测链表是否为空      "<<endl;
    cout<<"        12.遍历输出           "<<endl;
    cout<<"        13.按值查找前驱        "<<endl;
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
            cout<<"正在执行初始化链表操作...."<<endl;
            if(InitLinkList(list)) {
                cout<<"初始化链表成功！"<<endl;
                break;
            }
            cerr<<"初始化链表失败！"<<endl;
            break;
        case 2:
            cout<<"正在执行尾插法创建单链表操作...."<<endl;
            int num;
            cout<<"请输入链表元素个数：";
            cin>>num;
            if(CreateLinkList_Tail(list, num)) {
                cout<<"创建链表成功！"<<endl;
                break;
            }
            cerr<<"创建链表失败！"<<endl;
            break;

    }
    return 0;
}