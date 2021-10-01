#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
GLfloat cloudxoffset=0,sunyoffset=0,birdxoffset=0,muyoffset=0;
GLint cloudstatus=0,sunstatus=0,birdstatus=0,moveupstatus=0,flag=0;

void circle(GLfloat originx,GLfloat originy ,GLfloat radius)
{
    GLfloat prevVertexx=originx;
    GLfloat prevVertexy=originy+radius;
    for(GLfloat i=0;i<360;i+=0.015)
    {
        GLfloat vertexx=radius*sin(i);
        GLfloat vertexy=radius*cos(i);
        glBegin(GL_TRIANGLES);
        glVertex2f(originx,originy);
        glVertex2f(prevVertexx,prevVertexy);
        glVertex2f(vertexx,vertexy);
        glEnd();
        prevVertexx=vertexx;
        prevVertexy=vertexy;
    }
}
void tree(GLfloat x, GLfloat y)
{
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(x-0.05,y);
    glVertex2f(x-0.05,y+0.075);
    glVertex2f(x+0.05,y+0.075);
    glVertex2f(x+0.05,y);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0,0.6,0.1);
    glVertex2f(x-0.3,y+0.075);
    glVertex2f(x+0.3,y+0.075);
    glVertex2f(x,y+0.425);

    glVertex2f(x-0.25,y+0.225);
    glVertex2f(x+0.25,y+0.225);
    glVertex2f(x,y+0.475);

    glVertex2f(x-0.2,y+0.325);
    glVertex2f(x+0.2,y+0.325);
    glVertex2f(x,y+0.575);

    glVertex2f(x-0.15,y+0.425);
    glVertex2f(x+0.15,y+0.425);
    glVertex2f(x,y+0.625);

    glVertex2f(x-0.1,y+0.525);
    glVertex2f(x+0.1,y+0.525);
    glVertex2f(x,y+0.675);

    glVertex2f(x-0.05,y+0.625);
    glVertex2f(x+0.05,y+0.625);
    glVertex2f(x,y+0.725);

    glEnd();
}
void sun()
{
    glPushMatrix();
    glTranslatef(-0.7,0.8,0);
    glColor3ub(255,165,0);
    circle(0,0,0.115);
    glPopMatrix();

}
void bird(GLfloat,GLfloat);
void bird2(GLfloat,GLfloat);
void movebird()
{
    if(birdstatus==1&&birdxoffset<=4)
    {
    birdxoffset=birdxoffset+0.03;
    glPushMatrix();
    glTranslatef(birdxoffset,0,0);
    glPushMatrix();
    glScalef(0.7,0.7,0);
    glTranslatef(0.5,0.4,0);
    bird(0,0.5);
     glPopMatrix();
     glPushMatrix();
    glScalef(0.9,0.9,0);
    glTranslatef(-1.3,0,0);
     bird(0,0.5);
     glPopMatrix();
     glPushMatrix();
    glScalef(0.7,0.7,0);
    glTranslatef(-2.0,0.4,0);
     bird(0,0.5);
     glPopMatrix();
    glPushMatrix();
    glScalef(0.55,0.55,0);
    glTranslatef(-1.85,0.4,0);
     bird2(0,0.5);
     glPopMatrix();
     //
     glPushMatrix();
     glTranslatef(-2,0,0);//
     glPushMatrix();
    glScalef(0.7,0.7,0);
    glTranslatef(0.5,0.4,0);
    bird(0,0.5);
     glPopMatrix();
     glPushMatrix();
    glScalef(0.9,0.9,0);
    glTranslatef(-1.3,0,0);
     bird(0,0.5);
     glPopMatrix();
     glPushMatrix();
    glScalef(0.7,0.7,0);
    glTranslatef(-2.0,0.4,0);
     bird(0,0.5);
     glPopMatrix();
    glPushMatrix();
    glScalef(0.55,0.55,0);
    glTranslatef(-1.85,0.4,0);
     bird2(0,0.5);
     glPopMatrix();
     glPopMatrix();
     glPushMatrix();
     glTranslatef(-3,0,0);//
     glPushMatrix();
    glScalef(0.7,0.7,0);
    glTranslatef(0.5,0.4,0);
    bird(0,0.5);
     glPopMatrix();
     glPushMatrix();
    glScalef(0.9,0.9,0);
    glTranslatef(-1.3,0,0);
     bird(0,0.5);
     glPopMatrix();
     glPushMatrix();
    glScalef(0.7,0.7,0);
    glTranslatef(-2.0,0.4,0);
     bird(0,0.5);
     glPopMatrix();
    glPushMatrix();
    glScalef(0.55,0.55,0);
    glTranslatef(-1.85,0.4,0);
     bird2(0,0.5);
     glPopMatrix();
     glPopMatrix();
     //
     glPopMatrix();
    }

}
void movesun()
{
    if(sunstatus==1&&sunyoffset<1.10)
    {
        sunyoffset=sunyoffset+0.015;
    }
    else
    {
        sunyoffset=sunyoffset;
    }
    glPushMatrix();
    glTranslatef(0,sunyoffset,0);
    glPushMatrix();
    glTranslatef(0,-1.1,0);
    sun();
    glPopMatrix();
    glPopMatrix();
}
void kite();
void kite2();
void moveup()
{
    if(moveupstatus==1&&flag==0)
    {
        if(muyoffset<=0.025)
        muyoffset=muyoffset+0.005;
        else
            {
                flag=1;
            }
    }
    if(moveupstatus==1&&flag==1)
    {
        if(muyoffset>=0.00)
        {
            muyoffset=muyoffset-0.005;
        }

        else
            {

                flag=0;
            }
    }

    glPushMatrix();
    glTranslatef(0,muyoffset,0);
    glPushMatrix();
    glScalef(0.35,0.35,0);
    glTranslatef(-0.4,1.7,0);
     kite();
     glPopMatrix();
     glPushMatrix();
    glScalef(0.3,0.3,0);
    glTranslatef(0.25,1.58,0);
     kite2();
     glPopMatrix();
    glPopMatrix();
    //moveupstatus=0;
}
void cloud(GLfloat originx, GLfloat originy)
{
    glPushMatrix();
    glTranslatef(originx+0.02,originy,0);
    circle(0,0,0.06);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(originx+0.05,originy,0);
    circle(0,0,0.05);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(originx+0.1,originy,0);
    circle(0,0,0.09);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(originx+0.2,originy,0);
    circle(0,0,0.09);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(originx+0.3,originy,0);
    circle(0,0,0.07);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(originx+0.3,originy,0);
    circle(0,0,0.04);
    glPopMatrix();


     glPushMatrix();
    glTranslatef(originx+0.1,originy,0);
    circle(0,0,0.1);
    glPopMatrix();


    //cloud2
     glPushMatrix();
    glTranslatef(originx+0.5,originy+0.12,0);
    circle(0,0,0.05);
    glPopMatrix();

     glPushMatrix();
    glTranslatef(originx+0.6,originy+0.12,0);
    circle(0,0,0.1);
    glPopMatrix();

     glPushMatrix();
    glTranslatef(originx+0.75,originy+0.12,0);
    circle(0,0,0.15);
    glPopMatrix();

     glPushMatrix();
    glTranslatef(originx+0.9,originy+0.12,0);
    circle(0,0,0.1);
    glPopMatrix();

    //cloud3
     glPushMatrix();
    glTranslatef(originx+1.12,originy,0);
    circle(0,0,0.07);
    glPopMatrix();

     glPushMatrix();
    glTranslatef(originx+1.20,originy,0);
    circle(0,0,0.05);
    glPopMatrix();

     glPushMatrix();
    glTranslatef(originx+1.25,originy,0);
    circle(0,0,0.1);
    glPopMatrix();

     glPushMatrix();
    glTranslatef(originx+1.35,originy,0);
    circle(0,0,0.05);
    glPopMatrix();

    //cloud4
    glPushMatrix();
    glTranslatef(originx+1.55,originy+0.15,0);
    circle(0,0,0.09);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(originx+1.65,originy+0.15,0);
    circle(0,0,0.06);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(originx+1.73,originy+0.15,0);
    circle(0,0,0.04);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(originx+1.47,originy+0.15,0);
    circle(0,0,0.05);
    glPopMatrix();

}
void grass()
{
    glPushMatrix();
    glScalef(0.25,0.25,0.0);
    glTranslatef(-1.4,-1.1,0.0);
    glBegin(GL_POLYGON);
    glColor3ub(0,128,0);
    glVertex2f(-0.7,-0.7);
    glVertex2f(-0.75,-0.65);
    glVertex2f(-0.69,-0.67);
    glVertex2f(-0.7,-0.6);
    glVertex2f(-0.65,-0.69);
    glVertex2f(-0.65,-0.55);
    glVertex2f(-0.6,-0.68);
    glVertex2f(-0.57,-0.64);
    glVertex2f(-0.6,-0.7);
    glEnd();
    glPopMatrix();

}
void gate()
{
    glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3ub(139,69,19);
    glVertex2f(-0.4,-0.39);
    glVertex2f(-0.4,-0.45);

    glVertex2f(-0.38,-0.39);
    glVertex2f(-0.38,-0.45);

    glVertex2f(-0.36,-0.39);
    glVertex2f(-0.36,-0.45);

    glVertex2f(-0.34,-0.39);
    glVertex2f(-0.34,-0.45);

    glVertex2f(-0.32,-0.39);
    glVertex2f(-0.32,-0.45);

    glVertex2f(-0.3,-0.39);
    glVertex2f(-0.3,-0.45);

    glVertex2f(-0.28,-0.39);
    glVertex2f(-0.28,-0.45);

    glVertex2f(-0.26,-0.39);
    glVertex2f(-0.26,-0.45);

    glVertex2f(-0.24,-0.39);
    glVertex2f(-0.24,-0.45);

    glVertex2f(-0.22,-0.39);
    glVertex2f(-0.22,-0.45);

    glVertex2f(-0.2,-0.39);
    glVertex2f(-0.2,-0.45);

    glVertex2f(-0.18,-0.39);
    glVertex2f(-0.18,-0.45);

    glVertex2f(-0.42,-0.425);
    glVertex2f(-0.17,-0.425);

    glVertex2f(0.245,-0.39);
    glVertex2f(0.245,-0.45);

    glVertex2f(0.265,-0.39);
    glVertex2f(0.265,-0.45);

    glVertex2f(0.285,-0.39);
    glVertex2f(0.285,-0.45);

    glVertex2f(0.305,-0.39);
    glVertex2f(0.305,-0.45);

    glVertex2f(0.325,-0.39);
    glVertex2f(0.325,-0.45);

    glVertex2f(0.345,-0.39);
    glVertex2f(0.345,-0.45);

    glVertex2f(0.345,-0.39);
    glVertex2f(0.345,-0.45);

    glVertex2f(0.365,-0.39);
    glVertex2f(0.365,-0.45);

    glVertex2f(0.385,-0.39);
    glVertex2f(0.385,-0.45);

    glVertex2f(0.405,-0.39);
    glVertex2f(0.405,-0.45);

    glVertex2f(0.425,-0.39);
    glVertex2f(0.425,-0.45);

    glVertex2f(0.445,-0.39);
    glVertex2f(0.445,-0.45);

    glVertex2f(0.465,-0.39);
    glVertex2f(0.465,-0.45);

    glVertex2f(0.485,-0.39);
    glVertex2f(0.485,-0.45);

    glVertex2f(0.505,-0.39);
    glVertex2f(0.505,-0.45);

    glVertex2f(0.525,-0.39);
    glVertex2f(0.525,-0.45);

    glVertex2f(0.545,-0.39);
    glVertex2f(0.545,-0.45);

     glVertex2f(0.565,-0.39);
    glVertex2f(0.565,-0.45);

     glVertex2f(0.585,-0.39);
    glVertex2f(0.585,-0.45);

     glVertex2f(0.605,-0.39);
    glVertex2f(0.605,-0.45);

     glVertex2f(0.625,-0.39);
    glVertex2f(0.625,-0.45);

     glVertex2f(0.645,-0.39);
    glVertex2f(0.645,-0.45);

     glVertex2f(0.665,-0.39);
    glVertex2f(0.665,-0.45);

     glVertex2f(0.685,-0.39);
    glVertex2f(0.685,-0.45);

     glVertex2f(0.705,-0.39);
    glVertex2f(0.705,-0.45);

     glVertex2f(0.725,-0.39);
    glVertex2f(0.725,-0.45);

     glVertex2f(0.238,-0.425);
    glVertex2f(0.729,-0.425);

     glVertex2f(-0.52,-0.39);
    glVertex2f(-0.52,-0.45);

    glVertex2f(-0.54,-0.39);
    glVertex2f(-0.54,-0.45);

    glVertex2f(-0.56,-0.39);
    glVertex2f(-0.56,-0.45);

    glVertex2f(-0.58,-0.39);
    glVertex2f(-0.58,-0.45);

    glVertex2f(-0.6,-0.39);
    glVertex2f(-0.6,-0.45);

    glVertex2f(-0.62,-0.39);
    glVertex2f(-0.62,-0.45);

    glVertex2f(-0.64,-0.39);
    glVertex2f(-0.64,-0.45);

    glVertex2f(-0.66,-0.39);
    glVertex2f(-0.66,-0.45);

    glVertex2f(-0.68,-0.39);
    glVertex2f(-0.68,-0.45);


    glVertex2f(-0.7,-0.39);
    glVertex2f(-0.7,-0.45);

    glVertex2f(-0.72,-0.39);
    glVertex2f(-0.72,-0.45);

    glVertex2f(-0.74,-0.39);
    glVertex2f(-0.74,-0.45);

    glVertex2f(-0.76,-0.425);
    glVertex2f(-0.50,-0.425);

    glEnd();
    glPopMatrix();
}

