function [y] = correlacao(h, x)
    nx = length(x);
    nh = length(h);
    ny = nx + nh - 1;
    y = zeros(1, ny); % pré-alocação do vetor de saída
    
    for i = 1:ny
        for j = 1:nh
            if ((i + j - nh) > 0 && (i + j - nh) <= nx)
                y(i) = y(i) + h(j) * x(i + j - nh);
            end
        end
    end
end
