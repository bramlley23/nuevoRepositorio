# Análisis

El sistema estará basado en un banco ficticio
denominado Banco JP Morgan, que replica las operaciones de grandes bancos
en Guatemala.

## Objetivo General

El objetivo principal del proyecto es que los estudiantes se familiaricen con el
diseño y manejo de bases de datos SQL en un contexto bancario, desarrollando
habilidades clave como la normalización, la gestión de transacciones, la creación
de consultas avanzadas y la optimización para manejar grandes volúmenes de
datos en un entorno de producción.

## Objetivos Específicos

1. **Diseño de Base de Datos**: El estudiante debe diseñar una base de datos
completamente normalizada que represente las operaciones bancarias de un
banco real.
2. **Gestión de Transacciones**: Desarrollar la capacidad de manejar transacciones
bancarias de manera eficiente y segura, garantizando la integridad de los
datos.
3. **Consultas SQL Avanzadas**: Permitir a los estudiantes escribir consultas
complejas que involucren múltiples tablas, manejo de fechas, agregaciones y
optimización de rendimiento.
4. **Soporte de Cargas Simultáneas**: Diseñar y validar el sistema para que
soporte múltiples operaciones simultáneas, asegurando la integridad de los
datos y un rendimiento adecuado.
5. **Seguridad de Datos**: Establecer mecanismos de seguridad robustos,
incluyendo controles de acceso a la base de datos y manejo seguro de las
transacciones.
6. **Modelado de Base de Datos**: Aplicar las mejores prácticas de modelado de
datos en la construcción de bases de datos transaccionales, asegurando la
integridad referencial y la optimización de consultas.


# Definición del Sistema

Banco JP Morgan es un banco ficticio que ofrece una amplia gama de servicios
financieros, incluyendo cuentas de ahorro, préstamos, tarjetas de crédito y débito,
además de servicios de pago y transferencias. El banco tiene presencia en todo el
país y cuenta con una amplia red de sucursales y agencias que permiten ofrecer
servicios tanto en áreas urbanas como rurales.

# Análisis Sistema Bancario - Banco JP Morgan

En los archivos CSV se puede observar una serie de datos disponibles los cuales son:

- `clientes_banco_jp_morgan_1m.csv`
- `transacciones_banco_jp_morgan_500k.csv`
- `prestamos_banco_jp_morgan_100k.csv`
- `tarjetas_credito_banco_jp_morgan_100k.csv`
- `agencias_sucursales_banco_jp_morgan_escalado.csv`
- `empleados_banco_jp_morgan.csv`

## Modelo Conceptual
![modelo conceptual](../modelos/modelo_conceptual.png)

## Descripción de los Datos

A continuacion se selecciona el tipo de dato que se sugiere debido a los archivos de entrada (este analisis es sin la normalizacion):

### 1. Clientes
Los datos de las cuentas bancarias se encuentran en el archivo `clientes_banco_jp_morgan_1m.csv` y son:

1. `ID`: Identificador único del cliente. - `NUMBER`
2. `Nombre`: Primer nombre del cliente. - `VARCHAR2(50)`
3. `Apellido`: Apellido del cliente. `VARCHAR2(50)`
4. `Número de Cuenta`: Número de cuenta bancaria del cliente. - `VARCHAR2(30)`
5. `Tipo de Cuenta`: Clasificación del tipo de cuenta bancaria (e.g., corriente, ahorro). - `VARCHAR2(30)`
6. `Saldo`: Monto actual en la cuenta. - `NUMBER(15, 2)`
7. `Teléfono`: Número de contacto del cliente. - `VARCHAR2(20)`

### 2. Transacciones
Los datos de las transacciones se encuentran en el archivo `transacciones_banco_jp_morgan_500k.csv` y son:

1. `ID Transacción`: Identificador único de la transacción. - `NUMBER`
2. `ID Cliente`: Identificador único del cliente que realizó la transacción. - `NUMBER`
3. `Número de Cuenta`: Número de cuenta del cliente. - `VARCHAR2(30)`
4. `Tipo de Transacción`: Tipo de transacción realizada (Depósito, Retiro,
Transferencia, Pago). - `VARCHAR2(30)`
5. `Monto`: Monto de la transacción. - `NUMBER(15, 2)`
6. `Fecha`: Fecha en que se realizó la transacción. - `TIMESTAMP`
7. `Hora`: Hora en que se realizó la transacción. - `TIMESTAMP`
8. `Descripción`: Breve descripción de la transacción. - `VARCHAR(250)`
9. `Sucursal/Agencia`: Sucursal o agencia donde se realizó la transacción. - `VARCHAR2(50)`

### 3. Préstamos 
Los datos de los prestamos se encuentran en el archivo `prestamos_banco_jp_morgan_100k.csv` y son:

1. `ID Préstamo`: Identificador único del préstamo. - `NUMBER`
2. `ID Cliente`: Identificador único del cliente que recibió el préstamo. - `NUMBER`
3. `Monto del Préstamo`: Monto total del préstamo otorgado. - `NUMBER(15, 2)`
4. `Tasa de Interés`: Tasa de interés aplicada al préstamo. - `NUMBER(5, 2)`
5. `Fecha de Desembolso`: Fecha en que se desembolsó el préstamo. - `TIMESTAMP`
6. `Fecha de Vencimiento`: Fecha en que se debe liquidar el préstamo. - `TIMESTAMP`
7. `Saldo Pendiente`: Saldo que aún está pendiente de pago. - `NUMBER(15, 2)`
8. `Estado del Préstamo`: Estado actual del préstamo (Activo, Vencido,
Cancelado). - `VARCHAR2(30)`

### 4. Tarjetas de Crédito
Los datos de las tarjetas de credito se encuentran en el archivo `tarjetas_credito_banco_jp_morgan_100k.csv` y son:

1. `ID Tarjeta`: Identificador único de la tarjeta de crédito. - `NUMBER`
2. `ID Cliente`: Identificador único del cliente que posee la tarjeta. - `NUMBER`
3. `Número de Tarjeta`: Número de la tarjeta de crédito. - `CHAR(16)`
4. `Límite de Crédito`: Límite máximo de crédito asignado a la tarjeta. - `NUMBER(15, 2)`
5. `Saldo Actual`: Saldo actual pendiente en la tarjeta. - `NUMBER(15, 2)`
6. `Fecha de Emisión`: Fecha en que se emitió la tarjeta. - `TIMESTAMP`
7. `Fecha de Expiración`: Fecha en que expira la tarjeta. - `TIMESTAMP`
8. `Estado`: Estado actual de la tarjeta (Activa, Bloqueada, Cancelada). - `VARCHAR2(30)`
9. `Fecha de Corte`: La fecha en que se genera el estado de cuenta de la
tarjeta de crédito. - `TIMESTAMP`
10. `Día del Ciclo`: El día del mes en que se cierra el ciclo de facturación de la tarjeta de crédito (puede variar entre 1 y 31). - `NUMBER(2)`

### 5. Sucursales/Agencias
Los datos de las Sucursales/Agencias se encuentran en el archivo `agencias_sucursales_banco_jp_morgan_escalado.csv` y son:


1. `ID`: Identificador único de la sucursal o agencia. - `NUMBER`
2. `Nombre`: Nombre de la sucursal o agencia. - `VARCHAR2(50)`
3. `Tipo`: Especifica si es una sucursal o una agencia. - `VARCHAR2(10)`
4. `Departamento`: Departamento en el que se encuentra la sucursal o
agencia. - `VARCHAR2(50)`
5. `Municipio`: Municipio correspondiente. - `VARCHAR2(50)`
6. `Dirección`: Dirección específica de la sucursal o agencia. - `VARCHAR2(50)`
7. `Código Postal`: Código postal del área. - `CHAR(5)`
8. `Teléfono`: Número de contacto de la sucursal o agencia. - `VARCHAR2(20)`

### 6. Empleados
Los datos de los empleados se encuentran en el archivo `empleados_banco_jp_morgan.csv` y son:

1. `ID`: Identificador único del empleado. - `NUMBER`
2. `Nombre`: Nombre del empleado. - `VARCHAR2(50)`
3. `Apellido`: Apellido del empleado. - `VARCHAR2(50)`
4. `Rol`: El rol o posición del empleado (Ej. Gerente de Sucursal, Asesor Financiero, Cajero, etc.). - `VARCHAR2(50)`
5. `Departamento`: Departamento al que está asignado el empleado. - `VARCHAR2(50)`
6. `Sucursal/Asignación`: La sucursal o agencia a la que está asignado el empleado. - `VARCHAR2(50)`
7. `Teléfono`: Número de contacto del empleado. - `VARCHAR2(20)`

# Análisis
## Tablas Iniciales del Proyecto
## Clientes
| ID | Nombre | Apellido | Número de Cuenta | Tipo de Cuenta | Saldo | Teléfono |
| --- | --- | --- | --- | --- | --- | --- |
| 1 | Nombre_1 | Apellido_1 | 70186741-1 | Ahorro | 256848.49 | +502 4634-7041 |
| 2 | Nombre_2 | Apellido_2 | 42148275-2 | Ahorro | 378588.21 | +502 2701-1140 |
| 3 | Nombre_3 | Apellido_3 | 95968205-3 | Depósito Monetario | 294799.84 | +502 6277-2079 |
| 4 | Nombre_4 | Apellido_4 | 74601803-4 | Ahorro | 30357.74 | +502 7371-9552 |
| 5 | Nombre_5 | Apellido_5 | 18184518-5 | Ahorro | 270027.6 | +502 1699-8122 |

## Agencias

| ID | Nombre | Tipo | Departamento | Municipio | Dirección | Código Postal | Teléfono |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 1 | Sucursal Antigua Guatemala 1 | Sucursal | Sacatepéquez | Antigua Guatemala | Zona 7 | 91405 | +502 8036-8423 |
| 2 | Sucursal Escuintla 2 | Sucursal | Escuintla | Escuintla | Zona 1 | 97145 | +502 9525-7114 |
| 3 | Sucursal Quetzaltenango 3 | Sucursal | Quetzaltenango | Quetzaltenango | Zona 1 | 53915 | +502 2873-4763 |
| 4 | Sucursal Cobán 4 | Sucursal | Alta Verapaz | Cobán | Zona 8 | 31535 | +502 6809-5562 |
| 5 | Sucursal Flores 5 | Sucursal | Petén | Flores | Zona 10 | 63389 | +502 5942-1959 |

## Tarjetas de crédito

