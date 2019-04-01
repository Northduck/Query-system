//
//  warehouse.cpp
//  Query-system
//
//  Created by администратор on 17/03/2019.
//  Copyright © 2019 администратор. All rights reserved.
//

#include "warehouse.hpp"
Warehouse::Warehouse(string databaseName, string storageFaq){
    json data, info;
    ifstream finDatabase(databaseName);
    ifstream finFaq(storageFaq);
    finDatabase>>data;
    finFaq>>info;
    setObj(data, info);
    finDatabase.close();
    finFaq.close();
}
void Warehouse::about(json good, std::vector<bool> &shopInStock){
    json info=getFaq();
    int i=0;
    for(auto& element : info){
        if(shopInStock[i]==false){
            cout<<"If you order today you can take it \n";
            cout<<"in "<<element["name"]<<" in "<<element["deliveryTime"]<<" days\n";
        }
        i++;
    }
    cout<<"Quantity is "<< good["quantity"]<<endl;
}
