## Build

1. Estando en el root del proyecto generar una carpeta build
2. Ejecutar dentro de la carpeta build
  1. `conan install ..`
  2. `cmake ..`
  3. `make [all | enterprise | manager]`

## Run

### Tests

1. Dentro de build acceder a: `src/enterprise/bin`
2. `./ test-enterprise`

### App

1. Dentro de build acceder a: `src/manager`
2. `./manager`

## Notas

- Librería `enterprise` funcional y acabada.
- La aplicación `manager` inacabada.


