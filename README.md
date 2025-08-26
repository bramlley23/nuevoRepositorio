# 📘 Manual Técnico - Sistema de Parqueo

## 📑 Índice
1. [Introducción](#introducción)
2. [Requisitos Técnicos](#requisitos-técnicos)
3. [Estructura del Proyecto](#estructura-del-proyecto)
4. [Componentes del Sistema](#componentes-del-sistema)
   - [1. Login.jsx](#1-loginjsx)
   - [2. Register.jsx](#2-registerjsx)
   - [3. DashBoardUsuario.jsx](#3-dashboardusuariojsx)
   - [4. ParkingLotApp.jsx](#4-parkinglotappjsx)
   - [5. RegistroSalida.jsx](#5-registrosalidajsx)
5. [Próximas Mejoras](#próximas-mejoras)

---

## Introducción
Este manual técnico documenta el sistema de **gestión de parqueo** desarrollado en **React** utilizando la librería **PrimeReact**.  
El sistema incluye funciones de autenticación, registro de usuarios, administración de parqueos y generación de recibos de salida.

---

## Requisitos Técnicos
- **Node.js** v16 o superior
- **npm** o **yarn**
- **React** 18+
- **PrimeReact** 10+
- **PrimeIcons**
- **PrimeFlex** (para grid y estilos)

Instalación de dependencias:

npm install primereact primeicons primeflex

## 1. Login.jsx

### Propósito
Componente encargado de gestionar el inicio de sesión de usuarios (administrador o usuario estándar) y redirigirlos al dashboard correspondiente.

### Dependencias
- React (`useState`, `useRef`)
- React Router DOM (`useNavigate`)
- PrimeReact (`Toast`)
- Hoja de estilos personalizada `login.css`

### Flujo de ejecución
1. El usuario ingresa credenciales.
2. Se valida:
   - Si `username = admin` y `password = 1234` → redirige a `/dashboard`.
   - Si `username = user` y `password = 1234` → redirige a `/dashboardUsuario`.
   - En cualquier otro caso muestra un error.
3. Se muestra feedback al usuario con `Toast` y `alert`.

### Estructura principal
- **Estados locales:**  
  - `username` → almacena el nombre de usuario.  
  - `password` → almacena la contraseña.  
- **Refs:**  
  - `toast` → referencia para mostrar notificaciones.  
- **Funciones:**  
  - `handleSubmit(e)` → gestiona la validación y navegación.  
- **Renderizado:**  
  - Formulario de inicio de sesión con campos `usuario` y `contraseña`.  
  - Botón de acceso.  
  - Enlace de registro.  

### Ejemplo de uso

# Usuario administrador
usuario: admin
contraseña: 1234
→ Redirige a /dashboard

# Usuario estándar
usuario: user
contraseña: 1234
→ Redirige a /dashboardUsuario

# Credenciales incorrectas
→ Muestra notificación de error

## 2. Register.jsx

### Propósito
Componente de **registro de usuario** que permite capturar datos personales, validar información (correo, contraseña, imagen) y confirmar la creación de una cuenta mediante mensajes emergentes.

### Dependencias
- React (`useState`, `useRef`, `Fragment`)
- PrimeReact:
  - `InputText` → entradas de texto
  - `Password` → entrada con validación de contraseñas
  - `Dropdown` → selección de género
  - `Button` → botones estilizados
  - `FileUpload` → subida de imágenes
  - `InputMask` → campo de teléfono con máscara
  - `Message` → mensajes de validación
  - `Toast` → notificaciones emergentes
- Hoja de estilos personalizada: `formularioRegistro.css`

### Flujo de ejecución
1. El usuario llena el formulario con:
   - Nombre, Apellido, Usuario
   - Género
   - Teléfono (con máscara `9999-9999`)
   - Correo electrónico (validación con RegEx)
   - Contraseña (validación de complejidad)
   - Imagen de la licencia (solo formatos de imagen, máx. 1MB)
2. Validaciones:
   - Si el correo no cumple el formato → se muestra error.
   - Si no se sube una fotografía → se bloquea el registro.
   - Si todo es correcto → se limpia el formulario.
3. Se muestra un mensaje de éxito con `Toast`.

### Estructura principal
- **Estados locales:**  
  - `nombre`, `apellido`, `usuario` → datos personales  
  - `genero` → selección desde un `Dropdown`  
  - `telefono` → validado con máscara  
  - `correo` → validado con expresión regular  
  - `password` → validación visual de fortaleza  
  - `fotografia` → archivo de imagen subido  
  - `errorEmail` → estado de validación del correo  

- **Refs:**  
  - `toast` → referencia para mostrar notificaciones  
  - `fileuploadRef` → referencia para manejar el `FileUpload`  

- **Funciones clave:**  
  - `validarEmail(email)` → valida formato de correo con RegEx.  
  - `handleCorreoChange(e)` → actualiza correo y valida formato.  
  - `handleRegister(e)` → ejecuta validaciones, registra usuario y limpia formulario.  
  - `encabezadoPersonalizado(options)` → personaliza la barra del `FileUpload`.  

### Ejemplo de uso

# Campos válidos:
Nombre: Juan
Apellido: Pérez
Usuario: juanperez
Género: Masculino
Teléfono: 1234-5678
Correo: juan@example.com
Contraseña: Segura123
Fotografía: licencia.jpg

→ Mensaje de éxito: "Usuario registrado correctamente"
→ Se limpian los campos del formulario

# Campos inválidos:
Correo: juan@com
→ Error: "Correo electrónico inválido"

Sin imagen cargada
→ Error: "Debe subir una imagen antes de continuar"

## 3. DashBoardUsuario.jsx

### Propósito
Componente que representa el **panel de control del usuario** en el sistema de parqueo.  
Permite registrar entradas y salidas, visualizar gráficos estadísticos sobre la ocupación de autos y la comparativa entre autos y motos, además de gestionar la sesión.

### Dependencias
- React (`useState`)
- React Router DOM (`useNavigate`)
- PrimeReact:
  - `Card` → contenedor de formularios y gráficos
  - `Chart` → visualización de datos en gráficos
  - `Button` → botones estilizados
- Estilos: `dashboard.css`
- Componentes internos:
  - `RegistroParqueo` → formulario de registro de entradas
  - `RegistroSalida` → formulario de registro de salidas
  - `Tarifas` → (importado, no utilizado en esta versión)
  - `NotificacionesMultasAdmin` → (importado, no utilizado en esta versión)

### Flujo de ejecución
1. El panel lateral (sidebar) muestra el menú con las siguientes opciones:
   - **Registrar Entrada** → despliega el formulario `RegistroParqueo`.
   - **Registrar Salida** → despliega el formulario `RegistroSalida`.
   - **Autos** → despliega gráfico de ocupación por día de la semana.
   - **Comparativa** → muestra gráfico de comparación entre autos y motos.
   - **Cerrar sesión** → limpia el estado y redirige al inicio de sesión (`/`).
2. Al seleccionar una opción:
   - Si es un formulario → se renderiza dentro de un `Card`.
   - Si es un gráfico → se renderiza un gráfico de barras (`Chart`).
3. Cuando el usuario presiona “Cerrar sesión” → vuelve a la pantalla de login.

### Estructura principal
- **Estado local:**  
  - `activeChart` → guarda la opción activa del menú (formulario o gráfico).
- **Funciones:**  
  - `handleLogout()` → resetea el estado y redirige al login.
- **Objeto `charts`:**  
  - `chart1` → Formulario `RegistroParqueo`.  
  - `chart2` → Formulario `RegistroSalida`.  
  - `chart5` → Gráfico de ocupación de autos por días de la semana.  
  - `chart6` → Gráfico comparativo de espacios disponibles entre autos y motos.  

### Ejemplo de uso

### Al hacer clic en "Registrar Entrada":
→ Se muestra el formulario RegistroParqueo

### Al hacer clic en "Autos":
→ Se muestra un gráfico de barras con ocupación de autos por día

### Al hacer clic en "Comparativa":
→ Se muestra un gráfico comparativo Autos/Motos

### Al hacer clic en "Cerrar sesión":
→ Se limpia el estado y se redirige a /

## 4. ParkingLotApp.jsx

### Propósito
Componente que representa el **área de parqueo** de la aplicación.  
Permite seleccionar espacios según las reglas definidas por el tipo de vehículo y el tipo de estacionamiento, mostrando mensajes de error o advertencia cuando la selección no es válida.

### Dependencias
- Estilos personalizados: `parking.css`
- Iconos: PrimeIcons (`pi pi-car`, `pi pi-motorcycle`, `pi pi-clock`)

### Props (propiedades)
- **espacios** → Lista de objetos con la información de cada espacio (estado y tipo).  
  ```js
  { tipo: "auto" | "moto" | "largo", ocupado: true | false }

### Usuario selecciona un espacio tipo "auto" estando libre:
→ Espacio marcado como seleccionado
→ Callback ejecutado: { id: 1, tipo: "auto", ocupado: false }

### Usuario selecciona un espacio ocupado:
→ Error: "Este espacio ya está ocupado"

### Usuario selecciona un espacio tipo "moto" pero es estacionamiento por día:
→ Advertencia: "Selecciona un espacio de largo plazo"


## 5. RegistroSalida.jsx

### Propósito
Componente que gestiona el **registro de salida de vehículos** en el sistema de parqueo.  
Permite seleccionar un vehículo, calcular el monto a pagar y generar un recibo con los datos del usuario y la salida.

### Dependencias
- React (`useState`, `useEffect`)
- PrimeReact:
  - `InputText` → entrada de datos y visualización de información
  - `Dropdown` → selección de tipo de vehículo y vehículo específico
  - `Button` → botones de acción (calcular, generar recibo)

### Flujo de ejecución
1. El usuario ingresa su nombre en el campo `Usuario`.  
2. Selecciona el tipo de vehículo (`auto` o `moto`).  
3. Según el tipo de vehículo, se carga la lista correspondiente de opciones (`Auto 1, Auto 2…` o `Moto 1, Moto 2…`).  
4. Se actualiza la fecha y hora de salida en tiempo real.  
5. El usuario puede:
   - Presionar **Calcular** → (pendiente de implementar) debe calcular el monto a pagar.  
   - Presionar **Generar Recibo** → se muestra un `alert` con los datos de la salida (usuario, vehículo, monto).

### Estructura principal
- **Estados locales:**  
  - `usuario` → nombre del usuario.  
  - `tipoVehiculo` → tipo de vehículo seleccionado.  
  - `vehiculos` → lista de vehículos disponible según tipo.  
  - `vehiculoSeleccionado` → vehículo elegido.  
  - `fechaHoraSalida` → se actualiza cada segundo con la fecha/hora actual.  
  - `monto` → monto calculado a pagar (inicialmente 0).  

- **Hooks:**  
  - `useEffect` para actualizar la lista de vehículos al cambiar `tipoVehiculo`.  
  - `useEffect` para actualizar la fecha y hora en tiempo real.  

- **Funciones clave:**  
  - `calcularMonto()` → lógica pendiente de implementación (ejemplo: calcular según tarifa y tiempo).  
  - `generarRecibo(e)` → muestra un recibo simulado en un `alert`.  

### Ejemplo de interacción

### Caso 1: Usuario auto
Usuario: Carlos
Tipo Vehículo: Auto
Vehículo: Auto 1
Fecha Salida: 25/08/2025 15:45:10
Monto: Q20.00
→ "Recibo generado: Usuario Carlos, Vehículo Auto 1, Monto Q20.00"

### Caso 2: Usuario moto
Usuario: Ana
Tipo Vehículo: Moto
Vehículo: Moto 2
Fecha Salida: 25/08/2025 16:01:55
Monto: Q10.00
→ "Recibo generado: Usuario Ana, Vehículo Moto 2, Monto Q10.00"




