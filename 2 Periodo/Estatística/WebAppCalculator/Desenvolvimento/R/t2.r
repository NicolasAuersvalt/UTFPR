library(shiny)
ui <- fluidPage(
		  numericInput("obs", "Média :", 1, min = -100, max = 100),
		    numericInput("obs2", "Valor z :", 1, min = -3, max = 3),
		    numericInput("obs3", "Desvio Padrão :", 1, min = 0.1, max = 1000),
		      numericInput("obs4", "Tamanho da amostra :", 1, min = 1, max = 1000),
		      textOutput("value"),
		        textOutput("value2"),
		        textOutput("value3"),
			  textOutput("value4")
			  #z=abs(qnorm(alpha/2))
			)

server <- function(input, output) {
	  output$value <- renderText({
		      LI <- (input$obs)-((input$obs2)*(input$obs3)/sqrt(input$obs4))
		          paste("Resultado:", LI)
		        })
  
  output$value2 <- renderText({
	      LS <- (input$obs)+((input$obs2)*(input$obs3)/sqrt(input$obs4))
	          paste("Resultado2:", LS)
	        })
    
}
shinyApp(ui, server)

