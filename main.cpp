#include <iostream>
#include<istream>
#include<fstream>
#include <string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<time.h>

using namespace std;
class Salleconf{
private:
    string refsalle;
    char jour[50];
    char nomclient[20];
    char cni[15];
    double tel;
    string heure;
    int nbplace;

public:

    int menu();
    void connexion();
    void inscription();
    void infosalle();
    void reservation(Salleconf r[],int &nb,int &numres);
    void visresev(Salleconf r[],int &nb,int &numres);
    void annulreserv();
    void afficher();


    void setNomclient(char* nc){strcpy (nomclient,nc);};
    void setRefsalle(string re){refsalle=re;};
    void setJour(char* j){strcpy (jour,j);};
    void setHeure(string h){heure=h;};
    void setCni(char* c){strcpy(cni,c);};
    void setTel(double t) {tel=t;};
    void setNbplace( int np){nbplace=np;};

    char* getNomclient()  {return nomclient;};
    string getRefsalle() const {return refsalle;};
    char* getJour()  {return jour;};
    string getHeure() const {return heure;};
    char* getCni()  {return cni;};
    double getTel() const {return tel;};
    int getNbplace() const {return nbplace;};

};


 int main()
{

   char nom[20];
   class Salleconf res[100];
   int nb=0;
   int numres=100;
   Salleconf aff;
	int choisir;

        cout<<endl<<"\t\t***********************************************************************\n";
        cout<<endl<<"                            APPLICATION DE GESTION DE LA SALLE DE CONFERENCE                              \n";
        cout<<endl<<"\t\t***********************************************************************\n";
        cout<<endl<<"                                 BIENVENU A LA PAGE DE CONNEXION                               \n";
        cout<<endl<<"*******************        VEUILLEZ ENTRER VOS INFORMATIONS DE CONNEXION       ****************************************\n";
        cout<<"\n\t\t1.CONNEXION"<<endl;
        cout<<"\n\t\t2.INSCRIPTION"<<endl;
        cout<<"\n\t\t3.Exit"<<endl;
        cout<<"\n\t\tENTRER VOTRE CHOIX:";
        cin>>choisir;
        cout<<endl;
        switch(choisir)
        {
                case 1:
                        aff.connexion();
                        break;
                case 2:
                        aff.inscription();
                        break;

                case 3:
						system("cls");
                        cout<<"MERCI POUR VOTRE CONFIANCE. A BIENTOT!!!!!!!\n\n";
                        system("pause");
                        exit(1);
                        break;
                default:
                        system("cls");
                        cout<<"Mauvais choix,faites un choix de 1a3"<<endl;
                        main();
        }
    recommencer:
    switch(aff.menu()){

        case 1:cout<<"\n\tVous avez choisit Consulter les  informations par rapport a la salle de conference"<<endl;
            aff.infosalle();
        break;
        case 2:cout<<"\n\tvous avez choisit Effectuer une reservation"<<endl;
            aff.reservation(res,nb,numres);
        break;
        case 3:cout<<" \n\tvous avez choisit Visauliser les reservations enregistrer"<<endl;
           aff.visresev(res,nb,numres);

        break;
        case 4:cout<<" \n\tvous avez choisit Annuler une reservation"<<endl; break;
        case 5:
            cout<<" \n\tvous avez choisit de quitter"<<endl;
            cout<<"MERCI POUR VOTRE CONFIANCE. A BIENTOT!!!!!!!\n\n"<<endl;
            exit(1);
        break;
        default:
            system("cls");
            cout<<" Mauvais choix,faites un choix de 1a5"<<endl; break;
            goto recommencer;

    }

   cout<<"entrez le nom du client :";
   for (int i=1;i<4;i++){
        cout<<"entrez le nom:";
        cin>>nom;
        res[i].setNomclient(nom);

   }
   cout<<"voici les clients";
   for(int i=1;i<4;i++){
       cout<<res[i].getNomclient();
   }
   //return 0;
}



