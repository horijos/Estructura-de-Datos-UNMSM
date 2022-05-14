#include<bits/stdc++.h>
#include <conio.h>
using namespace std;
int A[10];
int B[10];
int C[10];

int tamA=0;
int tamB=0;
int tamC=0;



void insertarA(int a){
  for(int i=tamA;i>=1;i--){
    A[i]=A[i-1];
  }
  A[0]=a;
  tamA++;
}

void insertarB(int b){
  for(int i=tamB;i>=1;i--){
    B[i]=B[i-1];
  }
  B[0]=b;
  tamB++;
}
void insertarC(int c){
  C[tamC]=c;
  tamC++;
}

void llenar(){
  srand(time(0));
    for(int i = 0; i<10; i++){
      int k= rand()%1001;
      insertarA(k);
      int g=(rand()%1001)-1001;
      insertarB(g);
    }
}

int borrarA(){
  int k=A[0];
  for(int i=0;i<tamA-1;i++){
    A[i]=A[i+1];
  }
  tamA--;
  return k;
}

int borrarB(){
  int k=B[0];
  for(int i=0;i<tamB-1;i++){
    B[i]=B[i+1];
  }
  tamB--;
  return k;
}

void mostrarA(){
  cout<<"A : ";
  for(int i=0;i<tamA;i++){
    cout<<A[i]<<" ";
  }
  cout<<'\n';
}

void mostrarB(){
  cout<<"B : ";
  for(int i=0;i<tamB;i++){
    cout<<B[i]<<" ";
  }
  cout<<'\n';
}

void mostrarC(){
  cout<<"C : ";
  for(int i=0;i<tamC;i++){
    cout<<C[i]<<" ";
  }
  cout<<'\n';
}

void llenarC(){
  for(int i=0;i<10;i++){
  C[i]+=(borrarA()+borrarB());
  }
}

void llenarC2(){
  for(int i=0;i<10;i++){
    int bA=borrarA();
    int bB=borrarB();
    cout<<"Elementos eliminados de A y B: "<<bA<<" , "<<bB<<endl;
    cout<<"Elementos anadido a C: "<<bA+bB<<endl;
    C[i]+=(bA+bB);
  }
}

void menu(){
  int ea,eb,bA,bB;
  int k;
  cout<<"MENU"<<endl;
  cout<<"1)Insertar Elementos"<<endl;
  cout<<"2)Extraer"<<endl;
  cout<<"3)Mostrar Listas"<<endl;
  cout<<"opcion : ";
  cin>>k;
  while(k<1 || k>3){
    cout<<"opcion : ";
    cin>>k;
  }

  switch (k) {
    case 1:
    if(tamA==10){
      cout<<"Vectores llenos no se puede agregar mas.\n";
      getche();
      break;
    }
    cout<<"Elemento a ingresar en A(par positivo):";
    cin>>ea;
    while(!(ea%2==0 && ea>0)){
      cout<<"Elemento a ingresar en A(par positivo):";
      cin>>ea;
    }
    cout<<"Elemento a ingresar en B(impar negativo):";
    cin>>eb;
    while(!(eb%2!=0 && eb<0)){
      cout<<"Elemento a ingresar en B(impar negativo):";
      cin>>eb;
    }
    insertarA(ea);
    insertarB(eb);
    cout<<"Elementos anadidos satisfactoriamente :D!\n";
    getche();
    break;

    case 2:
    if(tamA==0 || tamB==0){
      cout<<"Vectores vacios no se puede extraer elementos.\n";
      getche();
      break;
    }
    if(tamC==10){
      cout<<"Vector C lleno no se puede adicionar mas elementos.\n";
      getche();
      break;
    }
    bA=borrarA();
    bB=borrarB();
    cout<<"Elementos eliminados de A y B: "<<bA<<" , "<<bB<<endl;
    cout<<"Elemento anadido a C :"<<bA+bB<<endl;
    insertarC(bA+bB);
    getche();
    break;

    case 3:
    mostrarA();
    mostrarB();
    mostrarC();
    getche();
  }
}

int main(){

  do {
    menu();
    system("CLS");
  } while(true);

  return 0;
}
