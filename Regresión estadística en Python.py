'''Programa que realiza regresión estadística'''

from tkinter import *
import math
import random

#Definicion de funciones

#funcion para dibujar puntos
def punto (x, y, color):
    panel.create_oval(x,700-y,x,700-y,width=1, fill=color, outline=color)

#funcion para dibujar cruces
def cruz (x, y, color):
    panel.create_line((x+1)*5+51, 650-(y+1)*5, (x-1)*5+51, 650-(y-1)*5, fill=color,width=2)
    panel.create_line((x-1)*5+51, 650-(y+1)*5, (x+1)*5+51, 650-(y-1)*5, fill=color,width=2)
    
    #panel.create_line(170, 80, 150, 100, fill=color,width=5)

def crear_puntos (pares, funcion):
 
 if(funcion==1):

  a=0
  b=0.8
  c=5

  i=0
  while i<100:
   pares[i][0]=random.randint(0,190)
   pares[i][1]=b*pares[i][0]+c-2+random.randint(0,4)

   if 0<pares[i][0]*pares[i][1] and pares[i][0]<190 and pares[i][1]<125:
    i+=1
 
 if(funcion==2):

  a=-0.013
  b=2.3
  c=9.5

  i=0
  while i<100:
   pares[i][0]=random.randint(0,190)
   pares[i][1]=a*math.pow(pares[i][0],2)+b*pares[i][0]+c-2+random.randint(0,4)

   if 0<pares[i][0]*pares[i][1] and pares[i][0]<190 and pares[i][1]<125:
    i+=1

 if(funcion==3):

  a=0.0001
  
  i=0
  while i<100:
   pares[i][0]=random.randint(0,190)
   pares[i][1]=a*math.pow(pares[i][0],3)-1+random.randint(0,1)

   if 0<pares[i][0]*pares[i][1] and pares[i][0]<190 and pares[i][1]<125:
    i+=1

 if(funcion==4):
  
  a=700
     
  i=0
  while i<100:
   pares[i][0]=random.randint(1,190)
   pares[i][1]=a/pares[i][0]-3+random.randint(0,3)
   
   if 0<pares[i][0]*pares[i][1] and pares[i][0]<190 and pares[i][1]<125:
    i+=1

 if(funcion==5):
  
  a=7
     
  i=0
  while i<100:
   pares[i][0]=random.randint(1,190)
   pares[i][1]=a*math.sqrt(pares[i][0])-3+random.randint(0,3)
   
   if 0<pares[i][0]*pares[i][1] and pares[i][0]<190 and pares[i][1]<125:
    i+=1
 
 if(funcion==6):
  
  a=1.02
  b=5
     
  i=0
  while i<100:
   pares[i][0]=random.randint(1,190)
   pares[i][1]=b*math.pow(a,pares[i][0])-1+random.randint(0,2)
   
   if 0<pares[i][0]*pares[i][1] and pares[i][0]<190 and pares[i][1]<125:
    i+=1

 if(funcion==7):
  
  a=20
  b=10
     
  i=0
  while i<100:
   pares[i][0]=random.randint(1,190)
   pares[i][1]=a*math.log(pares[i][0])+b-3+random.randint(0,3)
   
   if 0<pares[i][0]*pares[i][1] and pares[i][0]<190 and pares[i][1]<125:
    i+=1

 if(funcion==8):
  
  a=10
  b=50
     
  i=0
  while i<100:
   pares[i][0]=random.randint(1,190)
   pares[i][1]=a*math.sin(pares[i][0])+b-3+random.randint(0,3)
   
   if 0<pares[i][0]*pares[i][1] and pares[i][0]<190 and pares[i][1]<125:
    i+=1

 if(funcion==9):
  
  a=2
  b=50
     
  i=0
  while i<100:
   pares[i][0]=random.randint(1,190)
   pares[i][1]=a*math.tan(pares[i][0])+b-3+random.randint(0,3)
   
   if 0<pares[i][0]*pares[i][1] and pares[i][0]<190 and pares[i][1]<125:
    i+=1

