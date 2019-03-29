//
//  store.hpp
//  Query-system
//
//  Created by администратор on 17/03/2019.
//  Copyright © 2019 администратор. All rights reserved.
//

#ifndef store_hpp
#define store_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
#include "storage.hpp"
using namespace std;
class Store:public Storage{
private:
    int storeNumb;
public:
    Store(string databaseName, string storageFaq);
    
    void about(json good);
};
#endif /* store_hpp */
