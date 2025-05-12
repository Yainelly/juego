//Librerias utilizadas en el programa:

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib> // Para rand (para la ruta de hackeo)
#include <ctime> // Para time (para la ruta de hackeo)
#include <limits> //para usar numeric_limits

using namespace std;

//Prototipo de funcion de menu
void mostrarMenu();

//Prototipo de funcion para ver instrucciones de menu
void mostrarInstrucciones();

void iniciarJuego();

//Prototipos de final alterno secreto
void rutaDeHackeo();
string descifrarVigenere(const string&, const string&);

//Prototipo de funcion para salir o continuar
char salirContinuar();

//Prototipos de funciones para facultad de humanidades
void getHUMA();
bool HUMAanswer1(int&); 
bool HUMAanswer2(int&); 
bool HUMAanswer3(int&);

//Prototipos de funciones para facultad de educacion
void getEDU();
bool EDUanswer1(int&);
bool EDUanswer2(int&);
bool EDUanswer3(int&);

//Prototipos de funciones para facultad de arquitectura
void getARQ();
bool ARQanswer1(string&);
bool ARQanswer2(string&);
bool ARQanswer3(string&);
bool ARQanswer4(string&);

// Prototipos de funciones para faculdad de naturales 
void getNATU();
bool NATUanswer1(int&);
bool NATUanswer2(int&);
bool NATUanswer3(int&);
bool NATUanswer4(int&);

//Prototipos de funciones para facultad de Admi
void getADMI();
bool ADMIanswer1();
bool ADMIcesarChallenge(string&); 

//Prototipo de la funcion del final 
void getCENTRO();
string descifrarFinal(string&, string&);


//Constante global de cantidad de vidas
int VIDAS = 4;


//Funcion main
int main(){

    //Se invoca funcion menu
    mostrarMenu();
        
    return 0; 
}

//===================== FUNCIONES =====================

void mostrarMenu() {

    int opcion;

    do{
        cout << "\n==============================================" << endl;
        cout << "|              THE LOST ARCHIVE              |" << endl;
        cout << "|                                            |" << endl;
        cout << "|                                            |" << endl;
        cout << "|                                            |" << endl;
        cout << "|                MENÚ OPCIONES:              |" << endl;
        cout << "|                                            |" << endl;
        cout << "|            [1]- Iniciar juego              |" << endl;
        cout << "|            [2]- Ver instrucciones          |" << endl;
        cout << "|            [3]- Ver créditos               |" << endl;
        cout << "|            [4]- Salir del juego            |" << endl;
        cout << "|                                            |" << endl;
        cout << "==============================================" << endl;
        cout << "Selecciona una opción: ";


        cin >> opcion;

        //Input Validation por si el usuario ingresa una letra
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada no válida. Intenta de nuevo.\n";
            continue;
        }
            

        if (opcion == 1) {

            //Invocacion de funcion de iniciar juego
            iniciarJuego();
        }

        else if (opcion == 2) {

            //Invocacion de funcion para ver las instrucciones
            mostrarInstrucciones();
        }

        else if (opcion == 3) {

            cout << "\nAquí le damos créditos a cada persona que aportó a este proyecto:" << endl;

            cout << "\nEstudiantes de la Universidad de Puerto Rico Recinto de Río Piedras:" << endl;

            cout << "\nAriana P. Rivera Alejandro" << endl;
            cout << "Amanda Rosado Rosado" << endl;
            cout << "Yainelly Ortiz Serrano" << endl;

            cout << "\nPresiona Enter para volver al menú..." << endl;

            cin.ignore(); // Limpia cualquier entrada residual (si viene de un cin >> antes)
            cin.get();     // Espera a que el usuario presione Enter
        }

        else if (opcion == 4) {

            cout << "¡Gracias por jugar!" << endl;
            cin.ignore(); // Limpia cualquier entrada residual (si viene de un cin >> antes)
            cin.get();     // Espera a que el usuario presione Enter
            exit(0);
        }

        else {

            cout << "\nOpción inválida, intente de nuevo. " << endl;
        }

    } 
    //Bucle infinito hasta que elija salir
    while (true); 
}

//================TERMINA FUNCION MENU=================================

