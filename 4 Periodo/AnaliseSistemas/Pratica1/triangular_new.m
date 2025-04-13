%% uso: [Y]=triangular(vp, vn, f, fa)
%%
%% Plota uma onda triangular de freqüência 'f' (Hz) , valor de pico
%%positivo 'vp' (V), valor de pico negativo 'vn' (V), 
%%e freqüência de amostragem 'fa' (Hz).

function [Y]=triangular(vp, vn, f, fa)
t=1;
	amostras=1:(fa); %cria vetor de amostragem

	amplitude=(vp-vn)/2; %calcula a amplitude do sinal

	Y0=(vp+vn)/2; %calcula o deslocamento do sinal em Y

 	Y=Y0+(amplitude*sin((2*pi*f*amostras)/fa)); %calcula onda senoidal
plot(amostras,Y);
hold on
	%transforma onda senoidal em onda triangular; achando os pontos máximos
	%e mínimos da senóide e traçando retas ligando esses pontos
	maximo=1;
	minimo=1;
	for i=2:((t*fa)-1)
		if(Y(i)>Y(i-1)&&Y(i)>Y(i+1)| Y(i)==Y(i+1)|Y(i)==Y(i-1))
			maximo=i
			Y(minimo:maximo)=Y(minimo):(Y(maximo)-Y(minimo))/(maximo-minimo):Y(maximo);
		elseif(Y(i)<Y(i-1)&&Y(i)<Y(i+1)|Y(i)==Y(i+1)|Y(i)==Y(i-1))
			minimo=i
			Y(maximo:minimo)=Y(maximo):(Y(minimo)-Y(maximo))/(minimo-maximo):Y(minimo);
        end
    end
	maximo=t*fa;
	Y(minimo:maximo)=Y(minimo):(Y(maximo)-Y(minimo))/(maximo-minimo):Y(maximo);

 	
 	%plota gráfico da triangular
	plot(amostras,Y);grid;title('onda triangular');xlabel('número da amostra');ylabel('amplitude(V)');
hold off
end