def encontrar_ecuacion (pares):
 
 #Lineal y Cuadrática
 x=0
 xx=0
 xxx=0
 xxxx=0
 y=0
 xy=0
 xxy=0
 error_minimo=0

 for i in range (100):
  x+=pares[i][0]
  xx+=math.pow(pares[i][0],2)
  xxx+=math.pow(pares[i][0],3)
  xxxx+=math.pow(pares[i][0],4)
  y+=pares[i][1]
  xy+=pares[i][0]*pares[i][1]
  xxy+=math.pow(pares[i][0],2)*pares[i][1]
 
 mejor_a=((xy*xxx-xx*xxy)*(100*xx-x*x)-(y*xx-x*xy)*(x*xxx-xx*xx))/((xxx*xxx-xx*xxxx)*(100*xx-x*x)-(xx*xx-x*xxx)*(x*xxx-xx*xx))
 mejor_b=((xxxx*xy-xxx*xxy)*(100*xxx-xx*x)-(xxx*y-xx*xy)*(x*xxxx-xxx*xx))/((xx*xxxx-xxx*xxx)*(100*xxx-xx*x)-(x*xxx-xx*xx)*(x*xxxx-xxx*xx))
 mejor_c=((xxxx*xy-xxx*xxy)*(x*xxx-xx*xx)-(xxx*y-xx*xy)*(xx*xxxx-xxx*xxx))/((x*xxxx-xxx*xx)*(x*xxx-xx*xx)-(100*xxx-xx*x)*(xx*xxxx-xxx*xxx))
 
 for i in range (100):
  error_minimo+=pow( (mejor_a*math.pow(pares[i][0],2)+mejor_b*pares[i][0]+mejor_c) - (pares[i][1]) ,2);
 ecuacion=2

 #Cúbica, Homográfica y Raíz cuadrada
 lnx=0
 lny=0
 lnxlnx=0
 lnxlny=0
 error=0
  
 for i in range (100):
  lnx+=math.log(pares[i][0])
  lny+=math.log(pares[i][1])
  lnxlnx+=pow(math.log(pares[i][0]),2)
  lnxlny+=math.log(pares[i][0])*math.log(pares[i][1])
     
 b=(100*lnxlny-lnx*lny)/(100*lnxlnx-math.pow(lnx,2))
 a=math.exp((lny-math.log(math.exp(b))*lnx)/100)
 
 for i in range (100):
  error+=math.pow( (a*math.pow(pares[i][0],b)) - (pares[i][1]) ,2)

 if error<error_minimo:
   error_minimo=error
   mejor_a=a
   mejor_b=b
   mejor_c=c
   ecuacion=3

 #Exponencial
 xlny=0
 x=0
 lny=0
 xx=0
 error=0

 for i in range (100): 
  xlny+=pares[i][0]*math.log(pares[i][1])
  x+=pares[i][0]
  lny+=math.log(pares[i][1])
  xx+=math.pow(pares[i][0],2)
 
 a=math.exp((100*xlny-x*lny)/(100*xx-math.pow(x,2)));
 b=math.exp((lny-math.log(a)*x)/100);
 
 for i in range (100): 
  error+=pow( (b*math.pow(a,pares[i][0])) - (pares[i][1]) ,2);

 if error<error_minimo:
   error_minimo=error
   mejor_a=a
   mejor_b=b
   mejor_c=c
   ecuacion=6

 #Logarítmica
 y=0
 lnxlnx=0
 ylnx=0
 lnx=0
 error=0

 for i in range (100): 
  y+=pares[i][1]
  lnxlnx+=math.pow(math.log(pares[i][0]),2)
  ylnx+=pares[i][1]*math.log(pares[i][0])
  lnx+=math.log(pares[i][0])
   
 a=(100*ylnx-y*lnx)/(100*lnxlnx-math.pow(lnx,2))
 b=(y-a*lnx)/100
 
 for i in range (100): 
  error+=pow( (a*math.log(pares[i][0])+b) - (pares[i][1]) ,2)
 
 if error<error_minimo:
  error_minimo=error
  mejor_a=a
  mejor_b=b
  mejor_c=c
  ecuacion=7

 #Seno
 senxsenx=0
 senx=0
 ysenx=0
 y=0
 error=0

 for i in range (100): 
  senxsenx+=math.pow(math.sin(pares[i][0]),2)
  senx+=math.sin(pares[i][0])
  ysenx+=pares[i][1]*math.sin(pares[i][0])
  y+=pares[i][1]
    
 a=(100*ysenx-senx*y)/(100*senxsenx-math.pow(senx,2))
 b=(y-a*senx)/100

 for i in range (100): 
  error+=pow( (a*math.sin(pares[i][0])+b) - (pares[i][1]) ,2)
 
 if error<error_minimo:
  error_minimo=error
  mejor_a=a
  mejor_b=b
  mejor_c=c
  ecuacion=8

 #Tangente
 tanxtanx=0
 tanx=0
 ytanx=0
 y=0
 error=0

 for i in range (100): 
  tanxtanx+=pow(math.tan(pares[i][0]),2)
  tanx+=math.tan(pares[i][0])
  ytanx+=pares[i][1]*math.tan(pares[i][0])
  y+=pares[i][1]
    
 a=(100*ytanx-tanx*y)/(100*tanxtanx-pow(tanx,2))
 b=(y-a*tanx)/100

 for i in range (100): 
  error+=pow( (a*math.tan(pares[i][0])+b) - (pares[i][1]) ,2)
 
 if error<error_minimo:
  error_minimo=error
  mejor_a=a
  mejor_b=b
  mejor_c=c
  ecuacion=9

 return ecuacion, mejor_a, mejor_b, mejor_c, error_minimo