void mostrarInstrucciones() {

    cout << "\n\nPor si no entiendes lo que estás a punto de jugar, déjame explicarle..." << endl;

    cout << "Esto es un 'Text Adventure Game', ¿pero qué significa eso?" << endl;
    cout << "\nEs un tipo de videojuego donde la interacción del jugador " << endl;
    cout << "con el juego se realiza a través de comandos de texto, la información " << endl;
    cout << "sobre el entorno y la historia se presenta también como texto." << endl;
    cout << "En esencia, el jugador teclea sus acciones, y el juego responde " << endl;
    cout << "con descripciones textuales de los resultados." << endl;

    cout << "\nLuego de esa humilde explicación..." << endl;

    //Las instrucciones que el jugador debe de seguir durante todo el juego
   cout << "\n\n   Aquí están las instrucciones que debe de seguir el jugador en todo momento mientras esté jugando: " << endl;

    

    cout << "\n1. Este juego tiene un sistema de vidas que funciona de esta manera: " << endl;

    cout << "- Empiezas teniendo 5 vidas; si llegas mínimo con una vida al final del juego, significa que lo lograste." << endl;
    cout << "- Si pierdes todas tus vidas antes de poder terminar la partida, tendrás la opción de reiniciarla o salir del juego." << endl;
    cout << "- No podrás revivir en donde dejaste la partida, así que toma tus decisiones con precaución." << endl;
    cout << "- Mucho cuidado con los 'typos' o cosas mal escritas en general, podría costarte más de una vida dependiendo el nivel." << endl;

    cout << "\n2. La jugabilidad es bastante sencilla." << endl;
    cout << "- El juego está dividido en varios niveles; cada facultad es un nuevo nivel." << endl;
    cout << "- Cada vez que empieces un nuevo nivel, el sistema te dirá sus instrucciones, así que asegúrate de leer bien." << endl;
    cout << "- La mayoría serán opciones enumeradas, es cuestión de escribir solo el número que desea y darle 'enter'." << endl;


    cout << "\n3. Opciones in-game: " << endl;
    cout << "- Siempre va a tener la opción de terminar el juego y volver al menú o de salir del juego desde la misma partida." << endl;
    cout << "- Habrá momentos en los que sus decisiones determinarán el orden o desarrollo de la historia." << endl;

    cout << "\nPresiona Enter para volver al menú...";

    cin.ignore(); // Limpia cualquier entrada residual (si viene de un cin >> antes)
    cin.get();     // Espera a que el usuario presione Enter
}

//================TERMINA FUNCION INSTRUCCIONES MENU==============

//================FUNCION PARA CONTINUAR O SALIR==================

char salirContinuar() {
    char respuesta;
    if(VIDAS > 0){
        do {

            cin >> respuesta;

            if (respuesta != 'C' && respuesta != 'c' && respuesta != 'S' && respuesta != 's') {
                cout << "Entrada no válida. Por favor, escriba solo 'C' o 'S'." << endl;
            }

        } while (respuesta != 'C' && respuesta != 'c' && respuesta != 's' && respuesta != 'S');

        return respuesta;
    }
    else if(VIDAS <= 0){
        do {

            cin >> respuesta;

            if (respuesta != 'S' && respuesta != 's') {
                cout << "Entrada no válida. Por favor, escriba solo 'S'." << endl;
            }

        } while (respuesta != 's' && respuesta != 'S');

        return respuesta;
    }

}

//Definicion de funciones de facultad de humanidades
void getHUMA( ) {
    int respuesta;
    char respuesta2;

    //contexto del area
    cout << "\n*** DEPT. DE HUMANIDADES ***" << endl;
    cout << "En un salón lleno de retratos, cuatro de ellos sus rostros han desaparecido." 
         << " Debido a la anomalía del archivo central, han desvanecido sus caratulas." 
         << " Si logras descifrar cada uno de estos retratos lograrás obtener el código encriptado"
         << " del Departamento de Humanidades para activar el archivo central y escapar de ese cuarto.\n";
    cout << endl;

    if (HUMAanswer1(respuesta)) {
        cout <<"¡Excelente, lo lograste! Continuemos... \n" << endl;

        if (HUMAanswer2(respuesta)) {
            cout <<"¡Excelente, estás hecho un historiador! Continuemos... \n" << endl;

            if (HUMAanswer3(respuesta)) {
                cout <<"¡Haz logrado escapar del Departamento de Humanidades! Presiona C para continuar o S para salir.\n" << endl;
                
            } else {
                cout << "Los fragmentos no pudieron ser restaurados. La memoria del recinto se ha perdido... por ahora.\n";
                cout << "Presiona S para salir.\n" << endl;
            }
        } else {
            cout << "Los fragmentos no pudieron ser restaurados. La memoria del recinto se ha perdido... por ahora.\n";
            cout << "Presiona S para salir." << endl;
        }
    } else {
        cout << "Los fragmentos no pudieron ser restaurados. La memoria del recinto se ha perdido... por ahora.\n";
        cout << "Presiona S para salir." << endl;
    }


    char decision = salirContinuar();

    if (decision == 's' || decision == 'S') {
        mostrarMenu();
    } else {
        getEDU();
    }

}


