#include <bits/stdc++.h>
using namespace std;

class Item;
class cart;

class product{
    int id;
    string name;
    int price;

    public:
    product(){}
    product(int u_id, string name,int price){
        id= u_id;
        this->name =name;
        this->price=price;
    }
    string getdisplayName(){
        return name +" :Rs"+ to_string(price)+"\n";
    }
    string getShortName(){
        return name.substr(0,1);
    }
    friend class Item;
    friend class cart;
};

class Item{
    product Product;
    int quantity;
    public:
    Item(){}
    Item(product p, int q):Product(p), quantity(q){}
    int getItemPrice(){
        return quantity*Product.price;
    }
    string getItemInfo(){
        return to_string(quantity)+" x "+ Product.name +" Rs."+ to_string(quantity*Product.price)+"\n";
    }
    friend class cart;

};

class cart{
    unordered_map<int,Item> items;
    public:
    void addProduct(product Product){
        if(items.count(Product.id)==0){
            Item newItem(Product,1);
            items[Product.id] = newItem;
        }
        else{
            items[Product.id].quantity += 1;
        }
    }
    int get_total(){
        int total =0;
        for(auto itemPair:items){
            auto item = itemPair.second;
            total+= item.getItemPrice();
        }
        return total;
    }
    string viewcart(){
        if(items.empty()){
            return "cart is empty";
        }
        string itimizedlist;
        int cart_total = get_total();

        for(auto itemPair: items){
            auto item = itemPair.second;
            itimizedlist.append(item.getItemInfo());
        }
        return itimizedlist + "\nTotal cart amount: Rs." +to_string(cart_total);
    }

    bool isempty(){
        return items.empty();
    }

};