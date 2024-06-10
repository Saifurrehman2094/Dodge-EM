#ifndef game_h
#define game_h

#include"libararies.h"
#include"Car.h"
#include"reward.h"
#include <SFML/Audio.hpp>
#include<fstream>
using namespace std;
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

const int numSmallBoxes = 32; // Set the number of small boxes

class Box
{
public:
    RectangleShape shape;  // Direction of movement for the box
    
    // Default constructor
    Box()
        // Set a default direction (you can adjust as needed)
    {
        // Set default properties or leave them uninitialized as needed
    }

    // Parameterized constructor
    Box(float x, float y, float width, float height)
    {
        shape.setSize(Vector2f(width, height));
        shape.setPosition(x, y);
        shape.setFillColor(Color::Red); // Adjust the color as needed
        // shape.setOutlineColor(sf::Color::Red);
        //shape.setOutlineThickness(5);
    }

};



void DrawTriangle(Triangle t[], RenderWindow& window) {
    for (int i = 0; i < 4; i++) {
        window.draw(t[i].s);
    }
}
void DrawCircle(Circle c[], RenderWindow& window) {
    for (int i = 0; i < 4; i++) {
        window.draw(c[i].s);
    }
}
void DrawHex(Hexagon h[], RenderWindow& window) {
    for (int i = 0; i < 2; i++) {
        window.draw(h[i].s);
    }
}
void DrawRec(Rectangle r[], RenderWindow& window) {
    for (int i = 0; i < 2; i++) {
        window.draw(r[i].s);
    }
}
void pmove(Player*& p, int a=1, int b=0) {
    p->getsprite().move(a*(2.0f), b*(2.0f));
}
void emove(Enemy*& e, int a = 1, int b = 0) {
    e->getsprite().move(a * (2.0f), b * (2.0f));
}
void LeftKey(Player*& p, int y,int x, int& path) {
    if (!(path == 6)) {
        if ((y >= 360 && y <= 500) && path == 0&&x==1090) {
            p->getsprite().setPosition(1000, y);
            path = 1;
        }
        else if ((y >= 300 && y <= 450) && path == 1 && x==1000) {
            p->getsprite().setPosition(900, y);
            path = 2;
        }
        else if ((y >= 300 && y <= 450) && path == 2 &&x==900) {
            p->getsprite().setPosition(800, y);
            path = 3;
        }
        else if ((y >= 360 && y <= 500) && path == 3&&x==380) {
            p->getsprite().setPosition(300, y);
            path = 4;
        }
        else if ((y >= 300 && y <= 450) && path == 4 && x == 290) {
            p->getsprite().setPosition(200, y);
            path = 5;
        }
        else if ((y >= 300 && y <= 450) && path == 5 && x == 190) {
            p->getsprite().setPosition(100, y);
            path = 6;
        }
    }
}
void RightKey(Player*& p, int y,int x, int& path) {
    if ((y >= 360 && y <= 500)&&path==6) {
        p->getsprite().setPosition(200, y);
        path = 5;
    }
    else if ((y >= 360 && y <= 500) && path == 5) {
        p->getsprite().setPosition(300, y);
        path = 4;
    }
    else if ((y >= 360 && y <= 500) && path == 4) {
        p->getsprite().setPosition(400, y);
        path = 3;
    }
    else if ((y >= 360 && y <= 500) && path == 3) {
        p->getsprite().setPosition(900, y);
        path = 2;
    }
    else if ((y >= 360 && y <= 500) && path == 2) {
        p->getsprite().setPosition(1000, y);
        path = 1;
    }
    else if ((y >= 360 && y <= 500) && path == 1) {
        p->getsprite().setPosition(1090, y);
        path = 0;
    }

}
void upKey(Player*& p, int x, int y, int& path) {
    int a = p->getsprite().getPosition().x;
    if (y == 790) {
        path = 0;
    }
    else if (y == 710) {
        path = 1;
    }
    else if (y == 610) {
        path = 2;
    }
    else if (y == 515) {
        path = 3;
    }
    else if (y == 370) {
        path = 3;
    }
    else if (y == 290) {
        path = 4;
    }
    else if (y == 200) {
        path = 5;
    }
    else if (y == 115) {
        path = 6;
    }
    if (x >= 525 && x <= 665 && path==0) {
        p->getsprite().setPosition(a, 710);
        path = 1;
    }
    else if (x >= 525 && x <= 665 && path == 1) {
        p->getsprite().setPosition(a, 610);
        path = 2;
    }
    else if (x >= 525 && x <= 665 && path == 2) {
        p->getsprite().setPosition(a, 515);
        path = 3;
    }
    else if (x >= 525 && x <= 665 && path == 3 && y== 370) {
        p->getsprite().setPosition(a, 290);
        path = 4;
    }
    else if (x >= 525 && x <= 665 && path == 4 && y == 290) {
        p->getsprite().setPosition(a, 200);
        path = 5;
    }
    else if (x >= 525 && x <= 665 && path == 5 && y == 200) {
        p->getsprite().setPosition(a, 115);
        path = 6;
    }

}
void Scorerec(Player* &p,Rectangle r[], int& s) {
    for (int i = 0; i < 2; i++) {
        if (p->getsprite().getGlobalBounds().intersects(r[i].s.getGlobalBounds())) {
            s += 5;
            r[i].s.setPosition(-1000, 10000);
        }
    }
}
void Scorehex(Player*& p, Hexagon h[], int& s) {
    for (int i = 0; i < 2; i++) {
        if (p->getsprite().getGlobalBounds().intersects(h[i].s.getGlobalBounds())) {
            s += 10;
            h[i].s.setPosition(-1000, 10000);
        }
    }
}
void Scoretri(Player*& p, Triangle t[], int& s) {
    for (int i = 0; i < 4; i++) {
        if (p->getsprite().getGlobalBounds().intersects(t[i].s.getGlobalBounds())) {
            s += 10;
            t[i].s.setPosition(-1000, 10000);
        }
    }
}
void Scorecr(Player*& p, Circle c[], int& s) {
    for (int i = 0; i < 4; i++) {
        if (p->getsprite().getGlobalBounds().intersects(c[i].s.getGlobalBounds())) {
            s += 10;
            c[i].s.setPosition(-1000, 10000);
        }
    }
}
void DownKey(Player*& p, int x, int y, int& path) {
    int a = p->getsprite().getPosition().x;
    if (y == 115) {
        path = 6;
    }
    else if (y == 200) {
        path = 5;
    }
    else if (y == 290) {
        path = 4;
    }
    else if (y == 370) {
        path = 3;
    }
    else if (y == 515) {
        path = 3;
    }
    else if (y == 610) {
        path = 2;
    }
    else if (y == 710) {
        path = 1;
    }
    if (x >= 525 && x <= 665 && path == 6 && y == 115) {
        p->getsprite().setPosition(a, 200);
        path = 5;
    }
    else if (x >= 525 && x <= 665 && path == 5 && y == 200) {
        p->getsprite().setPosition(a, 290);
        path = 4;
    }
    else if (x >= 525 && x <= 665 && path == 4 && y == 290) {
        p->getsprite().setPosition(a, 370);
        path = 3;
    }
    else if (x >= 525 && x <= 665 && path == 3 && y == 515) {
        p->getsprite().setPosition(a, 610);
        path = 2;
    }
    else if (x >= 525 && x <= 665 && path == 2 && y == 610) {
        p->getsprite().setPosition(a, 710);
        path = 1;
    }
    else if (x >= 525 && x <= 665 && path == 1 && y == 710) {
        p->getsprite().setPosition(a, 790);
        path = 0;
    }
    
}

