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
    cout<<"        0.退出                "<<endl;
    cout<<endl;
    cout<<"-----------------------------"<<endl;
}
void Choice() {
    int choice;
    cout<<"请输入操作编号：";
    cin>>choice;
    system("CLS");
    dispmenu();
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
        case 3:
            cout<<"正在执行头插法创建单链表操作...."<<endl;
            int num1;
            cout<<"请输入链表元素个数：";
            cin>>num1;
            if(CreateLinkList_Head(list, num1)) {
                cout<<"创建链表成功！"<<endl;
                break;
            }
            cerr<<"创建链表失败！"<<endl;
            break;
        case 4:
            cout<<"正在执行获取第i个节点元素操作...."<<endl;
            int i,e;
            cout<<"请输入要获取的节点位置：";
            cin>>i;
            if(GetElem_i(list, i,e)) {
                cout<<"第"<<i<<"个节点元素为："<<e<<endl;
                break;
            }
            cerr<<"获取第"<<i<<"个节点元素失败！"<<endl;
            break;
        case 5:
            cout<<"正在执行按值查找元素序位操作...."<<endl;
            int value;
            cout<<"请输入查找元素：";
            cin>>value;
            if(LocateElem_e(list, value)!=-1) {
                cout<<"元素在第"<<LocateElem_e(list, value)<<"个位置"<<endl;
                break;
            }
            cout<<"元素不存在！"<<endl;
            break;
        case  6:
            cout<<"正在执行插入第i个元素操作...."<<endl;
            cout<<"目前链表：";
            ListDisp(list);
            int i1,e1;
            cout<<"请输入要插入的位置与数值：";
            cin>>i1>>e1;
            if(InsertElem_i(list, i1, e1)) {
                cout<<"插入成功！"<<endl;
                cout<<"插入后链表：";
                ListDisp(list);
                break;
            }
            cerr<<"插入失败！"<<endl;
            break;
        case 7:
            cout<<"正在执行删除第i个元素操作...."<<endl;
            cout<<"目前链表：";
            ListDisp(list);
            int i2;
            cin>>i2;
            if(DeleteElem_i(list, i2)) {
                cout<<"删除成功！"<<endl;
                cout<<"删除后链表：";
                ListDisp(list);
                break;
            }
            cerr<<"删除失败！"<<endl;
            break;
        case 8:
            cout<<"正在执行修改第i个元素操作...."<<endl;
            cout<<"目前链表：";
            ListDisp(list);
            int i3,e3;
            cout<<"请输入要修改的位置与数值：";
            cin>>i3>>e3;
            if(PutElem_i(list, i3, e3)) {
                cout<<"修改成功！"<<endl;
                cout<<"修改后链表：";
                ListDisp(list);
                break;
            }
            cerr<<"修改失败！"<<endl;
            break;
        case 9:
            cout<<"正在执行清空链表操作...."<<endl;
            if(ClearList(list)) {
                cout<<"清空链表成功！"<<endl;
                break;
            }
            cerr<<"清空链表失败！"<<endl;
            break;
        case 10:
            cout<<"正在执行测链表长度操作...."<<endl;
            cout<<"链表长度为："<<ListLength(list)<<endl;
            break;
        case 11:
            cout<<"正在执行测链表是否为空操作...."<<endl;
            if(IsEmpty(list)) {
                cout<<"链表为空！"<<endl;
                break;
            }
            cout<<"链表不为空！"<<endl;
            break;
        case 12:
            cout<<"正在执行遍历输出操作...."<<endl;
            ListDisp(list);
            break;
        case 13:
            cout<<"正在执行按值查找前驱操作...."<<endl;
            int value1,V;
            cout<<"请输入查找元素：";
            cin>>value1;
            if(LocatePrev_e(list, value1, V)) {
                cout<<"前驱元素为："<<V<<endl;
                break;
            }
            cout<<"没有前驱元素！"<<endl;
            break;
        case 14:
            dispmenu();
            break;
        case 0:
            cout<<"正在退出...."<<endl;
            exit(0);
        default:
            cout<<"输入错误！"<<endl;
    }
}
int main() {
    dispmenu();
    while (true) {
        Choice();
    }
}