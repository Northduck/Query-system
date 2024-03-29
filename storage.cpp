//
//  storage.cpp
//  Query-system
//
//  Created by администратор on 17/03/2019.
//  Copyright © 2019 администратор. All rights reserved.
//

#include "storage.hpp"
void Storage::addNext(Storage *n)
{
    if (next!=NULL)
        next->addNext(n);
    else
        next = n;
}

void Storage::isAvaliable(int productID, int quantity, std::vector<bool> &shopInStock){
    shopInStock.push_back(false);
    int productNumber=productSearch(productID, quantity);
    if(productNumber!=-1){
        about(database[productNumber], shopInStock);
    }
    if(next){
        next->isAvaliable(productID, quantity, shopInStock);
    }
}

int Storage::productSearch(int productID, int quantity){
    int storageProductID=0, i=0;
    for(auto& element : database){
        storageProductID=element["id"].template get<int>();
        if(storageProductID==productID&&element["quantity"].template get<int>()>=quantity){
            return i;
        }
        i++;
    }
    return -1;
}

void Storage::setObj(json data, json info){
    database=data;
    faq=info;
    next=NULL;
}

json Storage::getDatabase(){
    return database;
}
json Storage::getFaq(){
    return faq;
}
void Storage::printBase(){
    std::cout<<"\n\n"<<database<<"\n\n";
}
