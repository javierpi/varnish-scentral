sub redireccionaPortadasYAgrupadores{
if (std.tolower(req.url) == "/") { error 750 "/es";}
if (std.tolower(req.url) == "/default.asp") { error 750 "/es";}
### if (std.tolower(req.url) == "/default.asp?idioma=es") { error 750 "/es";}
if (std.tolower(req.url) == "/publicaciones/") { error 750 "/es/publications";}
if (std.tolower(req.url) == "/publicaciones/default.asp") { error 750 "/es/publications";}
### if (std.tolower(req.url) == "/publicaciones/default.asp?idioma=es") { error 750 "/es/publications";}
if (std.tolower(req.url) == "/frances/") { error 750 "/en";}
if (std.tolower(req.url) == "/frances/default.asp") { error 750 "/en";}
### if (std.tolower(req.url) == "/frances/default.asp?idioma=es") { error 750 "/en";}
if (std.tolower(req.url) == "/publicaciones/ebooks/") { error 750 "/es/publicaciones/epub";}
if (std.tolower(req.url) == "/publicaciones/ebooks/default.asp") { error 750 "/es/publicaciones/epub";}
### if (std.tolower(req.url) == "/publicaciones/ebooks/default.asp?idioma=es") { error 750 "/es/publicaciones/epub";}
if (std.tolower(req.url) == "/publicaciones/ebooks_listado/") { error 750 "/es/publicaciones/epub";}
if (std.tolower(req.url) == "/publicaciones/ebooks_listado/default.asp") { error 750 "/es/publicaciones/epub";}
### if (std.tolower(req.url) == "/publicaciones/ebooks_listado/default.asp?idioma=es") { error 750 "/es/publicaciones/epub";}
if (std.tolower(req.url) == "/default.asp?idioma=in") { error 750 "/en";}
if (std.tolower(req.url) == "/publicaciones/default.asp?idioma=in") { error 750 "/en/publications";}
if (std.tolower(req.url) == "/noticias/noticias/") { error 750 "/es/news/list/field_news_type/2/language/es";}
if (std.tolower(req.url) == "/noticias/noticias/default.asp") { error 750 "/es/news/list/field_news_type/2/language/es";}
###if (std.tolower(req.url) == "/noticias/noticias/default.asp?idioma=es") { error 750 "/es/news/list/field_news_type/2/language/es";}
if (std.tolower(req.url) == "/noticias/calendarioactividades/") { error 750 "/es/events";}
if (std.tolower(req.url) == "/noticias/calendarioactividades/default.asp") { error 750 "/es/events";}
###if (std.tolower(req.url) == "/noticias/calendarioactividades/default.asp?idioma=es") { error 750 "/es/events";}
if (std.tolower(req.url) == "/agenda/") { error 750 "/es/eventos";}
if (std.tolower(req.url) == "/agenda/default.asp") { error 750 "/es/eventos";}
###if (std.tolower(req.url) == "/agenda/default.asp?idioma=es") { error 750 "/es/eventos";}
if (std.tolower(req.url) == "/noticias/vacantes/") { error 750 "/es/oportunidades-de-empleo";}
if (std.tolower(req.url) == "/noticias/vacantes/default.asp") { error 750 "/es/oportunidades-de-empleo";}
###if (std.tolower(req.url) == "/noticias/vacantes/default.asp?idioma=es") { error 750 "/es/oportunidades-de-empleo";}
if (std.tolower(req.url) == "/noticias/noticias/default.asp?idioma=in") { error 750 "/en/news/list/field_news_type/2/language/en";}
if (std.tolower(req.url) == "/agenda/default.asp?idioma=in") { error 750 "/en/events";}
if (std.tolower(req.url) == "/noticias/calendarioactividades/default.asp?idioma=in") { error 750 "/en/events";}
if (std.tolower(req.url) == "/noticias/vacantes/default.asp?idioma=in") { error 750 "/en/oportunidades-de-empleo";}
if (std.tolower(req.url) == "/socinfo/publicaciones/") { error 750 "/es/publications/list/field_topic/105";}
if (std.tolower(req.url) == "/socinfo/publicaciones/default.asp") { error 750 "/es/publications/list/field_topic/105";}
### if (std.tolower(req.url) == "/socinfo/publicaciones/default.asp?idioma=es") { error 750 "/es/publications/list/field_topic/105";}
if (std.tolower(req.url) == "/socinfo/") { error 750 "/es/temas/tecnologias-de-la-informacion-y-las-comunicaciones-tic";}
if (std.tolower(req.url) == "/socinfo/default.asp") { error 750 "/es/temas/tecnologias-de-la-informacion-y-las-comunicaciones-tic";}
### if (std.tolower(req.url) == "/socinfo/default.asp?idioma=es") { error 750 "/es/temas/tecnologias-de-la-informacion-y-las-comunicaciones-tic";}
if (std.tolower(req.url) == "/socinfo/default.asp?idioma=in") { error 750 "/en/topics/information-and-communications-technologies-icts";}
if (std.tolower(req.url) == "/socinfo/noticias/noticias/") { error 750 "/es/news/list/field_topic/information-and-communications-technologies-icts-105";}
if (std.tolower(req.url) == "/socinfo/noticias/noticias/default.asp") { error 750 "/es/news/list/field_topic/information-and-communications-technologies-icts-105";}
###if (std.tolower(req.url) == "/socinfo/noticias/noticias/default.asp?idioma=es") { error 750 "/es/news/list/field_topic/information-and-communications-technologies-icts-105";}
if (std.tolower(req.url) == "/celade/") { error 750 "/es/areas-de-trabajo/poblacion-y-desarrollo";}
if (std.tolower(req.url) == "/celade/default.asp") { error 750 "/es/areas-de-trabajo/poblacion-y-desarrollo";}
### if (std.tolower(req.url) == "/celade/default.asp?idioma=es") { error 750 "/es/areas-de-trabajo/poblacion-y-desarrollo";}
if (std.tolower(req.url) == "/celade/indigenas/") { error 750 "/es/temas/pueblos-indigenas-y-afrodescendientes";}
if (std.tolower(req.url) == "/celade/indigenas/default.asp") { error 750 "/es/temas/pueblos-indigenas-y-afrodescendientes";}
### if (std.tolower(req.url) == "/celade/indigenas/default.asp?idioma=es") { error 750 "/es/temas/pueblos-indigenas-y-afrodescendientes";}
if (std.tolower(req.url) == "/celade/migracion/") { error 750 "/es/temas/migracion-internacional";}
if (std.tolower(req.url) == "/celade/migracion/default.asp") { error 750 "/es/temas/migracion-internacional";}
### if (std.tolower(req.url) == "/celade/migracion/default.asp?idioma=es") { error 750 "/es/temas/migracion-internacional";}
if (std.tolower(req.url) == "/celade/censos2010/") { error 750 "/es/temas/censos-de-poblacion-y-vivienda";}
if (std.tolower(req.url) == "/celade/censos2010/default.asp") { error 750 "/es/temas/censos-de-poblacion-y-vivienda";}
### if (std.tolower(req.url) == "/celade/censos2010/default.asp?idioma=es") { error 750 "/es/temas/censos-de-poblacion-y-vivienda";}
if (std.tolower(req.url) == "/celade/envejecimiento/") { error 750 "/es/temas/envejecimiento";}
if (std.tolower(req.url) == "/celade/envejecimiento/default.asp") { error 750 "/es/temas/envejecimiento";}
### if (std.tolower(req.url) == "/celade/envejecimiento/default.asp?idioma=es") { error 750 "/es/temas/envejecimiento";}
if (std.tolower(req.url) == "/celade/minterna/") { error 750 "/es/temas/migracion-interna";}
if (std.tolower(req.url) == "/celade/minterna/default.asp") { error 750 "/es/temas/migracion-interna";}
### if (std.tolower(req.url) == "/celade/minterna/default.asp?idioma=es") { error 750 "/es/temas/migracion-interna";}
if (std.tolower(req.url) == "/celade/default.asp?idioma=in") { error 750 "/en/work-areas/population-and-development";}
if (std.tolower(req.url) ~ "/celade/agrupadores_xml/aes51.xml") { error 751 "http://repositorio.cepal.org/handle/11362/71/browse?order=desc";}
if (std.tolower(req.url) ~ "/celade/agrupadores_xml/aes59.xml") { error 751 "http://repositorio.cepal.org/handle/11362/15/browse?value=CELADE+-+Divisi%C3%B3n+de+Poblaci%C3%B3n&type=division&order=desc";}
if (std.tolower(req.url) ~ "/celade/agrupadores_xml/aes62.xml") { error 751 "http://repositorio.cepal.org/handle/11362/65/browse?type=dateissued&order=desc";}
if (std.tolower(req.url) ~ "/celade/agrupadores_xml/aes94.xml") { error 750 "/es/courses/upcomming/work-area/8169";}
if (std.tolower(req.url) ~ "/celade/agrupadores_xml/aes234.xml") { error 750 "/es/events/past/work-area/population-and-development-8169";}
if (std.tolower(req.url) ~ "/celade/agrupadores_xml/aes235.xml") { error 750 "/es/events/past/topic/ageing-34";}
if (std.tolower(req.url) ~ "/celade/agrupadores_xml/aes414.xml") { error 750 "/es/publications/list/field_topic/indigenous-peoples-and-afro-descendants-91/field_work_area_v2/population-and-development-8169/language/es";}
if (std.tolower(req.url) ~ "/celade/agrupadores_xml/aes457.xml") { error 750 "/es/events/past/topic/indigenous-peoples-and-afro-descendants-91";}
if (std.tolower(req.url) ~ "/celade/agrupadores_xml/aes485.xml") { error 750 "/es/publications/list/field_topic/internal-migration-69/field_work_area_v2/population-and-development-8169/language/es";}
if (std.tolower(req.url) ~ "/celade/agrupadores_xml/aes488.xml") { error 750 "/es/events/past/work-area/population-and-development-8169";}
if (std.tolower(req.url) ~ "/celade/agrupadores_xml/aes691.xml") { error 750 "/es/events/past/work-area/population-and-development-8169";}
if (std.tolower(req.url) ~ "/celade/agrupadores_xml/aes692.xml") { error 750 "/es/publications/list/field_topic/population-and-housing-censuses-10/field_work_area_v2/population-and-development-8169/language/es";}
if (std.tolower(req.url) ~ "/celade/agrupadores_xml/aes703.xml") { error 751 "http://repositorio.cepal.org/handle/11362/58/browse?order=DESC";}
if (std.tolower(req.url) ~ "/celade/agrupadores_xml/aes717.xml") { error 751 "http://repositorio.cepal.org/handle/11362/38/browse?value=NU.+CEPAL.+CELADE&type=autorinstitucional&order=desc";}
if (std.tolower(req.url) ~ "/celade/agrupadores_xml/aes743.xml") { error 751 "http://repositorio.cepal.org/handle/11362/66/browse?order=desc";}
if (std.tolower(req.url) ~ "/celade/agrupadores_xml/aes861.xml") { error 750 "/es/publications/list/field_publication_type/project-and-research-documents-8056/field_work_area_v2/population-and-development-8169";}
if (std.tolower(req.url) == "/celade/agenda/") { error 750 "/es/events/work-area/population-and-development-8169";}
if (std.tolower(req.url) == "/celade/agenda/default.asp") { error 750 "/es/events/work-area/population-and-development-8169";}
###if (std.tolower(req.url) == "/celade/agenda/default.asp?idioma=es") { error 750 "/es/events/work-area/population-and-development-8169";}
if (std.tolower(req.url) == "/prensa/") { error 750 "/es/centro-de-prensa";}
if (std.tolower(req.url) == "/prensa/default.asp") { error 750 "/es/centro-de-prensa";}
### if (std.tolower(req.url) == "/prensa/default.asp?idioma=es") { error 750 "/es/centro-de-prensa";}
if (std.tolower(req.url) == "/prensa/default.asp?idioma=in") { error 750 "/en/press";}
if (std.tolower(req.url) ~ "/prensa/agrupadores_xml/aes123.xml") { error 750 "/es/news/list/field_article_type/1/language/es";}
if (std.tolower(req.url) ~ "/prensa/agrupadores_xml/aes385.xml") { error 750 "/es/news/list/field_article_type/0/language/es";}
if (std.tolower(req.url) ~ "/prensa/agrupadores_xml/aes632.xml") { error 750 "/es/news/list/language/es/type/cepal_speech";}
if (std.tolower(req.url) ~ "/prensa/agrupadores_xml/aes729.xml") { error 750 "/es/news/list/language/es/type/cepal_speech";}
if (std.tolower(req.url) ~ "/prensa/agrupadores_xml/aes897.xml") { error 750 "/es/news/list/language/es/type/cepal_speech";}
if (std.tolower(req.url) ~ "/prensa/agrupadores_xml/ain385.xml") { error 750 "/en/news/list/field_article_type/0/language/en";}
if (std.tolower(req.url) ~ "/prensa/agrupadores_xml/ain632.xml") { error 750 "/en/news/list/language/en/type/cepal_speech";}
if (std.tolower(req.url) ~ "/prensa/agrupadores_xml/ain729.xml") { error 750 "/en/news/list/language/en/type/cepal_speech";}
if (std.tolower(req.url) == "/prensa/noticias/noticias/") { error 750 "/es/news/list/field_news_type/2/language/es";}
if (std.tolower(req.url) == "/prensa/noticias/noticias/default.asp") { error 750 "/es/news/list/field_news_type/2/language/es";}
###if (std.tolower(req.url) == "/prensa/noticias/noticias/default.asp?idioma=es") { error 750 "/es/news/list/field_news_type/2/language/es";}
if (std.tolower(req.url) == "/prensa/noticias/notas/") { error 750 "/es/notas-de-la-cepal";}
if (std.tolower(req.url) == "/prensa/noticias/notas/default.asp") { error 750 "/es/notas-de-la-cepal";}
###if (std.tolower(req.url) == "/prensa/noticias/notas/default.asp?idioma=es") { error 750 "/es/notas-de-la-cepal";}
if (std.tolower(req.url) == "/prensa/noticias/comunicados/") { error 750 "/es/news/list/language/es/type/cepal_pr";}
if (std.tolower(req.url) == "/prensa/noticias/comunicados/default.asp") { error 750 "/es/news/list/language/es/type/cepal_pr";}
###if (std.tolower(req.url) == "/prensa/noticias/comunicados/default.asp?idioma=es") { error 750 "/es/news/list/language/es/type/cepal_pr";}
if (std.tolower(req.url) == "/prensa/noticias/noticias/default.asp?idioma=in") { error 750 "/en/news/list/field_news_type/2/language/en";}
if (std.tolower(req.url) == "/prensa/noticias/comunicados/default.asp?idioma=in") { error 750 "/en/news/list/language/en/type/cepal_pr";}
if (std.tolower(req.url) == "/argentina/") { error 750 "/es/sedes-y-oficinas/cepal-buenos-aires";}
if (std.tolower(req.url) == "/argentina/default.asp") { error 750 "/es/sedes-y-oficinas/cepal-buenos-aires";}
### if (std.tolower(req.url) == "/argentina/default.asp?idioma=es") { error 750 "/es/sedes-y-oficinas/cepal-buenos-aires";}
if (std.tolower(req.url) == "/argentina/default.asp?idioma=in") { error 750 "/en/headquarters-and-offices/eclac-buenos-aires";}
if (std.tolower(req.url) == "/argentina/noticias/noticias/") { error 750 "/es/news/list/field_country%3aname/Argentina";}
if (std.tolower(req.url) == "/argentina/noticias/noticias/default.asp") { error 750 "/es/news/list/field_country%3aname/Argentina";}
###if (std.tolower(req.url) == "/argentina/noticias/noticias/default.asp?idioma=es") { error 750 "/es/news/list/field_country%3aname/Argentina";}
if (std.tolower(req.url) == "/argentina/noticias/noticias/default.asp?idioma=in") { error 750 "/en/news/list/field_country%3aname/Argentina";}
if (std.tolower(req.url) == "/brasil/") { error 750 "/pt-br/sedes-e-escritorios/cepal-brasilia";}
if (std.tolower(req.url) == "/brasil/default.asp") { error 750 "/pt-br/sedes-e-escritorios/cepal-brasilia";}
### if (std.tolower(req.url) == "/brasil/default.asp?idioma=es") { error 750 "/pt-br/sedes-e-escritorios/cepal-brasilia";}
if (std.tolower(req.url) == "/brasil/default.asp?idioma=in") { error 750 "/pt-br/sedes-e-escritorios/cepal-brasilia";}
if (std.tolower(req.url) ~ "/brasil/agrupadores_xml/aes44.xml") { error 751 "http://repositorio.cepal.org/browse?value=BRASIL&type=paises&order=desc";}
if (std.tolower(req.url) ~ "/brasil/agrupadores_xml/aes45.xml") { error 750 "/pt-br/sedes-e-escritorios/cepal-brasilia";}
if (std.tolower(req.url) ~ "/brasil/agrupadores_xml/aes70.xml") { error 751 "http://repositorio.cepal.org/browse?value=BRASIL&type=paises&order=desc";}
if (std.tolower(req.url) ~ "/brasil/agrupadores_xml/aes454.xml") { error 750 "/es/publications/list/field_publication_type/8055/field_publication_type/8096/field_publication_type/8126?search_fulltext=";}
if (std.tolower(req.url) == "/brasil/noticias/noticias/") { error 750 "/pt-br/news/list/language/pt-br";}
if (std.tolower(req.url) == "/brasil/noticias/noticias/default.asp") { error 750 "/pt-br/news/list/language/pt-br";}
###if (std.tolower(req.url) == "/brasil/noticias/noticias/default.asp?idioma=es") { error 750 "/pt-br/news/list/language/pt-br";}
if (std.tolower(req.url) == "/brasil/noticias/paginas/") { error 750 "/pt-br/news/list/language/pt-br";}
if (std.tolower(req.url) == "/brasil/noticias/paginas/default.asp") { error 750 "/pt-br/news/list/language/pt-br";}
###if (std.tolower(req.url) == "/brasil/noticias/paginas/default.asp?idioma=es") { error 750 "/pt-br/news/list/language/pt-br";}
if (std.tolower(req.url) == "/brasil/noticias/documentosdetrabajo/") { error 750 "/pt-br/news/list/language/pt-br";}
if (std.tolower(req.url) == "/brasil/noticias/documentosdetrabajo/default.asp") { error 750 "/pt-br/news/list/language/pt-br";}
###if (std.tolower(req.url) == "/brasil/noticias/documentosdetrabajo/default.asp?idioma=es") { error 750 "/pt-br/news/list/language/pt-br";}
if (std.tolower(req.url) == "/brasil/noticias/documentosdetrabajo/default.asp?idioma=in") { error 750 "/pt-br/news/list/language/pt-br";}
if (std.tolower(req.url) == "/brasil/noticias/noticias/default.asp?idioma=in") { error 750 "/pt-br/news/list/language/pt-br";}
if (std.tolower(req.url) == "/brasil/noticias/paginas/default.asp?idioma=in") { error 750 "/pt-br/news/list/language/pt-br";}
if (std.tolower(req.url) == "/transporte/") { error 750 "/es/temas/logistica-y-movilidad";}
if (std.tolower(req.url) == "/transporte/default.asp") { error 750 "/es/temas/logistica-y-movilidad";}
### if (std.tolower(req.url) == "/transporte/default.asp?idioma=es") { error 750 "/es/temas/logistica-y-movilidad";}
if (std.tolower(req.url) ~ "/transporte/agrupadores_xml/aes281.xml") { error 751 "http://repositorio.cepal.org/handle/11362/60";}
if (std.tolower(req.url) == "/transporte/noticias/noticias/") { error 750 "/es/news/list/field_work_area_v2/natural-resources-and-infrastructure-8180/language/es";}
if (std.tolower(req.url) == "/transporte/noticias/noticias/default.asp") { error 750 "/es/news/list/field_work_area_v2/natural-resources-and-infrastructure-8180/language/es";}
###if (std.tolower(req.url) == "/transporte/noticias/noticias/default.asp?idioma=es") { error 750 "/es/news/list/field_work_area_v2/natural-resources-and-infrastructure-8180/language/es";}
if (std.tolower(req.url) == "/de/") { error 750 "/es/areas-de-trabajo/desarrollo-economico";}
if (std.tolower(req.url) == "/de/default.asp") { error 750 "/es/areas-de-trabajo/desarrollo-economico";}
### if (std.tolower(req.url) == "/de/default.asp?idioma=es") { error 750 "/es/areas-de-trabajo/desarrollo-economico";}
if (std.tolower(req.url) == "/de/default.asp?idioma=in") { error 750 "/en/work-areas/economic-development";}
if (std.tolower(req.url) ~ "/de/agrupadores_xml/aes9.xml") { error 750 "/es/publications/list/field_publication_type/8055/field_publication_type/8120/field_publication_type/8159?search_fulltext=";}
if (std.tolower(req.url) ~ "/de/agrupadores_xml/aes12.xml") { error 750 "/es/publications/list/field_publication_type/8055/field_publication_type/8120";}
if (std.tolower(req.url) ~ "/de/agrupadores_xml/aes81.xml") { error 750 "/es/publications/list/field_publication_type/8055/field_publication_type/8083/field_publication_type/8096?search_fulltext=";}
if (std.tolower(req.url) ~ "/de/agrupadores_xml/aes85.xml") { error 751 "http://repositorio.cepal.org/browse?value=divisi%c3%b3n+de+desarrollo+econ%c3%b3mico&type=division&order=desc";}
if (std.tolower(req.url) ~ "/de/agrupadores_xml/aes231.xml") { error 750 "/es/events/past/work-area/economic-development-8188";}
if (std.tolower(req.url) ~ "/de/agrupadores_xml/aes251.xml") { error 750 "/es/publications/list/field_publication_type/8068/field_publication_type/8130/field_publication_type/8138?search_fulltext=";}
if (std.tolower(req.url) ~ "/de/agrupadores_xml/aes252.xml") { error 750 "/es/publications/list/field_publication_type/8068/field_publication_type/8122/field_publication_type/8130?search_fulltext=";}
if (std.tolower(req.url) ~ "/de/agrupadores_xml/aes673.xml") { error 751 "http://repositorio.cepal.org/handle/11362/93/";}
if (std.tolower(req.url) ~ "/de/agrupadores_xml/aes690.xml") { error 751 "http://repositorio.cepal.org/handle/11362/52";}
if (std.tolower(req.url) ~ "/de/agrupadores_xml/aes738.xml") { error 750 "/es/projects/list/field_work_area_v2/economic-development-8188";}
if (std.tolower(req.url) ~ "/de/agrupadores_xml/ain231.xml") { error 750 "/en/events/past/work-area/economic-development-8188";}
if (std.tolower(req.url) ~ "/de/agrupadores_xml/aes975.xml") { error 751 "http://repositorio.cepal.org/handle/11362/4/browse?order=desc";}
if (std.tolower(req.url) == "/deype/") { error 750 "/es/areas-de-trabajo/estadisticas";}
if (std.tolower(req.url) == "/deype/default.asp") { error 750 "/es/areas-de-trabajo/estadisticas";}
### if (std.tolower(req.url) == "/deype/default.asp?idioma=es") { error 750 "/es/areas-de-trabajo/estadisticas";}
if (std.tolower(req.url) ~ "/deype/agrupadores_xml/aes791.xml") { error 750 "/es/events/topic/economic-statistics-8231";}
if (std.tolower(req.url) ~ "/deype/agrupadores_xml/aes792.xml") { error 750 "/es/manuales-economicos-y-documentos-metodologicos";}
if (std.tolower(req.url) ~ "/deype/agrupadores_xml/aes794.xml") { error 750 "/es/events/topic/environmental-statistics-8230";}
if (std.tolower(req.url) ~ "/deype/agrupadores_xml/aes809.xml") { error 750 "/es/manuales-sociales-y-documentos-metodologicos";}
if (std.tolower(req.url) ~ "/deype/agrupadores_xml/aes810.xml") { error 750 "/es/manuales-ambientales-y-documentos-metodologicos";}
if (std.tolower(req.url) == "/deype/agenda/") { error 750 "/es/events/list/work-area/8184";}
if (std.tolower(req.url) == "/deype/agenda/default.asp") { error 750 "/es/events/list/work-area/8184";}
###if (std.tolower(req.url) == "/deype/agenda/default.asp?idioma=es") { error 750 "/es/events/list/work-area/8184";}
if (std.tolower(req.url) == "/ddpe/") { error 750 "/es/areas-de-trabajo/desarrollo-productivo-y-empresarial";}
if (std.tolower(req.url) == "/ddpe/default.asp") { error 750 "/es/areas-de-trabajo/desarrollo-productivo-y-empresarial";}
### if (std.tolower(req.url) == "/ddpe/default.asp?idioma=es") { error 750 "/es/areas-de-trabajo/desarrollo-productivo-y-empresarial";}
if (std.tolower(req.url) == "/ddpe/inversiones/") { error 750 "/es/areas-de-trabajo/desarrollo-productivo-y-empresarial";}
if (std.tolower(req.url) == "/ddpe/inversiones/default.asp") { error 750 "/es/areas-de-trabajo/desarrollo-productivo-y-empresarial";}
### if (std.tolower(req.url) == "/ddpe/inversiones/default.asp?idioma=es") { error 750 "/es/areas-de-trabajo/desarrollo-productivo-y-empresarial";}
if (std.tolower(req.url) == "/ddpe/desarrolloindustrial/") { error 750 "/es/areas-de-trabajo/desarrollo-productivo-y-empresarial";}
if (std.tolower(req.url) == "/ddpe/desarrolloindustrial/default.asp") { error 750 "/es/areas-de-trabajo/desarrollo-productivo-y-empresarial";}
### if (std.tolower(req.url) == "/ddpe/desarrolloindustrial/default.asp?idioma=es") { error 750 "/es/areas-de-trabajo/desarrollo-productivo-y-empresarial";}
if (std.tolower(req.url) == "/ddpe/desarrolloagricola/") { error 750 "/es/temas/agricultura-y-desarrollo-rural";}
if (std.tolower(req.url) == "/ddpe/desarrolloagricola/default.asp") { error 750 "/es/temas/agricultura-y-desarrollo-rural";}
### if (std.tolower(req.url) == "/ddpe/desarrolloagricola/default.asp?idioma=es") { error 750 "/es/temas/agricultura-y-desarrollo-rural";}
if (std.tolower(req.url) == "/ddpe/default.asp?idioma=in") { error 750 "/en/work-areas/production-productivity-and-management";}
if (std.tolower(req.url) == "/ddpe/desarrolloindustrial/default.asp?idioma=in") { error 750 "/en/work-areas/production-productivity-and-management";}
if (std.tolower(req.url) ~ "/ddpe/agrupadores_xml/aes74.xml") { error 750 "/es/publications/list/field_publication_type/books-and-monographs-8059/field_work_area_v2/desarrollo-productivo-y-empresarial-8183";}
if (std.tolower(req.url) == "/drni/") { error 750 "/es/areas-de-trabajo/recursos-naturales-e-infraestructura";}
if (std.tolower(req.url) == "/drni/default.asp") { error 750 "/es/areas-de-trabajo/recursos-naturales-e-infraestructura";}
### if (std.tolower(req.url) == "/drni/default.asp?idioma=es") { error 750 "/es/areas-de-trabajo/recursos-naturales-e-infraestructura";}
if (std.tolower(req.url) == "/drni/urne/") { error 750 "/es/temas/recursos-mineros";}
if (std.tolower(req.url) == "/drni/urne/default.asp") { error 750 "/es/temas/recursos-mineros";}
### if (std.tolower(req.url) == "/drni/urne/default.asp?idioma=es") { error 750 "/es/temas/recursos-mineros";}
if (std.tolower(req.url) ~ "/drni/agrupadores_xml/aes38.xml") { error 750 "/es/temas/recursos-hidricos";}
if (std.tolower(req.url) ~ "/drni/agrupadores_xml/aes82.xml") { error 750 "/es/temas/energia";}
if (std.tolower(req.url) ~ "/drni/agrupadores_xml/aes84.xml") { error 750 "/es/temas/recursos-mineros";}
if (std.tolower(req.url) ~ "/drni/agrupadores_xml/aes124.xml") { error 751 "http://repositorio.cepal.org/handle/11362/35862/browse?order=desc";}
if (std.tolower(req.url) ~ "/drni/agrupadores_xml/aes626.xml") { error 751 "http://repositorio.cepal.org/handle/11362/22/browse?value=Divisi%C3%B3n+de+Recursos+Naturales+e+Infraestructura&type=division&order=desc";}
if (std.tolower(req.url) == "/drni/noticias/noticias/") { error 750 "/es/news/list/field_work_area_v2/8180";}
if (std.tolower(req.url) == "/drni/noticias/noticias/default.asp") { error 750 "/es/news/list/field_work_area_v2/8180";}
###if (std.tolower(req.url) == "/drni/noticias/noticias/default.asp?idioma=es") { error 750 "/es/news/list/field_work_area_v2/8180";}
if (std.tolower(req.url) == "/ilpes/") { error 750 "/es/areas-de-trabajo/planificacion-para-el-desarrollo";}
if (std.tolower(req.url) == "/ilpes/default.asp") { error 750 "/es/areas-de-trabajo/planificacion-para-el-desarrollo";}
### if (std.tolower(req.url) == "/ilpes/default.asp?idioma=es") { error 750 "/es/areas-de-trabajo/planificacion-para-el-desarrollo";}
if (std.tolower(req.url) ~ "/ilpes/agrupadores_xml/aes11.xml") { error 751 "http://repositorio.cepal.org/handle/11362/47/browse?order=desc";}
if (std.tolower(req.url) ~ "/ilpes/agrupadores_xml/aes111.xml") { error 751 "http://repositorio.cepal.org/handle/11362/15/browse?value=ILPES+-+Instituto+Latinoamericano+y+del+Caribe+de+Planificaci%C3%B3n+Econ%C3%B3mica+y+Social&type=division&order=desc";}
if (std.tolower(req.url) ~ "/ilpes/agrupadores_xml/aes114.xml") { error 751 "http://repositorio.cepal.org/handle/11362/38/browse?order=desc";}
if (std.tolower(req.url) ~ "/ilpes/agrupadores_xml/aes116.xml") { error 751 "http://repositorio.cepal.org/handle/11362/56/browse?order=desc";}
if (std.tolower(req.url) ~ "/ilpes/agrupadores_xml/aes155.xml") { error 751 "http://repositorio.cepal.org/handle/11362/43/browse?order=desc";}
if (std.tolower(req.url) ~ "/ilpes/agrupadores_xml/aes611.xml") { error 751 "http://repositorio.cepal.org/handle/11362/46/browse?order=desc";}
if (std.tolower(req.url) ~ "/ilpes/agrupadores_xml/aes826.xml") { error 751 "http://repositorio.cepal.org/handle/11362/22/browse?value=ILPES+-+Instituto+Latinoamericano+y+del+Caribe+de+Planificaci%C3%B3n+Econ%C3%B3mica+y+Social&type=division&order=desc";}
if (std.tolower(req.url) == "/mujer/") { error 750 "/es/areas-de-trabajo/asuntos-de-genero";}
if (std.tolower(req.url) == "/mujer/default.asp") { error 750 "/es/areas-de-trabajo/asuntos-de-genero";}
### if (std.tolower(req.url) == "/mujer/default.asp?idioma=es") { error 750 "/es/areas-de-trabajo/asuntos-de-genero";}
if (std.tolower(req.url) == "/mujer/default.asp?idioma=in") { error 750 "/es/areas-de-trabajo/asuntos-de-genero";}
if (std.tolower(req.url) == "/dds/") { error 750 "/es/areas-de-trabajo/desarrollo-social";}
if (std.tolower(req.url) == "/dds/default.asp") { error 750 "/es/areas-de-trabajo/desarrollo-social";}
### if (std.tolower(req.url) == "/dds/default.asp?idioma=es") { error 750 "/es/areas-de-trabajo/desarrollo-social";}
if (std.tolower(req.url) == "/dds/publicaciones/") { error 750 "/es/publications/list/field_work_area_v2/8195";}
if (std.tolower(req.url) == "/dds/publicaciones/default.asp") { error 750 "/es/publications/list/field_work_area_v2/8195";}
### if (std.tolower(req.url) == "/dds/publicaciones/default.asp?idioma=es") { error 750 "/es/publications/list/field_work_area_v2/8195";}
if (std.tolower(req.url) ~ "/dds/agrupadores_xml/aes68.xml") { error 750 "/es/publications/list/field_work_area_v2/8195";}
if (std.tolower(req.url) ~ "/dds/agrupadores_xml/aes151.xml") { error 750 "/es/publications/list/field_publication_type/books-and-monographs-8059/field_publication_type/books-and-monographs-8069/field_publication_type/libros-de-la-cepal-8156/field_work_area_v2/social-development-8195";}
if (std.tolower(req.url) ~ "/dds/agrupadores_xml/aes178.xml") { error 750 "/es/areas-de-trabajo/desarrollo-social";}
if (std.tolower(req.url) ~ "/dds/agrupadores_xml/aes179.xml") { error 750 "/es/temas/politicas-y-programas-sociales";}
if (std.tolower(req.url) ~ "/dds/agrupadores_xml/aes180.xml") { error 750 "/es/temas/estratificacion-y-movilidad-social";}
if (std.tolower(req.url) ~ "/dds/agrupadores_xml/aes183.xml") { error 750 "/es/publications/list/field_publication_type/coeditions-8053/field_publication_type/books-and-monographs-8059/field_publication_type/books-and-monographs-8069/field_work_area_v2/social-development-8195";}
if (std.tolower(req.url) ~ "/dds/agrupadores_xml/aes287.xml") { error 750 "/es/temas/capital-social";}
if (std.tolower(req.url) ~ "/dds/agrupadores_xml/aes288.xml") { error 750 "/es/temas/familias";}
if (std.tolower(req.url) ~ "/dds/agrupadores_xml/aes289.xml") { error 750 "/es/areas-de-trabajo/asuntos-de-genero";}
if (std.tolower(req.url) ~ "/dds/agrupadores_xml/aes290.xml") { error 750 "/es/areas-de-trabajo/desarrollo-social";}
if (std.tolower(req.url) ~ "/dds/agrupadores_xml/aes348.xml") { error 750 "/es/projects/list/field_work_area_v2/8195";}
if (std.tolower(req.url) ~ "/dds/agrupadores_xml/aes741.xml") { error 750 "/es/temas/tecnologias-de-la-informacion-y-las-comunicaciones-tic";}
if (std.tolower(req.url) ~ "/dds/agrupadores_xml/aes816.xml") { error 750 "/es/publications/list/field_publication_type/project-and-research-documents-8056/field_publication_type/project-and-research-documents-8063/field_work_area_v2/social-development-8195";}
if (std.tolower(req.url) == "/dds/agenda/") { error 750 "/es/events/list/work-area/8195";}
if (std.tolower(req.url) == "/dds/agenda/default.asp") { error 750 "/es/events/list/work-area/8195";}
###if (std.tolower(req.url) == "/dds/agenda/default.asp?idioma=es") { error 750 "/es/events/list/work-area/8195";}
if (std.tolower(req.url) == "/dmaah/") { error 750 "/es/areas-de-trabajo/desarrollo-sostenible-y-asentamientos-humanos";}
if (std.tolower(req.url) == "/dmaah/default.asp") { error 750 "/es/areas-de-trabajo/desarrollo-sostenible-y-asentamientos-humanos";}
### if (std.tolower(req.url) == "/dmaah/default.asp?idioma=es") { error 750 "/es/areas-de-trabajo/desarrollo-sostenible-y-asentamientos-humanos";}
if (std.tolower(req.url) == "/dmaah/default.asp?idioma=in") { error 750 "/en/work-areas/sustainable-development-and-human-settlements";}
if (std.tolower(req.url) == "/dmaah/capacitacion/") { error 750 "/es/courses/past/work-area/8179";}
if (std.tolower(req.url) == "/dmaah/capacitacion/default.asp") { error 750 "/es/courses/past/work-area/8179";}
###if (std.tolower(req.url) == "/dmaah/capacitacion/default.asp?idioma=es") { error 750 "/es/courses/past/work-area/8179";}
if (std.tolower(req.url) == "/dmaah/capacitacion/default.asp?idioma=in") { error 750 "/en/courses/past/work-area/8179";}
if (std.tolower(req.url) == "/comercio/") { error 750 "/es/areas-de-trabajo/comercio-internacional";}
if (std.tolower(req.url) == "/comercio/default.asp") { error 750 "/es/areas-de-trabajo/comercio-internacional";}
### if (std.tolower(req.url) == "/comercio/default.asp?idioma=es") { error 750 "/es/areas-de-trabajo/comercio-internacional";}
if (std.tolower(req.url) == "/comercio/notas_comercio/") { error 751 "http://repositorio.cepal.org/handle/11362/59/browse?order=desc&rpp=0&sort_by=0&etal=-0&offset=0&type=title";}
if (std.tolower(req.url) == "/comercio/notas_comercio/default.asp") { error 751 "http://repositorio.cepal.org/handle/11362/59/browse?order=desc&rpp=0&sort_by=0&etal=-0&offset=0&type=title";}
### if (std.tolower(req.url) == "/comercio/notas_comercio/default.asp?idioma=es") { error 751 "http://repositorio.cepal.org/handle/11362/59/browse?order=desc&rpp=0&sort_by=0&etal=-0&offset=0&type=title";}
if (std.tolower(req.url) == "/comercio/equipo_trabajo_dcii/") { error 750 "/es/equipo-de-trabajo-comercio-internacional-e-integracion";}
if (std.tolower(req.url) == "/comercio/equipo_trabajo_dcii/default.asp") { error 750 "/es/equipo-de-trabajo-comercio-internacional-e-integracion";}
### if (std.tolower(req.url) == "/comercio/equipo_trabajo_dcii/default.asp?idioma=es") { error 750 "/es/equipo-de-trabajo-comercio-internacional-e-integracion";}
if (std.tolower(req.url) == "/comercio/doc_serie_2012_2014/") { error 751 "http://repositorio.cepal.org/handle/11362/25/browse?order=desc&rpp=20&sort_by=1&etal=-1&offset=0&type=title";}
if (std.tolower(req.url) == "/comercio/doc_serie_2012_2014/default.asp") { error 751 "http://repositorio.cepal.org/handle/11362/25/browse?order=desc&rpp=20&sort_by=1&etal=-1&offset=0&type=title";}
### if (std.tolower(req.url) == "/comercio/doc_serie_2012_2014/default.asp?idioma=es") { error 751 "http://repositorio.cepal.org/handle/11362/25/browse?order=desc&rpp=20&sort_by=1&etal=-1&offset=0&type=title";}
if (std.tolower(req.url) == "/comercio/default.asp?idioma=in") { error 750 "/en/work-areas/international-trade-and-integration";}
if (std.tolower(req.url) == "/comercio/equipo_trabajo_dcii/default.asp?idioma=in") { error 750 "/en/staff-international-trade-and-integration-division";}
if (std.tolower(req.url) == "/comercio/doc_serie_2012_2014/default.asp?idioma=in") { error 750 "/en/publications/list/field_publication_type/series-8055/field_work_area_v2/international-trade-and-integration-8192/language/en";}
if (std.tolower(req.url) == "/redatam/") { error 750 "/es/temas/redatam";}
if (std.tolower(req.url) == "/redatam/default.asp") { error 750 "/es/temas/redatam";}
### if (std.tolower(req.url) == "/redatam/default.asp?idioma=es") { error 750 "/es/temas/redatam";}
if (std.tolower(req.url) == "/redatam/default.asp?idioma=in") { error 750 "/en/topics/redatam";}
if (std.tolower(req.url) == "/mexico/") { error 750 "/es/sedes-y-oficinas/cepal-mexico";}
if (std.tolower(req.url) == "/mexico/default.asp") { error 750 "/es/sedes-y-oficinas/cepal-mexico";}
### if (std.tolower(req.url) == "/mexico/default.asp?idioma=es") { error 750 "/es/sedes-y-oficinas/cepal-mexico";}
if (std.tolower(req.url) == "/mexico/dagricolayrural/") { error 750 "/es/topics/19/offices/8211";}
if (std.tolower(req.url) == "/mexico/dagricolayrural/default.asp") { error 750 "/es/topics/19/offices/8211";}
### if (std.tolower(req.url) == "/mexico/dagricolayrural/default.asp?idioma=es") { error 750 "/es/topics/19/offices/8211";}
if (std.tolower(req.url) == "/mexico/comercioeindustria/") { error 750 "/es/topics/8192/offices/8211";}
if (std.tolower(req.url) == "/mexico/comercioeindustria/default.asp") { error 750 "/es/topics/8192/offices/8211";}
### if (std.tolower(req.url) == "/mexico/comercioeindustria/default.asp?idioma=es") { error 750 "/es/topics/8192/offices/8211";}
if (std.tolower(req.url) == "/mexico/dsocial/") { error 750 "/es/topics/8195/offices/8211";}
if (std.tolower(req.url) == "/mexico/dsocial/default.asp") { error 750 "/es/topics/8195/offices/8211";}
### if (std.tolower(req.url) == "/mexico/dsocial/default.asp?idioma=es") { error 750 "/es/topics/8195/offices/8211";}
if (std.tolower(req.url) == "/mexico/energia/") { error 750 "/es/topics/33/offices/8211";}
if (std.tolower(req.url) == "/mexico/energia/default.asp") { error 750 "/es/topics/33/offices/8211";}
### if (std.tolower(req.url) == "/mexico/energia/default.asp?idioma=es") { error 750 "/es/topics/33/offices/8211";}
if (std.tolower(req.url) == "/mexico/deconomico/") { error 750 "/es/topics/8188/offices/8211";}
if (std.tolower(req.url) == "/mexico/deconomico/default.asp") { error 750 "/es/topics/8188/offices/8211";}
### if (std.tolower(req.url) == "/mexico/deconomico/default.asp?idioma=es") { error 750 "/es/topics/8188/offices/8211";}
if (std.tolower(req.url) ~ "/mexico/agrupadores_xml/aes188.xml") { error 750 "/es/publications/list/field_regional_office/eclac-mexico-8211/field_work_area_v2/social-development-8195/office/eclac-mexico-8211/work-area/social-development-8195";}
if (std.tolower(req.url) ~ "/mexico/agrupadores_xml/aes189.xml") { error 750 "/es/publications/list/field_regional_office/eclac-mexico-8211/field_work_area_v2/international-trade-and-integration-8192/office/eclac-mexico-8211/topic/international-trade-116";}
if (std.tolower(req.url) ~ "/mexico/agrupadores_xml/aes190.xml") { error 750 "/es/publications/list/field_regional_office/eclac-mexico-8211/field_topic/energy-33/office/eclac-mexico-8211/topic/energy-33";}
if (std.tolower(req.url) ~ "/mexico/agrupadores_xml/aes192.xml") { error 750 "/es/publications/list/field_regional_office/eclac-mexico-8211/field_topic/agriculture-and-rural-development-19/field_work_area_v2/production-productivity-and-management-8183/office/eclac-mexico-8211/topic/agriculture-and-rural-development-19";}
if (std.tolower(req.url) ~ "/mexico/agrupadores_xml/aes193.xml") { error 750 "/es/publications/list/field_regional_office/eclac-mexico-8211/field_topic/energy-33/office/eclac-mexico-8211/topic/natural-disasters-26";}
if (std.tolower(req.url) ~ "/mexico/agrupadores_xml/aes238.xml") { error 750 "/es/publicaciones/tipo/estudios-perspectivas-sede-subregional-cepal-mexico";}
if (std.tolower(req.url) == "/mexico/noticias/noticias/") { error 750 "/es/notes/list/field_regional_office/8211/office/eclac-mexico-8211";}
if (std.tolower(req.url) == "/mexico/noticias/noticias/default.asp") { error 750 "/es/notes/list/field_regional_office/8211/office/eclac-mexico-8211";}
###if (std.tolower(req.url) == "/mexico/noticias/noticias/default.asp?idioma=es") { error 750 "/es/notes/list/field_regional_office/8211/office/eclac-mexico-8211";}
if (std.tolower(req.url) == "/washington/") { error 750 "/en/headquarters-and-offices/eclac-washington-dc";}
if (std.tolower(req.url) == "/washington/default.asp") { error 750 "/en/headquarters-and-offices/eclac-washington-dc";}
### if (std.tolower(req.url) == "/washington/default.asp?idioma=es") { error 750 "/en/headquarters-and-offices/eclac-washington-dc";}
if (std.tolower(req.url) == "/washington/default.asp?idioma=in") { error 750 "/en/headquarters-and-offices/eclac-washington-dc";}
if (std.tolower(req.url) ~ "/washington/agrupadores_xml/aes215.xml") { error 751 "http://repositorio.cepal.org/browse?value=ESTADOS+UNIDOS&type=paises";}
if (std.tolower(req.url) ~ "/washington/agrupadores_xml/aes216.xml") { error 751 "http://repositorio.cepal.org/browse?value=ESTADOS+UNIDOS&type=paises";}
if (std.tolower(req.url) ~ "/washington/agrupadores_xml/aes217.xml") { error 751 "http://repositorio.cepal.org/browse?value=ESTADOS+UNIDOS&type=paises";}
if (std.tolower(req.url) ~ "/washington/agrupadores_xml/ain215.xml") { error 751 "http://repositorio.cepal.org/browse?value=ESTADOS+UNIDOS&type=paises";}
if (std.tolower(req.url) ~ "/washington/agrupadores_xml/ain613.xml") { error 750 "/en/publications/list/field_publication_type/8055/field_publication_type/8096/field_publication_type/8123";}
if (std.tolower(req.url) ~ "/washington/agrupadores_xml/ain216.xml") { error 751 "http://repositorio.cepal.org/browse?value=ESTADOS+UNIDOS&type=paises";}
if (std.tolower(req.url) ~ "/washington/agrupadores_xml/ain217.xml") { error 751 "http://repositorio.cepal.org/browse?value=ESTADOS+UNIDOS&type=paises";}
if (std.tolower(req.url) == "/revista/") { error 750 "/es/publicaciones/tipo/revista-cepal";}
if (std.tolower(req.url) == "/revista/default.asp") { error 750 "/es/publicaciones/tipo/revista-cepal";}
### if (std.tolower(req.url) == "/revista/default.asp?idioma=es") { error 750 "/es/publicaciones/tipo/revista-cepal";}
if (std.tolower(req.url) == "/revista/default.asp?idioma=in") { error 750 "/en/publications/type/cepal-review";}
if (std.tolower(req.url) ~ "/revista/agrupadores_xml/aes980.xml") { error 751 "http://repositorio.cepal.org/handle/11362/70/discover?order=desc&rpp=10&sort_by=dc.date.issued_dt&page=1&group_by=none&etal=0";}
if (std.tolower(req.url) == "/revista/noticias/articulocepal/") { error 751 "http://repositorio.cepal.org/handle/11362/70";}
if (std.tolower(req.url) == "/revista/noticias/articulocepal/default.asp") { error 751 "http://repositorio.cepal.org/handle/11362/70";}
###if (std.tolower(req.url) == "/revista/noticias/articulocepal/default.asp?idioma=es") { error 751 "http://repositorio.cepal.org/handle/11362/70";}
if (std.tolower(req.url) == "/revista/noticias/autores/") { error 751 "http://repositorio.cepal.org/handle/11362/70/browse?type=author";}
if (std.tolower(req.url) == "/revista/noticias/autores/default.asp") { error 751 "http://repositorio.cepal.org/handle/11362/70/browse?type=author";}
###if (std.tolower(req.url) == "/revista/noticias/autores/default.asp?idioma=es") { error 751 "http://repositorio.cepal.org/handle/11362/70/browse?type=author";}
if (std.tolower(req.url) == "/revista/noticias/autores/default.asp?idioma=in") { error 751 "http://repositorio.cepal.org/handle/11362/70/browse?type=author";}
if (std.tolower(req.url) == "/uruguay/") { error 750 "/es/sedes-y-oficinas/cepal-montevideo";}
if (std.tolower(req.url) == "/uruguay/default.asp") { error 750 "/es/sedes-y-oficinas/cepal-montevideo";}
### if (std.tolower(req.url) == "/uruguay/default.asp?idioma=es") { error 750 "/es/sedes-y-oficinas/cepal-montevideo";}
if (std.tolower(req.url) == "/dmaah/proyectos/esalc/noticias/noticias/") { error 750 "/es/areas-de-trabajo/desarrollo-sostenible-y-asentamientos-humanos";}
if (std.tolower(req.url) == "/dmaah/proyectos/esalc/noticias/noticias/default.asp") { error 750 "/es/areas-de-trabajo/desarrollo-sostenible-y-asentamientos-humanos";}
###if (std.tolower(req.url) == "/dmaah/proyectos/esalc/noticias/noticias/default.asp?idioma=es") { error 750 "/es/areas-de-trabajo/desarrollo-sostenible-y-asentamientos-humanos";}
if (std.tolower(req.url) == "/dmaah/proyectos/esalc/noticias/paginas/") { error 750 "/es/areas-de-trabajo/desarrollo-sostenible-y-asentamientos-humanos";}
if (std.tolower(req.url) == "/dmaah/proyectos/esalc/noticias/paginas/default.asp") { error 750 "/es/areas-de-trabajo/desarrollo-sostenible-y-asentamientos-humanos";}
###if (std.tolower(req.url) == "/dmaah/proyectos/esalc/noticias/paginas/default.asp?idioma=es") { error 750 "/es/areas-de-trabajo/desarrollo-sostenible-y-asentamientos-humanos";}
if (std.tolower(req.url) == "/colombia/") { error 750 "/es/sedes-y-oficinas/cepal-bogota";}
if (std.tolower(req.url) == "/colombia/default.asp") { error 750 "/es/sedes-y-oficinas/cepal-bogota";}
### if (std.tolower(req.url) == "/colombia/default.asp?idioma=es") { error 750 "/es/sedes-y-oficinas/cepal-bogota";}
if (std.tolower(req.url) ~ "/colombia/agrupadores_xml/aes319.xml") { error 751 "http://repositorio.cepal.org/handle/11362/41";}
if (std.tolower(req.url) ~ "/colombia/agrupadores_xml/aes320.xml") { error 751 "http://repositorio.cepal.org/handle/11362/39";}
if (std.tolower(req.url) ~ "/colombia/agrupadores_xml/aes321.xml") { error 751 "http://repositorio.cepal.org/";}
if (std.tolower(req.url) ~ "/colombia/agrupadores_xml/aes323.xml") { error 751 "http://repositorio.cepal.org/handle/11362/37";}
if (std.tolower(req.url) ~ "/colombia/agrupadores_xml/aes324.xml") { error 751 "http://repositorio.cepal.org/handle/11362/42";}
if (std.tolower(req.url) ~ "/colombia/agrupadores_xml/aes325.xml") { error 751 "http://repositorio.cepal.org/handle/11362/26";}
if (std.tolower(req.url) ~ "/colombia/agrupadores_xml/aes326.xml") { error 751 "http://repositorio.cepal.org/handle/11362/47";}
if (std.tolower(req.url) ~ "/colombia/agrupadores_xml/aes327.xml") { error 751 "http://repositorio.cepal.org/handle/11362/27";}
if (std.tolower(req.url) ~ "/colombia/agrupadores_xml/aes328.xml") { error 751 "http://repositorio.cepal.org/handle/11362/35";}
if (std.tolower(req.url) ~ "/colombia/agrupadores_xml/aes341.xml") { error 750 "/es/temas/objetivos-de-desarrollo-del-milenio-odm";}
if (std.tolower(req.url) ~ "/colombia/agrupadores_xml/aes364.xml") { error 751 "http://repositorio.cepal.org/browse?value=COLOMBIA&type=paises";}
if (std.tolower(req.url) ~ "/colombia/agrupadores_xml/aes366.xml") { error 750 "/es/publicaciones/tipo/revista-cepal";}
if (std.tolower(req.url) ~ "/colombia/agrupadores_xml/aes373.xml") { error 750 "/es/temas/innovacion-social";}
if (std.tolower(req.url) ~ "/colombia/agrupadores_xml/aes970.xml") { error 751 "http://repositorio.cepal.org/handle/11362/25";}
if (std.tolower(req.url) == "/desastres/") { error 750 "/es/temas/desastres";}
if (std.tolower(req.url) == "/desastres/default.asp") { error 750 "/es/temas/desastres";}
### if (std.tolower(req.url) == "/desastres/default.asp?idioma=es") { error 750 "/es/temas/desastres";}
if (std.tolower(req.url) == "/desastres/default.asp?idioma=in") { error 750 "/en/topics/disasters";}
if (std.tolower(req.url) == "/perfil/") { error 751 "http://perfil.cepal.org/l/es/start.html";}
if (std.tolower(req.url) == "/perfil/default.asp") { error 751 "http://perfil.cepal.org/l/es/start.html";}
### if (std.tolower(req.url) == "/perfil/default.asp?idioma=es") { error 751 "http://perfil.cepal.org/l/es/start.html";}
if (std.tolower(req.url) == "/perfil/default.asp?idioma=in") { error 751 "http://perfil.cepal.org/l/en/start.html";}
if (std.tolower(req.url) == "/perfil/agenda/") { error 751 "http://perfil.cepal.org/l/es/start.html";}
if (std.tolower(req.url) == "/perfil/agenda/default.asp") { error 751 "http://perfil.cepal.org/l/es/start.html";}
###if (std.tolower(req.url) == "/perfil/agenda/default.asp?idioma=es") { error 751 "http://perfil.cepal.org/l/es/start.html";}
if (std.tolower(req.url) == "/perfil/agenda/default.asp?idioma=in") { error 751 "http://perfil.cepal.org/l/en/start.html";}
if (std.tolower(req.url) == "/dppo/") { error 750 "/es/cooperacion";}
if (std.tolower(req.url) == "/dppo/default.asp") { error 750 "/es/cooperacion";}
### if (std.tolower(req.url) == "/dppo/default.asp?idioma=es") { error 750 "/es/cooperacion";}
if (std.tolower(req.url) == "/oig/afisica/") { error 751 "http://oig.cepal.org/es/autonomias/autonomia-fisica";}
if (std.tolower(req.url) == "/oig/afisica/default.asp") { error 751 "http://oig.cepal.org/es/autonomias/autonomia-fisica";}
### if (std.tolower(req.url) == "/oig/afisica/default.asp?idioma=es") { error 751 "http://oig.cepal.org/es/autonomias/autonomia-fisica";}
if (std.tolower(req.url) == "/oig/aeconomica/") { error 751 "http://oig.cepal.org/es/autonomias/autonomia-economica";}
if (std.tolower(req.url) == "/oig/aeconomica/default.asp") { error 751 "http://oig.cepal.org/es/autonomias/autonomia-economica";}
### if (std.tolower(req.url) == "/oig/aeconomica/default.asp?idioma=es") { error 751 "http://oig.cepal.org/es/autonomias/autonomia-economica";}
if (std.tolower(req.url) == "/oig/") { error 751 "http://oig.cepal.org/es";}
if (std.tolower(req.url) == "/oig/default.asp") { error 751 "http://oig.cepal.org/es";}
### if (std.tolower(req.url) == "/oig/default.asp?idioma=es") { error 751 "http://oig.cepal.org/es";}
if (std.tolower(req.url) == "/oig/adecisiones/") { error 751 "http://oig.cepal.org/es/autonomias/autonomia-la-toma-decisiones";}
if (std.tolower(req.url) == "/oig/adecisiones/default.asp") { error 751 "http://oig.cepal.org/es/autonomias/autonomia-la-toma-decisiones";}
### if (std.tolower(req.url) == "/oig/adecisiones/default.asp?idioma=es") { error 751 "http://oig.cepal.org/es/autonomias/autonomia-la-toma-decisiones";}
if (std.tolower(req.url) == "/oig/afisica/default.asp?idioma=in") { error 751 "http://oig.cepal.org/en/autonomies/physical-autonomy";}
if (std.tolower(req.url) == "/oig/aeconomica/default.asp?idioma=in") { error 751 "http://oig.cepal.org/en/autonomies/economic-autonomy";}
if (std.tolower(req.url) == "/oig/default.asp?idioma=in") { error 751 "http://oig.cepal.org/en";}
if (std.tolower(req.url) == "/oig/adecisiones/default.asp?idioma=in") { error 751 "http://oig.cepal.org/en/autonomies/autonomy-decision-making";}
if (std.tolower(req.url) ~ "/oig/agrupadores_xml/aes779.xml") { error 751 "http://oig.cepal.org/es/documentos";}
if (std.tolower(req.url) ~ "/oig/agrupadores_xml/aes854.xml") { error 751 "http://oig.cepal.org/es/politicas-justas";}
if (std.tolower(req.url) ~ "/oig/agrupadores_xml/ain854.xml") { error 751 "http://oig.cepal.org/en/fair-policies";}
if (std.tolower(req.url) ~ "/oig/agrupadores_xml/ain779.xml") { error 751 "http://oig.cepal.org/en/documents";}
if (std.tolower(req.url) == "/aecid/") { error 751 "http://www.cepal.org/es/proyectos/programa-cooperacion-tecnica-cepal-aecid";}
if (std.tolower(req.url) == "/aecid/default.asp") { error 751 "http://www.cepal.org/es/proyectos/programa-cooperacion-tecnica-cepal-aecid";}
### if (std.tolower(req.url) == "/aecid/default.asp?idioma=es") { error 751 "http://www.cepal.org/es/proyectos/programa-cooperacion-tecnica-cepal-aecid";}
if (std.tolower(req.url) == "/aecid/libsypubs/") { error 751 "http://www.cepal.org/es/proyectos/programa-cooperacion-tecnica-cepal-aecid";}
if (std.tolower(req.url) == "/aecid/libsypubs/default.asp") { error 751 "http://www.cepal.org/es/proyectos/programa-cooperacion-tecnica-cepal-aecid";}
### if (std.tolower(req.url) == "/aecid/libsypubs/default.asp?idioma=es") { error 751 "http://www.cepal.org/es/proyectos/programa-cooperacion-tecnica-cepal-aecid";}
if (std.tolower(req.url) == "/aecid/eventos/") { error 751 "http://www.cepal.org/es/proyectos/programa-cooperacion-tecnica-cepal-aecid";}
if (std.tolower(req.url) == "/aecid/eventos/default.asp") { error 751 "http://www.cepal.org/es/proyectos/programa-cooperacion-tecnica-cepal-aecid";}
### if (std.tolower(req.url) == "/aecid/eventos/default.asp?idioma=es") { error 751 "http://www.cepal.org/es/proyectos/programa-cooperacion-tecnica-cepal-aecid";}
if (std.tolower(req.url) == "/aecid/programa/") { error 751 "http://www.cepal.org/es/antecedentes-cepal-aecid";}
if (std.tolower(req.url) == "/aecid/programa/default.asp") { error 751 "http://www.cepal.org/es/antecedentes-cepal-aecid";}
### if (std.tolower(req.url) == "/aecid/programa/default.asp?idioma=es") { error 751 "http://www.cepal.org/es/antecedentes-cepal-aecid";}
if (std.tolower(req.url) == "/aecid/default.asp?idioma=in") { error 751 "http://www.cepal.org/es/proyectos/programa-cooperacion-tecnica-cepal-aecid";}
if (std.tolower(req.url) == "/aecid/libsypubs/default.asp?idioma=in") { error 751 "http://www.cepal.org/es/proyectos/programa-cooperacion-tecnica-cepal-aecid";}
if (std.tolower(req.url) == "/aecid/eventos/default.asp?idioma=in") { error 751 "http://www.cepal.org/es/proyectos/programa-cooperacion-tecnica-cepal-aecid";}
if (std.tolower(req.url) == "/aecid/programa/default.asp?idioma=in") { error 751 "http://www.cepal.org/es/proyectos/programa-cooperacion-tecnica-cepal-aecid";}
if (std.tolower(req.url) == "/rio20/principio10/") { error 751 "http://www.cepal.org/es/temas/principio-10";}
if (std.tolower(req.url) == "/rio20/principio10/default.asp") { error 751 "http://www.cepal.org/es/temas/principio-10";}
### if (std.tolower(req.url) == "/rio20/principio10/default.asp?idioma=es") { error 751 "http://www.cepal.org/es/temas/principio-10";}
if (std.tolower(req.url) == "/rio20/principio10/default.asp?idioma=in") { error 751 "http://www.cepal.org/en/topics/principle-10";}
} 