void checkeMovement(Enemy* &e, Box smallBoxes[]) {
    static int a = 0;
    static int b = 0;
    bool flag = 0;
    static int check = 0;
    if (a == 0 && b == 0) {
        e->getsprite().move(-0.8f, 0.0f);
    }
    for (int i = 0; i < 32; i++) {
        if (e->getsprite().getGlobalBounds().intersects(smallBoxes[i].shape.getGlobalBounds())) {
            if (i == 30) {
                e->getsprite().setPosition(90, 720);
                a = 0;
                b = -1;
                flag = 1;
                break;
            }
            else if (i == 24) {
                e->getsprite().setPosition(190, 115);
                a = 1;
                b = 0;
                flag = 1;
                break;
            }
            else if (i == 29) {
                e->getsprite().setPosition(1090, 170);
                a = 0;
                b = 1;
                flag = 1;
                break;
            }
            else if (i == 27) {
                e->getsprite().setPosition(1000, 790);
                a = -1;
                b = 0;
                flag = 1;
                break;
            }
            else if (i == 4) {
                e->getsprite().setPosition(220, 200);
                a = 1;
                b = 0;
                flag = 1;
                break;
            }
            else if (i == 0) {
                e->getsprite().setPosition(e->getsprite().getPosition().x-50, 230);
                a = 0;
                b = 1;
                flag = 1;
                break;
            }
            else if (i == 7) {
                e->getsprite().setPosition(e->getsprite().getPosition().x -25, 710);
                a = -1;
                b = 0;
                flag = 1;
                break;
            }
            else if (i == 3) {
                e->getsprite().setPosition(e->getsprite().getPosition().x + 50, 680);
                a = 0;
                b = -1;
                flag = 1;
                break;
            }
            else if (i == 12) {
                e->getsprite().setPosition(e->getsprite().getPosition().x - 30, 610);
                a = -1;
                b = 0;
                flag = 1;
                break;
            }
            else if (i == 8) {
                e->getsprite().setPosition(e->getsprite().getPosition().x + 30, 290);
                a = 1;
                b = 0;
                flag = 1;
                break;
            }
            else if (i == 11) {
                e->getsprite().setPosition(e->getsprite().getPosition().x + 50, 580);
                a = 0;
                b = -1;
                flag = 1;
                break;
            }
            else if (i == 15) {
                e->getsprite().setPosition(e->getsprite().getPosition().x -60, 340);
                a = 0;
                b = 1;
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1)
        e->getsprite().rotate(90);
    if (check == 0)
        emove(e, a, b);
}

void checkpMovement(Player*& p, Box smallBoxes[]) {
    static int a = 0;
    static int b = 0;
    bool flag = 0;
    static int check = 0;
    if (a==0&&b==0) {
        p->getsprite().move(0.8f, 0.0f);
    }
    for (int i = 0; i < 32; i++) {
        if (p->getsprite().getGlobalBounds().intersects(smallBoxes[i].shape.getGlobalBounds())) {
            if (i == 31) {
                p->getsprite().setPosition(1090, 720);
                a = 0;
                b = -1;
                flag = 1;
                break;
            }
            else if (i == 25) {
                p->getsprite().setPosition(1000, 115);
                a = -1;
                b = 0;
                flag = 1;
                break;
            }
            else if (i == 28) {
                p->getsprite().setPosition(100, 170);
                a = 0;
                b = 1;
                flag = 1;
                break;
            }
            else if (i == 26) {
                p->getsprite().setPosition(140, 790);
                a = 1;
                b = 0;
                flag = 1;
                break;
            }
            else if (i == 5) {
                p->getsprite().setPosition(950, 200);
                a = -1;
                b = 0;
                flag = 1;
                break;
            }
            else if (i == 2) {
                p->getsprite().setPosition(190, 230);
                a = 0;
                b = 1;
                flag = 1;
                break;
            }
            else if (i == 6) {
                p->getsprite().setPosition(215, 710);
                a = 1;
                b = 0;
                flag = 1;
            }
            else if (i == 1) {
                p->getsprite().setPosition(1000, 685);
                a = 0;
                b = -1;
                flag = 1;
                break;
            }
            else if (i == 9) {
                p->getsprite().setPosition(865, 290);
                a = -1;
                b = 0;
                flag = 1;
                break;
            }
            else if (i == 10) {
                p->getsprite().setPosition(290, 335);
                a = 0;
                b = 1;
                flag = 1;
                break;
            }
            else if (i == 13) {
                p->getsprite().setPosition(330, 610);
                a = 1;
                b = 0;
                flag = 1;
                break;
            }
            else if (i == 14) {
                p->getsprite().setPosition(900, 590);
                a = 0;
                b = -1;
                flag = 1;
                break;
            }
            else if (i == 17) {
                p->getsprite().setPosition(770, 370);
                a = -1;
                b = 0;
                flag = 1;
                break;
            }
            else if (i == 20) {
                p->getsprite().setPosition(380,410);
                a = 0;
                b = 1;
                flag = 1;
                break;
            }
            else if (i == 18) {
                p->getsprite().setPosition(420, 515);
                a = 1;
                b = 0;
                flag = 1;
                break;
            }
            else if (i == 22) {
                p->getsprite().setPosition(810, 480);
                a = 0;
                b = -1;
                flag = 1;
                break;
            }
        }
    }
    if(flag==1)
        p->getsprite().rotate(-90);
    if (check == 0)
        pmove(p, a, b);
}
void carpathR(Enemy*& e, int& path, int& carpath) {
    int a = e->getsprite().getPosition().x;
    int b = e->getsprite().getPosition().y;
    if ((b >= 360 && b <= 500) && (path==5||path==1)) {
        if (a > 50 && a < 110) {
            e->getsprite().setPosition(190, b);
            carpath = 1;
        }
        else if (a > 1000 && a < 1150) {
            e->getsprite().setPosition(1000, b);
            carpath = 5;
        }
    }
    else if ((b >= 360 && b <= 500) && (path == 2 || path == 4)) {
        if (a > 180 && a < 290) {
            e->getsprite().setPosition(290, b);
            carpath = 4;
        }
        if (a > 930 && a < 1040) {
            e->getsprite().setPosition(900, b);
            carpath = 2;
        }
        
    }
}
class Game
{
    Player* player;
    Enemy* enemy;
   // int score;
public:
    int score = 0;
    int check = 0;
    int path = 0;
    Text text[4];
    Text dis[3];
    Text t[3];
    Font font;
    int option = 0;
    Sprite background; // Game background sprite
    Texture bg_texture;
    Box smallBoxes[numSmallBoxes]; // Declare the array here

    Game()
    {
        player = new Player;
        enemy = new Enemy;
        //score = 0;
        bg_texture.loadFromFile("img/background.jpg");
        background.setTexture(bg_texture);
        background.setScale(2, 2);
        initializeSmallBoxes();
    }

    void initializeSmallBoxes()
    {
        // Add code here to initialize small boxes as needed
        smallBoxes[0] = Box(1050.f, 130.f, 20.f, 260.f); // Initial direction is 1 (right)
        smallBoxes[1] = Box(1050.f, 500.f, 20.f, 260.f); // Initial direction is -1 (left)
        //smallBoxes[1].shape.setOutlineThickness(10);
        smallBoxes[2] = Box(120.f, 130.f, 20.f, 260.f);
        smallBoxes[3] = Box(120.f, 500.f, 20.f, 260.f);
        smallBoxes[4] = Box(120.f, 130.f, 400.f, 20.f);
        smallBoxes[5] = Box(650.f, 130.f, 400.f, 20.f);
        smallBoxes[6] = Box(120.f, 760.f, 400.f, 20.f);
        smallBoxes[7] = Box(650.f, 760.f, 420.f, 20.f);
        smallBoxes[8] = Box(220.f, 220.f, 300.f, 20.f);
        smallBoxes[9] = Box(650.f, 220.f, 300.f, 20.f);
        smallBoxes[10] = Box(220.f, 220.f, 20.f, 170.f);
        smallBoxes[11] = Box(220.f, 500.f, 20.f, 170.f);
        smallBoxes[12] = Box(650.f, 670.f, 320.f, 20.f);
        smallBoxes[13] = Box(220.f, 670.f, 300.f, 20.f);
        smallBoxes[14] = Box(950.f, 500.f, 20.f, 170.f);
        smallBoxes[15] = Box(950.f, 220.f, 20.f, 170.f);
        smallBoxes[16] = Box(320.f, 310.f, 200.f, 20.f);
        smallBoxes[17] = Box(650.f, 310.f, 200.f, 20.f);
        smallBoxes[18] = Box(320.f, 560.f, 200.f, 20.f);
        smallBoxes[19] = Box(650.f, 560.f, 200.f, 20.f);
        smallBoxes[20] = Box(320.f, 310.f, 20.f, 80.f);
        smallBoxes[21] = Box(850.f, 310.f, 20.f, 80.f);
        smallBoxes[22] = Box(850.f, 500.f, 20.f, 80.f);
        smallBoxes[23] = Box(320.f, 500.f, 20.f, 80.f);
        smallBoxes[24] = Box(20.f, 40.f, 500.f, 20.f);
        smallBoxes[25] = Box(650.f, 40.f, 500.f, 20.f);
        smallBoxes[26] = Box(20.f, 850.f, 500.f, 20.f);
        smallBoxes[27] = Box(650.f, 850.f, 520.f, 20.f);
        smallBoxes[28] = Box(20.f, 40.f, 20.f, 350.f);
        smallBoxes[29] = Box(1150.f, 40.f, 20.f, 350.f);
        smallBoxes[30] = Box(20.f, 500.f, 20.f, 350.f);
        smallBoxes[31] = Box(1150.f, 500.f, 20.f, 350.f);
    }
    void InitialMenu() {
        if (!font.loadFromFile("\OpenSans-BoldItalic.ttf")) {
            cout << "Error Loading File" << endl;
        }
        else {
            text[0].setFont(font);
            text[0].setFillColor(Color::Red);
            text[0].setString("Resume Game");
            text[0].setCharacterSize(80);
            text[0].setPosition(400, 100);

            text[1].setFont(font);
            text[1].setFillColor(Color::White);
            text[1].setString("High Score");
            text[1].setCharacterSize(60);
            text[1].setPosition(400, 250);

            text[2].setFont(font);
            text[2].setFillColor(Color::White);
            text[2].setString("Help");
            text[2].setCharacterSize(60);
            text[2].setPosition(400, 400);

            text[3].setFont(font);
            text[3].setFillColor(Color::White);
            text[3].setString("Exit");
            text[3].setCharacterSize(60);
            text[3].setPosition(400, 550);

        }
    }
    void Showscreen() {
        if (!font.loadFromFile("\OpenSans-BoldItalic.ttf")) {
            cout << "Error Loading File" << endl;
        }
        else {
            text[0].setFont(font);
            text[0].setFillColor(Color::White);
            text[0].setString("Score: ");
            text[0].setCharacterSize(35);
            text[0].setPosition(100, 870);

            text[1].setFont(font);
            text[1].setFillColor(Color::White);
            text[1].setString("Lives: ");
            text[1].setCharacterSize(35);
            text[1].setPosition(400, 870);

            text[2].setFont(font);
            text[2].setFillColor(Color::White);
            text[2].setString("High Score: ");
            text[2].setCharacterSize(35);
            text[2].setPosition(700, 870);
        }
    }
    void Showscore(RenderWindow& window) {
        for (int i = 0; i < 3; i++) {
            window.draw(text[i]);
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
    void PauseMenu(RenderWindow& window) {
        for (int i = 0; i < 4; i++) {
            window.draw(text[i]);
        }
    }
    bool checklives() {
        
        if (player->getsprite().getGlobalBounds().intersects(enemy->getsprite().getGlobalBounds())) {
            return 1;
        }
        return 0;
    }
    void displaysct(RenderWindow& window,int a,int s,int high) {
        
        if (!font.loadFromFile("\OpenSans-BoldItalic.ttf")) {
            cout << "Y";
        }
        t[0].setFont(font);
        t[0].setString(to_string(a));
        t[0].setPosition(500, 870);
        t[0].setCharacterSize(32);
        t[0].setFillColor(Color::Green);

        t[1].setFont(font);
        t[1].setString(to_string(s));
        t[1].setPosition(230, 870);
        t[1].setCharacterSize(32);
        t[1].setFillColor(Color::Green);

        ifstream file("high.txt");
        if (!file.is_open()) {
            cerr << "Unable to open file!" << std::endl;
        }
        string line[100];
        int D = 0;
        while (getline(file, line[D]))
        {
            if (D == 0)
                high = stoi(line[D]);
            //cout << endl << line[D];
            D++;
        }
        file.close();
        if (score > high) {
            ofstream file1("high.txt", std::ios::trunc);
            if (!file1.is_open()) {
                cerr << "Unable to open file!" << std::endl;
            }

            string newContent = to_string(score);
            newContent += "\n";

            int i = 0;
            while (i<4)
            {
                file1 << newContent[i];
                i++;
            }
            file.close();
            high = score;
        }

        t[2].setFont(font);
        t[2].setString(to_string(high));
        t[2].setPosition(1000, 870);
        t[2].setCharacterSize(32);
        t[2].setFillColor(Color::Green);

        window.draw(t[0]);
        window.draw(t[1]);
        window.draw(t[2]);
    }
    void callhigh(int a) {

    }
    void start_game()
    {
        srand(time(0));
        RenderWindow window(VideoMode(1200, 1000), title);
        Clock clock;
        Clock clock2,clock3,clock4,clock5;
        float timer = 0;
        Texture tex;
        Sprite sp;
        int path2 = 0;
        int carp = 0;
        Time cool = seconds(0.5);
        bool lasttime = 0;
        bool lasttime1 = 0;
        bool lasttime2 = 0;
        bool lasttime3 = 0;
        bool lasttime4 = 0;
        int high = 0;
        Music music;
        Circle cr[4] = { {"img\\circle1.png", 50, 68},{"img\\circle1.png", 1080, 68} ,{"img\\circle1.png", 50, 780},{"img\\circle1.png", 1080, 780} };
        Hexagon hx[2] = { {"img\\haxagon1.png", 25, 250},{"img\\haxagon1.png", 1057, 250} };
        Rectangle rec[2] = { {"img\\rrect1.png", 45, 560},{"img\\rrect1.png", 1075, 560} };
        Triangle tri[4] = { {"img\\triangle1.png", 355, 790},{"img\\triangle1.png", 355, 68},{"img\\triangle1.png", 755, 790},{"img\\triangle1.png", 755, 68} };
        if (!music.openFromFile("Song2.ogg")) {
            cout << "No music" << endl;
        }
        music.play();
        while (window.isOpen())
        {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;

            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                    window.close();

            }
            if (Keyboard::isKeyPressed(Keyboard::P)) {
                RenderWindow pause(VideoMode(1200, 1000), "Pause scren");
                InitialMenu();
                while (pause.isOpen()) {
                    Event p;
                    while (pause.pollEvent(p))
                    {
                        if (p.type == Event::Closed)
                        {
                            pause.close();
                            window.close();
                        }
                    }
                    if (Keyboard::isKeyPressed(Keyboard::R)) {
                        cout << "open" << endl;
                        pause.close();
                    }
                    pause.clear(Color::Black);
                    pause.draw(background);
                    PauseMenu(pause);
                    pause.display();
                }

            }
            lasttime = 0;
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                // Check if the left key was not pressed in the previous frame
                if (!lasttime) {
                    // Check if enough time has passed since the last execution
                    if (clock.getElapsedTime() <= cool) {
                        if (player->getsprite().getPosition().x == 1090) {
                            path = 0;
                        }
                        else if (player->getsprite().getPosition().x == 1000) {
                            path = 1;
                        }
                        else if (player->getsprite().getPosition().x == 900) {
                            path = 2;
                        }
                        else if (player->getsprite().getPosition().x == 380) {
                            path = 3;
                        }
                        else if (player->getsprite().getPosition().x == 290) {
                            path = 4;
                        }
                        else if (player->getsprite().getPosition().x == 190) {
                            path = 5;
                        }
                        else if (player->getsprite().getPosition().x == 100) {
                            path = 6;
                        }
                        int a = player->getsprite().getPosition().x;
                        if (a == 1090 || a == 1000 || a == 900 || a == 380 || a == 290 || a == 190)
                            LeftKey(player, player->getsprite().getPosition().y, player->getsprite().getPosition().x, path);
                        // Reset the timer
                        clock.restart();
                    }
                }

                // Set the flag to true to indicate that the left key is currently pressed
                lasttime = true;
            }
            else {
                // Reset the flag when the left key is not pressed
                lasttime = false;
            }
            lasttime1 = 0;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                // Check if the left key was not pressed in the previous frame
                if (!lasttime1) {
                    // Check if enough time has passed since the last execution
                    if (clock2.getElapsedTime() >= cool) {
                        // Your code to be executed once when the left key is pressed
                        if (player->getsprite().getPosition().x == 100) {
                            path = 6;
                        }
                        else if (player->getsprite().getPosition().x == 190) {
                            path = 5;
                        }
                        else if (player->getsprite().getPosition().x == 290) {
                            path = 4;
                        }
                        else if (player->getsprite().getPosition().x == 810) {
                            path = 3;
                        }
                        else if (player->getsprite().getPosition().x == 900) {
                            path = 2;
                        }
                        else if (player->getsprite().getPosition().x == 1000) {
                            path = 1;
                        }
                        else if (player->getsprite().getPosition().x == 1090) {
                            path = 0;
                        }
                        int a = player->getsprite().getPosition().x;
                            RightKey(player, player->getsprite().getPosition().y, a, path);
                        // Reset the timer
                        clock2.restart();
                    }
                }

                // Set the flag to true to indicate that the left key is currently pressed
                lasttime1 = true;
            }
            else {
                // Reset the flag when the left key is not pressed
                lasttime1 = false;
            }
            if (Keyboard::isKeyPressed(Keyboard::Up)) {
                if (!lasttime2) {
                    if (clock3.getElapsedTime() >= cool) {
                        cout << "Y: " << player->getsprite().getPosition().y;
                        upKey(player, player->getsprite().getPosition().x, player->getsprite().getPosition().y, path2);
                        clock3.restart();
                    }
                }
                lasttime2 = true;
            }
            else {
                lasttime2 = false;
            }
            if (Keyboard::isKeyPressed(Keyboard::Down)) {
                if (!lasttime3) {
                    if (clock4.getElapsedTime() >= cool) {
                        cout << "Y: " << player->getsprite().getPosition().y << endl;
                        DownKey(player, player->getsprite().getPosition().x, player->getsprite().getPosition().y, path2);
                        clock4.restart();
                    }

                }

                lasttime3 = true;
            }
            else {
                lasttime3 = false;
            }
            if (!lasttime3) {
                if (checklives()) {
                    if (clock5.getElapsedTime() >= cool) {
                        player->setl(player->getlive() - 1);
                        clock5.restart();
                    }
                }
                lasttime = 1;
            }
            else {
                lasttime = 0;
            }
            Scorerec(player, rec, score);
            Scorehex(player, hx, score);
            Scoretri(player, tri, score);
            Scorecr(player, cr, score);
            carpathR(enemy, path, carp);
            window.clear(Color::Black);
            window.draw(background);
            //window.draw(background);
            // Move and draw small boxes
            for (int i = 0; i < 32; i++) {
                window.draw(smallBoxes[i].shape);
            }
            checkpMovement(player, smallBoxes);
            checkeMovement(enemy, smallBoxes);

            window.draw(enemy->getsprite());
            window.draw(player->getsprite());
            
            DrawCircle(cr, window);
            DrawHex(hx, window);
            DrawRec(rec, window);
            DrawTriangle(tri, window);
            Showscreen();
            Showscore(window);
            displaysct(window,player->getlive(),score,high);
            if (player->getlive() == 0) {
                RenderWindow over(VideoMode(1200, 1000), title);
                Texture t;
                Sprite s;
                t.loadFromFile("img/game.jpg");
                s.setTexture(t);
                s.setScale(2.5, 1.0);
                while (over.isOpen())
                {
                    music.stop();
                    window.close();
                    Event e;
                    while (over.pollEvent(e))
                    {
                        if (e.type == Event::Closed) {
                            window.close();
                            over.close();
                        }
                    }
                    over.clear(Color::Black);
                    over.draw(s);
                    over.display();
                }
            }
            window.display();
        }
    }
};
#endif // !game_h