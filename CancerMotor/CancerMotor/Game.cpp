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
	
	Player p;
		CML::CMCircle circle(500, 250, 200, 6);
		circle.SetImage(CML::ResourceManager::createResource<CML::CMImage>("sample.png"));
		circle.SetRotation(0.0f);
		circle.SetSize(0.5f);
		circle.SetColor(0.0f, 0.0f, 0.0f, 0.0f);
	while (true)
	{
		window.WindowMessageCheck();
		gcontext.Draw(&circle);
		gcontext.Draw(p.returnPaska());
		
		circle.SetRotation(circle.GetRotation() + 2.5);

			//std::cout << p.GetX() << " "  << p.GetY() << std::endl;

			if (CML::CMInput::isKeyPressed(CML::CMInput::Right))
				p.SetX(p.GetX() + 10);
			if (CML::CMInput::isKeyPressed(CML::CMInput::Left))
				p.SetX(p.GetX() - 10);

			if (CML::CMInput::isKeyPressed(CML::CMInput::Up))
				p.SetY(p.GetY() + 10);
			if (CML::CMInput::isKeyPressed(CML::CMInput::Down))
				p.SetY(p.GetY() - 10);

			if (CML::CMInput::isKeyPressed(CML::CMInput::Space))
				p.SetRotation(p.GetRotation() + 15);

			if (CML::CMInput::isKeyPressed(CML::CMInput::N))
				p.SetSize(p.GetWidth() + 0.01);
			if (CML::CMInput::isKeyPressed(CML::CMInput::M))
				p.SetSize(p.GetWidth() - 0.01);

		gcontext.EndDraw();

		if (CML::CMInput::isKeyPressed(CML::CMInput::Escape))
			break;
	}
}

Game::~Game()
{
}
