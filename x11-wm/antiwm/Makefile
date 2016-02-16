# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	antiwm
PORTVERSION=	0.0.5
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Minimalist window manager inspired by Ratpoison

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_XORG=	x11

PLIST_FILES=	bin/antiwm
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

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

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
