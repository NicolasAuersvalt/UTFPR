library(shiny)
ui <- fluidPage(
  numericInput("obs", "Margem de Erro (%) :", 1, min = 0, max = 100),
  numericInput("obs2", "Valor de Confiança (%) :", 1, min = 0, max = 100),
  textOutput("value"),
  textOutput("value2"),

) tarde tarde tarde tarde tarde tarde tarde tarde tarde tarde tarde tarde tarde tarde tarde

server <- function(input, output) {

  output$value <- renderText({
    z <- abs(qnorm((1+(input$obs2/100)) / 2))
    TA <- ((z^2*(0.5)*(0.5))/(input$obs/100)^2)
    paste("Tamanho da Amostra para Proporção: ", TA)
  })



}
shinyApp(ui, server)
