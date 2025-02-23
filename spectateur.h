#include<iostream>
#include<algorithm>
#include<cstdlib>
#include <ctime>
#include<vector>


using namespace std;

class spectateur
{
	private:
		string num;
		int place;
	
	public:
		spectateur():num(""),place(0){}
		spectateur(string numb,int pl):num(numb),place(pl){}
		// Getters
		string getNum(){return num;}
		int getPlace(){return place;}
		
		// Setters
		void setNum(string numb){num=numb;}
		void setPlace(int pl){place=pl;}
		
		void AfficherSp();
		spectateur saisirSpect();
};

spectateur spectateur::saisirSpect()
{
	string id;
	int pl;
	terrain t;
	pl=rand()%t.getCapacite();
	id=rand()%100000;
	return spectateur(id,pl);
}

vector<spectateur> AjouterSpect(vector<spectateur> Spect) // Ajout au vecteur de spectateurs
{
	spectateur s;
	s=s.saisirSpect();
	Spect.push_back(s);
	cout<<"merci ";
	return Spect;
}

void spectateur::AfficherSp()
{
	cout<<"Nº Billet : "<<getNum()<<" : "<<getPlace()<<endl;
}

void AfficherSpectateurs(vector<spectateur> Spect)
{
	for(auto i:Spect)
		i.AfficherSp();
}


