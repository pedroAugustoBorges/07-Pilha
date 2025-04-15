#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* anterior;
};

NO* topo = NULL;

// headers
void menu();
void inicializar();
void pop();
void push();
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 4) {
		system("cls"); // somente no windows
		cout << "Menu Pilha";
		cout << endl << endl;
		cout << "1 - Inicializar Pilha \n";
		cout << "2 - Inserir elemento (Push) \n";
		cout << "3 - Remover elementos (Pop) \n";
		cout << "4 - Sair \n";


		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:push();
			break;
		case 3: pop();
			break;
		case 4:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = topo;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->anterior;
		free(paraExcluir);
	}

	topo = NULL;
	cout << "Pilha inicializada \n";

}


void push()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}
	
	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->anterior = NULL;

	if (topo == NULL) {
		topo = novo;
	}

	novo->anterior = topo;

	topo = novo;
}

void pop()
{
	if (topo == NULL) {
		cout << "A fila esta vazia";
	}

	NO* aux = topo;

	cout << "Elemento eliminado: " << topo->valor << endl;

	topo = topo->anterior;

	cout << "Novo elemento" << topo->valor << endl ;

	

	free(aux);

}

