# 🗃️ CPP Module 05 – Excepciones, Formularios y Jerarquías Burocráticas

> ✅ **Objetivo:** Dominar el uso de **excepciones**, el diseño de **jerarquías de clases** y la manipulación de objetos mediante **referencias/punteros abstractos**, con un enfoque especial en la separación de interfaz e implementación.
> ✅ **Nivel:** Medio-Avanzado
> ✅ **Temas clave:** excepciones, herencia, clases abstractas, polimorfismo, factorías, funciones virtuales, organización de código

---

## 📚 Tabla de Contenidos

1. [Excepciones en C++](#-1-excepciones-en-c)
2. [Clase Bureaucrat: límites y reglas](#-2-clase-bureaucrat-límites-y-reglas)
3. [Clase Form: validaciones y firma](#-3-clase-form-validaciones-y-firma)
4. [Clases derivadas y ejecución](#-4-clases-derivadas-y-ejecución)
5. [Intern y Factory Pattern](#-5-intern-y-factory-pattern)
6. [Errores Comunes](#-6-errores-comunes)
7. [Buenas Prácticas](#-7-buenas-prácticas)

---

## 🔹 1. Excepciones en C++

📘 **¿Qué son?**
Las **excepciones** son una forma de controlar errores en tiempo de ejecución sin usar códigos de error manuales.

🎯 En este módulo se crean clases de excepción personalizadas como `GradeTooHighException` o `GradeTooLowException`, derivadas de `std::exception`.

🧪 **Ejemplo:**

```cpp
try
{
    Bureaucrat b("John", 151); // ❌ Grade too low
}
catch (std::exception &e)
{
    std::cerr << e.what() << std::endl;
}
```

---

## 🔹 2. Clase Bureaucrat: límites y reglas

📘 **¿Qué contiene?**

* `std::string const _name`
* `int _grade` (rango válido: 1 a 150)
* Funciones:

  * `incrementGrade()`
  * `decrementGrade()`
  * `signForm(Form&)`
  * `executeForm(AForm&)`

🔐 Cualquier operación que cause un `grade` fuera de rango lanza excepción.

🧪 **Output esperado:**

```bash
Alice, bureaucrat grade 5
Alice signed Form42
```

---

## 🔹 3. Clase Form: validaciones y firma

📘 **Características clave:**

* Atributos constantes: nombre, grados requeridos para firma/ejecución
* Funciones:

  * `beSigned(Bureaucrat&)`
  * `getName()`, `getIsSigned()`, etc.

⚠️ Si el grado del burócrata es demasiado bajo para firmar, lanza `GradeTooLowException`.

🧪 **Output esperado:**

```bash
Alice couldn't sign Form42 because grade too low
```

---

## 🔹 4. Clases derivadas y ejecución

📘 **AForm y sus derivados:**

1. `ShrubberyCreationForm`: escribe árboles ASCII en `<target>_shrubbery`
2. `RobotomyRequestForm`: 50% éxito robotomizando a `<target>`
3. `PresidentialPardonForm`: indulta a `<target>`

🔁 **Método común:**

* `execute(Bureaucrat const &executor) const`
  (verifica si el formulario está firmado y si el executor tiene suficiente rango)

🧪 **Ejemplo de uso:**

```cpp
form->execute(bureaucrat);
```

📄 **Output:**

```bash
Alice executed PresidentialPardonForm
```

---

## 🔹 5. Intern y Factory Pattern

📘 **Objetivo:** crear formularios a partir de un string.

🧠 **Intern::makeForm(nombre, target)**
Devuelve un puntero a `AForm` adecuado según el nombre.

🎯 Usar array de structs o punteros a funciones para evitar `if/else` excesivo.

🧪 **Output esperado:**

```bash
Intern creates RobotomyRequestForm
```

---

## 🔹 6. Errores Comunes

❌ Crear formularios con grados inválidos
❌ Ejecutar formularios no firmados
❌ Lógica complicada con `if/else if/else`
❌ Usar mal `std::exception` y no sobrescribir `what()`
❌ No aplicar Orthodox Canonical Form en clases requeridas

---

## 🔹 7. Buenas Prácticas

✅ Implementa `Orthodox Canonical Form` en todas las clases
✅ Usa referencias o punteros a `AForm` para polimorfismo
✅ Valida siempre rango de `grade` al construir o modificar
✅ Implementa correctamente el operador `<<` para logs
✅ Utiliza `try/catch` para capturar excepciones controladamente

---

## Autor 🤝💡📬

<div align="center">
  <a href="https://github.com/jfercode">
    <img src="https://github.com/jfercode.png" width="100px" alt="Javier Fernández Correa" />
    <br />
    <sub><b>Javier Fernández Correa</b></sub>
  </a>
</div>

---

## Licencia 📜✅🗝️

Este proyecto está bajo la licencia MIT. ⚖️📄🆓
