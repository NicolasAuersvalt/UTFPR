library(shiny)
ui <- fluidPage(
  numericInput("obs", "Margem de Erro :", 1, min = -100, max = 100),
  numericInput("obs2", "Valor de Confiança (%) :", 1, min = 0, max = 100),
  numericInput("obs3", "Desvio Padrão :", 1, min = 0.1, max = 1000),
  textOutput("value"),
  textOutput("value2"),
  textOutput("value3"),


)

server <- function(input, output) {

  output$value <- renderText({
    z <- abs(qnorm((1+(input$obs2/100)) / 2))
    TA <- (z*input$obs3/input$obs)^2
    paste("Tamanho da Amostra para Média: ", TA)
  })



}
shinyApp(ui, server)