| ID Tarjeta | ID Cliente | Número de Tarjeta | Límite de Crédito | Saldo Actual | Fecha de Emisión | Fecha de Expiración | Estado | Fecha de Corte | Día del Ciclo |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 1 | 558120 | 4872410269895827 | 4344.96 | 20358.67 | 2022-02-09 | 2025-05-04 | Bloqueada | 2022-03-06 | 6 |
| 2 | 443984 | 4,78043E+15 | 48263.8 | 12583.92 | 2021-04-29 | 2025-11-10 | Activa | 2021-05-26 | 26 |
| 3 | 709855 | 4653562424107275 | 37894.69 | 16274.3 | 2021-12-10 | 2026-08-08 | Bloqueada | 2022-01-08 | 8 |
| 4 | 495584 | 4935123661880312 | 3610.3 | 31113.15 | 2020-11-21 | 2025-07-26 | Bloqueada | 2020-12-18 | 18 |
| 5 | 621646 | 4,91859E+15 | 35118.01 | 5054.92 | 2023-10-06 | 2028-02-05 | Cancelada | 2023-11-05 | 5 |

## Prestamos
| ID Préstamo | ID Cliente | Monto del Préstamo | Tasa de Interés | Fecha de Desembolso | Fecha de Vencimiento | Saldo Pendiente | Estado del Préstamo |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 1 | 495798 | 964203.64 | 6.63 | 2023-11-19 | 2032-06-06 | 674174.18 | Vencido |
| 2 | 42734 | 811935.67 | 13.42 | 2023-05-07 | 2028-08-29 | 756664.53 | Activo |
| 3 | 540710 | 961457.89 | 13.68 | 2021-10-28 | 2030-03-10 | 200162.19 | Vencido |
| 4 | 983331 | 78869.24 | 11.42 | 2023-05-14 | 2026-12-17 | 67546.61 | Vencido |
| 5 | 409214 | 456168.05 | 6.93 | 2020-05-18 | 2026-07-08 | 729762.37 | Activo |

## Empleado
| ID | Nombre | Apellido | Rol | Departamento | Sucursal/Asignación | Teléfono |
| --- | --- | --- | --- | --- | --- | --- |
| 1 | Nombre_1 | Apellido_1 | Auditor Interno | Petén | Sucursal/Agencia 528 | +502 7815-2167 |
| 2 | Nombre_2 | Apellido_2 | Administrador | Chiquimula | Sucursal/Agencia 171 | +502 3808-9764 |
| 3 | Nombre_3 | Apellido_3 | Atención al Cliente | Jutiapa | Sucursal/Agencia 103 | +502 4899-1699 |
| 4 | Nombre_4 | Apellido_4 | Oficial de Crédito | Quetzaltenango | Sucursal/Agencia 36 | +502 3452-1726 |
| 5 | Nombre_5 | Apellido_5 | Soporte Técnico | Jutiapa | Sucursal/Agencia 583 | +502 8283-6524 |

## Transacciones

| ID Transacción | ID Cliente | Número de Cuenta | Tipo de Transacción | Monto | Fecha | Hora | Descripción | Sucursal/Agencia |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 1 | 455902 | 58639163-455902 | Transferencia | 2865.8 | 2023-10-24 | 14:28:01 | Transacción de tipo Transferencia | Sucursal/Agencia 221 |
| 2 | 469824 | 99757988-469824 | Depósito | 2438.92 | 2023-12-09 | 14:28:01 | Transacción de tipo Depósito | Sucursal/Agencia 257 |
| 3 | 626567 | 19969005-626567 | Transferencia | 9494.98 | 2024-06-01 | 14:28:01 | Transacción de tipo Transferencia | Sucursal/Agencia 874 |
| 4 | 784443 | 95861936-784443 | Pago | 8399.08 | 2023-12-26 | 14:28:01 | Transacción de tipo Pago | Sucursal/Agencia 265 |
| 5 | 421423 | 21672609-421423 | Depósito | 7722.1 | 2022-12-27 | 14:28:01 | Transacción de tipo Depósito | Sucursal/Agencia 986 |


## Aplicación de las 3 formas normales

## Tabla Clientes

| ID | Nombre | Apellido | Número de Cuenta | Tipo de Cuenta | Saldo | Teléfono |
| --- | --- | --- | --- | --- | --- | --- |
| 1 | Nombre_1 | Apellido_1 | 70186741-1 | Ahorro | 256848.49 | +502 4634-7041 |
| 2 | Nombre_2 | Apellido_2 | 42148275-2 | Ahorro | 378588.21 | +502 2701-1140 |
| 3 | Nombre_3 | Apellido_3 | 95968205-3 | Depósito Monetario | 294799.84 | +502 6277-2079 |
| 4 | Nombre_4 | Apellido_4 | 74601803-4 | Ahorro | 30357.74 | +502 7371-9552 |
| 5 | Nombre_5 | Apellido_5 | 18184518-5 | Ahorro | 270027.6 | +502 1699-8122 |

`1FN`: Si cumple, cada columna contiene valores atomicos.

`2FN`: No cumple, debido a que campos como Numero de cuenta, tipo de cuenta, saldo; no dependen de la llave primaria ID correspondiente al cliente.

por lo tanto se crea 2 nuevas tablas: Cuentas y Tipo de cuenta.

### Clientes
| ID | Nombre | Apellido | Teléfono |
| --- | --- | --- | --- |
| 1 | Nombre_1 | Apellido_1 | +502 4634-7041 |
| 2 | Nombre_2 | Apellido_2 | +502 2701-1140 |
| 3 | Nombre_3 | Apellido_3 | +502 6277-2079 |
| 4 | Nombre_4 | Apellido_4 | +502 7371-9552 |
| 5 | Nombre_5 | Apellido_5 | +502 1699-8122 |

### Cuentas
| ID | ID_Tipo_Cuenta | Número de Cuenta | Saldo | cliente_id
| --- | --- | --- | --- | --- |
| 1 | 1 | 70186741-1 | 256848.49 | 1 |
| 2 | 2 | 42148275-2 | 378588.21 | 2 |
| 3 | 1 | 95968205-3 | 294799.84 | 3 |
| 4 | 1 | 74601803-4 | 30357.74 | 4 | 
| 5 | 1 | 18184518-5 | 270027.60 | 5 |

### Tipos_De_Cuentas
| ID | Tipo |
| --- | --- |
| 1 | Ahorro |
| 2 | Monetario |
| 3 | Corriente |

`3FN`: Separadas de esta manera se cumple la tercer forma normal debido a que las tablas estan en `2FN` y ninguna columna no clave depende de otra columna no clave.

## Tabla Agencias
| ID | Nombre | Tipo | Departamento | Municipio | Dirección | Código Postal | Teléfono |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 1 | Sucursal Antigua Guatemala 1 | Sucursal | Sacatepéquez | Antigua Guatemala | Zona 7 | 91405 | +502 8036-8423 |
| 2 | Sucursal Escuintla 2 | Sucursal | Escuintla | Escuintla | Zona 1 | 97145 | +502 9525-7114 |
| 3 | Sucursal Quetzaltenango 3 | Sucursal | Quetzaltenango | Quetzaltenango | Zona 1 | 53915 | +502 2873-4763 |
| 4 | Sucursal Cobán 4 | Sucursal | Alta Verapaz | Cobán | Zona 8 | 31535 | +502 6809-5562 |
| 5 | Sucursal Flores 5 | Sucursal | Petén | Flores | Zona 10 | 63389 | +502 5942-1959 |

`1FN`: Si cumple, cada columna contiene valores atomicos.

`2FN`: No cumple, debido a que campos como tipo, Departamento, Municipio; no dependen de la llave primaria ID correspondiente a la Agencia/Sucursal.

por lo tanto se crea 3 nuevas tablas: Tipo Agencia/Sucursal, Departamentos y Municipio.

### Agencias_Sucursales

| ID | Nombre | Dirección | Código Postal | Teléfono | ID_tipo_agencia/sucursal| ID_Municipio |
| --- | --- | --- | --- | --- | --- | --- |
| 1 | Sucursal Antigua Guatemala 1 | Zona 7 | 91405 | +502 8036-8423 | 1 | 1 |
| 2 | Sucursal Escuintla 2 | Zona 1 | 97145 | +502 9525-7114 | 1 | 2 |
| 3 | Sucursal Quetzaltenango 3 | Zona 1 | 53915 | +502 2873-4763 | 1 | 3 |
| 4 | Sucursal Cobán 4 | Zona 8 | 31535 | +502 6809-5562 | 1 | 4 |
| 5 | Sucursal Flores 5 | Zona 10 | 63389 | +502 5942-1959 | 1 | 5 |

### Tipos_De_Agencias_Sucursales
| ID | Nombre |
| --- | --- |
| 1 | Sucursal |
| 2 | Agencia |

### Departamentos

| ID | Nombre |
| --- | --- |
| 1 | Sacatepéquez |
| 2 | Escuintla |
| 3 | Quetzaltenango |
| 4 | Alta Verapaz |
| 5 | Petén |

### Municipios

| ID | Nombre | ID_Departamento |
| --- | --- | --- |
| 1 | Antigua Guatemala | 1 |
| 2 | Escuintla | 2 |
| 3 | Quetzaltenango | 3 |
| 4 | Cobán | 4 |
| 5 | Flores | 5 |

## Tabla Tarjetas de crédito

| ID Tarjeta | ID Cliente | Número de Tarjeta | Límite de Crédito | Saldo Actual | Fecha de Emisión | Fecha de Expiración | Estado | Fecha de Corte | Día del Ciclo |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 1 | 558120 | 4872410269895827 | 4344.96 | 20358.67 | 2022-02-09 | 2025-05-04 | Bloqueada | 2022-03-06 | 6 |
| 2 | 443984 | 4780431200473540 | 48263.8 | 12583.92 | 2021-04-29 | 2025-11-10 | Activa | 2021-05-26 | 26 |
| 3 | 709855 | 4653562424107275 | 37894.69 | 16274.3 | 2021-12-10 | 2026-08-08 | Bloqueada | 2022-01-08 | 8 |
| 4 | 495584 | 4935123661880312 | 3610.3 | 31113.15 | 2020-11-21 | 2025-07-26 | Bloqueada | 2020-12-18 | 18 |
| 5 | 621646 | 4918591621061050 | 35118.01 | 5054.92 | 2023-10-06 | 2028-02-05 | Cancelada | 2023-11-05 | 5 |

`1FN`: Si cumple, cada columna contiene valores atomicos.