sub redireccionaProductosManual{
if (std.tolower(req.url) ~ "/faq/5/1295/p1295.xml") { error 750 "/es/about";}
if (std.tolower(req.url) ~ "/deype/noticias/paginas/2/5502/p5502.xml") { error 750 "/es/node/41749";}
if (std.tolower(req.url) ~ "/brasil/noticias/paginas/1/5571/p5571.xml") { error 751 "http://repositorio.cepal.org/handle/11362/127";}
if (std.tolower(req.url) ~ "/brasil/noticias/paginas/0/5560/p5560.xml") { error 750 "/pt-br/node/41244";}
if (std.tolower(req.url) ~ "/brasil/noticias/paginas/4/5594/p5594.xml") { error 750 "/pt-br/sedes-e-escritorios/cepal-brasilia";}
if (std.tolower(req.url) ~ "/de/noticias/paginas/7/5697/p5697.xml") { error 750 "/es/node/41136";}
if (std.tolower(req.url) ~ "/celade/noticias/paginas/8/7088/p7088.xml") { error 750 "/es/node/41174";}
if (std.tolower(req.url) ~ "/brasil/noticias/paginas/5/7555/p7555.xml") { error 751 "http://repositorio.cepal.org/handle/11362/20";}
if (std.tolower(req.url) ~ "/celade/noticias/paginas/5/7765/p7765.xml") { error 750 "/es/areas-de-trabajo/poblacion-y-desarrollo";}
if (std.tolower(req.url) ~ "/celade/noticias/paginas/6/7766/p7766.xml") { error 750 "/es/areas-de-trabajo/poblacion-y-desarrollo";}
if (std.tolower(req.url) ~ "/celade/noticias/paginas/7/7767/p7767.xml") { error 750 "/es/courses/work-area/population-and-development-8169";}
if (std.tolower(req.url) ~ "/de/noticias/paginas/5/5735/p5735.xml") { error 750 "/es/projects/list/field_work_area_v2/economic-development-8188";}
if (std.tolower(req.url) ~ "/drni/noticias/paginas/3/5713/p5713.xml") { error 750 "es/node/41200";}
if (std.tolower(req.url) ~ "/mujer/noticias/fichas/4/6404/p6404.xml") { error 750 "/es/node/41151";}
if (std.tolower(req.url) ~ "/de/noticias/paginas/5/9225/p9225.xml") { error 750 "/en/projects/list/field_work_area_v2/economic-development-8188";}
if (std.tolower(req.url) ~ "/celade/noticias/paginas/5/9345/p9345.xml") { error 750 "es/node/41175";}
if (std.tolower(req.url) ~ "/celade/noticias/paginas/3/9353/p9353.xml") { error 750 "/es/node/41177";}
if (std.tolower(req.url) ~ "/washington/noticias/paginas/4/9124/p9124.xml") { error 750 "/es/node/41750";}
if (std.tolower(req.url) ~ "/celade/noticias/paginas/9/7769/p7769.xml") { error 750 "/es/acerca-de-poblacion-y-desarrollo";}
if (std.tolower(req.url) ~ "/celade/noticias/paginas/0/7770/p7770.xml") { error 750 "/es/acerca-de-poblacion-y-desarrollo";}
if (std.tolower(req.url) ~ "/celade/noticias/paginas/3/7773/p7773.xml") { error 750 "/es/node/41171";}
if (std.tolower(req.url) ~ "/mexico/noticias/paginas/8/7868/p7868.xml") { error 750 "/es/node/41229";}
if (std.tolower(req.url) ~ "/mexico/noticias/paginas/2/8382/p8382.xml") { error 750 "/es/projects/list/office/eclac-mexico-8211";}
if (std.tolower(req.url) ~ "/mexico/noticias/paginas/8/8388/p8388.xml") { error 750 "/es/publications/list/field_regional_office/8211/office/eclac-mexico-8211";}
if (std.tolower(req.url) ~ "/mexico/noticias/paginas/9/8389/p8389.xml") { error 750 "/es/publications/list/field_regional_office/8211/office/eclac-mexico-8211";}
if (std.tolower(req.url) ~ "/mexico/noticias/paginas/1/8411/p8411.xml") { error 750 "/es/node/41230";}
if (std.tolower(req.url) ~ "/mexico/noticias/paginas/9/8419/p8419.xml") { error 750 "/es/biblioteca/mexico-df";}
if (std.tolower(req.url) ~ "/washington/noticias/paginas/9/9089/p9089.xml") { error 750 "/en/publications/list/field_regional_office/eclac-washington-dc-8213?search_fulltext=";}
if (std.tolower(req.url) ~ "/washington/noticias/paginas/1/9091/p9091.xml") { error 750 "/en/headquarters-and-offices/eclac-washington-dc";}
if (std.tolower(req.url) ~ "/washington/noticias/noticias/1/9071/p9071.xml") { error 750 "/en/headquarters-and-offices/eclac-washington-dc";}
if (std.tolower(req.url) ~ "/noticias/paginas/8/21208/p21208.xml") { error 750 "/en/staff/alicia-barcena";}
if (std.tolower(req.url) ~ "/deype/noticias/paginas/5/15265/p15265.xml") { error 750 "/es/node/41212";}
if (std.tolower(req.url) ~ "/deype/noticias/paginas/8/15268/p15268.xml") { error 750 "/es/node/41216";}
if (std.tolower(req.url) ~ "/deype/noticias/paginas/1/15271/p15271.xml") { error 750 "/es/node/41749";}
if (std.tolower(req.url) ~ "/deype/noticias/paginas/2/15272/p15272.xml") { error 750 "/es/node/41749";}
if (std.tolower(req.url) ~ "/drni/noticias/paginas/8/12088/p12088.xml") { error 750 "/es/node/41199";}
if (std.tolower(req.url) ~ "/ddpe/noticias/paginas/5/12455/p12455.xml") { error 750 "/es/publications/list/field_work_area_v2/desarrollo-productivo-y-empresarial-8183";}
if (std.tolower(req.url) ~ "/dmaah/noticias/paginas/3/11513/p11513.xml") { error 750 "/es/node/41185";}
if (std.tolower(req.url) ~ "/washington/noticias/paginas/6/11526/p11526.xml") { error 750 "/en/publications/list/field_regional_office/eclac-washington-dc-8213?search_fulltext=";}
if (std.tolower(req.url) ~ "/noticias/paginas/5/11065/p11065.xml") { error 751 "http://repositorio.cepal.org/handle/11362/21";}
if (std.tolower(req.url) ~ "/mexico/noticias/paginas/1/10061/p10061.xml") { error 750 "/es/publicaciones/35894-manual-para-la-evaluacion-de-desastres";}
if (std.tolower(req.url) ~ "/celade/noticias/paginas/4/9364/p9364.xml") { error 750 "/es/node/41180";}
if (std.tolower(req.url) ~ "/noticias/paginas/7/12517/p12517.xml") { error 750 "/es/catedra-prebisch";}
if (std.tolower(req.url) ~ "/colombia/noticias/paginas/5/13905/p13905.xml") { error 751 "http://repositorio.cepal.org/browse?type=temas";}
if (std.tolower(req.url) ~ "/colombia/noticias/paginas/7/13577/p13577.xml") { error 750 "/es/node/41238";}
if (std.tolower(req.url) ~ "/colombia/noticias/paginas/1/13591/p13591.xml") { error 750 "/es/sedes-y-oficinas/cepal-bogota";}
if (std.tolower(req.url) ~ "/colombia/noticias/paginas/0/13590/p13590.xml") { error 750 "/es/publications/list/field_country%253aname/Colombia";}
if (std.tolower(req.url) ~ "/colombia/noticias/paginas/8/13588/p13588.xml") { error 750 "/es/sedes-y-oficinas/cepal-bogota";}
if (std.tolower(req.url) ~ "/noticias/paginas/4/13954/p13954.xml") { error 750 "/es/historia-de-la-cepal";}
if (std.tolower(req.url) ~ "/noticias/paginas/5/13975/p13975.xml") { error 750 "/es/node/18571";}
if (std.tolower(req.url) ~ "/argentina/noticias/paginas/3/14033/p14033.xml") { error 750 "/es/publications/list/field_country%253aname/Argentina";}
if (std.tolower(req.url) ~ "/noticias/paginas/5/14295/p14295.xml") { error 750 "/en/node/18571";}
if (std.tolower(req.url) ~ "/deype/noticias/paginas/1/15031/p15031.xml") { error 750 "/es/node/41210";}
if (std.tolower(req.url) ~ "/argentina/noticias/paginas/9/9839/p9839.xml") { error 750 "/es/node/41751";}
if (std.tolower(req.url) ~ "/uruguay/noticias/paginas/6/10416/p10416.xml") { error 750 "/es/node/41258";}
if (std.tolower(req.url) ~ "/uruguay/noticias/paginas/2/10422/p10422.xml") { error 750 "/es/publications/list/field_country%253aname/Uruguay";}
if (std.tolower(req.url) ~ "/uruguay/noticias/paginas/3/10423/p10423.xml") { error 750 "/es/sedes-y-oficinas/cepal-montevideo";}
if (std.tolower(req.url) ~ "/revista/noticias/paginas/7/20347/p20347.xml") { error 750 "/es/node/41283";}
if (std.tolower(req.url) ~ "/revista/noticias/paginas/4/20404/p20404.xml") { error 750 "/en/node/41283";}
if (std.tolower(req.url) ~ "/celade/noticias/paginas/9/19819/p19819.xml") { error 750 "/es/areas-de-trabajo/poblacion-y-desarrollo";}
if (std.tolower(req.url) ~ "/noticias/paginas/4/21324/p21324.xml") { error 750 "/es/acerca";}
if (std.tolower(req.url) ~ "/noticias/paginas/9/21159/p21159.xml") { error 750 "/es/acerca/secretaria-ejecutiva";}
if (std.tolower(req.url) ~ "/dds/noticias/paginas/4/32864/p32864.xml") { error 750 "/es/node/41152";}
if (std.tolower(req.url) ~ "/dds/noticias/paginas/5/32865/p32865.xml") { error 750 "/es/areas-de-trabajo/desarrollo-social";}
if (std.tolower(req.url) ~ "/noticias/paginas/7/33137/p33137.xml") { error 750 "/es/registro-de-proveedores";}
if (std.tolower(req.url) ~ "/noticias/paginas/7/37307/p37307.xml") { error 750 "/es/equipo/antonio-prado";}
if (std.tolower(req.url) ~ "/noticias/paginas/0/37310/p37310.xml") { error 750 "/es/equipo/antonio-prado";}
if (std.tolower(req.url) ~ "/noticias/paginas/4/33494/p33494.xml") { error 750 "/es/equipo/alicia-barcena";}
if (std.tolower(req.url) ~ "/noticias/paginas/9/33499/p33499.xml") { error 750 "/en/about/office-of-the-executive-secretary";}
if (std.tolower(req.url) ~ "/prensa/noticias/comunicados/0/37330/p37330.xml") { error 750 "/en/staff/antonio-prado";}
if (std.tolower(req.url) ~ "/noticias/paginas/8/33638/p33638.xml") { error 750 "/es/presentaciones/5";}
if (std.tolower(req.url) ~ "/celade/noticias/paginas/7/36157/p36157.xml") { error 750 "/es/temas/censos-de-poblacion-y-vivienda";}
if (std.tolower(req.url) ~ "/noticias/paginas/6/21346/p21346.xml") { error 750 "/es/equipo/antonio-prado";}
if (std.tolower(req.url) ~ "/noticias/paginas/0/21490/p21490.xml") { error 750 "/es/events/past/type/8222/event-type/periodos-de-sesiones-8222";}
if (std.tolower(req.url) ~ "/noticias/paginas/0/21710/p21710.xml") { error 750 "/en/about";}
if (std.tolower(req.url) ~ "/colombia/noticias/paginas/8/21828/p21828.xml") { error 750 "/es/centro-de-prensa";}
if (std.tolower(req.url) ~ "/mujer/noticias/paginas/4/25644/p25644.xml") { error 750 "/es/node/41126";}
if (std.tolower(req.url) ~ "/celade/noticias/paginas/2/26682/p26682.xml") { error 750 "/es/temas/migracion-interna";}
if (std.tolower(req.url) ~ "/celade/noticias/paginas/1/26681/p26681.xml") { error 750 "/es/node/41179";}
if (std.tolower(req.url) ~ "/dmaah/noticias/paginas/2/28062/p28062.xml") { error 750 "/es/node/41748";}
if (std.tolower(req.url) ~ "/mujer/noticias/paginas/5/28455/p28455.xml") { error 750 "/es/publications/list/field_work_area_v2/8187/language/es";}
if (std.tolower(req.url) ~ "/mexico/noticias/paginas/1/29871/p29871.xml") { error 750 "/es/registro-de-proveedores";}
if (std.tolower(req.url) ~ "/ddpe/noticias/paginas/4/35304/p35304.xml") { error 750 "/en/node/41140";}
if (std.tolower(req.url) ~ "/ddpe/noticias/paginas/3/35323/p35323.xml") { error 750 "/es/node/41140";}
if (std.tolower(req.url) ~ "/revista/noticias/paginas/2/35852/p35852.xml") { error 750 "/es/node/41279";}
if (std.tolower(req.url) ~ "/revista/noticias/paginas/6/35856/p35856.xml") { error 750 "/es/node/41278";}
if (std.tolower(req.url) ~ "/revista/noticias/paginas/7/35857/p35857.xml") { error 750 "/es/equipo/osvaldo-sunkel";}
if (std.tolower(req.url) ~ "/revista/noticias/paginas/8/35858/p35858.xml") { error 750 "/es/equipo/andre-hofman";}
if (std.tolower(req.url) ~ "/revista/noticias/paginas/9/35859/p35859.xml") { error 750 "/es/equipo/miguel-torres";}
if (std.tolower(req.url) ~ "/revista/noticias/paginas/5/35885/p35885.xml") { error 750 "/es/node/41280";}
if (std.tolower(req.url) ~ "/celade/noticias/paginas/1/36641/p36641.xml") { error 750 "/es/publications/list/field_topic/ageing-34/field_work_area_v2/population-and-development-8169/language/es";}
if (std.tolower(req.url) ~ "/revista/noticias/paginas/5/36275/p36275.xml") { error 750 "/en/node/41280";}
if (std.tolower(req.url) ~ "/celade/noticias/paginas/4/36634/p36634.xml") { error 750 "/es/publications/list/field_topic/international-migration-70/field_work_area_v2/population-and-development-8169/language/es";}
if (std.tolower(req.url) ~ "/deype/agenda/6/37356/p37356.xml") { error 751 "http://repositorio.cepal.org/handle/11362/37356";}
if (std.tolower(req.url) ~ "/brasil/noticias/paginas/5/36525/p36525.xml") { error 750 "/pt-br/events/past/course-country/BR";}
if (std.tolower(req.url) ~ "/revista/noticias/paginas/0/36600/p36600.xml") { error 750 "/es/equipo/osvaldo-sunkel";}
if (std.tolower(req.url) ~ "/revista/noticias/paginas/1/36601/p36601.xml") { error 750 "/es/equipo/andre-hofman";}
if (std.tolower(req.url) ~ "/revista/noticias/paginas/2/36602/p36602.xml") { error 750 "/es/equipo/miguel-torres";}
if (std.tolower(req.url) ~ "/revista/noticias/paginas/6/36436/p36436.xml") { error 750 "/en/node/41279";}
if (std.tolower(req.url) ~ "/revista/noticias/paginas/8/36438/p36438.xml") { error 750 "/en/node/41278";}
if (std.tolower(req.url) ~ "/brasil/noticias/paginas/2/38422/p38422.xml") { error 750 "/pt-br/events/past/course-country/BR";}
if (std.tolower(req.url) ~ "/noticias/paginas/1/39501/p39501.xml") { error 750 "/es/presentaciones/131";}
if (std.tolower(req.url) ~ "/deype/noticias/paginas/5/40105/p40105.xml") { error 750 "/es/node/41211";}
if (std.tolower(req.url) ~ "/deype/noticias/paginas/8/39578/p39578.xml") { error 750 "/es/projects/list/field_work_area_v2/8184";}
if (std.tolower(req.url) ~ "/deype/noticias/paginas/9/39579/p39579.xml") { error 750 "/es/publications/list/field_work_area_v2/8184";}
if (std.tolower(req.url) ~ "/colombia/noticias/paginas/3/41133/p41133.xml") { error 750 "/es/escalafon-de-la-competitividad-de-los-departamentos-en-colombia";}
if (std.tolower(req.url) ~ "/noticias/paginas/1/39611/p39611.xml") { error 750 "/en/presentations/131";}
if (std.tolower(req.url) ~ "/washington/noticias/paginas/6/38426/p38426.xml") { error 750 "/en/headquarters-and-offices/eclac-washington-dc";}
if (std.tolower(req.url) ~ "/deype/noticias/paginas/0/40830/p40830.xml") { error 750 "/es/projects/list/field_work_area_v2/8184";}
if (std.tolower(req.url) ~ "/brasil/noticias/noticias/8/42518/p42518.xml") { error 751 "http://repositorio.cepal.org/browse?value=NU.+CEPAL.+Oficina+de+Brasilia&type=autorinstitucional";}
if (std.tolower(req.url) ~ "/de/noticias/paginas/6/38046/p38046.xml") { error 750 "/en/node/41136";}
if (std.tolower(req.url) ~ "/deype/noticias/paginas/9/40799/p40799.xml") { error 750 "/es/node/41749";}
if (std.tolower(req.url) ~ "/deype/noticias/paginas/9/40829/p40829.xml") { error 750 "/es/projects/list/field_work_area_v2/8184";}
if (std.tolower(req.url) ~ "/deype/noticias/paginas/6/40776/p40776.xml") { error 750 "/es/node/41214";}
if (std.tolower(req.url) ~ "/portofspain/noticias/paginas/2/42832/p42832.xml") { error 750 "/en/topics/8184/offices/8209";}
if (std.tolower(req.url) ~ "/portofspain/noticias/paginas/2/44232/p44232.xml") { error 750 "/en/node/41237";}
if (std.tolower(req.url) ~ "/portofspain/noticias/paginas/8/42838/p42838.xml") { error 750 "/en/topics/8238/offices/8209";}
if (std.tolower(req.url) ~ "/ilpes/noticias/paginas/3/45713/p45713.xml") { error 750 "/es/courses/past/work-area/8190";}
if (std.tolower(req.url) ~ "/mujer/noticias/paginas/4/45904/p45904.xml") { error 750 "/es/node/41149";}
if (std.tolower(req.url) ~ "/dds/noticias/paginas/2/44872/p44872.xml") { error 750 "/es/node/41153";}
if (std.tolower(req.url) ~ "/colombia/noticias/paginas/7/45177/p45177.xml") { error 750 "/es/node/41243";}
if (std.tolower(req.url) ~ "/portofspain/noticias/paginas/0/47350/p47350.xml") { error 750 "/en/node/41233";}
if (std.tolower(req.url) ~ "/portofspain/noticias/paginas/6/47356/p47356.xml") { error 750 "/en/node/47356";}
if (std.tolower(req.url) ~ "/portofspain/noticias/paginas/9/47369/p47369.xml") { error 750 "/en/publications/list/field_regional_office/8209";}
if (std.tolower(req.url) ~ "/portofspain/noticias/paginas/1/47371/p47371.xml") { error 750 "/en/node/41234";}
if (std.tolower(req.url) ~ "/portofspain/noticias/paginas/9/47379/p47379.xml") { error 750 "/en/topics/8188/offices/8209";}
if (std.tolower(req.url) ~ "/prensa/noticias/paginas/0/51940/p51940.xml") { error 750 "/es/news/list/language/es/type/cepal_infographic";}
if (std.tolower(req.url) ~ "/dmaah/noticias/paginas/5/48025/p48025.xml") { error 750 "/es/node/41189";}
if (std.tolower(req.url) ~ "/ilpes/noticias/paginas/9/52849/p52849.xml") { error 750 "/es/node/41747";}
if (std.tolower(req.url) ~ "/ilpes/noticias/paginas/7/50667/p50667.xml") { error 750 "/es/events/past/work-area/planning-development-8190";}
if (std.tolower(req.url) ~ "/portofspain/noticias/paginas/3/47383/p47383.xml") { error 750 "/en/topics/24/offices/8209";}
if (std.tolower(req.url) ~ "/portofspain/noticias/paginas/8/47388/p47388.xml") { error 750 "/en/topics/8195/offices/8209";}
if (std.tolower(req.url) ~ "/washington/noticias/noticias/1/54551/p54551.xml") { error 750 "/en/publications/37388-economics-climate-change-latin-america-and-caribbean-paradoxes-and-challenges";}
if (std.tolower(req.url) ~ "/celade/noticias/paginas/5/50215/p50215.xml") { error 750 "/es/node/41172";}
if (std.tolower(req.url) ~ "/ilpes/noticias/paginas/4/50384/p50384.xml") { error 750 "/es/publications/list/field_work_area_v2/8190";}
if (std.tolower(req.url) ~ "/ues/noticias/paginas/8/50128/p50128.xml") { error 750 "/es/node/41148";}
if (std.tolower(req.url) ~ "/washington/noticias/noticias/3/54833/p54833.xml") { error 750 "/es/publicaciones/la-participacion-de-america-latina-y-el-caribe-en-el-mecanismo-de-solucion-de";}
if (std.tolower(req.url) ~ "/mexico/noticias/noticias/9/53959/p53959.xml") { error 750 "/es/comunicados/exportaciones-de-america-latina-y-el-caribe-se-estancan-por-tercer-ano-consecutivo-y";}
if (std.tolower(req.url) ~ "/washington/noticias/noticias/5/54835/p54835.xml") { error 750 "/en/publications/37747-fiscal-panorama-latin-america-and-caribbean-2015-policy-space-and-dilemmas";}
if (std.tolower(req.url) ~ "/dmaah/noticias/noticias/3/54373/p54373.xml") { error 750 "/es/node/41195";}
if (std.tolower(req.url) ~ "/rio20/noticias/paginas/8/54448/p54448.xml") { error 750 "/en/node/41198";}
if (std.tolower(req.url) ~ "/washington/noticias/noticias/8/54498/p54498.xml") { error 750 "/es/node/25364";}
if (std.tolower(req.url) ~ "/washington/noticias/noticias/8/54678/p54678.xml") { error 750 "/es/publicaciones/37626-panorama-social-de-america-latina-2014";}
if (std.tolower(req.url) ~ "/prensa/noticias/paginas/7/51947/p51947.xml") { error 750 "/en/news/list/language/en/type/cepal_infographic";}
if (std.tolower(req.url) ~ "/prensa/noticias/comunicados/7/53847/p53847.xml") { error 750 "/en/publications/37056-economics-climate-change-latin-america-and-caribbean-paradoxes-and-challenges";}
if (std.tolower(req.url) ~ "/mexico/noticias/vacantes/9/54659/p54659.xml") { error 750 "/es/oportunidades-de-empleo";}
if (std.tolower(req.url) ~ "/prensa/noticias/paginas/6/54456/p54456.xml") { error 750 "/en/eclac-notes";}
if (std.tolower(req.url) ~ "/rio20/noticias/paginas/9/49479/p49479.xml") { error 750 "/es/node/41198";}
if (std.tolower(req.url) ~ "/rio20/noticias/paginas/2/49482/p49482.xml") { error 750 "/pt-br/node/41194";}
if (std.tolower(req.url) ~ "/deype/noticias/noticias/5/54195/p54195.xml") { error 750 "/es/publicaciones/37647-anuario-estadistico-de-america-latina-y-el-caribe-2014-statistical-yearbook";}
if (std.tolower(req.url) ~ "/rio20/noticias/paginas/5/48585/p48585.xml") { error 750 "/es/node/41194";}
if (std.tolower(req.url) ~ "/washington/noticias/noticias/1/54761/p54761.xml") { error 750 "/es/node/29161";}
if (std.tolower(req.url) ~ "/colombia/noticias/paginas/1/51441/p51441.xml") { error 750 "/es/escalafon-de-la-competitividad-de-los-departamentos-en-colombia";}
if (std.tolower(req.url) ~ "/mexico/noticias/noticias/8/53998/p53998.xml") { error 750 "/es/comunicados/desempleo-podria-caer-hasta-60-en-america-latina-y-el-caribe-pesar-de-la-escasa-creacion";}
if (std.tolower(req.url) ~ "/celade/noticias/paginas/1/50191/p50191.xml") { error 750 "/en/node/41172";}
if (std.tolower(req.url) ~ "/rio20/noticias/paginas/3/54423/p54423.xml") { error 750 "/en/node/41194";}
if (std.tolower(req.url) ~ "/rio20/noticias/paginas/7/54437/p54437.xml") { error 750 "/en/node/41195";}
if (std.tolower(req.url) ~ "/mexico/noticias/noticias/6/53986/p53986.xml") { error 750 "/es/comunicados/paises-de-la-region-deberian-invertir-62-del-pib-anual-para-satisfacer-demandas-de";}
} 
 
