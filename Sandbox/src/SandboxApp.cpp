#include <Slurp.h>

class Sandbox : public Slurp::Application
{
public:
	Sandbox(): Application(), geometry(sf::Triangles, 3), movementSpeed(100.0f)
	{
		// set initial geometry position
		PointA = sf::Vector2f(1000.f, 650.f);
		PointB = sf::Vector2f(800.f, 600.f);
		PointC = sf::Vector2f(1000.f, 500.f);

		geometry[0].position = PointA;
		geometry[1].position = PointB;
		geometry[2].position = PointC;

		window->QueueDrawable(&geometry);
	}

	~Sandbox()
	{

	}

	// move geomtry with fixed time
	virtual void Update(double deltaTime)
	{
		// setup rotation angle and rotation center
		double moveAmount = movementSpeed * deltaTime;
		rotation.rotate(moveAmount, PointA);

		// apply rotation
		sf::Vector2f Point_BP = rotation.transformPoint(PointB);
		sf::Vector2f Point_CP = rotation.transformPoint(PointC);

		geometry[1].position = Point_BP;
		geometry[2].position = Point_CP;
	}

private:
	sf::Vector2f PointA;
	sf::Vector2f PointB;
	sf::Vector2f PointC;
	sf::VertexArray geometry;

	sf::Transform rotation;
	double movementSpeed;
};

Slurp::Application* Slurp::CreateApplication()
{
	return new Sandbox();
}