bool HUMAanswer1(int& entry) {
    cout << "\tA. Primer retrato:\n";
    cout << "El retrato era de antigua Grecia y vestía con túnicas blancas sosteniendo un libro de filosofía.\n\n";

    cout << "¿Quién podrá ser?\n";
    cout << "1. Jean-Paul Sartre\n"
         << "2. René Descartes\n"
         << "3. Platón\n\n";

    while (VIDAS > 0) {
        cout << "Respuesta: ";
        cin >> entry;

        // Validación de input
        if (cin.fail() || entry < 1 || entry > 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada no válida. Intente de nuevo.\n\n";
            continue;
        }

        if (entry == 3) {
            return true;
        } else {
            VIDAS--;
            cout << "\nRespuesta incorrecta. Intente de nuevo.\n";
            cout << "Le quedan " << VIDAS << " vidas para jugar.\n\n";
        }
    }

    // Si se queda sin vidas
    return false;
}


bool HUMAanswer2(int& entry) {
    cout << "\tA. Segundo retrato:\n";
    cout << "El retrato era del siglo XX y vestía un juego de traje, chaleco y pantalón negro sosteniendo un cigarro en la mano.\n\n";

    cout << "¿Quién podrá ser?\n";
    cout << "1. Sigmund Freud\n"
         << "2. Immanuel Kant\n"
         << "3. Sócrates\n\n";

    while (VIDAS > 0) {
        cout << "Respuesta: ";
        cin >> entry;

        // Validación de entrada
        if (cin.fail() || entry < 1 || entry > 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada no válida. Intente de nuevo.\n\n";
            continue;
        }

        if (entry == 1) {
            return true;
        } else {
            VIDAS--;
            cout << "\nRespuesta incorrecta. Intente de nuevo.\n";
            cout << "Le quedan " << VIDAS << " vidas para jugar.\n\n";
        }
    }

    return false;
}


bool HUMAanswer3(int& entry) {
    cout << "\tA. Tercer retrato:\n";
    cout << "El retrato era del siglo XIX y vestía una bata de laboratorio acompañado de su placa petri.\n\n";

    cout << "¿Quién podrá ser?\n";
    cout << "1. Michel Foucault\n"
         << "2. Alexander Fleming\n"
         << "3. John Locke\n\n";

    while (VIDAS > 0) {
        cout << "Respuesta: ";
        cin >> entry;

        // Validación de entrada
        if (cin.fail() || entry < 1 || entry > 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada no válida. Intente de nuevo.\n\n";
            continue;
        }

        if (entry == 2) {
            return true;
        } else {
            VIDAS--;
            cout << "\nRespuesta incorrecta. Intente de nuevo.\n";
            cout << "Le quedan " << VIDAS << " vidas para jugar.\n\n";
        }
    }

    return false;
}

//===========================SE TERMINA FACULTAD DE HUMA===============================

void getEDU( ) {

    int respuesta;

    cout << "\n*** DEPARTAMENTO DE EDUCACIÓN ***" << endl;

    cout << "\nLas paredes están cubiertas de pizarras con notas borrosas y esquemas inconclusos. " << endl;
    cout << "El mobiliario está desordenado, como si alguien hubiera interrumpido una clase para siempre. " << endl;
    cout << "En el centro del salón, una mesa circular con sillas vacías emite una tenue luz. " << endl;

    cout << "\nEncima, una nota digital parpadea: " << endl;
    cout << "\"Para restaurar el plan de formación, debes tomar decisiones pedagógicas como si tuvieras un grupo real frente a ti.\"\n\n" << endl;

    cout << "Solo si logras actuar con empatía, intuición y lógica, el sistema revelará el código encriptado del Departamento de Educación " << endl;
    cout << "y abrirá el acceso al siguiente nivel del archivo central.\n";
    cout << endl;


    if (EDUanswer1(respuesta)) {
        cout <<"¡Muy bien, lo lograste! Continuemos... \n" <<endl;

        if (EDUanswer2(respuesta)) {
            cout <<"¡Excelente, te pusiste en los zapatos de un maestro! Continuemos... \n" <<endl;

            if (EDUanswer3(respuesta)) {
                cout <<"¡Haz logrado escapar del Departamento de Educación! Presiona C para continuar o S para salir.\n" <<endl;


            } else {
                cout << "Los fragmentos no pudieron ser restaurados. La memoria del recinto se ha perdido... por ahora.\n";
                cout << "Presiona S para salir.\n" << endl;
            }
        } else {
            cout << "Los fragmentos no pudieron ser restaurados. La memoria del recinto se ha perdido... por ahora.\n";
            cout << "Presiona S para salir.\n" << endl;
        }
    } else {
        cout << "Los fragmentos no pudieron ser restaurados. La memoria del recinto se ha perdido... por ahora.\n";
        cout << "Presiona S para salir.\n" <<endl;
    }

    char decision = salirContinuar();

    if (decision == 's' || decision == 'S') {
        mostrarMenu();
    } else {
        getARQ();
    }
}


