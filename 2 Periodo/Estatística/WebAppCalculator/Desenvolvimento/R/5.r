library(shiny)

x=seq(1,10,by=0.1)
y=3+4*x+rnorm(length(x),0,1)

ui <- fluidPage(
  numericInput("obs", "Valor x :", 1, min = -100, max = 100),
  textOutput("value"),

)

server <- function(input, output) {
  output$value <- renderText({
    ajuste=lm(y~x)
    previsto <- ajuste$coefficients[1]+ajuste$coefficients[2]*input$obs
    paste("Previsão:",previsto)
  })
}
shinyApp(ui, server)

