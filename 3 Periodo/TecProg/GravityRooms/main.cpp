#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Cube {
public:
    sf::RectangleShape shape;
    sf::Vector2f velocity;
    bool isJumping;
    bool isFalling;
    float moveSpeed;
    float gravity;

    Cube(float x, float y) {
        shape.setSize(sf::Vector2f(50.f, 50.f));
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(x, y);
        velocity = sf::Vector2f(0.f, 0.f);
        isJumping = false;
        isFalling = false;
        moveSpeed = 200.f;  // Velocidade de movimento horizontal
        gravity = 500.f;    // Aceleração de gravidade
    }

    void update(float deltaTime) {
        // Se o cubo estiver pulando, simula a redução da velocidade vertical
        if (isJumping) {
            velocity.y += gravity * deltaTime;  // Gravidade atuando após o pico do salto

            // Reduzindo a velocidade vertical até atingir o pico do pulo
            if (velocity.y < 0) {
                velocity.y += 100.f * deltaTime;  // Decremente a velocidade vertical (subida)
                if (velocity.y >= 0) {
                    velocity.y = 0;  // A velocidade vertical atinge zero no topo do pulo
                }
            }
        } else if (isFalling) {
            velocity.y += gravity * deltaTime;  // Continuar a aceleração para baixo (gravidade)
        }

        // Atualiza a posição com a velocidade
        shape.move(velocity * deltaTime);

        // Impede que o cubo saia da tela (limite inferior)
        if (shape.getPosition().y + shape.getSize().y > 600) {
            shape.setPosition(shape.getPosition().x, 600 - shape.getSize().y);
            velocity.y = 0;
            isJumping = false;
            isFalling = false;
        }
    }

    void jump() {
        if (!isJumping && !isFalling) {
            velocity.y = -400.f;  // Velocidade inicial do pulo
            isJumping = true;
        }
    }

    void moveLeft() {
        velocity.x = -moveSpeed;  // Movimento para a esquerda
    }

    void moveRight() {
        velocity.x = moveSpeed;  // Movimento para a direita
    }

    void stop() {
        velocity.x = 0;  // Para o movimento horizontal
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }

    // Verifica se o cubo está colidindo com uma plataforma
    bool checkCollisionWithPlatform(const sf::RectangleShape& platformShape) {
        return shape.getGlobalBounds().intersects(platformShape.getGlobalBounds());
    }

    void landOnPlatform(const sf::RectangleShape& platformShape) {
        if (checkCollisionWithPlatform(platformShape) && velocity.y > 0) {
            shape.setPosition(shape.getPosition().x, platformShape.getPosition().y - shape.getSize().y);
            velocity.y = 0;
            isJumping = false;
            isFalling = false;
        }
    }
};

class Platform {
public:
    sf::RectangleShape shape;

    Platform(float x, float y, float width, float height) {
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(sf::Color::Blue);
        shape.setPosition(x, y);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }
};

int main() {
    // Cria a janela do jogo
    sf::RenderWindow window(sf::VideoMode(800, 600), "GravityRooms");

    Cube cube(375.f, 300.f);  // Posição inicial do cubo
    Platform platform1(100.f, 500.f, 200.f, 20.f);  // Plataforma 1
    Platform platform2(400.f, 400.f, 200.f, 20.f);  // Plataforma 2
    Platform platform3(200.f, 300.f, 200.f, 20.f);  // Plataforma 3

    sf::Clock clock;  // Usado para calcular o tempo delta

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        sf::Event event;

        // Processamento de eventos
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Controle do cubo
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            cube.jump();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            cube.moveLeft();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            cube.moveRight();
        }
        else {
            cube.stop();
        }

        // Atualiza a lógica do cubo
        cube.update(deltaTime.asSeconds());

        // Verifica se o cubo colidiu com alguma plataforma
        cube.landOnPlatform(platform1.shape);
        cube.landOnPlatform(platform2.shape);
        cube.landOnPlatform(platform3.shape);

        // Limpa a tela
        window.clear();

        // Desenha os objetos
        platform1.draw(window);
        platform2.draw(window);
        platform3.draw(window);
        cube.draw(window);

        // Exibe a tela
        window.display();
    }

    return 0;
}
