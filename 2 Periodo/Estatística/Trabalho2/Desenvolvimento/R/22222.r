# Carrega a biblioteca Shiny
library(shiny)

# Define a interface do usuário (UI) da aplicação
ui <- fluidPage(
  # Cria um campo de entrada numérico para o valor da proporção p com valor inicial 1 e intervalo de -100 a 100
  numericInput("obs", "p :", 1, min = -100, max = 100),

  # Cria um campo de entrada numérico para o "Valor de Confiança (%)" com valor inicial 1 e intervalo de 0 a 100
  numericInput("obs2", "Valor de Confiança (%) :", 1, min = 0, max = 100),

  # Cria um campo de entrada numérico para o "Tamanho da amostra" com valor inicial 1 e intervalo de 1 a 1000
  numericInput("obs3", "Tamanho da amostra :", 1, min = 1, max = 1000),

  # Define áreas de texto para exibir os resultados calculados
  textOutput("value"),    # Exibe o limite inferior
  textOutput("value2"),   # Exibe o limite superior
  textOutput("value3")    # Área para outro texto, mas não é usado no código atual
)

# Define a lógica do servidor para a aplicação
server <- function(input, output) {

  output$value <- renderText({
    
    # Calcula o valor z-score baseado no nível de confiança fornecido
    conf_level <- input$obs2 / 100
    z_prob <- (1 + conf_level) / 2
    z <- abs(qnorm(z_prob))

    # Calcula a variância da proporção
    p <- input$obs
    p_complement <- 1 - p
    variance <- p * p_complement / input$obs3

    # Calcula o limite inferior do intervalo de confiança
    error_margin <- z * sqrt(variance)
    LI <- p - error_margin

    # Cria o texto a ser exibido para o limite inferior
    paste("Limite inferior: ", LI)
    
  })

  output$value2 <- renderText({
    # Calcula o valor z-score baseado no nível de confiança fornecido
    conf_level <- input$obs2 / 100
    z_prob <- (1 + conf_level) / 2
    z <- abs(qnorm(z_prob))

    # Calcula a variância da proporção
    p <- input$obs
    p_complement <- 1 - p
    variance <- p * p_complement / input$obs3

    # Calcula o limite superior do intervalo de confiança
    error_margin <- z * sqrt(variance)
    LS <- p + error_margin

    # Cria o texto a ser exibido para o limite superior
    paste("Limite superior: ", LS)
  })

}

# Cria e executa a aplicação Shiny
shinyApp(ui, server)
