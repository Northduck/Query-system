//
//  store.cpp
//  Query-system
//
//  Created by администратор on 17/03/2019.
//  Copyright © 2019 администратор. All rights reserved.
//

#include "store.hpp"

Store::Store(string databaseName, string storageFaq){
    json data, info;
    ifstream finDatabase(databaseName);
    ifstream finFaq(storageFaq);
    finDatabase>>data;
    finFaq>>info;
    setObj(data, info);
    finDatabase.close();
    finFaq.close();
}
void Store::about(json good){
    cout<<getFaq()<<"\n\n"<<good;
    json info=getFaq();
    cout<<"Good news! There is your product in "<<info["name"]<<"store in quantity of "<<good["quantity"];
    cout<<"\nStore is avaliable"<<info["workinghours"];
}
