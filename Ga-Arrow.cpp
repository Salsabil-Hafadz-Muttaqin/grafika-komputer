#include<windows.h>
#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <GL/glut.h>
#include <fstream>
#include <sstream>
int score = 0;
char cetakScore[1000];
float ortho[]={0,54,0,36};
float target1[]=
{53.5,55,17,23,0.0   ,0.0   ,0.0   , 0.0         ,0.0};
///x1,x2,y1,y2,transx,transy,isatas,relativeBawah,relativeAtas
///00,11,22,33,444444,555555,666666,7777777777777,888888888888,99999,10
///x1,x2,y1,y2,transx,transy,relatifx1,relatifx2,relatify1,relatify2,kecepetan
float bow1[]=
{0,   3, 14,26,0     ,0      ,0     ,0           ,0};
float arrow1[]=
{0.0f,4.0f,19.5f,20.5f,0.0f,0.0f  ,0.0f    ,0.0f   ,0.0f          ,0.0f,0.0f,1.0f,0.0f};
float dynamite1[4][11]=
{{9.0f,10.0f,21.0f,23.5f,10.0f    ,10.0f   ,0.0f   ,0.0f          ,0.0f,0.0f,0.5f},
 {9.0f,10.0f,21.0f,23.5f,20.0f    ,30.0f   ,0.0f   ,0.0f          ,0.0f,0.0f,1.0f},
 {9.0f,10.0f,21.0f,23.5f,30.0f    ,20.0f   ,0.0f   ,0.0f          ,0.0f,0.0f,1.2f},
 {9.0f,10.0f,21.0f,23.5f,40.0f    ,15.0f   ,0.0f   ,0.0f          ,0.0f,0.0f,0.8f}};
float kelapKelip1[]=
{0.0f,0.0f,0.0f,0.0f,0.0f};
bool change; //Display Change
void init(){
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 54, 0, 36);
}
void *font = GLUT_BITMAP_HELVETICA_18;
void *font1 = GLUT_BITMAP_HELVETICA_12;
void drawText(int x, int y, const char *string) {
	glRasterPos2f(x, y);
	int len = (int)strlen(string);
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(font, string[i]);
	}
}
void drawText1(int x, int y, const char *string) {
	glRasterPos2f(x, y);
	int len = (int)strlen(string);
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(font1, string[i]);
	}
}
void target(){

    //target
    glPushMatrix();
    glColor3f(0,0,1.0);
    glBegin(GL_QUADS);
        glVertex2f(53.5,17);
        glVertex2f(54,17);
        glVertex2f(54,23);
        glVertex2f(53.5,23);
        glVertex2f(53.5,17);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9,0.9,0.1);
    glBegin(GL_QUADS);
        glVertex2f(53.5,18.5);
        glVertex2f(54,18.5);
        glVertex2f(54,19.5);
        glVertex2f(53.5,19.5);
        glVertex2f(53.5,18.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,2,0);
    glColor3f(1,1,0);
    glBegin(GL_QUADS);
        glVertex2f(53.5,18.5);
        glVertex2f(54,18.5);
        glVertex2f(54,19.5);
        glVertex2f(53.5,19.5);
        glVertex2f(53.5,18.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
        glVertex2f(53.5,19.5);
        glVertex2f(54,19.5);
        glVertex2f(54,20.5);
        glVertex2f(53.5,20.5);
        glVertex2f(53.5,19.5);
    glEnd();
    glPopMatrix();}
void bow(){
    //BOW
    //Color1
    glColor3f(1,1,0.1);
    glBegin(GL_QUADS);
        glVertex2f(0,14);
        glVertex2f(1,17.5);
        //Color2
        glColor3f(0.21,0.64,0.5);
        glVertex2f(3,19);
        glVertex2f(0,19);
        glVertex2f(0,14);
    glEnd();

    //Color1
    glColor3f(1,1,0.1);
    glBegin(GL_QUADS);
        glVertex2f(0,26);
        glVertex2f(1,22.5);
        //Color2
        glColor3f(0.21,0.64,0.5);
        glVertex2f(3,21);
        glVertex2f(0,21);
        glVertex2f(0,26);
    glEnd();

    //BOW ACCESSORIES
    //Color21
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(0.9,17);
        glVertex2f(1,17.5);
        glVertex2f(0,17.5);
        //Color2
        glColor3f(1, 0, 0);
        glVertex2f(0,17);
    glEnd();

    //Color1
    glColor3f(0, 0,0);
    glBegin(GL_QUADS);
        glVertex2f(0.9,23);
        glVertex2f(1,22.5);
        glVertex2f(0,22.5);
        //Color2
        glColor3f(1, 0, 0);
        glVertex2f(0,23);
    glEnd();
    }
