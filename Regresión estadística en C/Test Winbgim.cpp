#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <winbgim.h>
#include <time.h>

void crear_puntos(float pares[2][100], int *funcion)
{
 float a,b,c;
 int i;
 
 srand(time(0));
 
 if(*funcion==1)
 {
  a=0;
  b=0.8;
  c=5;
 
  for(i=0;i<100;)
  {
   pares[0][i]=rand()%190;
   pares[1][i]=b*pares[0][i]+c-5+rand()%10;
   
   if(0<pares[0][i]*pares[1][i]&&pares[0][i]<190&&pares[1][i]<130) i++;
  }
 }
 
 if(*funcion==2)
 {
  a=-0.013;
  b=2.3;
  c=9.5;
 
  for(i=0;i<100;)
  {
   pares[0][i]=rand()%190;
   pares[1][i]=a*pow(pares[0][i],2)+b*pares[0][i]+c -5+rand()%10;
   
   if(0<pares[0][i]*pares[1][i]&&pares[0][i]<190&&pares[1][i]<130) i++;
  }
 }
 
 if(*funcion==3)
 {
  a=0.0001;
     
  for(i=0;i<100;)
  {
   pares[0][i]=rand()%190;
   pares[1][i]=a*pow(pares[0][i],3)-1+rand()%2;
   
   if(0<pares[0][i]*pares[1][i]&&pares[0][i]<190&&pares[1][i]<130) i++;
  }
 }
 
 if(*funcion==4)
 {
  a=700;
     
  for(i=0;i<100;)
  {
   pares[0][i]=rand()%190;
   pares[1][i]=a/pares[0][i]-3+rand()%3;
   
   if(0<pares[0][i]*pares[1][i]&&pares[0][i]<190&&pares[1][i]<130) i++;
  }
 }

 if(*funcion==5)
 {
  a=7;
     
  for(i=0;i<100;)
  {
   pares[0][i]=rand()%190;
   pares[1][i]=a*sqrt(pares[0][i])-3+rand()%3;
   
   if(0<pares[0][i]*pares[1][i]&&pares[0][i]<190&&pares[1][i]<130) i++;
  }
 }

 if(*funcion==6)
 {
  a=1.02;
  b=5;

  for(i=0;i<100;)
  {
   pares[0][i]=rand()%190;
   pares[1][i]=b*pow(a,pares[0][i])-5+rand()%10;
  
   if(0<pares[0][i]*pares[1][i]&&pares[0][i]<190&&pares[1][i]<130) i++;
  }
 }
 
 if(*funcion==7)
 {
  a=20;
  b=10;

  for(i=0;i<100;)
  {
   pares[0][i]=rand()%190;
   pares[1][i]=a*log(pares[0][i])+b-3+rand()%3;
  
   if(0<pares[0][i]*pares[1][i]&&pares[0][i]<190&&pares[1][i]<130) i++;
  }
 }
 
 if(*funcion==8)
 {
  a=10;
  b=50;

  for(i=0;i<100;)
  {
   pares[0][i]=rand()%190;
   pares[1][i]=a*sin(pares[0][i])+b-3+rand()%3;
  
   if(0<pares[0][i]*pares[1][i]&&pares[0][i]<190&&pares[1][i]<130) i++;
  }
 }
 
 if(*funcion==9)
 {
  a=2;
  b=50;

  for(i=0;i<100;)
  {
   pares[0][i]=rand()%190;
   pares[1][i]=a*tan(pares[0][i])+b-3+rand()%3;
  
   if(0<pares[0][i]*pares[1][i]&&pares[0][i]<190&&pares[1][i]<130) i++;
  } 
 }
}

