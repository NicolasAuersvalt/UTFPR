### 23 - Fazer uma classe *Aluno* que possua as seguintes características:
* dois atributos do tipo inteiro: primeira nota parcial (de 0 a 100) e Segunda nota parcial (de 0 a 100)
* um atributo *String* representando o nome do aluno
* possua métodos para ler e escrever os atributos (ou uma construtora)

Fazer uma classe *Turma* que possua as seguintes características:
* atributos: coleção de *Aluno* (vetor ou objeto da classe *ArrayList*), número de vagas e nome da turma (disciplina e código).

* métodos: *matricularAluno()*, que recebe um Aluno como parâmetro e o matricula na Turma se houver vaga; *cancelarAluno()*, que recebe um *Aluno* como parâmetro e cancela sua matrícula; *gerarRelatorio()*, que gera uma String contendo: média da turma, quantos alunos foram aprovados, quantos foram para a final e quantos foram reprovados e os códigos de todos os alunos cujas notas ficaram abaixo da média da turma

Fazer uma classe *Controle* que:
* pergunte ao usuário o nome da turma, número de vagas e instancie um novo objeto da classe *Turma*.
* em laço, pergunte ao usuário se quer matricular um novo aluno, cancelar um aluno já matriculado, mostrar relatório ou sair.
  * o caso queira matricular, pergunte ao usuário o nome e as duas notas parciais de um aluno. Caso o nome entrado seja “fim” isso significa que o usuário não quer inserir mais nenhum aluno, do contrário deve ser instanciado um objeto da classe *Aluno*, armazenados os dados digitados e matriculado na turma instanciada.
  * o caso queira cancelar, pergunte ao usuário o nome do aluno e cancela
  * a sua matrícula na turma instanciada.
  * o caso queira mostrar relatório, chamar o método correspondente na turma instanciada e mostrar o relatório gerado.
  * o caso queira sair, encerrar o programa.