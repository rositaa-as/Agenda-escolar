 //Proyecto final: Base de datos Agenda alumnos_ASRMG

//librerías
#include<stdio.h> 
#include<stdlib.h>
#include<conio.h>
#include<string.h> 
#include<locale.h>
#include<windows.h> 
#include<iostream>



struct agenda{ //Estructura principal- 2 anidadas

    struct datos_p{ //datos personales 
    	
        char nombre[40], domicilio[30], colonia[30];
		char ciudad[25];
        char telefono[20], email[20], sexo[10];
		char notas[80];
        int CP, edad;
        
    }person;

    struct datos_aca{//datos academicos 
    	
        char codigo[20], carrera[10];
		char escuela[10];
        int semestre;
        float promedio;
        
    }acad;
    
}agen[10]; //capacidad para 10 registros

int cont=0; //contador de elementos

//PROTOTIPOS DE LAS FUNCIONES 
void inicio_acc();//solicitar clave
void key_error();//si la clave es erronea 

void bienvenida();//MUESTRA DIBUJO
void salida();//SALE DEL PROGRAMA

//opciones menu 
void menu();
void capturar();//opc 1
void mostrar();//opc 2
void buscar();//opc 3

void gotoxy(int, int);
void recuadro(int, int, int, int);


int main(int argc, char *argv[]){
    setlocale(LC_ALL,"");
    
    system("COLOR 5F");
    system("mode con: cols=123 lines=40");
    

     inicio_acc();

    return 0;
}

void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void recuadro(int xs, int ys, int xi, int yi)
{
    int i;
    for (i = xs; i <= xi; i++)
    {
        gotoxy(i, ys); printf("%c", 95);
        gotoxy(i, yi); printf("%c", 95);
    }
    
    for (i = ys; i <= yi; i++)
    {
        gotoxy(xs, i); printf("%c", 124);
        gotoxy(xi, i); printf("%c", 124);
    }    

    gotoxy(xs, ys); printf("%c", 46);
    gotoxy(xi, yi); printf("%c", 46);
    gotoxy(xi, ys); printf("%c", 46);
    gotoxy(xs, yi); printf("%c", 46);
}


void inicio_acc(){//solicitar clave de acceso (123)
    int i = 0;
    char key[4];

    while(i < 3){
    	
        system("cls");
        fflush(stdin);
        recuadro(1, 0, 121, 38);
        recuadro(30, 2, 100, 5);
        gotoxy(37,4),printf("\t\t  ACCESO A LA AGENDA DE ALUMNOS");
        
        gotoxy(22, 10),printf("Ingrese la clave de acceso: ");
        gets(key);

        if (strcmp(key,"123")==0){ //función que compara que la clave sea correcta
            bienvenida();
            i = 3;
        }
        else{
            i = i + 1;
            key_error();
        }
    }
    salida();
}

void key_error(){//en caso de que la clave sea incorrecta
	
    system("cls");
    recuadro(1, 0, 121, 38); 
    gotoxy(40, 20),printf("La clave que a ingresado es incorreta.");
    Sleep(1500);
    system("cls");
}

//--------------------------------------------------------------------

