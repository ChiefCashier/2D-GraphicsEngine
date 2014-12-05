#include "Game.h"


Game::Game()
{
	glewInit();
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
			p.SetWidth(-200);
		else
			p.SetWidth(200);

		circle.SetRotation(circle.GetRotation() + 2.5);

		mx = CML::CMInput::getMouseX(window.CMWindowHandle());
		my = abs((CML::CMInput::getMouseY(window.CMWindowHandle()) - (window._windowHeight)));

		p.playerInputs(mx, my);
		

		if (CML::CMInput::isMouseKeyPressed(CML::CMInput::Mouse1))
		{
			ProjectileList.push_back(new Projectile(mx, my, p.GetX(), p.GetY()));
		}

		//if (CML::CMInput::isMouseKeyPressed(CML::CMInput::Mouse2))
		//{
		//	for (int i = 0; i < ProjectileList.size(); i++)
		//	{
		//		//std::cout << ProjectileList.size() << std::endl;
		//		if (ProjectileList[i]->Collision(mx, my))
		//		{
		//			std::cout << "osuu" << i << std::endl;

		//			it = ProjectileList.begin() + i;
		//			if (it != ProjectileList.end())
		//			{
		//		
		//				it = ProjectileList.erase(it);
		//			}
		//		}
		//	}
		//}


		if (!ProjectileList.empty())
		{
				for (int i = 0; i < ProjectileList.size(); i++)
				{
				ProjectileList[i]->MoveProjectiles();
				gcontext.Draw(ProjectileList[i]->returnPaska());
				}
		}

		gcontext.EndDraw();

		if (CML::CMInput::isKeyPressed(CML::CMInput::Escape))
			break;
	}
}

Game::~Game()
{
}
