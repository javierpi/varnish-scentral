
## Varnish para sitio central www.cepal.org
# Usa a Drupal y SADE como servidores de backend
# En primera instancia solicita a Drupal todas las consultas, si recibe 404 hace la consulta a SADE.
##################

acl internal {
    ## Estas IP recibirán todos los mensajes de debug 
   # "10.0.17.152";  ## Javier
   # "10.0.17.116";  ## Javier
  
}

acl purge {
		"10.0.0.0"/16; ## cepal santiago completa
		# para poder hacer purge desde back-end (Administracion de contenidos en Drupal)
		 "localhost";
		 "127.0.0.1";
}
import std;
 
#DEFAULT Back End -- CEPALWEB
backend drupal
{
	.host = "webpro.cepal.org"; 
	.port = "80";
    .max_connections = 200;
    .connect_timeout = 3.5s;
    .first_byte_timeout = 60s;
    .between_bytes_timeout = 60s;
}
backend drupal443
{
	.host = "webpro.cepal.org"; 
	.port = "8443";
    .max_connections = 400;
    .connect_timeout = 3.5s;
    .first_byte_timeout = 60s;
    .between_bytes_timeout = 60s;
}
#SADE
backend sade 
{
   .host = "10.0.9.56";
   .port = "80";
   .connect_timeout = 5s;
   .first_byte_timeout = 120s;
   .between_bytes_timeout = 120s;
}
/*  Para pruebas también, se ha creado el subdominio cepalorg.cepal.org el que es dominio correcto.
*/
 include "detalle_redirecciones.vcl";
 include "detalle_direcciones_en_sade.vcl";
 include "error_generico.vcl";
 include "cierre_sitios_sade.vcl";
 include "ip_bloqueadas.vcl";
 


