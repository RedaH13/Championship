#include<iostream>

#include"equipe.h"
#include"arbitre.h"
#include"terrain.h"
#include<algorithm>
#include<cstdlib>
#include <ctime>
#include<set>

using namespace std;

class match
{
	private:
		equipe team1;
		equipe team2;
		arbitre ref;
		terrain terr;
		int phase;
		int goals1;
		int goals2;
		string dateheure;
		
	public:
		match();
		match(equipe eq1,equipe eq2,arbitre arb,terrain tr,int ph,int gl1,int gl2,string time);
		// Getters
		equipe getTeam1(){return team1;}
		equipe getTeam2(){return team2;}
		arbitre getRef(){return ref;}
		terrain getTerr(){return terr;}
		int getPhase(){return phase;}
		int getGoals1(){return goals1;}
		int getGoals2(){return goals2;}
		string getDateheure(){return dateheure;}
		
		// Setters
		void setTeam1(equipe eq1){team1=eq1;}
		void setTeam2(equipe eq2){team2=eq2;}
		void setArbitre(arbitre arb){ref=arb;}
		void setTerr(terrain tr){terr=tr;}
		void setPhase(int ph){phase=ph;}
		void setGoals1(int gl1){goals1=gl1;}
		void setGoals2(int gl2){goals2=gl2;}
		void setDateheure(string time){dateheure=time;}
		
		void AfficherDetailsAvantSim();
		void AfficherDetailsApresSim();
};
match::match()
{
	equipe();
	equipe();
	arbitre();
	terrain();
	phase=1;
	goals1=0;
	goals2=0;
	dateheure="";
}

match::match(equipe eq1,equipe eq2,arbitre arb,terrain tr,int ph,int gl1,int gl2,string time)
{
	team1=eq1;
	team2=eq2;
	ref=arb;
	terr=tr;
	goals1=gl1;
	goals2=gl2;
	dateheure=time;
}

void match::AfficherDetailsAvantSim()
{
	switch(getPhase())
	{
		case(1):
			cout<<"Phase de Groupes"<<endl;
			break;
		case(2):
			cout<<"Eliminatoires"<<endl;
			break;
		case(3):
			cout<<"Quarts de Finale"<<endl;
			break;
		case(4):
			cout<<"Semi-Finale"<<endl;
			break;
		case(5):
			cout<<"Finale"<<endl;
			break;
		default:
			cout<<"Pas de Phases"<<endl;
			break;
	}
	
	cout<<team1.getNom()<<"  -  "<<team2.getNom()<<endl;
	cout<<"Terrain : "<<terr.getNom()<<"	"<<terr.getVille();
	cout<<"   "<<getDateheure()<<endl;
	cout<<"Arbitre : "<<ref.getNom()<<endl<<endl;
}

void match::AfficherDetailsApresSim()
{
	switch(getPhase())
	{
		case(1):
			cout<<"Phase de Groupes"<<endl;
			break;
		case(2):
			cout<<"Eliminatoires"<<endl;
			break;
		case(3):
			cout<<"Quarts de Finale"<<endl;
			break;
		case(4):
			cout<<"Semi-Finale"<<endl;
			break;
		case(5):
			cout<<"Finale"<<endl;
			break;
		default:
			cout<<"Pas de Phases"<<endl;
			break;
	}
	
	cout<<team1.getNom()<<"  "<<getGoals1()<<" - "<<getGoals2()<<" "<<team2.getNom()<<endl;
	cout<<"Terrain : "<<terr.getNom()<<"	"<<terr.getVille();
	cout<<"   "<<getDateheure()<<endl;
	cout<<"Arbitre : "<<ref.getNom()<<endl<<endl;
}

vector<match> creerMatchsGrps(vector<equipe>& Eqs,vector<arbitre> Ref, vector<terrain> Turf,int ph)
{
	srand(time(NULL));
	vector<match> M;
	match game;
	random_shuffle(Eqs.begin(),Eqs.end());
	
	for (int i = 0; i < Eqs.size()-1; i++) 
	{
		for (int j = i+1; j < Eqs.size(); j++) 
    	{
    		random_shuffle(Ref.begin(),Ref.end());
			random_shuffle(Turf.begin(),Turf.end());
    		game.setArbitre(Ref[0]);
    		game.setTerr(Turf[0]);
    		
			if (i != j && j  < Eqs.size()-1) 
			{	
				game.setTeam1(Eqs[i]);
				game.setTeam2(Eqs[j]);
				game.setGoals1(0);
				game.setGoals2(0);
				game.setPhase(1);
				game.setDateheure("15/12/2024 18:00");
			}
		// Condition de la 1ere equipe vs la derniere
			if (i != j && j  == Eqs.size()-1) 
			{
				game.setTeam1(Eqs[i]);
				game.setTeam2(Eqs[j]);
				game.setGoals1(0);
				game.setGoals2(0);
				game.setPhase(1);
				game.setDateheure("15/12/2024 18:00");
			}
			M.push_back(game);
		}
	}
	return M;
}

