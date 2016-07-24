#include<iostream>
#include<SFML/Graphics.hpp>
#include<stdlib.h>
#include<time.h>


using namespace std;
using namespace sf;



class plane{
public:
  int bulx=0,buly=0,planex=20,planey=150;

  void plane_pos(int x,int y){
  bulx=x+43,buly=y+23;
   planex=x,planey=y;
  }

};

class enemy{

public:
    int enemy_x=0,enemy_y=0;

    void en_pos(int x,int y){
    enemy_x=x,enemy_y=y;
    }

bool check_enemy();

};


///this function is checking that whether my bullet hit enemy or not.....
bool check_enemy(int x,int y,enemy ob)
{
    int z=0;

    if(x>=ob.enemy_x){
        if(y>=ob.enemy_y-10&&y<=ob.enemy_y+30){
      z=1;
        }
    }
    if(z==1)
    {
        return true;
    }
    else
     return false;

}


bool check_myplane(int x,int y,plane ob)
{
   int z=0;

    if(x<=ob.planex+50){
        if(y>=ob.planey&&y<=ob.planey+45){
      z=1;
        }
    }
    if(z==1)
    {
        return true;
    }
    else
     return false;



}



int main(){
   int bul_control=1,bul_barral1_start=0,bul_barral1_end=-1,bul_barral2_start=0,bul_barral2_end=-1,start=0;
   int enemy_control_start=1,enemy_loop_start=0,enbul_start=0,enbul_barral1_start=0,enbul_barral1_end=-1,enbul_barral2_start=0,enbul_barral2_end=-1;
   int enbarral=1;
   int my_bullet_pos[50][50];
    plane ob;
    enemy ob1;


   srand(time(NULL));


RectangleShape back(Vector2f(700,700));
back.setFillColor(Color::Cyan);
RectangleShape starts(Vector2f(700,700));
starts.setFillColor(Color::Green);



Texture texplane;
RectangleShape plane(Vector2f(80,50));
plane.setPosition(30,100);
texplane.loadFromFile("plane.jpg");
plane.setTexture(&texplane);


Texture texplosion;
texplosion.loadFromFile("explosion.jpg");
CircleShape explosion;
explosion.setRadius(30);
explosion.setPosition(-100,-100);
explosion.setTexture(&texplosion);



Texture winners;
RectangleShape winner(Vector2f(300,300));
winner.setPosition(200,200);
winners.loadFromFile("winner.jpg");
winner.setTexture(&winners);


Texture lose;
RectangleShape loses(Vector2f(400,400));
loses.setPosition(150,150);
lose.loadFromFile("lose.jpg");
loses.setTexture(&lose);









RectangleShape enemyscore[20];
int k,enscore=0,timedelay=0;
enemyscore[0].setSize(Vector2f(100,20));
enemyscore[0].setFillColor(Color::Green);

enemyscore[0].setPosition(590,10);
enemyscore[0].setOutlineColor(Color::Black);
enemyscore[0].setOutlineThickness(1);
for(k=1;k<=19;k++){
    enemyscore[k].setSize(Vector2f((k*5.2),18));
    enemyscore[k].setFillColor(Color::Red);
    enemyscore[k].setPosition(-100,-100);
}



RectangleShape myscore[20];
int miscore=0;
myscore[0].setSize(Vector2f(100,20));
myscore[0].setFillColor(Color::Green);

myscore[0].setPosition(12,10);
myscore[0].setOutlineColor(Color::Black);
myscore[0].setOutlineThickness(1);
for(k=1;k<=19;k++){
    myscore[k].setSize(Vector2f((k*5.2),18));
    myscore[k].setFillColor(Color::Red);
    myscore[k].setPosition(-100,-100);
}







RectangleShape bulet[50];

for(int x=0;x<50;x++){
    bulet[x].setSize(Vector2f(10,4));
    bulet[x].setFillColor(Color::Red);

}



RectangleShape enemy[6];


for(int x=0;x<=5;x++){
     enemy[x].setSize(Vector2f(90,50));

}
Texture enemi;
enemi.loadFromFile("enemy.jpg");
enemy[1].setTexture(&enemi);

RectangleShape enbul[30];
for(int x=0;x<=29;x++){
  enbul[x].setSize(Vector2f(6,3));
  enbul[x].setFillColor(Color::Red);

}

Font font;
        font.loadFromFile("black.ttf");
Text startf;
        startf.setFont(font);
        startf.setColor(Color::Black);
        startf.setPosition(100,250);
        startf.setString("Prees any Key to start");
        startf.setCharacterSize(45);



RenderWindow window(VideoMode(700,630),"Air StrikeV0.4");
Event event;



while(window.isOpen()){














    if(start==0){
    window.draw(starts);
    window.draw(startf);
    }



if(start==3){

    if(miscore<enscore){
        window.draw(winner);
    }
    else
        window.draw(loses);
}



if(start==1){

     window.draw(back);

    window.draw(myscore[0]);
    window.draw(enemyscore[0]);
    window.draw(enemyscore[enscore]);
    window.draw(myscore[miscore]);

    Vector2f planepos=plane.getPosition();
    ob.plane_pos(planepos.x,planepos.y);


    Vector2f bulpose;
     window.draw(plane);


///...my plane bullet control area.......///
///.............................///


 for(int x=bul_barral1_start;x<=bul_barral1_end;x++){


    window.draw(bulet[x]);
    bulet[x].move(14,0);
    bulpose=bulet[x].getPosition();

    //cout<<"\n bulpose.x= "<<bulpose.x<<endl;
     my_bullet_pos[x][0]=bulpose.x;
     my_bullet_pos[x][1]=bulpose.y;
    bool m=check_enemy(bulpose.x,bulpose.y-16,ob1);
    if(bulpose.x>=700||m){
            if(m){
                timedelay++;
                    if(timedelay==3){
                        enscore++;
                        timedelay=0;
                    }
                explosion.setPosition(ob1.enemy_x,ob1.enemy_y+0);

            }
            bulet[x].setPosition(1000,1000);
            bul_barral1_start++;
            if(bul_barral1_start>bul_barral1_end)
             {
               bul_barral1_end=-1;
               bul_barral1_start=0;
             }
          }

       }


 for(int x=bul_barral2_start;x<=bul_barral2_end;x++){


    window.draw(bulet[x]);
    bulet[x].move(14,0);
    bulpose=bulet[x].getPosition();
   /// cout<<"\n bulpose.x= "<<bulpose.x<<endl;
    my_bullet_pos[x+10][0]=bulpose.x;
    my_bullet_pos[x+10][1]=bulpose.y;

bool m=check_enemy(bulpose.x,bulpose.y-16,ob1);
  if(m==true)
    cout<<"hi everyone...............<<"<<endl;


    if(bulpose.x>=700||m==true){
             if(m){
                    timedelay++;
                    if(timedelay==3){
                        enscore++;
                        timedelay=0;
                    }
                explosion.setPosition(ob1.enemy_x,ob1.enemy_y+0);

            }
            bulet[x].setPosition(1000,1000);
            bul_barral2_start++;
            if(bul_barral2_start>bul_barral2_end)
             {
               bul_barral2_end=-1;
               bul_barral2_start=0;
             }
          }
       }
        if(enscore>=19){
            enscore=19;
            enemyscore[19].setPosition(592,11);
            start=3;
        }
        if(enscore>0&&enscore<19){

        enemyscore[enscore].setPosition((594+(19-enscore)*5),11);
        }
///......my plane bullet control area end here.....///
///../////////////////////////////////////..//










///....enemy control area....////
///..........................////



if(enemy_control_start==1){


int y=rand()%10;
if(y%2!=0){
   enemy[1].setPosition(750,y*40);
   enemy_loop_start=1;
   enemy_control_start=0;
  }
}

Vector2f enpos;

if(enemy_loop_start==1){
    enpos=enemy[1].getPosition();
    ob1.en_pos(enpos.x,enpos.y);
 //cout<<"enpose is ...= "<<enpos.x<<endl;
      if(enpos.x<=600){
            //cout<<"enpos y is ....== "<<enpos.y<<endl;
            //cout<<"ob.planey is= "<<ob.planey<<endl;
         if(enpos.y>=ob.planey-5&&enpos.y<=ob.planey+5){
           //cout<<"i am here"<<endl;
          enbul_start=1;


        }

         else
         {
            if(enpos.y<ob.planey){
             enemy[1].move(0,2);
           }

            else if(enpos.y>ob.planey){
             enemy[1].move(0,-2);

           }
        enbul_start=0;
         }
      }
 else
 {
     enemy[1].move(-5,0);
 }

   window.draw(enemy[1]);
   window.draw(explosion);

   explosion.setPosition(-100,-100);
}

///...enemy bullet control area....///
Vector2f enbul_pose;
//cout<<"enbul_start......=  "<<enbul_start<<endl;
if(enbul_start==1){


  int y=rand()%20;
  if(y==12){
    if(enbarral==1)
    {
        enbul_barral1_end++;
        enbul[enbul_barral1_end].setPosition(ob1.enemy_x,ob1.enemy_y+25);
        if(enbul_barral1_end==29)
        {
            enbarral=2;
        }
    }

    else if(enbarral==2)
    {
        enbul_barral2_end++;
        enbul[enbul_barral2_end].setPosition(ob1.enemy_x,ob1.enemy_y+25);
        if(enbul_barral2_end==29){
            enbarral=1;
        }
    }



  }
}
  for(int x=enbul_barral1_start;x<=enbul_barral1_end;x++){
          enbul_pose=enbul[x].getPosition();
         bool m=check_myplane(enbul_pose.x,enbul_pose.y,ob);
          if(enbul_pose.x<=10||m){
                if(m){
                        miscore++;
                    explosion.setPosition(ob.planex+18,ob.planey);
                    window.draw(explosion);
                    explosion.setPosition(-100,-100);
                }
            enbul_barral1_start++;

          }

           else
            enbul[x].move(-12,0);
         for(int z=0;z<=20;z++){
            if(enbul_pose.x==my_bullet_pos[z][0]){
                    cout<<"i am in x so the main"<<endl;
                if(enbul_pose.y>=my_bullet_pos[z][1]+10&&enbul_pose.y<=my_bullet_pos[z][1]-10){

                }
            }
         }

          if(enbul_barral1_start==29){
            enbul_barral1_start=0;
            enbul_barral1_end=-1;

          }

          window.draw(enbul[x]);
  }






for(int x=enbul_barral2_start;x<=enbul_barral2_end;x++){
          enbul_pose=enbul[x].getPosition();
           bool m=check_myplane(enbul_pose.x,enbul_pose.y,ob);
          if(enbul_pose.x<=10||m){
                 if(m){
                        miscore++;
                    explosion.setPosition(ob.planex+18,ob.planey);
                    window.draw(explosion);
                    explosion.setPosition(-100,-100);
                }
            enbul_barral2_start++;

          }
           else
            enbul[x].move(-12,0);

for(int z=0;z<=20;z++){

            if(enbul_pose.x==my_bullet_pos[z][0]){
                    cout<<"i am in x so the main"<<endl;
                if(enbul_pose.y>=my_bullet_pos[z][1]+10&&enbul_pose.y<=my_bullet_pos[z][1]-10){

                }
            }
         }
          if(enbul_barral2_start==29){
            enbul_barral2_start=0;
            enbul_barral2_end=-1;
          }


          window.draw(enbul[x]);
  }


 if(miscore>=19){
            miscore=19;
            myscore[19].setPosition(13,11);
            start=3;
        }
        if(miscore>0&&miscore<19){

        myscore[miscore].setPosition((16+(19-miscore)*5),11);
        }








///...enemy bullet control area end here....///


///.........enemy control area end here........///
///.//////////////////////////////////////////.///




}





while(window.pollEvent(event)){
    if(event.type==Event::Closed){
        window.close();
    }
    if(start==0){
       if((Keyboard::isKeyPressed(Keyboard::Up))||(Keyboard::isKeyPressed(Keyboard::Down))||(Keyboard::isKeyPressed(Keyboard::Right))||(Keyboard::isKeyPressed(Keyboard::Left))){
        start=1;;

       }

    }
    if(start==1){
    if(Keyboard::isKeyPressed(Keyboard::Up)){
            if(ob.planey<=40){
               plane.setPosition(ob.planex,40);
            }
            else
           plane.setPosition(ob.planex,ob.planey-5);





    }

    if(Keyboard::isKeyPressed(Keyboard::Down)){
            if(ob.planey>=400){
                plane.setPosition(ob.planex,400);
            }
            else
                plane.setPosition(ob.planex,ob.planey+20);

    }

    if(Keyboard::isKeyPressed(Keyboard::Right)){
        if(ob.planex>=300){
            plane.setPosition(300,ob.planey);
        }
        else
            plane.setPosition(ob.planex+7,ob.planey);




    }

    if(Keyboard::isKeyPressed(Keyboard::Left)){
        if(ob.planex<=10){
            plane.setPosition(10,ob.planey);
        }
        else
            plane.setPosition(ob.planex-10,ob.planey);

    }





    Vector2f planepos=plane.getPosition();
    ob.plane_pos(planepos.x,planepos.y);


    Vector2f bulpose;
///...........my plane bullet control area........
     if(Keyboard::isKeyPressed(Keyboard::Right)){

       if(bul_control==1){

          bul_barral1_end++;
          bulet[bul_barral1_end].setPosition(ob.planex+50,ob.planey+25);

          if(bul_barral1_end>=11){
            bul_control=2;

          }
        }

      if(bul_control==2){

          bul_barral2_end++;
          bulet[bul_barral2_end].setPosition(ob.planex+50,ob.planey+25);

          if(bul_barral2_end>=11){
            bul_control=1;
          }
        }
      }




    }


   }
 window.display();

 }
 return 0;
}
