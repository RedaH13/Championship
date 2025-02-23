#include<iostream>
#include<vector>
#include<string>


using namespace std;

class terrain
{
	private:
		string nom;
		int capacite;
		string ville;
	
	public:
		terrain():nom(""),capacite(0),ville(""){}
		terrain(string name,int cap, string city):nom(name),capacite(cap),ville(city){}
		// Getters
		string getNom(){return nom;}
		int getCapacite(){return capacite;}
		string getVille(){return ville;}
		
		// Setters
		void setNom(string name){nom=name;}
		void setCapacite(int cap){capacite=cap;}
		void setVille(string city){ville=city;}
		
		terrain SaisirTerr();
		void AfficherTerr();
		
};

terrain terrain::SaisirTerr()
{
	// cin.getLine(cin, name); permet la lecture de string avec espace
	string name;
	int cap;
	string city;
	cout<<"Entrez le nom du terrain ";
	cin>>name;
	cout<<"Entrez la capacite du terrain ";
	cin>>cap;
	cout<<"Entrez la ville du terrain ";
	cin>>city;
	return terrain(name,cap,city);
}

void terrain::AfficherTerr()
{
	cout<<"Terrain : "<<endl;
	cout<<getNom()<<" : "<<getCapacite()<<" places  "<<getVille()<<endl;
}

vector<terrain> AjouterTerr(vector<terrain> Turf) // Ajout au vecteur de terrains
{
	terrain t;
	t=t.SaisirTerr();
	Turf.push_back(t);
	return Turf;
}

vector<terrain> SupprimerTerr(vector<terrain> Turf) // Supprimer un terrain du vecteur
{
	string name;
	cout<<"Le terrain a supprimer ";
	cin>>name;
	int count=0;
	for(auto& i:Turf)
	{
		if(i.getNom()==name)
		{
			Turf.erase(Turf.begin()+count);
			return Turf;
		}
		count++;
	}
	return Turf;
}

void AfficherTurfs(vector<terrain> Turf) // Afficher tous les terrains
{
	for(auto i:Turf)
	{
		i.AfficherTerr();
	}
}

void RechercherTerr(vector<terrain> Turf) // Rechercher un terrain dans le vecteur
{
	string name;
	bool exist=false;
	cout<<"Entrez le nom du terrain ";
	cin>>name;
	for(auto i:Turf)
	{
		if(i.getNom()==name)
		{
			cout<<"Le terrain recherche "<<endl;
			i.AfficherTerr();
			exist=true;
		}
	}
	if(exist==false)
	cout<<"Terrain "<<name<<" est introuvable"<<endl;
}
