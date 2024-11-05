#include "stdinc.hpp"

#include "Email.hpp"

int main()
{
  // Criamos um objeto da classe Email
  Email meuEmail;
  // Utilizamos o setter para passar o texto do assunto
  meuEmail.setConteudoAssunto("Teste");
  // Utilizamos o método para enviar o texto da mensagem
  meuEmail.addTextoMensagem("Este é um email de teste. :D");
  // Chamamos a função mostrar dados para imprimir o assunto e mensagem
  meuEmail.mostraDados();

  return 0;
}