void arrow(){
//ARROW
    glColor3f(0.3, 0.2, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(0,20.2);
    glVertex2f(3,20.2);
    glVertex2f(3,19.8);
    //
    glColor3f(1,1,0.5);
    glVertex2f(0,19.8);
    glVertex2f(0,20.2);
    glEnd();

    glColor3f(1, 1, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(3,20.5);
    glVertex2f(4,20);
    //
    glColor3f(0.52,0,0);
    glVertex2f(3,19.5);
    glVertex2f(3,20.5);
    glEnd();

}
void dynamite(){
    //DINAMITE BARU
    //COLLISSIONNYA
    glPushMatrix();
    //glBegin(GL_POLYGON);
    //glColor3f(1,1,1);
    //    glVertex2f(dynamite1[0][0],dynamite1[0][2]);
    //    glVertex2f(dynamite1[0][0],dynamite1[0][3]);
    //    glVertex2f(dynamite1[0][1],dynamite1[0][3]);
    //    glVertex2f(dynamite1[0][1],dynamite1[0][2]);
    //glEnd();
    //BENTUKNYA
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
        glVertex2f(9,21);
        glVertex2f(10,21);
        glVertex2f(10,23);
        glColor3f(0.7, 0, 0);
        glVertex2f(9,23);
        glVertex2f(9,21);
    glEnd();
    glColor3f(.8, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(9,21);
        glVertex2f(9.4,21);
        glVertex2f(9.4,23);
        glColor3f(.5, 0, 0);
        glVertex2f(9,23);
        glVertex2f(9,21);
    glEnd();
    glColor3f(1, 1, 0);
    glBegin(GL_QUADS);
        glVertex2f(9.4,23.5);
        glVertex2f(9.6,23.5);
        glVertex2f(9.6,23);
        glVertex2f(9.4,23);
        glVertex2f(9.4,23.5);
    glEnd();
    glPopMatrix();
}
void dynamiteBanyak(){
    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glTranslated(dynamite1[i][4], dynamite1[i][5], 0);
        dynamite();
        glPopMatrix();
    }
}
void star(){

    //star 1
    glPushMatrix();
    glTranslatef(0,-5,0);
    glPushMatrix();
    glColor3f(0.56,0.56,0.56);
    glBegin(GL_POLYGON);
        glVertex2f(3,1);
        glVertex2f(3,1.4);
        glVertex2f(3.2,1.4);
        glVertex2f(3.2,1);
        glVertex2f(3.6,1);
        glVertex2f(3.6,0.8);
        glVertex2f(3.2,0.8);
        glVertex2f(3.2,0.4);
        glVertex2f(3,0.4);
        glVertex2f(3,0.8);
        glVertex2f(2.6,0.8);
        glVertex2f(2.6,1);
        glVertex2f(3,1);
    glEnd();
    glPopMatrix();
    //inti
    glPushMatrix();
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glVertex2f(2.9,1.1);
        glVertex2f(3.3,1.1);
        glVertex2f(3.3,0.7);
        glVertex2f(2.9,0.7);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}
void star2(){
//star 2
    glPushMatrix();
    glTranslatef(0,-5,0);
    glPushMatrix();
    glColor3f(0.56,0.56,0.56);
    glBegin(GL_POLYGON);
        glVertex2f(6,1);
        glVertex2f(6,1.6);
        glVertex2f(6.2,1.6);
        glVertex2f(6.2,1);
        glVertex2f(6.9,1);
        glVertex2f(6.9,0.8);
        glVertex2f(6.2,0.8);
        glVertex2f(6.2,0.10);
        glVertex2f(6,0.10);
        glVertex2f(6,0.8);
        glVertex2f(5.3,0.8);
        glVertex2f(5.3,1);
        glVertex2f(6,1);
    glEnd();
    glPopMatrix();
    //inti
    glPushMatrix();
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glVertex2f(5.9,1.1);
        glVertex2f(6.3,1.1);
        glVertex2f(6.3,0.7);
        glVertex2f(5.9,0.7);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    }
void star3(){
//titik terang
    glPushMatrix();
    glTranslatef(0,-5,0);
    glPushMatrix();
    glPushMatrix();
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glVertex2f(7.9,1.1);
        glVertex2f(8.3,1.1);
        glVertex2f(8.3,0.7);
        glVertex2f(7.9,0.7);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    }
void star4(){
//titik gelap
    glPushMatrix();
    glTranslatef(0,-5,0);
    glPushMatrix();
    glColor3f(0.36,0.36,0.36);
    glBegin(GL_QUADS);
        glVertex2f(9.9,1.1);
        glVertex2f(10.3,1.1);
        glVertex2f(10.3,0.7);
        glVertex2f(9.9,0.7);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    }
void semuaStar(){
    glPushMatrix();
    glScaled(kelapKelip1[2],kelapKelip1[2],0);
    glTranslatef(3,12,0);
        star();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[4],kelapKelip1[4],0);
    glTranslatef(14,24,0);
        star();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[1],kelapKelip1[1],0);
    glTranslatef(17,16,0);
        star();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[1],kelapKelip1[1],0);
    glTranslatef(31,24,0);
        star();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[2],kelapKelip1[2],0);
    glTranslatef(27,16,0);
        star();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[1],kelapKelip1[1],0);
    glTranslatef(10,15,0);
        star();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[3],kelapKelip1[3],0);
    glTranslatef(48,32,0);
        star();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[1],kelapKelip1[1],0);
    glTranslatef(2,38,0);
        star();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[3],kelapKelip1[3],0);
    glTranslatef(28,8,0);
        star();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[3],kelapKelip1[3],0);
    glTranslatef(17,37,0);
        star();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[4],kelapKelip1[4],0);
    glTranslatef(14,21,0);
        star2();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[2],kelapKelip1[2],0);
    glTranslatef(19,36,0);
        star2();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[2],kelapKelip1[2],0);
    glTranslatef(29,9,0);
        star2();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[4],kelapKelip1[4],0);
    glTranslatef(41,19,0);
        star2();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[3],kelapKelip1[3],0);
    glTranslatef(1,10,0);
        star3();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[1],kelapKelip1[1],0);
    glTranslatef(19,36,0);
        star4();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[3],kelapKelip1[3],0);
    glTranslatef(-3,27,0);
        star3();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[3],kelapKelip1[3],0);
    glTranslatef(7,19,0);
        star3();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[1],kelapKelip1[1],0);
    glTranslatef(31,29,0);
        star3();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[3],kelapKelip1[3],0);
    glTranslatef(39,9,0);
        star3();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[4],kelapKelip1[4],0);
    glTranslatef(39,13,0);
        star2();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[3],kelapKelip1[3],0);
    glTranslatef(37,36,0);
        star3();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[4],kelapKelip1[4],0);
    glTranslatef(16,19,0);
        star4();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[4],kelapKelip1[4],0);
    glTranslatef(13,17,0);
        star4();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[2],kelapKelip1[2],0);
    glTranslatef(35,16,0);
        star4();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[4],kelapKelip1[4],0);
    glTranslatef(15,22,0);
        star4();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[1],kelapKelip1[1],0);
    glTranslatef(29,31,0);
        star4();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[2],kelapKelip1[2],0);
    glTranslatef(-4,21,0);
        star4();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[3],kelapKelip1[3],0);
    glTranslatef(-2,49,0);
        star4();
    glPopMatrix();

    glPushMatrix();
    glScaled(kelapKelip1[4],kelapKelip1[4],0);
    glTranslatef(31,10,0);
        star4();
    glPopMatrix();
}
void title(){
    ///"(G)a"
    glBegin(GL_POLYGON);
        glVertex2f(8.4540624051322,7.7087593164503);
        glVertex2f(8.6559630161005,9.900823092677);
        glVertex2f(7.8772035166516,10.3911531478855);
        glVertex2f(6.9686507672945,10.5353678700057);
        glVertex2f(6.1177839067854,10.3623102034615);
        glVertex2f(5.4688176572447,10.0161948703731);
        glVertex2f(4.920801713188,9.4826003985285);
        glVertex2f(4.6179507967356,8.8913200378357);
        glVertex2f(6.8677004618103,7.6078090109662);
        glVertex2f(7.3147661003829,7.9395028718426);
        glVertex2f(7.8483605722275,7.9971887606907);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(4.6179507967356,8.8913200378357);
        glVertex2f(6.8677004618103,7.6078090109662);
        glVertex2f(6.7523286841142,7.1895863168177);
        glVertex2f(6.8100145729623,6.9011568725774);
        glVertex2f(6.9686507672945,6.7136777338211);
        glVertex2f(7.401294933655,6.5406200672769);
        glVertex2f(7.3580305170189,5.4590096513756);
        glVertex2f(6.3196845177537,5.5743814290718);
        glVertex2f(5.742825629273,5.77628204004);
        glVertex2f(5.1948096852163,6.1656617897645);
        glVertex2f(4.7910084632799,6.6704133171851);
        glVertex2f(4.5602649078876,7.2616936778778);
        glVertex2f(4.4304716579794,7.9827672884787);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(7.401294933655,6.5406200672769);
        glVertex2f(7.3580305170189,5.4590096513756);
        glVertex2f(7.6608814334713,5.4445881791636);
        glVertex2f(7.9925752943477,5.4878525957997);
        glVertex2f(8.3963765162842,5.5166955402237);
        glVertex2f(8.5982771272524,6.3964053451568);
        glVertex2f(8.7713347937966,7.2328507334538);
        glVertex2f(7.9781538221357,7.2761151500898);
        glVertex2f(7.3436090448069,7.3193795667259);
        glVertex2f(7.386873461443,6.9732642336374);
    glEnd();

    ///"G(a)"
    glBegin(GL_POLYGON);
        glVertex2f(8.8112386658711,5.5626580980918);
        glVertex2f(10.1087725218083,9.2133465741185);
        glVertex2f(11.5382589732646,5.5406659988386);
    glEnd();

    ///"Petik"
    glBegin(GL_POLYGON);
        glVertex2f(12,10.8);
        glVertex2f(13,10.8);
        glVertex2f(13,10);
        glVertex2f(12,10);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(13,10);
        glVertex2f(12.8,10);
        glVertex2f(12.8,9.8);
        glVertex2f(12.6,9.6);
        glVertex2f(12.7484360407656,9.4664650666233);
        glVertex2f(13.0003019079891,9.7100276634988);
    glEnd();

    ///"(A)rrow"
    glBegin(GL_QUADS);
        glVertex2f(12.8008119026379,5.5367444956759);
        glVertex2f(14.948536274916,10.6303340542543);
        glVertex2f(15.7176537866102,8.7873543564211);
        glVertex2f(14.5712333446509,5.4932095421838);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(15.7176537866102,8.7873543564211);
        glVertex2f(16.9221208332256,5.4351629375276);
        glVertex2f(15.1226760888845,5.4496745886916);
        glVertex2f(14.8324430656037,6.2478154027139);

    ///"A(r)row"
    glBegin(GL_QUADS);
        glVertex2f(17.1235540766078,5.5423030226511);
        glVertex2f(17,9);
        glVertex2f(18.3305083987976,9.1293261484114);
        glVertex2f(18.1274693539432,5.5423030226511);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(18.1658451919647,8.7575181250593);
        glVertex2f(18.3984014981569,8.9771546364631);
        glVertex2f(18.656797393926,9.1063525843476);
        glVertex2f(19.0702308271565,9.0417536104053);
        glVertex2f(19.3221668255314,8.8221170990016);
        glVertex2f(19.4319850812333,8.3699242814057);
        glVertex2f(19.3803059020795,7.9952502325405);
        glVertex2f(19.2123485698295,7.782073618531);
        glVertex2f(18.8505943157528,7.6076563888869);
        glVertex2f(18.4565405747049,7.5818167993099);
        glVertex2f(18.3208827294262,7.6141162862811);
        glVertex2f(18.1400056023878,8.2601060257038);
    glEnd();

    ///"Ar(r)ow"
    glPushMatrix();
    glTranslatef(2.7,0,0);
    glBegin(GL_QUADS);
        glVertex2f(17.1235540766078,5.5423030226511);
        glVertex2f(17,9);
        glVertex2f(18.3305083987976,9.1293261484114);
        glVertex2f(18.1274693539432,5.5423030226511);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(18.1658451919647,8.7575181250593);
        glVertex2f(18.3984014981569,8.9771546364631);
        glVertex2f(18.656797393926,9.1063525843476);
        glVertex2f(19.0702308271565,9.0417536104053);
        glVertex2f(19.3221668255314,8.8221170990016);
        glVertex2f(19.4319850812333,8.3699242814057);
        glVertex2f(19.3803059020795,7.9952502325405);
        glVertex2f(19.2123485698295,7.782073618531);
        glVertex2f(18.8505943157528,7.6076563888869);
        glVertex2f(18.4565405747049,7.5818167993099);
        glVertex2f(18.3208827294262,7.6141162862811);
        glVertex2f(18.1400056023878,8.2601060257038);
    glEnd();
    glPopMatrix();

    ///"Arr(o)w"
    glBegin(GL_POLYGON);
        glVertex2f(23.8843646857387,7.4257101798446);
        glVertex2f(23.745752268344,9.1514347764094);
        glVertex2f(23.1843719778952,8.9920304964054);
        glVertex2f(22.7893265883201,8.6940137990066);
        glVertex2f(22.5259629952701,8.3336215137803);
        glVertex2f(22.3734893361358,8.049466058121);
        glVertex2f(22.2418075396108,7.6405594268064);
        glVertex2f(22.2071544352621,7.1831384494037);
        glVertex2f(22.290321885699,6.7326480928707);
        glVertex2f(22.4635874074424,6.3722558076443);
        glVertex2f(22.6576447917951,6.0742391102456);
        glVertex2f(22.8932859013662,5.8316673798048);
        glVertex2f(23.1843719778952,5.6445406163218);
        glVertex2f(23.5,5.5);
        glVertex2f(23.8358503396506,5.4296913693599);
        glVertex2f(23.8843646857387,6.5247294667786);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(23.8843646857387,7.4257101798446);
        glVertex2f(23.8843646857387,6.5247294667786);
        glVertex2f(23.8054990852815,5.4240973976788);
        glVertex2f(24.2357269615489,5.4679982013795);
        glVertex2f(24.648394516336,5.6348212554424);
        glVertex2f(24.9644803029814,5.8806657561666);
        glVertex2f(25.227885125186,6.1967515428121);
        glVertex2f(25.5264105903511,6.8201429553628);
        glVertex2f(25.579091554792,7.1889097064492);
        glVertex2f(25.5351907510913,7.698159029378);
        glVertex2f(25.3332470540678,8.1810678700863);
        glVertex2f(25.1225231963042,8.5410544604325);
        glVertex2f(24.7537564452178,8.8747005685583);
        glVertex2f(24.3849896941315,9.0766442655817);
        glVertex2f(24.0425634252656,9.1644458729833);
        glVertex2f(23.954761817864,8.2249686737871);
    glEnd();

    ///"Arro(w)"
    glBegin(GL_POLYGON);
        glVertex2f(26,9);
        glVertex2f(27.4320817969433,9.1147587769437);
        glVertex2f(27.9780031056108,5.5414556656657);
        glVertex2f(26.8241239759273,5.5786775730749);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(27.6802278463377,8.9906857522466);
        glVertex2f(28.710033951324,9.0775368695346);
        glVertex2f(27.9780031056108,5.5414556656657);
        glVertex2f(27.097084630261,5.5662702706051);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(27.6802278463377,8.9906857522466);
        glVertex2f(28.710033951324,9.0775368695346);
        glVertex2f(29.0822530254155,5.5414556656657);
        glVertex2f(28.3874440871114,5.5538629681354);
        glVertex2f(28.1765199451263,6.794593215107);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(28.9286223401363,8.9912294716651);
        glVertex2f(30.3477978773265,9.1395733818832);
        glVertex2f(29.4272250792576,5.5541723971613);
        glVertex2f(28.323610529955,5.5748007064941);
        glVertex2f(28.6330351699464,6.987839895788);
    glEnd();
    }
