# nullable
C#のnull許容型を模倣したもの。  
基本的なgetter、setterのみ実装。

# How to use
``` cpp
#include <iostream>
#include "nullable.h"
using namespace std;

void main()
{
    nullable<int> val_1;
    if(val_1)
    {
        cout << (int)val_1 << endl; // 実行されない
    }
    
    val_1 = 123;
    if(val_1)
    {
        cout << (int)val_1 << endl; // 実行される
    }
    
    nullable<int> val_2 = val_1;
    if(val_2)
    {
        cout << (int)val_2 << endl; // 実行される
    }
    
    val_1 = nullptr;
    if(val_1)
    {
        cout << (int)val_1 << endl; // 実行されない
    }
}
```

# Environment
C++11 and after.
