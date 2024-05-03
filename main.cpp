#include<iostream>
#include<vector>

using namespace std;

// ------------------------------------- Clas Plat -------------------------------- 
class Plat{
        string nomPlat;
        string DescriptionPlat;
        double prixPlat;
    public:
        Plat() {};
        Plat(string nom,string desc,double prix) : nomPlat(nom),DescriptionPlat(desc),prixPlat(prix){};
        string getNomPlat() const {return nomPlat;}
        string getDescriptionPlat() const {return DescriptionPlat;}
        double getPrixPlat()const { return prixPlat; }

        void afficheDetailPlat() const {
            cout << "|-----------------------------------------------------------------------------------------------------|" << endl;
            cout << "| - Nom         : " << nomPlat <<"                                                                            " << endl;
            cout << "| - Description : " << DescriptionPlat <<"                                                               " << endl;
            cout << "| - Prix        : " << prixPlat << " DH                                                                      " << endl;
            cout << "|-----------------------------------------------------------------------------------------------------|" << endl;
        }
        

        void Saisirpalt(){
            cout << "=============== | Ajouter Un Plat |==============="<< endl;
            cout << "| - Nom : ";
            cin.ignore(); 
            getline(cin,nomPlat); 
            cout << "| - Description: ";
            getline(cin,DescriptionPlat);
            cout << "| - Prix : ";
            cin >> prixPlat;
            cout << "==================================================|" << endl;      
        }

        void modifierplat( string n,string d,double p){
            nomPlat = n;
            DescriptionPlat = d;
            prixPlat = p;
        }

        friend ostream& operator<<(ostream& os,Plat& pl){
            os << "Nom Plat : " << pl.nomPlat << endl;
            os << "Description : " << pl.DescriptionPlat << endl;
            os << "Prix Plat : " << pl.prixPlat << endl; 
            return os;
        }
};
//---------------c---------------------------------------------------------------------------



// ------------------------------------- Clas Boisson -------------------------------- 
class Boisson{
        string nameBoisson;
        string DescriptionBoisson;
        double prixBoisson;
    public:
        Boisson(){};
        Boisson(string name,string desc,double prix) 
        : nameBoisson(name),DescriptionBoisson(desc),prixBoisson(prix){};

        string getNameBoisson() const {return nameBoisson;}
        string getDescriptionBoisson() const {return DescriptionBoisson;}
        double getPrixBoisson() const {return prixBoisson;}
        
        void afficheDetailBoisson(){
            cout << "|-----------------------------------------------------------------------------------------------------|" << endl;
            cout << "| - Nom         : " << nameBoisson <<"                                                                            " << endl;
            cout << "| - Description : " << DescriptionBoisson <<"                                                               " << endl;
            cout << "| - Prix        : " << prixBoisson << " DH                                                                      " << endl;
            cout << "|-----------------------------------------------------------------------------------------------------|" << endl;
        }

        void SaisirBoisson(){
            cout << "=============== | Ajouter Un Boisson |==============="<< endl;
            cout << "| - Nom : ";
            cin.ignore(); 
            getline(cin,nameBoisson);       
            cout << "| - Description: ";
            getline(cin,DescriptionBoisson);
            cout << "| - Prix : ";
            cin >> prixBoisson;
            cin.ignore();
            cout << "==================================================|" << endl<< endl;
            cout << "--> BOISSON AJOUTER AU MENU <--" << endl<< endl;  
        }

        void modifierboisson(string n,string d,double p){
            nameBoisson = n;
            DescriptionBoisson = d;
            prixBoisson = p;
        }

};
//------------------------------------------------------------------------------------------



// ------------------------------------- Clas Menu -------------------------------- 
class Menu{
    vector<Plat> listePlats;
    vector<Boisson> listeBoissons;

