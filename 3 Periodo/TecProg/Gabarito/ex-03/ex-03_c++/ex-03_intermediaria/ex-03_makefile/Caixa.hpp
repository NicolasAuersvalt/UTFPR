#ifndef C_CAIXA
#define C_CAIXA

class Caixa
{
private:
  double largura, altura, profundidade;

public:
  // Construtora & Destrutora
  Caixa();
  Caixa(const double &largura, const double &altura, const double &profundidade);
  ~Caixa();
  // Setters
  void setLargura(const double &largura);
  void setAltura(const double &altura);
  void setProfundidade(const double &profundidade);
  // Getters
  const double &getLargura() const;
  const double &getAltura() const;
  const double &getProfundidade() const;
  // Funções
  double calcularAreaExt() const;
  double calcularVolume() const;
};

#endif