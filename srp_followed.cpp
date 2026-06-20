#include<iostream>
#include<vector>
using namespace std;
class Product{
    public:
    double price;
    string name;
    public:
    Product(double price,string name){
        this->price=price;
        this->name=name;
    }
};
//methods of shopping cart will be divided into subclasses bcoz we can only have 1 method in a class
class ShoppingCart{
    private:
    vector<Product*>vec;
    public:
    void add_product(Product *p){
        vec.push_back(p);
    }
    const vector<Product*> get_product(){
        return vec;
    }
    double calc_total_price(){
        double ans=0;
        for(auto it:vec){
            ans+=it->price;
        }
        return ans;
    }
};
class cart_printer{
    private:
    ShoppingCart *sc;
    public:
    cart_printer(ShoppingCart *sc){
        this->sc=sc;
    }
    void print_invoice(){
        cout<<"shopping cart invoice"<<endl;
        int total=0;
        for(auto it:sc->get_product()){
            cout<<it->name<<" : "<<it->price<<" $"<<endl;
        }
        cout<<"total : "<<sc->calc_total_price()<<" $"<<endl;
    }
};
class savetodb{
    private:
    ShoppingCart *sc;
    public:
    savetodb(ShoppingCart *sc){
        this->sc=sc;
    }
    void save(){
        cout<<"saving in database "<<endl;
    }
};
int main(){
    ShoppingCart *s1=new ShoppingCart();
    s1->add_product(new Product(1500,"macbook air"));
    s1->add_product(new Product(713,"headphones"));
    s1->add_product(new Product(1228,"Benq Monitor"));
    cart_printer *cart=new cart_printer(s1);
    cart->print_invoice();
    savetodb * s=(new savetodb(s1));
    s->save();
    cout<<s1->calc_total_price()<<endl;
    return 0;
}