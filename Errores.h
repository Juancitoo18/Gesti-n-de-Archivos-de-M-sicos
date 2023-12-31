#ifndef ERRORES_H_INCLUDED
#define ERRORES_H_INCLUDED

void cargarCadena(char *pal, int tam);

const char * ERR_DESCRIPTION[128] = {
    "Error no especificado. ", //0
    "La opci�n seleccionada no tiene asignada una funci�n. ", //1
    "Hubo un problema al intentar acceder al archivo en cuesti�n. ", // 2
    "Hubo un problema al intentar cerrar el archivo en cuesti�n. ", // 3
    "Hubo un error al intentar escribir en el archivo en cuesti�n. " // 4
  , "Hubo un error al intentar eliminar de forma l�gica un registro en el archivo en cuesti�n. " //5
  , "No se ha encontrado un registro con los valores ingresados. " // 6
  , "Valor inv�lido. " // 7
  , "EL INT�RPRETE NO EXISTE EN EL ARCHIVO DE INT�RPRETES. INTENTE DE NUEVO " // 8
  , "LA FECHA Y HORA INGRESADAS SON POSTERIORES A LA FECHA Y HORA ACTUALES" // 9
  , "LA NACIONALIDAD NO EXISTE EN EL ARCHIVO DE PAISES. INTENTE DE NUEVO"//10
  , "EL TIPO DE INTERPRETE NO EXISTE EN EL ARCHIVO DE TIPO DE INTERPRETE. INTENTE DE NUEVO"//11
  , "EL GENERO NO EXISTE EN EL ARCHIVO DE GENERO. INTENTE DE NUEVO"//12
};

class Error {
private:
    int code = 0;
public:
    void print() {
        cout<<"Error N� "<<code<<": "<<ERR_DESCRIPTION[code]<<" "<<endl;
    }
    int getCode() {return code;}
    Error(int c) {
        code = c;
    }
};

void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}


#endif // ERRORES_H_INCLUDED
