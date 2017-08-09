#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

const int SCREEN_W = 620;
const int SCREEN_H = 480;

class POINT {
	private:
		int x;
		int y;
	public:
		POINT() { x=0; y=0;}
	    POINT(int a, int b) { x=a; y=b;}
	    void setPoint(POINT a) {x = a.x; y = a.y;}
	    void setPoint(int a, int b) { x=a; y=b;}
	    void midPoint(POINT a, POINT b);
		void midPoint(POINT a);
		void putPoint();
};


#endif // TRIANGLE_H_INCLUDED