`2FN`: No cumple, debido a que campo Estado; no dependen de la llave primaria ID correspondiente a la Tarjeta de credito y ID_Cliente esta relacionado con la tabla Clientes.

por lo tanto se crea 1 nuevas tabla llamada Estado_Tarjeta

### Tarjetas_De_Credito

| ID Tarjeta | ID_Cliente | Número de Tarjeta | Límite de Crédito | Saldo Actual | Fecha de Emisión | Fecha de Expiración | Fecha de Corte | Día del Ciclo | ID_estado_tarjeta |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 1 | 1 | 4872410269895827 | 4344.96 | 20358.67 | 2022-02-09 | 2025-05-04 | 2022-03-06 | 6 | 1 |
| 2 | 2 | 4,78043E+15 | 48263.8 | 12583.92 | 2021-04-29 | 2025-11-10 | 2021-05-26 | 26 | 2 |
| 3 | 3 | 4653562424107275 | 37894.69 | 16274.3 | 2021-12-10 | 2026-08-08 | 2022-01-08 | 8 | 1 |
| 4 | 4 | 4935123661880312 | 3610.3 | 31113.15 | 2020-11-21 | 2025-07-26 | 2020-12-18 | 18 | 1 |
| 5 | 5 | 4,91859E+15 | 35118.01 | 5054.92 | 2023-10-06 | 2028-02-05 | 2023-11-05 | 5 | 3 |

### Estados_De_Tarjetas

| ID_Estado_Tarjeta | Estado |
| --- | --- |
| 1 | Activa |
| 2 | Cancelada |
| 3 | Bloqueada |

## Tabla Prestamos

| ID Préstamo | ID Cliente | Monto del Préstamo | Tasa de Interés | Fecha de Desembolso | Fecha de Vencimiento | Saldo Pendiente | Estado del Préstamo |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 1 | 495798 | 964203.64 | 6.63 | 2023-11-19 | 2032-06-06 | 674174.18 | Vencido |
| 2 | 42734 | 811935.67 | 13.42 | 2023-05-07 | 2028-08-29 | 756664.53 | Activo |
| 3 | 540710 | 961457.89 | 13.68 | 2021-10-28 | 2030-03-10 | 200162.19 | Vencido |
| 4 | 983331 | 78869.24 | 11.42 | 2023-05-14 | 2026-12-17 | 67546.61 | Vencido |
| 5 | 409214 | 456168.05 | 6.93 | 2020-05-18 | 2026-07-08 | 729762.37 | Activo |

`1FN`: Si cumple, cada columna contiene valores atomicos.

`2FN`: No cumple, debido a que campo Estado del Prestamo; no dependen de la llave primaria ID correspondiente al prestamo y ID_Cliente esta relacionado con la tabla Clientes.

por lo tanto se crea 1 nuevas tabla llamada Estado_del_Prestamo

### Prestamos

| ID_Préstamo | ID Cliente | Monto del Préstamo | Tasa de Interés | Fecha de Desembolso | Fecha de Vencimiento | Saldo Pendiente | Estado del prestamo |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 1 | 1 | 964203.64 | 6.63 | 2023-11-19 | 2032-06-06 | 674174.18 | 1 |
| 2 | 2 | 811935.67 | 13.42 | 2023-05-07 | 2028-08-29 | 756664.53 | 1 |
| 3 | 3 | 961457.89 | 13.68 | 2021-10-28 | 2030-03-10 | 200162.19 | 2 |
| 4 | 4 | 78869.24 | 11.42 | 2023-05-14 | 2026-12-17 | 67546.61 | 1 |
| 5 | 5 | 456168.05 | 6.93 | 2020-05-18 | 2026-07-08 | 729762.37 | 3 |

### Estados_De_Prestamos

| ID_Estado_Prestamo | Estado |
| --- | --- |
| 1 | Activo |
| 2 | Vencido |
| 3 | Cancelado |

# Tabla Empleado

| ID | Nombre | Apellido | Rol | Departamento | Sucursal/Agencia | Teléfono |
| --- | --- | --- | --- | --- | --- | --- |
| 1 | Nombre_1 | Apellido_1 | Auditor Interno | Petén | Sucursal/Agencia 528 | +502 7815-2167 |
| 2 | Nombre_2 | Apellido_2 | Administrador | Chiquimula | Sucursal/Agencia 171 | +502 3808-9764 |
| 3 | Nombre_3 | Apellido_3 | Atención al Cliente | Jutiapa | Sucursal/Agencia 103 | +502 4899-1699 |
| 4 | Nombre_4 | Apellido_4 | Oficial de Crédito | Quetzaltenango | Sucursal/Agencia 36 | +502 3452-1726 |
| 5 | Nombre_5 | Apellido_5 | Soporte Técnico | Jutiapa | Sucursal/Agencia 583 | +502 8283-6524 |

**La columna Sucursal/Agencia no cumple con la primera forma normal(`1FN`), por convenio dejaremos solo sucursal y representara la que tenemos en la tabla Agencias_Sucursales**

### Empleados

| ID | Nombre | Apellido | Rol | Departamento | Sucursal | Teléfono |
| --- | --- | --- | --- | --- | --- | --- |
| 1 | Nombre_1 | Apellido_1 | 1 | 1 | 1 | +502 7815-2167 |
| 2 | Nombre_2 | Apellido_2 | 2 | 3 | 2 | +502 3808-9764 |
| 3 | Nombre_3 | Apellido_3 | 3 | 4 | 3 | +502 4899-1699 |
| 4 | Nombre_4 | Apellido_4 | 4 | 1 | 4 | +502 3452-1726 |
| 5 | Nombre_5 | Apellido_5 | 5 | 2 | 5 | +502 8283-6524 |

Se crea la tabla `Rol` que representa el rol del empleado. La tabla `Departamento` la tenemos definida anteriormente.

### Roles_Empleados

| ID | Rol |
| --- | --- |
| 1 | Auditor Interno |
| 2 | Administrador |
| 3 | Atención al Cliente |
| 4 | Oficial de Crédito |
| 5 | Soporte Técnico |


## Tabla Transacciones

| ID Transacción | ID Cliente | Número de Cuenta | Tipo de Transacción | Monto | Fecha | Hora | Descripción | Sucursal/Agencia |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 1 | 455902 | 58639163-455902 | Transferencia | 2865.8 | 2023-10-24 | 14:28:01 | Transacción de tipo Transferencia | Sucursal/Agencia 221 |
| 2 | 469824 | 99757988-469824 | Depósito | 2438.92 | 2023-12-09 | 14:28:01 | Transacción de tipo Depósito | Sucursal/Agencia 257 |
| 3 | 626567 | 19969005-626567 | Transferencia | 9494.98 | 2024-06-01 | 14:28:01 | Transacción de tipo Transferencia | Sucursal/Agencia 874 |
| 4 | 784443 | 95861936-784443 | Pago | 8399.08 | 2023-12-26 | 14:28:01 | Transacción de tipo Pago | Sucursal/Agencia 265 |
| 5 | 421423 | 21672609-421423 | Depósito | 7722.1 | 2022-12-27 | 14:28:01 | Transacción de tipo Depósito | Sucursal/Agencia 986 |

`1FN`: No cumple la primer forma normal debido a que numero de cuenta nos traer 2 datos cuenta origen y destino por lo tanto lo separamos.

Para las transacciones tenemos relacion con la tabla Clientes y Agencias/Sucursales y creamos una nueva tabla para tipo de transaccion:

### Transacciones

| ID Transacción | ID Cliente | Número de Cuenta Origen | Número de Cuenta Destino | Tipo de Transacción | Monto | Fecha | Hora | Descripción | Sucursal |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 1 | 1 | 58639163 | 455902 | 1 | 2865.8 | 2023-10-24 | 14:28:01 | Certificación | 1 |
| 2 | 2 | 99757988 | 469824 | 2 | 2438.92 | 2023-12-09 | 14:28:01 | Deposito para apartamento | 2 |
| 3 | 3 | 19969005 | 626567 | 1 | 9494.98 | 2024-06-01 | 14:28:01 | pago luz | 3 |
| 4 | 4 | 95861936 | 784443 | 3 | 8399.08 | 2023-12-26 | 14:28:01 | pago casa | 4 |
| 5 | 5 | 21672609 | 21672609 | 2 | 7722.1 | 2022-12-27 | 14:28:01 | servicio internet | 5 |

### Tipos_De_Transacciones

| ID  | Tipo de Transacción |
| --- | --- |
| 1 | Transferencia |
| 2 | Depósito |
| 3 | Pago |
| 4 | Retiro |

Asi se cumplen en todas las tablas hasta la Tercera forma Normal.

### Tablas Tarjetas_Debito
| tarjeta_id | fecha_de_emision     | fecha_de_expiracion   | codigo_cvv | numero_de_tarjeta  | estado        | numero_de_cuenta |
|------------|-----------------------|-----------------------|------------|--------------------|---------------|------------------|
| 1          | 2022-05-15 10:30:00   | 2027-05-15 10:30:00   | 123        | 1234567812345678   | activo        | 123456789012345  |
| 2          | 2021-08-10 14:45:00   | 2026-08-10 14:45:00   | 234        | 2345678923456789   | bloqueado     | 234567890123456  |
| 3          | 2020-12-01 09:15:00   | 2025-12-01 09:15:00   | 345        | 3456789034567890   | activo        | 345678901234567  |
| 4          | 2023-02-25 16:00:00   | 2028-02-25 16:00:00   | 456        | 4567890145678901   | cancelado     | 456789012345678  |
| 5          | 2022-07-18 11:20:00   | 2027-07-18 11:20:00   | 567        | 5678901256789012   | activo        | 567890123456789  |

`1FN`: Si cumple, cada columna contiene valores atomicos.

`2FN`: No cumple, Debido a que hay dependencias parciales en estado y numero de cuenta, por lo que las volvemos foraneas de las tablas Estados_Tarjetas y Cuentas, quedando asi:

| tarjeta_id | fecha_de_emision     | fecha_de_expiracion   | codigo_cvv | numero_de_tarjeta  | estados_tarjetas_estado_id | cuentas_cuenta_id |
|------------|-----------------------|-----------------------|------------|--------------------|----------------------------|--------------------|
| 1          | 2022-05-15 10:30:00   | 2027-05-15 10:30:00   | 123        | 1234567812345678   | 1                          | 1                 |
| 2          | 2021-08-10 14:45:00   | 2026-08-10 14:45:00   | 234        | 2345678923456789   | 2                          | 2                 |
| 3          | 2020-12-01 09:15:00   | 2025-12-01 09:15:00   | 345        | 3456789034567890   | 1                          | 3                 |
| 4          | 2023-02-25 16:00:00   | 2028-02-25 16:00:00   | 456        | 4567890145678901   | 3                          | 4                 |
| 5          | 2022-07-18 11:20:00   | 2027-07-18 11:20:00   | 567        | 5678901256789012   | 1                          | 5                 |

