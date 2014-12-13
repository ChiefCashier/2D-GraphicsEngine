#include "Game.h"
#include <Collision.h>

Game::Game()
{
	CML::CMWindow window(0, L"asd", 1000, 1000);
	window.ShowCMWindow();
	rContext = CML::RenderingContext(&window);
	gcontext.Initialize(&rContext);
	glClearColor(0.2f, 0.4f, 0.8f, 1.0f);


	GameState gameState = MainMenu;

	if (gameState == MainMenu)
	{
		Menu m;

		CML::CMRectangle background = CML::CMRectangle(500, 500, 1024, 768);
		background.SetImage(CML::ResourceManager::createResource<CML::CMImage>("MenuBackground.png"));
		background.SetRotation(0.0f);
		background.SetSize(CML::CMVector2<float>(-1.0f, 1.5f));
		background.SetColor(0.0f, 0.0f, 0.0f, 0.0f);
		background.SetOrigon(512, 384);

		while (true)
		{
			window.WindowMessageCheck();
			gcontext.Draw(&background);
			gcontext.Draw(m.returnShape());

			gcontext.EndDraw();

			if (CML::CMInput::isKeyPressed(CML::CMInput::Return))
			{
				gameState = Play;
				break;
			}

			if (CML::CMInput::isKeyPressed(CML::CMInput::Escape))
				break;
		}
	}

	if (gameState == Play)
	{
		float _jumpDelayMax = 1.0f;
		float _jumpDelayMin = 0.5f;
		float _currentTime = _currentTime = (rand() % (int)_jumpDelayMax) + _jumpDelayMin;
		//////////////////////////////////////////////////////////////////////////////////
		float _drugSpawnDelayMax = 10.0f;
		float _drugSpawnDelayMin = 5.0f;
		float _drugSpawnTimer = _drugSpawnTimer = (rand() % (int)_drugSpawnDelayMax) + _drugSpawnDelayMin;

		srand(time(NULL));
		float mx, my;
		Player p;
		CML::CMRectangle background2(0, 0, 1000, 1000);
		background2.SetImage(CML::ResourceManager::createResource<CML::CMImage>("background.jpg"));

		CML::CMRectangle tempbackground(-1000, 0, 1000, 1000);
		tempbackground.SetImage(CML::ResourceManager::createResource<CML::CMImage>("background.jpg"));

		std::vector<Projectile*>::iterator it;

		while (true)
		{
			window.WindowMessageCheck();
			gcontext.Draw(&background2);
			gcontext.Draw(&tempbackground);
			gcontext.Draw(p.returnShape());
			gcontext.Draw(p.GetCursor());
		
			if (p.GetX() < CML::CMInput::getMouseX(window.CMWindowHandle()))
			{
			//p.returnPaska(p.CURSOR)->SetSize(1);
			p.getShape()->SetTextureRectangle(0.0f, 0.0f, p.getShape()->GetImage()->getWidth(), p.getShape()->GetImage()->getHeight());
				p.GetCursor()->SetWidth(75);
				p.GetCursor()->SetHeight(-75);
			//p.SetWidth(-200);
			}
			else
			{
			p.getShape()->SetTextureRectangle(0.0f, 0.0f, -static_cast<float>(p.getShape()->GetImage()->getWidth()), p.getShape()->GetImage()->getHeight());

			//p.SetWidth(200);
				p.GetCursor()->SetWidth(-75);
				p.GetCursor()->SetHeight(-75);
			//p.returnPaska(p.CURSOR)->SetSize(-1);
			}
	
			// Scrolling background

			background2.SetX(background2.GetX() + 10);
			tempbackground.SetX(tempbackground.GetX() + 10);
			
			if (background2.GetX() > window._windowWidht)
			{
				background2.SetX(tempbackground.GetX() - background2.GetWidth());
			}

			if (tempbackground.GetX() > window._windowWidht)
			{
				tempbackground.SetX(background2.GetX() - tempbackground.GetWidth());
			}
			
			mx = CML::CMInput::getMouseX(window.CMWindowHandle());
			my = abs((CML::CMInput::getMouseY(window.CMWindowHandle()) - (window._windowHeight)));

			p.playerInputs(mx, my);


			if (CML::CMInput::isMouseKeyPressed(CML::CMInput::Mouse1))
			{
				for (int i = 0; i < 1; i++)
					ProjectileList.push_back(new Projectile(mx + rand() % 20, my + rand() % 20, p.GetX(), p.GetY()));
			}
			
			// Enemy spawn timer

			int u = rand() % 1000;
			if (_currentTime <= 0)
			{
				float sideSpawn = 0; 
				if (u > 500)
					sideSpawn = 0 - rand()%200;
				else
					sideSpawn = window._windowWidht + rand()%200;
				EnemyList.push_back(new Enemy(sideSpawn, rand() % 300 ));
				_currentTime = (rand() % (int)_jumpDelayMax) + _jumpDelayMin;
			}
			else
			{
				_currentTime -= 0.016;
			}

			// Drug spawn timer

			if (_drugSpawnTimer <= 0)
			{
		
			PickupList.push_back(new Pickup(rand() % window._windowWidht, window._windowHeight + rand() % 100));
			_drugSpawnTimer = (rand() % (int)_drugSpawnDelayMax + _drugSpawnDelayMin);
			}
			else
			{
				_drugSpawnTimer -= 0.016;
			}

			// Pickup/drugs
			for (int g = 0; g < PickupList.size(); g++)
			{
				bool asdd = CML::Collision::CollisionRectangle((PickupList[g]->getShape()), p.getShape());
				if (asdd == true)
				{
					gcontext.RemoveDrawable(PickupList[g]->getShape());
					p.doPickupEffect();

					//PickupList.at(g)->getShape()->~CMShape();
					PickupList.erase(PickupList.begin() + g);
					continue;
				}
				if (PickupList.size() != 0)
				{
					gcontext.Draw(PickupList[g]->getShape());
					PickupList[g]->Update(0.0f);
				}
			}


			for (int i = 0; i < ProjectileList.size(); i++)
			{
				std::cout << ProjectileList[i]->GetSpeed().getY() << std::endl;
				// If size has changed, shoot bigger bullits.
				if (p.getShape()->GetSize().getX() > 1)
				{
					ProjectileList[i]->returnShape()->SetSize(CML::CMVector2<float>(1.1f, 1.1f));
				}
				ProjectileList[i]->MoveProjectiles();
				gcontext.Draw(ProjectileList[i]->returnShape());

				if (ProjectileList.at(i)->returnShape()->GetX() < 0 || ProjectileList.at(i)->returnShape()->GetX() > 1000)
				{
					ProjectileList.at(i)->returnShape()->~CMShape();
					ProjectileList.erase(ProjectileList.begin() + i);
					continue;
				}
				if (ProjectileList.at(i)->returnShape()->GetY() < 0 || ProjectileList.at(i)->returnShape()->GetY() > 1000)
				{
					ProjectileList.at(i)->returnShape()->~CMShape();
					ProjectileList.erase(ProjectileList.begin() + i);
					continue;
				}


				for (int k = 0; k < EnemyList.size(); k++)
				{

					//if (EnemyList.size() == 0|| Projectik)
					bool asd = CML::Collision::CollisionRectangle((EnemyList[k]->returnShape()), ProjectileList[i]->returnShape());
					if (asd == true)
					{
						ProjectileList.at(i)->returnShape()->~CMShape();
						ProjectileList.erase(ProjectileList.begin() + i);
						EnemyList.at(k)->returnShape()->~CMShape();
						EnemyList.erase(EnemyList.begin() + k);
						break;
					}
					float distance = CML::CMVector2<float>::Distance(CML::CMVector2<float>(ProjectileList[i]->returnShape()->GetX(), ProjectileList[i]->returnShape()->GetY()), CML::CMVector2<float>(EnemyList[k]->returnShape()->GetX(), EnemyList[k]->returnShape()->GetY()));

					if (distance < 250.0f
						&& !EnemyList[k]->_jumping
						&& ProjectileList[i]->GetSpeed().getY() < 5)
					{
						EnemyList[k]->Jump();
					}

				}

			}


			for (int j = 0; j < EnemyList.size(); j++)
			{
				gcontext.Draw(EnemyList[j]->returnShape());
				EnemyList[j]->Update(p.GetX());


			}


			gcontext.EndDraw();

			if (CML::CMInput::isKeyPressed(CML::CMInput::Escape))
				break;
		}
	}
}

Game::~Game()
{
}