//page du menu d'utilisation de l'qpplicqtion
int Salleconf::menu(){

    entrer:
    int choix;
    cout<<endl<<"                               BIENVENU A LA PAGE DE MENU                              \n";
    cout<<endl<<"*******************        VEUILLEZ ENTRER VOTRE CHOIX       ****************************************\n";
    cout<<endl<<"\n\t\t****************MENU*********************"<<endl;
    cout<<endl<<"n\t\t ENTRER LE CHIFFRE  CORRESPONDATION A LA TACHE QUE VOUS SOUHAITEZ EXECUTER.";
    cout<<endl<<"\n\t\t1-Consulter les  informations par rapport a la salle de conference"<<endl;
    cout<<endl<<"\n\t\t2-Effectuer une reservation"<<endl;
    cout<<endl<<"\n\t\t3-Visauliser les reservations enregistrer"<<endl;
    cout<<endl<<"\n\t\t4-Annuler une reservation"<<endl;
    cout<<endl<<"\n\t\t5-Quitter"<<endl;
    cout<<"\n\t\t";cin>>choix;
    if(choix>5){
            cout<<endl<<"\n\t\tMauvais choix,faites un choix de 1a5";
        goto entrer;
    }
    return choix;
}
//page d'authentification
void Salleconf::connexion()
 {
      system("cls");
      cout<<endl<<"\t\t***********************************************************************\n";
   	  cout<<endl<<"                            APPLICATION DE GESTION DE LA SALLE DE CONFERENCE                              \n";
      cout<<endl<<"\t\t***********************************************************************\n";
      cout<<endl<<"                                 BIENVENU A LA PAGE DE CONNEXION                               \n";
      cout<<endl<<"*******************        VEUILLEZ ENTRER VOS INFORMATIONS DE CONNEXION       ****************************************\n";
        int count;
        int compte =0;
        int decompte=3;
    while ( compte < 3)
	{

	    entrer:
        string userName,userPassword,u,p;
        cout<<"\n\n\t\t\tVEUILLEZ ENTRER VOS INFORMATIONS DE CONNEXION"<<endl;
        cout<<"\n\n\t\t\t\tNOM D'UTILISATEUR' :";
        cin>>userName;
        cout<<"\n\t\t\t\tMOT DE PASSE:";
        cin>>userPassword;

        ifstream input("database.txt");
        while(input>>u>>p)//verifie si l'uitlisateur existe dans le fichier de stockage database.txt qui fait office de base de donnees
        {
                if(u==userName && p==userPassword)

                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
        	 system("cls");
			        time_t now;
					struct tm nowLocal;
	 				now=time(NULL);//avoir l'heure du systeme
					nowLocal=*localtime(&now);
                    cout<<endl<<"\t\t***********************************************************************\n";
                    cout<<endl<<"                            APPLICATION DE GESTION DE LA SALLE DE CONFERENCE                              \n";
                    cout<<endl<<"\t\t***********************************************************************\n";
                    cout <<endl <<endl<< "\t\t\tBIENVENUE M."<<userName <<"  "<< userPassword;
					//affiche la date
                    cout<<"\tla date est:"<<nowLocal.tm_mday<<"-"<<nowLocal.tm_mon+1<<"-" <<nowLocal.tm_year + 1900<<endl;
                    cin.get();
                	cin.get();
                	cin.get();
                	break;
        }
        else
        {
            	cout<<endl<<endl<< "\n\t\t\t Nom d'utilisateur ou mot de passe incorrect, veuillez reessayer...\n\n "<<endl;
           	    cout <<"\t\t\tIl vous reste " <<--decompte<<" tentatives"<<endl;
                compte++;
                system("pause");
                goto entrer;
        }
        if (compte ==3)
            {

                cout<<endl<<"\n\t\t\tVous avez atteint le notre maximal de tentative possible; le progammme va s'eteindre.";
                exit(1);

            }
	}

 }
 //page d'inscription
 void Salleconf::inscription()
 {
      system("cls");
      cout<<endl<<"\t\t***********************************************************************\n";
   	  cout<<endl<<"                            APPLICATION DE GESTION DE LA SALLE DE CONFERENCE                              \n";
      cout<<endl<<"\t\t***********************************************************************\n";
      cout<<endl<<"                                 BIENVENU A LA PAGE D'INSCRIPTION                              \n";
      cout<<endl<<"*******************        VEUILLEZ ENTRER VOS INFORMATIONS D'INSCRIPTION     ****************************************\n";

        string reguser,regpass,ru,rp;

        cout<<"\n\t\tENTRER VOTRE NOM D'UTILISATEUR:";
        cin>>reguser;
        cout<<"\n\t\tENTRER VOTRE MOT DE PASSE:";
        cin>>regpass;

        ofstream reg("database.txt",ios::app);//enregistrer les informations de connexion dans le fichier database
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\n\t\t INSCRIPTION REUSSIE !!!!! \n";
        system("pause");
       main();
 }

 //creation d'une fonction pour afficher les infos sur la salle de conference
 void Salleconf::infosalle(){
      system("cls");
     cout<<endl<<"\t\t***********************************************************************\n";
    cout<<endl<<"                            APPLICATION DE GESTION DE LA SALLE DE CONFERENCE                              \n";
    cout<<endl<<"\t\t***********************************************************************\n";
    cout<<endl<<"                                 BIENVENU A LA PAGE D'INFORMATION                              \n";
    cout<<endl<<"\n\n\t\t****************INFO*********************"<<endl;
    cout<<endl<<"\n\t\tBienvenu dans la page d'information sur notre salle de conférence"<<endl;
    cout<<endl<<"\t\t ref:SALCONF 01 AYANT LES CARACTERISTIQUEs CI-DESSOUS:"<<endl;
    cout<<endl<<"\n\t\t>>NOUS METTONS A VOTRE DISPOSITION UNE SALLE DE CONFERENCE DE REFERENCE:"<<endl;
    cout<<endl<<"\n\t\t>>NOTRE SALLE DE CONFERENCE A UNE CAPACITE DE 200 PLACES ASSISES"<<endl;
    cout<<endl<<"\n\t\t>>SONORISE ET POSSEDE UN ECRAN UN VIDEO PROJECTEUR POUR UNE QULECONQUE PROJECTION "<<endl;
    cout<<endl<<"\n\t\t>>OUVERT DE LUNDI A DIMANCHE 24H/24"<<endl;
    cout<<endl<<"\n\t\t>>NOUS AVONS UN PERSONNEL QUALIFIE A VOTRE DISPOSITION. "<<endl;
    cout<<endl<<"\n\t\t*******************************MERCI DE NOUS FAIRE CONFIANCE.**********************************"<<endl;
    cout<<endl<<"\n\t\tpour  appuyer sur 1 pour ";
    int quitter;
    cin>>quitter;
        if(quitter ==1){
                cout<<"MERCI POUR VOTRE CONFIANCE. A BIENTOT!!!!!!!\n\n";
                        system("pause");

        }
        main();
 }
 //creation d'une fonction aui permet d'effectuer les reservation
 void Salleconf::reservation(Salleconf r[],int &nb,int &numres){
     system("cls");
    cout<<endl<<"\t\t***********************************************************************\n";
    cout<<endl<<"                            APPLICATION DE GESTION DE LA SALLE DE CONFERENCE                              \n";
    cout<<endl<<"\t\t***********************************************************************\n";
    cout<<endl<<"                                 BIENVENU A LA PAGE DE RESERVATION                               \n";
    cout<<endl<<"*******************        VEUILLEZ ENTRER LES INFORMATION POUR UNE RESERVATION       ***********************************\n";

    time_t now;
    struct tm nowLocal;
    now=time(NULL);//avoir l'heure du systeme
    nowLocal=*localtime(&now);
    //affiche la date
    cout<<"\tla date est:"<<nowLocal.tm_mday<<"-"<<nowLocal.tm_mon+1<<"-" <<nowLocal.tm_year + 1900<<endl;
    cin.get();

     numres=100;
     nb=0;
     cout<<endl<<"\n\t\tRESERVATION DE LA SALLE No:SALCONF 01"<<endl;
     cout<<endl<<"\n\t\tENTREZ LE NOMBRE DE RESERVATION A EFFECTUER:\t";
     cin>>nb;

    char nc[20];
    string re;
    char j[50];
    char c[15];
    double t;
    string h;
    int np;

     for(int i=0;i<nb;i++){

     cout<<endl<<"\n\t\tRESERVATION No:"<<numres<<endl;
     cout<<endl<<"\n\t\tSALLE REFERENCE";
     r[i].setRefsalle("SALCONF 01");
     cout<< r[i].getRefsalle()<<endl;
     cout<<endl<<"\n\t\tENTRER LE  NOM DU CLIENT:";
     cin>>nc;
     r[i].setNomclient(nc);
     cout<<endl<<"\n\t\tENTRER VOTRE NoCNI:";
     cin>>c;
     r[i].setCni(c);
     cout<<endl<<"\n\t\tENTRER VOTRE NUMERO DE TELEPHONE(6xxxxxxxxxx):";
     cin>>t;
     r[i].setTel(t);
     cout<<endl<<"\n\t\tENTRER LE NOMBRE DE PLACE:";
     cin>>np;
     r[i].setNbplace(np);
     cout<<endl<<"\n\t\tENTRER LE JOUR DE LA CONFERENCE(EX:lundi-5-mai-2021):";
     cin>>j;
     r[i].setJour(j);
     cout<<endl<<"\n\t\tENTRER L' HEURE DE LA CONFERENCE(EX:09H00)";
     cin>>h;
     r[i].setHeure(h);
       cout<<endl<<"\n\t\t*********VOTRE RESERVATION A ETE ENREGISTER AVEC SUCCES!!!********";
     numres++;
     }

    //visresev(r,nb,numres);
    main();
 }


 void Salleconf::visresev(Salleconf r[],int &nb,int &numres){

      system("cls");
    cout<<endl<<"\t\t***********************************************************************\n";
    cout<<endl<<"                            APPLICATION DE GESTION DE LA SALLE DE CONFERENCE                              \n";
    cout<<endl<<"\t\t***********************************************************************\n";
    cout<<endl<<"                                 BIENVENU A LA PAGE DE VISUALISATION DES  RESERVATIONS                               \n";
    cout<<endl<<"\n\n*******************      VOICI LA LISTE DES RESERVATION DEJA EFFECTUER       ***********************************\n";
      time_t now;
    struct tm nowLocal;
    now=time(NULL);//avoir l'heure du systeme
    nowLocal=*localtime(&now);
    //affiche la date
    cout<<"\tla date est:"<<nowLocal.tm_mday<<"-"<<nowLocal.tm_mon+1<<"-" <<nowLocal.tm_year + 1900<<endl;
    cin.get();
     cout<<endl<<"\n\t\tSALLE REFERENCE:";
     setRefsalle("SALCONF 01");
     cout<< getRefsalle()<<endl;
     cout<<"\n\n\t No:\t L' HEURE \t  JOUR  \t  NOM DU CLIENT \t NoCNI \t TELEPHONE \t NOMBRE DE PLACE"<<endl;

     for (int i=0;i<nb;i++)
        {
        int n=1;
    cout<<n<<"\t"<<r[i].getHeure()<<"\t"<<r[i].getJour()<<"\t"<<r[i].getNomclient()<<"\t"<<r[i].getCni()<<"\t"<<r[i].getTel()<<"\t"<<r[i].getNbplace();
        n++;
        }
    //main();

 }

