
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <fstream>
#include "utils.h"
#include "functionality.h"

using namespace sf;
int main(){
	
	gameReset();
	
	srand(time(0));
	RenderWindow window(VideoMode(650, 480), title);
	
	Texture obj1, obj2, obj3, obj4, obj5, obj6;
	Font fontForScore;
	Text scoringtext, theWordScore, highScoreText;
	
	obj1.loadFromFile("img/head.png");
	obj2.loadFromFile("img/background.png");
	obj3.loadFromFile("img/frame.png");
	obj4.loadFromFile("img/body.png");
	obj5.loadFromFile("img/food.png");
	obj6.loadFromFile("img/death.png");
	fontForScore.loadFromFile("fonts/metallord.ttf");
	
	scoringtext.setFont(fontForScore);			//sets the font for this Text.
	scoringtext.setCharacterSize(45); 			//sets the size of the text.
	scoringtext.setFillColor(Color::Black); 		//sets its color as black.
	scoringtext.setPosition(555,190); 			//sets it position on the screen.
	
	theWordScore.setFont(fontForScore);			
	theWordScore.setCharacterSize(45); 			
	theWordScore.setFillColor(Color::Black); 		
	theWordScore.setPosition(490,100); 			
	theWordScore.setString("Score\n- - - - - -");
	
	highScoreText.setFont(fontForScore);
	highScoreText.setCharacterSize(33);
	highScoreText.setFillColor(Color::Black);
	highScoreText.setPosition(210,423);
	
	std::ifstream readFile;
	std::ofstream writeFile;
	std::string highscoreString;
	
	readFile.open("./highscore.txt");			// reading from the file highscore.txt and 
	if(readFile.is_open()){					// storing the highscore inhighscore.txt file.
		while(!readFile.eof()){
			readFile>>highscoreString;
		}
	}
	readFile.close();
	highScoreText.setString(highscoreString);

	Sprite headimg(obj1), background(obj2), frame(obj3), bodyimg(obj4), foodimg(obj5), deathimg(obj6);
	int delta_x=-2, colorNum=1;
	float timer=0;
	bool rotate=0; 
	bool spawn = 0;

	
	Clock clock;
	
	while (window.isOpen()){
	
	float time = clock.getElapsedTime().asSeconds();
	clock.restart();
	timer+=time;

        // ------- Event Listening Part ------- //
        
	Event e;
	
	while (window.pollEvent(e)){                    
		if (e.type == Event::Closed)                 
			window.close();                            
		if (e.type == Event::KeyPressed) {             
			if (e.key.code == Keyboard::Up)            
				delta_x = 2;                
			else if(e.key.code == Keyboard::Down)
				delta_x = -2;        
			else if (e.key.code == Keyboard::Left)     
				delta_x = -1;                         
			else if (e.key.code == Keyboard::Right)    
				delta_x = 1;     
			if (e.key.code == Keyboard::Space)
				spawn=true;                      
		}
	}
	if(!death){
	snakeFood(spawn);
	snake(timer, delta_x, spawn); 
	}


	window.clear(Color::Black);
	window.draw(background);
	
	for(int i=0; i<O;i++)
	{
		if(i>bodyStop)
			break;
		bodyimg.setTextureRect(IntRect(0,0,20,20));
		bodyimg.setPosition(body[i][0]*20,body[i][1]*20);
		bodyimg.move(40,31);
		window.draw(bodyimg);
	}

	headimg.setTextureRect(IntRect(0,0,20,20));
	headimg.setPosition(head[0]*20,head[1]*20);
	headimg.move(40,31);
	window.draw(headimg);
	
	foodimg.setTextureRect(IntRect(0,0,20,20));
	foodimg.setPosition(food[0]*20,food[1]*20);
	foodimg.move(40,31);
	window.draw(foodimg);

	window.draw(frame);
	
	scoringtext.setString(std::to_string(scoreNum)); 				//the string stored in 'scoretext'
	window.draw(scoringtext);
	window.draw(theWordScore);
	
	if(death){
		if(std::stoi(highscoreString)<scoreNum){				//stores the new score as highscore
			writeFile.open("./highscore.txt");				//in highscore.txt file
			if(writeFile.is_open()){
				writeFile<<std::to_string(scoreNum);
				writeFile.close();
			}
		}
		readFile.open("./highscore.txt");			// reading from the file highscore.txt and 
		if(readFile.is_open()){					// storing the highscore inhighscore.txt file.
			while(!readFile.eof()){
				readFile>>highscoreString;
			}
		}
		readFile.close();
		highScoreText.setString(highscoreString);

		window.draw(deathimg);			
		scoringtext.setCharacterSize(60); 					
		scoringtext.setPosition(300,270); 
		window.draw(scoringtext);
		window.draw(highScoreText);
		
		if(Keyboard::isKeyPressed(Keyboard::R)){
					
			scoringtext.setCharacterSize(45); 			
			scoringtext.setPosition(555,190); 	
				
			death=false;
			gameReset();
			scoreNum=0;
		}
	}

	window.display();
	}
	
	return 0;
}
