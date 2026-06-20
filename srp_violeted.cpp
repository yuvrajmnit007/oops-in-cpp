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
    void cart_invoice(){
        cout << "Shopping Cart Invoice:\n";
        for (auto p : vec) {
            cout << p->name << " - $ " << p->price << endl;
        }
        cout << "Total: $ " << calc_total_price() << endl;
    }
    void savetodb(){
        cout << "Saving shopping cart to database..." << endl;
    }
};
int main(){
    ShoppingCart *s1=new ShoppingCart();
    s1->add_product(new Product(1500,"macbook air"));
    s1->add_product(new Product(713,"headphones"));
    s1->add_product(new Product(1228,"Benq Monitor"));
    s1->cart_invoice();
    cout<<s1->calc_total_price()<<endl;
    s1->savetodb();
    return 0;
}