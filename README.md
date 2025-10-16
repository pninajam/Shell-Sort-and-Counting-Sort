# Comparación de Algoritmos de Ordenamiento

Proyecto de análisis de tiempo de ejecución entre **Shell Sort** y **Counting Sort** con diferentes tamaños de datos.

Autors 
- Pedro Pablo Ninaja Medina
- Jairo Brayan Zegarra Gutierrez
- Arturo Willy Montalico Llica
📁 Estructura del Proyecto
```
proyecto/
├── include/
│   ├── shellsort.h          # Declaración de Shell Sort
│   └── countingsort.h       # Declaración de Counting Sort
├── src/
│   ├── main.cpp             # Programa principal
│   ├── shellsort.cpp        # Implementación de Shell Sort
│   ├── countingsort.cpp     # Implementación de Counting Sort
│   └── results              # Resultados CSV (creado automáticamente)
├── data/                    # Datos generados (creado automáticamente)
├── Makefile                 # Compilación del proyecto
├── .gitignore              # Archivos ignorados por Git
└── README.md               # Documentación
```

## 🚀 Compilación y Ejecución

### Requisitos
- g++ con soporte para C++17
- make

### Compilar
```bash
make
```

### Ejecutar
```bash
make run
```

### Limpiar archivos compilados
```bash
make clean
```

### Limpiar todo (incluye datos y resultados)
```bash
make clean-all
```

## 📊 Funcionamiento

El programa:
1. Genera datos aleatorios de tamaños: **10, 100, 1000, 10000 y 100000** elementos
2. Guarda los datos en archivos `.txt` en la carpeta `data/`
3. Ejecuta ambos algoritmos de ordenamiento
4. Mide el tiempo de ejecución en milisegundos
5. Guarda los resultados en `src/results.csv`

## 📈 Resultados

Los resultados se guardan en formato CSV con las columnas:
- **Tamaño**: Cantidad de elementos
- **ShellSort(us)**: Tiempo de ejecución de Shell Sort
- **CountingSort(us)**: Tiempo de ejecución de Counting Sort

## 🔍 Algoritmos Implementados

### Shell Sort
- **Archivo**: `shellsort.h` / `shellsort.cpp`
- Complejidad promedio: O(n log n)
- Usa la secuencia de gaps original de Shell (n/2, n/4, ..., 1)

### Counting Sort
- **Archivo**: `countingsort.h` / `countingsort.cpp`
- Complejidad: O(n + k) donde k es el rango de valores
- Ideal para números enteros en un rango conocido
- No es comparativo

## 📝 Ejemplo de Uso

```bash
# Compilar y ejecutar
make run

# Ver resultados
cat results/results.csv

# Ver datos generados
ls data/
```

## 👨‍💻 Autor
