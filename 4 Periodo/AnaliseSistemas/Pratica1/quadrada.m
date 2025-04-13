%## uso: [Y]=quadrada(vp, vn, f, fa)
%##
%## Plota uma onda quadrada de freqüência 'f' (Hz) , valor de pico
%##positivo 'vp' (V), valor de pico negativo 'vn' (V), intervalo de
%##tempo 't' (s) e freqüência de amostragem 'fa' (Hz).

function [Y]=quadrada(vp, vn, f, fa)

	amostras=0:(fa-1); %#cria vetor de amostragem

	amplitude=(vp-vn)/2; %#calcula a amplitude do sinal

	Y0=(vp+vn)/2; %#calcula o deslocamento do sinal em Y

 	Y=Y0+(amplitude*sin((2*pi*f*amostras)/fa)); %#calcula onda senoidal
 	
 	%#transforma onda senoidal em onda quadrada
 	for i=1:fa
 		if(Y(i)<Y0)
 			Y(i)=vn;
 		else
 			Y(i)=vp;
        end%if;
    end%for;

end%function;