#ifndef menu_h
#define menu_h
#include"libararies.h"
class Menu {
private:
    sf::Font font;
    sf::Text text[5];
    int option = 1;
public:

    //add menu attributes here
    Menu() {};
    void InitialMenu() {
        if (!font.loadFromFile("\OpenSans-BoldItalic.ttf")) {
            cout << "Error Loading File" << endl;
        }
        else {
            text[0].setFont(font);
            text[0].setFillColor(Color::Blue);
            text[0].setString("Dodge EM");
            text[0].setCharacterSize(80);
            text[0].setPosition(400, 100);

            text[1].setFont(font);
            text[1].setFillColor(Color::Red);
            text[1].setString("Start Game");
            text[1].setCharacterSize(60);
            text[1].setPosition(400, 250);

            text[2].setFont(font);
            text[2].setFillColor(Color::White);
            text[2].setString("High Score");
            text[2].setCharacterSize(60);
            text[2].setPosition(400, 400);

            text[3].setFont(font);
            text[3].setFillColor(Color::White);
            text[3].setString("Help");
            text[3].setCharacterSize(60);
            text[3].setPosition(400, 550);

            text[4].setFont(font);
            text[4].setFillColor(Color::White);
            text[4].setString("Exit");
            text[4].setCharacterSize(60);
            text[4].setPosition(400, 700);
        }

    }

    void up() {
        if (option - 1 != 0) {
            text[option].setFillColor(Color::White);
            option--;
            text[option].setFillColor(Color::Red);
        }
    }
    void down() {
        if (option + 1 != 5) {
            text[option].setFillColor(Color::White);
            option++;
            text[option].setFillColor(Color::Red);
            text[0].setFillColor(Color::Blue);
        }
    }

    void DisplayMenu(RenderWindow& window) {
        for (int i = 0; i < 5; i++) {
            window.draw(text[i]);
        }
    }

    void display_menu()

    {

        Game* g;
        g = new Game;
        Sprite background; // Game background sprite
        Texture bg_texture;
        bg_texture.loadFromFile("img/background_1.png");
        background.setTexture(bg_texture);
        background.setScale(2, 2);
        RenderWindow mnu(VideoMode(1200, 1000), "Menu");
        InitialMenu();
        while (mnu.isOpen()) {
            Event e;
            bool flag = true;
            while (mnu.pollEvent(e))
            {
                if (e.type == Event::Closed)
                    mnu.close();
                if (e.type == Event::KeyReleased) {
                    if (e.key.code == Keyboard::Up) {
                        up();
                    }
                    else if (e.key.code == Keyboard::Down) {
                        down();
                    }
                    else if (e.key.code == Keyboard::Return) {
                        if (option == 1) {
                            mnu.close();
                            g->start_game();
                        }
                        else if (option == 4) {
                            mnu.close();
                        }

                    }
                }
            }
            mnu.clear(Color::Black);
            mnu.draw(background);
            DisplayMenu(mnu);
            mnu.display();
        }
        //g.start_game();
        //display menu screen here
        // 
        // add functionality of all the menu options here

        //if Start game option is chosen 

       //g.start_game();


    }


};
#endif //