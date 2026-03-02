# Conceptos de Herencia en C++

Este documento contiene las explicaciones necesarias para comprender y realizar el ejercicio de herencia de clases en C++.

---

## 1. ¿Qué es la Herencia?

La **herencia** es un mecanismo de la Programación Orientada a Objetos (POO) que permite crear una nueva clase a partir de una clase existente. La nueva clase **hereda** atributos y métodos de la clase original, y puede añadir los suyos propios o modificar el comportamiento heredado.

**Analogía**: Piensa en la herencia como la relación entre un padre y un hijo. El hijo hereda características del padre (color de ojos, apellido) pero también puede tener características propias (profesión, hobbies). En C++, la clase "padre" se llama **clase base** y la clase "hija" se llama **clase derivada**.

```cpp
// Clase base (padre)
class Vehiculo {
    // Atributos y métodos comunes a todos los vehículos
};

// Clase derivada (hija): hereda de Vehiculo
class Coche : public Vehiculo {
    // Atributos y métodos propios del coche
    // + todo lo que hereda de Vehiculo
};
```

**Ventajas de la herencia:**
- **Reutilización de código**: No repites lo que ya está en la clase base.
- **Organización**: Agrupas lo común en la base y lo específico en las derivadas.
- **Extensibilidad**: Puedes añadir nuevas clases derivadas sin tocar la base.

---

## 2. Clase Base y Clase Derivada

### Clase base (superclase)
Es la clase de la que se hereda. Contiene los atributos y métodos **comunes** a todas las clases que hereden de ella.

### Clase derivada (subclase)
Es la clase que hereda de otra. Además de lo que hereda, puede tener sus propios atributos y métodos.

```cpp
// Base: lo común
class Vehiculo {
private:
    std::string marca;
    std::string modelo;
    int anio;
public:
    void mostrarInformacion();  // Común a todos los vehículos
};

// Derivada: lo común + lo específico del coche
class Coche : public Vehiculo {
private:
    int numeroPuertas;  // Específico del coche
public:
    void mostrarInformacion();  // Puede redefinirse para incluir puertas
};
```

---

## 3. Sintaxis de Herencia

La sintaxis para declarar una clase derivada es:

```cpp
class ClaseDerivada : public ClaseBase {
    // miembros de la clase derivada
};
```

- **`ClaseDerivada`**: nombre de la nueva clase.
- **`:`**: indica que hereda de otra clase.
- **`public ClaseBase`**: tipo de herencia y nombre de la clase base.

### Tipos de herencia (resumen)

| Herencia   | Acceso a `public` en base | Acceso a `protected` en base |
|-----------|----------------------------|------------------------------|
| `public`  | Sigue siendo `public` en derivada  | Sigue siendo `protected` en derivada  |
| `protected` | Pasa a `protected` en derivada | Sigue siendo `protected` en derivada  |
| `private` | Pasa a `private` en derivada   | Pasa a `private` en derivada   |

En este material usaremos **herencia pública** (`public ClaseBase`), que es la más habitual cuando queremos que la derivada sea un "tipo de" la base.

---

## 4. Modificador `protected`

En herencia aparece un tercer modificador de acceso: **`protected`**.

- **`private`**: Solo la propia clase puede acceder. Las clases derivadas **no** pueden acceder.
- **`protected`**: La propia clase y las clases derivadas pueden acceder. El resto del programa, no.
- **`public`**: Cualquiera puede acceder.

Si quieres que un atributo o método sea usado por la clase base y por las derivadas, pero no por el resto del programa, decláralo **`protected`**.

```cpp
class Vehiculo {
protected:
    std::string marca;   // La derivada puede usar marca y modelo
    std::string modelo;
    int anio;
private:
    int idInterno;       // Solo Vehiculo; la derivada no puede acceder
public:
    std::string obtenerMarca();  // Cualquiera puede llamar
};
```

---

## 5. Constructores en Herencia

Cuando creas un objeto de una clase derivada, primero se ejecuta el constructor de la **clase base** y después el de la **clase derivada**. No puedes tener un objeto derivado sin que antes se haya construido la parte base.

### Llamada al constructor de la base

En el constructor de la clase derivada debes indicar qué constructor de la base quieres usar. Se hace en la **lista de inicialización** (antes del cuerpo del constructor), con la sintaxis `ClaseBase(...)`.

```cpp
// En vehiculo.h
class Vehiculo {
protected:
    std::string marca;
    std::string modelo;
    int anio;
public:
    Vehiculo();
    Vehiculo(std::string marca, std::string modelo, int anio);
};

// En coche.h
class Coche : public Vehiculo {
private:
    int numeroPuertas;
public:
    Coche();
    Coche(std::string marca, std::string modelo, int anio, int numeroPuertas);
};
```

