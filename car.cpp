#include<iostream>
using namespace std;
class car{
    string model;
    int year;
    double fuel_lvl,speed;
    bool isRunning;
    public:
    car(string model,int year,double fuel_lvl,double speed){
        this->model=model;
        this->year=year;
        this->fuel_lvl=fuel_lvl;
        this->speed=speed;
        this->isRunning=false;
    }
    void startengine(){
        if(fuel_lvl>0){
            isRunning=true;
            cout<<"car starting with a roarrrrrr......"<<endl;
        }else{
            cout<<"car cannot starts because of the low fuel"<<endl;
        }
    }
    void stopengine(){
        isRunning=false;
        cout<<"car stopped..."<<endl;
    }
    void accelerate(double acceleration){
        if(acceleration>0){
            speed+=acceleration;
            cout<<"car is running with a speed of : "<<speed<<endl;
        }else{
            cout<<"invalid call!!"<<endl;
        }
    }
    void retard(double retardation){
        if(speed>retardation){
            speed-=retardation;
            if(speed==0){
                cout<<"car stopped"<<endl;
                speed=0;
                isRunning=false;
            }
            cout<<"car is running with a speed of : "<<speed<<endl;
        }else{
            cout<<"car stopped "<<endl;
            speed=0.0;
            isRunning=0;
        }
    }
    void refuel(double fuel){
        if(fuel>=0){
            fuel_lvl+=fuel;
        }else{
            cout<<"Invalid call!!"<<endl;
        }
    }
    void printStatus() const {
        cout << "\n----- Car Status -----\n";
        cout << "Model      : " << model << '\n';
        cout << "Year       : " << year << '\n';
        cout << "Speed      : " << speed << " km/h\n";
        cout << "Fuel Level : " << fuel_lvl << " L\n";
        cout << "Engine     : "<< (isRunning ? "Running" : "Stopped") << '\n';
        cout << "----------------------\n";
    }
};
int main() {
    car c1("Toyota Camry", 2023, 20.5, 0);
    c1.printStatus();
    c1.startengine();
    c1.accelerate(30);
    c1.accelerate(20);
    c1.printStatus();
    c1.retard(15);
    c1.printStatus();
    c1.refuel(10);
    c1.printStatus();
    c1.retard(35); 
    c1.printStatus();
    c1.stopengine();
    c1.printStatus();
    return 0;
}