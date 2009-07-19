# New ports collection makefile for:	antiwm
# Date created:		2009-01-30
# Whom:			Dennis Herrmann <adox@mcx2.org>
#
# $FreeBSD$
#

PORTNAME=	antiwm
PORTVERSION=	0.0.5
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A minimalist window manager inspired by Ratpoison

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

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
