********************************************************************************
**** 1.                     MODULO DE MIGRACIÓN                             ****
********************************************************************************



El módulo de migración contiene la funcionalidad básica para migrar tipos de
contenido.



***********************
* 2.     MODO DE USO  *
*                     **********************************************************

El módulo se basa en el módulo Migrate y por lo tanto la funcionalidad de
importación es la que tiene ese módulo.
La interfaz de administración se encuentra en:
admin/content/migrate
donde hay que elegir las migraciones que se van a ejecutar.

2.1 Comunicados
Se necesita hacer las siguientes modificaciones:
2.1.1 Guardar una carpeta con las imagenes de los comunicados
2.1.2 Guardar una carpeta con los archivos de los comunicados
2.1.3 Guardar el xml de PressRelease
@see http://jpi-w7/sade_ws/Service1.asmx?op=GetPressReleases
2.1.4 Guardar el xml de las imágenes de PressRelease
@see http://jpi-w7/sade_ws/Service1.asmx?op=GetPressReleaseImage
2.1.4 Guardar el xml de los archivos de PressRelease
@see http://jpi-w7/sade_ws/Service1.asmx?op=GetPressReleaseFile

2.1.5 Modificar el archivo config/migrar.config.xml para representar las rutas
de los archivos y carpetas añadidos en los puntos anteriores.
2.1.6 Ejecutar vía Drush:
drush mi ComunicadoXML


****************************
* 3.    IMPLEMENTACIONES   *
*                          *****************************************************

Para implementar una migracion de un tipo de contenido, hay que implementar
un archivo como el que se ha implementado en "proyecto.inc".
Debe extender desde la clase abstracta BaseMigracion e implementar la interface
BaseMigracionInterface.
Se debe agregar la informacion de la conexion con el webservice y de las
carpetas de guardado temporal en el archivo:
migrar.config.xml

En particular se puede tomar como referencia la configuracion de "proyecto".

********************************************************************************