`3FN`: Separadas de esta manera se cumple la tercer forma normal debido a que las tablas estan en `2FN` y ninguna columna no clave depende de otra columna no clave.

### Tablas Bovedas

| boveda_id | monto_actual | capacidad_max |
|-----------|--------------|---------------|
| 1         | 1,000,000    | 10,000,000    |
| 2         | 2,000,000    | 20,000,000    |
| 3         | 3,000,000    | 30,000,000    |
| 4         | 4,000,000    | 40,000,000    |
| 5         | 5,000,000    | 50,000,000    |
| 6         | 6,000,000    | 60,000,000    |
| 7         | 7,000,000    | 70,000,000    |
| 8         | 8,000,000    | 80,000,000    |
| 9         | 9,000,000    | 90,000,000    |
| 10        | 10,000,000   | 100,000,000   |

`1FN`: Si cumple, cada columna contiene valores atomicos.

`2FN`: Si cumple, no tiene dependencias parciales.

`3FN`: Separadas de esta manera se cumple la tercer forma normal, No hay dependencias transitivas.

### Detalles_Transacciones

| detalle_trans_id | fecha_trans         | descripcion                  | empleados_empleado_id | transacciones_transaccion_id | clientes_cliente_id | agencias_agencia_id |
|------------------|---------------------|------------------------------|------------------------|------------------------------|----------------------|----------------------|
| 1                | 2023-10-20 00:00:00 | Consulta de movimientos      | 9                      | 7                            | 2                    | 7                    |
| 2                | 2023-09-04 00:00:00 | Consulta de estado de cuenta | 9                      | 4                            | 10                   | 8                    |
| 3                | 2023-10-07 00:00:00 | Modificación de cuenta       | 9                      | 4                            | 8                    | 8                    |
| 4                | 2023-10-27 00:00:00 | Consulta de estado de cuenta | 1                      | 2                            | 1                    | 6                    |
| 5                | 2023-09-08 00:00:00 | Consulta de estado de cuenta | 3                      | 2                            | 3                    | 7                    |

`1FN`: Si cumple, cada columna contiene valores atomicos.

`2FN`: Si cumple, no tiene dependencias parciales.

`3FN`: Separadas de esta manera se cumple la tercer forma normal, No hay dependencias transitivas.

### Auditorias

| auditoria_id | descripcion      | fecha_auditoria | empleados_empleado_id | empleados_empleado_id2 |
|---------------|------------------|------------------|-----------------------|------------------------|
| 1             | auditoria 1      | 2020-01-01       | 1                     | 2                      |
| 2             | auditoria 2      | 2020-01-02       | 1                     | 3                      |
| 3             | audjsonitoria 3   | 2020-01-03       | 1                     | 2                      |
| 4             | auditoria 4      | 2020-01-04       | 1                     | 3                      |
| 5             | auditoria 5      | 2020-01-05       | 1                     | 10                     |
| 6             | auditoria 6      | 2020-01-06       | 1                     | 10                     |
| 7             | auditoria 7      | 2020-01-07       | 1                     | 2                      |
| 8             | auditoria 8      | 2020-01-08       | 1                     | 3                      |
| 9             | auditoria 9      | 2020-01-09       | 1                     | 10                     |

`1FN`: Si cumple, cada columna contiene valores atomicos.

`2FN`: Si cumple, no tiene dependencias parciales.

`3FN`: Separadas de esta manera se cumple la tercer forma normal, No hay dependencias transitivas.

### Trans_Interbancos

| id_trans_agencia | monto  | fecha               | agencias_agencia_id | agencias_agencia_id2 |
|------------------|--------|---------------------|----------------------|-----------------------|
| 1                | 910.61 | 2023-08-12 00:00:00 | 4                    | 10                    |
| 2                | 794.57 | 2023-09-29 00:00:00 | 8                    | 1                     |
| 3                | 887.19 | 2023-09-04 00:00:00 | 1                    | 6                     |
| 4                | 754.71 | 2023-10-27 00:00:00 | 10                   | 3                     |
| 5                | 232.65 | 2023-08-14 00:00:00 | 4                    | 4                     |

`1FN`: Si cumple, cada columna contiene valores atomicos.

`2FN`: Si cumple, no tiene dependencias parciales.

`3FN`: Separadas de esta manera se cumple la tercer forma normal, No hay dependencias transitivas.

### Estados_Financieros

| estado_id | total_activo | total_pasivo | total_ingreso | total_gasto | fecha_corte | agencias_agencia_id |
|-----------|--------------|--------------|----------------|--------------|--------------|----------------------|
| 1         | 10000000     | 5000000      | 1000000        | 500000       | 2023-01-01   | 1                    |
| 2         | 1000000      | 500000       | 100000         | 50000        | 2023-01-01   | 2                    |
| 3         | 2000000      | 1000000      | 200000         | 100000       | 2023-01-01   | 3                    |
| 4         | 3000000      | 1500000      | 300000         | 150000       | 2023-01-01   | 4                    |
| 5         | 4000000      | 2000000      | 400000         | 200000       | 2023-01-01   | 5                    |
| 6         | 5000000      | 2500000      | 500000         | 250000       | 2023-01-01   | 6                    |
| 7         | 6000000      | 3000000      | 600000         | 300000       | 2023-01-01   | 7                    |
| 8         | 7000000      | 3500000      | 700000         | 350000       | 2023-01-01   | 8                    |
| 9         | 8000000      | 4000000      | 800000         | 400000       | 2023-01-01   | 9                    |
| 10        | 9000000      | 4500000      | 900000         | 450000       | 2023-01-01   | 10                   |

`1FN`: Si cumple, cada columna contiene valores atomicos.

`2FN`: Si cumple, no tiene dependencias parciales.

`3FN`: Separadas de esta manera se cumple la tercer forma normal, No hay dependencias transitivas.

### Tipos_Usuarios

| tipo_id | tipo         |
|---------|--------------|
| 1       | cliente      |
| 2       | empleado     |
| 3       | administrador |


`1FN`: Si cumple, cada columna contiene valores atomicos.

`2FN`: Si cumple, no tiene dependencias parciales.

`3FN`: Separadas de esta manera se cumple la tercer forma normal, No hay dependencias transitivas.
### Usuarios

| usuario         | password         | tipos_usuarios_tipo_id | permisos_permiso_id |
|-----------------|------------------|-------------------------|----------------------|
| juan_perez      | password123      | 1                       | 1                    |
| maria_gomez     | securePass!45    | 1                       | 1                    |
| carlos_lopez    | empleado2024     | 2                       | 3                    |
| ana_martinez    | adminPower2023   | 3                       | 2                    |
| luis_santos     | empSecret98      | 2                       | 3                    |
| jose_ramirez    | clntSafePass55   | 1                       | 1                    |
| pedro_garcia    | admMaster99      | 3                       | 2                    |
| luz_fuentes     | user2023login    | 2                       | 3                    |
| sofia_hernandez | admSecure77      | 3                       | 2                    |
| diego_castillo  | custAcces98      | 1                       | 1                    |

`1FN`: Si cumple, cada columna contiene valores atomicos.

`2FN`: Si cumple, no tiene dependencias parciales.

`3FN`: Separadas de esta manera se cumple la tercer forma normal, No hay dependencias transitivas.

### Permisos

| permiso_id | permiso      |
|------------|--------------|
| 1          | cliente      |
| 2          | administrador |
| 3          | empleado     |

`1FN`: Si cumple, cada columna contiene valores atomicos.

`2FN`: Si cumple, no tiene dependencias parciales.

`3FN`: Separadas de esta manera se cumple la tercer forma normal, No hay dependencias transitivas.

### Asignaciones_Empleados

| asignacion_id | fecha_inicio         | fecha_fin           | agencias_agencia_id | empleados_empleado_id |
|---------------|-----------------------|---------------------|----------------------|-----------------------|
| 1             | 2023-01-10 08:00:00   | 2023-06-10 17:00:00 | 1                    | 1                     |
| 2             | 2023-02-15 09:00:00   |                     | 2                    | 2                     |
| 3             | 2023-03-01 08:30:00   | 2023-08-01 16:00:00 | 3                    | 3                     |
| 4             | 2023-04-20 10:00:00   | 2023-10-20 18:00:00 | 4                    | 4                     |
| 5             | 2023-05-05 07:45:00   |                     | 5                    | 5                     |
| 6             | 2023-06-30 08:00:00   | 2023-12-31 17:00:00 | 6                    | 6                     |
| 7             | 2023-07-15 09:00:00   |                     | 7                    | 7                     |
| 8             | 2023-08-25 08:15:00   | 2024-01-25 16:00:00 | 8                    | 8                     |
| 9             | 2023-09-01 07:30:00   |                     | 9                    | 9                     |
| 10            | 2023-10-05 08:45:00   | 2024-04-05 18:00:00 | 10                   | 10                    |

`1FN`: Si cumple, cada columna contiene valores atomicos.

`2FN`: Si cumple, no tiene dependencias parciales.

`3FN`: Separadas de esta manera se cumple la tercer forma normal, No hay dependencias transitivas.

### Estados_Empleados

| estado_id | estado     |
|-----------|------------|
| 1         | activo     |
| 2         | despedido  |
| 3         | jubilado   |
| 4         | licencia   |
| 5         | renuncia   |
| 6         | suspendido |
| 7         | vacaciones  |

`1FN`: Si cumple, cada columna contiene valores atomicos.

`2FN`: Si cumple, no tiene dependencias parciales.

`3FN`: Separadas de esta manera se cumple la tercer forma normal, No hay dependencias transitivas.


## Resumen de Tablas
A continuacion se lista el nombre de las tablas que se dejaran en Plural:

1. Clientes
2. Cuentas
3. Tipos_Cuentas
4. Agencias
5. Tipos_Agencias
6. Departamentos
7. Municipios
8. Tarjetas_Credito
9. Estados_Tarjetas
10. Prestamos
11. Estados_Prestamos
12. Empleados
13. Roles_Empleados
14. Transacciones
15. Tipos_Trans
16. Tarjetas_Debito
17. Bovedas
18. Detalles_Transacciones
19. Auditorias
20. Trans_Interbancos
21. Estados_Financieros
22. Tipos_Usuarios
23. Usuarios
24. Permisos
25. Asignaciones_Empleados
26. Estados_Empleados

