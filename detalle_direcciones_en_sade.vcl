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

# http://apache2-q3:8080/browse/SWDEV-1137
# OBSERVATORIOS
#Gender Equality Observatory for Latin America and the Caribbean
#if (std.tolower(req.url) ~ "/en/observatories/gender-equality-observatory-latin-america-and-caribbean") { set req.url = "/oig/default.asp?idioma=IN" ; }
#if (std.tolower(req.url) ~ "/es/observatorio/observatorio-de-igualdad-de-genero-de-america-latina-y-el-caribe") { set req.url = "/oig/" ; }

# Observatory of Latin America and the Caribbean
if (std.tolower(req.url) ~ "/en/observatories/observatory-latin-america-and-caribbean") { set req.url = "/ofilac/default.asp?idioma=IN" ; }
if (std.tolower(req.url) ~ "/es/observatorio/observatorio-fiscal-de-latinoamerica-y-el-caribe") { set req.url = "/ofilac/" ; }

#Regional Broadband Observatory / Observatorio Regional de Banda Ancha
#if (std.tolower(req.url) ~ "/en/observatories/regional-broadband-observatory") { set req.url = "/socinfo/orba/" ; }
#if (std.tolower(req.url) ~ "/es/observatorio/observatorio-regional-de-banda-ancha") { set req.url = "/socinfo/orba/" ; }

#Organos subsidiarios
#Caribbean Development and Cooperation Committee
#if (std.tolower(req.url) ~ "/en/subsidiary-bodies/caribbean-development-and-cooperation-committee") { set req.url = "/cgi-bin/getProd.asp?xml=/portofspain/noticias/paginas/2/42762/P42762.xml&base=/portofspain/tpl/top-bottom.xsl" ; }
#if (std.tolower(req.url) ~ "/es/organos-subsidiarios/comite-de-desarrollo-y-cooperacion-del-caribe") { set req.url = "/cgi-bin/getProd.asp?xml=/portofspain/noticias/paginas/2/42762/P42762.xml&base=/portofspain/tpl/top-bottom.xsl" ; }

# Committee on South-South Cooperation
#if (std.tolower(req.url) ~ "/en/subsidiary-bodies/committee-south-south-cooperation") { set req.url = "/cgi-bin/getProd.asp?xml=/cooperacion/noticias/paginas/4/25934/P25934.xml&xsl=/cooperacion/tpl/p18f.xsl&base=/cooperacion/tpl-i/top-bottom.xsl" ; }
#if (std.tolower(req.url) ~ "/es/organos-subsidiarios/comite-de-cooperacion-sur-sur") { set req.url = "/cgi-bin/getprod.asp?xml=/cooperacion/noticias/paginas/6/25916/P25916.xml&xsl=/cooperacion/tpl/p18f.xsl&base=/cooperacion/tpl/top-bottom.xsl" ; }

#if (std.tolower(req.url) ~ "/en/subsidiary-bodies/regional-conference-women-latin-america-and-caribbean") { set req.url = "/cgi-bin/getprod.asp?xml=/mujer/noticias/paginas/8/28478/P28478.xml&xsl=/mujer/tpl/p18f-st.xsl&base=/tpl/e-mail.xsl" ; }
#if (std.tolower(req.url) ~ "/es/organos-subsidiarios/conferencia-regional-sobre-la-mujer-de-america-latina-y-el-caribe") { set req.url = "/cgi-bin/getprod.asp?xml=/mujer/noticias/paginas/8/28478/P28478.xml&xsl=/mujer/tpl/p18f-st.xsl&base=/tpl/e-mail.xsl" ; }

#Regional Council for Planning of ILPES 
##########--> en redirect de Drupal NO INDICAR IDIOMA ORIGEN !!
## así Desde taxonomy/term/8168	hacia http://iis7-e2.cepal.org/crp-ilpes
#if (std.tolower(req.url) ~ "/en/subsidiary-bodies/regional-council-planning-ilpes") { set req.url = "/crp-ilpes/" ; }
#if (std.tolower(req.url) ~ "/es/organos-subsidiarios/consejo-regional-de-planificacion-del-ilpes") { set req.url = "/crp-ilpes/" ; }

#statistical Conference of the Americas
#if (std.tolower(req.url) ~ "/en/subsidiary-bodies/statistical-conference-americas") { error 751 "/deype/ceacepal/index2.htm";}
#if (std.tolower(req.url) ~ "/es/organos-subsidiarios/conferencia-estadistica-de-las-americas") { error 751 "/deype/ceacepal/";}


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