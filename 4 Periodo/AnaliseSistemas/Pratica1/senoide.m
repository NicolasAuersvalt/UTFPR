
%% uso: senoide(vp, vn, f, fa)
%%
%% Plota uma onda senoidal de freq��ncia 'f' (Hz) , valor de pico
%%positivo 'vp' (V), valor de pico negativo 'vn' (V),
%%e freq��ncia de amostragem 'fa' (Hz).

function [Y]=senoide(vp, vn, f, fa)

	amostras=0:(fa-1); %vetor de amostragem COME�A EM ZERO

	amplitude=(vp-vn)/2; %calcula a amplitude do sinal

	Y0=(vp+vn)/2; %calcula o deslocamento do sinal em Y

 	Y=Y0+(amplitude*sin((2*pi*f*amostras)/fa)); %calcula onda senoidal

 	%plota gr�fico da sen�ide
% 	plot(amostras,Y);grid; title('onda senoidal');xlabel('n�mero da amostra');ylabel('amplitude(V)');

end