bool EDUanswer1(int& entry) {
    cout << "\tA. Primer escenario:\n\n";
    cout << "Planificaste una clase con mucho esfuerzo, pero los estudiantes no parecen entender. ¿Cómo respondes?.\n\n";
    
    cout << "\n1. Culpó a los estudiantes por no cooperar." << endl;

    cout << "2. Reflexionó y buscó ajustar la estrategia para la próxima." << endl;

    cout << "3. Uso la misma clase y estrategia otra vez; tal vez funcione mejor." << endl;


    while (VIDAS > 0) {
        cout << "Respuesta: ";
        cin >> entry;

        // Validación de input
        if (cin.fail() || entry < 1 || entry > 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada no válida. Intente de nuevo.\n\n";
            continue;
        }

        if (entry == 2) {
            return true;
        } else {
            VIDAS--;
            cout << "\nRespuesta incorrecta. Intente de nuevo.\n";
            cout << "Le quedan " << VIDAS << " vidas para jugar.\n\n";
        }
    }

    // Si se queda sin vidas
    return false;
}


bool EDUanswer2(int& entry) {
    cout << "\tB. Segundo escenario:\n\n";
    cout << "\nVes que un estudiante llega al salón de clases con nuevos moretones y con una expresión vacía." << endl;
    cout << "Sientes que algo está mal, ¿qué deberías de hacer?" << endl;
    
    cout << "\n1. Lo ignoró, no es mi responsabilidad como maestra/o." << endl;
    cout << "2. Lo señalas frente a la clase para que explique qué le pasó." << endl;
    cout << "3. Lo llevas a un rincón y le preguntas suavemente si todo está bien." << endl;

    while (VIDAS > 0) {
        cout << "Respuesta: ";
        cin >> entry;

        // Validación de input
        if (cin.fail() || entry < 1 || entry > 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada no válida. Intente de nuevo.\n\n";
            continue;
        }

        if (entry == 3) {
            return true;
        } else {
            VIDAS--;
            cout << "\nRespuesta incorrecta. Intente de nuevo.\n";
            cout << "Le quedan " << VIDAS << " vidas para jugar.\n\n";
        }
    }

    // Si se queda sin vidas
    return false;
}


bool EDUanswer3(int& entry) {
    cout << "\tC. Tercer escenario:\n\n";
    cout << "\nHay un estudiante tratando de llamar constantemente la atención de sus compañeros, interrumpiendo la clase." << endl;
    cout << "Te está empezando a molestar, ¿qué acercamiento deberías de hacerle?" << endl;
    
    cout << "\n1. Le llamas la atención duramente frente a todos para que aprenda la lección." << endl;
    cout << "2. Ignoras su conducta con la esperanza de que se calme por sí solo." << endl;
    cout << "3. Te acercas con calma y en privado, buscando entender qué está causando su conducta." << endl;


    while (VIDAS > 0) {
        cout << "Respuesta: ";
        cin >> entry;

        // Validación de input
        if (cin.fail() || entry < 1 || entry > 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada no válida. Intente de nuevo.\n\n";
            continue;
        }

        if (entry == 3) {
            return true;
        } else {
            VIDAS--;
            cout << "\nRespuesta incorrecta. Intente de nuevo.\n";
            cout << "Le quedan " << VIDAS << " vidas para jugar.\n\n";
        }
    }

    // Si se queda sin vidas
    return false;
}


//===========================SE TERMINA FACULTAD DE EDUCACION==========================

// Variable global para el mensaje final de Arquitectura
string mensajeARQ = "ESTA EN EL CENTRO";


