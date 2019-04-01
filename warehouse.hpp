//
//  warehouse.hpp
//  Query-system
//
//  Created by администратор on 17/03/2019.
//  Copyright © 2019 администратор. All rights reserved.
//

#ifndef warehouse_hpp
#define warehouse_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "json.hpp"
#include "storage.hpp"
#include "store.hpp"
using namespace std;
class Warehouse:public Storage  {
private:
    
public:
    Warehouse(string databaseName, string storageFaq);
    
    void about(json good, std::vector<bool> &shopInStock);
};
#endif /* warehouse_hpp */