sub centraliza_dominios{
	## 
	# CU-01: Reescribir dominio. www.cepal.cl, www.eclac.cl y www.eclac.org se redireccionan a www.cepal.org
	## CU-01:------------- Desde acá 
	#
	if (std.tolower(req.http.host) ~ "^(www\.)cepal\.cl" || 
        std.tolower(req.http.host) ~ "^(www\.)eclac\.cl"  ||
        std.tolower(req.http.host) ~ "^(www\.)eclac\.org" ) 
    {
        error 750 "http://www.cepal.org" + req.url;
        
    } 
	
	## 
	# CU-02: Redirigir a SADE dominios existentes, con código 302:
	# socinfo.cepal.org
	# www.ilpes.cl
	# www.ofilac.org
	# www.eclacpos.org
	# www.cepal.org.mx
	## CU-02:------------- Desde acá 
	
	if (std.tolower(req.http.host) ~ "^www.ofilac.org") 
    {
		error 751 "http://www.cepal.org/ofilac" + req.url;
    }
	## CU-02 - HASTA ACÁ
}
sub limpia_url{
	## http://apache2-q3:8080/browse/SWDEV-1097
	set req.url = regsuball(req.url, "&AMP;", "&");
	set req.url = regsuball(req.url, "&amp;", "&");
	
	if (client.ip ~ ataca) {
		error 753 "";
	}
	## revisa entrada por agente
	call bad_agent;
	###
	
}
# Respond to incoming requests.
sub vcl_recv {
	
	call limpia_url;
	
	if (req.url ~ "PURGE" || req.request == "PURGE") {
        if (client.ip ~ purge) {
			# =============================================
			# Se pasa solicitud de Purge desde URL a Request 
			set req.request = "PURGE";
			# Se quita PURGE de la URL
			set req.url = regsub(req.url, "\/PURGE", "");
			# =============================================
			return(lookup);
		}else{
            error 404 "Not allowed";
        }
    }
	# CU-01 y 02: Redirigir a SADE dominios existentes:
	##
	call centraliza_dominios;
	
	# Force client.ip forwarding
	#remove req.http.X-Forwarded-For;
	#set req.http.X-Forwarded-For = client.ip;
	# 		std.tolower(req.url) ~ "^/drni/biee*" 	||  	
	if (
		##
		# CU-03 Análisis de Aplicaciones en el servidor back_sade
		# std.tolower(req.url) ~ "^/celade/migracion/migracion_interna*" 	||  
		##
		
		std.tolower(req.url) ~ "^/aecid/memoriaaecid*" 	||  
		std.tolower(req.url) ~ "^/badepro*" 	||  
		std.tolower(req.url) ~ "^/cap_comercio*" 	||  
		std.tolower(req.url) ~ "^/comercio/aftis*" 	||  
		std.tolower(req.url) ~ "^/dds/InnovacionSocial*" 	||  
		std.tolower(req.url) ~ "^/drni/proyectos*" 	||  
		std.tolower(req.url) ~ "^/indicadores*" 	||  
		std.tolower(req.url) ~ "^/magicplus*" 	||  
		std.tolower(req.url) ~ "^/mujer/proyectos*" 	||  
		std.tolower(req.url) ~ "^/notas*" 	||  
		std.tolower(req.url) ~ "^/notas_p*" 	||  
		std.tolower(req.url) ~ "^/notes*" 	||  
		std.tolower(req.url) ~ "^/povertystatistics*" 	||  
		std.tolower(req.url) ~ "^/pses31foto*" 	||  
		std.tolower(req.url) ~ "^/publicaciones/mail*" 	||  
		std.tolower(req.url) ~ "^/iydws*" 	||  
		std.tolower(req.url) ~ "^/magicws*" 	||  
		std.tolower(req.url) ~ "^/ticws*" 	||  
		std.tolower(req.url) ~ "^/rio10*" 	||  
		std.tolower(req.url) ~ "^/ServiciosEditoriales*" 	||  
		std.tolower(req.url) ~ "^/ses29*" 	||  
		std.tolower(req.url) ~ "^/tic*" 	||  
		std.tolower(req.url) ~ "^/treeeditor*" ||
		std.tolower(req.url) ~ "^/crossdomain.xml" ||	
		std.tolower(req.url) ~ "^/magic/*" 
	)
	{
		set req.backend = sade;
		## retorno con Pipe: No hace caché, cortocircuitea entre cliente y servidor
		# return(pipe);
		
		/* Not cacheable by default */
        return (pass);
	#-------------------------------------------
	
	} else { 
		#  No cachear post a SADE 
		if (req.request == "POST" && req.url ~ "\.(asmx|asp)") {
			set req.backend = sade;
			return (pass);
		}
		#-------------------------------------------
		#  Desde Drupal
		#  Dirije a SADE URLS de Drupal que no están listas.
		#  Son direcciones que si existen 
		call DireccionesEnSade;
		#  Se agregan en el mismo archivo segunda subrutina, direcciones de sitios que serán cerrados
		#  pero hay proyectos que seguirán en IIS, son casos como de los sitios de comercio o celade
		# 
		call ProyectosQueQuedanenSADE;
		#-------------------------------------------
		
		#-------------------------------------------
		#  Se guarda número de restarts 
		set req.http.x-restarts = req.restarts;
		#-------------------------------------------
		
		if (req.restarts == 0) {
			#############################################
			## es primera solicitud-> debe ir a drupal
			#############################################
			#  Se guarda solicitud 
			set req.http.x-url = req.url;
			### Cambio transitorio 
			##  es solamente mientras se da servicio por puerto 80 y 9443 simultáneamente
			############################
			if (server.port == 9443) {
			   set req.backend = drupal443;
			}
			  else {
			   set req.backend = drupal;
			}
			############################
			if (!req.backend.healthy) {
				unset req.http.Cookie;
				# Allow the backend to serve up stale content if it is responding slowly.
				set req.grace = 6h;
			}
			
			call redirecciona_a_drupal;

			call prepara_drupal;
			## Utiliza caché de varnish para entregar esta página
			return(lookup);
		} 
		else if (req.restarts == 1) {
			##################################################
			## Segunda vuelta, debe ir a sade con url original
			##################################################
			## utiliza url inicial solicitada por usuario
			set req.url = req.http.x-url;	
			set req.backend = sade;
			#####################################
			# por cierre de sitio SADE
			call analiza_sitio_cerrado_sade;			
			# ###################################
			set req.http.x-restarts = req.restarts;

			#  No cachear post
			if (req.request == "POST"){
				return (pass);
			}
			
			if (std.tolower(req.url) ~ "\.(asmx|pdf|asp|doc|docx|xls|ppt|swf)") {
   				/* Not cacheable by default */
				## No se cachean aplicaciones o archivos que 
				# queremos mantener registro en logs
				return (pass);
			}else{
				#con caché
				# retorna lookup
				return(lookup);
			}
		}else if (req.restarts > 1) {
			set req.http.x-restarts = req.restarts;
			# Sobrepasa cantidad de restart.
			# set req.http.x-mensaje = req.http.x-mensaje + "(..request > 1)";
			error 753 "";
			
		} else {
			set req.http.x-restarts = req.restarts;
			# llego POR DONDE NO DEBIA
		}
	 }
}

