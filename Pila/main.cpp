#include <iostream>
#define TAM 50
using namespace std;
//plantillas
class Pila{
private:
    char datos[TAM];
    int ult;
    bool inserta(char , int);
    bool elimina(int);
    char recupera(int)const;
    int primero()const;
    int ultimo()const;
    void imprime()const;
public:
    Pila():ult(-1){}
    bool vacia()const;
    bool llena()const;
    int buscar(char);
    bool push(char);
    bool pop();
    char top()const;
};

char Pila::top()const{
    return datos[ult];
}

bool Pila::pop(){
    if(vacia()){
        return false;
    }
    else{
        elimina(ultimo());
    }
    return true;
}

bool Pila::push(char elem){
    if(llena()){
        return false;
    }
    if(vacia()){
        inserta(elem,0);
    }
    else{
        inserta(elem,ultimo()+1);
    }
    return true;
}

int Pila::buscar(char elem){
    int i=0;
    while(i<=ult){
        if(elem ==datos[i]){
            return i;
        }
        i++;
    }
    return -1;
}

void Pila::imprime()const{
    if(!vacia()){
        char x;
        for(int i=0; i<=ult; i++){
            x=datos[i];
            std::cout<<x<<std::endl;
        }
    }
}

bool Pila::vacia()const{
    return ult==-1;
}
bool Pila::llena()const{
    return ult==TAM-1;
}

bool Pila::inserta(char elem, int pos){
    if(llena() || pos<0 || pos>ult+1){
        std::cout<<"\n No se pudo insertar";
        return false;
    }
    int i=ult+1;
    while(i>pos){
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return true;
}

bool Pila::elimina(int pos){
    if(vacia() || pos<0 || pos>ult){
        std::cout<<"\n No se pudo eliminar";
        return false;
    }
    int i=pos;
    while(i<ult){
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return true;
}

char Pila::recupera(int pos)const{
    if(vacia() || pos<0 || pos>ult-1){
        std::cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
    }
    else{
       return datos[pos];
    }
}

int Pila::primero()const{
    if(vacia()){
       return -1;
    }
    return 0;
}
int Pila::ultimo()const{
    if(vacia()){
       return -1;
    }
    return ult;
}
int ley(char menu)
{
    switch(menu)
    {
        case '/': return 2;
        case '*': return 2;
        case '+': return 1;
        case '-': return 1;
        default:  return 0;
    }
}

int main()
{
string primera;
string segunda;
Pila tmp;

cout<<"Introduce la suma:"<<endl;
cin>>primera;
for(int i=0; i<primera.size(); i++)
{
    switch(primera[i])
    {
        case '(':
            tmp.push('(');
            break;
        case ')':
            while(tmp.top()!='(')
            {
                segunda += tmp.top();
                tmp.pop();
            }
            tmp.pop();
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        if(primera[i]!=tmp.top()){
            while(ley(primera[i])<=ley(tmp.top()))
            {
                segunda += tmp.top();
                tmp.pop();
            }
            tmp.push(primera[i]);
            break;
        default:
            segunda += primera[i];
                }
    }
}
 while (!tmp.vacia())
    {
        segunda += tmp.top();
        tmp.pop();
    }
cout<<"Posfija:"<<segunda;
    return 0;
}
