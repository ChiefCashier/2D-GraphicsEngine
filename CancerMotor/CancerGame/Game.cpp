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
		Pickup *pickup = new Pickup(500.0f,500.0f);
	while (true)
	{
		window.WindowMessageCheck();
		gcontext.Draw(&circle);
		if (pickup != nullptr)
		{
			if (p.GetX() < pickup->getShape()->GetX())
			{
				gcontext.RemoveDrawable(pickup->getShape());
				p.doPickupEffect();
				delete pickup;
				pickup = nullptr;

			}
		}
		gcontext.Draw(p.returnPaska(p.PLAYER));
		gcontext.Draw(p.returnPaska(p.CURSOR));
		if (pickup != nullptr)
		gcontext.Draw(pickup->getShape());
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
		if (pickup != nullptr)
		pickup->Update(0.0f);
		circle.SetRotation(circle.GetRotation() + 2.5);

		mx = CML::CMInput::getMouseX(window.CMWindowHandle());
		my = abs((CML::CMInput::getMouseY(window.CMWindowHandle()) - (window._windowHeight)));

		p.playerInputs(mx, my);
		

		if (CML::CMInput::isMouseKeyPressed(CML::CMInput::Mouse1))
		{
			for (int i = 0; i < 10; i++)
			ProjectileList.push_back(new Projectile(mx+ rand() % 20, my + rand() % 20, p.GetX(), p.GetY()));
		}

			if (CML::CMInput::isMouseKeyPressed(CML::CMInput::Mouse2))
			{
				EnemyList.push_back(new Enemy(mx, my));
			}	

							
					
							for (int i = 0; i < ProjectileList.size(); i++)
							{
								
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
