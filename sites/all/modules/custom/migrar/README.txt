********************************************************************************
****                     MODULO DE MIGRACIÓN                                ****
********************************************************************************



El módulo de migración contiene la funcionalidad básica para migrar tipos de
contenido.



***********************
*     MODO DE USO     *
*                     **********************************************************

El módulo se basa en el módulo Migrate y por lo tanto la funcionalidad de
importación es la que tiene ese módulo.
La interfaz de administración se encuentra en:
admin/content/migrate
donde hay que elegir las migraciones que se van a ejecutar.



**************************
*    IMPLEMENTACIONES    *
*                        *******************************************************

Para implementar una migracion de un tipo de contenido, hay que implementar
un archivo como el que se ha implementado en "proyecto.inc".
Debe extender desde la clase abstracta BaseMigracion e implementar la interface
BaseMigracionInterface.
Se debe agregar la informacion de la conexion con el webservice y de las
carpetas de guardado temporal en el archivo:
migrar.config.xml

En particular se puede tomar como referencia la configuracion de "proyecto".

********************************************************************************