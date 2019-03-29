//
//  website.cpp
//  Query-system
//
//  Created by администратор on 17/03/2019.
//  Copyright © 2019 администратор. All rights reserved.
//

#include "website.hpp"



Website::Website(string databaseName, string productIDs, Storage *nextObj):next(nextObj){
    ifstream finDatabase(databaseName);
    finDatabase>>database;
    finDatabase.close();
    ifstream finID(productIDs);
    finID>>ids;
    finID.close();
}

void Website::websiteSearch(json product, int quantity){
    int i=0;
    for(auto& element : database){
        if(element==product){
            cout<<ids[i];
            next->printBase();
            next->isAvaliable(ids[i] ,quantity);
            return;
        }
        i++;
    }
    cout<<"Sorry, there is no such product on our website, try again another product";
}