    public:
        Menu(){
            Plat plat1("BOCA ORIGINAL","Chicken strips, dinde fumée, fromage, ketchup et mayo, laitue", 33);
            Plat plat2("BOCA SPICY","Chicken strips, dinde fumée, fromage, sauce buffalo, laitue", 35);
            Boisson boisson1("Jus Banane", "Un rafraîchissant thé vert à la menthe sucré", 15.0);
            Boisson boisson2("Jus d'orange frais", "Un jus d'orange fraîchement pressé, plein de vitamines", 20.0);
            listePlats.push_back(plat1);
            listePlats.push_back(plat2);
            listeBoissons.push_back(boisson1);
            listeBoissons.push_back(boisson2);
        }
        const vector<Plat>& getListePlats()const { return listePlats;}
        const vector<Boisson>& getListeBoissons()const {return listeBoissons;}

        void ajouterPlat(){
            Plat p1;
            p1.Saisirpalt();
            listePlats.push_back(p1);
        }

        void ajouterBoisson(){
            Boisson b;
            b.SaisirBoisson();
            listeBoissons.push_back(b);
        }

        void afficheMenu(){
            cout << endl;
            cout << "|==============================================| MENU |===============================================|" << endl;
            cout << "|" << endl;
            cout << "|------------| LISTE DES PLAT |" << endl<<endl;
                for(auto i : listePlats){
                    i.afficheDetailPlat();
                }
            cout << endl;
            cout << "|------------| LISTE DES BOISSONS |" << endl<<endl;
                for(auto j : listeBoissons){
                    j.afficheDetailBoisson();
                }
            cout << "|=======================================================================================================|" << endl;
        }

        void Modifierplat(){
            cout << "Entrer le nom de Plat a Modifier : ";
            string choix;
            cin.ignore();
            getline(cin,choix);
            for(auto i = listePlats.begin(); i != listePlats.end(); ++i){
                if(i->getNomPlat() == choix){
                    listePlats.erase(i);
                }
            }
            cout << "|=============== | Modification Plat |===============|"<< endl;
            cout << "| - New Plat : ";
            cin.ignore(); 
            string nomPlat,DescriptionPlat;
            float prixPlat;
            getline(cin,nomPlat); 
            cout << "| - Description: ";
            getline(cin,DescriptionPlat);
            cout << "| - Prix : ";
            cin >> prixPlat;
            cout << "|==================================================|" << endl; 
            Plat p;
            p.modifierplat(nomPlat,DescriptionPlat,prixPlat);
            listePlats.push_back(p);
        }
        void Modifierboisson(){
            cout << "Entrer le nom de Boisson a Modifier : ";
            string choix;
            cin.ignore();
            getline(cin,choix);
            for(auto i = listeBoissons.begin(); i != listeBoissons.end(); ++i){
                if(i->getNameBoisson() == choix){
                    listeBoissons.erase(i);
                }
            }
            cout << "|=============== | Modification Boisson |===============|"<< endl;
            cout << "| - New Boisson : ";
            cin.ignore(); 
            string n,Des;
            float p;
            getline(cin,n); 
            cout << "| - Description: ";
            getline(cin,Des);
            cout << "| - Prix : ";
            cin >> p;
            cout << "|==================================================|" << endl; 
            Boisson b;
            b.modifierboisson(n,Des,p);
            listeBoissons.push_back(b);
        }
};
//------------------------------------------------------------------------------------------

// ------------------------------------- Clas Reservation -------------------------------- 
class Reservation{
        string Date;
        string Heure;
        int NombrePersonne;
        string status;
    public: 
        Reservation(){};
        Reservation(string d, string h,int nbr, string sta)
        : Date(d), Heure(h), NombrePersonne(nbr), status(sta){};
        string getDate(){
            return Date;
        }
        string getHeure(){
            return Heure;
        }
        string getStatus(){
            return status;
        }
        void setStatus(string s){
            status = s;
        }

    
        void ConfirmerReservation(){
            status = "Reservation Confirmer";
        }

        void annulerReservations(){
           cout << "|      RESREVATION ANNULER     |" << endl;
           cout << "| - Date : " <<  Date << endl;
           cout << "| - Heure : " << Heure << endl;
            status = "Resservation Annuler";
        }


