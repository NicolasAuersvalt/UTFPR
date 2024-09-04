    library(shiny)
ui <- fluidPage(
  numericInput("obs", "p :", 1, min = -100, max = 100),
  numericInput("obs2", "Valor de Confiança (%) :", 1, min = 0, max = 100),
  numericInput("obs3", "Tamanho da amostra :", 1, min = 1, max = 1000),
  textOutput("value"),
  textOutput("value2"),
  textOutput("value3"),

)

server <- function(input, output) {

  output$value <- renderText({
    z <- abs(qnorm((1+(input$obs2/100)) / 2))
    LI <- (input$obs)-((z)*sqrt(((input$obs)*(1-input$obs))/(input$obs3)))
    paste("Limite inferior: ", LI)
  })

  output$value2 <- renderText({
    z <- abs(qnorm((1+(input$obs2/100)) / 2))
    LS <- (input$obs)+((z)*sqrt(((input$obs)*(1-input$obs))/(input$obs3)))
    paste("Limite superior: ", LS)
  })

}
shinyApp(ui, server)
