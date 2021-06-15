#define _PTWE

#ifdef _PTWE

#include"libOne.h"
class ENEMY {
protected:
    int Img = 0;
    float Px = 0, Py = 0, Vx = 0;
public:
    void setImage(int img) {
        Img = img;
    }

    void init() {
        Px = random() % (int)width;
        Py = random() % (int)height;
        Vx = random() % (int)5 + 1.0f;
    }
    virtual void move() {
        Px += Vx;
    }

    void draw() {
        image(Img, Px, Py);
    }

};
void gmain() {
    window(1920, 1080, full);
    hideCursor();

    int enemyImg = loadImage("assets\\enemy.png");

    int num = 50;
    ENEMY* enemy = new ENEMY[num];

    for (int i = 0; i < num; i++) {
        enemy[i].setImage(enemyImg);
        enemy[i].init();
    }

    while (notQuit) {
        clear();
        for (int i = 0; i < num; i++) {
            enemy[i].move();
            enemy[i].draw();
        }
    }
    delete[] enemy;
}
#endif

#ifdef _PONE

#include"libOne.h"

class CHARACTER {
protected:
    int Img = 0;
    float Px = 0, Py = 0, Angle = 0;
    float Vx = 0, Vy = 0, AngSpeed = 0;

public:
    void setImage(int img) {
        Img = img;
    }

    void init() {
        Px = width / 2;
        Py = height / 2;
        Angle = 0;
        Vx = 1;
        Vy = 1;
        AngSpeed = 0.01f;
    }

    virtual void move() {
        Angle += AngSpeed;
    }

    void draw() {
        rectMode(CENTER);
        image(Img, Px, Py, Angle);
    }

};
//派生クラス　プレイヤー
class PLAYER :public CHARACTER {
public:
    void move() {
        Px += Vx;
    }
};
//派生クラス　エネミー
class ENEMY :public CHARACTER {
public:
    void move() {
        Py += Vy;
    }
};

class ENEMY_BULLET :public CHARACTER {
};

void gmain() {
    window(1920, 1080, full);
    //画像用意
    int playerImg = loadImage("assets\\player.png");
    int enemyImg = loadImage("assets\\enemy.png");
    int enemyBulletImg = loadImage("assets\\eBullet.png");

    //データ用意
    PLAYER player;
    ENEMY enemy;
    ENEMY_BULLET eBullet;

    player.setImage(playerImg);
    enemy.setImage(enemyImg);
    eBullet.setImage(enemyBulletImg);

    //アドレスを渡す 基底＜ー派生
    const int num = 3;
    CHARACTER* chara[num];
    chara[0] = &player;
    chara[1] = &enemy;
    chara[2] = &eBullet;

    for (int i = 0; i < num; i++) {
        chara[i]->init();
    }

    while (notQuit) {
        for (int i = 0; i < num; i++) {
            chara[i]->move();
        }
        clear();
        for (int i = 0; i < num; i++) {
            chara[i]->draw();
        }
    }
}
#endif

