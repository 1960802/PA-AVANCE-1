#include <iostream>
#include "Usuario.h"
#include "ListaLibros.h"
#include "ListaEnvios.h"
#include "ListaUsuario.h"

using namespace std;
ListaUsuarios g_usuario;
ListaLibros g_libros;
ListaEnvios g_envio;

void Registrar();
void Iniciar();
void info();
void productos();
void envios();
void salir();
void moduloproductos();
void modulos();
void nuev();
void editar();
void eliminar();
void misproductos();
void nuevEn();
void editarEn();
void eliminarEn();
void misenvios();
void BuscarUsuarioPorCodigo();
void GuardarArchivoLibros();
void CargarArchivoLibros();

int main()
{
	int a = 0;
	while (a != 2)
	{
		system("cls");
		cout << "L I B R E R I A" << endl;
		cout << endl << endl;
		cout << endl << endl;

		cout << "Escoger opci\242n" << endl;
		cout << "1. Registrarse " << endl;
		cout << "2. Iniciar sesi\242n " << endl;
		cin >> a;

		switch (a)
		{
		case 1:
			system("cls");
			Registrar();
			break;

		case 2:
			system("cls");
			Iniciar();
			break;
		}

	}
}

void  Registrar()
{
	Usuario nuevoUsuario;

	cout << "Nombre de usuario: ";
	cin.ignore();
	cin.getline(nuevoUsuario.nombre, 40);
	cout << endl << endl;

	//validación
	cout << "Ingresar contraseña: ";
	cin >> nuevoUsuario.contrasena;
	cout << endl;

	cout << "Nombre de alias: ";
	cin.ignore();
	cin.getline(nuevoUsuario.Alias, 40);
	cout << endl << endl;

	InsertarUsuarioAlInicio(nuevoUsuario, g_usuario);
}

void eliminarEn()
{
}

void misenvios()
{
}

void BuscarUsuarioPorCodigo()
{
	char nombre[40];
	cout << "Nombre de usuario: ";
	cin.ignore();
	cin.getline(nombre, 40);
	cout << endl << endl;

	//validación

	int contrasena = 0;
	cout << "Ingresar contraseña: ";
	cin >> contrasena;
	cout << endl;

	Usuario* usuario = BuscarUsuario(g_usuario, contrasena);
	if (usuario != nullptr)
	{
		moduloproductos();
	}
	else {
		std::cout << "El usuario no existe" << std::endl;
	}
}

void  Iniciar()
{
	BuscarUsuarioPorCodigo();
}

void moduloproductos()
{
	bool salirPrograma = false;
	while (!salirPrograma)
	{
		system("cls");
		int respuesta = 0;
		cout << "Bienvenido" << endl;
		cout << "1 - Informaci\242n del vendedor" << endl;
		cout << "2 - Productos" << endl;
		cout << "3 - Envios" << endl;
		cout << "4 - Salir" << endl;
		cin >> respuesta;

		switch (respuesta)
		{
		case 1:
			system("cls");
			info();
			break;
		case 2:
			system("cls");
			productos();
			break;
		case 3:
			system("cls");
			envios();
			break;
		case 4:
			system("cls");
			salir();
			salirPrograma = true;
			break;
		}

		cin.ignore();
		cin.get();
	}
}

void modulos()
{
}

void salir()
{
	cout << "Saliendo con éxito" << endl;
}

void info()
{
	NodoUsuario* auxiliar = g_usuario.Primero;
	for (int i = 0; i < g_usuario.TotalNodos; i++)
	{
		// Imprimir

		system("cls");
		std::cout << "Usuario: " << auxiliar->Contenido.nombre << std::endl;
		std::cout << "Contraseña: " << auxiliar->Contenido.contrasena << std::endl;
		std::cout << "Alias: " << auxiliar->Contenido.Alias << std::endl;
		std::cout << "-----------------------------" << std::endl;

		auxiliar = auxiliar->Siguiente;
	}
}

void envios()
{
	system("cls");
	int opcion = 0;
	cout << "Bienvenido" << endl;
	cout << "1 - Nuevo envio" << endl;
	cout << "2 - Editar envio" << endl;
	cout << "3 - Eliminar envio" << endl;
	cout << "4 - Mis envios" << endl;
	cin >> opcion;

	switch (opcion)
	{
	case 1:
		system("cls");
		nuevEn();
		break;
	case 2:
		system("cls");
		editarEn();
		break;
	case 3:
		system("cls");
		eliminarEn();
		break;
	case 4:
		system("cls");
		misenvios();
		break;
	}

}

