x1=senoide(2.5,-2.5,0.25,15); %cria 1/4 de ciclo de uma senoide (sinal emitido por radar)
x2=ruido(0,10,1000); %ruido com 1000 pontos
x3=x2;
for i=700:714
x3(i)=x3(i)+x1(i-699);
end

subplot(3,1,1)
plot(x2, 'b')
hold on
plot(x3,'r') %sinal recebido pelo radar

title('Sinal Gerado pelo Radar');
xlabel('n'); ylabel('c_0[n]');

grid;
hold off 

c = correlacao(x3,x1)
subplot(3,1,2)
plot(c);

title('Convolução entre x1 e x3');
xlabel('n'); ylabel('c_0[n]');