sub prepara_drupal{
		if (!req.backend.healthy) {
			unset req.http.Cookie;
		}
			
		# Allow the backend to serve up stale content if it is responding slowly.
		set req.grace = 600s;
		  # Do not cache these paths.
		  if (
				std.tolower(req.url) ~ "^.*/ajax/.*$" ||
				std.tolower(req.url) ~ "^.*/ahah/.*$" ||
				std.tolower(req.url) ~ "/search"
			  ) 
			  { 
				# set req.http.x-mensaje =  req.http.x-mensaje +"(f:prepara_drupal:pass1)";
			    return (pass);
		  }
 
		  # Do not allow outside access to cron.php or install.php.
		  if (
				std.tolower(req.url) ~ "^/cron\.php$"  ||
				std.tolower(req.url) ~ "^/status\.php$" ||
				std.tolower(req.url) ~ "^/update\.php$" ||
				std.tolower(req.url) ~ "^/install\.php$" ||
				std.tolower(req.url) ~ "^/admin$" ||
				std.tolower(req.url) ~ "^/admin/.*$" ||
				std.tolower(req.url) ~ "^/es\/admin*$" ||
				std.tolower(req.url) ~ "^/en\/admin*$" ||
				# Agregados luego de ver el contenido del archivo robots.txt de Drupal
				# Tienen que ver con http://apache2-q3:8080/browse/SWDEV-1396
				std.tolower(req.url) ~ "/scripts/" ||
				std.tolower(req.url) ~ "changelog.txt" ||
				std.tolower(req.url) ~ "install.mysql.txt" ||
				std.tolower(req.url) ~ "install.pgsql.txt" ||
				std.tolower(req.url) ~ "install.sqlite.txt" ||
				std.tolower(req.url) ~ "install.txt" ||
				std.tolower(req.url) ~ "license.txt" ||
				std.tolower(req.url) ~ "maintainers.txt" ||
				std.tolower(req.url) ~ "upgrade.txt" ||
				std.tolower(req.url) ~ "xmlrpc.php" ||
				std.tolower(req.url) ~ "/filter/tips/" ||
				std.tolower(req.url) ~ "/user/login/" ||
				std.tolower(req.url) ~ "/user/password/" ||
				std.tolower(req.url) ~ "/user/logout/" ||
				std.tolower(req.url) ~ "/?q=admin/" ||
				std.tolower(req.url) ~ "/?q=node/add/" ||
				std.tolower(req.url) ~ "/?q=comment/reply/" ||
				std.tolower(req.url) ~ "/?q=filter/tips/" ||
				std.tolower(req.url) ~ "/?q=user/password/" ||
				std.tolower(req.url) ~ "/?q=user/register/" ||
				std.tolower(req.url) ~ "/?q=user/login/" ||
				std.tolower(req.url) ~ "/?q=user/logout/" ||
				std.tolower(req.url) ~ "/?q=user" ||
				# Hasta acá las incorporaciones
				std.tolower(req.url) ~ "^/user$" ||
				std.tolower(req.url) ~ "^/es\/user$" ||
				std.tolower(req.url) ~ "^/en\/user$" ||
				std.tolower(req.url) ~ "^/update\.php$" ||
				std.tolower(req.url) ~ "^/node\/add$" ||
				std.tolower(req.url) ~ "^/es\/node\/add$" ||
				std.tolower(req.url) ~ "^/en\/node\/add$" ||
				std.tolower(req.url) ~ "^/opcache/.*$" ||
				std.tolower(req.url) ~ "^/info/.*$" ||
				std.tolower(req.url) ~ "^/flag/.*$" ||
				## Por ataque 24-04-15
				std.tolower(req.url) ~ "/?q=.*$"	|| 
				std.tolower(req.url) ~ "/user.*$" 	||
				std.tolower(req.url) ~ "/admin.*$"  || 
				std.tolower(req.url) ~ "/node\/add.*$" 
			){
			## error 403 "Forbidden.";
			# set obj.status = 403;
			#error 404 "Not found.";
			error 752 "";
		  }
		  
		#  No cachear post
		if (req.request == "POST"){
			return (pass);
		}

		# Always cache the following file types for all users. This list of extensions
		# appears twice, once here and again in vcl_fetch so make sure you edit both
		# and keep them equal.
		if (std.tolower(req.url) ~ "(?i)\.(pdf|asc|dat|txt|doc|xls|ppt|tgz|csv|png|gif|jpeg|jpg|ico|swf|css|js)(\?.*)?$") {
			unset req.http.Cookie;
		}
		if (req.url ~ "(\?itok=)([a-zA-Z0-9]+)?$") {
			unset req.http.Cookie;
		}
		
		if (req.http.Cookie) {
			# 1. Append a semi-colon to the front of the cookie string.
			# 2. Remove all spaces that appear after semi-colons.
			# 3. Match the cookies we want to keep, adding the space we removed
			#    previously back. (\1) is first matching group in the regsuball.
			# 4. Remove all other cookies, identifying them by the fact that they have
			#    no space after the preceding semi-colon.
			# 5. Remove all spaces and semi-colons from the beginning and end of the
			#    cookie string.
			set req.http.Cookie = ";" + req.http.Cookie;
			set req.http.Cookie = regsuball(req.http.Cookie, "; +", ";");   
			set req.http.Cookie = regsuball(req.http.Cookie, ";(SESS[a-z0-9]+|SSESS[a-z0-9]+|NO_CACHE)=", "; \1=");
			set req.http.Cookie = regsuball(req.http.Cookie, ";[^ ][^;]*", "");
			set req.http.Cookie = regsuball(req.http.Cookie, "^[; ]+|[; ]+$", "");
			if (req.http.Cookie == "") {
				# If there are no remaining cookies, remove the cookie header. If there
				# aren't any cookie headers, Varnish's default behavior will be to cache
				# the page.
				unset req.http.Cookie;
				# set req.http.x-mensaje =  req.http.x-mensaje +"(unset req.http.Cookie 2) ";
			} else {
				# If there is any cookies left (a session or NO_CACHE cookie), do not
				#	cache the page. Pass it on to Apache directly.
				# set req.http.x-mensaje =  req.http.x-mensaje +"(aun hay cookie, pasa con PASS) ";
				# set req.http.x-mensaje =  req.http.x-mensaje +"(f:prepara_drupal:pass3)";
				return (pass);
			}
		}
}
sub redirecciona_a_drupal{
	# set req.http.x-mensaje =  req.http.x-mensaje +"(f:redirecciona_a_drupal) ";
	#############################################
	# Caso de productos (id de sade) a una dirección en drupal
	call redireccionaProductosManual;
	#############################################
	#############################################
	# 06-11-2014
	# Redirecciones desde ubicaciones No hechas por el CMS hacia Drupal u otros dominios 
	call redireccionaSADE_Libre;
	#############################################
	
	## si la URL tiene un patron de SADE con id, se transforma como URL Drupal
	## Caso 1: que sea solicitud /cgi-bin
	## Ojo, sacar caso de los agrupadores
	if (std.tolower(req.url) ~ "\/cgi-bin" && !  std.tolower(req.url) ~ "\/agrupadores_xml" ){
		# set req.http.x-mensaje =  req.http.x-mensaje +"(Caso 1: que sea solicitud /cgi-bin) ";
		## Expresiones regulares programadas con confirmación en http://regex101.com/
		## En base a las siguientes URL

		# Paso url a minúsculas para hacer comparación y reemplazo acá abajo
		set req.url = std.tolower(req.url);
		## 1:  cgi-bin/getProd.asp?xml=/prensa/noticias/comunicados/6/49436/P49436.xml&xsl=/prensa/tpl/p6f.xsl&base=/prensa/tpl/top-bottom.xsl
		set req.url = regsub(req.url, "cgi-bin\/getprod\.asp\?", "");
		## Quito Base
		set req.url = regsub(req.url, "&base=\/[%.A-z0-9\/-]*", "");
		set req.url = regsub(req.url, "%26base%3D\/[%.A-z0-9\/-]*", "");
		## Quito el xsl
		set req.url = regsub(req.url, "[&]xsl=\/[%.A-z0-9\/-]+", "");
		## trato al XML
		set req.url = regsub(req.url, "xml=\/[%.A-z0-9\/-]+\/+[pP]", "");
		set req.url = regsub(req.url, "\.xml", "");
		if ( req.url ~ "formularios" || req.url ~ "\/noticias\/vacantes\/default") {
			## No debe llegar a drupal si solicitan formularios.
			## Los formularios no están migrados 
			## Drupal debe dar error 404
			set req.url = "/errordedrupalrequeridoporformulariossade/" + req.url ;
		}else{
			set req.url = "/es/idxsade" + req.url ;
			set req.http.x-Newurl = req.url;
		}
	
	}
	## Caso 2: que sea solicitud por ID => /id.asp?id=
	if (std.tolower(req.url) ~ "id\.asp") {
		## Transforma solicitud x id de SADE a solicitud x id de Drupal
		set req.url = regsub(req.url, "id\.asp\?id=", "/es/idxsade/");
		## Quito Base
		set req.url = regsub(req.url, "&base=\/[%.A-z0-9\/-]*", "");
		set req.url = regsub(req.url, "%26base%3D\/[%.A-z0-9\/-]*", "");
		
		set req.http.x-Newurl = req.url;
	}

#	----------------------------------------------------------------------
#	-----> caso 3 eliminado
#		   No se centralizaron los archivos en carpeta LEGACY por lo que no es necesario y trabaja mal la solicitud del archivo www.cepal.org/robots
#	----------------------------------------------------------------------
	
	## Caso 4: Caso llegar a la ficha de un archivo (pdf, excel, etc.) para las publicaciones
	if (std.tolower(req.url) ~ "\.(pdf|asc|dat|txt|doc|docx|xls|ppt|tgz|csv|swf)" && std.tolower(req.url) ~ "^/publicaciones") {               ## quitado el 4/feb/2015
		# elimino todo lo anterior al número de carpeta ->[/9/]<-2244/nombredearchivo.aaa
		set req.url = regsub(req.url, "\/[%.A-z0-9\/-]+\/[0-9]\/", "");
		# elimino todo el resto luego del slash
		set req.url = regsub(req.url, "\/[%.A-z0-9\/-]+", "");
		## Quito Base
		set req.url = regsub(req.url, "&base=\/[%.A-z0-9\/-]*", "");
		# Hago búsqueda en Drupal
		set req.url = "/es/idxsade/" + req.url ;
		
	}
	## Almaceno URL solicitada
	set req.http.url_cortada = req.url;
	## Quito Base
	set req.url = regsub(req.url, "&base=\/[%.A-z0-9\/-]*", "");
	call redireccionaPortadasYAgrupadores;
	## Se vuelve a poner URL anterior
	set req.url = req.http.url_cortada;

}