void encontrar_ecuacion(float pares[2][100], int *ecuacion, float *a, float *b, float *c, float *error)
{
 int i;
 double x, xx, xxx, xxxx, y, xy, xxy, lnx, lnxlnx, xlny, lny, lnxlny, ylnx, senx, ysenx, senxsenx, tanxtanx, tanx, ytanx;
 float error_minimo=0, mejor_a, mejor_b, mejor_c;
  
 //Lineal y cuadrática
 x=0, xx=0, xxx=0, xxxx=0, y=0, xy=0, xxy=0;
   
 for(i=0;i<100;i++) 
 { 
  x+=pares[0][i];
  xx+=pow(pares[0][i],2);
  xxx+=pow(pares[0][i],3);
  xxxx+=pow(pares[0][i],4);
  y+=pares[1][i];
  xy+=pares[0][i]*pares[1][i];
  xxy+=pow(pares[0][i],2)*pares[1][i];
 }
  
 mejor_a=((xy*xxx-xx*xxy)*(100*xx-x*x)-(y*xx-x*xy)*(x*xxx-xx*xx))/((xxx*xxx-xx*xxxx)*(100*xx-x*x)-(xx*xx-x*xxx)*(x*xxx-xx*xx));
 mejor_b=((xxxx*xy-xxx*xxy)*(100*xxx-xx*x)-(xxx*y-xx*xy)*(x*xxxx-xxx*xx))/((xx*xxxx-xxx*xxx)*(100*xxx-xx*x)-(x*xxx-xx*xx)*(x*xxxx-xxx*xx));
 mejor_c=((xxxx*xy-xxx*xxy)*(x*xxx-xx*xx)-(xxx*y-xx*xy)*(xx*xxxx-xxx*xxx))/((x*xxxx-xxx*xx)*(x*xxx-xx*xx)-(100*xxx-xx*x)*(xx*xxxx-xxx*xxx));
 
 for(i=0;i<100;i++)
 error_minimo+=pow( (mejor_a*pow(pares[0][i],2)+mejor_b*pares[0][i]+mejor_c) - (pares[1][i]) ,2);
 *ecuacion=2;
 
 //Cúbica, Homográfica y Raíz cuadrada
 lnx=0, lny=0, lnxlnx=0,lnxlny=0, *error=0;
  
 for(i=0;i<100;i++) 
 {  
  lnx+=log(pares[0][i]);
  lny+=log(pares[1][i]);
  lnxlnx+=pow(log(pares[0][i]),2);
  lnxlny+=log(pares[0][i])*log(pares[1][i]);
 }
    
 *b=(100*lnxlny-lnx*lny)/(100*lnxlnx-pow(lnx,2));
 *a=exp((lny-log(exp(*b))*lnx)/100);

 for(i=0;i<100;i++)
 *error+=pow( (*a*pow(pares[0][i],*b)) - (pares[1][i]) ,2);
 if(*error<error_minimo) { error_minimo=*error; mejor_a=*a; mejor_b=*b; mejor_c=*c; *ecuacion=3; }
  
 //Exponencial
 xlny=0, x=0, lny=0, xx=0, *error=0;
  
 for(i=0;i<100;i++) 
 { 
  xlny+=pares[0][i]*log(pares[1][i]);
  x+=pares[0][i];
  lny+=log(pares[1][i]);
  xx+=pow(pares[0][i],2);
 }
    
 *a=exp((100*xlny-x*lny)/(100*xx-pow(x,2)));
 *b=exp((lny-log(*a)*x)/100);
 
 for(i=0;i<100;i++)
 *error+=pow( (*b*pow(*a,pares[0][i])) - (pares[1][i]) ,2);
 if(*error<error_minimo) { error_minimo=*error; mejor_a=*a; mejor_b=*b; mejor_c=*c; *ecuacion=6; }
 
 //Logarítmica
 y=0, lnxlnx=0, ylnx=0, lnx=0, *error=0;
    
 for(i=0;i<100;i++) 
 { 
  y+=pares[1][i];
  lnxlnx+=pow(log(pares[0][i]),2);
  ylnx+=pares[1][i]*log(pares[0][i]);
  lnx+=log(pares[0][i]);
 }
    
 *a=(100*ylnx-y*lnx)/(100*lnxlnx-pow(lnx,2));
 *b=(y-*a*lnx)/100;
 
 for(i=0;i<100;i++)
 *error+=pow( (*a*log(pares[0][i])+*b) - (pares[1][i]) ,2);
 if(*error<error_minimo) { error_minimo=*error; mejor_a=*a; mejor_b=*b; mejor_c=*c; *ecuacion=7; }
 
 //Seno 
 senxsenx=0, senx=0, ysenx=0, y=0, *error=0;
 
 for(i=0;i<100;i++)
 { 
  senxsenx+=pow(sin(pares[0][i]),2);
  senx+=sin(pares[0][i]);
  ysenx+=pares[1][i]*sin(pares[0][i]);
  y+=pares[1][i];
 }
    
 *a=(100*ysenx-senx*y)/(100*senxsenx-pow(senx,2));
 *b=(y-*a*senx)/100;
  
 for(i=0;i<100;i++)
 *error+=pow( (*a*sin(pares[0][i])+*b) - (pares[1][i]) ,2);
 if(*error<error_minimo) { error_minimo=*error; mejor_a=*a; mejor_b=*b; mejor_c=*c; *ecuacion=8; }
   
 //Tangente
 tanxtanx=0, tanx=0, ytanx=0, y=0, *error=0;
  
 for(i=0;i<100;i++)
 { 
  tanxtanx+=pow(tan(pares[0][i]),2);
  tanx+=tan(pares[0][i]);
  ytanx+=pares[1][i]*tan(pares[0][i]);
  y+=pares[1][i];
 }
    
 *a=(100*ytanx-tanx*y)/(100*tanxtanx-pow(tanx,2));
 *b=(y-*a*tanx)/100;
 
 for(i=0;i<100;i++)
 *error+=pow( (*a*tan(pares[0][i])+*b) - (pares[1][i]) ,2);
 if(*error<error_minimo) { error_minimo=*error; mejor_a=*a; mejor_b=*b; mejor_c=*c; *ecuacion=9; }
  
 *a=mejor_a; *b=mejor_b; *c=mejor_c;
 *error=error_minimo;
}

