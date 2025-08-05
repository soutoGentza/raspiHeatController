# 🔥 ¡Controlador temperatura Raspberry Pi 3B+! 🔥

---

## **Detalles del proyecto**

### 1.Descripcion del proyecto
Este proyecto construye el binario temp_monitor a partir del cual se es capaz de leer la temperatura del procesador de una raspi 3B+ con el fin de activar un ventilador en caso de pasar un umbral establecido. Se utiliza el PIN 17 para el control de la salida GPIO


---

### 2.Criterio de desarrollo
El proyecto se ha desarrollado sobre arquitectura armv7l. Se puede apreciar como dentro del proyecto se crean diferentes dependencias para despues enlazarlas todas en la ultima fase de la compilacion. 


---

### 3.Instalacion
Para poder compilar el binario hay que seguir los siguientes pasos desde el dir raiz de proyecto:

| Pasos      | Comando      
|----------------|----------------
| Creacion de la carpeta build         | mkdir build         
| Ir a la carpeta build        | cd build         
| Preparar archivos compilacion        | cmake ..
| Compilar        | make

Es importante saber que el proyecto se ha desarrollado con las librerias y dependencias de raspberrypi 3B+ por lo que se recomienda compilar sobre una de éstas.