sub vcl_hit { 
	if (req.request == "PURGE") {
        purge;
        error 204 "Purged";
    }
}

sub vcl_miss{
	if (req.request == "PURGE") {
        purge;
        error 204 "Purged (Not in cache)";
    }
 }

sub vcl_deliver {
	if (client.ip ~ internal) {
		set resp.http.X-IE-Device = req.http.X-IE-Device;
		set resp.http.x-BackServerName = req.http.x-BackServerName;
		set resp.http.x-mensaje = req.http.x-mensaje;
		set resp.http.x-restarts =  req.restarts;
		set resp.http.x-req.url = resp.http.x-req.url + req.url;
		if (obj.hits > 0) {
				set resp.http.X-Cache-Varnish = "HIT:" + obj.hits ;
		} else {
				set resp.http.X-Cache-Varnish = "MISS";
		}
	}else{
		remove resp.http.x-BackServerName;
		remove resp.http.X-Drupal-Cache;
		remove resp.http.x-host;
		remove resp.http.X-IE-Device;
		remove resp.http.X-UA-Compatible;
		remove resp.http.x-url;
		remove resp.http.Via;
		remove resp.http.X-Whatever;
		remove resp.http.X-Powered-By;
		remove resp.http.X-Varnish;
		remove resp.http.Age;
		remove resp.http.Server;
		remove resp.http.x-mensaje;
		remove resp.http.Via;
		remove resp.http.X-Cache-Varnish;
		remove resp.http.x-req.url;
		remove resp.http.x-restarts;
		# para Drupal, Varnish ban type BAN LUCKER, es necesario agregar estas dos variables
		# es/admin/config/development/varnish
		unset resp.http.x-host; # Optional
		unset resp.http.x-url; # Optional
		# -----------------------------------------------------------------------------------
	}
	set resp.http.X-Forwarded-For = req.http.X-Forwarded-For;
}
 
