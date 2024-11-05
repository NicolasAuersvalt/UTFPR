#include "stdinc.hpp"

#include "Universidade.hpp"

int main()
{

  // Criamos o objeto universidade
  Universidade uni;
  uni.setNome("UTFPR");

  // Adicionamos os departamentos à universidade
  Departamento dainf;
  dainf.setNome("DAINF");      // Colocamos o nome do departamento
  dainf.setUniversidade(&uni); // Fornecemos a universidade afiliada
  uni.addDepartamento(&dainf); // Adicionamos o departamento à universidade

  Departamento damat;
  damat.setNome("DAMAT");      // Colocamos o nome do departamento
  damat.setUniversidade(&uni); // Fornecemos a universidade afiliada
  uni.addDepartamento(&damat); // Adicionamos o departamento à universidade

  Departamento daeln;
  daeln.setNome("DAELN");      // Colocamos o nome do departamento
  daeln.setUniversidade(&uni); // Fornecemos a universidade afiliada
  uni.addDepartamento(&daeln); // Adicionamos o departamento à universidade

  Departamento dafis;
  dafis.setNome("DAFIS");      // Colocamos o nome do departamento
  dafis.setUniversidade(&uni); // Fornecemos a universidade afiliada
  uni.addDepartamento(&dafis); // Adicionamos o departamento à universidade

  // Finalmente imprimimos os departamentos associados à universidade
  uni.imprimeDepartamentos();

  return 0;
}