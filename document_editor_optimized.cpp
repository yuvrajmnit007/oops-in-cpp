//this is a brute force try of making a documnets editior 
//here only 2 fuctions are added to add string or test in the documents  
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
//abstraction for document element
class documents_element{
    public:
    virtual string render()=0;//"Every derived class MUST provide its own implementation of render()."bcos it is a pure virtual function
};
class textelement:public documents_element{
    private :
    string text;
    public:
    textelement(string &text){
        this->text=text;
    }
    string render() override{
        return text;
    }
};
class imageelement :public documents_element{
    private :
    string text;
    public:
    imageelement(string &text){
        this->text=text;
    }
    string render() override {
        return "[Image: " + text + "]";
    }
};
class newline :public documents_element{
    private :
    string text;
    public:
    string render() override{
        return "\n";
    }
};
class tabspace :public documents_element{
    private :
    string text;
    public:
    string render() override{
        return "\t";
    }
};
class documents{
    private:
    vector<documents_element*>vec;
    public:
    void addElement(documents_element* element) {
        vec.push_back(element);
    }
    string render() {
        string result;
        for (auto element : vec) {
            result += element->render();
        }
        return result;
    }
};
class persistance{
    public: 
    virtual void save(string data)=0;
};
class SaveToFile :public persistance{
    void save(string data) override {
        ofstream file("document1.txt");
        if(file){
            file << data;
            file.close();
            cout<<"documnet saved to document1.txt file"<<endl;
        }else{
            cout<<"Error : unable to save the rendered document in file"<<endl;
        }
    }
};
class SaveToDB : public persistance{
    void save(string data) override{
        cout<<"the data saved to the database sucessfully"<<endl;
    }
};
class document_editor{
    private:
    documents *doc;
    persistance *per;
    string rendered_doc;
    public:
    document_editor(documents *doc,persistance *per){
        this->doc=doc;
        this->per=per;
    }
    void addtxt(string &text){
        doc->addElement(new textelement(text));
    }
    void addimage(string &text){
        doc->addElement(new imageelement(text));
    }
    void addnewline(){
        doc->addElement(new newline());
    }
    void addtabspace(){
        doc->addElement(new tabspace());
    }
    string render_document(){
        if(rendered_doc.empty()){
            rendered_doc=doc->render();
        }
        return rendered_doc;
    }
    void save_document(){
        per->save(render_document());
    }
};
int main(){
    documents cv;
    SaveToFile fileStorage;
    document_editor editor(&cv, &fileStorage);
    string text1 = "Hello everyone my name is Yuvraj";
    string image1 = "pfp.jpg";
    string text2 = "Bachelor of Technology in ECE from MNIT";
    string text3 = "CGPA : 8.00";
    editor.addtxt(text1);
    editor.addnewline();
    editor.addimage(image1);
    editor.addnewline();
    editor.addtxt(text2);
    editor.addnewline();
    editor.addtxt(text3);
    cout << editor.render_document() << endl;
    editor.save_document();
    return 0;
}