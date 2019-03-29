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
void Warehouse::about(json good){
    json info=getFaq();
    cout<<"There is your product in warehouse. If you order today you can take it \n";
    for(auto& element : info){
        cout<<"in "<<element["name"]<<" in "<<element["deliveryTime"]<<" days\n";
    }
    cout<<"Quantity is "<< good["quantity"]<<endl;
}
