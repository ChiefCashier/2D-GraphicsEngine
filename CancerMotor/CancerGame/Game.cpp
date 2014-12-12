#include "Game.h"
#include <Collision.h>

Game::Game()
{
	CML::CMWindow window(0, L"asd", 1000, 1000);
	window.ShowCMWindow();
	rContext = CML::RenderingContext(&window);
	gcontext.Initialize(&rContext);
	glClearColor(0.2f, 0.4f, 0.8f, 1.0f);

	srand(time(NULL));
	float mx, my;
	Player p;
		CML::CMRectangle background(0, 0, 1000, 1000);
		background.SetImage(CML::ResourceManager::createResource<CML::CMImage>("background.jpg"));

		CML::CMRectangle tempbackground(-1000, 0, 1000, 1000);
		tempbackground.SetImage(CML::ResourceManager::createResource<CML::CMImage>("background.jpg"));

		std::vector<Projectile*>::iterator it;
	while (true)
	{
		window.WindowMessageCheck();
		gcontext.Draw(&background);
		gcontext.Draw(&tempbackground);

		gcontext.Draw(p.returnPaska(p.PLAYER));
		gcontext.Draw(p.returnPaska(p.CURSOR));
		if (p.GetX() < CML::CMInput::getMouseX(window.CMWindowHandle()))
		{
			p.GetCursor()->SetWidth(75);
			p.GetCursor()->SetHeight(-75);
			p.SetWidth(-200);
		}
		else
		{
			p.SetWidth(200);
			p.GetCursor()->SetWidth(-75);
			p.GetCursor()->SetHeight(-75);
		}

		// Scrolling background

		background.SetX(background.GetX() + 10);
		tempbackground.SetX(tempbackground.GetX() + 10);

		if (background.GetX() > window._windowWidht )
		{
			background.SetX(tempbackground.GetX() - background.GetWidth());
		}
			
		if (tempbackground.GetX() > window._windowWidht )
		{
			tempbackground.SetX(background.GetX() - tempbackground.GetWidth());
		}


		mx = CML::CMInput::getMouseX(window.CMWindowHandle());
		my = abs((CML::CMInput::getMouseY(window.CMWindowHandle()) - (window._windowHeight)));

		p.playerInputs(mx, my);
		

		if (CML::CMInput::isMouseKeyPressed(CML::CMInput::Mouse1))
		{
			for (int i = 0; i < 1; i++)
			ProjectileList.push_back(new Projectile(mx+ rand() % 20, my + rand() % 20, p.GetX(), p.GetY()));
		}

			if (CML::CMInput::isMouseKeyPressed(CML::CMInput::Mouse2))
			{
				EnemyList.push_back(new Enemy(mx, my));
			}	

							
					
							for (int i = 0; i < ProjectileList.size(); i++)
							{
								
								std::cout << ProjectileList[i]->GetSpeed().getY() << std::endl;

							ProjectileList[i]->MoveProjectiles();
							gcontext.Draw(ProjectileList[i]->returnPaska());

								if (ProjectileList.at(i)->returnPaska()->GetX() < 0 || ProjectileList.at(i)->returnPaska()->GetX() > 1000)
								{
									ProjectileList.at(i)->returnPaska()->~CMShape();
									ProjectileList.erase(ProjectileList.begin() + i);
									continue;
								}
								if (ProjectileList.at(i)->returnPaska()->GetY() < 0 || ProjectileList.at(i)->returnPaska()->GetY() > 1000)
								{
									ProjectileList.at(i)->returnPaska()->~CMShape();
									ProjectileList.erase(ProjectileList.begin() + i);
								}


								for (int k = 0; k < EnemyList.size(); k++)
								{
									

									bool asd = CML::Collision::CollisionRectangle((EnemyList[k]->returnShape()), ProjectileList[i]->returnPaska());
									if ( asd == true)
									{
										ProjectileList.at(i)->returnPaska()->~CMShape();
										ProjectileList.erase(ProjectileList.begin() + i);
										EnemyList.at(k)->returnShape()->~CMShape();
										EnemyList.erase(EnemyList.begin() + k);
										break;
									}
									float distance = CML::CMVector2<float>::Distance(CML::CMVector2<float>(ProjectileList[i]->returnPaska()->GetX(), ProjectileList[i]->returnPaska()->GetY()), CML::CMVector2<float>(EnemyList[k]->returnShape()->GetX(), EnemyList[k]->returnShape()->GetY()));
									
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

Game::~Game()
{
}
