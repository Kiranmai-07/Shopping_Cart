#include <bits/stdc++.h>
#include "datamodel.h"
using namespace std;

vector<product> allProducts ={
    product(1,"apple",25),
    product(2,"banana",6),
    product(3,"strawberry",10),
    product(4,"pineapple",52),
    product(5,"mango",33),
    product(6,"guava",34)
};

product* chooseProd(){
    string Productlist;
    cout<<"Availble Products "<<endl;
    for(auto prod:allProducts){
        Productlist.append(prod.getdisplayName());
    }
    cout<<Productlist<<endl;
    cout<<"------------------------"<<endl;
    string choice;
    cin>>choice;
    for(int i=0;i<allProducts.size();i++){
        if(allProducts[i].getShortName()==choice){
            return &allProducts[i];
        }
    }
    cout<<"Product not found!"<<endl;
    return NULL;
}

bool checkout(cart &cart){
    if(cart.isempty()){
        return false;
    }
    int total = cart.get_total();
    cout<<"Pay in cash!"<<endl;
    int paid;
    cin>>paid;
    if(paid>=total){
        cout<<"change: Rs"<<paid-total<<endl;
        cout<<"Thank ypu for shopping!"<<endl;
        return true;
    }
    else{
        cout<<"Insufficient amount"<<endl;
        return false;
    }
}


int main(){
    char action;
    cart cart;
    while(true){
        cout<<"select an action- (a)dd item, (v)iew cart,(c)heckout"<<endl;
        cin>>action;
        if(action=='a'){
            product *Product =chooseProd();
            if(Product!=NULL){
                cout<<"Added to the cart "<<Product->getdisplayName()<<endl;
                cart.addProduct(*Product);
            }
        }
        else if(action =='v'){
            cout<<"---------------------->"<<endl;
            cout<<cart.viewcart()<<endl;
            cout<<"---------------------->"<<endl;            

        }
        else{
            cart.viewcart();
            if(checkout(cart)){
                break;
            }
        }
    }
    return 0;
}