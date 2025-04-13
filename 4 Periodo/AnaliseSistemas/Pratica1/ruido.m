%% uso: [Y]=ruido(media, desvio, fa)
%% desvio padrão(sigma) é raiz quadrada da variância (v=sigma^2)
%% Plota ruido randômico com freqëncia de amostragem 'fa' (Hz) utilizando a técnica:
%%	Y[n]=rand+rand+...(12 vezes)

function [Y]=ruido(media, desvio,fa)
rng('shuffle') % Initialize the generator based on the current
% time, resulting in a different sequence of random numbers after
% each call to rng.(2semestre2023)
	amostras=0:(fa-1); %cria vetor de amostragem

 	for i=1:(fa)
 		Y(i)=0;
 		aux=0;
 		for j=1:12
 			Y(i)=Y(i)+rand;
        end
 		Y(i)=Y(i)/12;
 		for j=1:6
 			aux=aux+rand;
        end
 		Y(i)=Y(i)-(aux/6);
 		Y(i)=(Y(i)*desvio)+media;
    end
        end

