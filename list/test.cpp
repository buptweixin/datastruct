#include "list.hpp"

using namespace std;

int main()
{
    List<int> list;
    int num;
    while(cin>>num)
    {
        list.list_insert(num);
    }
    list.print();
    return 0;
}