void titlex(){
    glPushMatrix();
    glTranslated(6,18,0);
    ///"(G)a"
    glBegin(GL_POLYGON);
        glVertex2f(8.4540624051322,7.7087593164503);
        glVertex2f(8.6559630161005,9.900823092677);
        glVertex2f(7.8772035166516,10.3911531478855);
        glVertex2f(6.9686507672945,10.5353678700057);
        glVertex2f(6.1177839067854,10.3623102034615);
        glVertex2f(5.4688176572447,10.0161948703731);
        glVertex2f(4.920801713188,9.4826003985285);
        glVertex2f(4.6179507967356,8.8913200378357);
        glVertex2f(6.8677004618103,7.6078090109662);
        glVertex2f(7.3147661003829,7.9395028718426);
        glVertex2f(7.8483605722275,7.9971887606907);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(4.6179507967356,8.8913200378357);
        glVertex2f(6.8677004618103,7.6078090109662);
        glVertex2f(6.7523286841142,7.1895863168177);
        glVertex2f(6.8100145729623,6.9011568725774);
        glVertex2f(6.9686507672945,6.7136777338211);
        glVertex2f(7.401294933655,6.5406200672769);
        glVertex2f(7.3580305170189,5.4590096513756);
        glVertex2f(6.3196845177537,5.5743814290718);
        glVertex2f(5.742825629273,5.77628204004);
        glVertex2f(5.1948096852163,6.1656617897645);
        glVertex2f(4.7910084632799,6.6704133171851);
        glVertex2f(4.5602649078876,7.2616936778778);
        glVertex2f(4.4304716579794,7.9827672884787);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(7.401294933655,6.5406200672769);
        glVertex2f(7.3580305170189,5.4590096513756);
        glVertex2f(7.6608814334713,5.4445881791636);
        glVertex2f(7.9925752943477,5.4878525957997);
        glVertex2f(8.3963765162842,5.5166955402237);
        glVertex2f(8.5982771272524,6.3964053451568);
        glVertex2f(8.7713347937966,7.2328507334538);
        glVertex2f(7.9781538221357,7.2761151500898);
        glVertex2f(7.3436090448069,7.3193795667259);
        glVertex2f(7.386873461443,6.9732642336374);
    glEnd();

    ///"G(a)"
    glBegin(GL_POLYGON);
        glVertex2f(8.8112386658711,5.5626580980918);
        glVertex2f(10.1087725218083,9.2133465741185);
        glVertex2f(11.5382589732646,5.5406659988386);
    glEnd();
    ///"Ga(m)e"
    glPushMatrix();
    glTranslatef(-.8,-2.7,0);
    glScaled(1.79,1.79,0);
    glBegin(GL_POLYGON);
        glVertex2f(7.075276494812,4.6156728248078);
        glVertex2f(7.0537767675847,6.5668564466152);
        glVertex2f(7.7830741954323,6.6456994117879);
        glVertex2f(7.6648097476732,4.605637687944);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(7.7762767993177,6.4711263122693);
        glVertex2f(7.9520437459838,6.6525631604408);
        glVertex2f(8.1221407911446,6.7092621754944);
        glVertex2f(8.3092475408214,6.6809126679676);
        glVertex2f(8.428315472434,6.5958641453872);
        glVertex2f(8.5,6.5);
        glVertex2f(8.570063010068,6.3974175926996);
        glVertex2f(8.5133639950144,4.6057287170061);
        glVertex2f(7.844315617382,4.5660394064686);
        glVertex2f(7.8499855188873,5.0082917238866);
        glVertex2f(7.8329758143712,5.3598256172189);
        glVertex2f(7.8329758143712,5.6716702000136);
        glVertex2f(7.7706068978123,5.8077478361422);
        glVertex2f(7.6685486707158,5.898466260228);
    glEnd();
    glPushMatrix();
    glTranslatef(.82,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(7.7762767993177,6.4711263122693);
        glVertex2f(7.9520437459838,6.6525631604408);
        glVertex2f(8.1221407911446,6.7092621754944);
        glVertex2f(8.3092475408214,6.6809126679676);
        glVertex2f(8.428315472434,6.5958641453872);
        glVertex2f(8.5,6.5);
        glVertex2f(8.570063010068,6.3974175926996);
        glVertex2f(8.5133639950144,4.6057287170061);
        glVertex2f(7.844315617382,4.5660394064686);
        glVertex2f(7.8499855188873,5.0082917238866);
        glVertex2f(7.8329758143712,5.3598256172189);
        glVertex2f(7.8329758143712,5.6716702000136);
        glVertex2f(7.7706068978123,5.8077478361422);
        glVertex2f(7.6685486707158,5.898466260228);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    ///"Gam(e)"
    glPushMatrix();
    glTranslatef(-1.2,-2.7,0);
    glScaled(1.79,1.79,0);
    glBegin(GL_POLYGON);
        glVertex2f(10.6383425302498,6.7116297468638);
        glVertex2f(10.5519674204202,5.2926100853776);
        glVertex2f(10.1200918712722,4.7866987278043);
        glVertex2f(9.9843595558257,4.9039220911444);
        glVertex2f(9.8547968910813,5.1445384685269);
        glVertex2f(9.7931003840602,5.3728155445051);
        glVertex2f(9.780761082656,5.6812980796108);
        glVertex2f(9.7931003840602,5.9897806147165);
        glVertex2f(9.8856451445919,6.2303969920989);
        glVertex2f(10.0454900979094,6.4769268685567);
        glVertex2f(10.2797422435546,6.6665595578886);
        glVertex2f(10.4582200688081,6.7148973022281);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(10.5635802519535,6.7193651580337);
        glVertex2f(10.6550803231684,5.3834641182963);
        glVertex2f(11.271180802682,5.371264108801);
        glVertex2f(11.3870808928875,5.5969642844644);
        glVertex2f(11.4358809308688,5.8470644791184);
        glVertex2f(11.4114809118781,6.0910646690248);
        glVertex2f(11.3443808596539,6.2984648304452);
        glVertex2f(11.2223807647007,6.5119649966133);
        glVertex2f(11.0271806127756,6.6461651010618);
        glVertex2f(10.8197804513552,6.7071651485384);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(10.5519674204202,5.2926100853776);
        glVertex2f(10.0778574226888,4.8137973886809);
        glVertex2f(10.2597386366121,4.6375999626927);
        glVertex2f(10.5,4.5);
        glVertex2f(10.7201254593556,4.4500349608342);
        glVertex2f(10.9076904612141,4.9161055715128);
        glVertex2f(10.7485443990312,4.984311026734);
        glVertex2f(10.6235010644589,5.1377733009819);
    glEnd();
    glPopMatrix();

    ///"Game (O)ver"
    glPushMatrix();
    glScalef(1.4,1.4,0);
    glTranslatef(-7,-1.7,0);
    glBegin(GL_POLYGON);
        glBegin(GL_POLYGON);
        glVertex2f(23.8843646857387,7.4257101798446);
        glVertex2f(23.745752268344,9.1514347764094);
        glVertex2f(23.1843719778952,8.9920304964054);
        glVertex2f(22.7893265883201,8.6940137990066);
        glVertex2f(22.5259629952701,8.3336215137803);
        glVertex2f(22.3734893361358,8.049466058121);
        glVertex2f(22.2418075396108,7.6405594268064);
        glVertex2f(22.2071544352621,7.1831384494037);
        glVertex2f(22.290321885699,6.7326480928707);
        glVertex2f(22.4635874074424,6.3722558076443);
        glVertex2f(22.6576447917951,6.0742391102456);
        glVertex2f(22.8932859013662,5.8316673798048);
        glVertex2f(23.1843719778952,5.6445406163218);
        glVertex2f(23.5,5.5);
        glVertex2f(23.8358503396506,5.4296913693599);
        glVertex2f(23.8843646857387,6.5247294667786);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(23.8843646857387,7.4257101798446);
        glVertex2f(23.8843646857387,6.5247294667786);
        glVertex2f(23.8054990852815,5.4240973976788);
        glVertex2f(24.2357269615489,5.4679982013795);
        glVertex2f(24.648394516336,5.6348212554424);
        glVertex2f(24.9644803029814,5.8806657561666);
        glVertex2f(25.227885125186,6.1967515428121);
        glVertex2f(25.5264105903511,6.8201429553628);
        glVertex2f(25.579091554792,7.1889097064492);
        glVertex2f(25.5351907510913,7.698159029378);
        glVertex2f(25.3332470540678,8.1810678700863);
        glVertex2f(25.1225231963042,8.5410544604325);
        glVertex2f(24.7537564452178,8.8747005685583);
        glVertex2f(24.3849896941315,9.0766442655817);
        glVertex2f(24.0425634252656,9.1644458729833);
        glVertex2f(23.954761817864,8.2249686737871);
    glEnd();
    glPopMatrix();

    ///"Game O(v)er"
    glPushMatrix();
    glTranslatef(-3.2,-3.8,0);
    glScalef(1.9,2,0);
    glBegin(GL_POLYGON);
        glVertex2f(15.5,6.5);
        glVertex2f(16.4238857528174,4.5594386346839);
        glVertex2f(17.2992360721822,6.5155786340808);
    glEnd();
    glPopMatrix();

    ///"Game Ov(e)r"
    glPushMatrix();
    glTranslatef(12,-2.7,0);
    glScaled(1.79,1.79,0);
    glBegin(GL_POLYGON);
        glVertex2f(10.6383425302498,6.7116297468638);
        glVertex2f(10.5519674204202,5.2926100853776);
        glVertex2f(10.1200918712722,4.7866987278043);
        glVertex2f(9.9843595558257,4.9039220911444);
        glVertex2f(9.8547968910813,5.1445384685269);
        glVertex2f(9.7931003840602,5.3728155445051);
        glVertex2f(9.780761082656,5.6812980796108);
        glVertex2f(9.7931003840602,5.9897806147165);
        glVertex2f(9.8856451445919,6.2303969920989);
        glVertex2f(10.0454900979094,6.4769268685567);
        glVertex2f(10.2797422435546,6.6665595578886);
        glVertex2f(10.4582200688081,6.7148973022281);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(10.5635802519535,6.7193651580337);
        glVertex2f(10.6550803231684,5.3834641182963);
        glVertex2f(11.271180802682,5.371264108801);
        glVertex2f(11.3870808928875,5.5969642844644);
        glVertex2f(11.4358809308688,5.8470644791184);
        glVertex2f(11.4114809118781,6.0910646690248);
        glVertex2f(11.3443808596539,6.2984648304452);
        glVertex2f(11.2223807647007,6.5119649966133);
        glVertex2f(11.0271806127756,6.6461651010618);
        glVertex2f(10.8197804513552,6.7071651485384);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(10.5519674204202,5.2926100853776);
        glVertex2f(10.0778574226888,4.8137973886809);
        glVertex2f(10.2597386366121,4.6375999626927);
        glVertex2f(10.5,4.5);
        glVertex2f(10.7201254593556,4.4500349608342);
        glVertex2f(10.9076904612141,4.9161055715128);
        glVertex2f(10.7485443990312,4.984311026734);
        glVertex2f(10.6235010644589,5.1377733009819);
    glEnd();
    glPopMatrix();

    ///"Game Ove(r)"
    glPushMatrix();
    glTranslatef(15.8,0,0);
    glBegin(GL_QUADS);
        glVertex2f(17.1235540766078,5.5423030226511);
        glVertex2f(17,9);
        glVertex2f(18.3305083987976,9.1293261484114);
        glVertex2f(18.1274693539432,5.5423030226511);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(18.1658451919647,8.7575181250593);
        glVertex2f(18.3984014981569,8.9771546364631);
        glVertex2f(18.656797393926,9.1063525843476);
        glVertex2f(19.0702308271565,9.0417536104053);
        glVertex2f(19.3221668255314,8.8221170990016);
        glVertex2f(19.4319850812333,8.3699242814057);
        glVertex2f(19.3803059020795,7.9952502325405);
        glVertex2f(19.2123485698295,7.782073618531);
        glVertex2f(18.8505943157528,7.6076563888869);
        glVertex2f(18.4565405747049,7.5818167993099);
        glVertex2f(18.3208827294262,7.6141162862811);
        glVertex2f(18.1400056023878,8.2601060257038);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}
void title2(){
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(.2,.2,0);
        titlex();
    glPopMatrix();
    glPushMatrix();
        glColor3f(1,1,1);
        titlex();
    glPopMatrix();
}
void tutorial(){
    glBegin(GL_POLYGON);
        glVertex2f(7.2237819372358,16.9825869495502);
        glVertex2f(7.2928915848329,17.1942623679574);
        glVertex2f(7.3859653200657,17.3131899185329);
        glVertex2f(7.5100636337095,17.4372882321768);
        glVertex2f(7.716894156449,17.5200204412728);
        glVertex2f(13.7940572898796,17.5337654380814);
        glVertex2f(13.9640294059645,17.4540566926344);
        glVertex2f(14.124177510237,17.3276239787348);
        glVertex2f(14.2506102241363,17.1843335696487);
        glVertex2f(14.3208506207471,17.0129470019182);
        glVertex2f(14.3219623019878,14.0597637733873);
        glVertex2f(14.2367628457593,13.905339758973);
        glVertex2f(14.1409134575024,13.7402658125302);
        glVertex2f(13.9811644770741,13.607141662173);
        glVertex2f(13.7575159044744,13.5006423418873);
        glVertex2f(7.734240631743,13.5229538354256);
        glVertex2f(7.5237747829337,13.6135978698309);
        glVertex2f(7.4093793135121,13.7279933392527);
        glVertex2f(7.2778245236772,13.8824272229721);
        glVertex2f(7.1977476950821,14.0883390679313);
    glEnd();

    //CREDIT
    glPushMatrix();
    glTranslatef(0,0.1,0);
    glPushMatrix();
	glColor3f(0,0,0);
	drawText(8, 15, "   ABOUT");
	glPopMatrix();
	glPopMatrix();


}
void tombolPlay(){

    glBegin(GL_POLYGON);
        glVertex2f(7.2237819372358,16.9825869495502);
        glVertex2f(7.2928915848329,17.1942623679574);
        glVertex2f(7.3859653200657,17.3131899185329);
        glVertex2f(7.5100636337095,17.4372882321768);
        glVertex2f(7.716894156449,17.5200204412728);
        glVertex2f(13.7940572898796,17.5337654380814);
        glVertex2f(13.9640294059645,17.4540566926344);
        glVertex2f(14.124177510237,17.3276239787348);
        glVertex2f(14.2506102241363,17.1843335696487);
        glVertex2f(14.3208506207471,17.0129470019182);
        glVertex2f(14.3219623019878,14.0597637733873);
        glVertex2f(14.2367628457593,13.905339758973);
        glVertex2f(14.1409134575024,13.7402658125302);
        glVertex2f(13.9811644770741,13.607141662173);
        glVertex2f(13.7575159044744,13.5006423418873);
        glVertex2f(7.734240631743,13.5229538354256);
        glVertex2f(7.5237747829337,13.6135978698309);
        glVertex2f(7.4093793135121,13.7279933392527);
        glVertex2f(7.2778245236772,13.8824272229721);
        glVertex2f(7.1977476950821,14.0883390679313);
    glEnd();

    //SEGITIGA
    glColor3f(0.1,1,0.4);
    glBegin(GL_POLYGON);
        glVertex2f(10.4083433737124,16.2012621759427);
        glColor3f(0,0.50,0.17);
        glVertex2f(10.3955396644974,14.792854162296);
        glVertex2f(11.5350697846279,15.5098618783343);
    glEnd();
    }
void scoreGameOver(){
///BG SCORE
	glPushMatrix();
    glBegin(GL_POLYGON);
        glVertex2f(7.2237819372358,16.9825869495502);
        glVertex2f(7.2928915848329,17.1942623679574);
        glVertex2f(7.3859653200657,17.3131899185329);
        glVertex2f(7.5100636337095,17.4372882321768);
        glVertex2f(7.716894156449,17.5200204412728);
        glVertex2f(13.7940572898796,17.5337654380814);
        glVertex2f(13.9640294059645,17.4540566926344);
        glVertex2f(14.124177510237,17.3276239787348);
        glVertex2f(14.2506102241363,17.1843335696487);
        glVertex2f(14.3208506207471,17.0129470019182);
        glVertex2f(14.3219623019878,14.0597637733873);
        glVertex2f(14.2367628457593,13.905339758973);
        glVertex2f(14.1409134575024,13.7402658125302);
        glVertex2f(13.9811644770741,13.607141662173);
        glVertex2f(13.7575159044744,13.5006423418873);
        glVertex2f(7.734240631743,13.5229538354256);
        glVertex2f(7.5237747829337,13.6135978698309);
        glVertex2f(7.4093793135121,13.7279933392527);
        glVertex2f(7.2778245236772,13.8824272229721);
        glVertex2f(7.1977476950821,14.0883390679313);
    glEnd();
	glPopMatrix();
}
void perintah(){
    glPushMatrix();
        glTranslatef(2.2,-7.5,0);
        glColor3f(0,0.7,0.2);
        scoreGameOver();
	glPopMatrix();
	glPushMatrix();
        glTranslatef(1.8,-7.7,0);
        glColor3f(0,0.8,0.211);
        scoreGameOver();
	glPopMatrix();
}
void perintah1(){
    glPushMatrix();
        glTranslatef(2.2,-7.5,0);
        glColor3f(0.7,0,0.19);
        scoreGameOver();
	glPopMatrix();
	glPushMatrix();
        glTranslatef(1.8,-7.7,0);
        glColor3f(0.8,0,0.211);
        scoreGameOver();
	glPopMatrix();
}

void nilai(){
    glPushMatrix();
	glColor3f(1,1,1);
	drawText(2, 32, "Score : ");
	drawText(8, 32, cetakScore);
	glPopMatrix();
}
void gameOver(){
    glClear(GL_COLOR_BUFFER_BIT);
    ///BG
    glPushMatrix();
    glBegin(GL_QUADS);
        glColor3f(1,1,0);
        glVertex2f(0,0);
        glColor3f(0,1,1);
        glVertex2f(54,0);
        glColor3f(0,1,0);
        glVertex2f(54,36);
        glColor3f(0,0,1);
        glVertex2f(0,36);
    glEnd();
    glPopMatrix();

    ///BG SCORE SHADOW
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(7.7,-.3,0);
        glScalef(1.8,1.2,0);
        scoreGameOver();
    glPopMatrix();
    ///BG SCORE
    glPushMatrix();
        glColor3f(1,1,1);
        glTranslatef(7.5,-.5,0);
        glScalef(1.8,1.2,0);
        scoreGameOver();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,-10,0);
        glScaled(kelapKelip1[1]+1,kelapKelip1[1]+1,0);
        glColor3f(0,0,0);
        drawText(23, 28, "Score Anda : ");
        drawText(30, 28, cetakScore);
	glPopMatrix();

    ///TEXT GAME OVER
	title2();

	///BG ULANG


	glPushMatrix();
	glTranslatef(26,0,0);
        perintah1();
	glPopMatrix();

    ///TEXT ULANG
    glPushMatrix();
    glTranslatef(1,0,0);
	glPushMatrix();
        perintah();
        glColor3f(1,1,1);
        drawText1(11, 8, "Tekan 'R'");
        drawText1(10, 7, "untuk RESTART");
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
        glColor3f(1,1,1);
        drawText1(37, 8, "Tekan 'E'");
        drawText1(36, 7, "   untuk EXIT");
	glPopMatrix();
    glFlush();

}
void home(){

    glClear(GL_COLOR_BUFFER_BIT);
    //BACKGROUND
    //Color1
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
        glVertex2f(0,0);
        glVertex2f(60,0);
        glVertex2f(60,40);
        //Color2
        glColor3f(0,0.031,0.36);
        glVertex2f(0,40);
        glVertex2f(0,0);
    glEnd();

    ///TARGET
    glPushMatrix();
    glTranslatef(0, target1[5], 0);
    target();
    glPopMatrix();

    ///BOW(atas||bawah)
    glPushMatrix();
    glTranslatef(0,bow1[5],0);
    bow();
    glPopMatrix();

    ///DYNAMITE
    glPushMatrix();
    dynamiteBanyak();
    glPopMatrix();

    ///ARROW
    glPushMatrix();
    glTranslatef(0,0,0);
    glPushMatrix();
    glTranslatef(arrow1[4], arrow1[12], 0);
    arrow();
    glPopMatrix();
    glPopMatrix();

    ///BINTANG
    semuaStar();
    star();

    ///SCORE
    nilai();

    glFlush();
}
void creditGame(){
    glClear(GL_COLOR_BUFFER_BIT);
    ///BG
    glPushMatrix();
    glBegin(GL_QUADS);
        glColor3f(0,1,1);
        glVertex2f(0,0);
        glColor3f(0,1,0);
        glVertex2f(54,0);
        glColor3f(1,1,0);
        glVertex2f(54,36);
        glColor3f(0,0,1);
        glVertex2f(0,36);
    glEnd();
    glPopMatrix();

    ///TEXT
    glPushMatrix();
    glTranslatef(0,20,0);
    glPushMatrix();
        glColor3f(1,1,1);
        drawText(10, 11, "ABOUT");
        drawText(10, 8, "Ga'Arrow merupakan game bertema sport, yaitu panahan.");
        drawText(10, 6, "kalian dapat mengumpulkan score sebanyak-banyaknya");
        drawText(10, 4,"dengan cara menambakkan anak panah ke target bergerak (disisi kanan layar)");
        drawText(10, 2,"score akan bertambah (+10) jika anak panah mengenai target.");
        drawText(10, 0,"namun apabila anak panah mengenai bom, maka permainan selesai.");

        drawText(10, -4, "KELOMPOK");
        drawText(10, -7,    "1. Ahmad Lukman Maulana");
        drawText(10, -9,    "2. Agill Fajar Prismadika");
        drawText(10, -11,   "3. Ardi Sugondo");
        drawText(10, -13,   "4. Witsudi Anasrullah");
        drawText(25, -7,    "182410103015");
        drawText(25, -9,    "182410103016");
        drawText(25, -11,   "182410103024");
        drawText(25, -13,   "182410103062");


	glPopMatrix();
	glPushMatrix();
        glTranslatef(kelapKelip1[1]*50,kelapKelip1[1]*50,0);
        glColor3f(0,0,0);
        drawText1(10, -17,   "Tekan 'K' untuk KEMBALI");
    glPopMatrix();
	glPopMatrix();
	glFlush();
}
void introGame(){
    glClear(GL_COLOR_BUFFER_BIT);
    ///BG

    glPushMatrix();
    glBegin(GL_QUADS);
        glColor3f(1,1,0);
        glVertex2f(0,0);
        glColor3f(0,1,0);
        glVertex2f(54,0);
        glColor3f(0,0,1);
        glVertex2f(54,36);
        glColor3f(0,1,1);
        glVertex2f(0,36);
    glEnd();
    glPopMatrix();

    ///TITLE
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(9.2,16.2,0);
    title();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(9,16,0);
    title();
    glPopMatrix();

    ///TOMBOL-PLAY
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(9.2,-4.8,0);
    tombolPlay();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(9,-5,0);
    tombolPlay();
    glPopMatrix();

    ///TOMBOL-TUTORIAL
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(23.2,-4.8,0);
    tutorial();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(23,-5,0);
    tutorial();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(kelapKelip1[1]*50,kelapKelip1[1]*50,0);
        glColor3f(0,0,0);
        drawText1(16,7,"Tekan 'P' untuk PLAY");
        drawText1(30,7,"Tekan 'A' untuk ABOUT");
    glPopMatrix();




	glFlush();
}
void batasArrow(int bA){
        sprintf(cetakScore, "%d", score);
        if (arrow1[4]>50){
            arrow1[4] -= 51;
        }
        if (arrow1[4]>0){
            arrow1[4] += 1;
        } else {
            arrow1[12]=bow1[5];
        }

        //collision
        arrow1[6] = arrow1[0] + arrow1[4];//x1
        arrow1[7] = arrow1[1] + arrow1[4];//x2
        arrow1[8] = arrow1[2] + arrow1[5];//y1
        arrow1[9] = arrow1[3] + arrow1[5];//y2

        if (arrow1[7] <= target1[1] && arrow1[7] >= target1[1] && arrow1[9] >= target1[7] && arrow1[8] <= target1[8] )
			{
			    arrow1[4] = 0;
				score += 10;
			}

        glutPostRedisplay();
        glutTimerFunc(30,batasArrow,0);
    }