        void afficherDetailReservation(){
            cout << "|================| Detail Reservation |===============|"<< endl;
            cout << "|                                                     "<< endl;
            cout << "| - Date Reservation   : " << Date                     << endl;
            cout << "| - Heure Reservation  : " << Heure                    << endl;
            cout << "| - Nombre De Personne : " << NombrePersonne           << endl;  
            cout << "| - Status           : " << status                     << endl;
            cout << "|                                                     "<< endl;
            cout << "|=====================================================|" << endl;
            
        }

};
//------------------------------------------------------------------------------------------

// ------------------------------------- Clas Client -------------------------------- 
class Client{
        string nameClient;
        int numtele;
        vector<Reservation> reservations;
    public:
        Client(){};
        Client( const Client& c){
            nameClient = c.nameClient;
            numtele = c.numtele;
        }
        Client(string name, int num) : nameClient(name),numtele(num){};
        string getNameClient()const { return nameClient;}
        string getNameClient(){
            return nameClient;
        }
        int getNumtele(){ return numtele; }
        
        vector<Reservation>& getreservations(){
            return reservations;
        }

        void ReserverTable(string name,string date,string hr,int nbrp){
                Reservation newReservation(date,hr,nbrp,"En attente");
                reservations.push_back(newReservation);
                cout << endl << endl;
                cout << "|============================================================|"<< endl;
                cout << "      La Reservation de " << name << " est Avec succes        " << endl;
                cout << "|============================================================|"<< endl;
                cout << "|   --> La Maison D'arabe Vous souhaite le Bienvenue <--     |" << endl;
                cout << "|============================================================|"<< endl<<endl;
        }

        void annulerReservation(string date, string heure) {
            bool reservationTrouvee = false;
            for (auto it = reservations.begin(); it != reservations.end(); ++it) {
                if (it->getDate() == date && it->getHeure() == heure) {
                    it = reservations.erase(it); // Supprimer la réservation
                    reservationTrouvee = true;
                    cout << "Réservation annulée pour la date " << date << " et l'heure " << heure << endl;
                    break;
                }
            }
            if (!reservationTrouvee) {
                cout << "Aucune réservation trouvée pour la date " << date << " et l'heure " << heure << endl;
            }
        }









        void afficherDetailClient(){
            cout << "===================| Nos Client |==========================" << endl;
            cout << "| - Nom Client : " << nameClient << endl;
            cout << "| - Numero Telephone : " << numtele << endl;
            cout << "===========================================================" << endl;
        }



};
//------------------------------------------------------------------------------------------
class Commande{
        vector<Plat>listaPlatCommande;
        vector<Boisson>listBoissonCommande;
        const Menu& menu;
    public:
        Commande(const Menu& m): menu(m){};
        vector<Plat>& getListaPlatCommande(){
            return listaPlatCommande;
        }
        void ajouterPlatCommande(string p){
            for(auto plat : menu.getListePlats()){
                if(plat.getNomPlat() == p){
                    listaPlatCommande.push_back(plat);
                    cout << "|====== -> Commande Valider <- ======|" << endl;
                    cout << "| - Plat : " << p << "               |" << endl;
                    cout << "|====================================|" <<endl;
                    break;
                }else{
                    cout << "!!!!!!!!! -> Plat Introuvable <- !!!!!!!!!" << endl;
                    break;
                }
            }
        }


        void ajouterBoissonCommande(string b){
            for(auto boisson : menu.getListeBoissons()){
                if(boisson.getNameBoisson() == b){
                    listBoissonCommande.push_back(boisson);
                    cout << "|====== -> Commande Valider <- ======|" << endl;
                    cout << "| - Boisson : " << b << "               |" << endl;
                    cout << "|====================================|" <<endl;
                    break;
                }else{
                    cout << "!!!!!!!!! -> Boisson Introuvable <- !!!!!!!!!" << endl;
                    break;
                }
                
            }
        }

