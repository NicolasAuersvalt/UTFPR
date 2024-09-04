library(shiny)

ui <- fluidPage(
  titlePanel("Regressão Linear Simples"),

  sidebarLayout(
    sidebarPanel(
      textInput("x_values", "Valores de x (separados por vírgula):", "1,2,3,4,5,6,7,8,9,10"),
      textInput("y_values", "Valores de y (separados por vírgula):", "3,7,8,12,14,15,20,22,25,30"),
      numericInput("obs", "Valor de x para previsão:", 1, min = -100, max = 100)
    ),

    mainPanel(
      textOutput("value"),
      plotOutput("plot")
    )
  )
)

server <- function(input, output) {
  output$value <- renderText({
    # Convertendo os valores de entrada de texto para vetores numéricos
    x <- as.numeric(unlist(strsplit(input$x_values, ",")))
    y <- as.numeric(unlist(strsplit(input$y_values, ",")))

    # Ajustando o modelo linear
    ajuste <- lm(y ~ x)
    previsto <- ajuste$coefficients[1] + ajuste$coefficients[2] * input$obs
    paste("Previsão:", round(previsto, 2))
  })

  output$plot <- renderPlot({
    x <- as.numeric(unlist(strsplit(input$x_values, ",")))
    y <- as.numeric(unlist(strsplit(input$y_values, ",")))

    ajuste <- lm(y ~ x)

    plot(x, y, main = "Regressão Linear", xlab = "x", ylab = "y", pch = 19)
    abline(ajuste, col = "blue", lwd = 2)
  })
}

shinyApp(ui, server)
