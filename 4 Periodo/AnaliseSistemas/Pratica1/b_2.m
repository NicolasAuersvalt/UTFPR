x1 = senoide(2.5, -2.5, 0.25, 15);  % cria 1/4 de ciclo de uma senoide (sinal emitido por radar)
x2 = ruido(0, 10, 1000);            % ruído com 1000 pontos
x3 = x2;

for i = 700:714
    x3(i) = x3(i) + x1(i - 699);
end

% Criando subplots
figure;

subplot(3,1,1);
plot(x1, 'g');
title('x1 (1/4 de ciclo de senoide)');
grid on;

subplot(3,1,2);
plot(x2, 'm');
title('x2 (ruído aleatório)');
grid on;

subplot(3,1,3);
plot(x2, 'b');
hold on;
plot(x3, 'r');
title('x3 (sinal da senoide injetado com o ruído)');
legend('x2 (ruído)', 'x3 (sinal recebido pelo radar)');
grid on;
hold off;