        void calculerTotal(string p,string b){
            double total = 0.0;
            if(b.empty()){
                for(auto& plat : menu.getListePlats()){
                    if(plat.getNomPlat() == p){
                        total += plat.getPrixPlat();
                            cout << endl;
                            cout << "|================= Reçu Commande =================|" << endl;
                            cout << "| - Plat : " << p << "                            |" << endl;
                            cout << "| - Total : " << total << "                       |" << endl;
                            cout << "| - Telecharger Votre Reçu |->  <-|              |" << endl;
                            cout << "|=================================================|" << endl;
                            break;
                    }
                }
            }else if(p.empty()){
                for(auto& boisson : menu.getListeBoissons()){
                    if(boisson.getNameBoisson() == b){
                        total += boisson.getPrixBoisson();
                            cout << endl;
                            cout << "|================= Reçu Commande =================|" << endl;
                            cout << "| - Boisson : " << b << "                         |" << endl;
                            cout << "| - Total : " << total << "                       |" << endl;
                            cout << "| - Telecharger Votre Reçu |->  <-|              |" << endl;
                            cout << "|=================================================|" << endl;
                            break;
                    }
                }
            }else{
                for(auto& plat : menu.getListePlats()){
                    if(plat.getNomPlat() == p){
                        total += plat.getPrixPlat();
                    }
                }
                for(auto& boisson : menu.getListeBoissons()){
                    if(boisson.getNameBoisson() == b){
                        total += boisson.getPrixBoisson();
                    }
                }
                    cout << endl;
                    cout << "|================= Reçu Commande =================|" << endl;  
                    cout << "| - Plat : " << p << "                            |" << endl;
                    cout << "| - Boisson : " << b << "                         |" << endl;
                    cout << "| - Total : " << total << "                       |" << endl;
                    cout << "| - Telecharger Votre Reçu |->  <-|              |" << endl;
                    cout << "|=================================================|" << endl;
                
            }
            

        }
        void afficherTouslesCommande(){
            cout << "|=================  Commande =================|" << endl;
            for(Plat& p: listaPlatCommande){
                p.afficheDetailPlat();
            }
        }

};

class gestionnaireDeStocks{
    vector<int>Stockplat;
    vector<int>stockBoisson;

    static int totalPlat;
    static int totalBoisson;
    const Menu& menu;
    int password = 1919;
    public:
    gestionnaireDeStocks(const Menu& m) : menu(m){};

        int getPassword(){
            return password;
        }
        void newPlat(){
            totalPlat += 1;
            Stockplat.push_back(totalPlat);
            cout << "Total Plat : " << totalPlat << endl;
        }
        void newBoisson(){
            totalBoisson += 1;
            stockBoisson.push_back(totalBoisson);
            cout << "Total Boisson : " << totalBoisson << endl;
        }

        void updatestockPlat(){
            totalPlat -= 1;
            Stockplat.pop_back();
            cout << "Total Plat : " << totalPlat << endl;
        }

        void updatestockBoisson(){
            totalBoisson -= 1;
            stockBoisson.pop_back();
                cout << "Total Boisson : " << totalBoisson << endl;
        }


        void VerificationPlat(string plat)const {
            bool dispo = false;
            for(const auto palt : menu.getListePlats()){
                if(plat == palt.getNomPlat()){
                    dispo = true;
                    break;
                }
            }
            if(!dispo){
                cout <<endl<<endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<endl;
                cout << "!!!!!! -> PLAT DEMANDER NON DISPONIBLE <- !!!!!!"<< endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<endl<<endl;
            }
        }
        

        void VerificationBoisson(string boisson)const {
            bool dispo = false;
            for(const auto b : menu.getListeBoissons()){
                if(boisson == b.getNameBoisson()){
                dispo = true;
                }
            }
            if(!dispo){
                cout <<endl<<endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<endl;
                cout << "!!!!!! -> BOISSON DEMANDER NON DISPONIBLE <- !!!!!!"<< endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<endl<<endl;
            }
        }


};