void productos()
{
	system("cls");
	int opcion = 0;
	cout << "Bienvenido" << endl;
	cout << "1 - Nuevo producto" << endl;
	cout << "2 - Editar producto" << endl;
	cout << "3 - Eliminar" << endl;
	cout << "4 - Mis productos" << endl;
	cout << "5 - Guardar a archivo" << endl;
	cout << "6 - Cargar archivo" << endl;
	cin >> opcion;

	switch (opcion)
	{
	case 1:
		system("cls");
		nuev();
		break;
	case 2:
		system("cls");
		editar();
		break;
	case 3:
		system("cls");
		eliminar();
		break;
	case 4:
		system("cls");
		misproductos();
		break;
	case 5:
		system("cls");
		GuardarArchivoLibros();
		break;
	case 6:
		system("cls");
		CargarArchivoLibros();
		break;
	}
}

void nuev()
{
	Libro nuevoLibro;
	system("cls");
	cout << "Nombre de producto: ";
	cin.ignore();
	cin.getline(nuevoLibro.titulo, 40);
	cout << endl << endl;

	cout << "Cantidad: ";
	cin >> nuevoLibro.TotalInventario;
	cout << endl;

	cout << "Codigo: ";
	cin >> nuevoLibro.Codigo;
	cout << endl;

	cout << "Marca: ";
	cin.ignore();
	cin.getline(nuevoLibro.Marca, 40);
	cout << endl << endl;

	cout << "Descripcion: ";
	//cin.ignore();
	cin.getline(nuevoLibro.Descripcion, 100);
	cout << endl << endl;

	cout << "Monto: ";
	cin >> nuevoLibro.Monto;
	cout << endl;

	InsertarLibroAlInicio(nuevoLibro, g_libros);
}

void editar()
{
	system("cls");
	int codigo = -1;
	cout << "Ingrese codigo" << endl;
	cin >> codigo;

	float monto = 0.0f;
	cout << "Ingrese nuevo monto" << endl;
	cin >> monto;
	cout << endl;

	int cantidad = 0;
	cout << "Ingrese nueva cantidad" << endl;
	cin >> cantidad;

	char titulo[40];
	cout << "Titulo nuevo: ";
	cin.ignore();
	cin.getline(titulo, 40);
	cout << endl << endl;

	char descripcion[100];
	cout << "Descripcion nueva: ";
	//cin.ignore();
	cin.getline(descripcion, 100);
	cout << endl << endl;

	char Marca[40];
	cout << "Marca: ";
	//cin.ignore();
	cin.getline(Marca, 40);
	cout << endl << endl;

	Libro nuevo;
	nuevo.TotalInventario = cantidad;
	nuevo.Monto = monto;
	strcpy_s(nuevo.titulo, titulo);
	strcpy_s(nuevo.Descripcion, descripcion);
	strcpy_s(nuevo.Marca, Marca);

	if (ModificarLibro(g_libros, nuevo, codigo))
	{
		std::cout << "Modificado con exito" << std::endl;
	}
	else {
		std::cout << "No se pudo modificar" << std::endl;
	}
}

void eliminar()
{
	system("cls");
	int codigo = -1;
	cout << "Ingrese el codigo del libro a eliminar" << endl;
	cin >> codigo;

	EliminarLibro(g_libros, codigo);

	std::cout << "Se ha eliminado";
}

void misproductos()
{
	NodoLibro* auxiliar = g_libros.Primero;
	for (int i = 0; i < g_libros.TotalNodos; i++)
	{
		std::cout << "Codigo: " << auxiliar->Contenido.Codigo << std::endl;
		std::cout << "Producto: " << auxiliar->Contenido.titulo << std::endl;
		std::cout << "Cantidad: " << auxiliar->Contenido.TotalInventario << std::endl;
		std::cout << "Marca: " << auxiliar->Contenido.Marca << std::endl;
		std::cout << "Descripcion: " << auxiliar->Contenido.Descripcion << std::endl;
		std::cout << "Monto: " << auxiliar->Contenido.Monto << std::endl;
		std::cout << "-----------------------------" << std::endl;

		auxiliar = auxiliar->Siguiente;
	}
}

void GuardarArchivoLibros()
{
	std::cout << "Guardando en el archivo libros.bin" << std::endl;
	if (GuardarListaEnArchivo("libros.bin", g_libros))
	{
		std::cout << "Se ha guardado con exito" << std::endl;
	}
	else
	{
		std::cout << "No se pudo guardar en libros.bin" << std::endl;
	}
}

void CargarArchivoLibros()
{
	std::cout << "Cargando el archivo libros.bin" << std::endl;
	if (LeerListaDeArchivo("libros.bin", g_libros))
	{
		std::cout << "Se ha cargado con exito" << std::endl;
	}
	else
	{
		std::cout << "No se pudo cargar libros.bin" << std::endl;
	}
}

void nuevEn()
{
}

void editarEn()
{
}
