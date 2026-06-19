#include<iostream>
using namespace std;
class customer{
    string name;
    int account_number;
    double amount;
    bool isactive;
    public:
    customer(string name,int account_number,double amount){
        this->name=name;
        this->account_number=account_number;
        this->amount=amount;
        this->isactive=true;
    }
    void deposit(double amount){
        this->amount+=amount;
    }
    void withdraw(double amount){
        this->amount-=amount;
    }
    void transfer(double amount, customer &a){
        if(this->amount>amount){
            a.amount+=amount;
            this->amount-=amount;
        }else{
            cout<<"t=Transcation failed due to insufficient balance"<<endl;
        }
    }
    void print_details(){
        cout<<"name : "<<name<<endl<<"account number : "<<account_number<<endl<<"balance : "<<amount<<endl<<"is active : "<<((isactive==1)?"YES":"NO")<<endl;
    }
};
int main(){
    customer a("Yuvraj",3458992,78942.95);
    customer b("kuldeep",3458993,70000.00);
    a.deposit(67.05);
    b.withdraw(1000);
    a.transfer(1000,b);
    a.print_details();
    b.print_details();
}