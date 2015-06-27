

#include <iostream>
#include <vector>
#include <GL/freeglut.h>
#include <math.h>

double height = 500.0, wide = 500.0;
float px = 0.0, py = 0.0;

void resize(int w, int h)
{

	glViewport(0, 0, w, h);
	glLoadIdentity();
	glOrtho(-w / 500.0, w / 500.0, -h / 500.0, h / 500.0, -1.0, 1.0);
}

void idle()
{
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		std::cout << "mouse" << std::endl;
		if (x == wide / 2.0)
			px = 0.0;
		else
			px = (x - (wide / 2.0)) / (wide / 2.0);

		if (y == height / 2.0)
			py = 0.0;
		else
			py = (-y + (height / 2.0)) / (height / 2.0);
	}
	std::cout << "px=" << px << " py=" << py << std::endl;

	glutPostRedisplay();
}

void visual()
{

	//バッファをカラーバッファでクリア
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0.0, 500.0, 500, 500.0);

	glPointSize(10);
	glColor3d(1.0, .0, 0.0);
	glBegin(GL_POINTS);
	glVertex2f(px, py);
	glEnd();

	// glViewport(0, 0, 50, 50);
	glLineWidth(1.0f);
	//四角
	glColor3d(1.0, .0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2d(-0.5, -0.5);
	glVertex2d(-0.5, 0.5);
	glVertex2d(0.5, 0.5);
	glVertex2d(0.5, -0.5);
	glEnd();

	glFlush();
}

int main(int argc, char *argv[])
{

	// glut及びopenglの環境を初期化引数にはmainの引数を直接渡す
	glutInit(&argc, argv);
	//ディスプレイモードの選択，GLUT_RGBAは色の指定をRGBで行えるようにする
	glutInitDisplayMode(GLUT_RGBA);

	// 00x00のピクセルのウィンドウ
	glutInitWindowSize(500, 500);
	//ウィンドウを開く．引数はウィンドウの名前
	glutCreateWindow("freeglut");

	//引数は開いたウィンドウ内に描画する関数へのポインタ，この関数内で描画をする
	glutDisplayFunc(visual);
	glutReshapeFunc(resize);
	glutMouseFunc(mouse);

	//塗りつぶす色を指定 ４つ目の引数は不透明度
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutIdleFunc(idle);
	//無限ループ
	glutMainLoop();

	return 0;
}
