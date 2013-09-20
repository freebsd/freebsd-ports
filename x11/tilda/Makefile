# $FreeBSD$

PORTNAME=	tilda
PORTVERSION=	0.9.6
PORTREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	vlad@vlad.uz.ua
COMMENT=	Drop down x11 terminal with transparency support

LIB_DEPENDS=	confuse.0:${PORTSDIR}/devel/libconfuse

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 libglade2 vte
USES=		gmake pkgconfig

DOCS=		AUTHORS ChangeLog README TODO

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|ps -C tilda -o pid=|pgrep tilda|' \
		${WRKSRC}/src/tilda.c
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/src/tomboykeybinder.h

post-install:
.if !defined (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

	@${ECHO_MSG} ""
	@${ECHO_MSG} ""
	@${ECHO_MSG} "		ATTENTION:"
	@${ECHO_MSG} "		If you are upgrade from version 0.09.1 or below,"
	@${ECHO_MSG} "		you'll need to delete your old config files and "
	@${ECHO_MSG} "		make them again."
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""

.include <bsd.port.mk>