## Definicion de campos de cada Tabla
### 1. Clientes
Los datos de la tabla clientes seran:

1. `cliente_id`: Identificador único del cliente. - `NUMBER` - `PK`
2. `nombre`: Primer nombre del cliente. - `VARCHAR2(50)`
3. `apellido`: Apellido del cliente. `VARCHAR2(50)`
4. `telefono`: Número de contacto del cliente. - `VARCHAR2(20)`

### 2. Cuentas
Los datos de la tabla cuentas seran:

1. `cuenta_id`: Identificador único de la cuenta. - `NUMBER` - `PK`
2. `tipo_id`: Llave foranea hacia la tabla Tipos_Cuentas - `NUMBER` - `FK`
3. `numero_de_cuenta`: Número de cuenta bancaria del cliente. - `VARCHAR2(30)`
4. `saldo`: Monto actual en la cuenta. - `NUMBER(15, 2)`
5.  `cliente_id`: Llave foranea hacia la tabla Clientes - `NUMBER` - `FK`

### 3. Tipos_Cuentas
Los datos de la tabla Tipos_Cuentas seran:

1. `tipo_id`: Identificador único del tipo de cuenta. - `NUMBER` - `PK`
2. `tipo`: Clasificación del tipo de cuenta bancaria (e.g., corriente, ahorro). - `VARCHAR2(30)`


### 4. Agencias
Los datos de la tabla Agencias seran:


1. `agencia_id`: Identificador único de la sucursal o agencia. - `NUMBER` - `PK`
2. `nombre`: Nombre de la sucursal o agencia. - `VARCHAR2(50)`
3. `direccion`: Dirección específica de la sucursal o agencia. - `VARCHAR2(50)`
4. `codigo_postal`: Código postal del área. - `CHAR(5)`
5. `telefono`: Número de contacto de la sucursal o agencia. - `VARCHAR2(20)`
6. `tipo_id`: Llave foranea hacia la tabla Tipos_Agencias - `NUMBER` - `FK`
7. `municipio_id`: Llave foranea hacia la tabla Municipios - `NUMBER` - `FK`

### 5. Tipos_Agencias
Los datos de la tabla Tipos_Agencias seran:

1. `tipo_id`: Identificador único del tipo de Agencia o sucursal. - `NUMBER` - `PK`
2. `tipo`: Especifica si es una sucursal o una agencia. - `VARCHAR2(10)`

### 6. Departamentos
Los datos de la tabla Departamentos seran:

1. `departamento_id`: Identificador único del Departamento. - `NUMBER` - `PK`
2. `nombre`: Departamento en el que se encuentra la sucursal o agencia. - `VARCHAR2(50)`

### 7. Municipios
Los datos de la tabla Municipios seran:

1. `municipio_id`: Identificador único del Municipio. - `NUMBER` - `PK`
2. `nombre`: Nombre del Municipio correspondiente. - `VARCHAR2(50)`
3. `departamento_id`: Llave foranea hacia la tabla Departamentos - `NUMBER` - `FK`

### 8. Tarjetas_Credito
Los datos de la tabla Tarjetas_De_Credito seran:

1. `tarjeta_id`: Identificador único de la tarjeta de crédito. - `NUMBER` - `PK`
2. `cliente_id`: Llave foranea hacia la tabla Clientes. - `NUMBER` - `FK`
3. `numero_de_tarjeta`: Número de la tarjeta de crédito. - `CHAR(16)`
4. `limite_de_credito`: Límite máximo de crédito asignado a la tarjeta. - `NUMBER(15, 2)`
5. `saldo_actual`: Saldo actual pendiente en la tarjeta. - `NUMBER(15, 2)`
6. `fecha_de_emision`: Fecha en que se emitió la tarjeta. - `TIMESTAMP`
7. `fecha_de_expiracion`: Fecha en que expira la tarjeta. - `TIMESTAMP`
8. `fecha_de_corte`: La fecha en que se genera el estado de cuenta de la tarjeta de crédito. - `TIMESTAMP`
9. `dia_del_ciclo`: El día del mes en que se cierra el ciclo de facturación de la tarjeta de crédito (puede variar entre 1 y 31). - `NUMBER(2)`
10. `estado_id`: Llave foranea hacia la tabla Estados_Tarjetas - `NUMBER` - `FK`

### 9. Estados_Tarjetas
Los datos de la tabla Estados_Tarjetas seran:

1. `estado_id`: Identificador único del estado de la tarjeta. - `NUMBER` - `PK`
2. `estado`: Estado actual de la tarjeta (Activa, Bloqueada, Cancelada). - `VARCHAR2(30)`

### 10. Préstamos 
Los datos de la tabla Préstamos seran:

1. `prestamo_id`: Identificador único del préstamo. - `NUMBER` - `PK`
2. `cliente_id`: Llave foranea hacia la tabla Clientes. - `NUMBER` - `FK`
3. `monto_del_prestamo`: Monto total del préstamo otorgado. - `NUMBER(15, 2)`
4. `tasa_de_interes`: Tasa de interés aplicada al préstamo. - `NUMBER(5, 2)`
5. `fecha_de_desembolso`: Fecha en que se desembolsó el préstamo. - `TIMESTAMP`
6. `fecha_de_vencimiento`: Fecha en que se debe liquidar el préstamo. - `TIMESTAMP`
7. `saldo_pendiente`: Saldo que aún está pendiente de pago. - `NUMBER(15, 2)`
8. `estado_id`: Llave foranea hacia la tabla Estados_Prestamos - `NUMBER` - `FK`


### 11. Estados_Prestamos
Los datos de la tabla Estados_Prestamos seran:

1. `estado_id`: Identificador único del estado del prestamo. - `NUMBER` - `PK`
2. `estado`: Estado actual del préstamo (Activo, Vencido, Cancelado). - `VARCHAR2(30)`

### 12. Empleados
Los datos de la tabla Empleados seran:

1. `empleado_id`: Identificador único del empleado. - `NUMBER` - `PK`
2. `nombre`: Nombre del empleado. - `VARCHAR2(50)`
3. `apellido`: Apellido del empleado. - `VARCHAR2(50)`
4. `rol_id`: Llave foranea hacia la tabla Roles_Empleados - `NUMBER` - `FK`
5. `departamento_id`: Llave foranea hacia la tabla Departamentos - `NUMBER` - `FK`
6. `agencia_id`: Llave foranea hacia la tabla Agencias - `NUMBER` - `FK`
7. `Telefono`: Número de contacto del empleado. - `VARCHAR2(20)`

### 13. Roles_Empleados
Los datos de la tabla Roles_Empleados seran:

1. `rol_id`: Identificador único del rol_id. - `NUMBER` - `PK`
2. `nombre`: El rol o posición del empleado (Ej. Gerente de Sucursal, Asesor Financiero, Cajero, etc.). - `VARCHAR2(50)`


### 14. Transacciones
Los datos de la tabla Transacciones seran:

1. `transaccion_id`: Identificador único de la transacción. - `NUMBER` - `PK`
2. `cliente_id`: Llave foranea hacia la tabla Clientes. - `NUMBER` - `FK`
3. `cuenta_origen`: Número de cuenta del cliente origen. - `VARCHAR2(30)`
4. `cuenta_destino`: Número de cuenta del cliente destino. - `VARCHAR2(30)`
5. `tipo_id`: Llave foranea hacia la tabla Tipos_Trans. - `NUMBER` - `FK`
6. `monto`: Monto de la transacción. - `NUMBER(15, 2)`
7. `fecha`: Fecha en que se realizó la transacción. - `TIMESTAMP`
8. `hora`: Hora en que se realizó la transacción. - `TIMESTAMP`
9. `descripcion`: Breve descripción de la transacción. - `VARCHAR(250)`
10. `agencia_id`: Llave foranea hacia la tabla Agencias - `NUMBER` - `FK`

### 15. Tipos_Trans
Los datos de la tabla Tipos_Trans seran:

1. `tipo_id`: Identificador único del tipo de transaccion. - `NUMBER` - `PK`
2. `tipo`: Tipo de transacción realizada (Depósito, Retiro, Transferencia, Pago). - `VARCHAR2(30)`

### 16. Tarjetas_Debito
Los datos de la tabla Tarjetas_Debito seran:

1. `tarjeta_id`: Identificador único de la tarjeta de debito. - `NUMBER` - `PK`
2. `fecha_de_emision`: Fecha en que se emitió la tarjeta. - `TIMESTAMP`
3. `fecha_de_expiracion`: Fecha en que expira la tarjeta. - `TIMESTAMP`
4. `codigo_cvv`: Codigo de seguridad de la tarjeta. - `NUMBER(3)`
5. `numero_de_tarjeta`: Numero de la tarjeta. - `NUMBER(16)`
6. `estado_id`: Llave foranea hacia la tabla Estados_Tarjetas - `NUMBER` - `FK`
7. `cuenta_id`: Llave foranea hacia la tabla Cuentas - `NUMBER` - `FK`

### 17. Bovedas
Los datos de la Tabla Bovedas seran:

1. `boveda_id`: Identificador único de la Boveda. - `NUMBER` - `PK`
2. `monto_actual`: Dinero que posee la boveda. - `NUMBER`
3. `capacidad_max`: Cantidad maxima de dinero que posee la boveda. - `NUMBER`

### 18. Detalles_Transacciones
Los datos de la Tabla Detalles_Transacciones seran:

1. `detalle_trans_id`: Identificador único de la transaccion. - `NUMBER` - `PK`
2. `fecha_trans`: Fecha en que se emitió la transaccion. - `TIMESTAMP`
3. `descripcion`: Breve descripción de la transacción. - `VARCHAR2(250)`
4. `empleado_id`: Llave foranea hacia la tabla Empleados - `NUMBER` - `FK`
5. `transaccion_id`: Llave foranea hacia la tabla Transacciones - `NUMBER` - `FK`
6. `cliente_id`: Llave foranea hacia la tabla Clientes - `NUMBER` - `FK`
7. `agencia_id`: Llave foranea hacia la tabla Agencias - `NUMBER` - `FK`

### 19. Auditorias
Los datos de la Tabla Detalles_Transacciones seran:

