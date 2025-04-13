x = zeros(1,1000);
for i = 1:1000
    x(i) = cos((2*pi*(i-1)/250) + cos(2*pi*(i-1)/25));
end
subplot(3,1,1)
plot(x);

axis([0 1000 -1.1 1.1])