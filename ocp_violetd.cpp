//open close principle is violeted 
#include<iostream>
#include<vector>
using namespace std;
class Product{
    public:
    double price;
    string name;
    Product(double price,string name){
        this->price=price;
        this->name=name;
    }
};
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
    //here we will follow the srp(single responsiability principle but violet the ocp)
    double calc_total_price(){
        double total=0;
        for(auto it:vec){
            total+=it->price;
        }
        return total;
    }
};
class print_invoice{
    private:
    ShoppingCart * sc;
    public:
    print_invoice(ShoppingCart *sc){
        this->sc=sc;
    }
    void print(){
        cout << "Shopping Cart Invoice:\n";
        for (auto p : sc->get_product()) {
            cout << p->name << " - $ " << p->price << endl;
        }
        cout << "Total: $ " << sc->calc_total_price() << endl;
    }
};
class savetodb{
    ShoppingCart *sc;
    public:
    savetodb(ShoppingCart *sc){
        this->sc=sc;
    }
    void savetosql(){
        cout<<"saving to sql"<<endl;
    }
    void savetomongo(){
        cout<<"saving to monogodb"<<endl;
    }
};
int main(){
    ShoppingCart *s1=new ShoppingCart();
    s1->add_product(new Product(1500,"macbook air"));
    s1->add_product(new Product(713,"headphones"));
    s1->add_product(new Product(1228,"Benq Monitor"));
    print_invoice *cart=new print_invoice(s1);
    cart->print();
    savetodb * s=(new savetodb(s1));
    s->savetomongo();
    s->savetosql();
    cout<<s1->calc_total_price()<<endl;
    return 0;
}