1. `auditoria_id`: Identificador único de la auditoria. - `NUMBER` - `PK`
2. `descripcion`: Consulta echa por el auditor. - `VARCHAR2(600)`
3. `fecha_auditoria`: Fecha en que se emitió la auditoria. - `TIMESTAMP`
4. `auditado_id`: Llave foranea hacia la tabla Empleados, representa el empleado auditado - `NUMBER` - `FK`
5. `auditor_id`: Llave foranea hacia la tabla Empleados, representa el auditado - `NUMBER` - `FK`

### 20. Trans_Interbancos
Los datos de la Tabla Trans_Interbancos seran:

1. `id_trans_agencia`: Identificador único de la transaccion interbancaria. - `NUMBER` - `PK`
2. `monto`: Monto de la transacción. - `NUMBER(15, 2)`
3. `fecha`: Fecha en que se emitió la transaccion interbancaria. - `TIMESTAMP`
4. `origen_agencia_id`: Llave foranea hacia la tabla Agencias, representa la agencia de la que sale el dinero - `NUMBER` - `FK`
5. `destino_agencia_id`: Llave foranea hacia la tabla Agencias, representa la agencia a la que le ingresan dinero. - `NUMBER` - `FK`

### 21. Estados_Financieros
Los datos de la Tabla Estados_Financieros seran:

1. `estado_id`: Identificador único del estado financiero. - `NUMBER` - `PK`
2. `total_activo`: Cantidad de activos de la agencia. - `NUMBER`
3. `total_pasivos`: Cantidad de pasivos de la agencia. - `NUMBER`
4. `total_ingresos`: Cantidad de ingresos de la agencia. - `NUMBER`
5. `total_gastos`: Cantidad de gastos de la agencia. - `NUMBER`
6. `fecha_corte`: Fecha de corte. - `TIMESTAMP`
7. `agencia_id`: Llave foranea hacia la tabla Agencias, representa la agencia a la que pertenece el estado financiero. - `NUMBER` - `FK`

### 22. Tipos_Usuarios
Los datos de la Tabla Tipos_Usuarios seran:

1. `tipo_id`: Identificador único del tipo de usuario. - `NUMBER` - `PK`
2. `tipo`: Puede ser cliente, empleado, sistema. - `VARCHAR2(20)`

### 23. Usuarios
Los datos de la Tabla Usuarios seran:

1. `usuario`: Identificador único del usuario. - `VARCHAR2(30)` - `PK`
2. `password`: password del usuario - `VARCHAR2(30)`
3. `tipo_id`: Llave foranea hacia la tabla Tipos_Usuarios. - `NUMBER` - `FK`
4. `permiso_id`: Llave foranea hacia la tabla Permisos. - `NUMBER` - `FK`

### 24. Permisos
Los datos de la Tabla Permisos seran:

1. `permiso_id`: Identificador único del permiso que tiene en el sistema. - `NUMBER` - `PK`
2. `permiso`: permiso que tiene en el sistema, cliente, admin, nivel1, nivel2 etc. - `VARCHAR2(30)`

### 25. Asignaciones_Empleados
Los datos de la Tabla Asignaciones_Empleados seran:

1. `asignacion_id`: Identificador único de la asignacion del empleado. - `NUMBER` - `PK`
2. `fecha_inicio`: Fecha en la que inicio a laborar. - `TIMESTAMP`
3. `fecha_fin`: Fecha en la que dejo el puesto. - `TIMESTAMP`
4. `agencia_id`: Llave foranea hacia la tabla Agencias - `NUMBER` - `FK`
5. `empleado_id`: Llave foranea hacia la tabla Empleados - `NUMBER` - `FK`

### 26. Estados_Empleados
Los datos de la Tabla Estados_Empleados seran:

1. `estado_id`: Identificador único del estado del empleado. - `NUMBER` - `PK`
2. `estado`: Estado en el que se encuentra el empleado en la agencia o sucursal: activo, despedido, jubilado. - `VARCHAR2(20)`


## Nuevo Diagrama Matricial

| **Tablas**               | **Clientes**      | **Cuentas** | **Tipos_Cuentas** | **Agencias** | **Tipos_Agencias** | **Departamentos** | **Municipios** | **Tarjetas_Credito** | **Estados_Tarjetas** | **Prestamos** | **Estados_Prestamos** | **Empleados** | **Roles_Empleados** | **Transacciones** | **Tipos_Trans** | **Tarjetas_Debito** | **Bovedas** | **Detalles_Transacciones** | **Auditorias** | **Trans_Interbancos** | **Estados_Financieros** | **Tipos_Usuarios** | **Usuarios** | **Permisos** | **Asignaciones_Empleados** | **Estados_Empleados** |
|--------------------------|-------------------|-------------|--------------------|--------------|--------------------|-------------------|----------------|-----------------------|-----------------------|---------------|------------------------|---------------|---------------------|-------------------|-----------------|----------------------|-------------|---------------------------|----------------|-----------------------|-------------------------|--------------------|--------------|-------------|--------------------------|-------------------------|
| **Clientes**             | ———              | tener       | ———               | ———          | ———               | ———              | ———           | adquirir              | ———                   | adquirir      | ———                   | ———           | ———                | realizar          | ———             | ———                 | ———         | realizar                  | ———              | ———                  | ———                     | ———               | pertenece    | solicitar  | ———                      | ———                     |
| **Cuentas**              | pertenecer       | ———         | tener             | ———          | ———               | ———              | ———           | ———                   | ———                   | ———           | ———                   | ———           | ———                | ———               | ———             | adquirir            | ———         | ———                       | ———              | ———                  | ———                     | ———               | ———          | ———         | ———                      | ———                     |
| **Tipos_Cuentas**        | ———              | estar       | ———               | ———          | ———               | ———              | ———           | ———                   | ———                   | ———           | ———                   | ———           | ———                | ———               | ———             | ———                 | ———         | ———                       | ———              | ———                  | ———                     | ———               | ———          | ———         | ———                      | ———                     |
| **Agencias**             | ———              | ———         | ———               | ———          | tener             | ———              | estar         | ———                   | ———                   | ———           | ———                   | tener asignado | ———                | ejecutar          | ———             | pertenecer          | tener       | pertenecer                | ———              | estar presente        | tener                   | ———               | ———          | ———         | asignar                   | ———                     |
| **Tipos_Agencias**       | ———              | ———         | ———               | estar        | ———               | ———              | ———           | ———                   | ———                   | ———           | ———                   | ———           | ———                | ———               | ———             | ———                 | ———         | ———                       | ———              | ———                  | ———                     | ———               | ———          | ———         | ———                      | ———                     |
| **Departamentos**        | ———              | ———         | ———               | ———          | ———               | ———              | tener         | ———                   | ———                   | ———           | ———                   | ———           | ———                | ———               | ———             | ———                 | ———         | ———                       | ———              | ———                  | ———                     | ———               | ———          | ———         | ———                      | ———                     |
| **Municipios**           | ———              | ———         | ———               | tener ubicadas | ———             | pertenecer       | ———           | ———                   | ———                   | ———           | ———                   | ———           | ———                | ———               | ———             | ———                 | ———         | ———                       | ———              | ———                  | ———                     | ———               | ———          | ———         | ———                      | ———                     |
| **Tarjetas_Credito**     | pertenecer       | ———         | ———               | ———          | ———               | ———              | ———           | ———                   | tener                 | ———           | ———                   | ———           | ———                | ———               | ———             | ———                 | ———         | ———                       | ———              | ———                  | ———                     | ———               | ———          | ———         | ———                      | ———                     |
| **Estados_Tarjetas**     | ———              | ———         | ———               | ———          | ———               | ———              | ———           | estar                 | ———                   | ———           | ———                   | ———           | ———                | ———               | ———             | tener               | ———         | ———                       | ———              | ———                  | ———                     | ———               | ———          | ———         | ———                      | ———                     |
| **Prestamos**            | pertenecer       | ———         | ———               | ———          | ———               | ———              | ———           | ———                   | ———                   | ———           | tener                 | ———           | ———                | ———               | ———             | ———                 | ———         | ———                       | ———              | ———                  | ———                     | ———               | ———          | ———         | ———                      | ———                     |
| **Estados_Prestamos**    | ———              | ———         | ———               | ———          | ———               | ———              | ———           | ———                   | ———                   | estar         | ———                   | ———           | ———                | ———               | ———             | ———                 | ———         | ———                       | ———              | ———                  | ———                     | ———               | ———          | ———         | ———                      | ———                     |
| **Empleados**            | ———              | ———         | ———               | estar        | ———               | estar            | ———           | ———                   | ———                   | ———           | ———                   | ———           | tener asignado      | ———               | ———             | ———                 | ———         | contener                 | recibir           | ———                  | ———                     | ———               | solicitar    | ———         | obtiene                  | ———                     |
| **Roles_Empleados**      | ———              | ———         | ———               | ———          | ———               | ———              | ———           | ———                   | ———                   | ———           | ———                   | ejecutarse    | ———                | ———               | ———             | ———                 | ———         | ———                       | ———              | ———                  | ———                     | ———               | ———          | ———         | ———                      | ———                     |
| **Transacciones**        | pertenecer       | ———         | ———               | estar        | ———               | ———              | ———           | ———                   | ———                   | ———           | ———                   | ———           | ———                | ———               | tener           | ———                 | ———         | debe tener               | estar presente   | estar presente       | ———                     | ———               | ———          | ———         | ———                      | ———                     |
| **Tipos_Trans**          | ———              | ———         | ———               | ———          | ———               | ———              | ———           | ———                   | ———                   | ———           | ———                   | ———           | ———                | estar presente    | ———             | ———                 | ———         | ———                       | ———              | ———                  | ———                     | ———               | ———          | ———         | ———                      | ———                     |
| **Tarjetas_Debito**      | ———              | pertenecer  | ———               | ———          | ———               | ———              | ———           | ———                   | estar presente        | ———           | ———                   | ———           | ———                | utilizar          | ———             | ———                 | ———         | ———                       | ———              | ———                  | ———                     | ———               | ———          | ———         | ———                      | ———                     |
| **Bovedas** | — 
——              | ———         | ———               | ———          | ———               | ———              | ———           | ———                   | ———                   | ———           | ———                   | ———           | ———                | ———               | ———             | ———                 | estar       | ———                       | ———              | ———                  | ———                     | ———               | ———          | ———         | ———                      | ———                     |
| **Detalles_Transacciones** | ———           | ———         | ———               | ———          | ———               | ———              | ———           | ———                   | ———                   | ———           | ———                   | ———           | ———                | contener          | ———             | ———                 | ———         | ———                       | ———              | ———                  | ———                     | ———               | ———          | ———         | ———                      | ———                     |
| **Auditorias**           | ———              | ———         | ———               | ———          | ———               | ———              | ———           | ———                   | ———                   | ———           | ———                   | ———           | ———                | ———               | ———             | ———                 | ———         | realizar                  | ———              | ———                  | ———                     | ———               | ———          | ———         | ———                      | ———                     |
| **Trans_Interbancos**    | ———              | ———         | ———               | ———          | ———               | ———              | ———           | ———                   | ———                   | ———           | ———                   | ———           | ———                | pertenecer        | ———             | ———                 | ———         | ———                       | ———              | ———                  | ———                     | ———               | ———          | ———         | ———                      | ———                     |
| **Estados_Financieros**  | ———              | ———         | ———               | ———          | ———               | ———              | ———           | ———                   | ———                   | ———           | ———                   | ———           | ———                | ———               | ———             | ———                 | ———         | ———                       | ———              | ———                  | ———                     | ———               | ———          | ———         | ———                      | ———                     |
| **Tipos_Usuarios**       | ———              | ———         | ———               | ———          | ———               | ———              | ———           | ———                   | ———                   | ———           | ———                   | ———           | ———                | ———               | ———             | ———                 | ———         | ———                       | ———              | ———                  | ———                     | ———               | tener        | ———         | ———                      | ———                     |
| **Usuarios**             | pertenecer       | ———         | ———               | ———          | ———               | ———              | ———           | ———                   | ———                   | ———           | ———                   | ———           | ———                | ejecutar          | ———             | ———                 | ———         | ———                       | realizar         | ———                  | ———                     | pertenecer        | ———          | realizar   | solicitar               | ———                     |
| **Permisos**             | ———              | ———         | ———               | ———          | ———               | ———              | ———           | ———                   | ———                   | ———           | ———                   | ———           | ———                | ———               | ———             | ———                 | ———         | ———                       | ———              | ———                  | ———                     | ———               | pertenecer    | ———         | obtener                  | ———                     |
| **Asignaciones_Empleados** | ———           | ———         | ———               | ———          | ———               | ———              | ———           | ———                   | ———                   | ———           | ———                   | ———           | tener              | ———               | ———             | ———                 | ———         | ———                       | ———              | ———                  | ———                     | ———               | ———          | ———         | asignar                   | ———                     |
| **Estados_Empleados**    | ———              | ———         | ———               | ———          | ———               | ———              | ———           | ———                   | ———                   | ———           | ———                   | ———           | tener              | ———               | ———             | ———                 | ———         | ———                       | ———              | ———                  | ———                     | ———               | ———          | ———         | pertenecer               | ———                     |