void getARQ( ){
    string respuesta;

    cout << "\n*** DEPARTAMENTO DE ARQUITECTURA ***" << endl;

    cout << "\n¡Bienvenidos al Departamento de Arquitectura!" << endl;
    cout << "Donde aprendemos sobre las edificaciones y el soporte de cada construcción." << endl;
    cout << "Incluyendo el de nuestro propio recinto." << endl;

    cout << "\nDebido a la anomalía del archivo central, todas nuestras copias digitales fueron corrompidas." << endl;
    cout << "Para restaurar los planos de cada departamento necesitamos una llave secreta." << endl;

    cout << "Necesitamos de tu ayuda para encontrar esa llave secreta y poder salvar los planos del recinto." << endl;
    cout << "*** PISTA: El mapa anejo en el Read.Me ***"<<endl;
    cout << endl;
    cout << "Aún nos faltan las llaves de los siguientes departamentos: \n";
    cout << endl;

    if (ARQanswer1(respuesta)) {
        cout <<"¡Uff un plano más! Continuemos... \n" << endl;

        if (ARQanswer2(respuesta)) {
            cout <<"¡Qué bueno, los necesitamos! Continuemos... \n" << endl;

            if (ARQanswer3(respuesta)) {
                cout <<"¡Tremenda memoria que tienes! Continuemos...\n" << endl;

                if (ARQanswer4(respuesta)) {
                    cout <<"¡Haz logrado escapar del Departamento de Arquitectura! Presiona C para continuar o S para salir.\n" << endl;

                } else {
                    cout << "Los fragmentos no pudieron ser restaurados. La memoria del recinto se ha perdido... por ahora.\n";
                    cout << "Presiona S para salir\n" << endl;
                }    

            } else {
                cout << "Los fragmentos no pudieron ser restaurados. La memoria del recinto se ha perdido... por ahora.\n";
                cout << "Presiona S para salir.\n" <<endl;
            }

        } else {
            cout << "Los fragmentos no pudieron ser restaurados. La memoria del recinto se ha perdido... por ahora.\n";
            cout << "Presiona S para salir.\n" <<endl;
        }

    } else {
        cout << "Los fragmentos no pudieron ser restaurados. La memoria del recinto se ha perdido... por ahora.\n";
        cout << "Presiona S para salir.\n" <<endl;
    }

    char decision = salirContinuar();

    if (decision == 's' || decision == 'S') {
        mostrarMenu();
    } else {
        getNATU();
    }
}


bool ARQanswer1(string& llave){
    string answer = "TSAE";
    cout << "1. Centro de Estudiantes\n";

    while (VIDAS > 0) {
        cout << "Entra la llave: ";
        cin >> llave;

        if (llave == answer)
            return true;

        // Validación de input
        if (llave != answer) {
            VIDAS--;
            cout << "\nRespuesta incorrecta. Intente de nuevo.\n";
            cout << "Le quedan " << VIDAS << " vidas para jugar.\n\n";
        }
    }
    //Si se queda sin vidas
    return false;
}

bool ARQanswer2(string& llave){
    string answer = "LEEN";
    cout << "2. Deportivo\n";

    while (VIDAS > 0) {
        cout << "Entra la llave: ";
        cin >> llave;

        if (llave == answer)
            return true;

        // Validación de input
        if (llave != answer) {
            VIDAS--;
            cout << "\nRespuesta incorrecta. Intente de nuevo.\n";
            cout << "Le quedan " << VIDAS << " vidas para jugar.\n\n";
        }
    }
    return false;
}

bool ARQanswer3(string& llave){
    string answer = "NECT";
    cout << "3. Centro de Estudiantes\n";

    while (VIDAS > 0) {
        cout << "Entra la llave: ";
        cin >> llave;

        if (llave == answer)
            return true;

        // Validación de input
        if (llave != answer) {
            VIDAS--;
            cout << "\nRespuesta incorrecta. Intente de nuevo.\n";
            cout << "Le quedan " << VIDAS << " vidas para jugar.\n\n";
        }
    }
    return false;
}
bool ARQanswer4(string& llave){
    string answer = "OR";
    cout << "4. Torre\n";

    while (VIDAS > 0) {
        cout << "Entra la llave: ";
        cin >> llave;

        if (llave == answer)
            return true;

        // Validación de input
        if (llave != answer) {
            VIDAS--;
            cout << "\nRespuesta incorrecta. Intente de nuevo.\n";
            cout << "Le quedan " << VIDAS << " vidas para jugar.\n\n";
        }
    }
    return false;
}

// ========================== FACULTAD DE NATURALES ===============================

