a=[0.2, 0.6, 0.2];
b=[ 1, 2, 4, 2];

c0 = conv(a,b);
c1 = convolucao(a, b);
c2 = correlacao(a, b);
c3 = correlacao(b, a);

subplot(3,1,1);             
stem(c0, 'filled');
title('Convolução: a * b');
xlabel('n'); ylabel('c_0[n]');

subplot(3,1,2);             
stem(c1, 'filled');
title('Convolução: a * b');
xlabel('n'); ylabel('c_1[n]');

subplot(3,1,3);         
stem(c2, 'filled');
title('Correlação: a com b');
xlabel('n'); ylabel('c_2[n]');
