#include<iostream>
#include<vector>
#include<string>

#include"match.h"
#include"spectateur.h"

using namespace std;

int main() 
{   
	// Equipes
	vector<equipe> Eqs;
	vector<arbitre> Ref;
	vector<terrain> Turf;
	int phase=1;
	equipe Eq1("FC_Barcelona",1,0,0,0,false);
	equipe Eq2("Juve",1,0,0,0,false);
	equipe Eq3("Chelsea",1,0,0,0,false);
	equipe Eq4("Arsenal",1,0,0,0,false);
	equipe Eq5("Inter_Milan",1,0,0,0,false);
	equipe Eq6("Real_Madrid",1,0,0,0,false);
	equipe Eq7("Bayern_Munchen",1,0,0,0,false);
	equipe Eq8("Lazio",1,0,0,0,false);
	equipe Eq9("Man_Utd",1,0,0,0,false);
	equipe Eq10("PSG",1,0,0,0,false);
	
	Eqs.push_back(Eq1);
	Eqs.push_back(Eq2);
	Eqs.push_back(Eq3);
	Eqs.push_back(Eq4);
	Eqs.push_back(Eq5);
	Eqs.push_back(Eq6);
	Eqs.push_back(Eq7);
	Eqs.push_back(Eq8);
	Eqs.push_back(Eq9);
	Eqs.push_back(Eq10);


	// Arbitres
	arbitre A1("Radouane_Jayed", 42,3,10);
	arbitre A2("Mateu_Lahoz", 44,1,11);
	arbitre A3("Michael_Oliver", 25,2,6);
	arbitre A4("Gil_Manzano", 20,0,2);
	Ref.push_back(A1);
	Ref.push_back(A2);
	Ref.push_back(A3);
	Ref.push_back(A4);

	

	// Terrains
	terrain T1("Wembley",90000,"London");
	terrain T2("Santiago_Bernabeu",78000,"Madrid");
	terrain T3("San_Siro",80000,"Milan");
	terrain T4("Parc_des_Princes",50000,"Paris");
	Turf.push_back(T1);
	Turf.push_back(T2);
	Turf.push_back(T3);
	Turf.push_back(T4);
	
	int choix;
	int choice2;
	vector<spectateur> Spect;
	vector<match> M;
	cout<<"==========MENU PRINCIPAL========="<<endl;
	cout<<"1. Gestion Equipes"<<endl;
	cout<<"2. Gestion Arbitres"<<endl;
	cout<<"3. Gestion Terrains"<<endl;
	cout<<"4. Gestion Spectateurs"<<endl;
	cout<<"5. Planification des Matchs"<<endl;
	cout<<"6. Simulation des Matchs"<<endl;
	cout<<"7. Table de Classement"<<endl;
	
	do
	{
		
		cout<<"Choisir ";
		cin>>choix;
		switch(choix)
		{
			case 1:
			{
				cout<<endl;
				cout<<"		-----------SOUS MENU EQUIPE-----------"<<endl;
				cout<<"		1. Ajouter Equipe"<<endl;
				cout<<"		2. Afficher les Equipes"<<endl;
				cout<<"		3. Supprimer Equipe "<<endl;
				cout<<"		4. Afficher le classement"<<endl;
				cout<<"		5. Recherche Equipe"<<endl<<endl;
				cout<<"=> Choisir ";
				cin>>choice2;
				vector<equipe> Eq;
				switch(choice2)
				{
					case 1:
					{
						Eqs=AjouterEq(Eqs);
						break;
					}
					case 2:
					{
						AfficherEqs(Eqs);
						break;
					}
					case 3:
					{
						Eqs=SupprimerEq(Eqs);
						break;
					}
					case 5:
					{
						RechercheEq(Eqs);
						break;
					}			
				}
				break;
			}
			case 2:
			{
				cout<<"		1. Ajouter Arbitre"<<endl;
				cout<<"		2. Afficher les Arbitres"<<endl;
				cout<<"		3. Recherche Arbitre"<<endl;
				cout<<"=> Choisir ";
				cin>>choice2;
				switch(choice2)
				{
					case 1:
					{
						AjouterArbitres(Ref);
						break;
					}
					case 2:
					{
						AfficherArbitres(Ref);
						break;
					}
					case 3:
					{
						RechercherArbitre(Ref);
						break;
					}	
				}
				break;
			}
			case 3:
			{
				cout<<"		1. Ajouter Terrain"<<endl;
				cout<<"		2. Afficher les Terrains"<<endl;
				cout<<"		3. Recherche Terrain"<<endl;
				cout<<"		4. Supprimer Terrain"<<endl;
				cout<<"=> Choisir ";
				cin>>choice2;
				switch(choice2)
				{
					case 1:
					{
						Turf=AjouterTerr(Turf);
						break;
					}
					case 2:
					{
						AfficherTurfs(Turf);
						break;
					}
					case 3:
					{
						RechercherTerr(Turf);
						break;
					}
					case 4:
					{
						Turf=SupprimerTerr(Turf);
						break;
					}
				}
				break;
			}
				
			case 4:
			{
				cout<<"		1. Ajouter Spectateur"<<endl;
				cout<<"		2. Afficher les Spectateurs"<<endl;
				cout<<"=> Choisir ";
				cin>>choice2;
				switch(choice2)
				{
					case 1:
					{
						Spect=AjouterSpect(Spect);
						break;
					}
					case 2:
					{
						AfficherSpectateurs(Spect);
						break;
					}
				}
				break;
			}
			case 5:
			{
				cout<<"		1. Phase de Groupes"<<endl;
				cout<<"		2. Quart de Finale"<<endl;
				cout<<"		3. Semi Finale"<<endl;
				cout<<"		4. Finale"<<endl;
				cout<<"=> Choisir ";
				cin>>choice2;
				switch(choice2)
				{
					case 1:
					{
						M=creerMatchsGrps(Eqs,Ref, Turf, 1);
						for(auto i:M)	
							i.AfficherDetailsAvantSim();
						break;
					}
					case 2:
					{
						M=creerMatchsElim(Eqs,Ref, Turf, 3);
						for(auto i:M)	
							i.AfficherDetailsAvantSim();
						break;
					}
					case 3:
					{
						M=creerMatchsElim(Eqs,Ref, Turf, 4);
						for(auto i:M)	
							i.AfficherDetailsAvantSim();
						break;
					}
					case 4:
					{
						M=creerMatchsElim(Eqs,Ref, Turf, 5);
						for(auto i:M)	
							i.AfficherDetailsAvantSim();
						break;
					}
				}
				break;
			}
			case 6:
			{
				cout<<"		1. Phase de Groupes"<<endl;
				cout<<"		2. Quart de Finale"<<endl;
				cout<<"		3. Semi Finale"<<endl;
				cout<<"		4. Finale"<<endl;
				cout<<"=> Choisir ";
				cin>>choice2;
				switch(choice2)
				{
					case 1:
					{
						M=SimulerMatchGrps(M,Eqs,1);
						for(auto i:M)	
							i.AfficherDetailsApresSim();
						MajPoints(M,Eqs);
						Eqs.pop_back();
						Eqs.pop_back();
						break;
					}
					case 2:
					{
						M=creerMatchsElim(Eqs,Ref, Turf, 3);
						M=SimulerMatchElim(M,Eqs,3);
						for(auto i:M)	
							i.AfficherDetailsApresSim();
						MajPoints(M,Eqs);
						Eqs.pop_back();
						Eqs.pop_back();
						Eqs.pop_back();
						Eqs.pop_back();
						break;
					}
					case 3:
					{
						M=creerMatchsElim(Eqs,Ref, Turf, 4);
						M=SimulerMatchElim(M,Eqs,4);
						for(auto i:M)	
							i.AfficherDetailsApresSim();
						MajPoints(M,Eqs);
						Eqs.pop_back();
						Eqs.pop_back();		
						break;
					}
					case 4:
					{
						cout<<"\nPhase suivante"<<endl;
						M=creerMatchsElim(Eqs,Ref, Turf, 5);
						M=SimulerMatchElim(M,Eqs,5);
						for(auto i:M)	
							i.AfficherDetailsApresSim();
						MajPoints(M,Eqs);
						Eqs.pop_back();

						cout<<"Felicitations !!! "<<Eqs[0].getNom()<<" remporte le Tournoi"<<endl;
						break;
					}
				}
			}
			case 7:
			{
				AfficherEqs(Eqs);
			}
		}
		cout<<"Continuer? (1/0) ";
		cin>>choix;
	}while(choix==1);
	
	
}