void getNATU() {
    int respuesta;

    cout << "\n*** DEPARTAMENTO DE CIENCIAS NATURALES ***" << endl;
    cout << "\n¡No puede ser! Has caído en una trampa dentro del laboratorio del Departamento de Ciencias Naturales. " << endl;
    cout << "Un científico dejó una nota diciendo: “Si mis plantas no se salvan, nadie verá la luz del día.” " << endl;
    cout << "Para poder escapar necesitas salvar cada planta del laboratorio.\n" << endl;

    if (NATUanswer1(respuesta)) {
        cout << "¡Primera planta salvada! Continuemos... \n\n";

        if (NATUanswer2(respuesta)) {
            cout << "¡Segunda planta recuperada! Continuemos... \n\n";

            if (NATUanswer3(respuesta)) {
                cout << "¡Tercera planta sana y fuerte! Solo una más... \n\n";

                if (NATUanswer4(respuesta)) {
                    cout << "¡Has logrado escapar del Departamento de Ciencias Naturales! Presiona C para continuar o S para salir.\n" << endl;

                } else {
                    cout << "Los fragmentos no pudieron ser restaurados. La memoria del recinto se ha perdido... por ahora.\n";
                    cout << "Presiona S para salir.\n" << endl;
                }

            } else {
                cout << "Los fragmentos no pudieron ser restaurados. La memoria del recinto se ha perdido... por ahora.\n";
                cout << "Presiona S para salir.\n" << endl;
            }

        } else {
            cout << "Los fragmentos no pudieron ser restaurados. La memoria del recinto se ha perdido... por ahora.\n";
            cout << "Presiona S para salir.\n" << endl;
        }

    } else {
        cout << "Los fragmentos no pudieron ser restaurados. La memoria del recinto se ha perdido... por ahora.\n";
        cout << "Presiona S para salir.\n" << endl;
    }

    char decision = salirContinuar();

    if (decision == 's' || decision == 'S') {
        mostrarMenu();
    } else {
        getADMI();
    }
}
 
bool NATUanswer1(int& entry) {
    cout << "\t1. Primer caso:\n\n";
    cout << "Una planta con hojas amarillas y la tierra constantemente húmeda.\n";

    cout << "¿Qué tú harías?\n";
    cout << "1. Aumentar el riego del agua\n";
    cout << "2. Brindarle exposición al sol\n";
    cout << "3. Trasplantarla\n";

    while (VIDAS > 0) {
        cout << "Respuesta: ";
        cin >> entry;

        // validación de input
        if (cin.fail() || entry < 1 || entry > 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada no válida. Intente de nuevo.\n\n";
            continue;
        }

        if (entry == 3) {
            return true;
        } else {
            VIDAS--;
            cout << "\nTristemente, no ingresaste la respuesta correcta pero aún te quedan " << VIDAS << " vidas para continuar. ¡No te rindas!\n\n";
        }
    }
    return false;
}


bool NATUanswer2(int& entry) {
    cout << "\t2. Segundo caso:\n\n";
    cout << "Una planta con hojas marchitas o quebradizas.\n";

    cout << "¿Qué tú harías?\n";
    cout << "1. Aumentar el riego del agua\n";
    cout << "2. Brindarle exposición al sol\n";
    cout << "3. Trasplantarla\n";

    while (VIDAS > 0) {
        cout << "Respuesta: ";
        cin >> entry;

        // validacion de input
        if (cin.fail() || entry < 1 || entry > 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada no válida. Intente de nuevo.\n\n";
            continue;
        }

        if (entry == 1) {
            return true;
        } else {
            VIDAS--;
            cout << "\nTristemente, no ingresaste la respuesta correcta pero aún te quedan " << VIDAS << " vidas para continuar. ¡No te rindas!\n\n";
        }
    }
    return false;
}

bool NATUanswer3(int& entry) {
    cout << "\t3. Tercer caso:\n\n";
    cout << "Una planta que crece débil y sus hojas están pálidas.\n";

    cout << "¿Qué tú harías?\n";
    cout << "1. Desinfectarla con productos especializados\n";
    cout << "2. Brindarle exposición al sol\n";
    cout << "3. Trasplantarla\n";

    while (VIDAS > 0) {
        cout << "Respuesta: ";
        cin >> entry;

        // validacion de input
        if (cin.fail() || entry < 1 || entry > 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada no válida. Intente de nuevo.\n\n";
            continue;
        }

        if (entry == 2) {
            return true;
        } else {
            VIDAS--;
            cout << "\nTristemente, no ingresaste la respuesta correcta pero aún te quedan " << VIDAS << " vidas para continuar. ¡No te rindas!\n\n";
        }
    }
    return false;
}