void batasDynamite(int bD){
    for (int i = 0; i < 6; i++) {
        if (dynamite1[i][5] < -25){
            dynamite1[i][5] += 45;
        }
        dynamite1[i][5] -= dynamite1[i][10];

        //collision
        dynamite1[i][6] = dynamite1[i][0] + dynamite1[i][4];//x1
        dynamite1[i][7] = dynamite1[i][1] + dynamite1[i][4];//x2
        dynamite1[i][8] = dynamite1[i][2] + dynamite1[i][5];//y1
        dynamite1[i][9] = dynamite1[i][3] + dynamite1[i][5];//y2

        if ((arrow1[6] <= dynamite1[i][6] && arrow1[7] >= dynamite1[i][6] &&
            arrow1[8] <= dynamite1[i][8] && arrow1[9] >= dynamite1[i][8])
            ||
            (arrow1[6] <= dynamite1[i][7] && arrow1[7] >= dynamite1[i][7] &&
            arrow1[8] <= dynamite1[i][9] && arrow1[9] >= dynamite1[i][9]))
			{
			    arrow1[4] = 0;
                glutDisplayFunc(gameOver);
			}
    }
    glutPostRedisplay();
    glutTimerFunc(30,batasDynamite,0);
}
void batasBow(int bB){
    bow1[8]=bow1[2]+bow1[5];
    bow1[7]=bow1[3]+bow1[5];
    if (bow1[8]+3 > ortho[3]){
        bow1[5]=-23;
    } else if(bow1[7]-3 < ortho[2]){
        bow1[5]=+19;
    }
    glutPostRedisplay();
    glutTimerFunc(10,batasBow,0);
}
void kelapKelip(int kK){
    kelapKelip1[0] += 1;
    if (kelapKelip1[0]>25){
            kelapKelip1[0]-=25;
        }
    if (kelapKelip1[0]>15){
            kelapKelip1[1]=0;
        } else {
            kelapKelip1[1]=1;
        }

    if (kelapKelip1[0]>7){
            kelapKelip1[2]=1;
        } else {
            kelapKelip1[2]=0;
        }
    if (kelapKelip1[0]>10){
            kelapKelip1[3]=0;
        } else {
            kelapKelip1[3]=1;
        }
    if (kelapKelip1[0]>3){
            kelapKelip1[4]=1;
        } else {
            kelapKelip1[4]=0;
        }
    glutPostRedisplay();
    glutTimerFunc(30,kelapKelip,0);
}
void timer(int t){
    if (target1[6]== 1){
        target1[5] += 0.5;
    } else {
        target1[5] -= 0.5;
    }
    target1[7]=target1[2]+target1[5];
    target1[8]=target1[3]+target1[5];
    if (target1[8] >= ortho[3]) {
        target1[6]= 0;
    } else if(target1[7] <= ortho[2]){
        target1[6]= 1;
    }
    ///Numpang timer, ini buat warna score

    glutPostRedisplay();
    glutTimerFunc(30,timer,0);
}
void kontrol(int key, int z, int zz){

    switch(key){
        case GLUT_KEY_UP:
        bow1[5]+=1;
        break;

        case GLUT_KEY_DOWN:
        bow1[5]-=1;
        break;
    }
}
void keyboard(unsigned char key, int x, int xx){

    switch(key){
        case ' ':
        arrow1[4] += 1;
        break;

        case 'a':
        glutDisplayFunc(creditGame);
        break;

        case 'p':
        glutDisplayFunc(home);
        break;

        case 'k':
            if(creditGame){
                glutDisplayFunc(introGame);
            }

        break;

        case 'r':
        glutDisplayFunc(home);
        score = 0;
        break;

        case 'e':
        exit(1);
        }
}
int main(int argc, char ** argv) {
    // inisialisasi GLUT
    // glutInit(&argc, argv);
    // Mengatur mode tampilan
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Mengatur lebar dan tinggi tampilan
    glutInitWindowSize(900, 600);
    // Membuat jendela tampilan dengan judul yang diberikan
    glutCreateWindow("Ga-Arrow Games");
    // menjalankan prosedur inisialisasi
    init();
    // memanggil method display
    glutDisplayFunc(introGame);
    // kontroler
    glutSpecialFunc(kontrol);
    glutKeyboardUpFunc(keyboard);
    // mengulang fungsi
    gluOrtho2D(ortho[0], ortho[0],ortho[0], ortho[1] );
    glutTimerFunc(1,timer,0);
    glutTimerFunc(1,kelapKelip,0);
    glutTimerFunc(1,batasDynamite,0);
    glutTimerFunc(1,batasArrow,0);
    glutTimerFunc(1,batasBow,0);
    glutMainLoop();
    return 0;
}

