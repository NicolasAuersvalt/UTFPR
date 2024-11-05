#pragma once

class Ponto {
private:
    float x;
    float y;

public:
    Ponto(float x = 0.0, float y = 0.0);
    ~Ponto();

    void setPonto(float x, float y);
    float getX() const;
    float getY() const;
};