void imprimir_cruz(float cx, float cy)
{
 int x=0,y=0;

 cx=(cx+10)*5-5;
 cy=710-(cy+10)*5+5;

 for(x=0;x<=10;x++,y++)
 {
  putpixel(cx+x  ,cy+y-10,7);
  putpixel(cx+x  ,cy-y   ,7);
  putpixel(cx+x+1,cy+y-10,7);
  putpixel(cx+x+1,cy-y   ,7);
 }
 
 /* Colores de la función putpixel:
 0: Negro 1: Azul 2: Verde 3: Cian 4: Rojo 5: Magenta 6: Marrón 
 7: Gris claro 8: Gris oscuro 9: Azul claro 10: Verde claro 
 11: Cian claro 12: Rojo claro 13: Magenta claro 14: Amarillo 15: Blanco 
*/
}

void dibujar(float pares[2][100], int *funcion, float *a, float *b, float *c, float *error)
{
 int i, j;
 float x=0, y=0;
 char num[4], num1[10], num2[10], num3[10], ecuacion[30]; 

 settextstyle(8,0,2);
 strcpy(num," 10"); for(i=1;i<20;i++) { if(i==10) num[0]=49; num[1]=48+i%10; outtextxy(20+i*50,710-45,num); }
 strcpy(num," 00"); for(i=0;i<20;i++) { if(i==10) num[0]=49; num[1]=48+i%10; outtextxy(10,710-50-i*50,num); }
 for(i=0;i<1017;i++) { putpixel(50+i,660     ,10); if(i%5==0) for(j= 10;j<= 610;j=j+50) putpixel(50+i ,j,2); }
 for(i=0;i< 710;i++) { putpixel(50  ,710-50-i,10); if(i%5==0) for(j=100;j<=1000;j=j+50) putpixel(j,660-i,2); }

 for(i=0;i<100;i++) imprimir_cruz(pares[0][i],pares[1][i]); delay(500);
 strcpy(ecuacion,"y=");

 if(*funcion==1)
 {
  for(x=0;x<195;x=x+0.01) 
  { y=*b*x+*c; if(y>0) { putpixel(x*5+50,710-y*5-50,4); putpixel(x*5+51,710-y*5-51,4); putpixel(x*5+49,710-y*5-49,4); } }
      
  gcvt(*b,5,num1); strcat(ecuacion,num1); strcat(ecuacion,"x+"); gcvt(*c,5,num2); strcat(ecuacion,num2); outtextxy(550,45,ecuacion);
 }

 if(*funcion==2)
 {
  for(x=0;x<195;x=x+0.01) 
  { y=*a*pow(x,2)+*b*x+*c; if(y>0) { putpixel(x*5+50,710-y*5-50,4); putpixel(x*5+51,710-y*5-51,4); putpixel(x*5+49,710-y*5-49,4); } }
   
  gcvt(*a,5,num1); strcat(ecuacion,num1); strcat(ecuacion,"x^2+"); gcvt(*b,5,num2); strcat(ecuacion,num2); strcat(ecuacion,"x+"); gcvt(*c,5,num3); strcat(ecuacion,num3);
 }

 if(*funcion==3)
 {
  for(x=0;x<195;x=x+0.01) 
  { y=*a*pow(x,*b); if(y>0) { putpixel(x*5+50,710-y*5-50,4); putpixel(x*5+51,710-y*5-51,4); putpixel(x*5+49,710-y*5-49,4); } }
   
  gcvt(*a,5,num1); strcat(ecuacion,num1); strcat(ecuacion,"x^"); gcvt(*b,5,num2); strcat(ecuacion,num2);
 }

 if(*funcion==4)
 {
  for(x=0;x<195;x=x+0.01) 
  { y=*a*pow(x,*b); if(y>0) { putpixel(x*5+50,710-y*5-50,4); putpixel(x*5+51,710-y*5-51,4); putpixel(x*5+49,710-y*5-49,4); } }
   
  gcvt(*a,5,num1); strcat(ecuacion,num1); strcat(ecuacion,"/x");
 }

 if(*funcion==5)
 {
  for(x=0;x<195;x=x+0.01) 
  { y=*a*pow(x,*b); if(y>0) { putpixel(x*5+50,710-y*5-50,4); putpixel(x*5+51,710-y*5-51,4); putpixel(x*5+49,710-y*5-49,4); } }
   
  gcvt(*a,5,num1); strcat(ecuacion,num1); strcat(ecuacion,"*x^(1/2)");
 }

 if(*funcion==6)
 {
  for(x=0;x<195;x=x+0.01) 
  { y=*b*pow(*a,x); if(y>0) { putpixel(x*5+50,710-y*5-50,4); putpixel(x*5+51,710-y*5-51,4); putpixel(x*5+49,710-y*5-49,4); } }
 
  gcvt(*b,5,num1); strcat(ecuacion,num1); strcat(ecuacion,"*"); gcvt(*a,5,num2); strcat(ecuacion,num2); strcat(ecuacion,"^x");
 }
 
 if(*funcion==7)
 {
  
  for(x=0;x<195;x=x+0.01) 
  { y=*a*log(x)+*b; if(y>0) { putpixel(x*5+50,710-y*5-50,4); putpixel(x*5+51,710-y*5-51,4); putpixel(x*5+49,710-y*5-49,4); } }
 
  gcvt(*b,5,num1); strcat(ecuacion,num1); strcat(ecuacion,"*ln(x)+"); gcvt(*a,5,num2); strcat(ecuacion,num2);
 }
 
 if(*funcion==8)
 {
  for(x=0;x<195;x=x+0.01) 
  { y=*a*sin(x)+*b; if(y>0) { putpixel(x*5+50,710-y*5-50,4); putpixel(x*5+51,710-y*5-51,4); putpixel(x*5+49,710-y*5-49,4); } }
 
  gcvt(*b,5,num1); strcat(ecuacion,num1); strcat(ecuacion,"*sen(x)+"); gcvt(*a,5,num2); strcat(ecuacion,num2);
 }
 
 if(*funcion==9)
 {
  for(x=0;x<195;x=x+0.0001) 
  { y=*a*tan(x)+*b; if(y>0) { putpixel(x*5+50,710-y*5-50,4); putpixel(x*5+51,710-y*5-51,4); putpixel(x*5+49,710-y*5-49,4); } }
 
  gcvt(*b,5,num1); strcat(ecuacion,num1); strcat(ecuacion,"*tan(x)+"); gcvt(*a,5,num2); strcat(ecuacion,num2);
 }
 
 outtextxy(550,45,ecuacion); outtextxy(550,70,"error: "); gcvt(*error,5,num1); outtextxy(630,70,num1);
 delay(1000); cleardevice(); 
}

int main (void)
{
 float pares[2][100], a, b, c, error;
 int i, ecuacion; 
 //1: lineal, 2: cuadratica, 3: cúbica, 4: homográfica, 5: raizcuadrada, 6: exponencial, 7: logarítmica, 8: seno, 9: tangente
 
 initwindow(1017,710);
 
 for(i=1;i<10;i++)
 {
  crear_puntos(pares,&i);
  encontrar_ecuacion(pares,&ecuacion,&a,&b,&c,&error);
  dibujar(pares,&ecuacion,&a,&b,&c,&error);
 }

 closegraph();
}

