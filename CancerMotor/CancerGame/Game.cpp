#include "Game.h"


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
		CML::CMCircle circle(500, 500, 800, 360 / 6);
		circle.SetImage(CML::ResourceManager::createResource<CML::CMImage>("sample.png"));
		std::vector<Projectile*>::iterator it;
	while (true)
	{
		window.WindowMessageCheck();
		gcontext.Draw(&circle);
		gcontext.Draw(p.returnPaska(p.CURSOR));
		gcontext.Draw(p.returnPaska(p.PLAYER));
		

		if (p.GetX() < CML::CMInput::getMouseX(window.CMWindowHandle()))
		{
			p.returnPaska(p.CURSOR)->SetSize(1);
			p.SetWidth(-200);
		}
		else
		{
			p.SetWidth(200);
			p.returnPaska(p.CURSOR)->SetSize(-1);
		}

		circle.SetRotation(circle.GetRotation() + 2.5);

		mx = CML::CMInput::getMouseX(window.CMWindowHandle());
		my = abs((CML::CMInput::getMouseY(window.CMWindowHandle()) - (window._windowHeight)));

		p.playerInputs(mx, my);
		

		if (CML::CMInput::isMouseKeyPressed(CML::CMInput::Mouse1))
		{
			ProjectileList.push_back(new Projectile(mx, my, p.GetX(), p.GetY()));
		}

			if (CML::CMInput::isMouseKeyPressed(CML::CMInput::Mouse2))
			{
				EnemyList.push_back(new Enemy(mx, my));
			}	

				
					
							for (int i = 0; i < ProjectileList.size(); i++)
							{
							ProjectileList[i]->MoveProjectiles();
							gcontext.Draw(ProjectileList[i]->returnPaska());
							}
					

						
							for (int j = 0; j < EnemyList.size(); j++)
							{
								gcontext.Draw(EnemyList[j]->returnShape());
								EnemyList[j]->EnemyMove(p.GetX(), p.GetY());
							}
						

		gcontext.EndDraw();

		if (CML::CMInput::isKeyPressed(CML::CMInput::Escape))
			break;
	}
}

Game::~Game()
{
}