```cpp
// En coche.cpp

// Constructor por defecto del Coche: llama al constructor por defecto de Vehiculo
Coche::Coche() : Vehiculo() {
    numeroPuertas = 0;
}

// Constructor con parámetros: pasa los datos del vehículo a la base
Coche::Coche(std::string marca, std::string modelo, int anio, int numeroPuertas)
    : Vehiculo(marca, modelo, anio) {
    this->numeroPuertas = numeroPuertas;
}
```

**Orden de ejecución:** primero `Vehiculo(...)`, luego el cuerpo de `Coche(...)`.

Si no escribes `: Vehiculo(...)` en el constructor de `Coche`, el compilador intentará llamar al constructor por defecto de `Vehiculo`. Por eso la base debe tener constructor por defecto si la derivada no va a llamar explícitamente a otro.

---

## 6. Sobrescritura de Métodos (Override)

Cuando una clase derivada define un método con el **mismo nombre y la misma firma** que uno de la clase base, se dice que **sobrescribe** (override) ese método. Al llamar al método sobre un objeto de la clase derivada, se ejecuta la versión de la derivada, no la de la base.

```cpp
// En Vehiculo
void Vehiculo::mostrarInformacion() {
    std::cout << "Marca: " << marca << std::endl;
    std::cout << "Modelo: " << modelo << std::endl;
    std::cout << "Año: " << anio << std::endl;
}

// En Coche: misma firma, comportamiento extendido
void Coche::mostrarInformacion() {
    Vehiculo::mostrarInformacion();  // Reutilizar código de la base
    std::cout << "Número de puertas: " << numeroPuertas << std::endl;
}
```

**Llamar al método de la base desde la derivada:**  
`ClaseBase::nombreMetodo(...)` — así evitas duplicar código y mantienes el comportamiento de la base.

---

## 7. Acceso a Miembros Heredados

Desde la clase derivada puedes:
- Usar los miembros **`public`** y **`protected`** de la base directamente (por nombre).
- Usar un método de la base con `ClaseBase::metodo()` si lo estás sobrescribiendo y quieres llamar a la versión base.

Desde `main()` (o código externo):
- Solo puedes usar los miembros **`public`** de la clase base y de la derivada.
- Un objeto de tipo `Coche` puede usar métodos públicos de `Vehiculo` (heredados) y de `Coche`.

```cpp
Coche c("Toyota", "Corolla", 2020, 4);
c.mostrarInformacion();   // Si es público en Coche o en Vehiculo, se puede llamar
c.obtenerMarca();         // Método público de Vehiculo, heredado por Coche
```

---

## 8. Destructores en Herencia

Si defines destructores, el orden de ejecución es el **contrario** al de los constructores: primero se ejecuta el destructor de la **clase derivada** y después el de la **clase base**.

```cpp
// Primero se ejecuta ~Coche(), después ~Vehiculo()
```

Para las prácticas de este material no es obligatorio definir destructores; se menciona para que conozcas el orden cuando más adelante uses memoria dinámica.

---

## 9. Resumen: Pasos para Usar Herencia

1. **Diseñar la clase base**: Atributos y métodos comunes. Usa `protected` para lo que la derivada deba usar.
2. **Declarar la clase derivada**: `class Derivada : public Base { ... };`
3. **Constructores de la derivada**: En la lista de inicialización llama al constructor de la base, por ejemplo `: Base(...)`.
4. **Atributos y métodos propios**: Añade lo específico de la derivada.
5. **Sobrescribir métodos** (opcional): Misma firma que en la base; dentro puedes llamar a `Base::metodo()` si conviene.
6. **Usar objetos**: Crea objetos de la derivada; ellos incluyen todo lo de la base más lo propio.

---

## 10. Ejemplo Completo (Esquema)

```cpp
// vehiculo.h
class Vehiculo {
protected:
    std::string marca;
    std::string modelo;
    int anio;
public:
    Vehiculo();
    Vehiculo(std::string marca, std::string modelo, int anio);
    void mostrarInformacion();
    std::string obtenerMarca();
};

// coche.h
class Coche : public Vehiculo {
private:
    int numeroPuertas;
public:
    Coche();
    Coche(std::string marca, std::string modelo, int anio, int numeroPuertas);
    void mostrarInformacion();  // Sobrescribe el de Vehiculo
    int obtenerNumeroPuertas();
};
```

En el ejercicio y en el programa ejemplo verás este esquema aplicado con archivos `.h` y `.cpp` separados, igual que en el material de clases.

---

¡Con estos conceptos estás listo para el ejercicio de herencia!
