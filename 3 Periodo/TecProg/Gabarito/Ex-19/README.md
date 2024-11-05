### 19 - Fazer a classe Assunto:
* atributos: texto do assunto  
* métodos: *setTexto()* para definir o texto do assunto e *getTexto()* para retornar o assunto  
  
Fazer a classe *Mensagem*:
* atributos: texto da mensagem
* métodos: *addMensagem()* para adicionar ao texto da mensagem que já existe e *getMensagem()* para retornar o texto

Fazer uma classe *EMail* com as seguintes características:

* atributos: objetos das classes *Assunto* e *Mensagem* (por composição)
* métodos:
  * o *setConteudoAssunto()* para definir o conteúdo do assunto
  * o *addTextoMensagem()* para adicionar texto à mensagem.
  * o *mostraDados()* que mostra no console os dados do e-mail no seguinte formato:

    Assunto: xxxxx  
    Mensagem: xxxxxxxxxxxxxxxxxxxx  

Fazer uma classe principal que cria um *EMail*, preenche assunto e texto e
depois chama *mostraDados()* para mostrar os dados do e-mail