#include<iostream>
#include<vector>
#include<string>
#include<iomanip>

using namespace std;

class equipe
{
	private:
		string nom;
		int classement;
		int points;
		int matchs_joue;
		int gd;
		bool statut;
		
	public:
		equipe();
		equipe(string name, int pos, int poin, int mj,int gd, bool stat);
		// Getters
		string getNom(){return nom;}
		int getClassement(){return classement;}
		int getPoints(){return points;}
		int getMatchsJoue(){return matchs_joue;}
		int getGD(){return gd;}
		bool getStatut(){return statut;}
		
		// Setters
		void setNom(string name){nom=name;}
		void setClassement(int cl){classement=cl;}
		void setPoints(int poin){points=poin;}
		void setMatchsJoue(int mj){matchs_joue=mj;}
		void setGD(int GD){gd=GD;}
		void setStatut(bool stat){statut=stat;}
		
		void AfficherEq();
		equipe SaisirEq();
		
};


equipe::equipe()
{
	nom="";
	classement=1;
	points=0;
	matchs_joue=0;
	gd=0;
	statut=false;
}

equipe::equipe(string name, int pos, int poin, int mj,int gd,bool stat)
{
	nom=name;
	classement=pos;
	points=poin;
	matchs_joue=mj;
	statut=stat;
}

equipe equipe::SaisirEq()
{
	string name;
	equipe e;
	cout<<"Entrez le nom de l equipe ";
	cin>>name;
	e.setNom(name);
	e.setStatut(false);
	return e;
}

void equipe::AfficherEq() 
{
	cout<<left<<setw(15)<<getNom()<<setw(10) << getMatchsJoue()<<setw(15)<<getClassement()<<setw(10) <<getPoints()<<setw(10) <<getGD()<<endl;
}

vector<equipe> AjouterEq(vector<equipe> Eq) // Ajout au vecteur d'equipes
{
	equipe e;
	e= e.SaisirEq();
	bool exist=false;
	for(auto i:Eq)
	{
		if(i.getStatut()==true)
			exist=true;
	}
	if( exist == true)
		cout<<e.getNom()<<" existe deja"<<endl;
	else
		Eq.push_back(e);
	return Eq;
}

vector<equipe> SupprimerEq(vector<equipe> Eq) // Supprimer une equipe du vecteur
{
	equipe e;
	e=e.SaisirEq();
	int count=0;
	for(auto& i:Eq)
	{
		if(i.getNom()==e.getNom())
		{
			Eq.erase(Eq.begin()+count);
			return Eq;
		}
		count++;
	}
	return Eq;
}

void AfficherEqs(vector<equipe> Eq) // Afficher toutes les equipes
{
	cout<<"Equipe		Matchs	Pos		Pts		GD"<<endl;
	for(auto i:Eq)
	{
		i.AfficherEq();
	}
}

void RechercheEq(vector<equipe> Eq) // Recherche par nom/classement
{
	string name;
	int pos;
	bool exist=false;
	int choice;
	do
	{
		cout<<"Par nom ou par classement ?(0/1) ";
		cin>>choice;
	}while( choice != 0 && choice != 1 );
	if(choice == 0)
	{
		cout<<"Entrez le nom de l equipe a rechercher ";
		cin>>name;
		for( auto i:Eq )
		{
			if(i.getNom()==name)
			{
				i.AfficherEq();
				exist = true;
			}
		}
		if( exist == false )
			cout<<name<<" est introuvable"<<endl;
	}
	else if(choice == 1)
	{
		cout<<"Entrez la position de l equipe a rechercher ";
		cin>>name;
		for( auto i:Eq )
		{
			if(i.getClassement()==pos)
			{
				i.AfficherEq();
				exist = true;
			}
		}
		if( exist == false )
			cout<<name<<" est introuvable"<<endl;
	}
}

