//this is a brute force try of making a documnets editior 
//here only 2 fuctions are added to add string or test in the documents  
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
class documents{
    private:
    vector<string>vec;
    string rendor_string;
    public:
    void add_text(string s){
        vec.push_back(s);
    }
    void add_img(string s){
        //here this string will be the address of the image photo.pg or photo.png
        vec.push_back(s);
    }
    string rendor_document(){
        //this function will result the rendered string in a string format
        if((rendor_string.empty())){
            string ans;
            for(auto s:vec){
                if(s.size()>4&&(s.substr(s.size()-4)==".jpg"||s.substr(s.size()-4)==".png")){
                    ans+="[Image : "+s+"]\n";
                }else{
                    ans+=s+"\n";
                }
            }
            rendor_string=ans;
        }
        return rendor_string;
    }
    void savetofile(){
        ofstream file("document1.txt");
        if(file.is_open()){
            file<<rendor_document();
            file.close();
            cout<<"documnet saved to document1.txt file"<<endl;
        }else{
            cout<<"Error : unable to save the rendored document in file"<<endl;
        }
    }
};
int main(){
    documents cv;
    cv.add_text("hello everyone my name is yuvraj");
    cv.add_img("pfp.jpg");
    cv.add_text("bachlor of tech in ece form mnit ");
    cv.add_text("cgpa : 8.00");
    cout<<cv.rendor_document()<<endl;
    cv.savetofile();
    return 0;
}