sub redireccionaSADE_Libre{
if (std.tolower(req.url) == "/publicaciones/search.asp?tipdoc=17&desdoc=libros%20institucionales") { error 750 "/es/publications/list/field_publication_type/8059/field_publication_type/8069/field_publication_type/8101?search_fulltext=";}
if (std.tolower(req.url) == "/publicaciones/search.asp?tipdoc=2&desdoc=libros%20de%20la%20cepal") { error 750 "/es/publications/list/field_publication_type/8059/field_publication_type/8069/field_publication_type/8156?search_fulltext=";}
if (std.tolower(req.url) == "/publicaciones/search.asp?tipdoc=3&desdoc=cuadernos%20de%20la%20cepal") { error 750 "/es/publications/list/field_publication_type/8059/field_publication_type/8069/field_publication_type/8135?search_fulltext=";}
if (std.tolower(req.url) == "/publicaciones/search.asp?tipdoc=4&desdoc=coediciones") { error 750 "/es/publications/list/field_publication_type/8053/field_publication_type/8059/field_publication_type/8069?search_fulltext=";}
if (std.tolower(req.url) == "/publicaciones/search.asp?tipdoc=5&desdoc=copublicaciones") { error 750 "/es/publications/list/field_publication_type/8059/field_publication_type/8067/field_publication_type/8069?search_fulltext=";}
if (std.tolower(req.url) == "/publicaciones/search.asp?tipdoc=13&desdoc=boletines") { error 750 "/es/publicaciones-periodicas";}
if (std.tolower(req.url) == "/publicaciones/search.asp?tipdoc=20&desdoc=cuadernos%20estad%c3%adsticos") { error 750 "/es/publications/list/field_publication_type/8055/field_publication_type/8080/field_publication_type/8096?search_fulltext=";}
if (std.tolower(req.url) == "/publicaciones/search.asp?tipdoc=22&desdoc=informes%20de%20reuniones%20y%20programas") { error 750 "/es/publications/list/field_publication_type/8062?search_fulltext=";}
if (std.tolower(req.url) == "/publicaciones/search.asp?tipdoc=23&desdoc=cuadernos%20del%20ilpes") { error 750 "/es/publications/list/field_publication_type/series-8055/field_publication_type/8120?search_fulltext=cuadernos+del+ilpes";}
if (std.tolower(req.url) == "/desafios/") { error 751 "http://repositorio.cepal.org/handle/11362/57";}
if (std.tolower(req.url) == "/noticias/calendarioactividades/search.asp") { error 750 "/es/eventos";}
if (std.tolower(req.url) == "/noticias/calendarioactividades/search.asp?idioma=in") { error 750 "/en/events";}
if (std.tolower(req.url) == "/software/") { error 750 "/es/datos-y-estadisticas";}
if (std.tolower(req.url) == "/software/default.asp?idioma=in") { error 750 "/en/data-and-statistics";}
if (std.tolower(req.url) == "/divisiones/") { error 750 "/es/divisiones";}
if (std.tolower(req.url) == "/divisiones/default.asp?idioma=in") { error 750 "/en/divisions-and-units";}
if (std.tolower(req.url) == "/de/formularios/361.xml") { error 750 "/es/areas-de-trabajo/desarrollo-economico";}
if (std.tolower(req.url) == "/subsedes/") { error 750 "/es/sedes-y-oficinas";}
if (std.tolower(req.url) == "/ues/") { error 750 "/es/temas/financiamiento-para-el-desarrollo";}
if (std.tolower(req.url) == "/adquisiciones") { error 750 "/es/registro-de-proveedores";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/noticias/vacantes/default.xml&xsl=/acerca/opor-tra.xsl&base=/tpl/top-bottom.xsl") { error 750 "/es/oportunidades-de-empleo";}
if (std.tolower(req.url) == "/celade/antecedentes50.htm") { error 750 "/es/acerca-de-poblacion-y-desarrollo";}
if (std.tolower(req.url) == "/socinfo/") { error 750 "/es/temas/tecnologias-de-la-informacion-y-las-comunicaciones-tic";}
if (std.tolower(req.url) == "/socinfo/default.asp?idioma=in") { error 750 "/en/topics/information-and-communications-technologies-icts";}
if (std.tolower(req.url) == "/socinfo/orba/") { error 750 "/es/observatorio-regional-de-banda-ancha";}
if (std.tolower(req.url) == "/presentaciones/cepal/index.html") { error 750 "https://www.flickr.com/photos/cepal/sets/72157625916957346/";}
if (std.tolower(req.url) == "/uruguay/publicaciones/search_pub.asp?desdoc=uruguay") { error 750 "/es/publications/list/field_country%253aname/Uruguay";}
if (std.tolower(req.url) == "/default.asp?idioma=pr") { error 750 "/pt-br";}
if (std.tolower(req.url) == "/biblioteca/default.asp?xml=xml/geninfo.xml&lang=eng") { error 750 "/en/bibliotecas-de-la-cepal";}
if (std.tolower(req.url) == "/biblioteca/default.asp?xml=xml/geninfo.xml&lang=spa") { error 750 "/es/biblioteca";}
if (std.tolower(req.url) == "/deype/ceacepal/reunioncea2015.htm") { error 750 "http://cea.cepal.org/es";}
if (std.tolower(req.url) == "/deype/ceacepal/meetingsca2015.htm") { error 750 "http://cea.cepal.org/en";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/noticias/vacantes/default.xml&xsl=/acerca/opor-tra-i.xsl&base=/tpl-i/top-bottom.xsl") { error 750 "/en/oportunidades-de-empleo";}
if (std.tolower(req.url) == "/dds/innovacionsocial") { error 750 "/es/temas/innovacion-social";}
if (std.tolower(req.url) == "/dds/innovacionsocial/") { error 750 "/es/temas/innovacion-social";}
if (std.tolower(req.url) ~ "^/en/organizational-unit/*") { error 751 "/en";}
if (std.tolower(req.url) ~ "^/en/event-type/*") { error 751 "/en";}
if (std.tolower(req.url) ~ "^/en/country-taxonomy/*") { error 751 "/en";}
if (std.tolower(req.url) ~ "^/en/special-topics/*") { error 751 "/en";}
if (std.tolower(req.url) ~ "^/en/unbis/*") { error 751 "/en";}
if (std.tolower(req.url) ~ "^/es/unbis/*") { error 751 "/es";}
if (std.tolower(req.url) ~ "^/es/special-topics/*") { error 751 "/es";}
if (std.tolower(req.url) == "/mexico/cambioclimatico_trabajo/") { error 750 "/es/topics/8/offices/8211";}
if (std.tolower(req.url) == "/prensa/noticias/notas/todas_notas.asp") { error 750 "/es/notas-de-la-cepal";}
if (std.tolower(req.url) == "/prensa/noticias/notas/todas_notas.asp?idioma=in") { error 750 "/en/eclac-notes";}
if (std.tolower(req.url) == "/erecc/homepresent.html") { error 750 "/en/topics/disasters";}
if (std.tolower(req.url) == "/pobrezaurbana") { error 750 "/es/temas/asentamientos-humanos";}
if (std.tolower(req.url) == "/caf") { error 750 "/es/areas-de-trabajo/desarrollo-sostenible-y-asentamientos-humanos";}
if (std.tolower(req.url) == "/esalc") { error 750 "/es/areas-de-trabajo/desarrollo-sostenible-y-asentamientos-humanos";}
if (std.tolower(req.url) == "/oig/default.asp?idioma=pr") { error 750 "http://oig.cepal.org/pt";}
if (std.tolower(req.url) == "/oig/default.asp?idioma=fr") { error 750 "http://oig.cepal.org/es";}
if (std.tolower(req.url) == "/oig/afisica/default.asp?idioma=pr") { error 750 "http://oig.cepal.org/pt/autonomias/autonomia-fisica";}
if (std.tolower(req.url) == "/oig/afisica/default.asp?idioma=fr") { error 750 "http://oig.cepal.org/es/autonomias/autonomia-fisica";}
if (std.tolower(req.url) == "/oig/aeconomica/default.asp?idioma=pr") { error 750 "http://oig.cepal.org/pt/autonomias/autonomia-economica";}
if (std.tolower(req.url) == "/oig/aeconomica/default.asp?idioma=fr") { error 750 "http://oig.cepal.org/es/autonomias/autonomia-economica";}
if (std.tolower(req.url) == "/oig/adecisiones/default.asp?idioma=pr") { error 750 "http://oig.cepal.org/pt/autonomias/autonomia-na-tomada-decisoes";}
if (std.tolower(req.url) == "/oig/adecisiones/default.asp?idioma=fr") { error 750 "http://oig.cepal.org/es/autonomias/autonomia-la-toma-decisiones";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/oig/agrupadores_xml/aes779.xml&xsl=/oig/agrupadores_xml/agrupa_listado-p.xsl&base=/oig/tpl-p/top-bottom.xsl") { error 750 "http://oig.cepal.org/pt/documentos";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/oig/agrupadores_xml/aes779.xml&xsl=/oig/agrupadores_xml/agrupa_listado-f.xsl&base=/oig/tpl-f/top-bottom.xsl") { error 750 "http://oig.cepal.org/es/documentos";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/oig/noticias/paginas/5/36135/p36135.xml&xsl=/oig/tpl/p18f.xsl&base=/oig/tpl/top-bottom-decisiones.xsl") { error 750 "http://oig.cepal.org/es/leyes/leyes-de-cuotas";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/oig/noticias/paginas/2/36362/p36362.xml&xsl=/oig/tpl-i/p18f.xsl&base=/oig/tpl-i/top-bottom-decisiones.xsl") { error 750 "http://oig.cepal.org/en/laws/quota-legislation";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/oig/noticias/paginas/8/36598/p36598.xml&xsl=/oig/tpl/p18f.xsl&base=/oig/tpl-p/top-bottom-decisiones.xsl") { error 750 "http://oig.cepal.org/pt/leis/leis-de-cotas";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/oig/noticias/paginas/6/36676/p36676.xml&xsl=/oig/tpl/p18f.xsl&base=/oig/tpl-f/top-bottom-decisiones.xsl") { error 750 "http://oig.cepal.org/es/leyes/leyes-de-cuotas";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/oig/noticias/paginas/1/46121/p46121.xml&xsl=/oig/tpl/p18f.xsl&base=/oig/tpl/top-bottom-fisica.xsl") { error 750 "http://oig.cepal.org/es/leyes/leyes-de-violencia";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/oig/noticias/paginas/6/46486/p46486.xml&xsl=/oig/tpl-i/p18f.xsl&base=/oig/tpl-i/top-bottom-fisica.xsl") { error 750 "http://oig.cepal.org/en/laws/violence-laws";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/oig/noticias/paginas/7/35037/p35037.xml&xsl=/oig/tpl/p18f.xsl&base=/oig/tpl-p/top-bottom-fisica.xsl") { error 750 "http://oig.cepal.org/pt/leis/leis-de-violencia";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/oig/noticias/paginas/0/36670/p36670.xml&xsl=/oig/tpl/p18f.xsl&base=/oig/tpl-f/top-bottom-fisica.xsl") { error 750 "http://oig.cepal.org/es/leyes/leyes-de-violencia";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/oig/noticias/paginas/2/46652/p46652.xml&xsl=/oig/tpl/p18f.xsl&base=/oig/tpl/top-bottom-economica.xsl") { error 750 "http://oig.cepal.org/es/leyes/leyes-de-cuidado";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/oig/noticias/paginas/2/47072/p47072.xml&xsl=/oig/tpl-i/p18f.xsl&base=/oig/tpl-i/top-bottom-economica.xsl") { error 750 "http://oig.cepal.org/en/laws/care-related-policies-laws";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/oig/noticias/paginas/7/36607/p36607.xml&xsl=/oig/tpl/p18f.xsl&base=/oig/tpl-p/top-bottom-economica.xsl") { error 750 "http://oig.cepal.org/pt/leis/leis-de-cuidado";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/oig/noticias/paginas/6/35036/p35036.xml&xsl=/oig/tpl/p18f.xsl&base=/oig/tpl-f/top-bottom-economica.xsl") { error 750 "http://oig.cepal.org/es/leyes/leyes-de-cuidado";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/oig/noticias/paginas/8/50478/p50478.xml&xsl=/oig/tpl/p18f.xsl&base=/oig/tpl/top-bottom-fisica.xsl") { error 750 "http://oig.cepal.org/es/leyes/leyes-sobre-aborto";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/oig/noticias/paginas/9/50479/p50479.xml&xsl=/oig/tpl-i/p18f.xsl&base=/oig/tpl-i/top-bottom-fisica.xsl") { error 750 "http://oig.cepal.org/en/laws/abortion-laws";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/oig/noticias/paginas/0/50480/p50480.xml&xsl=/oig/tpl/p18f.xsl&base=/oig/tpl-p/top-bottom-fisica.xsl") { error 750 "http://oig.cepal.org/pt/leis/leis-de-aborto";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/oig/noticias/paginas/7/50477/p50477.xml&xsl=/oig/tpl/p18f.xsl&base=/oig/tpl-f/top-bottom-fisica.xsl") { error 750 "http://oig.cepal.org/es/leyes/leyes-sobre-aborto";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/oig/agrupadores_xml/aes854.xml&xsl=/oig/agrupadores_xml/agrupa_listado-p.xsl&base=/oig/tpl-p/top-bottom.xsl") { error 750 "http://oig.cepal.org/pt/politicas-justas";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/oig/agrupadores_xml/afr854.xml&xsl=/oig/agrupadores_xml/agrupa_listado-f.xsl&base=/oig/tpl-f/top-bottom.xsl") { error 750 "http://oig.cepal.org/es/politicas-justas";}
if (std.tolower(req.url) == "/celade/redatam") { error 750 "/es/temas/redatam";}
if (std.tolower(req.url) == "/argentina-indicadores-desarrollo") { error 750 "http://indides.cepal.org";}
if (std.tolower(req.url) == "/cgi-bin/getprod.asp?xml=/noticias/vacantes/default.xml&xsl=/acerca/opor-tra.xsl&base=/tpl/top-bottom_acerca.xsl") { error 750 "/es/oportunidades-de-empleo";}
if (std.tolower(req.url) == "/default.asp?idioma=fr") { error 750 "/es";}
if (std.tolower(req.url) == "/celade/migracion/imila/") { error 750 "http://celade.cepal.org/bdcelade/imila/";}
if (std.tolower(req.url) == "/celade/depualc/") { error 750 "http://celade.cepal.org/bdcelade/depualc/";}
} 