void women(GLfloat ox,GLfloat oy)
{




   glBegin(GL_QUADS);
   glColor3ub(0,0,128);
   glVertex2f(ox+0.18,oy-0.1);
   glVertex2f(ox-0.18,oy-0.1);//body
   glVertex2f(ox-0.1,oy-0.5);
   glVertex2f(ox+0.1,oy-0.5);
   glEnd();





  // glColor3ub(255,250,240);
   //glPushMatrix();
   //glTranslatef(ox,oy,0);
   //circle(0,0,0.1);//head
   //glPopMatrix();


    glBegin(GL_QUADS);
   glColor3ub(218,165,32);
   glVertex2f(ox-0.1,oy+0.1);
   glVertex2f(ox-0.06,oy+0.15);//hat
   glVertex2f(ox+0.06,oy+0.15);
   glVertex2f(ox+0.1,oy+0.1);
   glEnd();

    glBegin(GL_QUADS);
   glColor3ub(0,0,0);
   glVertex2f(ox+0.15,oy-0.9);//shoe
   glVertex2f(ox+0.05,oy-0.9);
   glVertex2f(ox+0.05,oy-0.95);
   glVertex2f(ox+0.15,oy-0.95);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(0,0,0);
   glVertex2f(ox-0.07,oy-0.95);
   glVertex2f(ox-0.07,oy-0.98);//shoe
   glVertex2f(ox-0.13,oy-0.98);
   glVertex2f(ox-0.13,oy-0.95);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(0,0,0);
   glVertex2f(ox+0.07,oy-0.95);
   glVertex2f(ox+0.07,oy-0.98);
   glVertex2f(ox+0.13,oy-0.98);//shoe
   glVertex2f(ox+0.13,oy-0.95);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(178,34,34);
   glVertex2f(ox-0.18,oy-0.1);
   glVertex2f(ox-0.32,oy-0.34);
   glVertex2f(ox-0.22,oy-0.3);
   glVertex2f(ox-0.16,oy-0.18);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(0,0,0);
   glVertex2f(ox-0.15,oy-0.9);
   glVertex2f(ox-0.05,oy-0.9);
   glVertex2f(ox-0.05,oy-0.95);
   glVertex2f(ox-0.15,oy-0.95);//shoe
   glEnd();





   glBegin(GL_QUADS);
   glColor3ub(178,34,34);
    glVertex2f(ox-0.1,oy-0.5);
   glVertex2f(ox+0.1,oy-0.5);//skirt
   glVertex2f(ox+0.27,oy-0.92);
   glVertex2f(ox-0.27,oy-0.92);
   glEnd();

    glBegin(GL_QUADS);
   glColor3ub(178,34,34);
   glVertex2f(ox+0.18,oy-0.1);
   glVertex2f(ox+0.32,oy-0.34);
   glVertex2f(ox+0.22,oy-0.3);
   glVertex2f(ox+0.16,oy-0.18);
   glEnd();





    glBegin(GL_QUADS);
   glColor3ub(0,0,0);
   glVertex2f(ox-0.08,oy+0.1);//hair
   glVertex2f(ox-0.2,oy-0.25);
   glVertex2f(ox+0.2,oy-0.25);
   glVertex2f(ox+0.08,oy+0.1);
   glEnd();

    glBegin(GL_QUADS);
   glColor3ub(184,134,11);
   glVertex2f(ox-0.14,oy+0.05);
   glVertex2f(ox-0.14,oy+0.1);//hat
   glVertex2f(ox+0.14,oy+0.1);
   glVertex2f(ox+0.14,oy+0.05);
   glEnd();



   //glBegin(GL_QUADS);
   //glColor3ub(32,178,170);
   //glVertex2f(ox-0.15,oy-0.8);
   //glVertex2f(ox-0.05,oy-0.8);//;leg
   //glVertex2f(ox-0.05,oy-0.9);
   //glVertex2f(ox-0.15,oy-0.9);
   //glEnd();

    glBegin(GL_QUADS);
   glColor3ub(255,182,193);
   glVertex2f(ox-0.1,oy-0.5);
   glVertex2f(ox+0.1,oy-0.5);
   glVertex2f(ox+0.12,oy-0.48);
   glVertex2f(ox-0.12,oy-0.48);
   glEnd();

    glBegin(GL_TRIANGLES);
   glColor3ub(255,182,193);
   glVertex2f(ox,oy-0.5);
   glVertex2f(ox-0.08,oy-0.63);
   glVertex2f(ox-0.03,oy-0.64);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(255,182,193);
   glVertex2f(ox,oy-0.5);
   glVertex2f(ox+0.08,oy-0.63);
   glVertex2f(ox+0.03,oy-0.64);
   glEnd();


   //glBegin(GL_QUADS);
   //glColor3ub(32,178,170);
   //glVertex2f(ox+0.15,oy-0.8);
   //glVertex2f(ox+0.05,oy-0.8);//leg
   //glVertex2f(ox+0.05,oy-0.9);
   //glVertex2f(ox+0.15,oy-0.9);
   //glEnd();





   glBegin(GL_QUADS);
   glColor3ub(178,34,34);
   glVertex2f(ox-0.12,oy-0.38);
   glVertex2f(ox-0.32,oy-0.34);
   glVertex2f(ox-0.22,oy-0.3);
   glVertex2f(ox-0.13,oy-0.34);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(178,34,34);
   glVertex2f(ox+0.12,oy-0.38);
   glVertex2f(ox+0.32,oy-0.34);
   glVertex2f(ox+0.22,oy-0.3);
   glVertex2f(ox+0.13,oy-0.34);
   glEnd();









}

