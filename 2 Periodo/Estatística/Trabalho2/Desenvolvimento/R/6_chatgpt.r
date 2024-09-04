library(shiny)

ui <- fluidPage(
  numericInput("obs", "Média da amostra:", 1, min = -1000, max = 1000),
  numericInput("obs2", "Média Populacional (H0):", 1, min = -1000, max = 1000),
  numericInput("obs3", "Desvio Padrão da População:", 1, min = 0.1, max = 1000),
  numericInput("obs4", "Tamanho da amostra:", 1, min = 1, max = 1000),
  numericInput("obs5", "Valor crítico Z:", 1, min = -6, max = 6),
  textOutput("value"),
  textOutput("value2"),
  textOutput("value3")
)

server <- function(input, output) {

  output$value <- renderText({
    # Calculando o valor de z
    z <- (input$obs - input$obs2) / (input$obs3 / sqrt(input$obs4))
    z
  })

  output$value2 <- renderText({
    # Calculando o p-valor
    p_value <- 2 * (1 - pnorm(abs((input$obs - input$obs2) / (input$obs3 / sqrt(input$obs4)))))
    p_value
  })

  output$value3 <- renderText({
    # Verificando a decisão baseada em z e valor crítico Z
    z <- (input$obs - input$obs2) / (input$obs3 / sqrt(input$obs4))
    decisao <- if (abs(z) > abs(input$obs5)) {
      "Rejeita H0"
    } else {
      "Aceita H0"
    }
    paste("Decisão: ", decisao)
  })
}

shinyApp(ui, server)
