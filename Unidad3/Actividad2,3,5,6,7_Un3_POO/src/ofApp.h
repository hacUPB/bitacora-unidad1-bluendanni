#pragma once
#include "ofMain.h"
#include <vector>
// -------------------------------------------------
// Clase base abstracta: Particle
// -------------------------------------------------
class Particle {
public:
	virtual ~Particle() { }
	virtual void update(float dt) = 0;
	virtual void draw() = 0;
	virtual bool isDead() const = 0;
	// Nuevo método para saber si la partícula (tipo RisingParticle) debe explotar
	virtual bool shouldExplode() const { return false; }
	// Métodos para obtener posición y color, para usarlos en explosiones
	virtual glm::vec2 getPosition() const { return glm::vec2(0, 0); }
	virtual ofColor getColor() const { return ofColor(255); }
};
// -------------------------------------------------
// RisingParticle: Partícula que nace en la parte inferior central y sube
// -------------------------------------------------
class RisingParticle : public Particle {
protected:
	glm::vec2 position;
	glm::vec2 velocity;
	ofColor color;
	float lifetime;
	// tiempo máximo antes de explotar
	float age;
	bool exploded;

public:
	RisingParticle(const glm::vec2 & pos, const glm::vec2 & vel, const ofColor & col, float life)
		: position(pos)
		, velocity(vel)
		, color(col)
		, lifetime(life)
		, age(0)
		, exploded(false) { }
	void update(float dt) override {
		position += velocity * dt;
		age += dt;
		// Aumenta la desaceleración para dar sensación de recorrido largo
		velocity.y += 9.8f * dt * 8;
		// Condición de explosión: cuando la partícula alcanza aproximadamente el 15% de la altura
		float explosionThreshold = ofGetHeight() * 0.15 + ofRandom(-30, 30);
		if (position.y <= explosionThreshold || age >= lifetime) {
			exploded = true;
		}
	}
	void draw() override {
		ofSetColor(color);
		// Partícula más grande
		ofDrawCircle(position, 10);
	}
	bool isDead() const override { return exploded; }
	bool shouldExplode() const override { return exploded; }
	glm::vec2 getPosition() const override { return position; }
	ofColor getColor() const override { return color; }
};

// -------------------------------------------------
// ZigZagParticle: sube alternando su dirección
// horizontal
// -------------------------------------------------
class ZigZagParticle : public Particle {
private:
	glm::vec2 position;
	glm::vec2 velocity;
	ofColor color;

	float lifetime;
	float age;
	float directionTimer;

	bool exploded;

public:
	ZigZagParticle(
		const glm::vec2 & pos,
		const glm::vec2 & vel,
		const ofColor & col,
		float life)
		: position(pos)
		, velocity(vel)
		, color(col)
		, lifetime(life)
		, age(0)
		, directionTimer(0)
		, exploded(false) {
	}

	void update(float dt) override {
		position += velocity * dt;
		age += dt;
		directionTimer += dt;

		// Cambia la dirección horizontal
		// periódicamente.
		if (directionTimer >= 0.18f) {
			velocity.x *= -1;
			directionTimer = 0;
		}

		// Desaceleración vertical.
		velocity.y += 9.8f * dt * 7;

		float explosionThreshold = ofGetHeight() * 0.18f;

		if (position.y <= explosionThreshold || age >= lifetime) {
			exploded = true;
		}
	}

	void draw() override {
		ofSetColor(color);

		// Se dibuja como un triángulo para
		// diferenciarlo de RisingParticle.
		ofDrawTriangle(
			position.x,
			position.y - 10,

			position.x - 8,
			position.y + 8,

			position.x + 8,
			position.y + 8);
	}

	bool isDead() const override {
		return exploded;
	}

	bool shouldExplode() const override {
		return exploded;
	}

	glm::vec2 getPosition() const override {
		return position;
	}

	ofColor getColor() const override {
		return color;
	}
};

// -------------------------------------------------
// SpiralParticle: sube mientras gira alrededor
// de un punto central
// -------------------------------------------------
class SpiralParticle : public Particle {
private:
	glm::vec2 center;
	glm::vec2 position;

	ofColor color;

	float verticalSpeed;
	float angle;
	float radius;

	float lifetime;
	float age;

	bool exploded;

public:
	SpiralParticle(
		const glm::vec2 & pos,
		const ofColor & col,
		float life)
		: center(pos)
		, position(pos)
		, color(col)
		, verticalSpeed(-320.0f)
		, angle(0)
		, radius(5)
		, lifetime(life)
		, age(0)
		, exploded(false) {
	}

	void update(float dt) override {
		age += dt;

		// El centro de la espiral sube.
		center.y += verticalSpeed * dt;

		// Desaceleración vertical.
		verticalSpeed += 9.8f * dt * 5;

		// Actualiza el giro y el radio.
		angle += 10.0f * dt;
		radius += 15.0f * dt;

		// Calcula la posición alrededor del centro.
		position.x = center.x + cos(angle) * radius;

		position.y = center.y + sin(angle) * radius * 0.35f;

		float explosionThreshold = ofGetHeight() * 0.18f;

		if (center.y <= explosionThreshold || age >= lifetime) {
			exploded = true;
		}
	}

