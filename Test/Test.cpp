#include "../LinearList.cpp"


int main(int argc, char *argv[]) {
    int a=3;
    SqList<int> LIST;
    initSqList(LIST,15);
    CreateSqList(LIST,5);
    ListDisp(LIST);
    InsertElem_i(LIST,3,a);
    ListDisp(LIST);
    DeleteElem_i(LIST,1);
    PutElem_i(LIST,2,10);
    ListDisp(LIST);
}