## Modelo Lógico
![Modelo Lógico](../modelos/Modelo_logico_G3.png)

## Modelo Fisico
![Modelo Fisico](../modelos/fisico_G3.png)

## Detalles del modelo:

### Estados_Tarjetas Tarjetas_Credito

Cada Estados_Tarjetas puede estar presente en una o muchas Tarjetas_Credito

Cada Tarjetas_Credito debe tener uno y solo un Estados_Tarjetas

### Tarjetas_Credito Clientes

Cada Clientes puede adquirir una o muchas Tarjetas_Credito

Cada Tarjetas_Credito debe pertenecer a uno y solo un Clientes

### Clientes Prestamos

Cada Clientes puede adquirir uno o muchos Prestamos

Cada Prestamos debe pertenecer a uno y solo un Clientes

### Prestamos Estados_Prestamos

Cada Prestamos debe tener uno y solo un Estados_Prestamos

Cada Estados_Prestamos puede estar presente un uno o muchos Prestamos

### Clientes Cuentas

Cada Clientes puede tener una o muchas Cuentas

Cada Cuentas debe pertenecer a uno y solo un Clientes

### Clientes Transacciones

Cada Clientes puede realizar una o muchas Transacciones

Cada Transacciones debe pertenecer a uno y solo un Clientes

### Tipos_Cuentas Cuentas

Cada Tipos_Cuentas puede estar presente un una o muchas Cuentas

Cada Cuentas debe tener uno y solo un Tipos_Cuentas

### Transacciones Tipos_Trans

Cada Transacciones debe tener un y solo un Tipos_Trans

Cada Tipos_Trans puede estar presente en una o muchas Transacciones

### Transacciones Agencias

Cada Transacciones debe estar registrada en una Agencias

Cada Agencias puede ejecutar una o muchas Transacciones

### Tipos_Agencias Agencias

Cada Tipos_Agencias puede estar presente en una o muchas Agencias

Cada Agencias debe tener uno y solo un Tipos_Agencias

### Agencias Municipios

Cada Agencias debe estar presente en un Municipios

Cada Municipios puede tener ubicada una o muchas Agencias

### Agencias Empleados

Cada Agencias puede tener asignado uno o muchos Empleados

Cada Empleados debe estar trabajando en una Agencias

### Municipios Departamentos

Cada Municipios debe pertenecer a un Departamentos

Cada Departamentos puede tener uno o muchos Municipios

### Roles_Empleados Empleados

Cada Roles_Empleados puede ejecutarse por uno o muchos Empleados

Cada Empleados debe tener asignado un Roles_Empleados

### Empleados Departamentos

Cada Empleados debe estar ubicado en un Departamentos

Cada Departamentos puede ser la ubicacion de uno o muchos Empleados

## Implementación

Para este proyecto usaremos las convenciones de oracle para la sintaxis de SQL.

**Tabla CLIENTES**
```sql
CREATE TABLE clientes (
    cliente_id       NUMBER NOT NULL,
    nombre           VARCHAR2(50) NOT NULL,
    apellido         VARCHAR2(50) NOT NULL,
    telefono         VARCHAR2(20) NOT NULL,
    usuarios_usuario VARCHAR2(30) NOT NULL
);

ALTER TABLE clientes ADD CONSTRAINT clientes_pk PRIMARY KEY ( cliente_id );
```
- Esta tabla almacenara informacion sobre los clientes, se utiliza un campo cliente_id como clave primaria, los campos nombre, apellido y telefono son de tipo "VARCHAR2" debido a que son cadenas de longitud variable, estos campos son utilizados para guardar informacion personal.

**Tabla DEPARTAMENTOS**
```sql
CREATE TABLE departamentos (
    departamento_id NUMBER NOT NULL,
    nombre          VARCHAR2(50) NOT NULL
);

ALTER TABLE departamentos ADD CONSTRAINT departamentos_pk PRIMARY KEY ( departamento_id );
```
- Esta tabla almacena informacion sobre los departamentos del pais, se utiliza un campo departamento_id como clave primaria, el campo nombre es de  tipo "VARCHAR2" debido a que son cadenas de longitud variable.

**Tabla ROLES_EMPLEADOS**
```sql
CREATE TABLE roles_empleados (
    rol_id NUMBER NOT NULL,
    nombre VARCHAR2(50) NOT NULL
);

ALTER TABLE roles_empleados ADD CONSTRAINT roles_empleados_pk PRIMARY KEY ( rol_id );
```
- Esta tabla almacena los distintos roles que existen dentro del banco, se utiliza rol_id como clave primaria, el campo nombre es de tipo "VARCHAR2" debido a que son cadenas de longitud variable, los roles son vistos como el puesto de trabajo dentro del banco.

**Tabla TIPOS_AGENCIAS**
```sql
CREATE TABLE tipos_agencias (
    tipo_id NUMBER NOT NULL,
    tipo    VARCHAR2(10) NOT NULL
);

ALTER TABLE tipos_agencias ADD CONSTRAINT tipos_agencias_pk PRIMARY KEY ( tipo_id );
```
- Esta tabla almacena los distintos tipos de agencias es decir sucursal o agencia, se utiliza tipo_id como clave primaria, el campo tipo es de tipo "VARCHAR2" debido a que son cadenas de longitud variable.

**Tabla TIPOS_CUENTAS**
```sql
CREATE TABLE tipos_cuentas (
    tipo_id NUMBER NOT NULL,
    tipo    VARCHAR2(30) NOT NULL
);

ALTER TABLE tipos_cuentas ADD CONSTRAINT tipos_cuentas_pk PRIMARY KEY ( tipo_id );
```
-  Esta tabla almacena los distintos tipos de cuentas que puede tener un cliente, se utiliza tipo_id como clave primaria, el campo tipo es de tipo "VARCHAR2" debido a que son cadenas de longitud variable, los tipos de cuentas pueden ser monetaria, ahorro, corriente.

**Tabla TIPOS_TRANS**
```sql
CREATE TABLE tipos_trans (
    tipo_id NUMBER NOT NULL,
    tipo    VARCHAR2(30) NOT NULL
);

ALTER TABLE tipos_trans ADD CONSTRAINT tipos_trans_pk PRIMARY KEY ( tipo_id );
```
- Esta tabla almacena los distintos tipos de transacciones que ejecuta el banco, se utiliza tipo_id como clave primaria,  el campo tipo es de tipo "VARCHAR2" debido a que son cadenas de longitud variable, los tipos de transacciones pueden ser: transferencia, deposito, pago, retiro.

**Tabla ESTADOS_PRESTAMOS**
```sql
CREATE TABLE estados_prestamos (
    estado_id NUMBER NOT NULL,
    estado    VARCHAR2(30) NOT NULL
);

ALTER TABLE estados_prestamos ADD CONSTRAINT estados_prestamos_pk PRIMARY KEY ( estado_id );
```
- Esta tabla almacena los distintos estados de un prestamo, se utiliza estado_id como clave primaria, el campo estado es de tipo "VARCHAR2" debido a que son cadenas de longitud variable, los estados de un prestamo pueden ser: activo, vencido, cancelado.

**Tabla ESTADOS_TARJETAS**
```sql
CREATE TABLE estados_tarjetas (
    estado_id NUMBER NOT NULL,
    estado    VARCHAR2(30) NOT NULL
);

ALTER TABLE estados_tarjetas ADD CONSTRAINT estados_tarjetas_pk PRIMARY KEY ( estado_id );
```
- Esta tabla almacena los distintos estados de una tarjeta, se utiliza estado_id como clave primaria, el campo estado es de tipo "VARCHAR2" debido a que son cadenas de longitud variable, las tarjetas pueden estar en estado: activa, bloqueada, cancelada.

