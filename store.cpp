//
//  store.cpp
//  Query-system
//
//  Created by администратор on 17/03/2019.
//  Copyright © 2019 администратор. All rights reserved.
//

#include "store.hpp"

Store::Store(string databaseName, string storageFaq, int numb):storeNumb(numb){
    json data, info;
    ifstream finDatabase;
    ifstream finFaq;
    finDatabase.exceptions(ifstream::failbit);
    finFaq.exceptions(ifstream::failbit);
    try
    {
        finDatabase.open(databaseName);
        finFaq.open(storageFaq);
        finDatabase.seekg(0, ios::end);
        if (int(finDatabase.tellg()) != 0)
        {
            finDatabase.seekg(0, ios::beg);
            finDatabase>>data;
        }
        else{
            throw 0;
        }
        finFaq.seekg(0, ios::end);
        if (int(finFaq.tellg()) != 0)
        {
            finFaq.seekg(0, ios::beg);
            finFaq>>info;
        }
        else{
            throw 1;
        }
        setObj(data, info);
        finDatabase.close();
        finFaq.close();
    }
    catch (const ifstream::failure& exc)
    {
        cout << "Error, cannot open file" << endl;
    }
    catch (int i){
        if(i==0){
            cout<<"File"<<databaseName<<" is empty\n";
        }else{
            cout<<"File"<<storageFaq<<" is empty\n";
        }
    }
}
void Store::about(json good, std::vector<bool> &shopInStock){
    shopInStock[storeNumb]=true;
    json info=getFaq();
    cout<<"\nGood news! There is your product in "<<info["name"]<<"store in quantity of "<<good["quantity"];
    cout<<"\nStore is avaliable"<<info["workinghours"];
}