sub vcl_fetch {
	if (beresp.status == 404) {
		## este es el retorno de SADE
		return(restart);
	}
	
	if (beresp.status == 500){
		error 500 "";
	}
	if (beresp.status == 403 ){
		error 403 "";
	}
	if (std.tolower(req.url) ~ "(?i)\.(pdf|asc|dat|txt|doc|xls|ppt|tgz|csv|png|gif|jpeg|jpg|ico|swf|css|js)(\?.*)?$") {
		unset beresp.http.set-cookie;
    }
	
	set req.http.x-BackServerName = beresp.backend.name;
	
	# 12-Dic-2014: Se define TTL a objetos SADE para que queden  en caché
	if ( beresp.backend.name == "sade") {
			set beresp.ttl = 1209600s;
			set beresp.http.Cache-Control = "public, max-age=1209600";
	}
	# No cookies on Drupal 7.21 image derivatives
	if ( req.url ~ "(\?itok=)([a-zA-Z0-9]+)?$") {
		unset beresp.http.set-cookie;
	}
	# Si tiempo de vida es menor a 120 seg. se ajusta a 120 segundos
	if (beresp.ttl < 120s) {
		set beresp.ttl = 120s;
	}
	
	#------------------------------------------------------------------------------------
	# para Drupal, Varnish ban type BAN LUCKER, es necesario agregar estas dos variables
	# es/admin/config/development/varnish
	# Indicado en https://www.drupal.org/node/1423560
	# set obj.http.x-host = req.host;
	# set obj.http.x-url = req.url;
	# Arreglado en comentarios # 8
	set beresp.http.x-url = req.url;
	set beresp.http.x-host = req.http.host;
	#------------------------------------------------------------------------------------
	
}

