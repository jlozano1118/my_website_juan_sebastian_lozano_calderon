#include<iostream>
using namespace std;

struct Nodo{
	int dato;
	Nodo* sig;
};

void crearLista(Nodo*& cab, int d){
	Nodo* nuevo = new Nodo;
	nuevo->dato = d;
	nuevo->sig = NULL;
	cab = nuevo;
}

void insertarFinal(Nodo* cab, int d){
	Nodo* aux = cab;
	Nodo* nuevo = new Nodo;
	nuevo->dato = d;
	
	while(aux->sig != NULL){
		aux = aux->sig;
	}
	
	aux->sig = nuevo;
	nuevo->sig = NULL;
	
}

void mostrarLista(Nodo* cab){
	Nodo* aux = cab;
	while(aux != NULL){
		cout<<aux->dato<<" -> ";
		aux = aux->sig;
	}
	
}

Nodo* buscarNodo(Nodo*cab, int d){
	Nodo* aux = cab;
	while(aux != NULL){
		if(aux->dato == d){
			return aux;
		}
		
		aux = aux->sig;
	}
	
	return NULL;
}

void eliminarInicio(Nodo*& cab){
	Nodo* aux = cab;
	cab = cab->sig;
	delete aux;
}

void eliminarMedio(Nodo* cab, Nodo* elim){
	Nodo* aux = cab;
	while(aux->sig != elim){
		aux = aux->sig;
	}
	
	aux->sig = elim->sig;
	delete elim;
}

int main(){
	Nodo* cab = NULL; Nodo* buscar = NULL;
	int dato, N;
	
	cout<<"Digite la cantidad de datos que desea: ";
	cin >> N;
	
	for(int i = 1; i <= N; i++){
		cout<<"Digite el dato "<<i<<" : ";
		cin >> dato;
		if(cab == NULL){
			crearLista(cab,dato);
		}else{
			insertarFinal(cab,dato);
		}
	}
	
	mostrarLista(cab);
	int opc = 1;
	while(opc == 1){
		cout<<endl<<"Digite un valor para verificar si existe: ";
		cin >> dato;
		buscar = buscarNodo(cab,dato);
		if(buscar != NULL){
			cout<<"El dato existe";
		}else{
			cout<<"El dato no existe";
		}
		
		cout<<"\nDesea continuar? 1. Si 2. No ";
		cin >> opc;
	}
	
	opc = 1;
	
	while(opc == 1){
		do{
			cout<<endl<<"Digite un valor para eliminar: ";
			cin >> dato;
			buscar = buscarNodo(cab,dato);
			if(buscar != NULL){
				cout<<"El dato existe en la lista";
			}else{
				cout<<"El dato no existe";
			}
		}while(buscar == NULL);
		
		if(buscar == cab){
			eliminarInicio(cab);
		}else{
			eliminarMedio(cab,buscar);
		}
		
		cout<<endl<<"Lista modificada..."<<endl;
		mostrarLista(cab);
		cout<<"\nDesea continuar? 1. Si 2. No ";
		cin >> opc;
	}
	
	cout<<"Mision cumplida :D"<<endl;
	
}