void human(GLfloat ox,GLfloat oy)
{
glColor3f(0,0,0);
glPushMatrix();
glTranslatef(ox,oy,0);
 circle(0,0,0.1);
 glPopMatrix();

 glBegin(GL_QUADS);
 glColor3ub(72,61,139);
 glVertex2f(ox-0.14,oy+0.03);
 glVertex2f(ox-0.14,oy+0.1);
 glVertex2f(ox+0.14,oy+0.1);
 glVertex2f(ox+0.14,oy+0.03);
 glEnd();

  glBegin(GL_QUADS);
 glColor3ub(75,0,130);
 glVertex2f(ox-0.11,oy+0.1);
 glVertex2f(ox+0.11,oy+0.1);
 glVertex2f(ox+0.07,oy+0.15);
 glVertex2f(ox-0.07,oy+0.15);
 glEnd();

 glBegin(GL_QUADS);
 glColor3ub(47,79,79);
 glVertex2f(ox-0.2,oy-0.1);
 glVertex2f(ox+0.2,oy-0.1);//body
 glVertex2f(ox+0.1,oy-0.5);
 glVertex2f(ox-0.1,oy-0.5);
 glEnd();

 glBegin(GL_QUADS);
 glColor3ub(222,171,127);
 glVertex2f(ox-0.12,oy-0.4);
 glVertex2f(ox-0.18,oy-0.35);//left arm
 glVertex2f(ox-0.25,oy-0.4);
 glVertex2f(ox-0.11,oy-0.45);
 glEnd();

 glBegin(GL_QUADS);
 glColor3ub(105,105,105);
 glVertex2f(ox-0.2,oy-0.1);
 glVertex2f(ox-0.16,oy-0.24);//left hand
 glVertex2f(ox-0.18,oy-0.35);
 glVertex2f(ox-0.25,oy-0.4);

 glColor3ub(222,171,127);
 glVertex2f(ox+0.27,oy-0.4);
 glVertex2f(ox+0.2,oy-0.37);//right arm
 glVertex2f(ox+0.23,oy-0.14);
 glVertex2f(ox+0.26,oy-0.1);

 glColor3ub(105,105,105);
 glVertex2f(ox+0.2,oy-0.1);
 glVertex2f(ox+0.27,oy-0.4);//right hand
 glVertex2f(ox+0.2,oy-0.37);
 glVertex2f(ox+0.16,oy-0.24);
 glEnd();

 glBegin(GL_QUADS);
 glColor3ub(222,171,127);
 glEnd();

 glColor3f(1,0,0);
 glVertex2f(ox-0.1,oy-0.5);
 glVertex2f(ox+0.1,oy-0.5);
 glVertex2f(ox+0.09,oy-0.52);//belt
 glVertex2f(ox-0.09,oy-0.52);


 glBegin(GL_QUADS);
 glColor3ub(222,171,127);
 glVertex2f(ox-0.09,oy-0.52);
 glVertex2f(ox-0.2,oy-0.9);
 glVertex2f(ox-0.1,oy-0.9);//left leg
 glVertex2f(ox,oy-0.52);

 glVertex2f(ox+0.09,oy-0.52);
 glVertex2f(ox+0.2,oy-0.9);
 glVertex2f(ox+0.1,oy-0.9);//right leg
 glVertex2f(ox,oy-0.52);
 glEnd();


 glBegin(GL_QUADS);
 glColor3ub(105,105,105);
 glVertex2f(ox-0.09,oy-0.52);
 glVertex2f(ox,oy-0.52);
 glVertex2f(ox-0.05,oy-0.8);
 glVertex2f(ox-0.2,oy-0.8);
 glEnd();

 glBegin(GL_QUADS);
 glVertex2f(ox+0.09,oy-0.52);
 glVertex2f(ox,oy-0.52);
 glVertex2f(ox+0.05,oy-0.8);
 glVertex2f(ox+0.2,oy-0.8);
 glEnd();


 glBegin(GL_QUADS);
 glColor3ub(0,0,0);
 glVertex2f(ox-0.2,oy-0.9);
 glVertex2f(ox-0.1,oy-0.9);
 glVertex2f(ox-0.09,oy-0.94);
 glVertex2f(ox-0.22,oy-0.94);
 glEnd();

 glBegin(GL_QUADS);
 glColor3ub(0,0,0);
 glVertex2f(ox+0.2,oy-0.9);
 glVertex2f(ox+0.1,oy-0.9);
 glVertex2f(ox+0.09,oy-0.94);
 glVertex2f(ox+0.22,oy-0.94);
 glEnd();

  glPointSize(5);
  glBegin(GL_POINTS);
  glColor3f(0,0,0);
  glVertex2f(ox-0.05,oy+0.02);
  glVertex2f(ox+0.05,oy+0.02);
  glEnd();
}

