#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

string yazi;

int main(int argc,char* argv[]) 
{



    if(argc < 2)
    {
        sf::Font font;

        font.loadFromFile("/usr/share/OpenTtf/OpenSans-Italic-VariableFont_wdth,wght.ttf");

        sf::Text text;
        text.setFont(font);
        text.setString("Ttf file not entered!");
        text.setCharacterSize(80);
        text.setFillColor(sf::Color::Red);
        text.setPosition(100,360);



        sf::RenderWindow window(sf::VideoMode(800,800),"A", sf::Style::Titlebar | sf::Style::Close);


        sf::Image icon;
        icon.loadFromFile("/usr/share/icons/OpenTtf/OpenTtf.png");


        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());



        

            

        window.clear(sf::Color::White);

        window.draw(text);
            
        window.display();
        sf::sleep(sf::seconds(3));
    

        return 0;

    }








    sf::Image icon;


    icon.loadFromFile("/usr/share/icons/OpenTtf/OpenTtf.png");


    










    sf::Font font;
    if (!font.loadFromFile( argv[1] )) {  
        yazi="Could not open file!";
        font.loadFromFile("/usr/share/OpenTtf/OpenSans-Italic-VariableFont_wdth,wght.ttf");
    }
    else
    {

    	yazi= string(argv[1]) + " font";
    }




    int pxx = (yazi.length() * 40) + 200;
    int pxx2=100;







    sf::RenderWindow window(sf::VideoMode(pxx, 800),(string(argv[1]) + " font").c_str(), sf::Style::Titlebar | sf::Style::Close);
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());






    sf::Text text;
    text.setFont(font);
    text.setString(yazi);
    text.setCharacterSize(80);

    if(yazi != "Could not open file!")text.setFillColor(sf::Color::Black);
    if(yazi == "Could not open file!")text.setFillColor(sf::Color::Red);

    text.setPosition(pxx2,355);
    while (window.isOpen()) 
    {

        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(text);
        window.display();
    }

    return 0;
}

