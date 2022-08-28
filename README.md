# Regresion-estadistica

Comparto un programa que terminé hace poco.

Recibe las coordenadas de 100 puntos y devuelve la ecuación (polinómica, racional, irracional, trigonométrica, exponencial y logarítmica) de la curva que mejor se ajusta (minimiza la suma de los cuadrados de las diferencias entre los valores buscados y obtenidos) junto al valor de su error cuadrático y su gráfica.

Use la función de error cuadrático por su capacidad para positivizar los errores (misma ponderación para excesos que para defectos), su derivabilidad (la función valor absoluto también positiviza los errores pero no es derivable en su punto mínimo por ser anguloso) y su simplicidad (es la de menor grado par de todas las funciones polinómicas).

Por esto el método se llama regresión estadística por mínimos cuadrados y fue desarrollado hace más de 200 años por los matemáticos Legendre y el legendario Gauss para realizar predicciones astronómicas. Con su aplicación Gauss consiguió reencontrar el planeta Ceres que se había perdido luego de ocultarse tras el Sol. La astronomía es como la astrología salvo que sus predicciones se cumplen.

Legendre y Gauss se basaron en el método para encontrar mínimos del célebre matemático aficionado Fermat. Método precursor de las derivadas desarrolladas luego por Leibniz y el brillante Newton. Y además se basaron en el método para resolver sistemas de ecuaciones lineales que ahora lleva el nombre de Gauss pero que en realidad ya había sido desarrollado antes también por Newton.

Sobre los hombros de estas brillantes mentes se pararon Werbos, Rumelhart, Hinton y Williams para crear hace menos de medio siglo el método del gradiente descendiente. Una variante del método newtoniano para encontrar ceros con derivación aplicada a la derivada de la función de error. Método ampliamente utilizado en inteligencia artificial para el aprendizaje supervisado de las modernas redes neuronales artificiales que se vuelven cada día más cotidianas.

Como dicen los expertos en inteligencia artificial Goodfellow, Bengio y Courville en su libro Aprendizaje profundo: “El aprendizaje automático o machine learning es esencialmente una forma de estadística aplicada”.

El programa lo escribí en dos de los lenguajes más populares del mundo (según los índices TIOBE y PYPL): C (utilizando las bibliotecas Winbgim y Math) y Python (utilizando las bibliotecas Tkinter y Math). Sus códigos fuente, subidos a GitHub, son libres para usarse, estudiarse, mejorarse y compartirse.