void bird(GLfloat ox,GLfloat oy)
{
  glBegin(GL_QUADS);
  glColor3ub(0,0,139);
  glVertex2f(ox+0.7,oy+0.4);
  glVertex2f(ox+0.65,oy+0.43);
  glVertex2f(ox+0.65,oy+0.32);
  glVertex2f(ox+0.7,oy+0.35);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3ub(255,215,0);
  glVertex2f(ox+0.7,oy+0.4);
  glVertex2f(ox+0.8,oy+0.4);
  glVertex2f(ox+0.8,oy+0.37);
  glVertex2f(ox+0.76,oy+0.35);
  glVertex2f(ox+0.7,oy+0.35);
  glEnd();

  glBegin(GL_TRIANGLES);
  glColor3ub(112,128,144);
  glVertex2f(ox+0.8,oy+0.4);
  glVertex2f(ox+0.8,oy+0.37);
  glVertex2f(ox+0.83,oy+0.38);
  glEnd();

  glBegin(GL_TRIANGLES);
  glColor3ub(0,0,139);
  glVertex2f(ox+0.7,oy+0.38);
  glVertex2f(ox+0.75,oy+0.5);
  glVertex2f(ox+0.8,oy+0.38);
  glEnd();

  glBegin(GL_TRIANGLES);
  glColor3ub(0,0,139);
  glVertex2f(ox+0.7,oy+0.4);
  glVertex2f(ox+0.8,oy+0.4);
  glVertex2f(ox+0.83,oy+0.465);
  glEnd();


}
void bird2(GLfloat ox,GLfloat oy)
{
  glBegin(GL_QUADS);
  glColor3ub(128,0,0);
  glVertex2f(ox+0.7,oy+0.4);
  glVertex2f(ox+0.65,oy+0.43);
  glVertex2f(ox+0.65,oy+0.32);
  glVertex2f(ox+0.7,oy+0.35);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3ub(255,99,71);
  glVertex2f(ox+0.7,oy+0.4);
  glVertex2f(ox+0.8,oy+0.4);
  glVertex2f(ox+0.8,oy+0.37);
  glVertex2f(ox+0.76,oy+0.35);
  glVertex2f(ox+0.7,oy+0.35);
  glEnd();

  glBegin(GL_TRIANGLES);
  glColor3ub(0,0,0);
  glVertex2f(ox+0.8,oy+0.4);
  glVertex2f(ox+0.8,oy+0.37);
  glVertex2f(ox+0.83,oy+0.38);
  glEnd();

  glBegin(GL_TRIANGLES);
  glColor3ub(128,0,0);
  glVertex2f(ox+0.7,oy+0.38);
  glVertex2f(ox+0.75,oy+0.5);
  glVertex2f(ox+0.8,oy+0.38);
  glEnd();

  glBegin(GL_TRIANGLES);
  glColor3ub(128,0,0);
  glVertex2f(ox+0.7,oy+0.4);
  glVertex2f(ox+0.8,oy+0.4);
  glVertex2f(ox+0.83,oy+0.465);
  glEnd();
}
void kite()
{
    glBegin(GL_POLYGON);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(0.4,0.8);
    glVertex2f(0.6,0.6);
    glVertex2f(0.4,0.2);
    glVertex2f(0.2,0.6);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(165,42,42);
    glVertex2f(0.4,0.8);
    glVertex2f(0.4,0.2);
    glVertex2f(0.2,0.6);
    glVertex2f(0.6,0.6);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(0.2,0.6);
    glVertex2f(0.18,0.5);
    glVertex2f(0.22,0.5);
    glVertex2f(0.6,0.6);
    glVertex2f(0.58,0.5);
    glVertex2f(0.62,0.5);
    glVertex2f(0.4,0.2);
    glVertex2f(0.35,0.1);
    glVertex2f(0.45,0.1);
    glEnd();
}
void kite2()
{
    glBegin(GL_POLYGON);
    glColor3ub(139,0,139);
    glVertex2f(0.4,0.8);
    glVertex2f(0.6,0.6);
    glVertex2f(0.4,0.2);
    glVertex2f(0.2,0.6);
    glEnd();
    glLineWidth(0.09);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.4,0.8);
    glVertex2f(0.4,0.2);
    glVertex2f(0.2,0.6);
    glVertex2f(0.6,0.6);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(255,0,0);
    glVertex2f(0.2,0.6);
    glVertex2f(0.18,0.5);
    glVertex2f(0.22,0.5);
    glVertex2f(0.6,0.6);
    glVertex2f(0.58,0.5);
    glVertex2f(0.62,0.5);
    glVertex2f(0.4,0.2);
    glVertex2f(0.35,0.1);
    glVertex2f(0.45,0.1);
    glEnd();
}
void movecloud()
{
    if(cloudstatus==1&&cloudxoffset<2)
    {
        cloudxoffset=cloudxoffset+0.023;
    }
    else
        {
            cloudxoffset=0;
        }
    glPushMatrix();
    glTranslatef(cloudxoffset,0,0);
    glPushMatrix();
    glScalef(0.85,0.85,0);
    glTranslatef(0,0.2,0);
    glColor3ub(224,224,224);
    cloud(-0.9,0.7);
    cloud(-2,0.7);
    cloud(-3,0.7);
    glPopMatrix();
    glPopMatrix();
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='c'||key=='C')
    {
        cloudstatus=1;
    }
    if(key=='N'||key=='n')
    {
        cloudstatus=0;
    }
     if(key=='s'||key=='S')
    {
        sunstatus=1;
    }
    if(key=='d'||key=='D')
    {
        sunstatus=0;
    }

    if(key=='b'||key=='B')
    {
        birdstatus=1;
    }
    if(key=='w'||key=='W')
    {
        moveupstatus=1;
    }
    if(key=='Q'||key=='q')
    {
        exit(0);
    }
}

