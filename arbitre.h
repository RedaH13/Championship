#include<iostream>
#include<vector>

using namespace std;

class arbitre
{
	private:
		string nom;
		int age;
		int cardr; // Cartons Rouges
		int cardj; // Cartons Jaunes
		
	public:
		arbitre():nom(""),age(20),cardr(0),cardj(0){}
		arbitre(string name,int age,int cr,int cj):nom(name),age(age),cardr(cr),cardj(cj){}
		// Getters
		string getNom(){return nom;}
		int getAge(){return age;}
		int getCardr(){return cardr;}
		int getCardj(){return cardj;}
		
		// Setters
		void setNom(string name){nom=name;}
		void setAge(int age){age=age;}
		void setCardr(int cr){cardr=cr;}
		void setCardj(int cj){cardj=cj;}
		
		void AfficherArbitre();
		void RechercherArbitre(vector<arbitre> Ref);
		arbitre SaisirArbitre();
};

void arbitre::AfficherArbitre()
{
	cout<<"Arbitre : "<<getNom()<<" "<<getAge()<<" ans"<<endl;
	cout<<"Cartons rouges : "<<getCardr()<<"   Cartons jaunes : "<<getCardj()<<endl;
}

arbitre arbitre::SaisirArbitre()
{
	string name;
	int ag;
	arbitre arb;
	cout<<"Entrez le nom ";
	cin>>name;
	cout<<"Entrez l age";
	cin>>ag;
	arb.setNom(name);
	arb.setAge(ag);
	return arb;
}

vector<arbitre> AjouterArbitres(vector<arbitre> Ref)
{
	arbitre a;
	a= a.SaisirArbitre();
	bool exist=false;
	for(auto i:Ref)
	{
		if(a.getNom()==i.getNom())
			exist=true;
	}
	if( exist == true)
		cout<<a.getNom()<<" existe deja"<<endl;
	else
		Ref.push_back(a);
	return Ref;
}

void RechercherArbitre(vector<arbitre> Ref)
{
	string name;
	bool exist=false;
	cout<<"Entrez le nom de l arbitre ";
	cin>>name;
	for( auto i:Ref )
	{
		if(name==i.getNom())
		{
			cout<<"L arbitre recherche : "<<endl;
			i.AfficherArbitre();
			exist = true;
		}
	}
	if( exist == false )
		cout<<"Arbitre introuvable"<<endl;
}

void AfficherArbitres(vector<arbitre> Ref)
{
	for(auto i:Ref)
	{
		i.AfficherArbitre();
	}
}
