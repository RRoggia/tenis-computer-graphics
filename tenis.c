#include <stdio.h>
#include <GL/glut.h> 

typedef struct PLayer {
        float lowerX;
        float lowerY;
        float lowerEdgeX;
        float lowerEdgeY;
        float upperEdgeX;
        float upperEdgeY;
        float upperX;
        float upperY;
        float width;

} PLayer;

typedef struct TenisBall {
    float x;
    float y;
    float speed;
} TenisBall;

TenisBall ball;
PLayer playerOne, playerIA;
GLUquadricObj *quadObj;

void drawFieldDimensions(void){
    //Oficial Dimensions by wikipedia:
    //heigth: 23,78 meters --> rounded up to 24 points
    //width: 10,97 meters --> rounded up to 12 points
    //color is green, but could change to brown to play saibro :p
    glBegin(GL_QUADS);
    glLineWidth(3.0f);
        glColor3f(0.0f, 1.0f, 0.1f);
        glVertex2f( 7, 13);
        glVertex2f( 7,-13);
        glVertex2f(-7,-13);
        glVertex2f(-7, 13);
    glEnd();
}

void drawFieldOutterLines(void){
    glColor3f(1.0f, 1.0f, 1.0f); 
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glVertex2f( 6, 12);
        glVertex2f( 6,-12);

        glVertex2f( 6,-12);
        glVertex2f(-6,-12);

        glVertex2f(-6, -12);
        glVertex2f(-6, 12);

        glVertex2f(-6, 12);
        glVertex2f( 6, 12);
    glEnd(); 
}

void drawFieldInnerLines(void){
    glColor3f(1.0f, 1.0f, 1.0f); 
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glVertex2f( 4, 12);
        glVertex2f( 4,-12);

        glVertex2f(-4, 12);
        glVertex2f(-4,-12);

    glEnd(); 
}

void drawTenisNet(void){
    glLineWidth(5.0f);
    glBegin(GL_LINES);
        glVertex2f( 6, 0);
        glVertex2f(-6, 0);
    glEnd(); 
}

void drawServeLines(void){
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glVertex2f( 0, 6);
        glVertex2f( 0,-6);

        glVertex2f( 4,-6);
        glVertex2f(-4,-6);

        glVertex2f( 4, 6);
        glVertex2f(-4, 6);
    glEnd();
}

void drawTenisField(void){

    drawFieldDimensions();

    drawFieldOutterLines();
    
    drawFieldInnerLines();

    drawTenisNet();
    
    drawServeLines();
}

void drawPlayerOne(void){
    glColor3f(1.0f, 0.0f, 0.0f); // vermelho
    glBegin(GL_POLYGON);
        glVertex2f(playerOne.lowerX, playerOne.lowerY);
        glVertex2f(playerOne.lowerEdgeX, playerOne.lowerEdgeY);
        glVertex2f(playerOne.upperEdgeX ,playerOne.upperEdgeY);
        glVertex2f(playerOne.upperX, playerOne.upperY);
        glVertex2f(playerOne.upperX + 1,playerOne.upperY);
        glVertex2f(playerOne.upperEdgeX + playerOne.width, playerOne.upperEdgeY);
        glVertex2f(playerOne.lowerEdgeX + playerOne.width ,playerOne.lowerEdgeY);
        glVertex2f(playerOne.lowerX +1 ,playerOne.lowerY);
    glEnd();
}

void drawPlayerAI(void){
    glColor3f(1.0f, 0.0f, 0.0f); // vermelho
    glBegin(GL_POLYGON);
        glVertex2f(playerIA.lowerX, playerIA.lowerY);
        glVertex2f(playerIA.lowerEdgeX, playerIA.lowerEdgeY);
        glVertex2f(playerIA.upperEdgeX ,playerIA.upperEdgeY);
        glVertex2f(playerIA.upperX, playerIA.upperY);
        glVertex2f(playerIA.upperX + 1,playerIA.upperY);
        glVertex2f(playerIA.upperEdgeX + playerIA.width, playerIA.upperEdgeY);
        glVertex2f(playerIA.lowerEdgeX + playerIA.width ,playerIA.lowerEdgeY);
        glVertex2f(playerIA.lowerX +1 ,playerIA.lowerY);
    glEnd();
}