	void draw() override {
		ofSetColor(color);

		// Línea desde el centro hasta la partícula.
		ofDrawLine(center, position);

		// Partícula principal.
		ofDrawCircle(position, 7);
	}

	bool isDead() const override {
		return exploded;
	}

	bool shouldExplode() const override {
		return exploded;
	}

	glm::vec2 getPosition() const override {
		return position;
	}

	ofColor getColor() const override {
		return color;
	}
};





// -------------------------------------------------
// Clase base para explosiones: ExplosionParticle
// -------------------------------------------------
class ExplosionParticle : public Particle {
protected:
	glm::vec2 position;
	glm::vec2 velocity;
	ofColor color;
	float age;
	float lifetime;
	float size;
	// tamaño de la partícula de explosión
public:
	ExplosionParticle(const glm::vec2 & pos, const glm::vec2 & vel, const ofColor & col, float life, float sz)
		: position(pos)
		, velocity(vel)
		, color(col)
		, age(0)
		, lifetime(life)
		, size(sz) { }
	void update(float dt) override {
		position += velocity * dt;
		age += dt;
		float alpha = ofMap(age, 0, lifetime, 255, 0, true);
		color.a = alpha;
	}
	bool isDead() const override {
		return age >= lifetime;
	}
};
// -------------------------------------------------
// CircularExplosion: Explosión en patrón circular
// -------------------------------------------------
class CircularExplosion : public ExplosionParticle {
public:
	CircularExplosion(const glm::vec2 & pos, const ofColor & col)
		: ExplosionParticle(pos, glm::vec2(0, 0), col, 1.2f, ofRandom(16, 32)) {
		float angle = ofRandom(0, TWO_PI);
		float speed = ofRandom(80, 200);
		velocity = glm::vec2(cos(angle), sin(angle)) * speed;
	}
	void draw() override {
		ofSetColor(color);
		ofDrawCircle(position, size);
	}
};
// -------------------------------------------------
// RandomExplosion: Explosión con direcciones aleatorias
// -------------------------------------------------
class RandomExplosion : public ExplosionParticle {
public:
	RandomExplosion(const glm::vec2 & pos, const ofColor & col)
		: ExplosionParticle(pos, glm::vec2(0, 0), col, 1.5f, ofRandom(16, 32)) {
		velocity = glm::vec2(ofRandom(-200, 200), ofRandom(-200, 200));
	}
	void draw() override {
		ofSetColor(color);
		ofDrawRectangle(position.x, position.y, size, size);
	}
};
// -------------------------------------------------
// StarExplosion: Explosión en forma de estrella
// -------------------------------------------------
class StarExplosion : public ExplosionParticle {
public:
	StarExplosion(const glm::vec2 & pos, const ofColor & col)
		: ExplosionParticle(pos, glm::vec2(0, 0), col, 1.3f, ofRandom(20, 40)) {
		float angle = ofRandom(0, TWO_PI);
		float speed = ofRandom(90, 180);
		velocity = glm::vec2(cos(angle), sin(angle)) * speed;
	}
	void draw() override {
		ofSetColor(color);
		int rays = 5;
		float outerRadius = size;
		float innerRadius = size * 0.5;
		ofPushMatrix();
		ofTranslate(position);
		for (int i = 0; i < rays; i++) {
			float theta = ofMap(i, 0, rays, 0, TWO_PI);
			float xOuter = cos(theta) * outerRadius;
			float yOuter = sin(theta) * outerRadius;
			float xInner = cos(theta + PI / rays) * innerRadius;
			float yInner = sin(theta + PI / rays) * innerRadius;
			ofDrawLine(0, 0, xOuter, yOuter);
			ofDrawLine(xOuter, yOuter, xInner, yInner);
		}
		ofPopMatrix();
	}
};


// -------------------------------------------------
// CrossExplosion: explosión en forma de cruz
// -------------------------------------------------
class CrossExplosion : public ExplosionParticle {
public:
	CrossExplosion(
		const glm::vec2 & pos,
		const ofColor & col)
		: ExplosionParticle(
			  pos,
			  glm::vec2(0, 0),
			  col,
			  1.4f,
			  ofRandom(10, 20)) {

		int direction = static_cast<int>(ofRandom(4));

		float speed = ofRandom(100, 230);

		float spread = ofRandom(-25, 25);

		if (direction == 0) {
			// Derecha
			velocity = glm::vec2(speed, spread);
		} else if (direction == 1) {
			// Izquierda
			velocity = glm::vec2(-speed, spread);
		} else if (direction == 2) {
			// Abajo
			velocity = glm::vec2(spread, speed);
		} else {
			// Arriba
			velocity = glm::vec2(spread, -speed);
		}
	}

	void draw() override {
		ofSetColor(color);

		ofPushMatrix();
		ofTranslate(position);
		ofRotateDeg(45);

		ofDrawRectangle(
			-size / 2,
			-size / 2,
			size,
			size);

		ofPopMatrix();
	}
};



// -------------------------------------------------
// ofApp: Manejo de la escena y eventos
// -------------------------------------------------
class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
	void keyPressed(int key);
	std::vector<Particle *> particles;
	~ofApp();

private:
	void createRisingParticle();
	void createZigZagParticle();
	void createSpiralParticle();
};
