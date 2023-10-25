#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  
  int menu1, menu2, menu3, semestre;
  //Variables antiguas
  string dia;
  string año;
  bool log=false;
  int indice;
  int indice_citas, indice_citas_dis, ID_cancelar, ID_ticket;
  string contraseña;
  vector<string>citas_fecha;
  vector<string>citas_hora;
  vector<string>citas_fecha_dis;
  vector<string>citas_hora_dis;
  vector<string>pass;
  string nombre;
  string apellido;
  int id;
  string mes;
  string fechas;
  string hora;
  vector<string>nombre_estudiante;
  vector<string>apellido_estudiante;
  vector<int>id_estudiante;
  vector<int>semestre_estudiante;
  vector<int>dis_estudiante;

  cout<<"¡Bienvenido al Centro de Atención al Estudiante CAC-UPB!\n";

  while(menu1!=3){
  cout<<"Indique la opción que desea realiar\n";
  cout<<"1. Registrarse\n";
  cout<<"2. Ingresar\n";
  cout<<"3. Salir\n";
  cin>>menu1;

  switch(menu1){
    //Registro-----------------------------
    case 1:
      cout<<"Ingrese el nombre del estudiante: ";
      cin>>nombre;
      cout<<"Ingrese el apellido del estudiante: ";
      cin>>apellido;
      cout<<"Ingrese el ID del estudiante: ";
      cin>>id;
    cout<<"Ingrese el semestre que cursa (Num. enteros): ";
      cin>>semestre;
    cout<<"Indique si padece alguna alguna discapacidad\n";
      cout<<"1. Si\n";
      cout<<"2. No\n";
      cin>>menu2;
      cout<<"Cree su contraseña de estudiante: ";
      cin>>contraseña;
      nombre_estudiante.push_back(nombre);
      apellido_estudiante.push_back(apellido);
      id_estudiante.push_back(id);
      semestre_estudiante.push_back(semestre);
      dis_estudiante.push_back(menu2);
      pass.push_back(contraseña);

  cout<<"¡Registro Exitoso!\n";
  cout<<"Para solicitar su cita ingrese al sistema...\n";
    break;
    //Ingreso------------------------------
    case 2:
      
      cout<<"Ingrese su ID: ";
        cin>>id;
        cout<<"Ingrese su contraseña: ";
        cin>>contraseña;
        for(int i=0; i<id_estudiante.size(); i++){
          if(id_estudiante[i]==id&&pass[i]==contraseña){
            log=true;
            indice=i;
            break;
          }
          else{
            cout<<"Credenciales incorrectas, intente nuevamente\n";
          }
        
        }
      //Inicio del sistema----------------
      cout<<"¡Ingreso con exito! \n";
      while(log==true){
        
      cout<<"Indique la opción que desea realiar"<<endl;
      cout<<"1. Agendar una cita"<<endl;
      cout<<"2. Cancelar una cita"<<endl;
      cout<<"3. Mi Ticket"<<endl;
      cout<<"4. Salir"<<endl;
      cin.ignore();
      cin>>menu3;

        switch(menu3){
          //Agendar cita-----------------------
          case 1:
            cout<<"Ingrese la fecha de la cita"<<endl;
            cout<<"Día: ";
            cin>>dia;
            cout<<"Mes: ";
            cin>>mes;
            cout<<"Año: ";
            cin>>año;
        cout<<"Ingrese la hora de la cita (Hora militar): ";
            cin>>hora;
            fechas=dia+"/"+mes+"/"+año;

          if(semestre_estudiante[indice]==1||dis_estudiante[indice]==1)
            {
              citas_hora_dis.push_back(hora);
              citas_fecha_dis.push_back(fechas);
              indice_citas_dis=citas_fecha_dis.size()-1;
cout<<"Su cita se agendó exitosamente de manera prioritaria para la fecha: "<<citas_fecha_dis[indice_citas_dis]<<" a la hora: "<<citas_hora_dis[indice_citas_dis]<<endl;
              cout<<"ID Cita: "<<indice_citas_dis<<endl;
  cout<<"Recuerde el ID de su cita para poder eliminarla\n";
            }
            else{
              citas_hora.push_back(hora);
              citas_fecha.push_back(fechas);
              indice_citas=citas_fecha.size()-1;
cout<<"Su cita se agendó exitosamente para la fecha: "<<citas_fecha[indice_citas]<<" a la hora: "<<citas_hora[indice_citas]<<endl;
              cout<<"ID Cita: "<<indice_citas_dis<<endl;
              cout<<"Recuerde el ID de su cita para poder eliminarla\n";
            }
            break;
            //Cancelar cita---------------------
          case 2:
      cout<<"Ingrese el ID de la cita que desea cancelar: ";
            cin>>ID_cancelar;

            
 if(semestre_estudiante[indice]==1||dis_estudiante[indice]==1)
              {
                citas_hora_dis.erase(citas_hora_dis.begin()+ID_cancelar);
                citas_fecha_dis.erase(citas_fecha_dis.begin()+ID_cancelar);
        cout<<"Cita con ID: "<<ID_cancelar<<" cancelada con éxito"<<endl;
              }
            else{
              citas_hora.erase(citas_hora.begin()+ID_cancelar);
              citas_fecha.erase(citas_fecha.begin()+ID_cancelar);
              cout<<"Cita con ID: "<<ID_cancelar<<" cancelada con éxito"<<endl;
              
            }
            break;
            //Ticket-----------------------------
          case 3:
        cout<<"Ingrese el ID de la cita que desea ver: ";
        cin>>ID_ticket;

            if(semestre_estudiante[indice]==1||dis_estudiante[indice]==1){
              cout<<"Cita con ID: "<<ID_ticket<<endl;
              cout<<"Ventanilla prioritaria\n";
              cout<<"Turno: "<<ID_ticket+1<<endl;
                
            }
            else{
              cout<<"Cita con ID: "<<ID_ticket<<endl;
              cout<<"Ventanilla normal\n";
              cout<<"Turno: "<<ID_ticket+1<<endl;
            }
            
            
            
        break;    
            
          
         break;
          case 4:
            cout<<"¡Ha salido del sistema exitosamente!";
            log=false;
          break;
    //DEFAULT------------------------------
    default:
    cout<<"Opción inválida\n";
    break;
  }
      }
  }
  }
  return 0;
}