void draw()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //ground
    glBegin(GL_QUADS);
    glColor3ub(135,206,250);
    glVertex2f(-1,1);
    glVertex2f(1,1);
    glVertex2f(1,-0.65);
    glVertex2f(-1,-0.65);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0.8,0);
    glVertex2f(-1,-0.45);
    glVertex2f(1,-0.45);
    glVertex2f(1,-1);
    glVertex2f(-1,-1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(124,252,0);
    glVertex2f(-1,-0.45);
    glVertex2f(1,-0.45);
    glVertex2f(1,-0.5);
    glVertex2f(-1,-0.5);
    glEnd();
     movesun();

    //hills
    glBegin(GL_TRIANGLES);
    glColor3ub(112,128,144);
    glVertex2f(-1,-0.45);
    glVertex2f(-0.5,0.2);
    glVertex2f(0,-0.45);

    glVertex2f(-0.3,-0.45);
    glVertex2f(0.3,0.35);
    glVertex2f(0.9,-0.45);

    glVertex2f(0.5,-0.45);
    glVertex2f(0.85,0.1);
    glVertex2f(1.25,-0.45);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(245,255,250);
    glVertex2f(-0.61,0.06);
    glVertex2f(-0.5,0.0);
    glVertex2f(-0.45,0.05);
    glVertex2f(-0.34,0.0);
    glVertex2f(-0.5,0.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(245,255,250);
    glVertex2f(0.15,0.15);
    glVertex2f(0.2,0.05);
    glVertex2f(0.35,0.15);
    glVertex2f(0.49,0.1);
    glVertex2f(0.3,0.35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(245,255,250);
    glVertex2f(0.78,0.0);
    glVertex2f(0.9,-0.1);
    glVertex2f(1.0,-0.09);
    glVertex2f(0.85,0.1);
    glEnd();


    //house
    glBegin(GL_QUADS);
    glColor3ub(255,160,122);
    glVertex2f(-0.9,-0.45);
    glVertex2f(-0.9,-0.25);
    glVertex2f(-0.65,-0.25);
    glVertex2f(-0.65,-0.45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(178,34,34);
    glVertex2f(-0.9,-0.25);
    glVertex2f(-0.9,-0.2);
    glVertex2f(-0.65,-0.2);
    glVertex2f(-0.65,-0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,228,225);
    glVertex2f(-0.8,-0.45);
    glVertex2f(-0.8,-0.35);
    glVertex2f(-0.7,-0.35);
    glVertex2f(-0.7,-0.45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(165,42,42);
    glVertex2f(-0.8,-0.45);
    glVertex2f(-0.8,-0.35);
    glVertex2f(-0.75,-0.37);
    glVertex2f(-0.75,-0.43);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(250,128,114);
    glVertex2f(-0.65,-0.23);
    glVertex2f(-0.5,-0.23);
    glVertex2f(-0.5,-0.45);
    glVertex2f(-0.65,-0.45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,228,225);
    glVertex2f(-0.6,-0.3);
    glVertex2f(-0.55,-0.3);
    glVertex2f(-0.55,-0.4);
    glVertex2f(-0.6,-0.4);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(0,0,139);
    glVertex2f(0.4,-0.45);
    glVertex2f(0.4,-0.2);
    glVertex2f(0.7,-0.2);
    glVertex2f(0.7,-0.45);
    glEnd();

      glBegin(GL_QUADS);
    glColor3ub(138,43,226);
    glVertex2f(0.2,-0.3);
    glVertex2f(0.5,-0.3);
    glVertex2f(0.5,-0.45);
    glVertex2f(0.2,-0.45);
    glEnd();

      glBegin(GL_QUADS);
    glColor3ub(139,0,0);
    glVertex2f(0.2,-0.23);
    glVertex2f(0.5,-0.27);
    glVertex2f(0.5,-0.3);
    glVertex2f(0.2,-0.3);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(139,0,0);
    glVertex2f(0.4,-0.2);
    glVertex2f(0.4,-0.15);
    glVertex2f(0.7,-0.17);
    glVertex2f(0.7,-0.2);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(220,20,60);
    glVertex2f(0.23,-0.37);
    glVertex2f(0.27,-0.37);
    glVertex2f(0.27,-0.41);
    glVertex2f(0.23,-0.41);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(220,20,60);
    glVertex2f(0.29,-0.37);
    glVertex2f(0.33,-0.37);
    glVertex2f(0.33,-0.41);
    glVertex2f(0.29,-0.41);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(220,20,60);
    glVertex2f(0.39,-0.35);
    glVertex2f(0.45,-0.35);
    glVertex2f(0.45,-0.45);
    glVertex2f(0.39,-0.45);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(165,42,42);
    glVertex2f(0.55,-0.3);
    glVertex2f(0.65,-0.3);
    glVertex2f(0.65,-0.45);
    glVertex2f(0.55,-0.45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(205,92,92);
    glVertex2f(-0.65,-0.23);
    glVertex2f(-0.5,-0.23);
    glVertex2f(-0.5,-0.26);
    glVertex2f(-0.65,-0.26);
    glEnd();

    //tree
    glPushMatrix();
    glScalef(0.45,1.5,0.0);
    tree(-2.1,-0.4);
    glPopMatrix();


    glPushMatrix();
    glScalef(0.45,1.0,0.0);
    glTranslatef( -1.25, 0.0, 0.0 );
    tree(-0.7,-0.55);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.45,1.0,0.0);
    glTranslatef(2.7,0.0,0.0);
    tree(-0.55,-0.45);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.45,1.35,0.0);
    glTranslatef(2.7,0.0,0.0);
    tree(-0.8,-0.34);
    glPopMatrix();
    glPushMatrix();
    glScalef(0.45,1.0,0.0);
    glTranslatef(1.7,0.0,0.0);
    tree(-0.05,-0.45);
    glPopMatrix();


    grass();
    glPushMatrix();
    glScalef(1.35,1.35,0.0);
    glTranslatef(0.16,0.116,0.0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.15,1.15,0.0);
    glTranslatef(0.13,0.061,0.0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0,1.0,0.0);
    glTranslatef(0.1,0.0,0.0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.35,1.35,0.0);
    glTranslatef(0.4,0.117,0.0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.15,1.15,0.0);
    glTranslatef(0.41,0.06,0.0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.35,1.35,0.0);
    glTranslatef(0.45,0.117,0.0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.15,1.15,0.0);
    glTranslatef(0.47,0.059,0.0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.15,1.15,0.0);
    glTranslatef(0.5,0.059,0.0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0,1.0,0.0);
    glTranslatef(0.53,0.0,0.0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0,1.0,0.0);
    glTranslatef(0.56,0.0,0.0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.35,1.35,0.0);
    glTranslatef(0.57,0.116,0.0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.1,1.1,0.0);
    glTranslatef(0.61,0.042,0.0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.15,1.35,0.0);
    glTranslatef(0.63,0.117,0.0);
    grass();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0,1.0,0.0);
    glTranslatef(0.68,0.0,0.0);
    grass();
    glPopMatrix();

     glPushMatrix();
    glScalef(1.0,1.0,0.0);
    glTranslatef(0.71,0.0,0.0);
    grass();
    glPopMatrix();

     glPushMatrix();
    glScalef(1.0,1.0,0.0);
    glTranslatef(0.74,0.0,0.0);
    grass();
    glPopMatrix();

     glPushMatrix();
    glScalef(1.3,1.3,0.0);
    glTranslatef(-0.15,-0.05,0.0);
    grass();
    glPopMatrix();

     glPushMatrix();
    glScalef(1.5,1.5,0.0);
    glTranslatef(-0.08,0.03,0.0);
    grass();
    glPopMatrix();

     glPushMatrix();
    glScalef(1.0,1.0,0.0);
    glTranslatef(-0.35,-0.17,0.0);
    grass();
    glPopMatrix();

    gate();



    glPushMatrix();
    glTranslatef(-0.6,-0.6,0.0);
    glScalef(0.3,0.3,0.0);
    human(0,0.5);
    glPopMatrix();


    movecloud();


     movebird();
     moveup();
     //moveupstatus=0;

    /*glPushMatrix();
    glScalef(0.35,0.35,0);
    glTranslatef(-0.4,1.7,0);
     kite();
     glPopMatrix();*/

     glBegin(GL_LINES);
     glColor3ub(0,255,255);
     glVertex2f(0,0.81+muyoffset);
     glVertex2f(-0.525,-0.48);
     glVertex2f(0.1965,0.6604+muyoffset);
     glVertex2f(-0.25,-0.48);
     glEnd();

     glPushMatrix();
    glScalef(0.25,0.25,0.0);
    glTranslatef(-1.0,-2.3,0.0);
    women(0,0.5);
    glPopMatrix();
    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();

}
void init()
{
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    //glClearColor(1,1,1,0);
     glClearColor(1,2,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}
int main(int nidhi,char *gombe[])
{
    glutInit(&nidhi,gombe);
    //glutInitWindowPosition(200,1);
     glutInitWindowPosition(400,2);
    //glutInitWindowSize(800,800);
    glutInitWindowSize(900,900);
    glutCreateWindow("kite");
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(draw);
    init();
    glutMainLoop();
    return 0;

}