vector<match> creerMatchsElim(vector<equipe>& Eqs,vector<arbitre> Ref, vector<terrain> Turf,int ph)
{
	srand(time(NULL));
	vector<match> M;
	match game;
	random_shuffle(Eqs.begin(),Eqs.end());
	bool exist=false;
	for(int i=0; i<Eqs.size()-1; i++)
	{
		random_shuffle(Ref.begin(),Ref.end());
		random_shuffle(Turf.begin(),Turf.end());
		if(i+1<Eqs.size())
		{
			game.setArbitre(Ref[0]);
    		game.setTerr(Turf[0]);
			game.setTeam1(Eqs[i]);
			game.setTeam2(Eqs[i+1]);
			game.setGoals1(0);
			game.setGoals2(0);
			game.setPhase(ph);
			game.setDateheure("15/12/2024 18:00");
		}
		i++;
		
		M.push_back(game);
	}
	return M;
}

void MajPoints(vector<match>& matchs_termines, vector<equipe> &Eqs)
{
	// Reinitialiser les points
	for(auto& equipe:Eqs)
	{
		equipe.setPoints(0);
	}
	
	// Mettre a jour les points
	for(auto& match:matchs_termines)
	{
		equipe e1= match.getTeam1();
		equipe e2=match.getTeam2();
		int buts1=match.getGoals1();
		int buts2=match.getGoals2();
		
		
		for(auto& equipe:Eqs)
		{
			if(equipe.getNom()==e1.getNom())
			{ 
				equipe.setMatchsJoue(equipe.getMatchsJoue() + 1);
				if(buts1>buts2)
				{
					equipe.setGD(equipe.getGD() + buts1);
					equipe.setGD(equipe.getGD() - buts2); 
					equipe.setPoints(equipe.getPoints()+3);
				}
				
				else if(buts1==buts2)
				{
					equipe.setGD(equipe.getGD() + buts1);
					equipe.setGD(equipe.getGD() - buts2); 
					equipe.setPoints(equipe.getPoints()+1);
				}
				
				break;
			}
		}
		for(auto& equipe:Eqs)
		{
			if(equipe.getNom()==e2.getNom())
			{
				equipe.setMatchsJoue(equipe.getMatchsJoue() + 1);
				equipe.setGD(equipe.getGD() - buts1);
				equipe.setGD(equipe.getGD() + buts2); 
				if(buts2>buts1)
				{
					equipe.setPoints(equipe.getPoints()+3);
				}
				
				else if(buts1==buts2)
				{
					equipe.setPoints(equipe.getPoints()+1);
				}
				
				break;
			}
		}
	}
	
	// Tri du vecteur equipe selon points
	sort(Eqs.begin(), Eqs.end(),[](equipe& e1,equipe& e2)
	{
		if(e1.getPoints()==e2.getPoints())
			return e1.getClassement()<e2.getClassement();
		return e1.getPoints()>e2.getPoints();
	});
	for(int i=0; i<Eqs.size(); i++)
	{
		Eqs[i].setClassement(i+1);
	}
}


vector<match> SimulerMatchGrps(vector<match>& M, vector<equipe> Eqs,int ph)
{
	int buts1,buts2;
	vector<match> matchs_termines;
	equipe e1,e2;
	for(auto& i:M)
	{
		buts1=rand()%5;
		buts2=rand()%5;
		i.setGoals1(buts1);
		i.setGoals2(buts2);
		e1 = i.getTeam1(); 
		e2 = i.getTeam2();
		e1.setGD(e1.getGD()+buts1);
		e2.setGD(e2.getGD()+buts2);
		e1.setMatchsJoue(e1.getMatchsJoue()+1);
		e2.setMatchsJoue(e2.getMatchsJoue()+1);
		i.setTeam1(e1); 
		i.setTeam2(e2);
		matchs_termines.push_back(i);
	}
	return matchs_termines;
}



vector<match> SimulerMatchElim(vector<match>& M, vector<equipe>& Eqs,int ph)
{
	int buts1,buts2;
	vector<match> matchs_termines;
	equipe e1,e2;
	for(auto& i:M)
	{
		do{
			buts1=rand()%5;
			buts2=rand()%5;
		}while(buts1==buts2);
		
		i.setGoals1(buts1);
		i.setGoals2(buts2);
		e1 = i.getTeam1(); 
		e2 = i.getTeam2();
		e1.setGD(e1.getGD()+buts1);
		e2.setGD(e2.getGD()+buts2);
		e1.setMatchsJoue(e1.getMatchsJoue()+1);
		e2.setMatchsJoue(e2.getMatchsJoue()+1);
		i.setTeam1(e1); 
		i.setTeam2(e2);
		matchs_termines.push_back(i);
	}
	return matchs_termines;
}