void bienvenida(){//autor del programa
    system("cls");
    recuadro(1, 0, 121, 38);
    recuadro(30, 2, 100, 5);
    gotoxy(37,4),printf("\t\t\tAGENDA DE ALUMNOS");
    Sleep(900);
    
    gotoxy(40,7),printf("\t                                      ");
    gotoxy(40,8),printf("\t    *°°°°°°°°°°°°°°°°°°°°°°°°°        ");
    gotoxy(40,9),printf("\t***||**                        *      ");
    gotoxy(40,10),printf("\t   ||        ++     ++          * ++  ");
    gotoxy(40,11),printf("\t***||**    +++++   +++++        * ++  ");
    gotoxy(40,12),printf("\t   ||     +++++++++++++++       * ++  ");
    gotoxy(40,13),printf("\t***||**    +++++++++++++        *     ");
    gotoxy(40,14),printf("\t   ||       +++++++++++         *     ");
    gotoxy(40,15),printf("\t***||**       +++++++           *     ");
    gotoxy(40,16),printf("\t   ||           +++             *     ");
    gotoxy(40,17),printf("\t***||**          +              *     ");
    gotoxy(40,18),printf("\t   ||                           *     ");
    gotoxy(40,19),printf("\t***||**     ______   __         *     ");
    gotoxy(40,20),printf("\t   ||       ____________        *     ");
    gotoxy(40,21),printf("\t***||**     __  ________        *     ");
    gotoxy(40,22),printf("\t   ||                           *      ");
    gotoxy(40,23),printf("\t***||**                         *      ");
    gotoxy(40,24),printf("\t   ||     AGENDA ESTUDIANTES    *      ");
    gotoxy(40,25),printf("\t***||**                        *       ");
    gotoxy(40,26),printf("\t   *°°°°°°°°°°°°°°°°°°°°°°°°°          ");
    gotoxy(40,27),printf("\t                                      ");

    Sleep(1500);
    
    gotoxy(39,30),printf("\t  AUTOR: Ávila Sandoval Rosa Maria Guadalupe");
    Sleep(3000);
    menu();
    
}

void salida(){//mensaje de despedida y datos del autor 
    system("cls");
    recuadro(1, 0, 121, 38);
    
    gotoxy(40,20),printf("Gracias por usar este programa, vuelva pronto!");
    Sleep(1000);
    system("cls");
    recuadro(1, 0, 121, 38);
    gotoxy(60,20),printf("Saliendo...");
    Sleep(1000);
    system("cls");
   
    recuadro(1, 0, 121, 38);
    gotoxy(40,3),printf("NOMBRE: Avila Sandoval Rosa María Guadalupe\n");
    gotoxy(40,4),printf("CÓDIGO: 218419793\n");
    gotoxy(40,5),printf("NRC:193711\n");
    gotoxy(40,6),printf("CLAVE: IL352\n");
    gotoxy(40,7),printf("MATERIA: Programación estructurada\n\n");

}

//----------------------------------------------------------------------------------

