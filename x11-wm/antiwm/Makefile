# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	antiwm
PORTVERSION=	0.0.5
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Minimalist window manager inspired by Ratpoison

OPTIONS_DEFINE=	DOCS

USE_XORG=	x11

PLIST_FILES=	bin/antiwm
PORTDOCS=	README LICENSE

pre-everything::
	@${ECHO_MSG} "You can build antiwm with your own conf.h using the ANTIWM_CONF knob:"
	@${ECHO_MSG} "make ANTIWM_CONF=/path/to/antiwm/conf.h install clean"

post-extract:
.if defined(ANTIWM_CONF)
	@${ECHO_MSG} "creating conf.h from ${ANTIWM_CONF}"
	@${CP} ${ANTIWM_CONF} ${WRKSRC}/conf.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
