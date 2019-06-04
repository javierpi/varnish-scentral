sub analiza_sitio_cerrado_sade{
	
	if (std.tolower(req.url) ~ "/publicaciones/search.asp") {
		error 750 "/es/publicaciones";
	}
	if (std.tolower(req.url) ~ "^/revista" || std.tolower(req.url) ~ "/revista/") {
		 set req.url = "/es/publicaciones/tipo/revista-cepal";
		 set req.backend = drupal;
	}
	
	if (std.tolower(req.url) ~ "^/cooperacion" || std.tolower(req.url) ~ "/cooperacion/") {
		error 750 "/es/cooperacion";
	}
	
	if (std.tolower(req.url) ~ "^/dmaah" || std.tolower(req.url) ~ "/dmaah/") {
		error 750 "/es/areas-de-trabajo/desarrollo-sostenible-y-asentamientos-humanos";
	}
	
	if (std.tolower(req.url) ~ "^/dppo" || std.tolower(req.url) ~ "/dppo/") {
		error 750 "/es/cooperacion";
	}
	
	if (std.tolower(req.url) ~ "^/ddpe" || std.tolower(req.url) ~ "/ddpe/") {
		error 750 "/es/areas-de-trabajo/desarrollo-productivo-y-empresarial";
	}
	if (std.tolower(req.url) == "/de" || std.tolower(req.url) ~ "/de/") {
		# el '/deype' podría considerarse valido en analisis 'std.tolower(req.url) ~ "^/de"
		# se evalua funcionamiento de std.tolower(req.url) == "/de"
		error 750 "/es/areas-de-trabajo/desarrollo-economico";
		set req.http.x-mensaje = req.http.x-mensaje + "(Cierre de SADE: /de/)";
	}
	
	if (std.tolower(req.url) ~ "^/argentina" || std.tolower(req.url) ~ "/argentina/") {
		error 750 "/es/sedes-y-oficinas/cepal-buenos-aires";
	}
	if (std.tolower(req.url) ~ "^/comercio" || std.tolower(req.url) ~ "/comercio/") {
		error 750 "/es/areas-de-trabajo/comercio-internacional";
	}
	
	# SWDEV-2344
	# Apagado sade sitios fase 3 
	if (std.tolower(req.url) ~ "^/dds" || std.tolower(req.url) ~ "/dds/") {
		error 750 "/es/areas-de-trabajo/desarrollo-social";
	}
	# Se quita redirección de mujer 
	# http://apache2-q3:8080/browse/SWDEV-2473
	
	if (std.tolower(req.url) ~ "^/transporte" || std.tolower(req.url) ~ "/transporte/" ) {
		error 750 "/es/temas/logistica-y-movilidad";
	}

	if (std.tolower(req.url) ~ "^/drni" || std.tolower(req.url) ~ "/drni/" ) {
		error 750 "/es/areas-de-trabajo/recursos-naturales-e-infraestructura";
	}
	
	# SWDEV-2487
	# Apagado sade sitios fase 4
	if (std.tolower(req.url) ~ "^/washington" || std.tolower(req.url) ~ "/washington/" ) {
		error 750 "/en/headquarters-and-offices/eclac-washington-dc";
	}
	if (std.tolower(req.url) ~ "^/brasil" || std.tolower(req.url) ~ "/brasil/" ) {
		error 750 "/pt-br/sedes-e-escritorios/cepal-brasilia";
	}
	if (std.tolower(req.url) ~ "^/colombia" || std.tolower(req.url) ~ "/colombia/" ) {
		error 750 "/es/sedes-y-oficinas/cepal-bogota";
	}
	if (std.tolower(req.url) ~ "^/uruguay" || std.tolower(req.url) ~ "/uruguay/" ) {
		error 750 "/es/sedes-y-oficinas/cepal-montevideo";
	}
	
	# SWDEV-2538
	# Apagado sade sitios fase 5
	if (std.tolower(req.url) ~ "^/mexico" || std.tolower(req.url) ~ "/mexico/" ) {
		error 750 "/es/sedes-y-oficinas/cepal-mexico";
	}
	if (std.tolower(req.url) ~ "^/portofspain" || std.tolower(req.url) ~ "/portofspain/" ) {
		error 750 "/en/headquarters-and-offices/eclac-caribbean";
	}
	
	# SWDEV-2568
	if (std.tolower(req.url) ~ "^/ccas" || std.tolower(req.url) ~ "/ccas/" ) {
		error 750 "/es/proyectos/euroclima";
	}
	
	# http://apache2-q3:8080/browse/SWDEV-2658
	if (std.tolower(req.url) ~ "^/biblioteca" || std.tolower(req.url) ~ "=/biblioteca/" ) {
		error 750 "/es/biblioteca";
	}
	if (std.tolower(req.url) ~ "^/library"  ) {
		error 750 "/en/eclac-libraries";
	}
	# http://apache2-q3:8080/browse/SWDEV-2704
	if (std.tolower(req.url) ~ "^/tradefacilitation" || std.tolower(req.url) ~ "=/tradefacilitation/" ) {
		error 750 "/es/temas/facilitacion-del-comercio";
	}
	if (std.tolower(req.url) ~ "^/ford" || std.tolower(req.url) ~ "=/ford/" ) {
		error 750 "/es/temas/macroeconomia";
	}
	if (std.tolower(req.url) ~ "^/bialfa" || std.tolower(req.url) ~ "=/bialfa/" ) {
		error 750 "/es/areas-de-trabajo/poblacion-y-desarrollo";
	}
	
	# http://apache2-q3:8080/browse/SWDEV-2735
	if (std.tolower(req.url) ~ "^/desastres" || std.tolower(req.url) ~ "=/desastres/" ) {
		error 750 "/es/temas/desastres";
	}
	
	# http://jira-p1.cepal.org:8088/browse/OBS-138
	if (std.tolower(req.url) ~ "^/oig" || std.tolower(req.url) ~ "=/oig/" ) {
		error 750 "http://oig.cepal.org/";
	}
	# http://soporteweb.cepal.org:8088/browse/SWDEV-3180
	if (std.tolower(req.url) ~ "^/elac2015" || std.tolower(req.url) ~ "=/elac2015/" ) {
		error 750 "/es/proyectos/elac2018";
	}
	# http://soporteweb.cepal.org:8088/browse/VSC-3
	if (std.tolower(req.url) ~ "^/perfil" || std.tolower(req.url) ~ "=/perfil/" ) {
		error 751 "http://perfil.cepal.org/l/en/start.html";
	}
	# http://soporteweb.cepal.org:8088/browse/VSC-6
	if (std.tolower(req.url) ~ "^/aecid" || std.tolower(req.url) ~ "=/aecid/" ) {
		error 750 "/es/proyectos/programa-cooperacion-tecnica-cepal-aecid";
	}
	# http://soporteweb.cepal.org:8088/browse/VSC-8
	if (std.tolower(req.url) ~ "^/analisis" || std.tolower(req.url) ~ "=/analisis/" ) {
		error 750 "/es/publications/list";
	}
	# http://soporteweb.cepal.org:8088/browse/SWDEV-3705
	if (std.tolower(req.url) ~ "^/deype" || std.tolower(req.url) ~ "=/deype/" ) {
		error 750 "/es/areas-de-trabajo/estadisticas";
	}
	## 
	## https://gitlab.cepal.org/uweb/web/issues/47
	if (std.tolower(req.url) ~ "^/celade" || std.tolower(req.url) ~ "=/celade/" ) {
		error 750 "/es/areas-de-trabajo/poblacion-y-desarrollo";
	}
}
