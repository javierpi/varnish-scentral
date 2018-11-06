sub DireccionesEnSade{
## Archivo de direcciones Drupal que se necesita enviar a SADE
## Mantención del archivo es manual
## Recordar que:
## ~ es búsqueda dentro del texto
## ^ es inicio
## == Identico
## /xxxxx es redirección dentro de varnish
## error 750 es redirección permanente, con código 301 que llega al visitante. Indique URL completa, protocolo://xxx.xxxx.xx:[puerto]/url
## error 751 es redirección temporal, se enviará código 302 que llega al visitante. Indique URL completa, protocolo://xxx.xxxx.xx:[puerto]/url

## Caso especial
# http://apache2-q3:8080/browse/SWFNC-286
## solo www.ilpes.org/"  será redirigido a /es/areas-de-trabajo/planificacion-para-el-desarrollo
if (std.tolower(req.http.host) ~ "^www.ilpes.cl") { error 750 "http://www.cepal.org/es/areas-de-trabajo/planificacion-para-el-desarrollo" ;}
if (std.tolower(req.http.host) ~ "^socinfo.cepal.org" || std.tolower(req.http.host) ~ "^socinfo.eclac.org") { error 750 "http://www.cepal.org/es/temas/tecnologias-de-la-informacion-y-las-comunicaciones-tic" ;}
##

# Observatory of Latin America and the Caribbean
if (std.tolower(req.url) ~ "/en/observatories/observatory-latin-america-and-caribbean") { set req.url = "/ofilac/default.asp?idioma=IN" ; }
if (std.tolower(req.url) ~ "/es/observatorio/observatorio-fiscal-de-latinoamerica-y-el-caribe") { set req.url = "/ofilac/" ; }

#  https://gitlabpro-d.cepal.org/uweb/observatoriop10/issues/21
if (std.tolower(req.url) ~ "/es/acuerdodeescazu/paises") { error 750 "https://observatoriop10.cepal.org/es/tratados/acuerdo-regional-acceso-la-informacion-la-participacion-publica-acceso-la-justicia-asuntos" ; }
if (std.tolower(req.url) ~ "/en/escazuagreement/countries") { error 750 "https://observatoriop10.cepal.org/en/treaties/regional-agreement-access-information-public-participation-and-justice-environmental" ; }

## JIRA: http://apache2-q3:8080/browse/SWDEV-554
## FR
# error 750 "http://www.cepal.org";}
if (std.tolower(req.url) == "/fr") { error 750 "http://www.cepal.org/es" ; }
if (std.tolower(req.url) == "/fr/work-areas") { error 750 "http://www.cepal.org/es/areas-de-trabajo" ; }
if (std.tolower(req.url) == "/fr/cooperation") { error 750 "http://www.cepal.org/es/cooperacion" ; }
if (std.tolower(req.url) == "/fr/publications") { error 750 "http://www.cepal.org/es/publicaciones" ; }
if (std.tolower(req.url) == "/fr/training") { error 750 "http://www.cepal.org/es/capacitacion" ; }
if (std.tolower(req.url) == "/fr/press") { error 750 "http://www.cepal.org/es/centro-de-prensa" ; }
if (std.tolower(req.url) == "/fr/events") { error 750 "http://www.cepal.org/es/eventos" ; }
if (std.tolower(req.url) == "/fr/events/past") { error 750 "http://www.cepal.org/es/eventos/pasados" ; }
if (std.tolower(req.url) == "/fr/events/calendar") { error 750 "http://www.cepal.org/es/events/calendar" ; }
if (std.tolower(req.url) == "/fr/about/office-of-the-executive-secretary") { error 750 "http://www.cepal.org/es/acerca/secretaria-ejecutiva" ; }
if (std.tolower(req.url) == "/fr/headquarters-and-offices") { error 750 "http://www.cepal.org/es/sedes-y-oficinas" ; }
if (std.tolower(req.url) == "/fr/about/former-executive-secretaries") { error 750 "http://www.cepal.org/es/acerca/exsecretarios-ejecutivos" ; }
if (std.tolower(req.url) == "/fr/node/18558") { error 750 "http://www.cepal.org/es/acerca" ; }

if (std.tolower(req.url) ~ "^/fr/taxonomy/term/*") { error 750 "http://www.cepal.org" + regsuball(req.url,"/fr/taxonomy/term/","/es/taxonomy/term/"); }
if (std.tolower(req.url) ~ "^/fr/news/list*") { error 750 "http://www.cepal.org" + regsuball(req.url,"/fr/news/list","/es/news/list"); }
if (std.tolower(req.url) ~ "^/fr/publications/list/*") { error 750 "http://www.cepal.org" + regsuball(req.url,"/fr/publications/list/","/es/publications/list/") ; }
if (std.tolower(req.url) ~ "^/fr/events/list*") { error 750 "http://www.cepal.org" + regsuball(req.url,"/fr/events/list","/es/events/list"); }
if (std.tolower(req.url) ~ "^/fr/projects/list*") { error 750 "http://www.cepal.org" + regsuball(req.url,"/fr/projects/list","/es/projects/list") ; }


} 
sub ProyectosQueQuedanenSADE{
	if (
		std.tolower(req.url) ~ "/comercio/ecdata2/"  ||
		std.tolower(req.url) ~ "/comercio/hhibysector/"  ||
		std.tolower(req.url) ~ "/comercio/observatorio/" ||
		std.tolower(req.url) ~ "/drni/biee/" 
		
	) 
	{ 
		set req.backend = sade;
		return(pass);
	}
}