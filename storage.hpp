//
//  storage.hpp
//  Query-system
//
//  Created by администратор on 17/03/2019.
//  Copyright © 2019 администратор. All rights reserved.
//

#ifndef storage_hpp
#define storage_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "json.hpp"
using json = nlohmann::json;
class Storage {
private:
    json database;
    json faq;
    Storage *next;
public:
    void addNext(Storage *n);
    
    virtual void about(json about, std::vector<bool> &shopInStock)=0;
    
    void isAvaliable(int productID, int quantity, std::vector<bool> &shopInStock);
    
    int productSearch(int productID, int quantity);
    
    void setObj(json data, json info);
    
    json getDatabase();
    
    json getFaq();
    
    void printBase();
    
};
#endif /* storage_hpp */
