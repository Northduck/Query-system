//
//  website.hpp
//  Query-system
//
//  Created by администратор on 17/03/2019.
//  Copyright © 2019 администратор. All rights reserved.
//

#ifndef website_hpp
#define website_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
#include "storage.hpp"
#include "store.hpp"
using json = nlohmann::json;
using namespace std;
class Website{
private:
    json database;
    json ids;
    Storage *next;
public:
    Website(string databaseName, string productIDs, Storage *nextObj);
    
    void websiteSearch(json product, int quantity);
};
#endif /* website_hpp */
