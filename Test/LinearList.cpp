#include "../LinearList.h"

using namespace std;

void dispmenu() {
    cout<<"---------顺序表操作菜单---------"<<endl;
    cout<<endl;
    cout<<"        1.初始化顺序表          "<<endl;
    cout<<"        2.创建顺序表           "<<endl;
    cout<<"        3.获取第i个元素     "<<endl;
    cout<<"        4.按值查找元素序位      "<<endl;
    cout<<"        5.插入第i个元素        "<<endl;
    cout<<"        6.删除第i个元素        "<<endl;
    cout<<"        7.修改第i个元素        "<<endl;
    cout<<"        8.清空表              "<<endl;
    cout<<"        9.测表长度         "<<endl;
    cout<<"        10.测表是否为空      "<<endl;
    cout<<"        11.测表是否已满           "<<endl;
    cout<<"        12.显示表           "<<endl;
    cout<<"        13.按值查找前驱        "<<endl;
    cout<<"        0.退出                "<<endl;
    cout<<endl;
    cout<<"-----------------------------"<<endl;
}

void Choice(){
    int choice;
    cout<<"请输入操作编号：";
    cin.sync();
    cin>>choice;
    system("CLS");
    dispmenu();
    SqList<int> list;
    switch (choice)
    {
    case 1:
        cout<<"正在执行初始化链表操作...."<<endl;
        cout<<"请输入顺序表长度：";
        int n;
        cin>>n;
        if(InitSqList(list,n)) {
            cout<<"初始化链表成功！"<<endl;
            break;
        }
        cerr<<"初始化链表失败！"<<endl;
        break;
    case 2:
        cout<<"正在执行创建顺序表操作...."<<endl;
        cout<<"请输入初始元素元素长度："<<"(当前顺序表空间为"<<list.size<<")";
        int n1;
        cin>>n1;
        if(CreateSqList(list,n1)) {
            cout<<"创建顺序表成功！"<<endl;
            break;
        }
        cerr<<"创建顺序表失败！"<<endl;
        break;
    case 3:
        cout<<"正在执行获取第i个元素操作...."<<endl;
        cout<<"请输入要获取的位置：";
        int i;
        cin>>i;
        int e;
        if(GetElem_i(list,i,e)) {
            cout<<"获取成功！"<<endl;
            cout<<"获取元素为："<<e<<endl;
            break;
        }
        break;
    case 4:
        cout<<"正在执行按值查找元素序位操作...."<<endl;
        cout<<"请输入要查找的元素：";
        int e1;
        cin>>e1;
        if(LocateElem_e(list,e1)!=-1) {
            cout<<"查找成功！"<<endl;
            cout<<"元素位置为："<<LocateElem_e(list,e1)<<endl;
            break;
        }
        cout<<"元素不存在！"<<endl;
        break;    
    case 5:
        cout<<"正在执行插入第i个元素操作...."<<endl;
        cout<<"目前顺序表：";
        ListDisp(list);
        cout<<"请输入插入位置与元素值：";
        int i1,e2;
        cin>>i1>>e2;
        if(InsertElem_i(list,i1,e2)) {
            cout<<"插入成功！"<<endl;
            cout<<"插入后顺序表：";
            ListDisp(list);
            break;
        }
        cerr<<"插入失败！"<<endl;
        break;        
    case 6:
        cout<<"正在执行删除第i个元素操作...."<<endl;
        cout<<"目前顺序表：";
        ListDisp(list);
        cout<<"请输入删除位置：";
        int i2;
        cin>>i2;
        if(DeleteElem_i(list,i2)) {
            cout<<"删除成功！"<<endl;
            cout<<"删除后顺序表：";
            ListDisp(list);
            break;
        }
        cerr<<"删除失败！"<<endl;       
        break; 
    case 7:
        cout<<"正在执行修改第i个元素操作...."<<endl;
        cout<<"目前顺序表：";
        ListDisp(list);
        cout<<"请输入修改位置与元素值：";
        int i3,e3;
        cin>>i3>>e3;
        if(PutElem_i(list,i3,e3)) {
            cout<<"修改成功！"<<endl;
            cout<<"修改后顺序表：";
            ListDisp(list);
            break;
        }
        cerr<<"修改失败！"<<endl;
        break;
    case 8:
        cout<<"正在执行清空表操作...."<<endl;
        ClearList(list);
        cout<<"清空表成功！"<<endl;
        break;
    case 9:
        cout<<"正在执行测表长度操作...."<<endl;
        cout<<"当前顺序表长度为："<<ListLength(list)<<endl;
        break;
    case 10:
        cout<<"正在执行测表是否为空操作...."<<endl;
        if(ListEmpty(list)) {
            cout<<"顺序表为空！"<<endl;
            break;
        }
        cout<<"顺序表不为空！"<<endl;
        break;
    case 11:
        cout<<"正在执行测表是否已满操作...."<<endl;
        if(ListFull(list)) {
            cout<<"顺序表已满！"<<endl;
            break;
        }
        cout<<"顺序表未满！"<<endl;
        break;
    case 12:
        cout<<"正在执行显示表操作...."<<endl;
        ListDisp(list);
        break;
    case 13:
        cout<<"正在执行按值查找前驱操作...."<<endl;
        cout<<"请输入要查找的元素：";
        int e4,v;
        cin>>e4;
        if(PriorElem_e(list,e4,v)) {
            cout<<"查找成功！"<<endl;
            cout<<"前驱元素为："<<v<<endl;
            break;
        }   
        cout<<"元素不存在！"<<endl;
        break;
    case 0:
        cout<<"正在退出......"<<endl;
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