void menu(){//soliitar opciones
    int opc;
    
    do{
        system("cls");
        recuadro(1, 0, 121, 38);
        recuadro(30, 2, 100, 5);
        gotoxy(37,4),printf("\t\t\t       MENÚ");
        
        gotoxy(50,10),printf("Por favor seleccione la opción");
        gotoxy(52,11),printf("a la cuál desea acceder.");

        gotoxy(43,15),printf("1. Capturar");
        gotoxy(43,16),printf("2. Mostrar");
        gotoxy(43,17),printf("3. Buscar");
        gotoxy(43,18),printf("4. Salir");
        gotoxy(43,20),printf("Selección: ");
        scanf("%i",&opc);

        if(opc == 1){
            capturar();
        }
        else
        if(opc == 2){
            mostrar();
        }
        else
        if(opc == 3){
            buscar();
        }
        else
        if(opc == 4){
            printf("");
        }
        else{
            gotoxy(50,25),printf("Usted ingresó una opción incorrecta");
            
            Sleep(1500);
            system("cls");
        }
        
    }while(opc != 4);
}
//-------------------------------------------------------------------------------------
void capturar(){ //opción 1
	
    int i, num_r;
    
    system("cls");
    recuadro(1, 0, 121, 38);
    recuadro(30, 2, 100, 5);
    gotoxy(37,4),printf("\t\t\t CAPTURA DE DATOS");
    

    if(cont<10){
    	
        gotoxy(40,8),printf("Ingrese el número de registros que desea realizar: ");
        scanf("%i",&num_r);
        
        if(num_r<10){
            for(i=0;i<num_r;i++){
            	
                system("cls");
                cont = cont + 1;
                
                recuadro(1, 0, 121, 38);
                recuadro(30, 2, 100, 5);
                gotoxy(37,4),printf("\t\t\t   ALUMNO #%i\n", i+1);
                
                
                gotoxy(2,8),printf("----- DATOS PERSONALES -----");
                fflush(stdin);
                gotoxy(3,10),printf("Nombre: ");
                gets(agen[i].person.nombre);
                gotoxy(3,11),printf("Domicilio: ");
                gets(agen[i].person.domicilio);
                gotoxy(3,12),printf("Colonia: ");
                gets(agen[i].person.colonia);
                gotoxy(3,13),printf("Código postal: ");
                scanf("%i",&agen[i].person.CP);
                fflush(stdin);
                
                gotoxy(3,14),printf("Ciudad: ");
                gets(agen[i].person.ciudad);
                gotoxy(3,15),printf("Teléfono: ");
                gets(agen[i].person.telefono);
                gotoxy(3,16),printf("Email: ");
                gets(agen[i].person.email);
                gotoxy(3,17),printf("Sexo: ");
                gets(agen[i].person.sexo);
                gotoxy(3,18),printf("Edad: ");
                scanf("%i",&agen[i].person.edad);
                fflush(stdin);
                gotoxy(3,19),printf("Notas: ");
                gets(agen[i].person.notas);
                
                
                gotoxy(2,21),printf("----- Datos académicos ------");
                gotoxy(3,23),printf("Código de estudiante: ");
                gets(agen[i].acad.codigo);
                gotoxy(3,24),printf("Carrera: ");
                gets(agen[i].acad.carrera);
                gotoxy(3,25),printf("Semestre: ");
                scanf("%i",&agen[i].acad.semestre);
                fflush(stdin);
                gotoxy(3,26),printf("Centro universitario: ");
                gets(agen[i].acad.escuela);
                gotoxy(3,27),printf("Promedio: ");
                scanf("%f",&agen[i].acad.promedio);
                gotoxy(3,30),system("pause");
            }
        }
        else{
            gotoxy(40,20),printf("No se pueden hacer más registros, el límite es 10");
            
            Sleep(2000);
        }
    }
}

void mostrar(){//opción 2
    int i, num_r;
    system("cls");
    recuadro(1, 0, 121, 38);
    recuadro(30, 2, 100, 5);
    gotoxy(37,4),printf("\t\t\t MOSTRAR REGISTROS");

    if(cont!=0){
    	
        gotoxy(40,8),printf("Ingrese el número de registros que desea ver: ");
        scanf("%i",&num_r);

        if(num_r<10){
            for(i=0;i<num_r;i++){
            	
                system("cls");
                recuadro(1, 0, 121, 38);
                recuadro(30, 2, 100, 5);
                gotoxy(37,4),printf("\t\t\t   ALUMNO #%i",i+1);
                
                gotoxy(2,8),printf("-------------------------------------------------------");
                gotoxy(2,9),printf("\t\tDATOS PERSONALES");
                gotoxy(2,10),printf("-------------------------------------------------------");
                
                gotoxy(3,11),printf("Nombre: %s",agen[i].person.nombre);
                gotoxy(3,12),printf("Domicilio: %s",agen[i].person.domicilio);
                gotoxy(3,13),printf("Colonia: %s",agen[i].person.colonia);
                gotoxy(3,14),printf("Código postal: %i",agen[i].person.CP);
                gotoxy(3,15),printf("Ciudad: %s",agen[i].person.ciudad);
                gotoxy(3,16),printf("Teléfono: %s",agen[i].person.telefono);
                gotoxy(3,16),printf("Email: %s",agen[i].person.email);
                gotoxy(3,17),printf("Sexo: %s",agen[i].person.sexo);
                gotoxy(3,18),printf("Edad: %i",agen[i].person.edad);
                gotoxy(3,19),printf("Notas: %s",agen[i].person.notas);
                
                gotoxy(2,22),printf("-------------------------------------------------------");
                gotoxy(3,23),printf("\t\tDATOS ACADÉMICOS\n");
                gotoxy(2 ,24),printf("-------------------------------------------------------");
                gotoxy(3,25),printf("Código: %s",agen[i].acad.codigo);
                gotoxy(3,26),printf("Carrera: %s",agen[i].acad.carrera);
                gotoxy(3,27),printf("Semestre: %i",agen[i].acad.semestre);
                gotoxy(3,28),printf("Centro universitario: %s",agen[i].acad.escuela);
                gotoxy(3,29),printf("Promedio: %.2f",agen[i].acad.promedio);
                
                gotoxy(4,32),system("pause");
            }
        }
        else{
            gotoxy(40,20),printf("No se pueden mostrar más de 10 registros");
            Sleep(2000);
        }
    }
    else{
        gotoxy(45,20),printf("No se puede imprimir ningún registro");
        gotoxy(45,21),printf("porque este está vacio, realice uno.");
        Sleep(2000);
    }
}

