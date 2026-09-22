class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
	void keyPressed(int key);
	std::vector<Particle*> particles;
	~ofApp();
private:
	void createRisingParticle();
};