# BUGS GROCERY

Método vender productos: 

`¿Pago recibido? [y/n]:`
`y`
`Producto leche con id: 12 eliminado`
`Producto      con id: 0 eliminado`
`free(): double free detected in tcache 2`

`Process finished with exit code 134 (interrupted by signal 6: SIGABRT)`

Tal vez sea pq estamos devolviendo más valores, por ejemplo, cuando agregamos más de un producto al carrito. 

Al parecer se trata de un problema de alocamiento de memoria. 

El error s[olo aperece] si le doy en no volver al men[u] inicial

## Mejoras

Se agregó una emulación de base de datos, ya que si se implkementaba una base de datos real sería reestructurar todo el proyecto. 

![](/home/guerrero/Pictures/Screenshot from 2021-11-23 20-53-33.png)

