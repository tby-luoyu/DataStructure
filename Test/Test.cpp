#include "../LinearList.h"
#include "../LinkList.h"


int main(int argc, char *argv[]) {

    //LinearList Test

    /*
     *int a=3;
    SqList<int> LIST;
    initSqList(LIST,15);
    CreateSqList(LIST,5);
    ListDisp(LIST);
    InsertElem_i(LIST,3,a);
    ListDisp(LIST);
    DeleteElem_i(LIST,1);
    PutElem_i(LIST,2,10);
    ListDisp(LIST);
    */

    //LinkList Test

    int a;
    LNode<int> *List;
    InitLinkList(List);
    CreateLinkList(List,5);
    DeleteElem_i(List,4);
    ListDisp(List);
    GetElem_i(List,0,a);
    cout<<a<<endl;
    cout<<LocateElem_e(List,4)<<endl;
    ClearList(List);
    ListDisp(List);
    cout<<"Length of List: "<<endl;
    DestoryList(List);



}
