i = 0:1000;
a = gerarSinal(i);

c1 = convolucao(a, load("fpa.txt"));
c2 = convolucao(a, load("fpb.txt"));


subplot(3,2,1); % Linha 1
plot(load("fpa.txt"));
title('Filtro A');

subplot(3,2,2); % Linha 2
plot(load("fpb.txt"));
title('Filtro B');

subplot(3,2,3); % Linha 1
plot(c1);
title('Resposta com Filtro A');

subplot(3,2,4); % Linha 2
plot(c2);
title('Resposta com Filtro B');

subplot(3,2,5); % Linha 1
plot(abs(fft(c1)));
title('FFT Filtro A');

subplot(3,2,6); % Linha 2
plot(abs(fft(c2)));
title('FFT Filtro B');