**Tabla MUNICIPIOS**
```sql
CREATE TABLE municipios (
    municipio_id                  NUMBER NOT NULL,
    nombre                        VARCHAR2(50) NOT NULL,
    departamentos_departamento_id NUMBER NOT NULL
);

ALTER TABLE municipios ADD CONSTRAINT municipios_pk PRIMARY KEY ( municipio_id );
```
- Esta tabla almacena los distintos municipios del pais, se utiliza municipio_id como clave primaria, nombre es de tipo "VARCHAR2" debido a que son cadenas de longitud variable, departamentos_departamento_id se utiliza para establecer relaciones con la tabla DEPARTAMENTOS como clave foranea.

**Tabla AGENCIAS**
```sql
CREATE TABLE agencias (
    agencia_id              NUMBER NOT NULL,
    nombre                  VARCHAR2(50) NOT NULL,
    direccion               VARCHAR2(50) NOT NULL,
    codigo_postal           CHAR(5) NOT NULL,
    telefono                VARCHAR2(20) NOT NULL,
    tipos_agencias_tipo_id  NUMBER NOT NULL,
    municipios_municipio_id NUMBER NOT NULL,
    bovedas_boveda_id       NUMBER NOT NULL
);

ALTER TABLE agencias ADD CONSTRAINT agencias_pk PRIMARY KEY ( agencia_id );
```

**Tabla CUENTAS**
```sql
CREATE TABLE cuentas (
    cuenta_id             NUMBER NOT NULL,
    numero_de_cuenta      VARCHAR2(30) NOT NULL,
    saldo                 NUMBER(15, 2) NOT NULL,
    tipos_cuentas_tipo_id NUMBER NOT NULL,
    clientes_cliente_id   NUMBER NOT NULL
);

ALTER TABLE cuentas ADD CONSTRAINT cuentas_pk PRIMARY KEY ( cuenta_id );
```

**Tabla EMPLEADOS**
```sql
CREATE TABLE empleados (
    empleado_id                 NUMBER NOT NULL,
    nombre                      VARCHAR2(50) NOT NULL,
    apellido                    VARCHAR2(50) NOT NULL,
    telefono                    VARCHAR2(20) NOT NULL,
    roles_empleados_rol_id      NUMBER NOT NULL,
    estados_empleados_estado_id NUMBER NOT NULL,
    usuarios_usuario            VARCHAR2(30) NOT NULL
);

ALTER TABLE empleados ADD CONSTRAINT empleados_pk PRIMARY KEY ( empleado_id );
```

**Tabla PRESTAMOS**
```sql
CREATE TABLE prestamos (
    prestamo_id                 NUMBER NOT NULL,
    monto_del_prestamo          NUMBER(15, 2) NOT NULL,
    tasa_de_interes             NUMBER(5, 2) NOT NULL,
    fecha_de_desembolso         TIMESTAMP WITH LOCAL TIME ZONE NOT NULL,
    fecha_de_vencimiento        TIMESTAMP WITH LOCAL TIME ZONE NOT NULL,
    saldo_pendiente             NUMBER(15, 2) NOT NULL,
    estados_prestamos_estado_id NUMBER NOT NULL,
    clientes_cliente_id         NUMBER NOT NULL
);

ALTER TABLE prestamos ADD CONSTRAINT prestamos_pk PRIMARY KEY ( prestamo_id );
```
  
**Tabla TARJETAS_CREDITO**
```sql
CREATE TABLE tarjetas_credito (
    tarjeta_id                 NUMBER NOT NULL,
    numero_de_tarjeta          CHAR(16) NOT NULL,
    limite_de_credito          NUMBER(15, 2) NOT NULL,
    saldo_actual               NUMBER(15, 2) NOT NULL,
    fecha_de_emision           TIMESTAMP WITH LOCAL TIME ZONE NOT NULL,
    fecha_de_expiracion        TIMESTAMP WITH LOCAL TIME ZONE NOT NULL,
    fecha_de_corte             TIMESTAMP WITH LOCAL TIME ZONE NOT NULL,
    dia_del_ciclo              NUMBER(2) NOT NULL,
    clientes_cliente_id        NUMBER NOT NULL,
    estados_tarjetas_estado_id NUMBER NOT NULL
);

ALTER TABLE tarjetas_credito ADD CONSTRAINT tarjetas_credito_pk PRIMARY KEY ( tarjeta_id );
```

**Tabla TRANSACCIONES**
```sql
CREATE TABLE transacciones (
    transaccion_id      NUMBER NOT NULL,
    monto               NUMBER(15, 2) NOT NULL,
    fecha               TIMESTAMP WITH LOCAL TIME ZONE NOT NULL,
    hora                TIMESTAMP WITH LOCAL TIME ZONE NOT NULL,
    descripcion         VARCHAR2(250) NOT NULL,
    tipos_trans_tipo_id NUMBER NOT NULL,
    agencias_agencia_id NUMBER NOT NULL,
    cuentas_cuenta_id   NUMBER NOT NULL,
    cuentas_cuenta_id2  NUMBER NOT NULL
);

ALTER TABLE transacciones ADD CONSTRAINT transacciones_pk PRIMARY KEY ( transaccion_id );
```

**Tabla Tarjetas_Debito**
```sql
CREATE TABLE tarjetas_debito (
    tarjeta_id                 NUMBER NOT NULL,
    fecha_de_emision           TIMESTAMP WITH LOCAL TIME ZONE NOT NULL,
    fecha_de_expiracion        TIMESTAMP WITH LOCAL TIME ZONE NOT NULL,
    codigo_cvv                 NUMBER(3) NOT NULL,
    numero_de_tarjeta          NUMBER(16) NOT NULL,
    estados_tarjetas_estado_id NUMBER NOT NULL,
    cuentas_cuenta_id          NUMBER NOT NULL
);

ALTER TABLE tarjetas_debito ADD CONSTRAINT tarjetas_debito_pk PRIMARY KEY ( tarjeta_id );
```
**Tabla Bovedas**
```sql
CREATE TABLE bovedas (
    boveda_id     NUMBER NOT NULL,
    monto_actual  NUMBER NOT NULL,
    capacidad_max NUMBER NOT NULL
);

ALTER TABLE bovedas ADD CONSTRAINT bovedas_pk PRIMARY KEY ( boveda_id );
```
**Tabla Detalles_Transacciones**
```sql
CREATE TABLE detalles_transacciones (
    detalle_trans_id             NUMBER NOT NULL,
    fecha_trans                  TIMESTAMP WITH LOCAL TIME ZONE NOT NULL,
    descripcion                  VARCHAR2(250) NOT NULL,
    empleados_empleado_id        NUMBER NOT NULL,
    transacciones_transaccion_id NUMBER NOT NULL,
    clientes_cliente_id          NUMBER NOT NULL,
    agencias_agencia_id          NUMBER NOT NULL
);

ALTER TABLE detalles_transacciones ADD CONSTRAINT detalles_transacciones_pk PRIMARY KEY ( detalle_trans_id );
```
**Tabla Auditorias**
```sql
CREATE TABLE auditorias (
    auditoria_id           NUMBER NOT NULL,
    descripcion            VARCHAR2(600) NOT NULL,
    fecha_auditoria        TIMESTAMP WITH LOCAL TIME ZONE NOT NULL,
    empleados_empleado_id  NUMBER NOT NULL,
    empleados_empleado_id2 NUMBER NOT NULL
);

ALTER TABLE auditorias ADD CONSTRAINT auditorias_pk PRIMARY KEY ( auditoria_id );
```
**Tabla trans_interbancos**
```sql
CREATE TABLE trans_interbancos (
    id_trans_agencia     NUMBER NOT NULL,
    monto                NUMBER(15, 2) NOT NULL,
    fecha                TIMESTAMP WITH LOCAL TIME ZONE NOT NULL,
    agencias_agencia_id  NUMBER NOT NULL,
    agencias_agencia_id2 NUMBER NOT NULL
);

ALTER TABLE trans_interbancos ADD CONSTRAINT trans_interbancos_pk PRIMARY KEY ( id_trans_agencia );
```
**Tabla Estados_Financieros**
```sql
CREATE TABLE estados_financieros (
    estado_id           NUMBER NOT NULL,
    total_activo        NUMBER NOT NULL,
    total_pasivo        NUMBER NOT NULL,
    total_ingreso       NUMBER NOT NULL,
    total_gasto         NUMBER NOT NULL,
    fecha_corte         TIMESTAMP WITH LOCAL TIME ZONE NOT NULL,
    agencias_agencia_id NUMBER NOT NULL
);

ALTER TABLE estados_financieros ADD CONSTRAINT estados_financieros_pk PRIMARY KEY ( estado_id );
```
**Tabla Tipos_Usuarios**
```sql
CREATE TABLE tipos_usuarios (
    tipo_id NUMBER NOT NULL,
    tipo    VARCHAR2(20) NOT NULL
);

ALTER TABLE tipos_usuarios ADD CONSTRAINT tipos_usuarios_pk PRIMARY KEY ( tipo_id );
```
**Tabla Usuarios**
```sql
CREATE TABLE usuarios (
    usuario                VARCHAR2(30) NOT NULL,
    password               VARCHAR2(30) NOT NULL,
    tipos_usuarios_tipo_id NUMBER NOT NULL,
    permisos_permiso_id    NUMBER NOT NULL
);

ALTER TABLE usuarios ADD CONSTRAINT usuarios_pk PRIMARY KEY ( usuario );
```
**Tabla Permisos**
```sql
CREATE TABLE permisos (
    permiso_id NUMBER NOT NULL,
    permiso    VARCHAR2(30) NOT NULL
);

ALTER TABLE permisos ADD CONSTRAINT permisos_pk PRIMARY KEY ( permiso_id );
```
**Tabla Asignaciones_Empleados**
```sql
CREATE TABLE asignaciones_empleados (
    asignacion_id         NUMBER NOT NULL,
    fecha_inicio          TIMESTAMP WITH LOCAL TIME ZONE NOT NULL,
    fecha_fin             TIMESTAMP WITH LOCAL TIME ZONE,
    agencias_agencia_id   NUMBER NOT NULL,
    empleados_empleado_id NUMBER NOT NULL
);

ALTER TABLE asignaciones_empleados ADD CONSTRAINT asignaciones_empleados_pk PRIMARY KEY ( asignacion_id );
```
**Tabla Estados_Empleados**
```sql
CREATE TABLE estados_empleados (
    estado_id NUMBER NOT NULL,
    estado    VARCHAR2(20) NOT NULL
);

ALTER TABLE estados_empleados ADD CONSTRAINT estados_empleados_pk PRIMARY KEY ( estado_id );
```