int gestionnaireDeStocks::totalPlat = 2;
int gestionnaireDeStocks::totalBoisson = 2;
void menuclient(){
    cout << endl << endl;
    cout << "|================================================|" << endl;
    cout << "|                                                |" << endl;
    cout << "|                    Client                      |" << endl;
    cout << "|                                                |" << endl;
    cout << "|================================================|" << endl;
    cout << "|                                                |" << endl;
    cout << "| |1| Voir le menu                               |" << endl;
    cout << "|                                                |" << endl;
    cout << "| |2| Passer une commande                        |" << endl;
    cout << "|                                                |" << endl;
    cout << "| |3| Réserver une table                         |" << endl;
    cout << "|                                                |" << endl;
    cout << "| |4| Annuler une réservation                    |" << endl;
    cout << "|                                                |" << endl;
    cout << "| |5| Retour                                     |" << endl;
    cout << "|                                                |" << endl;
    cout << "|================================================|" << endl;
    cout << "| - Saisir Votre Choix : " ;
}

void menugestionnaire() {
    cout << endl << endl;
    cout << "|=================================================|" << endl;
    cout << "|                                                 |" << endl;
    cout << "|            Gestionnaire de restaurant           |" << endl;
    cout << "|                                                 |" << endl;
    cout << "|=================================================|" << endl;
    cout << "|                                                 |" << endl;
    cout << "| |1| Ajouter un plat                             |" << endl;
    cout << "|                                                 |" << endl;
    cout << "| |2| Ajouter une boisson                         |" << endl;
    cout << "|                                                 |" << endl;
    cout << "| |3| Voir le menu                                |" << endl;
    cout << "|                                                 |" << endl;
    cout << "| |4| Modifier Menu                               |" << endl;
    cout << "|                                                 |" << endl;
    cout << "| |5| Reservation                                 |" << endl;
    cout << "|                                                 |" << endl;
    cout << "| |6| Afficher Client Reserver                    |" << endl;
    cout << "|                                                 |" << endl;
    cout << "| |7| Consulter  Stock                            |" << endl;
    cout << "|                                                 |" << endl;
    cout << "| |8| Retour                                      |" << endl;
    cout << "|                                                 |" << endl;
    cout << "|=================================================|" << endl;
    cout << "| - Saisir Votre Choix : " ;

}
void commender(){
    cout << "|===================| Commender |=================|" << endl;
    cout << "| |1| Plat                                         |" << endl;
    cout << "| |2| Boisson                                      |" << endl;
    cout << "| |3| Plat + Boisson                               |" << endl;
    cout << "|=================================================|" << endl;
    cout << "| - Quelle Commende Voudrais Effectuer ? ";
}
void invalidchoix(){
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<< endl;
    cout << "!!!!!! ->> Choix Invalide <<- !!!!!!!" << endl;
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<< endl;
}
int main(){
MENU_P:
Menu m; // constructeur pour le menu
Commande cmd(m);
vector<string> clientsreserver;
vector<Reservation>reservations;
vector<string> listecommande;
vector<int>stockpkat(2);
vector<int>stockboisson(2);
gestionnaireDeStocks GES(m);
    int choix;
    do{
        
        cout << endl << endl;
        cout << "|================================================|" << endl;
        cout << "|                                                |" << endl;
        cout << "|                 La Maison Arabe                |" << endl;
        cout << "|                                                |" << endl;
        cout << "|================================================|" << endl;
        cout << "|                                                |" << endl;
        cout << "| |1| Client                                     |" << endl;
        cout << "|                                                |" << endl;
        cout << "| |2| Gestionnaire de restaurant                 |" << endl;
        cout << "|                                                |" << endl;
        cout << "| |3| Quitter                                    |" << endl;
        cout << "|                                                |" << endl;
        cout << "|================================================|" << endl;
        cout << "| - Saisir Votre Choix : " ;
        cin >> choix;
        if(choix == 1){
            int choix1;
            MENU_C:
            menuclient();
            cin >> choix1;
            switch(choix1){
                case 1:{
                    m.afficheMenu();
                    goto MENU_C;
                    break;
                }case 2:{
                    commender();
                    int com;
                    cin >> com;
                    if(com == 1){ 
                        cout << endl << endl;
                        cout << "|=================================================|" << endl;
                        cout << "| - Entrer Le Nom Plat : ";
                        string nomPlat;
                        cin.ignore();
                        getline(cin,nomPlat);
                        cmd.ajouterPlatCommande(nomPlat);
                        cmd.calculerTotal(nomPlat,"");
                        listecommande.push_back(nomPlat);
                        stockpkat.pop_back();
                        break;
                    }else if(com == 2){
                        cout << endl << endl;
                        cout << "|=================================================|" << endl;
                        cout << "| - Entrer Le Nom du Boisson : ";
                        string nomboi;
                        cin.ignore();
                        getline(cin,nomboi);
                        cmd.ajouterBoissonCommande(nomboi);
                        cmd.calculerTotal("",nomboi);
                        stockboisson.pop_back();
                        break;
                    }else if(com == 3){
                        cout << endl << endl;
                        cout << "|=================================================|" << endl;
                        cout << "| - Entrer Le Nom Plat : ";
                        string nomPlat;
                        cin.ignore();
                        getline(cin,nomPlat);
                        cout << "|=================================================|" << endl;
                        cout << "| - Entrer Le Nom du Boisson : ";
                        string nomboi;
                        getline(cin,nomboi);
                        cmd.ajouterPlatCommande(nomPlat);
                        cmd.ajouterBoissonCommande(nomboi);
                        cmd.calculerTotal(nomPlat,nomboi);
                        stockpkat.pop_back();
                        stockboisson.pop_back();
                        break;
                    }else{
                        invalidchoix();
                        break;
                    }
                    
                }case 3:{
                    if(reservations.size() < 8){
                        string nom, date, heure;
                        int nbrp,numtele;
                        cout << "Entrer Votre Nom : ";
                        cin >> nom;
                        cout << "Entrer votre Numero de Telephone : ";
                        cin >> numtele;
                        cout << "Entrer la date de Reservation : ";
                        cin >> date;
                        cout << "Entrer l'heure de reservation : ";
                        cin >> heure;
                        cout << "Entrer le Nombre de personne : ";
                        cin >> nbrp;
                        Client newclient(nom,numtele);
                        clientsreserver.push_back(nom);
                        Reservation newreservation(date,heure,nbrp,"en attente");
                        newclient.ReserverTable(nom,date,heure,nbrp);
                        reservations.push_back(newreservation);
                        newclient.getreservations().push_back(newreservation);
                        break;
                    }else{
                        cout << endl;
                        cout << "!!!! -> Le Nombre De Reservation Atteint Le Seuil MINIMAL <- !!!! " << endl;
                        cout << endl;
                    }
                    
                }case 4:{
                    cout << "Entrer votre nom : ";
                    string nom;
                    cin >> nom;
                    cout << "Entrer La date : ";
                    string date;
                    cin >> date;
                    cout << "Entrer l'heure : ";
                    string heure;
                    cin >> heure;
                        if(reservations.size() == 0){
                            cout << "-> Aucune reservation dosponible <-"<< endl;
                            break;
                        }else{
                            for(auto& c : reservations){
                                if(c.getDate() == date && c.getHeure() == heure){
                                c.annulerReservations();
                                break;
                                }
                            }
                        }
                        for(auto i = reservations.begin(); i != reservations.end(); ++i){
                            if(i->getDate() == date && i->getHeure() == heure){
                                reservations.erase(i);
                                break;
                            }
                        }
                        
                }
                
                case 5:{
                    goto MENU_P;
                    break;
                }default :{
                    invalidchoix();
                    break;
                }
            }
        }else if(choix == 2){
            cout << "============ VERIFICATION ================"<<endl;
            cout << "|- Entrer Votre Mot de passe : ";
            string mdp;
            cin >> mdp;
            if(GES.getPassword() == 1919){
                MENU_G:
                menugestionnaire();
                int choix2;
                cin >> choix2;
                switch(choix2){
                    case 1:{
                        m.ajouterPlat();
                        stockpkat.push_back(1);
                        goto MENU_G;
                        break;
                    }case 2:{
                        m.ajouterBoisson();
                        stockboisson.push_back(1);
                        goto MENU_G;
                        break;
                    }case 3:{
                        m.afficheMenu();
                        goto MENU_G;
                        break;
                    }case 4:{
                        cout << "|=============== Modification ===============|"<< endl;
                        cout << "| 1- Modifier Plat                           |" << endl;
                        cout << "| 2- Modifier Boisson                        |" << endl;
                        cout << "| -> Saisir Votre Choix : ";
                        int mo;
                        cin >> mo;
                        if(mo == 1){
                            m.Modifierplat();
                            goto MENU_G;
                            break;
                        }else if(mo == 2){
                            m.Modifierboisson();
                            goto MENU_G;
                            break;
                        }else{
                            invalidchoix();
                            goto MENU_G;
                            break;
                        }   
                    }case 5:{
                        cout << "|==================== Resrevation ====================|"<< endl;
                        cout << "| - 1.Affichage Les reservation en attente            |" << endl;
                        cout << "| - 2. Valider Reservation                            |" << endl;
                        cout << "| - 3. Annuler Reservation                            |" << endl;
                        cout << "| - Entrer Votre choix : ";
                        int resre;
                        cin >> resre;
                        if(resre == 1){
                            if(reservations.size() == 0){
                                cout << "-> Aucune reservation dosponible <-"<< endl;
                                break;
                            }else{
                                for(auto res : reservations){
                                    res.afficherDetailReservation();
                                }
                                break;
                            }
                            break;
                        }else if(resre == 2){
                            cout << "Entrer l'heure De Confirmation : ";
                            string h;
                            cin >> h;
                            for(auto res : reservations){
                                if(res.getHeure() == h){
                                    res.setStatus("Confirmation Valider");
                                    res.afficherDetailReservation();
                                    for(auto i = reservations.begin() ; i != reservations.end(); ++i){
                                        if(i->getHeure() == h){
                                            reservations.erase(i);
                                            break;
                                        }
                                    }
                                }else{
                                    cout << "Aucune Reservation A cette Heure" << endl;
                                                break;
                                }
                            }
                            break;
                        }else if( resre == 3){
                            cout << "Entrer l'heure D'anuulation : ";
                            string h;
                            cin >> h;
                            for(auto res : reservations){
                                if(res.getHeure() == h){
                                    res.setStatus("Confirmation Annuler");
                                    res.afficherDetailReservation();
                                    for(auto i = reservations.begin() ; i != reservations.end(); ++i){
                                        if(i->getHeure() == h){
                                            reservations.erase(i);
                                            break;
                                        }
                                    }
                                }else{
                                    cout << "Aucune Reservation A cette Heure" << endl;
                                    break;
                                }
                            }
                            break;
                        }else{
                            invalidchoix();
                            break;
                        }
                        
                    }
                    case 6:{
                        cout << endl;
                        cout << "|====================== CLIENT RESRVER ==================" << endl; 
                        for(auto c : clientsreserver){
                            cout << "| - " << c << endl; 
                        }
                        break;
                    }case 7:{
                        cout << endl;
                        cout << "|====================== SOCK DES INGREDIENTS ==================|" << endl;
                        cout << "|--| PLAT |" <<endl;
                        cout << "|" << endl;
                        cout << "|-> | " << stockpkat.size() << " |"    << endl;
                        cout << "|" << endl;
                        cout << "|--| BOISSON |" <<endl;
                        cout << "|" << endl;
                        cout << "|-> | " << stockpkat.size() << " |"    << endl;
                        cout << "|                                                              |" << endl;  
                        cout << "|==============================================================|"<< endl;    
                        break;        
                    }
                    case 8:{
                        goto MENU_P;
                    }default:{
                        invalidchoix();
                        break;
                    }

            }
        }else{
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<< endl;
            cout << "!!!!!! ->>  MOT DE PASSE INCORRECT  <<- !!!!!!!" << endl;
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<< endl;
            goto MENU_G;
        }
        }else if(choix == 3){
        cout << endl;
        cout << "|================================================|" << endl;
        cout << "|                 La Maison Arabe                |" << endl;
        cout << "|================================================|" << endl;
        cout << "|                  -> AU REVOIR <-               |"  << endl<<endl<<endl;
        }else{
            invalidchoix();
        }
    }while(choix != 3);

}