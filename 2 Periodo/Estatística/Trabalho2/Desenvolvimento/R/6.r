library(shiny)
ui <- fluidPage(
  numericInput("obs", "Média :", 1, min = -1000, max = 1000),
  numericInput("obs2", "MO :", 1, min = -1000, max = 1000),
  numericInput("obs3", "Desvio Padrão :", 1, min = 0.1, max = 1000),
  numericInput("obs4", "Tamanho da amostra :", 1, min = 1, max = 1000),
  numericInput("obs5", "Valor Z :", 1, min = -6, max = 6),
  textOutput("value"),
  textOutput("value2"),
  textOutput("value3"),
  textOutput("value4"),
  textOutput("value5"),

)

server <- function(input, output) {

  output$value <- renderText({
    z=(input$obs-input$obs2)/(input$obs3/sqrt(input$obs4))
    res=if(abs(z)>abs(input$obs5))
    {
      "Reprovo Ho"
    }
    else
    {
      "Aceito Ho"
    }
    paste("Decisão: ", res)
  })


}
shinyApp(ui, server)
