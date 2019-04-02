//
//  main.cpp
//  Query-system
//
//  Created by администратор on 17/03/2019.
//  Copyright © 2019 администратор. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
#include "store.hpp"
#include "website.hpp"
#include "warehouse.hpp"
#include "storage.hpp"
using json = nlohmann::json;
using namespace std;
json makeProduct(){
    string tempInput;
    json product={
        {"name"," "},
        {"publishing house", ""},
        {"year", 0},
        {"page numbers", 0},
        {"photos", false},
        {"map", false},
        {"binding", ""},
        {"author", ""}
    };
    cout<<"Enter the product ";
    getline(cin, tempInput, '\n');
    for (auto& el : product.items()) {
        cout << el.key()<<"\n";
        if(product[el.key()].type_name()=="string"||product[el.key()].type_name()=="boolean"){
            getline(cin, tempInput, '\n');
            if(product[el.key()].type_name()=="boolean"){
                if(tempInput=="0"){
                    product[el.key()]=false;
                }else{
                    product[el.key()]=true;
                }
            }else{
                product[el.key()]=tempInput;
            }
        }else{
            cin>>product[el.key()];
        }
    }
    return product;
}
int main() {
    json costumerProduct;
    ifstream finDatabase("../Database/product.json");
    finDatabase>>costumerProduct;
    finDatabase.close();
    cout<<costumerProduct<<endl<<endl;
    Storage *ourDatabase[4];
    ourDatabase[0]=new Warehouse("../Database/Warehouse.json", "../Info/Warehouse_info.json");
    ourDatabase[1]=new Store("../Database/Shop1.json", "../Info/Shop1_info.json",0);
    ourDatabase[2]=new Store("../Database/Shop2.json", "../Info/Shop2_info.json",1);
    ourDatabase[3]=new Store("../Database/Shop3.json", "../Info/Shop3_info.json",2);
    ourDatabase[1]->addNext(ourDatabase[2]);
    ourDatabase[1]->addNext(ourDatabase[3]);
    ourDatabase[1]->addNext(ourDatabase[0]);
    Website site("../Database/Site.json","../Database/Site_ID.json", ourDatabase[1]);
    char c;
    int quan=0;
    cout<<"Do you want search product?(y/n)\n";
    c=getchar();
    while (c=='y') {
        costumerProduct=makeProduct();
        cout<<"Enter quatity of your product\n";
        cin>>quan;
        site.websiteSearch(costumerProduct, quan);
        cout<<"Do you want search again?(y/n)\n";
        cin>>c;
        if(c=='n'){
            break;
        }
    }
    return 0;
}