bool NATUanswer4(int& entry) {
    cout << "\t4. Cuarto caso:\n\n";
    cout << "Los áfidos, ácaros y mosquitos del sustrato han infectado la planta.\n";

    cout << "¿Qué tú harías?\n";
    cout << "1. Desinfectarla con productos especializados\n";
    cout << "2. Brindarle exposición al sol\n";
    cout << "3. Trasplantarla\n";

    while (VIDAS > 0) {
        cout << "Respuesta: ";
        cin >> entry;

        // validacion de input
        if (cin.fail() || entry < 1 || entry > 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada no válida. Intente de nuevo.\n\n";
            continue;
        }

        if (entry == 1) {
            return true;
        } else {
            VIDAS--;
            cout << "\nNo ingresaste la respuesta correcta pero aún te quedan " << VIDAS << " vidas para continuar. ¡No te rindas!\n\n";
        }
    }

    return false;
}


//===========================SE TERMINA FACULTAD DE NATURALES==========================

// =========================== FACULTAD ADMINISTRACION DE EMPRESAS =======================


void getADMI() {
    //string respuesta;

    cout << "\n*** FACULTAD DE ADMINISTRACIÓN DE EMPRESAS ***" << endl;

    cout << "\nBienvenido al corazón del conocimiento empresarial.\n";
    cout << "La computadora del decano está bloqueada. Solo puedes acceder si ingresas la clave correcta.\n";
    cout << "Pista: proviene de la Facultad de Arquitectura.\n\n";

    if (ADMIanswer1(respuesta)) {
        cout << "\n¡Acceso concedido! La computadora del decano se ha desbloqueado...\n";
        cout << "Presiona C para continuar o S para salir...\n" << endl;
    } else {
        cout << "\nClave incorrecta. La computadora sigue bloqueada.\n";
        cout << "Presiona S para salir.\n" << endl;
    }

    char decision = salirContinuar();

    if (decision == 's' || decision == 'S') {
        mostrarMenu();
    } else {
        getCENTRO();
    }
}

bool ADMIanswer1() {
    string claveCorrecta = mensajeARQ;

    cout << "Ingresa la clave para acceder a la computadora del decano: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // esto lo que hace es limpiar el buffer
    getline(cin, llave);

    while (VIDAS > 0) {
        if (llave == claveCorrecta)
            return true;

        VIDAS--;
        cout << "\nClave incorrecta. Intenta de nuevo.\n";
        cout << "Te quedan " << VIDAS << " vidas.\n";
        cout << "Ingresa la clave: ";
        getline(cin, llave);
    }

    return false;
}

// Cifrado Caesar con las claves de la ruta de hackeo
bool ADMIcesarChallenge(string& resultado) {
    const string clavesOriginales[] = {"ARCHIVO", "DIGITAL", "TORRE", "SECRETO"};
    srand(time(0));
    int idx = rand() % 4;
    string clave = clavesOriginales[idx];
    string cifrado;

    // Caesar tiene un desplazamiento de 3 
    int desplazamiento = 3;
    for (char c : clave) {
        char letra = ((c - 'A' + desplazamiento) % 26) + 'A';
        cifrado += letra;
    }

    cout << "\n*** DECODIFICACIÓN NECESARIA ***" << endl;
    cout << "Un mensaje ha aparecido en la computadora:\n";
    cout << "Mensaje cifrado (Caesar +3): " << cifrado << endl;

    cout << "\nIngresa el mensaje descifrado: ";
    getline(cin, resultado);

    // Validación
    return resultado == clave;
}

// ======================================= se acaba la facultad de ADMI ==================================================

// ======================================= FINAL DEL JUEGO ============================================================

// Función de descifrado Vigenère
string descifrarFinal(string& mensaje, string& clave) {
    string resultado;

    for (size_t i = 0; i < mensaje.length(); ++i) {
        char letra = ((mensaje[i] - clave[i % clave.length()] + 26) % 26) + 'A';
        resultado += letra;
    }

    return resultado;
}

