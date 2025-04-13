function [y]=convolucao(h,x)
nx=length(x);
nh=length(h);
ny=nx+nh-1;
 for i=1:ny
 y(i)=0;
 for j=1:nh
 if((i-j+1)>0&&(i-j+1)<=nx)
 y(i)=y(i)+h(j)*x(i-j+1);
 end
 end
 end
end