sub vcl_error {
	if (obj.status == 750) {
		set obj.http.Location = obj.response;
        #HTTP 301 para indicar redirección permanente
        set obj.status = 301;
        return(deliver);
    }
	if (obj.status == 751) {
		set obj.http.Location = obj.response;
        #HTTP 302 para indicar redirección temporal - Así estaba en IIS
        set obj.status = 302;
        return(deliver);
    }
	## No se ha encontrado
	if (obj.status == 753) {
		set obj.status = 404;
		call error_404;
        return(deliver);
	}
	
	## Acceso denegado. Han enviado URL que se ha programado no entregar.
	if (obj.status == 752) {
		set obj.status = 404;
		call error_404;
        return(deliver);
	}
	
	## Si no encuentra el contenido, cambie de back_end
	if (obj.status == 404 && req.restarts < 2) {
			return(restart);
	} else if (obj.status == 404 ) {
		call error_404;
        return(deliver);
  	}
	
	if (obj.status == 403 ) {
		call error_403;
        return(deliver);
	} 
	if (obj.status == 500 ) {
		call error_500;
        return(deliver);
	}
	if (obj.status == 503 ) {
		call error_503;
		return(deliver);
	}
	
}
sub vcl_pipe {
    # Al habilitar estas dos opciones, se logra enviar la ip del 
	# visitante a IIS y aplicaciones SADE que comenzaron a utilizanr 
	# la variable req.http.X-Forwarded-For
	
}