void getCENTRO( ) {
    cout << "\n*** ARCHIVO CENTRAL: FINAL DEL JUEGO ***\n";
    cout << "Has llegado al núcleo del sistema.\n";
    cout << "Aquí se encuentra la verdad detrás de la anomalía.\n\n";

    // Claves que el jugador descifró en ADMI (mediante cifrado César)
    const string claves[] = {"ARCHIVO", "DIGITAL", "TORRE", "SECRETO"};
    const string descifrados[] = {"CONOCIMIENTO", "FRAGMENTO", "MEMORIA", "VERDAD"};

    srand(time(0));
    int idx = rand() % 4;

    string msjClaro = descifrados[idx];
    string claveCorrecta = claves[idx];
    string mensajeCifr;

    for (size_t i = 0; i < msjClaro.length(); ++i) {
        char letra = ((msjClaro[i] + claveCorrecta[i % claveCorrecta.length()] - 2 * 'A') % 26) + 'A';
        mensajeCifr += letra;
    }

    cout << "Mensaje cifrado final: " << mensajeCifr << "\n";
    cout << "Usa la clave que descifraste en la Facultad de Administración.\n";

    string claveUser;
    cout << "Introduce la clave (en MAYÚSCULAS): ";
    cin >> claveUser;

    string resultado = descifrarFinal(mensajeCifr, claveUser);

    if (resultado == msjClaro) {
        cout << "\n¡ACCESO CONCEDIDO!\n";
        cout << "Has restaurado el archivo central y salvado el recinto.\n";
        cout << ">>> FIN DEL JUEGO <<<\n" << endl;
        cout << "Presiona S para salir.\n";
    } else {
        cout << "\nClave incorrecta. El archivo central sigue bloqueado.\n";
        cout << ">>> INTÉNTALO NUEVAMENTE DESDE ADMI <<<\n" << endl;
        cout << "Presiona S para salir. \n";
    }
}


void iniciarJuego() {

    //Vuelven a reiniciarse las vidas cada vez que el jugador vuelva a iniciar el juego
    VIDAS = 4;

    string response;

    cout << "\n*** TORRE CENTRAL ***" << endl;
    cout << "Te encuentras frente a la Torre Central del recinto.\n";
    cout << "Desde aquí comienza tu misión para restaurar la memoria digital.\n" << endl;

    cout << "¿Deseas comenzar el juego? (si/no): ";
    cin >> response;

    if (response == "si" || response == "SI" || response == "Si") {
        cout << "\n¡Perfecto! Comienza la misión...\n";
        // aqui empezamos a invocar las funciones para cada facultad y eso

            getHUMA();
            getEDU();
            getARQ();
            getNATU();
            getADMI();
            getCENTRO();
        }

    else {
        cout << "\nRegresando al menú principal...\n";
        return;
    }
}


//========================FINAL ALTERNO======================================

//Definicion de funcion para descifrar Vigenere Code 
string descifrarVigenere(const string& mensaje, const string& clave) {

    string resultado;
    int claveLength = clave.length();

    for (size_t i = 0; i < mensaje.length(); ++i) {
        char mensajeCifr = mensaje[i];
        char fraseClave = clave[i % claveLength];
        char mensajeDescifr = ((mensajeCifr - fraseClave + 26) % 26) + 'A';
        resultado += mensajeDescifr;
    }

    return resultado;

 }


//Definicion de funcion de ruta alterna secreta
void rutaDeHackeo(){

    const string claves[] = {"ARCHIVO", "DIGITAL", "TORRE", "SECRETO"};
    const string descifrados[] = {"CONOCIMIENTO", "FRAGMENTO", "MEMORIA", "VERDAD"};

    srand(time(0));
    int idx = rand() % 4;

    string msjClaro = descifrados[idx];
    string claveCorrecta = claves[idx];
    string mensajeCifr;

    for (size_t i = 0; i < msjClaro.length(); ++i) {
        char letra = ((msjClaro[i] + claveCorrecta[i % claveCorrecta.length()] - 2 * 'A') % 26) + 'A';
        mensajeCifr += letra;
    }

    cout << "\n*** SISTEMA DE ACCESO ALTERNO ***" << endl;
    cout << "Has accedido al canal oculto de la red.\n";
    cout << "Para desbloquear el final secreto, descifra el siguiente mensaje:\n";
    cout << "Mensaje cifrado: " << mensajeCifr << endl;

    string claveUser;
    cout << "Introduce la clave secreta (en MAYÚSCULAS): ";
    cin >> claveUser;

    string resultado = descifrarVigenere(mensajeCifr, claveUser);

    if (resultado == msjClaro) {
        cout << "\n Has logrado hackear el sistema!!\n";
        cout << ">> Pudiste acceder al archivo oculto dentro del sistema.\n";
    } else {
        cout << "\n Clave incorrecta. Acceso denegado.\n";
    }

} 