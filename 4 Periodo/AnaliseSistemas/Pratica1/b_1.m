a=[0.2, 0.6, 0.2]
b=[1,2,4,2] 

c0 = conv(a,b);
c1 = convolucao(a, b);

subplot(3,1,1);             
stem(c0, 'filled');
title('Convolução MatLab: a * b');
xlabel('n'); ylabel('c_0[n]');

subplot(3,1,2);             
stem(c1, 'filled');
title('Convolução Professor: a * b');
xlabel('n'); ylabel('c_1[n]');
ylim([-4 4]);
axis([0 6 0 4])