def dibujar (pares, ecuacion, a, b, c, error):

 #Dibuja grilla
 for i in range (1024):
  punto(i,50,"green")
  if i%5==0:
   j=0
   while j<710:
    punto(i+50,j,"green")
    j+=50
 for i in range (750):
  punto(50,i,"green")
  if i%5==0:
   j=0
   while j<1001:
    punto(j,i+50,"green")
    j+=50

 #Escribe números de los ejes
 var = 10
 while var<200:
  panel.create_text(45+5*var,670, text= var,fill="white",font=('Verdana 12 bold'))
  if var<130:
   panel.create_text(30,651-5*var, text= var,fill="white",font=('Verdana 12 bold'))
  var+=10

 #Dibuja puntos
 for i in range(0, 100):
  cruz(pares[i][0],pares[i][1],"white")

 #Lineal y Cuadrática
 if ecuacion == 2:
  x=0
  while x<1000:
   y=a*math.pow(x,2)+b*x+c
   if y>0:
    punto((x+10)*5,(y+10)*5,"red")
   x+=0.1
 
  panel.create_text(140,70, text= "y =",fill="white",font=('Verdana 12 bold')) 
  panel.create_text(180,70, text= round(a,2),fill="white",font=('Verdana 12 bold'))
  panel.create_text(240,70, text= "*x^2 + ",fill="white",font=('Verdana 12 bold'))   
  panel.create_text(290,70, text= round(b,2),fill="white",font=('Verdana 12 bold'))   
  panel.create_text(340,70, text= "*x +",fill="white",font=('Verdana 12 bold'))  
  panel.create_text(390,70, text= round(c,2),fill="white",font=('Verdana 12 bold'))    
  panel.create_text(155,110, text= "error: ",fill="white",font=('Verdana 12 bold'))    
  panel.create_text(215,110, text= round(error,2),fill="white",font=('Verdana 12 bold'))    

 #Cúbica, Homográfica y Raíz cuadrada
 if ecuacion == 3:
  x=0.1
  while x<1000:
   if b<0:
    y=a*math.pow(1/x,-b)
   if b>0:
    y=a*math.pow(x,b)
   if y>0:
    punto((x+10)*5,(y+10)*5,"red")
   x+=0.01
  
  panel.create_text(140,70, text= "y =",fill="white",font=('Verdana 12 bold')) 
  panel.create_text(200,70, text= round(a,4),fill="white",font=('Verdana 12 bold'))
  panel.create_text(270,70, text= "*x^ ",fill="white",font=('Verdana 12 bold'))   
  panel.create_text(310,70, text= round(b,2),fill="white",font=('Verdana 12 bold'))   
  panel.create_text(155,110, text= "error: ",fill="white",font=('Verdana 12 bold'))    
  panel.create_text(222,110, text= round(error,2),fill="white",font=('Verdana 12 bold'))    

 #Exponencial
 if ecuacion == 6:
  x=0
  while x<1000:
   y=b*math.pow(a,x)
   if y>0:
    punto((x+10)*5,(y+10)*5,"red")
   x+=0.1
  
  panel.create_text(140,70, text= "y =",fill="white",font=('Verdana 12 bold')) 
  panel.create_text(200,70, text= round(b,4),fill="white",font=('Verdana 12 bold'))
  panel.create_text(270,70, text= "*x^ ",fill="white",font=('Verdana 12 bold'))   
  panel.create_text(310,70, text= round(a,2),fill="white",font=('Verdana 12 bold'))   
  panel.create_text(155,110, text= "error: ",fill="white",font=('Verdana 12 bold'))    
  panel.create_text(222,110, text= round(error,2),fill="white",font=('Verdana 12 bold'))    

 #Logarítmica
 if ecuacion == 7:
  x=0.1
  while x<1000:
   y=a*math.log(x)+b
   if y>0:
    punto((x+10)*5,(y+10)*5,"red")
   x+=0.01
  
  panel.create_text(140,70, text= "y =",fill="white",font=('Verdana 12 bold')) 
  panel.create_text(180,70, text= round(a,2),fill="white",font=('Verdana 12 bold'))
  panel.create_text(245,70, text= "*log(x)+ ",fill="white",font=('Verdana 12 bold'))   
  panel.create_text(300,70, text= round(b,2),fill="white",font=('Verdana 12 bold'))   
  panel.create_text(155,110, text= "error: ",fill="white",font=('Verdana 12 bold'))    
  panel.create_text(215,110, text= round(error,2),fill="white",font=('Verdana 12 bold')) 

 #Seno
 if ecuacion == 8:
  x=0.1
  while x<1000:
   y=a*math.sin(x)+b
   if y>0:
    punto((x+10)*5,(y+10)*5,"red")
   x+=0.01

  panel.create_text(140,70, text= "y =",fill="white",font=('Verdana 12 bold')) 
  panel.create_text(180,70, text= round(a,2),fill="white",font=('Verdana 12 bold'))
  panel.create_text(255,70, text= "* sen(x) + ",fill="white",font=('Verdana 12 bold'))   
  panel.create_text(330,70, text= round(b,2),fill="white",font=('Verdana 12 bold'))   
  panel.create_text(155,110, text= "error: ",fill="white",font=('Verdana 12 bold'))    
  panel.create_text(215,110, text= round(error,2),fill="white",font=('Verdana 12 bold')) 


 #Tangente
 if ecuacion == 9:
  x=0.1
  while x<1000:
   y=a*math.tan(x)+b
   if y>0:
    punto((x+10)*5,(y+10)*5,"red")
   x+=0.001

  panel.create_text(140,70, text= "y =",fill="white",font=('Verdana 12 bold')) 
  panel.create_text(180,70, text= round(a,2),fill="white",font=('Verdana 12 bold'))
  panel.create_text(255,70, text= " * tan(x) + ",fill="white",font=('Verdana 12 bold'))   
  panel.create_text(335,70, text= round(b,2),fill="white",font=('Verdana 12 bold'))   
  panel.create_text(153,110, text= "error: ",fill="white",font=('Verdana 12 bold'))    
  panel.create_text(215,110, text= round(error,2),fill="white",font=('Verdana 12 bold')) 

#Programa principal
pares = [[0]*2]*100

ventana=Tk()
ventana.title("")
ventana.geometry("1024x768")

panel=Canvas(width=1024, height=700, bg="black")
panel.pack()

for i in range(0, 100):
 pares[i]=[0,0]

a=0
b=0
c=0

#1: lineal, 2: cuadratica, 3: cúbica, 4: homográfica, # 5: raizcuadrada
# 6: exponencial, 7: logarítmica, 8: seno, 9: tangente

crear_puntos(pares, 1)
ecuacion, a, b, c, error = encontrar_ecuacion(pares)
dibujar(pares, ecuacion, a, b, c, error)

ventana.mainloop()