void drawGame(void)
{
    glClear(GL_COLOR_BUFFER_BIT); 
    
    drawTenisField();

    drawPlayerOne();

    drawPlayerAI();

    glColor3f(0.5f, 0.5f, 0.5f);    
    glBegin(GL_TRIANGLES);
        glVertex2f(playerOne.upperX + 0.5, playerOne.upperY + 1.5);
        glVertex2f(playerOne.upperX, playerOne.upperY + 1);
        glVertex2f(playerOne.upperX + 1, playerOne.upperY + 1);
    glEnd();
    

    // reset ball and add point
    if(ball.x > 15 || ball.y > 15 || ball.x < -15 || ball.y < -15 ){
        printf("placar 0 a 0");
        ball.speed = 0;
        ball.x = 0;
        ball.y = -11;
    }

    
    //Translate ball trough map
    if ((ball.y <= playerOne.upperY && ball.y >= playerOne.lowerY) && (ball.x >= playerOne.lowerEdgeX && ball.x <= playerOne.lowerEdgeX + playerOne.width))
    {
        ball.speed =0.1;
    } else if (ball.y <= playerIA.upperY && ball.y >= playerIA.lowerY){
        ball.speed= -0.1;
    }
    
    ball.y += ball.speed;

    glPushMatrix();
        glTranslatef(ball.x,ball.y,0);
        gluDisk(quadObj, 0.0, 0.1, 100,100);
    glPopMatrix();

    glutSwapBuffers(); 
} 

void keyboardArrows(int key, int x, int y){ 
    float distance;

    if(key == GLUT_KEY_UP || key == GLUT_KEY_DOWN ){

        if(key == GLUT_KEY_UP) {
            if( playerOne.upperY + 1 < 0){
                distance =  1;
            }
        }
        if(key == GLUT_KEY_DOWN) {
            if( playerOne.lowerY - 1 > -13){
                distance = -1;
            }
        }
        playerOne.lowerY += distance;
        playerOne.lowerEdgeY += distance;
        playerOne.upperEdgeY += distance;
        playerOne.upperY += distance; 

    }    

    if(key == GLUT_KEY_LEFT || key == GLUT_KEY_RIGHT ){ 
        if(key == GLUT_KEY_LEFT){
            if(playerOne.lowerEdgeX -1 > -7){
                distance = -0.5;
            }
        }
        if(key == GLUT_KEY_RIGHT){
            if(playerOne.lowerEdgeX + playerOne.width + 1 < 7){
                distance = 0.5;
            }
        }

        playerOne.lowerX += distance;
        playerOne.lowerEdgeX += distance;
        playerOne.upperEdgeX += distance;
        playerOne.upperX += distance;
    }

} 


void keyboardLetter(unsigned char key, int x, int y){ 
    float distance;

    if(key == 'w' || key == 's' ){

        if(key == 'w') {
            if( playerIA.upperY + 1 < 13){
                distance =  1;
            }
        }
        if(key == 's') {
            if( playerIA.lowerY - 1 > 0){
                distance = -1;
            }
        }
        playerIA.lowerY += distance;
        playerIA.lowerEdgeY += distance;
        playerIA.upperEdgeY += distance;
        playerIA.upperY += distance; 

    }    

    if(key == 'a' || key == 'd' ){ 
        if(key == 'a'){
            if(playerIA.lowerEdgeX -1 > -7){
                distance = -0.5;
            }
        }
        if(key == 'd'){
            if(playerIA.lowerEdgeX + playerIA.width + 1 < 7){
                distance = 0.5;
            }
        }

        playerIA.lowerX += distance;
        playerIA.lowerEdgeX += distance;
        playerIA.upperEdgeX += distance;
        playerIA.upperX += distance;
    }

}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    gluOrtho2D(-15,15,-15,15);
}

void initializeBall(void){
    ball.x = 0;
    ball.y = -11;
    ball.speed = 0;
}

void initializePlayers(void){
    playerOne.lowerX = -0.5;
    playerOne.lowerY = -12.5;
    playerOne.lowerEdgeX = -0.7;
    playerOne.lowerEdgeY = -12.1;
    playerOne.upperEdgeX = -0.7;
    playerOne.upperEdgeY = -11.9;
    playerOne.upperX = -0.5;
    playerOne.upperY = -11.4;
    playerOne.width = 1.4;

    playerIA.upperY = 12.5;
    playerIA.upperX = -0.5;
    playerIA.upperEdgeY = 12.1;
    playerIA.upperEdgeX = -0.7;
    playerIA.lowerEdgeY = 11.9;
    playerIA.lowerEdgeX = -0.7;
    playerIA.lowerY = 11.4;
    playerIA.lowerX = -0.5;
    playerIA.width = 1.4;
}


void initialize(void){
    initializePlayers();
    initializeBall();
}

// Programa principal 

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Jogos Olimpicos - Tenis - Renan Roggia");
    initialize();
    quadObj = gluNewQuadric();

    glutDisplayFunc(drawGame);
    glutIdleFunc(drawGame);
    glutSpecialFunc(keyboardArrows);
    glutKeyboardFunc(keyboardLetter);
    Inicializa();
    glutMainLoop();
}