void buscar(){//opción 3
    int i, opc;
    int band=0; //flag
    
    system("cls");
    if(cont!=0){
        recuadro(1, 0, 121, 38);
        recuadro(30, 2, 100, 5);
        gotoxy(37,4), printf("\t\t\t     BUSCAR");
        
        gotoxy(47,10),printf("Por favor seleccione la opción a la cuál");
        gotoxy(48,11),printf(" desea acceder para buscar el registro.");
        
        gotoxy(43,15),printf("1. Nombre ");
        gotoxy(43,16),printf("2. Teléfono ");
        gotoxy(43,17),printf("3. Código ");
        gotoxy(43,18),printf("4. Carrera ");
        gotoxy(43,19),printf("5. Centro universitario ");
        gotoxy(43,21),printf("Selección: ");
        scanf("%i",&opc);

        if(opc == 1){
            char busc_nombre[30];
            fflush(stdin);
            
            gotoxy(20,23),printf("Ingrese el nombre a buscar:");
            gets(busc_nombre);
            for(int i=0;i<cont;i++){
                if(strcmp(busc_nombre,agen[i].person.nombre)==0){ //función para buscar nombre
                    gotoxy(43,25),printf("Buscando resultados...");
                    Sleep(2000);
                    system("cls");
                    
                    recuadro(1, 0, 121, 38);
                    recuadro(30, 2, 100, 5);
                    gotoxy(37,4),printf("\t\t\t   ALUMNO #%i",i+1);
                
                    gotoxy(2,8),printf("-------------------------------------------------------");
                    gotoxy(2,9),printf("\t\tDATOS PERSONALES");
                    gotoxy(2,10),printf("-------------------------------------------------------");
                
                    gotoxy(3,11),printf("Nombre: %s",agen[i].person.nombre);
                    gotoxy(3,12),printf("Domicilio: %s",agen[i].person.domicilio);
                    gotoxy(3,13),printf("Colonia: %s",agen[i].person.colonia);
                    gotoxy(3,14),printf("Código postal: %i",agen[i].person.CP);
                    gotoxy(3,15),printf("Ciudad: %s",agen[i].person.ciudad);
                    gotoxy(3,16),printf("Teléfono: %s",agen[i].person.telefono);
                    gotoxy(3,16),printf("Email: %s",agen[i].person.email);
                    gotoxy(3,17),printf("Sexo: %s",agen[i].person.sexo);
                    gotoxy(3,18),printf("Edad: %i",agen[i].person.edad);
                    gotoxy(3,19),printf("Notas: %s",agen[i].person.notas);
                
                    gotoxy(2,22),printf("-------------------------------------------------------");
                    gotoxy(3,23),printf("\t\tDATOS ACADÉMICOS\n");
                    gotoxy(2 ,24),printf("-------------------------------------------------------");
                    gotoxy(3,25),printf("Código: %s",agen[i].acad.codigo);
                    gotoxy(3,26),printf("Carrera: %s",agen[i].acad.carrera);
                    gotoxy(3,27),printf("Semestre: %i",agen[i].acad.semestre);
                    gotoxy(3,28),printf("Centro universitario: %s",agen[i].acad.escuela);
                    gotoxy(3,29),printf("Promedio: %.2f",agen[i].acad.promedio);
                
                   gotoxy(4,32),system("pause");
                    band=1; //bandera
                }
            }
            if(band==0){
                gotoxy(20,26),printf("El nombre que ingresó no existe en nuestra base de datos...");
                Sleep(2000);
            }
        }
        else
        if(opc == 2){
            char busc_telefono[20];
            gotoxy(20,23),printf("Ingrese el teléfono a buscar:");
            scanf("%s",&busc_telefono);
            
            for(int i=0;i<cont;i++){
                if(strcmp(busc_telefono,agen[i].person.telefono)==0){ //buscar con el numero de telefono 
                    
                    gotoxy(43,25),printf("Buscando resultados...");
                    Sleep(2000);
                    system("cls");
                    
                    recuadro(1, 0, 121, 38);
                    recuadro(30, 2, 100, 5);
                    gotoxy(37,4),printf("\t\t\t   ALUMNO #%i",i+1);
                
                    gotoxy(2,8),printf("-------------------------------------------------------");
                    gotoxy(2,9),printf("\t\tDATOS PERSONALES");
                    gotoxy(2,10),printf("-------------------------------------------------------");
                
                    gotoxy(3,11),printf("Nombre: %s",agen[i].person.nombre);
                    gotoxy(3,12),printf("Domicilio: %s",agen[i].person.domicilio);
                    gotoxy(3,13),printf("Colonia: %s",agen[i].person.colonia);
                    gotoxy(3,14),printf("Código postal: %i",agen[i].person.CP);
                    gotoxy(3,15),printf("Ciudad: %s",agen[i].person.ciudad);
                    gotoxy(3,16),printf("Teléfono: %s",agen[i].person.telefono);
                    gotoxy(3,16),printf("Email: %s",agen[i].person.email);
                    gotoxy(3,17),printf("Sexo: %s",agen[i].person.sexo);
                    gotoxy(3,18),printf("Edad: %i",agen[i].person.edad);
                    gotoxy(3,19),printf("Notas: %s",agen[i].person.notas);
                
                    gotoxy(2,22),printf("-------------------------------------------------------");
                    gotoxy(3,23),printf("\t\tDATOS ACADÉMICOS\n");
                    gotoxy(2 ,24),printf("-------------------------------------------------------");
                    gotoxy(3,25),printf("Código: %s",agen[i].acad.codigo);
                    gotoxy(3,26),printf("Carrera: %s",agen[i].acad.carrera);
                    gotoxy(3,27),printf("Semestre: %i",agen[i].acad.semestre);
                    gotoxy(3,28),printf("Centro universitario: %s",agen[i].acad.escuela);
                    gotoxy(3,29),printf("Promedio: %.2f",agen[i].acad.promedio);
                
                    gotoxy(4,32),system("pause");				
                    band=1; 
                }
            }
            if(band==0){
                gotoxy(20,26),printf("El teléfono que ingresó no existe en nuestra base de datos.");
                Sleep(2000);
            }
        }
        else
        if(opc == 3){
            char busc_codigo[10];
            gotoxy(20,23),printf("Ingrese el código a buscar:");
            scanf("%s",&busc_codigo);
            
            for(int i=0;i<cont;i++){
                if(strcmp(busc_codigo,agen[i].acad.codigo)==0){ //buscar con el código de estudiante
                
                    gotoxy(43,25),printf("Buscando resultados...");
                    Sleep(2000);
                    system("cls");
                    
                    recuadro(1, 0, 121, 38);
                    recuadro(30, 2, 100, 5);
                    gotoxy(37,4),printf("\t\t\t   ALUMNO #%i",i+1);
                
                    gotoxy(2,8),printf("-------------------------------------------------------");
                    gotoxy(2,9),printf("\t\tDATOS PERSONALES");
                    gotoxy(2,10),printf("-------------------------------------------------------");
                
                    gotoxy(3,11),printf("Nombre: %s",agen[i].person.nombre);
                    gotoxy(3,12),printf("Domicilio: %s",agen[i].person.domicilio);
                    gotoxy(3,13),printf("Colonia: %s",agen[i].person.colonia);
                    gotoxy(3,14),printf("Código postal: %i",agen[i].person.CP);
                    gotoxy(3,15),printf("Ciudad: %s",agen[i].person.ciudad);
                    gotoxy(3,16),printf("Teléfono: %s",agen[i].person.telefono);
                    gotoxy(3,16),printf("Email: %s",agen[i].person.email);
                    gotoxy(3,17),printf("Sexo: %s",agen[i].person.sexo);
                    gotoxy(3,18),printf("Edad: %i",agen[i].person.edad);
                    gotoxy(3,19),printf("Notas: %s",agen[i].person.notas);
                
                    gotoxy(2,22),printf("-------------------------------------------------------");
                    gotoxy(3,23),printf("\t\tDATOS ACADÉMICOS\n");
                    gotoxy(2 ,24),printf("-------------------------------------------------------");
                    gotoxy(3,25),printf("Código: %s",agen[i].acad.codigo);
                    gotoxy(3,26),printf("Carrera: %s",agen[i].acad.carrera);
                    gotoxy(3,27),printf("Semestre: %i",agen[i].acad.semestre);
                    gotoxy(3,28),printf("Centro universitario: %s",agen[i].acad.escuela);
                    gotoxy(3,29),printf("Promedio: %.2f",agen[i].acad.promedio);
                
                    gotoxy(4,32),system("pause");                   
                    band=1; 
                }
            }
            if(band==0){
                gotoxy(20,26),printf("El código que ingresó no existe nuestra base de datos.");
                Sleep(2000);
            }
        }
        else
        if(opc == 4){
            char busc_carrera[30];
            gotoxy(20,23),printf("Ingrese la carrera a buscar:");
            scanf("%s",&busc_carrera);
            
            for(int i=0;i<cont;i++){
                if(strcmp(busc_carrera,agen[i].acad.carrera)==0){ //buscar con la carrera 
                
                    gotoxy(43,25),printf("Buscando resultados...");
                    Sleep(2000);
                    system("cls");
                    
                    recuadro(1, 0, 121, 38);
                    recuadro(30, 2, 100, 5);
                    gotoxy(37,4),printf("\t\t\t   ALUMNO #%i",i+1);
                
                    gotoxy(2,8),printf("-------------------------------------------------------");
                    gotoxy(2,9),printf("\t\tDATOS PERSONALES");
                    gotoxy(2,10),printf("-------------------------------------------------------");
                
                    gotoxy(3,11),printf("Nombre: %s",agen[i].person.nombre);
                    gotoxy(3,12),printf("Domicilio: %s",agen[i].person.domicilio);
                    gotoxy(3,13),printf("Colonia: %s",agen[i].person.colonia);
                    gotoxy(3,14),printf("Código postal: %i",agen[i].person.CP);
                    gotoxy(3,15),printf("Ciudad: %s",agen[i].person.ciudad);
                    gotoxy(3,16),printf("Teléfono: %s",agen[i].person.telefono);
                    gotoxy(3,16),printf("Email: %s",agen[i].person.email);
                    gotoxy(3,17),printf("Sexo: %s",agen[i].person.sexo);
                    gotoxy(3,18),printf("Edad: %i",agen[i].person.edad);
                    gotoxy(3,19),printf("Notas: %s",agen[i].person.notas);
                
                    gotoxy(2,22),printf("-------------------------------------------------------");
                    gotoxy(3,23),printf("\t\tDATOS ACADÉMICOS\n");
                    gotoxy(2 ,24),printf("-------------------------------------------------------");
                    gotoxy(3,25),printf("Código: %s",agen[i].acad.codigo);
                    gotoxy(3,26),printf("Carrera: %s",agen[i].acad.carrera);
                    gotoxy(3,27),printf("Semestre: %i",agen[i].acad.semestre);
                    gotoxy(3,28),printf("Centro universitario: %s",agen[i].acad.escuela);
                    gotoxy(3,29),printf("Promedio: %.2f",agen[i].acad.promedio);
                
                    gotoxy(4,32),system("pause");  
                    band=1; 
                }
            }
            if(band==0){
                gotoxy(20,26),printf("La carrera que ingresó no existe en nuestra base de datos..");
                Sleep(2000);
            }
        }
        else
        if(opc == 5){
            char busc_centro[30];
            gotoxy(20,23),printf("Ingrese el centro universitario a buscar:"); //buscar con la escuela
            scanf("%s",&busc_centro);
            
            for(int i=0;i<cont;i++){
                if(strcmp(busc_centro,agen[i].acad.escuela)==0){ 
                    gotoxy(43,25),printf("Buscando resultados...");
                    Sleep(2000);
                    system("cls");
                    
                    recuadro(1, 0, 121, 38);
                    recuadro(30, 2, 100, 5);
                    gotoxy(37,4),printf("\t\t\t   ALUMNO #%i",i+1);
                
                    gotoxy(2,8),printf("-------------------------------------------------------");
                    gotoxy(2,9),printf("\t\tDATOS PERSONALES");
                    gotoxy(2,10),printf("-------------------------------------------------------");
                
                    gotoxy(3,11),printf("Nombre: %s",agen[i].person.nombre);
                    gotoxy(3,12),printf("Domicilio: %s",agen[i].person.domicilio);
                    gotoxy(3,13),printf("Colonia: %s",agen[i].person.colonia);
                    gotoxy(3,14),printf("Código postal: %i",agen[i].person.CP);
                    gotoxy(3,15),printf("Ciudad: %s",agen[i].person.ciudad);
                    gotoxy(3,16),printf("Teléfono: %s",agen[i].person.telefono);
                    gotoxy(3,16),printf("Email: %s",agen[i].person.email);
                    gotoxy(3,17),printf("Sexo: %s",agen[i].person.sexo);
                    gotoxy(3,18),printf("Edad: %i",agen[i].person.edad);
                    gotoxy(3,19),printf("Notas: %s",agen[i].person.notas);
                
                    gotoxy(2,22),printf("-------------------------------------------------------");
                    gotoxy(3,23),printf("\t\tDATOS ACADÉMICOS\n");
                    gotoxy(2 ,24),printf("-------------------------------------------------------");
                    gotoxy(3,25),printf("Código: %s",agen[i].acad.codigo);
                    gotoxy(3,26),printf("Carrera: %s",agen[i].acad.carrera);
                    gotoxy(3,27),printf("Semestre: %i",agen[i].acad.semestre);
                    gotoxy(3,28),printf("Centro universitario: %s",agen[i].acad.escuela);
                    gotoxy(3,29),printf("Promedio: %.2f",agen[i].acad.promedio);
                
                    gotoxy(4,32),system("pause");                
                    
                    band=1; 
                }
            }
            if(band==0){
                gotoxy(20,26),printf("El centro universitario que ingresó no existe en nuestra base de datos.");
                Sleep(2000);
            }
        }
        else{
            gotoxy(20,26),printf("La opción que ingresó NO existe. ");
            Sleep(2000);
        }
    }
    else{
        gotoxy(45,20),printf("No se puede buscar ningún registro");
        gotoxy(45,21),printf("  debido a que este está vacío. ");
        gotoxy(45,22),printf("     Realice al menos uno.");
        Sleep(2000);
    }
}
