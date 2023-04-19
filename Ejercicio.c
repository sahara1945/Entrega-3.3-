#include <stdio.h>
#include <mysql.h>
#include <string.h>

int main(int argc, char **argv) {
	
	//Conector para poder acceder a la base de datos
	MYSQL *conn;
	int err;
	//Creamos las variables con las cuales introduciremos los datos  a nuestra bases de datos
	char username[20];
	char password[20];
	//Con esta variable devolveremos al usuario los valores 
	char consulta[100];
	
	//Creamos una connexion al servidor mysql
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	//inicializar la conexion, entrando nuestras claves de acceso y
	//el nombre de la base de datos a la que queremos acceder 
	conn = mysql_real_connect (conn, "localhost","root", "mysql", "juego", 0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexion: %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	//En este caso crearemos la consulta que nos permita poder introducir nuevos usuarios dentro de nuestra base de datos
	//Introduciremos en la base de datos a nuevos usuarios 
	//cuyos datos pedimos al usuario
	for (int i=0; i<3; i++) {
		printf ("Escribe el username y la contraseña del usuario, separados por un blanco\n");
		err = scanf ("%s %s", username, password);
		if (err!=2) {
			printf ("Error al introducir los datos \n");
			exit (1);
		}
	
	//Contruimos el string con el comando SQL
	strcpy (consulta, "INSERT INTO jugador VALUES('");
        //concatenamos el username 
		strcat (consulta, username); 
		strcat (consulta, "','");
        //concatenamos la contraseña 
		strcat (consulta, password); 
		strcat (consulta, "');");
        //Una vez concatamos los datos que tendran el usuario lo imprimimos en pantalla
         printf("consulta = %s\n", consulta);
		// Ahora ya podemos realizar la insercion 
		err = mysql_query(conn, consulta);
                if (err!=0) {
			printf ("Error al introducir datos la base %u %s\n", 
					mysql_errno(conn), mysql_error(conn));
			exit (1);
		}
       // cerrar la conexion con el servidor MYSQL 
	mysql_close (conn);
	exit(0);

	}



	
	
}

